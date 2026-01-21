#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(void){
    /*make the file pointer*/

    FILE *ptr;

    /*verfication if the file exist*/

    /*open the file in read mode*/

    ptr = fopen("phone.txt", "r");

    if (ptr == NULL)
    {
        /*informate the user*/
        printf("file not found\ncreating one");

        /*create the file with write mode*/
        fopen("phone.txt", "w");

        /*informate the user*/
        printf("created");
    }

    fclose(ptr);

    /*make variable*/
    
    char name[60];
    int numero[13];

    /*get information*/

    printf("\nname: ");
    scanf("%s", &name);

    printf("\nnuméro: ");
    scanf("%d", &numero);

    /*print information to file*/

    ptr = fopen("phone.txt", "a");

    fprintf(ptr, "name: %s\nnumero: %s", name, numero);

    /*close the file*/

    fclose(ptr);
}

void list(void){

    /*make the file pointer*/

    FILE *ptr;

    /*open the file in read mode for see if file existe*/

    ptr = fopen("phone.txt", "r");

    if (ptr == NULL)
    {
        /*informate the user*/
        perror("file not found");
        printf("creating one...\n");

        /*create the file*/
        fopen("phone.txt", "w");

        /*print to restart the programme*/
        printf("file created\nplease restart the programme");

        /*close the file and exit with errore*/
        fclose(ptr);
        exit(-1);
    }
    
    /*make variable*/
    char output[10000];

    /*read file*/
    fread(&output, sizeof(char), 1000, ptr);

    /*print the file*/
    puts(output);

    /*close the file*/
    fclose(ptr);
}

void search(void){
    /*make the file pointer*/
    FILE *ptr;

    /*make variable*/
    char output[2000], search[60];
    int i;

    /*read the file with output as a var*/
    fread(&output, sizeof(char), 2000, ptr);
}