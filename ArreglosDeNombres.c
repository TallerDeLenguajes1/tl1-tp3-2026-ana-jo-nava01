#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

void MostrarPersonas(char *V[]);
void BuscarNombrePorId(int n, char *V[]);
int BuscarNombrePorPalabra(char *V[], char str[]);

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

    int opcion;
    do {
        printf("==Opciones de busqueda==\n");
        printf("1. Buscar por Id\n");
        printf("2. Buscar por palabra\n");
        scanf("%d", &opcion);
        if(opcion != 1 && opcion != 2) {
            printf("Ingrese una opcion valida. \n");
        }
    }while(opcion != 1 && opcion != 2);

    if(opcion == 1) {
        int n;
        printf("Ingrese el indice que desea buscar: ");
        scanf("%d", &n);
        BuscarNombrePorId(n, V);
    } else {
        int indice;
        printf("Ingrese la palabra clave: ");
        fflush(stdin);
        gets(buff);
        indice = BuscarNombrePorPalabra(V, buff);

        if(indice != -1) {
            puts(V[indice]);
        } else {
            printf("No hubo coincidencias.\n");
        }
    }

    

    return 0;
}

void MostrarPersonas(char *V[]) {
    for(int i = 0; i < MAX; i++) {
        printf("Nombre %d: ", i);
        puts(V[i]);
    }
}

void BuscarNombrePorId(int n, char *V[]) {
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

int BuscarNombrePorPalabra(char *V[], char str[]) {
    for(int i = 0; i < MAX; i++) {
        if (strstr(V[i], str) != NULL) {
            return i;
        }
    }
    
    return -1;
}
