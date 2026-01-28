#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_function(void){
    system("cls");
    printf("function add\n\n");

    FILE *ptr;

    ptr = fopen("phone.txt", "a");

    char name[60];
    int number[15];


    printf("\n\nname: ");
    scanf("%s", &name[0]);

    printf("\n\nnumber: ");
    scanf("%d", &number[0]);

    ptr = fopen("phone.txt", "a");

    fprintf(ptr, "name: %s\nnumber: %d\n\n", name, number[0]);

    fclose(ptr);
}

void list_function(void){
    
    char ouput[2000];
    FILE *ptr;

    ptr = fopen("phone.txt", "r");

    if (ptr == NULL) {

        perror("\n\nfile not found");
        printf("creating one file...\n");

        fopen("phone.txt", "w");

        printf("file created !\n\n");
    }

    printf("start searching...\n\n");

    while (!feof(ptr)) {

        fscanf(ptr, "%s", ouput);
        printf("\nname: %s", ouput);

        fscanf(ptr, "%s", ouput);
        printf("\nnumber: %s\n", ouput);

    }

    fclose(ptr);

}

void search_function(void){
    
    char name[60];
    char ouput[2000];
    int num;

    FILE *ptr;

    ptr = fopen("phone.txt", "r");

    if (ptr == NULL) {
        
        perror("file not found");
        printf("creating the file...");

        fopen("phone.txt", "w");

        printf("file created !");
        exit(-1);

    }
    
    printf("name: ");
    scanf("%s", &name[0]);

    system("cls");
    printf("searching: %s\nfunction search\n\n", name);

    while (!feof(ptr)) {
        fscanf(ptr, "%s", ouput);

        if (strcmp(name, ouput) == 0) {
            num = num + 1;

            fscanf(ptr, "%s", ouput);
            fscanf(ptr, "%s", ouput);

            printf("\nname: %s\nnumber: %s\n", name, ouput);
        }
    }

    if (num == 1) {
        printf("\n\nsorry... we don't have found any %s in the file", name);
    } else {
        printf("\n\nwe found the name %s %d time\n\n", name, num);
    }
}


void remove_function(void){
    
    char name[60];
    char output[2000];
    char clone[2000];

    FILE *ptr;
    FILE *tempo;

    tempo = fopen("tempo.txt", "w");
    ptr = fopen("phone.txt", "r");

    if (ptr == NULL) {
        perror("file not found");
        printf("creating one...\n");
    
        fopen("phone.txt", "w");

        printf("file created !\n\n");

        exit(-1);
    }

    printf("name: ");
    scanf("%s", &name[0]);

    system("cls");
    printf("function: remove\n");
    printf("removing: %s\n\n", name);

    while (!feof(ptr)) {
        fscanf(ptr, "%s", output);

        startwhile:
        if (strcmp(name, output) == 0) {
            fscanf(ptr, "%s", output);
            fscanf(ptr, "%s", output);
            fscanf(ptr, "%s", output);
            fscanf(ptr, "%s", output);
            goto startwhile;
        }
        if ((strcmp(output, "name:") == 0) || (strcmp(output, "number:") == 0)) {
            fscanf(ptr, "%s", output);
            goto startwhile;
        }

        fprintf(tempo, "%s\n", output);
    }

    fclose(ptr);
    fclose(tempo);

    ptr = fopen("phone.txt", "w");
    tempo = fopen("tempo.txt", "r");

    while(!feof(tempo)) {
        fscanf(tempo, "%s", output);
        if (strcmp(output, "end") == 0) {
            break;
        }
        fprintf(ptr, "name: %s\n", output);

        fscanf(tempo, "%s", output);
        fprintf(ptr, "number: %s\n\n", output);
    }

    fprintf(ptr, "\nend");
}