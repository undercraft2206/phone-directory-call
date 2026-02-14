#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//add function

void add_function(void){

    //clear the cli and say the name of function

    system("clear");
    printf("function add\n\n");

    //make file pointer

    FILE *ptr;

    //open file phone.txt

    ptr = fopen("phone.txt", "a");

    //make var

    char name[60];
    int number[15];

    //ask user information

    printf("\n\nname: ");
    scanf("%s", &name[0]);

    printf("\n\nnumber: ");
    scanf("%d", &number[0]);

    //print result to phone.txt

    fprintf(ptr, "name: %s\nnumber: %d\n\n", name, number[0]);

    //close file pointer

    fclose(ptr);
}

//function list

void list_function(void){

    //make file pointer and var
    
    char output[2000];
    FILE *ptr;

    //open file

    ptr = fopen("phone.txt", "r");

    //look if the file don't exist

    if (ptr == NULL) {

        //informate the user

        perror("\n\nfile not found");
        printf("creating one file...\n");

        //open file in write mode for create one

        fopen("phone.txt", "w");

        //informate the user

        printf("file created !\n\n");

        //close file pointer

        fclose(ptr);
    }

    //clear the terminal and say to the user the name of function called

    system("clear");
    printf("function: list\n");

    //start the while for list all the name and number in the file

    while (!feof(ptr)) {

        //scan the word in phone.txt

        fscanf(ptr, "%s", output);

        //look if the output = "end"

        if(strcmp(output, "end") == 0){

            //then stop the while

            break;
        
        }

        //print the result

        printf("\n%s", output);

        fscanf(ptr, "%s", output);
        
        if(strcmp(output, "end") == 0){
            break;
        }

        printf("%s\n", output);

    }

    //close file pointer

    fclose(ptr);

}

//search function

void search_function(void){
    
    //make var

    char name[60];
    char ouput[2000];
    int num = 0;

    //make file pointer

    FILE *ptr;

    //open file phone.txt

    ptr = fopen("phone.txt", "r");

    //look if the file exist

    if (ptr == NULL) {

        //informate the user
        
        perror("file not found");
        printf("creating the file...");

        //open the file in write mode to create the file

        fopen("phone.txt", "w");

        //informate the user

        printf("file created !");
        
        //go to the end of the file

        goto end;
    }

    //ask user information

    printf("name: ");
    scanf("%s", &name[0]);

    //print function and name searched

    system("clear");
    printf("searching: %s\nfunction search\n\n", name);

    //start the search

    while (!feof(ptr)){

        //scan the word in phone.txt

        fscanf(ptr, "%s", ouput);

        //look if the word of the output is the name searched

        if (strcmp(name, ouput) == 0) {

            //add 1 to num for say the number of time we found this name

            num = num + 1;

            //scan the number of the name

            fscanf(ptr, "%s", ouput);
            fscanf(ptr, "%s", ouput);

            //print result

            printf("\nname: %s\nnumber: %s\n", name, ouput);
        }
    }

    //if num = 0 then tell the user we don't find the name in the file

    if (num == 0) {

        //informate the user

        printf("\n\nsorry... we don't have found any %s in the file", name);
    
    } else {
    
        //informate the user

        printf("\n\nwe found the name %s %d time\n\n", name, num);
    
    }

    end:
}

//remove function

