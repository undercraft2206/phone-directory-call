#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file/main-file-manager.c"

int main(void){

    start:

    /*clear cmd for windows*/
    system("cls");

    /*choice for user*/
    printf("whats do you want to do:\nadd\nremove (coming soon !)\nlist\nsearch\n\n");

    /*start user interaction*/
    userinput:
    printf("user: ");

    /*make the choice*/
    char choice[6];
    scanf("%s", &choice);

    /*function add*/

    if (strcmp(choice, "add") == 0)
    {
        add();
        goto start;
    }

    /*function list*/

    if (strcmp(choice, "list") == 0)
    {
        list();
    }
    
    /*function search*/
    
    if (strcmp(choice, "search") == 0)
    {
        search();
    }

    if (strcmp(choice, "remove") == 0)
    {
        printf("coming soon !\n\n");
        goto userinput;
    }
    
}