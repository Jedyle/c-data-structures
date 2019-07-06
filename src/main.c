#include "arraylist.h"

int main(int argc, char* argv[]){
  if (argc < 2){
    return 0;
  }
  AList a = ArrayList_create(0);
  for (int i = 1; i < argc; i++){
    ArrayList_append(a, (void* ) atoi(argv[i]));
  }
  ArrayList_display_as_int(a);
  ArrayList_free(a);
}
