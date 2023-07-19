#include<stdlib.h>

#define NCh 100000      //Veľkosť "pamäte" pre array

struct nodeCh {
    int key;
    struct nodeCh *next;     //Ukazovateľ na daľší prvok - vytvára "chain" (spájaný zoznam)
};

//Základná hashovacia funkcia
int hash(int key) {
    return key % NCh;
}

struct nodeCh *ch[NCh]; //Globálna premenná - array celého hashu

void insertCh(int k) {
    int key;
    struct nodeCh *new = malloc(sizeof(struct nodeCh));
    new->key = k;
    new->next = NULL;

    key = hash(k);

    if(ch[key] == NULL) {   //Ak na danej adrese ešte nieje žiadny prvok, pridáme tam nový prvok
        ch[key] = new;
    } else {                //Ak prvok už existuje, prejdeme na koniec jeho spájaného zoznamu a pripíšeme tam nový prvok
        struct nodeCh *n = ch[key];
        while(n->next) {
            n = n->next;
        }
        n->next = new;
    }
}

struct nodeCh *searchCh(int k) {
    int key = hash(k);
    struct nodeCh *n = ch[key];
    while(n) {
        if(n->key == k) {
            return n;
        }
        n = n->next;
    }
    //Ak nič nenájde, vráti 0
    return 0;
}