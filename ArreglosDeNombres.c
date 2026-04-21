#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

void MostrarPersonas(char *V[]);
void BuscarNombre(int n, char *V[]);

int main() {
    char *V[MAX];
    char buff[50];

    for(int i = 0; i < MAX; i++) {
        printf("Ingrese el nombre de la persona %d: ", i);
        scanf("%s", buff);

        int tamNombre = strlen(buff);
        V[i] = (char *)malloc(tamNombre * sizeof(char) + 1);
        strcpy(V[i], buff);
    }
    
    MostrarPersonas(V);
    
    int n;
    printf("Ingrese el indice que desea buscar: ");
    scanf("%d", &n);
    BuscarNombre(n, V);

    return 0;
}

void MostrarPersonas(char *V[]) {
    for(int i = 0; i < MAX; i++) {
        printf("Nombre %d: ", i);
        puts(V[i]);
    }
}

void BuscarNombre(int n, char *V[]) {
    if(n >= 0 && n < 5) {
        for(int i = 0; i < 5; i++) {
            if(i == n) {
                puts(V[i]);
            }
        }
    } else {
        printf("El valor no pertenece al vector. \n");
    }
}
