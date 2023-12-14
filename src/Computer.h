/*
 * Entidad.h
 *
 *  Created on: 12 dic 2023
 *      Author: ruben
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_


typedef struct
{
	int id;
	char descripcion[50];
	float precio;
	int idTipo;

}eComputer;


eComputer* Computer_new();
eComputer* Computer_newParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr);
int Computer_delete(eComputer* computer);

int ComputerSetId(eComputer* computer, int id);
int ComputerGetId(eComputer* computer, int* id);

int ComputerSetDescripcion(eComputer* computer, char* descripcion);
int ComputerGetDescripcion(eComputer* computer, char* descripcion);

int ComputerSetPrecio(eComputer* computer, float precio);
int ComputerGetPrecio(eComputer* computer, float* precio);

int ComputerSetIdTipo(eComputer* computer, int idTipo);
int ComputerGetIdTipo(eComputer* computer, int* idTipo);


int BuscarMayorId(LinkedList* pArrayComputer);
int ShowComputer(eComputer* this);
int ShowComputers(LinkedList* this);
int SearchIdComputer(LinkedList* pArrayComputer, int id);

int CompararComputerId(void* a, void* b);
int CompararComputerDescripcion(void* a, void* b);
int CompararComputerPrecio(void* a, void* b);
int CompararComputerIdTipo(void* a, void* b);




#endif /* COMPUTER_H_ */
