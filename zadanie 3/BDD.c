#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct uzol{
    char *hodnota;
    int hlbka;
    struct uzol *lavy;
    struct uzol *pravy;
}uzol;

typedef struct BDD{
    unsigned long int n;          //pocet premennych
    uzol *koren;
    uzol *T;        //uzol konecnej hodnoty 1
    uzol *F;        //uzol konecnej hodnoty 0
}BDD;

typedef struct BF{
    char *vektor;
}BF;

BF *BF_create(char *v) {
        BF *new = malloc(sizeof(BF));
        new->vektor = malloc(strlen(v)+1);
        strcpy(new->vektor, v);
        return new;
}

//Pomocná funkcia ktorá spočíta všetky uzly stromu
int spocitajUzly(struct uzol* u) {
    int n = 1;
    if(!strcmp(u->hodnota,"1") || !strcmp(u->hodnota,"0") || u == NULL || u->lavy == NULL || u->pravy == NULL) {
        return 0;
    }

    n += spocitajUzly(u->lavy);
    n += spocitajUzly(u->pravy);
    return n;
}

//Rekurzívna funkcia vytvárania BDD stromu
uzol *BDD_r(char *v, int h, BDD *bdd) {

    if (h == bdd->n) {
        if(!strcmp(v,"1")) {
            return bdd->T;
        }
        return bdd->F;
    }

    uzol *u = (uzol *)malloc(sizeof(uzol));
    u->hodnota = malloc(strlen(v)+1);
    strcpy(u->hodnota, v);
    u->hlbka = h;

    //Rozdelenie stringu "hodnota" na 2 polovicne stringy
    int len = strlen(v);
    int len1 = len/2;
    int len2 = len - len1;
    char *s1 = malloc(len1+1);
    memcpy(s1, v, len1);
    s1[len1] = '\0';
    char *s2 = malloc(len2+1);
    memcpy(s2, v+len1, len2);
    s2[len2] = '\0';

    u->lavy = BDD_r(s1, h+1, bdd);
    u->pravy = BDD_r(s2, h+1, bdd);

    free(s1);
    free(s2);
    return u;
}

//Inicializácia BDD stromu
BDD *BDD_create(BF *bfunkcia) {
    BDD *b = (BDD *)malloc(sizeof(BDD));
    b->n = log2(strlen(bfunkcia->vektor));
    b->T = (uzol *)malloc(sizeof(uzol));
    b->T->hodnota = malloc(2);
    b->T->hodnota = "1";
    b->T->lavy = NULL;
    b->T->pravy = NULL;
    b->F = (uzol *)malloc(sizeof(uzol));
    b->F->hodnota = malloc(2);
    b->F->hodnota = "0";
    b->F->lavy = NULL;
    b->F->pravy = NULL;
    b->koren = BDD_r(bfunkcia->vektor, 0, b);
    return b;
}

//Pomocná funkcia, uvoľní všetky uzly podstromu
void freeUzly(uzol *u) {
    if (u == NULL)
        return;

    freeUzly(u->lavy);
    freeUzly(u->pravy);

    if(strlen(u->hodnota) > 1) {
        free(u->hodnota);
        u = NULL;
        free(u);
    }
}

//Rekurzívna funkcia redukovania stromu
uzol *BDD_r_r(uzol *u) {
    if((u->pravy == NULL) || (u->lavy == NULL)) {
        return u;
    }
    if(!strcmp(u->lavy->hodnota,u->pravy->hodnota)) {
        freeUzly(u->pravy);
        u = u->lavy;
    } else {
        u->lavy = BDD_r_r(u->lavy);
        u->pravy = BDD_r_r(u->pravy);
    }
    return u;
}

//Opakuje redukovanie až pokým nieje nulový rozdiel medzi počtom uzlov pred a po redukcií.
int BDD_reduce(BDD *bdd) {
    int s = 0, x, y;
    do {
        x = spocitajUzly(bdd->koren) + 2;
        bdd->koren = BDD_r_r(bdd->koren);
        y = spocitajUzly(bdd->koren) + 2;
        s += (x-y);
    } while ((x-y) > 0 && y > 2);
    return s;
}

//Otestuje zadaný vstup
char BDD_use(BDD *bdd, char *vstupy) {
    uzol *u = bdd->koren;
    for(int i = 0; i < bdd->n; i++) {
        if(vstupy[i] == '0' && i == u->hlbka) {
            u = u->lavy;
        } else if(vstupy[i] == '1' && i == u->hlbka) {
            u = u->pravy;
        }
    }
    return u->hodnota[0];
}

//Otestuje všetky možné vstupy zo zadaným počtom premenných
char *BDD_use_all(BDD *bdd, int pocetP) {
    int array[100] = { 0 }, i = 0, j = 0;
    char *s = malloc(pocetP+1);
    char *v = malloc(pow(2,bdd->n)+1);

    while(i >= 0) {
        s[0] = '\0';
        for (i = 0; i < pocetP; i++) {
            s[i] = array[i]+'0';
        }
        s[i] = '\0';
        //printf("%s -> %c\n", s, BDD_use(bdd, s));
        v[j++] = BDD_use(bdd, s);
        for (i = pocetP; i-- > 0; ) {
            array[i] += 1;
            if (array[i] == 2) {
                array[i] = 0;
            } else {
                break;
            }
        }
        if (i < 0) {
            break;
        }
    }
    v[j] = '\0';
    free(s);
    return v;   //Vráti výstupný vektor funkcie
}

//Pomocná (debugovacia) funkcia na vypísanie BDD stromu
void printBDD(struct uzol* u) {
    if (u == NULL)
        return;

    printBDD(u->lavy);
    printf("%s ", u->hodnota);
    printBDD(u->pravy);
}

