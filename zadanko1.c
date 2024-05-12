/* NIE DOTYKAJ */
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void weryfikacja1(void* ss, int sz)
{
    // Mapowanie void'a na char'a (Mapowanie miejsca w pamięci który zawiera Janka)
    char* st = (char*)ss;
    // Pobranie wieku za pomocą wskazania na zmapoowany adres
    int wiek = *st;

    //Instrukcja warunkowa sprawdzająca czy wiek nie jest równy 105, jeśli nie jest to spierdalaj próbuj ponownie.
    if(wiek != 105)
    {
        printf("Błędne rozwiązanie\n");
        return;
    }

    // przeskoczenie w pamięci do miejsca gdzie znajduje się imie. W struct'cie są 3 pola więc dzielimy struct na 3 aby dojść do kolejnych pól.
    st += sz / 3;

    //Pobranie pointera do naszego imienia
    uint64_t imiePtr = (*(uint64_t*)st);

    //Mapowanie pointer'a do imienia na stringa
    char* imie = (char*)imiePtr;

    // Kolejne przeskoczenie w pamięci, tym razem do wzrostu.
    st += sz / 3;

    // Tak samo jak w poprzedniej instrukcji, tylko sprawdzana jest poprawność imienia.
    if(strcmp(imie, "Jan") != 0)
    {
        printf("Błędne rozwiązanie\n");
        return;
    }

    // Mapowanie reszty pamięci na float
    float wzrost = *(float*)st;

    // Tak samo jak w poprzedniej instrukcji, tylko sprawdzana jest poprawność imienia. Wraz z końcem jest koniec funkcji.
    if(wzrost < 2.138 && wzrost > 2.136)
    {
        printf("Brawo poprawne rozwiązanie\n");
    }
    else
    {
        printf("Ups, błędne rozwiązanie\n");
    }
}
/* KONIEC SEKCJI NIE DOTYKAJ */

/*
 Treść zadania:

 Stwórz strukturę o nazwie `czlowiek`.
 Zrób żeby zawierała następujące pola:
 - `wiek` <- liczba całkowita (rozmiar standardowy)
 - `imie` <- no jego imie a co xD (ptr do stringa)
 - `wzrost` <- liczba zmiennoprzecinkowa w metrach amerykańskich np 1.234

 Stwórz człowieka o imieniu `Jan`, wieku 105 lat, wzroście 2 m 137 cm (w metrach amerykańskich - 1 metr = 1000 cm - 2m 137cm = 2.137)
 Pola wiek, imie, i wzrost muszą mieć taką samą koleność.

 Uruchom funckje `weryfikacja1` ze swojej funkcji main podając wskaźnik do człowieka oraz rozmiar struktury człowiek jako drugi parametr.

 ***** Zadanie na 6 albo gwiazdke jak zwał tak zwał *****
 Opisz co robi po kolei funckja `void weryfikacja1(void* ss, int sz)`
*/

struct czlowiek {
    int wiek;
    char* imie;
    float wzrost;
};

int main(int argc, char *argv[])
{
    struct czlowiek jan;

    jan.wiek = 105;
    jan.imie = "Jan";
    jan.wzrost = 2.137;

    weryfikacja1( &jan, sizeof(struct czlowiek));

   return 0;
}