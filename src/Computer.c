#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Carga_validacion.h"
#include "Computer.h"


eComputer* Computer_new()
{
	eComputer* auxComputer = (eComputer*)malloc(sizeof(eComputer));
	if(auxComputer!=NULL)
	{
		auxComputer->id = 0;
		strcpy(auxComputer->descripcion, " ");
		auxComputer->precio = 0;
		auxComputer->idTipo = 0;
	}

	return auxComputer;
}


eComputer* Computer_newParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr)
{
	eComputer* newComputer = (eComputer*)malloc(sizeof(eComputer));
	if(newComputer != NULL && idStr != NULL && descripcionStr != NULL && precioStr != NULL && idTipoStr != NULL)
	{
				ComputerSetId(newComputer, atoi(idStr));
				ComputerSetDescripcion(newComputer, descripcionStr);
				ComputerSetPrecio(newComputer, atof(precioStr));
				ComputerSetIdTipo(newComputer, atoi(idTipoStr));
	}
	else
	{
		Computer_delete(newComputer);
		newComputer = NULL;
	}
	return newComputer;
}


int Computer_delete(eComputer* computer)
{
	if(computer != NULL)
	{
		free(computer);
		return 1;
	}
	return 0;
}

int ComputerSetId(eComputer* computer, int id)
{
	if(computer !=NULL && id > 0)
	{
		computer->id = id;
		return 1;
	}
	return 0;
}

int ComputerGetId(eComputer* computer, int* id)
{
	if(computer != NULL && id != NULL)
	{
		*id = computer->id;
		return 1;
	}
	return 0;
}

int ComputerSetDescripcion(eComputer* computer, char* descripcion)
{
	if(computer != NULL && descripcion != NULL)
	{
		strcpy(computer->descripcion, descripcion);
		return 1;
	}
	return 0;
}

int ComputerGetDescripcion(eComputer* computer, char* descripcion)
{
	if(computer != NULL && descripcion != NULL)
	{
		strcpy(descripcion, computer->descripcion);
		return 1;
	}
	return 0;
}

int ComputerSetPrecio(eComputer* computer, float precio)
{
	int rta = 0;
	if(computer !=NULL && precio > 0)
		{
			computer->precio = precio;
			rta = 1;
		}
		return rta;
}

int ComputerGetPrecio(eComputer* computer, float* precio)
{
	if(computer !=NULL && precio != NULL)
	{
		*precio = computer->precio;
		return 1;
	}
	return 0;
}


int ComputerSetIdTipo(eComputer* computer, int idTipo)
{
	if(computer !=NULL && idTipo > 0)
	{
		computer->idTipo = idTipo;
		return 1;
	}
	return 0;
}

int ComputerGetIdTipo(eComputer* computer, int* idTipo)
{
	if(computer !=NULL && idTipo != NULL)
	{
		*idTipo=computer->idTipo;
		return 1;
	}
	return 0;
}


/**
 * \brief recorre la lista de computer y trae el id de mayor tamaño
 * \param lista linkedlist
 * \return 1 si salio todo bien, 0 si todo lo contrarior
 */
int BuscarMayorId(LinkedList* pArrayComputer)
{
	eComputer* auxComputer = NULL;
	int mayor = 0;
	int id;
	int i;

	if(pArrayComputer != NULL)
	{
		for(i=0; i<ll_len(pArrayComputer); i++)
		{
			auxComputer = ll_get(pArrayComputer, i);
			ComputerGetId(auxComputer, &id);
			if(i==0 || id > mayor)
			{
				mayor = id;
			}
		}
	}
	return mayor;

}

int ShowComputer(eComputer* this)
{
	int id;
	char descripcion[50];
	float precio;
	int idTipo;

	if(this != NULL)
	{
		if(1== ComputerGetId(this, &id) && ComputerGetDescripcion(this, descripcion) && ComputerGetPrecio(this, &precio) && ComputerGetIdTipo(this, &idTipo))
		{
			printf("%d			%s			%f			%d\n", id, descripcion, precio, idTipo);
			return 1;
		}
	}
	return 0;
}

int ShowComputers(LinkedList* this)
{
	int i;

	if(this != NULL)
	{
		printf("id			descripcion			precio			idTIpo\n");
		for(i=0; i<ll_len(this); i++)
		{
			ShowComputer((eComputer*)ll_get(this, i));
		}
		return 1;
	}
	return 0;
}

int SearchIdComputer(LinkedList* pArrayComputer, int id)
{
	int index = -1;
	int i;
	int auxId;

	eComputer* auxComputer = NULL;

	for(i=0; i<ll_len(pArrayComputer); i++)
	{
		auxComputer = (eComputer*)ll_get(pArrayComputer, i);
		ComputerGetId(auxComputer, &auxId);
		if(auxId == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

int CompararComputerId(void* a, void* b)
{
	int rta = 0;
	eComputer* auxComputerA = NULL;
	eComputer* auxComputerB = NULL;

	if(a != NULL && b != NULL)
	{
		auxComputerA = (eComputer*)a;
		auxComputerB = (eComputer*)b;

		if(auxComputerA->id > auxComputerB->id)
		{
			rta = 1;
		}
		else
		{
			if(auxComputerA->id < auxComputerB->id)
				rta = -1;
		}
	}
	return rta;
}

int CompararComputerDescripcion(void* a, void* b)
{
	int rta = 0;
		eComputer* auxComputerA = NULL;
		eComputer* auxComputerB = NULL;

		if(a != NULL && b != NULL)
		{
			auxComputerA = (eComputer*)a;
			auxComputerB = (eComputer*)b;

			rta = strcmp(auxComputerA->descripcion, auxComputerB->descripcion);
			//1 si es mayor
			//0 si son iguales
			//-1 si es menor
		}
		return rta;
}

int CompararComputerPrecio(void* a, void* b)
{
	int rta = 0;
	eComputer* auxComputerA = NULL;
	eComputer* auxComputerB = NULL;

	if(a != NULL && b != NULL)
	{
		auxComputerA = (eComputer*)a;
		auxComputerB = (eComputer*)b;

		if(auxComputerA->precio > auxComputerB->precio)
		{
			rta = 1;
		}
		else
		{
			if(auxComputerA->precio < auxComputerB->precio)
				rta = -1;
		}
	}
	return rta;
}

int CompararComputerIdTipo(void* a, void* b)
{
	int rta = 0;
		eComputer* auxComputerA = NULL;
		eComputer* auxComputerB = NULL;

		if(a != NULL && b != NULL)
		{
			auxComputerA = (eComputer*)a;
			auxComputerB = (eComputer*)b;

			if(auxComputerA->idTipo > auxComputerB->idTipo)
			{
				rta = 1;
			}
			else
			{
				if(auxComputerA->idTipo < auxComputerB->idTipo)
					rta = -1;
			}
		}
		return rta;
}

