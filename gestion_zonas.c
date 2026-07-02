#include <stdio.h>
#include <string.h>

#include "gestion_zonas.h"
#include "zonas.h"
#include "persistencia.h"

int buscarZonaPorID(ZonaUrbana zonas[], int cantidad, int id)
{
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(zonas[i].id==id)
            return i;
    }

    return -1;
}

void menuGestionZonas(ZonaUrbana zonas[], int *cantidad)
{
    int opcion;

    do
    {
        printf("\n=================================\n");
        printf("      GESTION DE ZONAS\n");
        printf("=================================\n");

        printf("1. Agregar zona\n");
        printf("2. Modificar zona\n");
        printf("0. Volver\n");

        printf("\nOpcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                agregarZona(zonas,cantidad);
                break;

            case 2:
                modificarZona(zonas,*cantidad);
                break;

            case 0:
                break;

            default:
                printf("\nOpcion invalida.\n");
        }

    }while(opcion!=0);

}

int agregarZona(ZonaUrbana zonas[], int *cantidad)
{
    ZonaUrbana nueva;

    int id;

    char nombre[MAX_NOMBRE];

    if(*cantidad>=MAX_ZONAS)
    {
        printf("\nNo hay espacio para mas zonas.\n");
        return 0;
    }

    printf("\n=========== NUEVA ZONA ===========\n");

    do
    {
        printf("ID: ");
        scanf("%d",&id);

        if(id<=0)
            printf("ID invalido.\n");

        else if(buscarZonaPorID(zonas,*cantidad,id)!=-1)
        {
            printf("Ese ID ya existe.\n");
            id=-1;
        }

    }while(id<=0);


    getchar();

    do
    {
        printf("Nombre: ");

        fgets(nombre,MAX_NOMBRE,stdin);

        nombre[strcspn(nombre,"\n")]=0;

        if(strlen(nombre)==0)
            printf("El nombre no puede estar vacio.\n");

    }while(strlen(nombre)==0);


    inicializarZona(&nueva,id,nombre);


    printf("\n----- Contaminantes actuales -----\n");

    do{
        printf("CO: ");
        scanf("%f",&nueva.actual.co);
    }while(nueva.actual.co<0);

    do{
        printf("SO2: ");
        scanf("%f",&nueva.actual.so2);
    }while(nueva.actual.so2<0);

    do{
        printf("NO2: ");
        scanf("%f",&nueva.actual.no2);
    }while(nueva.actual.no2<0);

    do{
        printf("PM2.5: ");
        scanf("%f",&nueva.actual.pm25);
    }while(nueva.actual.pm25<0);



    printf("\n----- Clima -----\n");

    do
    {
        printf("Temperatura (-30 a 60): ");
        scanf("%f",&nueva.condiciones_clima.temperatura);

    }while(nueva.condiciones_clima.temperatura<-30 ||
           nueva.condiciones_clima.temperatura>60);



    do
    {
        printf("Velocidad del viento: ");
        scanf("%f",&nueva.condiciones_clima.velocidad_viento);

    }while(nueva.condiciones_clima.velocidad_viento<0);



    do
    {
        printf("Humedad (0-100): ");
        scanf("%f",&nueva.condiciones_clima.humedad);

    }while(nueva.condiciones_clima.humedad<0 ||
           nueva.condiciones_clima.humedad>100);



    zonas[*cantidad]=nueva;

    (*cantidad)++;

    guardarHistoricoEnArchivo(zonas,*cantidad);

    printf("\nZona agregada correctamente.\n");

    return 1;
}

int modificarZona(ZonaUrbana zonas[], int cantidad)
{
    int id;
    int pos;
    int opcion;

    printf("\nIngrese el ID de la zona: ");
    scanf("%d",&id);

    pos=buscarZonaPorID(zonas,cantidad,id);

    if(pos==-1)
    {
        printf("\nLa zona no existe.\n");
        return 0;
    }

    do
    {
        printf("\n=====================================\n");
        printf("      MODIFICAR ZONA\n");
        printf("=====================================\n");

        printf("Zona: %s\n",zonas[pos].nombre);

        printf("\n1. Nombre\n");
        printf("2. CO\n");
        printf("3. SO2\n");
        printf("4. NO2\n");
        printf("5. PM2.5\n");
        printf("6. Temperatura\n");
        printf("7. Velocidad del viento\n");
        printf("8. Humedad\n");
        printf("9. Mostrar datos\n");
        printf("0. Guardar y salir\n");

        printf("\nOpcion: ");
        scanf("%d",&opcion);

        getchar();

        switch(opcion)
        {

        case 1:

            do
            {
                printf("Nuevo nombre: ");

                fgets(zonas[pos].nombre,MAX_NOMBRE,stdin);

                zonas[pos].nombre[strcspn(zonas[pos].nombre,"\n")] = '\0';

            }while(strlen(zonas[pos].nombre)==0);

            break;

        case 2:

            do
            {
                printf("Nuevo CO: ");
                scanf("%f",&zonas[pos].actual.co);

            }while(zonas[pos].actual.co<0);

            break;

        case 3:

            do
            {
                printf("Nuevo SO2: ");
                scanf("%f",&zonas[pos].actual.so2);

            }while(zonas[pos].actual.so2<0);

            break;

        case 4:

            do
            {
                printf("Nuevo NO2: ");
                scanf("%f",&zonas[pos].actual.no2);

            }while(zonas[pos].actual.no2<0);

            break;

        case 5:

            do
            {
                printf("Nuevo PM2.5: ");
                scanf("%f",&zonas[pos].actual.pm25);

            }while(zonas[pos].actual.pm25<0);

            break;

        case 6:

            do
            {
                printf("Nueva temperatura: ");
                scanf("%f",&zonas[pos].condiciones_clima.temperatura);

            }while(zonas[pos].condiciones_clima.temperatura<-30 ||
                   zonas[pos].condiciones_clima.temperatura>60);

            break;

        case 7:

            do
            {
                printf("Nueva velocidad del viento: ");
                scanf("%f",&zonas[pos].condiciones_clima.velocidad_viento);

            }while(zonas[pos].condiciones_clima.velocidad_viento<0);

            break;

        case 8:

            do
            {
                printf("Nueva humedad: ");
                scanf("%f",&zonas[pos].condiciones_clima.humedad);

            }while(zonas[pos].condiciones_clima.humedad<0 ||
                   zonas[pos].condiciones_clima.humedad>100);

            break;

        case 9:

            mostrarZona(&zonas[pos]);

            break;

        case 0:

            guardarHistoricoEnArchivo(zonas,cantidad);

            printf("\nZona modificada correctamente.\n");

            break;

        default:

            printf("\nOpcion invalida.\n");

        }

    }while(opcion!=0);

    return 1;
}