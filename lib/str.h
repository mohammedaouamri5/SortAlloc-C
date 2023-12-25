#ifndef str_h
#define str_h

#include <stdlib.h>
typedef struct str {
    int length;
    char* data;
} str;

str strCreate(const char* strIn);

void strSet(str* s, const char* strIn);

char* strGet(str s);

int strSize(str s);

void strExtend(str* s, char* c);

void strFree(str* s);



#endif