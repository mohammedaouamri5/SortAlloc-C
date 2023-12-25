#include "str.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


str strCreate(const char* strIn) {
    str s;

    if (strIn != NULL) {
        s.length = strlen(strIn);
        s.data = malloc(s.length + 1);
        strcpy(s.data, strIn);
    } else {
        s.length = 0;
        s.data = malloc(1);
        s.data[0] = '\0';
    }

    return s;
}

void strSet(str* s, const char* strIn) {
    if (strIn != NULL) {
        s->length = strlen(strIn);
        s->data = realloc(s->data, s->length + 1);
        strcpy(s->data, strIn);
    } else {
        s->length = 0;
        s->data = realloc(s->data, 1);
        s->data[0] = '\0';
    }
}

char* strGet(str s) {
    return s.data;
}

int strSize(str s) {
    return s.length;
}

void strExtend(str* s, char* c) {
    int len = strlen(c);
    s->data = realloc(s->data, s->length + len + 1);
    strcat(s->data, c);
    s->length += len;
    s->data[s->length] = '\0';
}

void strFree(str* s) {
    free(s->data);
}

