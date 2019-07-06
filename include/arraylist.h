#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#define ERROR -12056
struct ArrayList;

typedef struct ArrayList* AList;

AList ArrayList_create();
void ArrayList_free(AList);

void* ArrayList_get(AList a, unsigned int index);
int ArrayList_set(AList a, unsigned int index, void* value);

void ArrayList_append(AList a, void* value);

void ArrayList_display_as_int(AList a);

#endif