void remove_function(void){
    
    //make var

    char name[60];
    char output[2000];
    char clone[2000];

    //make file pointer

    FILE *ptr;
    FILE *tempo;

    //open file "phone.txt" and "tempo.txt"

    tempo = fopen("tempo.txt", "w");
    ptr = fopen("phone.txt", "r");

    //look if the file exist

    if (ptr == NULL) {

        //informate the user

        perror("file not found");
        printf("creating one...\n");
    
        //open the file in write mode for create the file

        fopen("phone.txt", "w");

        //informate the user

        printf("file created !\n\n");

        //goto end of the file

        goto end;
    }

    //ask user information

    printf("name: ");
    scanf("%s", &name[0]);

    //print name of function and the name who will be removed

    system("clear");
    printf("function: remove\nremoving: %s\n\n", name);

    //start the while

    while (!feof(ptr)){

        //scan word
        fscanf(ptr, "%s", output);

        //look if the output and and the name match

        startwhile:

        if (strcmp(name, output) == 0) {
            
            //scan for the next nale
        
            fscanf(ptr, "%s", output);
            fscanf(ptr, "%s", output);
            fscanf(ptr, "%s", output);
            fscanf(ptr, "%s", output);

            //goto start while for see if the next name match with the output

            goto startwhile;
        }

        //if output match with string: "name:" or "number:"

        if ((strcmp(output, "name:") == 0) || (strcmp(output, "number:") == 0)) {
            
            //scan for next word

            fscanf(ptr, "%s", output);
            
            //goto start of the while
            
            goto startwhile;
        }

        //print the output to the file

        fprintf(tempo, "%s\n", output);
    }

    //clos file pointer

    fclose(ptr);
    fclose(tempo);

    //open file

    ptr = fopen("phone.txt", "w");
    tempo = fopen("tempo.txt", "r");

    //start the while for copy tempo.txt to phone.txt

    while(!feof(tempo)) {

        //scan for word in tempo.txt

        fscanf(tempo, "%s", output);
        
        //look if output match with "end"

        if (strcmp(output, "end") == 0){

            //then exit the while
            
            break;

        }

        //print output to file tempo.txt

        fprintf(ptr, "name: %s\n", output);

        //scan for the next word and print the result

        fscanf(tempo, "%s", output);
        fprintf(ptr, "number: %s\n\n", output);

    }

    //print end to file phone.txt

    fprintf(ptr, "\nend");

    end:

    //close file pointer and remove the tempo file

    fclose(ptr);

    fclose(tempo);
    remove("tempo.txt");
}

//rename function

void rename_function(void){

    //make a var
    
    char choice[6];

    //ask the user

    printf("\nname or number: ");
    scanf("%s", &choice);

    //if user say "name"

    if(strcmp(choice, "name") == 0){

        //make var
        
        char name[60];
        char change[60];

        //ask user informatiown
        
        printf("\nname to change: ");
        scanf("%s", &name);

        printf("name: ");
        scanf("%s", &change);

        system("clear");
        printf("function: rename\nname: %s to %s\n\n", name, change);

        //make a var

        char output[200];

        //make file pointer

        FILE *ptr;
        FILE *tempo;

        //open file

        ptr = fopen("phone.txt", "r");
        tempo = fopen("tempo.txt", "w");

        //if ptr = NULL do create file and exit

        if(ptr == NULL){

            //informate the user

            perror("file not found");
            printf("creating one...\n");

            //create the file

            ptr = fopen("phone.txt", "w");
            fprintf(ptr, "\nend");

            //say to the user, file created !

            printf("file created succesfully !");

            //close file and delete tempo file

            fclose(ptr);
            fclose(tempo);
            remove("tempo.txt");
            
            //exit

            exit(0);

        }


        //start the copy to tempo.txt

        while(!feof(ptr) == 1){

            start:

            //scan

            fscanf(ptr, "%s", output);

            //check if the word is end

            if(strcmp(output, "end") == 0){

                //the word = end

                fprintf(tempo, "\n\nend");

                //close file

                fclose(ptr);
                fclose(tempo);

                //exit the while function

                break;
            }

            //check for name or number

            if(strcmp(output, "name:") == 0 || strcmp(output, "number:") == 0){
              
                //scan for the next word

                fscanf(ptr, "%s", output);
            
            }

            //check if the word is the name wanted

            if(strcmp(name, output) == 0){

                //print the new name to the file tempo.txt

                fprintf(tempo, "%s\n", change);

                //scan the number

                fscanf(ptr, "%s", output);
                fscanf(ptr, "%s", output);

                //print word

                fprintf(tempo, "%s\n", output);
             
                //goto the start of while

                goto start;

            }

            //then if the word is not: "name", "number", "end", "name", so print the result to tempo.txt

            fprintf(tempo, "%s\n", output);

        }

        //open file

        ptr = fopen("phone.txt", "w");
        tempo = fopen("tempo.txt", "r");

        //start the while for copy the tempo.txt to phone.txt with change

        while (!feof(tempo))
        {

            //scan word

            fscanf(tempo, "%s", output);

            //if the word is "end"

            if (strcmp(output, "end") == 0)
            {
                //stop the while

                break;
            
            }

            //print word to phone.txt

            fprintf(ptr, "name: %s\n", output);

            fscanf(tempo, "%s", output);
            
            if (strcmp(output, "end") == 0)
            {
               break;
            }

            fprintf(ptr, "number: %s\n\n", output);
     
        }

        //print the end of the file tempo.txt

        fprintf(ptr, "\nend");

        //close file pointer and remove the file tempo.txt

        fclose(ptr);
        fclose(tempo);            
        remove("tempo.txt");

        //say to the user the name have been changed

        printf("the name '%s' have been changed to '%s'", name, change);        
    }
}
