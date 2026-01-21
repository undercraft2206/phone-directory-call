#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file/main-file-manager.c"

int main(void){

    /*clear cmd for windows*/
    system("cls");

    /*choice for user*/
    printf("whats do you want to do:\nadd\nlist\nsearch\n\nuser: ");

    /*make the choice*/
    char choice[6];
    scanf("%s", &choice);

    /*function add*/

    if (strcmp(choice, "add") == 0)
    {
        add();
    }

    /*function list*/

    if (strcmp(choice, "list") == 0)
    {
        list();
    }
    
}