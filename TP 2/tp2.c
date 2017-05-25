#include <stdio.h>
#include <string.h>

int automataPalabrasReservadas (char[]);
int valoresPalabrasResevadas (char);

void main ()
{
    char palabra[10];
    scanf("%s", palabra);
    printf("%i",automataPalabrasReservadas(palabra));
}

int valoresPalabrasResevadas (char caracter)
{
    switch (caracter)
    {
    case 'i':
        return 0;
    case 'f':
        return 1;
    case 'e':
        return 2;
    case 'l':
        return 3;
    case 's':
        return 4;
    case 'w':
        return 5;
    case 'h':
        return 6;
    case 'n':
        return 7;
    case 't':
        return 8;
    case 'o':
        return 9;
    case 'a':
        return 10;
    default:
        return -1;
    }
}

int automataPalabrasReservadas (char cadena[])
{
    int i, valorCaracter, estado = 0;
    int transiciones[][11] = {{1,9,3,13,13,6,13,13,13,13,13},
                            {13,12,13,13,13,13,13,2,13,13,13},
                            {13,13,13,13,13,13,13,13,12,13,13},
                            {13,13,13,4,13,13,13,13,13,13,13},
                            {13,13,13,13,5,13,13,13,13,13,13},
                            {13,13,12,13,13,13,13,13,13,13,13},
                            {13,13,13,13,13,13,7,13,13,13,13},
                            {8,13,13,13,13,13,13,13,13,13,13},
                            {13,13,13,5,13,13,13,13,13,13,13},
                            {13,13,13,10,13,13,13,13,13,13,13},
                            {13,13,13,13,13,13,13,13,13,11,13},
                            {13,13,13,13,13,13,13,13,13,13,2},
                            {13,13,13,13,13,13,13,13,13,13,13},
                            {13,13,13,13,13,13,13,13,13,13,13}};

    for(i = 0; cadena[i] != '\0'; i++)
    {
        printf("%i \n", estado);
        if(valoresPalabrasResevadas(cadena[i]) >= 0)
            estado = transiciones[estado][valoresPalabrasResevadas(cadena[i])];
        else
            estado = 13;
    }
    if(estado == 12)
        return 1;
    else
        return 0;
}
