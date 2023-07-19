//https://steemit.com/programming/@drifter1/programming-c-hashtables-with-linear-probing

#include <stdio.h>

#define N 10000000

void insertLP(int *table, int table_range, int hash_index, int val);

int searchLP(int *table, int table_range, int val);

void insertLP(int *table, int table_range, int hash_index, int val){

    if(table[hash_index] == -1 && hash_index < table_range){
        table[hash_index] = val;
        return;
    }

    // go to the next index using modulo when it is outside of the array
    hash_index = (hash_index+1) % table_range;

    if(hash_index == val % table_range){
        printf("Hashtable is full!\n");
        return;
    }
    insertLP(table, table_range, hash_index, val);
}

int searchLP(int *table, int table_range, int val){
    int i;
    i = val % table_range;
    // we search the whole array starting from the hashindex
    // cause some value in between could have been deleted
    // and we then would have false results
    do{
        if(table[i] == val){
            return i;
        }
        i = (i+1) % table_range;
    }while(i != val % table_range);
    return -1;
}