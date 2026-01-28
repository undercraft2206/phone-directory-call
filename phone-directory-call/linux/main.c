#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>
#include "file/file-manager.c"

int main(void){

    system("clear");
    
    start:
    printf("\nadd\nlist\nsearch\nremove\nexit\n\nuser: ");

    char choice[6];
    scanf("%s", &choice[0]);

    if (strcmp(choice, "add") == 0) {
        add_function();
        goto start;
    }

    if (strcmp(choice, "list") == 0) {
        list_function();
        goto start;
    }

    if (strcmp(choice, "search") == 0) {
        search_function();
        goto start;
    }

    if (strcmp(choice, "remove") == 0) {
        remove_function();
        goto start;
    }

    if (strcmp(choice, "rename")) {
        printf("\nthe function rename coming soon !\n");
        goto start;
    }

    if (strcmp(choice, "exit")) {
        exit(0);
    }
}