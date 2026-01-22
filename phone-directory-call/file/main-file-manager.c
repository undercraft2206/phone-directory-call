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

    fprintf(ptr, "\nname: %s\nnumero: %s", name, numero);

    /*close the file*/

    fclose(ptr);
}

/*function list*/

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
<<<<<<< HEAD
}

/*function search*/

void search(void){
    /*make the file pointer*/
    FILE *ptr;

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
    char output[1000], search[60];
    int i = 1, num = 0;

    /*take information*/
    printf("name: ");
    scanf("%s", &search);

    /*clear cmd for windows */
    system("cls");

    /*take information*/
    printf("name searched: '%s'\n\n", search);

    /*open file in read mod*/
    ptr = fopen("phone.txt", "r");

    /*search the word*/
    while (!feof(ptr)){

        /*take the string and add it to output as a variable*/
        fscanf(ptr, "%s", output);

        /*look if string match with the word*/
        if (strcmp(output, search) == 0 ){

        /*add 1 to the variable to num*/
        num++;

        /*informate the user*/
        printf("name: %s", output);

        /*go to number after*/
        fscanf(ptr, "%s", output);
        fscanf(ptr, "%s", output);

        /*print number of the user*/
        printf("\nnumber: %s\n\n", output);
        }        
    }

    if (num == 0)
    {
        printf("sorry... we don't found any %s in the file", search);
        fclose(ptr);
        exit(0);
    } else{
        printf("we found the name '%s' %d time\n\n", search, num);
        fclose(ptr);
    }
}

