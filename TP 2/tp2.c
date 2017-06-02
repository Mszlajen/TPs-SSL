#include <stdio.h>
#include <string.h>

#define tam 10

//int automata (int columnas, int, int [][columnas], char [], int [], int, char []);
int automata (int *[], char [], int [], int, char []);
void generalizarCaracteres (char [], char [], char[3]);
int esTerminal (int, int []);
int posCaracter (char [], char);

int automataReservadas (char []);
int automataConstantes (char []);
int automataOperadores (char []);
int automataPuntuacion (char []);
int automataIdentificadores (char []);

void main ()
{
    char cadena[tam + 1];
    int i, terminado = 0;
    scanf("%s", cadena);
    for (i = 0; i <= 5 && !terminado; i++)
        switch(i)
        {
            case 0:
                if(terminado = automataReservadas(cadena))
                    printf("Palabra Reservada");
                break;
            case 1:
                if(terminado = automataOperadores(cadena))
                    printf("Operador");
                break;
            case 2:
                if(terminado = automataPuntuacion(cadena))
                    printf("Caracter de Puntuacion");
                break;
            case 3:
                if(terminado = automataIdentificadores(cadena))
                    printf("Identificador");
                break;
            case 4:
                if(terminado = automataConstantes(cadena))
                    printf("Constante");
                break;
            default:
                printf("No es lexema");
        }
}

int automata (int *transiciones[], char caracteres[], int terminales[], int estVacio, char cadena[])
{
    int i, estado = 0, valorCaracter;
    for(i = 0; cadena[i] != '\0'; i++)
    {
        valorCaracter = posCaracter(caracteres, cadena[i]);
        if(valorCaracter >= 0)
            estado = (transiciones + estado * sizeof(int))[valorCaracter];
        else
            estado = estVacio;
    }
    if(esTerminal(estado, terminales))
        return 1;
    else
        return 0;
}

int esTerminal (int estado, int terminales[])
{
    int i, resultado = 0;

    for(i = 0; !resultado && terminales[i] != -1; i++)
    {
        if(terminales[i] == estado)
            resultado = 1;
    }
    return resultado;
}

int posCaracter (char cadena[], char caracter)
{
    int i;

    for (i = 0; cadena [i] != '\0' && cadena [i] != caracter; i++);
    if(cadena [i] == '\0')
        return -1;
    else
        return i;
}

void generalizarCaracteres (char original[], char destino[], char sustitutos[3]) // Sustitutos va [Digito, Mayuscula, Minuscula]
{
    int i;

    for(i = 0; original[i] != '\0'; i++)
    {
        if('0' <= original[i] && original[i] <= '9')
            destino[i] = sustitutos[0];
        else if('A' <= original[i] && original[i] <= 'Z')
            destino[i] = sustitutos[1];
        else if('a' <= original[i] && original[i] <= 'z')
            destino[i] = sustitutos[2];
        else
            destino[i] = original[i];
    }
    destino[i] = '\0';
}

int automataReservadas (char cadena[])
{
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
    char caracteres [] = {'i', 'f', 'e', 'l', 's', 'w', 'h', 'n', 't', 'f', 'o', 'a'};
    int terminales [] = {12, -1};

    return automata(&transiciones, caracteres, terminales, 13, cadena);
    //return automata(11, 14,transiciones, caracteres, terminales, 1, cadena);
}

int automataOperadores (char cadena[])
{
    int transiciones[][9] = {{5,5,2,5,5,1,6,3,4},
                            {6,6,6,6,6,6,5,6,6},
                            {6,6,5,6,6,6,6,6,6},
                            {6,6,6,6,6,6,6,5,6},
                            {6,6,6,6,6,6,6,6,5},
                            {6,6,6,6,6,6,6,6,6},
                            {6,6,6,6,6,6,6,6,6}};
    char caracteres [] = {'+', '-', '=', '>', '!', '(', ')', '&', '|'};
    int terminales [] = {2, 5, -1};

    return automata(&transiciones, caracteres, terminales, 6, cadena);
    //return automata(9, 7, transiciones, caracteres, terminales, 2, cadena);
}

int automataConstantes (char cadena[])
{
    int transiciones[][4] = {{4, 2, 1, 1},
                            {4, 2, 5, 5},
                            {3, 5, 5, 5},
                            {3, 5, 5, 5},
                            {4, 3, 5, 5},
                            {5, 5, 5, 5}};
    char caracteres [] = {'d', '.', '+', '-'};
    int terminales [] = {3, 4, -1};
    char cadenaTemp [10], sustitutos[] = {'d', '\0', '\0'};

    generalizarCaracteres(cadena, cadenaTemp, sustitutos);

    return automata(&transiciones, caracteres, terminales, 5, cadenaTemp);
    //return automata (4, 6, transiciones, caracteres, terminales, 3, cadenaTemp);
}

int automataPuntuacion (char cadena[])
{
    int transiciones[][1] = {{1},
                            {2},
                            {2}};
    char caracteres[] = {';'};
    int terminales[] = {2, -1};

    return automata(&transiciones, caracteres, terminales, 1, cadena);
    //return automata(1, 3, transiciones, caracteres, terminales, 1, cadena);
}

int automataIdentificadores (char cadena []) //Revisar
{
    char transiciones [][3] = {{1, 2, 2},
                            {1, 1, 1},
                            {2, 2, 2}};
    char caracteres [] = {'D', 'M', 'm'};
    char cadenaTemp [tam + 1];
    int terminales [] = {1, -1};

    generalizarCaracteres(cadena, cadenaTemp, caracteres);

    return automata(&transiciones, caracteres, terminales, 2, cadenaTemp);
}
