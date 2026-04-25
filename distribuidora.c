#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
typedef struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario  
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
}Cliente;

float costoTotal(Producto prod);

int main() {
    srand(time(NULL));

    Cliente *clientes;
    int cantClientes;
    char buff[50];

    //Solicitar cantidad de clientes
    do {
        printf("Ingrese la cantidad de clientes: ");
        scanf("%d", &cantClientes);
        if(cantClientes > 5 || cantClientes <= 0) {
            printf("Error: cantidad de clientes invalida.\n");
        }
    }while(cantClientes > 5 || cantClientes <= 0);

    clientes = (Cliente *)malloc(cantClientes * sizeof(Cliente));
    
    //Cargar por teclado los clientes con carga aleatoria de cant de productos y caracteristicas
    for(int i = 0; i < cantClientes; i++) {
        clientes[i].ClienteID = i;
        printf("==CLIENTE %d==\n", i);
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", buff);
        int tamNombre = strlen(buff);
        clientes[i].NombreCliente = (char *)malloc(tamNombre * sizeof(char) + 1);
        strcpy(clientes[i].NombreCliente, buff);
        
        //Genero aleatoriamente la cantidad de productos a pedir
        clientes[i].CantidadProductosAPedir = (rand() % 5) + 1;
        printf("Cantidad de productos a pedir: %d\n", clientes[i].CantidadProductosAPedir);

        clientes[i].Productos = (Producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
        
        //Cargo arreglo de productos con valores aleatorios
        float costo_por_cliente = 0;
        for(int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j;
            printf("->Producto %d\n", j);

            int cant_rand = (rand() % 10) + 1;
            clientes[i].Productos[j].Cantidad = cant_rand;
            printf("Cantidad del producto %d: %d\n", j, clientes[i].Productos[j].Cantidad);

            int prod_rand = (rand() % 5);
            clientes[i].Productos[j].TipoProducto = TiposProductos[prod_rand];
            puts(clientes[i].Productos[j].TipoProducto);

            int precio_rand = (rand() % 100) + 10;
            clientes[i].Productos[j].PrecioUnitario = precio_rand;
            printf("Precio unitario: $ %.2f\n", clientes[i].Productos[j].PrecioUnitario);

            float total = costoTotal(clientes[i].Productos[j]);
            printf("Costo total: $ %.2f\n", total);
            costo_por_cliente += total;
        }

        printf("==TOTAL: $ %.2f==\n", costo_por_cliente);
    }

    //Libero memoria
    for(int i = 0; i < cantClientes; i++) {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);

    return 0;
}

float costoTotal(Producto prod) {
    return prod.Cantidad * prod.PrecioUnitario;
}