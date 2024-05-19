#include <stdio.h>
#include <string.h>

//Poproś użytkownika o podanie 2 stringów.
//Połącz te 2 stringi ze sobą i zapisz je do pliku dupa.txt.

int main(int argc, char *argv[]) {

    char s1 [100];
    char s2 [100];
    char  finalString[200];
    printf("Podaj pierwszy string: ");
    scanf("%s",s1);
    printf("Podaj pierwszy string: ");
    scanf("%s",s2);

    strcat(finalString, s1);
    strcat(finalString, s2);

    FILE *uchwyt;

    uchwyt = fopen("dupa.txt", "w");

    fprintf(uchwyt, finalString);

    fclose(uchwyt);

    return 0;
}
