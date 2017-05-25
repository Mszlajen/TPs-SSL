#include <stdio.h>

int automataPalabrasReservadas (char[]);
int valoresPalabrasResevadas (char);
int automataOperadores (char[]);
int valoresOperadores (char);
int automataIdentificadores (char[]);
int valoresIdentificadores (char);
int automataConstantes (char[]);
int valoresConstantes (char);
int automataToken(char[]);

int main ()
{
    char palabra[10];
    int est;

    scanf("%s", palabra);
    est = automataToken(palabra);

    switch(est)
    {
    case 0:
        printf("Palabra Reservada");
        break;
    case 1:
        printf("Operador");
        break;
    case 2:
        printf("Identificador");
        break;
    case 3:
        printf("Constante");
        break;
    default:
        printf("No es un token");
    }
    return 0;
}

int automataToken (char palabra[])
{
    int est = 0, token;
    do
    {
        switch(est)
        {
        case 0:
            token = automataPalabrasReservadas(palabra);
            break;
        case 1:
            token = automataOperadores(palabra);
            break;
        case 2:
            token = automataIdentificadores(palabra);
            break;
        case 3:
            token = automataConstantes(palabra);
            break;
        default:
            token = 1;
        }
        est++;
    }while(!token);
    return est - 1;
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
        valorCaracter = valoresPalabrasResevadas(cadena[i]);
        if(valorCaracter >= 0)
            estado = transiciones[estado][valorCaracter];
        else
            estado = 13;
    }
    if(estado == 12)
        return 1;
    else
        return 0;
}

int valoresOperadores (char caracter)
{
    switch (caracter)
    {
    case '+':
        return 0;
    case '-':
        return 1;
    case '=':
        return 2;
    case '>':
        return 3;
    case '!':
        return 4;
    case '(':
        return 5;
    case ')':
        return 6;
    case '&':
        return 7;
    case '|':
        return 8;
    default:
        return -1;
    }
}

int automataOperadores (char cadena[])
{
    int i, valorCaracter, estado = 0;
    int transiciones[][9] = {{5,5,2,5,5,1,6,3,4},
                            {6,6,6,6,6,6,5,6,6},
                            {6,6,5,6,6,6,6,6,6},
                            {6,6,6,6,6,6,6,5,6},
                            {6,6,6,6,6,6,6,6,5},
                            {6,6,6,6,6,6,6,6,6}};

    for(i = 0; cadena[i] != '\0'; i++)
    {
        valorCaracter = valoresOperadores(cadena[i]);
        if(valorCaracter >= 0)
            estado = transiciones[estado][valorCaracter];
        else
            estado = 6;
    }
    if(estado == 2 || estado == 5)
        return 1;
    else
        return 0;
}

int valoresIdentificadores (char caracter)
{
    if('A' <= caracter && caracter <= 'Z')
        return 0;
    else if ('a' <= caracter && caracter <= 'z')
        return 1;
    else if ('0' <= caracter && caracter <= '9')
        return 2;
    else
        return -1;
}

int automataIdentificadores (char cadena[])
{
    int i, valorCaracter, estado = 0;
    int transiciones[][3] = {{1, 2, 2},
                            {1, 1, 1},
                            {2, 2, 2}};

    for(i = 0; cadena[i] != '\0'; i++)
    {
        valorCaracter = valoresIdentificadores(cadena[i]);
        if(valorCaracter >= 0)
            estado = transiciones[estado][valorCaracter];
        else
            estado = 2;
    }
    if(estado == 1)
        return 1;
    else
        return 0;
}

int valoresConstantes (char caracter)
{
    if('0' <= caracter && caracter <= '9')
        return 0;
    else
        switch (caracter)
        {
            case '.':
                return 1;
            case '+':
                return 2;
            case '-':
                return 3;
            default:
                return -1;
        }
}

int automataConstantes (char cadena[])
{
    int i, valorCaracter, estado = 0;
    int transiciones[][4] = {{4, 2, 1, 1},
                            {4, 2, 5, 5},
                            {3, 5, 5, 5},
                            {3, 5, 5, 5},
                            {4, 3, 5, 5},
                            {5, 5, 5, 5}};

    for(i = 0; cadena[i] != '\0'; i++)
    {
        valorCaracter = valoresConstantes(cadena[i]);
        if(valorCaracter >= 0)
            estado = transiciones[estado][valorCaracter];
        else
            estado = 6;
    }
    if(estado == 3 || estado == 4 || estado == 5)
        return 1;
    else
        return 0;
}

