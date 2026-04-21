#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

void MostrarPersonas(char *V[]);

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

    return 0;
}

void MostrarPersonas(char *V[]) {
    for(int i = 0; i < MAX; i++) {
        printf("Nombre %d: ", (i + 1));
        puts(V[i]);
    }
}