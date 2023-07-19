#include<stdlib.h>

struct nodeAVL {
    int height;
    int key;
    struct nodeAVL *left;
    struct nodeAVL *right;
};

int getHeight(struct nodeAVL *x) {
    if (x == NULL) {
        return 0;
    }
    return x->height;
}

int maxAVL(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }
}

struct nodeAVL *rotateL(struct nodeAVL *n) {
    //Rotácia stromu doľava
    struct nodeAVL *n1 = n->right, *n2 = n1->left;
    n1->left = n;
    n->right = n2;
    n->height = maxAVL(getHeight(n->left), getHeight(n->right)) + 1;
    n1->height = maxAVL(getHeight(n1->left), getHeight(n1->right)) + 1;
    return n1;
}

struct nodeAVL *rotateR(struct nodeAVL *n) {
    //Rotácia stromu doprava
    struct nodeAVL *n1 = n->left, *n2 = n1->right;
    n1->right = n;
    n->left = n2;
    n->height = maxAVL(getHeight(n->left), getHeight(n->right)) + 1;
    n1->height = maxAVL(getHeight(n1->left), getHeight(n1->right)) + 1;
    return n1;
}

struct nodeAVL* insertAVL(struct nodeAVL* n, int x) {
    //Ak n == NULL do vrchola len vložíme kľúč a nastavíme LEFT a RIGHT na NULL
    if (n == NULL) {
        struct nodeAVL *new = (struct nodeAVL*) malloc(sizeof(struct nodeAVL));
        new->key = x;
        new->right = NULL;
        new->left = NULL;
        new->height = 1;
        return (new);
    }
    //Vloženie do stromu
    if (x < n->key) {
        n->left = insertAVL(n->left, x);
    } else if (x > n->key) {
        n->right = insertAVL(n->right, x);
    } else {
        return n;
    }

    n->height = 1 + maxAVL(getHeight(n->left), getHeight(n->right));   //Nastavenie výšky vyššieho uzla

    //"Vybalancovanosť" stromu
    int b = 0;
    if (n != NULL) {
        b = getHeight(n->left) - getHeight(n->right);
    }
    //Možnosti rotácie:
    if (b < -1 && x > n->right->key) {
        return rotateL(n);
    } else if (b < -1 && x < n->right->key) {
        n->right = rotateR(n->right);
        return rotateL(n);
    }else if (b > 1 && x < n->left->key) {
        return rotateR(n);
    } else if (b > 1 && x > n->left->key) {
        n->left =  rotateL(n->left);
        return rotateR(n);
    }
    return n;
}

struct nodeAVL* searchAVL(struct nodeAVL* n, int key)
{
    //AK sa koreň n == NULL alebo ak je hľadaný kľúč už v koreni, ukončíme hľadanie
    if (n == NULL || n->key == key)
        return n;

    if (n->key > key) {
        return searchAVL(n->left, key);
    } else {
        return searchAVL(n->right, key);
    }
}