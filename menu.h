#ifndef MENU_H
#define MENU_H

#include "zonas.h"

/**
 * Muestra menu principal del sistema
 * @return Opcion seleccionada
 */
int mostrarMenuPrincipal(void);

/**
 * Ejecuta opcion seleccionada del menu
 * @param opcion Numero de opcion
 * @param zonas Array de zonas
 * @param cantidad Cantidad de zonas
 * @return 0 continuar, 1 salir
 */
int ejecutarOpcionMenu(int opcion, ZonaUrbana zonas[], int *cantidad);

/**
 * Loop principal
 */
void iniciarInterfazInteractiva(ZonaUrbana zonas[], int *cantidad);

#endif