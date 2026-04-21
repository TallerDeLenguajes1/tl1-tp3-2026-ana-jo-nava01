#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

void MostrarPersonas(char *V[]);
int BuscarNombre(char *V[], char str[]);

int main() {
    char *V[MAX];
    char buff[50];

    for(int i = 0; i < MAX; i++) {
        printf("Ingrese el nombre de la persona %d: ", (i + 1));
        scanf("%s", buff);

        int tamNombre = strlen(buff);
        V[i] = (char *)malloc(tamNombre * sizeof(char) + 1);
        strcpy(V[i], buff);
    }
    
    MostrarPersonas(V);
    
    int indice;
    printf("Ingrese la palabra clave: ");
    fflush(stdin);
    gets(buff);
    indice = BuscarNombre(V, buff);

    if(indice != -1) {
        printf("El nombre con esa palabra fue encontrado en %d", indice);
    } else {
        printf("No hubo coincidencias.\n");
    }

    return 0;
}

void MostrarPersonas(char *V[]) {
    for(int i = 0; i < MAX; i++) {
        printf("Nombre %d: ", (i + 1));
        puts(V[i]);
    }
}

int BuscarNombre(char *V[], char str[]) {
    for(int i = 0; i < MAX; i++) {
        if (strstr(V[i], str) != NULL) {
            return i;
        }
    }
    
    return -1;
}