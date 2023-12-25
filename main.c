// ? Libraries =====================================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "lib/str.h" // my srting library 
#include "lib/csv.h" // my csv library


// ? Macros ========================================================================================
#define MAX_PATH_LEN 256 // Max length of a path in windows is 256 characters
#define MAX_LINE_SIZE 1024 // Max length of a line in a CSV file
#define clearScreen system("cls") // Clear the screen in windows (clear in linux)


// ? functions =====================================================================================

// ? getFieldsNum : get the number of fields in a CSV file

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


// ? Main ==========================================================================================
int main() {
    // * Variables ------------------------------------------------------------------------------
    FILE *fp; // File pointer
    char path[MAX_PATH_LEN] ;

    // * Part 1 : get a path from the user ------------------------------------------------------
    do
    {
        clearScreen;
        printf("Enter a path: ");
        scanf("%s", path);
        fp = fopen(path, "r");
    } while (fp == NULL);
    // *Part 2 : get the number of the fields of the CSV file------------------------------------
    
    char line[MAX_LINE_SIZE] ;
    
    int fieldsNum = getFieldsNum(fp);
    printf("Fields number: %d\n", fieldsNum);
    printf("the first line: %s\n", fgets(line, MAX_LINE_SIZE, fp));


    // *Part 3 : choosing the alocation method ------------------------------------------------
    int choice;
    printf("Choose the alocation method:\n");
    printf("    1- Array\n");
    printf("    2- Linked List\n");
    printf("    3- binary tree\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);
    } while (choice < 1 || choice > 3);
    
    printf("Fields number: %d\n", fieldsNum);
    // using strtoc


    printf("End ...\n");
    return 0;
}
