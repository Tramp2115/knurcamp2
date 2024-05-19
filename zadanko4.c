#include <stdio.h>

//Zadanie 3:
//Poproś użytkownika o podanie 1 liczby całkowitej N.
//Wypisz ciąg fibonacziego do liczby N.

int main(int argc, char *argv[]) {
    int n, t1 = 0, t2 = 1, nextTerm;
    printf("Podaj 1 zmienna: ");
    scanf("%d", &n);
    if(n < 1) {
        printf("Zla wartosc\n");
    }
    printf("Ciag fibbonaciego\n");

    for(int i = 0; i <= n; i++) {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}
