#include <assert.h>
#include <stdio.h>
#include "arraylist.h"
#include "utils.h"

void test_ok(){
  ASSERT(1);
  SUCCESS;
}


void test_ArrayList_create_and_free(){
  AList a = ArrayList_create(0);
  ArrayList_free(a);
  SUCCESS;
}


void test_ArrayList_get_and_set(){
  AList a = ArrayList_create(5);
  int val = 5;
  int success = ArrayList_set(a, 0, (void*) val);
  ASSERT(success);
  int value_stored = (int) ArrayList_get(a, 0);
  ASSERT(value_stored == val);
  ArrayList_free(a);
  SUCCESS;
}


void test_ArrayList_append(){
  AList a = ArrayList_create(0);
  ASSERT(ArrayList_get(a, 0) == NULL);
  ArrayList_append(a, 1);
  ASSERT(ArrayList_get(a, 0) == 1);
  ArrayList_append(a, 2);
  ASSERT(ArrayList_get(a, 1) == 2);
  ArrayList_append(a, 3);
  ASSERT(ArrayList_get(a, 2) == 3);
  ArrayList_append(a, 4);
  ASSERT(ArrayList_get(a, 3) == 4);
  ArrayList_free(a);
  SUCCESS;
}


void test_ArrayList_append_batch(){
  AList a = ArrayList_create(0);
  int tab[50];
  for (int i = 0; i<50; i++){
    tab[i] = i;
  }
  for (int i = 0; i<50; i++){
    ArrayList_append(a, tab[i]);
    ASSERT(ArrayList_length(a) == i+1);
  }
  for (int i = 0; i<50; i++){
    ArrayList_append(a, i);
    ASSERT(ArrayList_get(a, i) == tab[i]);
  }
  ArrayList_free(a);
  SUCCESS;
}


int main(){
  printf("---------------- Testing ---------------\n");
  test_ok();
  test_ArrayList_create_and_free();
  test_ArrayList_get_and_set();
  test_ArrayList_append();
  test_ArrayList_append_batch();
}
