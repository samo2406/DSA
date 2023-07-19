#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "zadanie2_AVL.c"
#include "zadanie2_RB.c"
#include "zadanie2_Ch.c"
#include "zadanie2_LPOA.c"

void testAVL1(int n) {
    printf("========Inkrementacny test AVL=========\n");
    clock_t start = clock();
    struct nodeAVL *node = NULL;
    for(int i = 0; i < n; i++) {
        node = insertAVL(node, i);
    }
    clock_t stop1 = clock();
    double pridavanie = (double)(stop1 - start) * 1000.0 / CLOCKS_PER_SEC;

    for(int i = 0; i < n ; i++) {
        searchAVL(node, i);
    }
    clock_t stop2 = clock();
    double vyhladavanie = (double)(stop2 - stop1) * 1000.0 / CLOCKS_PER_SEC;
    printf("INSERT: %fms | SEARCH: %fms\n", pridavanie, vyhladavanie);
    printf("\n");
}

void testRB1(int n) {
    printf("=========Inkrementacny test RB=========\n");
    clock_t start = clock();
    NILL = malloc(sizeof(struct node));
    NILL->color = BLACK;

    ROOT = NILL;

    for(int i = 0; i < n; i++) {
        red_black_insert(i);
    }
    clock_t stop1 = clock();
    double pridavanie = (double)(stop1 - start) * 1000.0 / CLOCKS_PER_SEC;

    for(int i = 0; i < n; i++) {
        tree_search(i);
    }
    clock_t stop2 = clock();
    double vyhladavanie = (double)(stop2 - stop1) * 1000.0 / CLOCKS_PER_SEC;
    printf("INSERT: %fms | SEARCH: %fms\n", pridavanie, vyhladavanie);
    printf("\n");
}

void testCh1(int n) {
    printf("=====Inkrementacny test Chain Hash=====\n");
    clock_t start = clock();

    for(int i = 0; i < NCh; i++)
        ch[i] = NULL;

    for(int i = 0; i < n; i++) {
        insertCh(i);
    }

    clock_t stop1 = clock();
    double pridavanie = (double)(stop1 - start) * 1000.0 / CLOCKS_PER_SEC;

    for(int i = 0; i < n; i++) {
        searchCh(i);
    }

    clock_t stop2 = clock();
    double vyhladavanie = (double)(stop2 - stop1) * 1000.0 / CLOCKS_PER_SEC;
    printf("INSERT: %fms | SEARCH: %fms\n", pridavanie, vyhladavanie);
    printf("\n");
}

void testLP1(int n) {
    printf("=====Inkrementacny test Linear probing=====\n");
    clock_t start = clock();
    int *table; // hashtable
    table = (int*)malloc(N*sizeof(int));

    for(int i = 0; i < N; i++){
        table[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        insertLP(table, N, i % N, i);
    }

    clock_t stop1 = clock();
    double pridavanie = (double)(stop1 - start) * 1000.0 / CLOCKS_PER_SEC;

    for(int i = 0; i < n; i++) {
        searchLP(table, N, i);
    }

    clock_t stop2 = clock();
    double vyhladavanie = (double)(stop2 - stop1) * 1000.0 / CLOCKS_PER_SEC;
    printf("INSERT: %fms | SEARCH: %fms\n", pridavanie, vyhladavanie);
    printf("\n");
}

void testAVL2(int n) {
    printf("========Nahodny test AVL=========\n");
    clock_t start = clock();
    struct nodeAVL *node = NULL;
    int *a = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000001;
    }

    for(int i = 0; i < n; i++) {
        node = insertAVL(node, a[i]);
    }
    clock_t stop1 = clock();
    double pridavanie = (double)(stop1 - start) * 1000.0 / CLOCKS_PER_SEC;

    for(int i = 0; i < n ; i++) {
        searchAVL(node, a[i]);
    }
    clock_t stop2 = clock();
    double vyhladavanie = (double)(stop2 - stop1) * 1000.0 / CLOCKS_PER_SEC;
    printf("INSERT: %fms | SEARCH: %fms\n", pridavanie, vyhladavanie);
    printf("\n");
}

void testRB2(int n) {
    printf("=========Nahodny test RB=========\n");
    clock_t start = clock();
    NILL = malloc(sizeof(struct node));
    NILL->color = BLACK;
    ROOT = NILL;

    int *a = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000001;
    }

    for(int i = 0; i < n; i++) {
        red_black_insert(a[i]);
    }
    clock_t stop1 = clock();
    double pridavanie = (double)(stop1 - start) * 1000.0 / CLOCKS_PER_SEC;

    for(int i = 0; i < n; i++) {
        tree_search(a[i]);
    }
    clock_t stop2 = clock();
    double vyhladavanie = (double)(stop2 - stop1) * 1000.0 / CLOCKS_PER_SEC;
    printf("INSERT: %fms | SEARCH: %fms\n", pridavanie, vyhladavanie);
    printf("\n");
}

void testCh2(int n) {
    printf("=====Nahodny test Chain Hash=====\n");
    clock_t start = clock();

    int *a = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000001;
    }

    for(int i = 0; i < NCh; i++)
        ch[i] = NULL;

    for(int i = 0; i < n; i++) {
        insertCh(a[i]);
    }

    clock_t stop1 = clock();
    double pridavanie = (double)(stop1 - start) * 1000.0 / CLOCKS_PER_SEC;

    for(int i = 0; i < n; i++) {
        searchCh(a[i]);
    }

    clock_t stop2 = clock();
    double vyhladavanie = (double)(stop2 - stop1) * 1000.0 / CLOCKS_PER_SEC;
    printf("INSERT: %fms | SEARCH: %fms\n", pridavanie, vyhladavanie);
    printf("\n");
}

void testLP2(int n) {
    printf("=====Nahodny test Linear probing=====\n");
    clock_t start = clock();
    int *table; // hashtable
    table = (int*)malloc(N*sizeof(int));

    int *a = (int*) malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10000001;
    }

    for(int i = 0; i < N; i++){
        table[i] = -1;
    }

    for(int i = 0; i < n; i++) {
        insertLP(table, N, a[i] % N, a[i]);
    }

    clock_t stop1 = clock();
    double pridavanie = (double)(stop1 - start) * 1000.0 / CLOCKS_PER_SEC;

    for(int i = 0; i < n; i++) {
        searchLP(table, N, a[i]);
    }

    clock_t stop2 = clock();
    double vyhladavanie = (double)(stop2 - stop1) * 1000.0 / CLOCKS_PER_SEC;
    printf("INSERT: %fms | SEARCH: %fms\n", pridavanie, vyhladavanie);
    printf("\n");
}

int main() {
    testAVL1(1000000);
    testRB1(1000000);
    testCh1(1000000);
    testLP1(1000000);
    testAVL2(1000000);
    testRB2(1000000);
    testCh2(1000000);
    testLP2(50000);
}