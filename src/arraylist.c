#include <stdlib.h>
#include "arraylist.h"

struct ArrayList{
  unsigned int size;
  int array_length;
  void** array;
};

#define ARRAY_LEN_INIT 5

AList ArrayList_create(unsigned int size){
  AList a = malloc(sizeof(struct ArrayList));
  int array_length = (size == 0 ? ARRAY_LEN_INIT : size*2);
  a->size = size;
  a->array_length = array_length;
  a->array = malloc(sizeof(void*) * array_length);
  return a;
}


void ArrayList_free(AList a){
  free(a->array);
  free(a);
}


void* ArrayList_get(AList a, unsigned int index){
  if (a->size <= index){
    return NULL;
  }
  return a->array[index];
}

int ArrayList_set(AList a, unsigned int index, void* value){
  if (a->size <= index){
    return 0;
  }
  a->array[index] = value;
  return 1;
}

void ArrayList_append(AList a, void* value){
  if (a->size >= a->array_length){
    a->array = realloc(a->array, sizeof(void*) * a->size * 2);
  }
  a->array[a->size] = value;
  a->size++;
}


size_t ArrayList_length(AList a){
  return a->size;
}


void ArrayList_display_as_int(AList a){
  for (int i = 0; i < a->size; i++){
    printf("%d ", (int) a->array[i]);
  }
  printf("\n");
}
