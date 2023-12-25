#include "csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define MAX_LINE_SIZE 1024 // Max length of a line in a CSV file


// ? ========================================================================
// ? Record data types manupulation
// ? ========================================================================

int getFieldsNum(FILE *fp){
    int fieldsNum = 0;
    char *line = (char *)malloc(MAX_LINE_SIZE * sizeof(char));
    char *token = strtok(line, ",");
    while (token != NULL) {
        fieldsNum++;
        token = strtok(NULL, ",");
    }
    rewind(fp); // return the pointer to the begining of the file
    return fieldsNum;
}

int getLinesNum(FILE *fp){
    int linesNum = 0;
    char *line = (char *)malloc(MAX_LINE_SIZE * sizeof(char));
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        linesNum++;
    }
    rewind(fp); // return the pointer to the begining of the file
    return linesNum;
}



// create recorde 

Record RecordCreate(int FieldsNum){
    Record record;
    record.fields = strArrayCreate(FieldsNum-1); // FieldsNum = id + fields
    return record;
}

void SetRecord(Record *record, int id, strArray fields){
    record->id = id;
    record->fields = fields;
}



void PrintRecord(Record record){
    printf("{\n");
    printf("    id: %d\n", record.id);
    printf("    fields: ");
    strArrayPrint(record.fields);
    printf("\n}");
}

// * RecordArray --------------------------------------------------------------

RecordArray CreateRecordArray(int length, int fieldsNum){
    RecordArray arr;
    arr.length = length;
    arr.data = malloc(sizeof(Record) * length);
    for (int i = 0; i < length; i++) {
        arr.data[i] = RecordCreate(fieldsNum-1);
    }
    return arr;
}

void PrintRecordArray(RecordArray arr){
    printf("[\n");
    for (int i = 0; i < arr.length; i++) {
        PrintRecord(arr.data[i]);
        printf(",\n");
    }
    printf("]\n");
}
// ? ========================================================================
// ? CSV store data
// ? ========================================================================


RecordArray ArrStoreCSV(FILE *fp){
    int fieldsNum = getFieldsNum(fp);
    int linesNum = getLinesNum(fp);
    RecordArray arr = CreateRecordArray(linesNum, fieldsNum);
    arr.length = linesNum;

    char *line = (char *)malloc(MAX_LINE_SIZE * sizeof(char));
    char *token = strtok(line, ",");
    int recLine=0, recField=0;
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        // get the first token as int (the id)
        int id = atoi(strtok(line, ","));
        arr.data[recLine].id = id;
        token = strtok(line, ",");
        while (token != NULL) {
            strArraySet(&arr.data[recLine].fields, recField, token);
            recField++;
            token = strtok(NULL, ",");
        }
        recLine++;
    }
    return arr;
}


// RecordLinkedList StoreCSVList(FILE *fl){
//     RecordLinkedList list;
//     list.head = NULL;
//     list.tail = NULL;
//     list.length = 0;
//     char *line = (char *)malloc(MAX_LINE_SIZE * sizeof(char));
//     char *token = strtok(line, ",");
//     int i = 0;
//     while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
//         RecordNode *node = (RecordNode *)malloc(sizeof(RecordNode));
//         node->data.id = i;
//         node->data.fields = strArrayCreate(fieldsNum);
//         token = strtok(line, ",");
//         while (token != NULL) {
//             strArrayPush(&node->data.fields, token);
//             token = strtok(NULL, ",");
//         }
//         node->next = NULL;
//         if (list.head == NULL) {
//             list.head = node;
//             list.tail = node;
//         } else {
//             list.tail->next = node;
//             list.tail = node;
//         }
//         list.length++;
//         i++;
//     }
//     return list;
// }



// ! el mechkl fi strArray lazm nl9alha 7all
