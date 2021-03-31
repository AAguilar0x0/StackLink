#include <conio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "myTools.h"
#include "Stack.h"

void getBrackets(char **ptr, int lim, char echo) {
    int count = 0, size = 1;
    char inpt;

    if(*ptr == NULL)
        *ptr = malloc(sizeof(char));
    do{
        fflush(stdin);
        inpt = tolower(getch());
        if(inpt == 8 && count > 0){
            printf("%c %c",inpt,inpt);
            *(*ptr + (--count)) = '\0';
            *ptr = realloc(*ptr, (size = count + 1) * sizeof(char));
        }else if(getReverseBracket(inpt) && count < lim){
            *ptr = realloc(*ptr, (size = ++count + 1) * sizeof(char));
            *(*ptr + (count - 1)) = inpt;
            *(*ptr + count) = '\0';
            printf("%c",(!echo) ? inpt : echo);
        }
    }while(inpt != '\r' || count == 0);
}

int main(void) {
    CONSOLE_SCREEN_BUFFER_INFO info;
    printf("\t\tCheck Brackets Validity\n\n");
    char *symbols = NULL;
    char inpt = '\r';
    while(inpt == '\r') {
        printf("\tBracket Input: ");
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
        getBrackets(&symbols, info.dwSize.X - info.dwCursorPosition.X - 13, '\0');
        printf("\n\n\tResult: \"%s\" is %s\n\n",
			symbols,isValid(symbols) ? "valid" : "invalid");
        printf("\tPress 'Enter' to run again.\n\tAnd any key to exit.");
        inpt = getch();
        free(symbols);
        symbols = NULL;
        gotoxy(0,2);
        delline(6);
        gotoxy(0,2);
    }
    printf("\tProgram Terminated\n");
    sleep(1);

    return 0;
}

