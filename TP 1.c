/*
Matias David Szlajen
Curso K2032
TP #1 SSL
*/

#include <stdio.h>
#define tam 10

int largo (char cadena[]);
int vacia (char cadena[]);
void concatenar (char primera[], char segunda[], char salida[]);

void main (void)
{
    char primera_cad[tam + 1] = "Cad_uno", segunda_cad[tam + 1] = "Cad_dos", conc_cad[tam*2 + 1];
    printf("%s %s\n", primera_cad, segunda_cad);

    printf("El largo de las cadenas es:%d %d\n", largo(primera_cad), largo(segunda_cad));
    printf("Las cadenas son vacias: %s %s\n", vacia(primera_cad) ? "false" : "true", vacia(segunda_cad) ? "false" : "true");
    concatenar(primera_cad, segunda_cad, conc_cad);
    printf("Las cadenas concatenadas dan: %s", conc_cad);
    scanf("");
}

int largo (char cadena[])
{
    int i;
    for(i = 0; cadena[i] != '\0'; i++);
    return i;
}

int vacia (char cadena[])
{
    if(cadena[0] == '\0')
        return 0;
    else
        return 1;
}

void concatenar(char primera[], char segunda[], char salida[])
{
    int i, j;
    for(i = 0; primera[i] != '\0'; i++)
        salida[i] = primera[i];
    for(j = 0; segunda[j] != '\0'; j++)
    {
        salida[i] = segunda[j];
        i++;
    }
    salida[i] = '\0';
}
