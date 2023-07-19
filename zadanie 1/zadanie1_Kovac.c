#include <stdio.h>
#include <stdlib.h>

void *m;        //Globálne ukazuje na začiatok pamäte

void memory_init(void *ptr, int size) {                         //Inicializácia pamäte
    for(int i = 0; i < size; i++)                               //Nastavím cele pole na 1tky
        *((char*)ptr + i) = 1;
    m=ptr;                                                      //Nastavenie globálneho pointra na začiatok pamäte
    *((int*)ptr) = size - sizeof(int) - sizeof(int);            //Od celkovej veľkosti odrátam veľkost prvej hlavičky a koncového integera 0
    *((int*)(ptr+size-sizeof(int))) = 0;                        //Nastavenie koncoveho integera na 0 (slúži ako koncový znak)
}

void *memory_alloc(size_t size){                                                                //Alokovanie pamäte
    void *ptr = m;                                                                              //Pointer nastavený na začiatok pamäte
    while(((*((int*)ptr) < size) || (!(is_free(*((int*)ptr))))) && (*((char*)ptr) != 0))        //While((blok pamäte je menší ako požadovaná veľkosť ALEBO blok nie je volný) A ZÁROVEŇ nie sme na konci)
        ptr += abs(*((int*)ptr)) + sizeof(int);                                                 //Posúvame sa po blokoch pamäte

    if((*((int*)ptr)) == size) {                    //Ak nájdeme blok s presnou veľkosťou, otočíme znamienko hlavičky
        *((int*)ptr) = *((int*)ptr) * (-1);
        return (void*)(ptr + sizeof(int));          //Vrátenie výsledného pointera na alokovaný blok pamäte, posunutého o veľkosť hlavičky
    }
    else if((*((int*)ptr)) > size) {                //Ak nájdeme väčší blok pamäte, rozdelíme ho
        
        void *z = ptr + sizeof(int) + size;         //Vytvorenie nového bloku (zvyšok bloku)
        int r = (*((int*)ptr)-size-sizeof(int));    //Zaokruhlovanie velkosti bloku ak by bol zvyšný blok menší ako 1
        if (r < 1) {                                
            *((int*)ptr) = *((int*)ptr) * (-1); 
            return (void*)(ptr + sizeof(int));      //Vrátenie výsledného pointera na alokovaný blok pamäte       
        }
        *((int*)z) = *((int*)ptr)-size-sizeof(int); //Nastavenie veľkosti zvyšného bloku
        *((int*)ptr)=size;                          //Nastavenie veľkosti alokovaného bloku
        *((int*)ptr)= *((int*)ptr) * (-1);          //Nastavenie znamienka alokovaného bloku na (-)
        return (void*)(ptr + sizeof(int));          //Vrátenie výsledného pointera na alokovaný blok pamäte
    }
    else {
        printf("Nedostatok miesta pre velkost %d\n", size);
        return NULL;                                //Vrátenie NULL v prípade ak nieje možné nájsť voľné miesto v pamäti
    }                      
}

int is_free(int x) {                                //Vráti 0/1 podľa znamienka hlavičky bloku
    return (x>0)?1:0;                       
}

int memory_check(void *ptr) {                       //Skontroluje či je pointer platný (!= NULL a nie je volný)
    if (!ptr || is_free(*((int*)ptr))) 
        return 0;
    else
        return 1;
}

void memory_merge() {
    void *ptr = m;  
    while(*((char*)ptr) != 0) {
        if(is_free(*((int*)ptr)) && is_free(*((int*)(ptr + abs(*((int*)ptr)) + sizeof(int)))) && (*((char*)(ptr + abs(*((int*)ptr)) + sizeof(int))) != 0)) {          //Ak sú za sebou 2 volné bloky, spoja sa
            *((int*)ptr) += (*((int*)(ptr + *((int*)ptr) + sizeof(int))) + sizeof(int));                //K veľkosti prvého bloku pripočíta veľkosť druhého + hlavičku druhého
        }
        ptr += abs(*((int*)ptr)) + sizeof(int);
    }   
}

int memory_free(void *valid_ptr) {                              
    if(valid_ptr)
        valid_ptr -= sizeof(int);                               //Odčítania veľkosti integeru aby sme sa dostali k hlavičke
    if(memory_check(valid_ptr)) {                               //Pokiaľ je pointer platný, uvoľní ho a vráti 1    
        *((int*)valid_ptr) = *((int*)valid_ptr) * (-1);
        memory_merge();                                         //Pospájanie voľných blokov
        return 1;
    }
    printf("Neplatny pointer, nemozno uvolnit\n");
    return 0;                                                   //Ak to nieje platný pointer, vráti 0
}

void vypis() {                                                  //Pomocná funkcia ne debugovanie (vizuálne zobrazuje rozloženie pamäte)
    void *ptr = m;
    printf("| ");
    while(*((char*)ptr) != 0) { 
        printf("%d | ", *((int*)ptr));
        ptr += abs(*((int*)ptr)) + sizeof(int);
    } 
    printf("\n"); 
}

//1. test zo zadania
void test1() {
    char memory[100];
    memory_init(memory, 100);
    char* t1a[8];
    printf("Test1 :\n");
    vypis();

    for (int i = 0; i < 8; i++) {
        t1a[i]=(char*)memory_alloc(12);
        vypis();
    }
    for (int j = 0; j < 8; j++) {
        if(memory_free(t1a[j]))
            vypis();
    }
    printf("Test1 prebehol uspesne\n");
}
//2. test zo zadania
void test2() {
    char memory[100];
    memory_init(memory, 100);
    char* t1a[8];
    printf("Test2 :\n");
    vypis();

    for (int i = 0; i < 8; i++) {
        t1a[i]=(char*)memory_alloc((rand() % 17) + 8);    //Náhodná veľkosť od 8-24 B
        vypis();
    }
    for (int j = 0; j < 8; j++) {
        if(memory_free(t1a[j]))
            vypis();
    }
    printf("Test2 prebehol uspesne\n");
}
//3. test zo zadania
void test3() {
    char memory[10000];
    memory_init(memory, 10000);
    char* t1a[8];
    printf("Test3 :\n");
    vypis();

    for (int i = 0; i < 8; i++) {
        t1a[i]=(char*)memory_alloc((rand() % 4501) + 500);    //Náhodná veľkosť od 500-5000 B
        vypis();
    }
    for (int j = 0; j < 8; j++) {
        if(memory_free(t1a[j]))
            vypis();
    }
    printf("Test3 prebehol uspesne\n");
}
//4. test zo zadania
void test4() {
    char memory[100000];
    memory_init(memory, 100000);
    char* t1a[8];
    printf("Test4 :\n");
    vypis();

    for (int i = 0; i < 8; i++) {
        t1a[i]=(char*)memory_alloc((rand() % 49993) + 8);    //Náhodná veľkosť od 8-50000 B
        vypis();
    }
    for (int j = 0; j < 8; j++) {
        if(memory_free(t1a[j]))
            vypis();
    }
    printf("Test4 prebehol uspesne\n");
}

int main() {
    srand(time(NULL));              //Kvoli random() funkciam
    test1();
    test2();
    test3();
    test4();
    printf("Hotovo");
    return 0;
}