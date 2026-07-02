#ifndef GESTION_ZONAS_H
#define GESTION_ZONAS_H

#include "zonas.h"

/* Menu principal de gestion */
void menuGestionZonas(ZonaUrbana zonas[], int *cantidad);

/* Funciones principales */
int agregarZona(ZonaUrbana zonas[], int *cantidad);
int modificarZona(ZonaUrbana zonas[], int cantidad);
int agregarDiasZona(ZonaUrbana zonas[], int cantidad);

/* Funciones auxiliares */
int buscarZonaPorID(ZonaUrbana zonas[], int cantidad, int id);

#endif