#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include  <ctype.h>
#include "LinkedList.h"
#include "parser.h"
#include "Carga_validacion.h"
#include "Computer.h"




int controller_loadFromText(char* path , LinkedList* pArrayListPassenger, int* flagA, int* flagB)
{
	int rta = 0;
	int cant;

	if(*flagA == 0)
	{
		FILE* pArchivos;
		pArchivos = fopen(path, "r");
		if(pArchivos != NULL)
		{
			cant = parser_eComputerFromText(pArchivos, pArrayListPassenger);
			if(cant == 1)
				rta = 1;

			printf("Exito en la carga de datos.\n");
		}
		else
		{
			printf("Error con el archivo.\n");
		}
		*flagA = 1;
	}
	else
	{
		printf("La carga de datos del archivo ya a sido realizada.\n");
	}

	return rta;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger, int* flagA, int* flagB)
{
	int rta = 0;
		int cant;
		if(*flagA == 0 )
		{
			if(pArrayListPassenger != NULL && path != NULL)
			{
				FILE* pArchivo = NULL;
				pArchivo = fopen(path, "rb");

				if(pArchivo != NULL)
				{

					cant = parser_eComputerFromBinary(pArchivo, pArrayListPassenger);
					if(cant == 1)
						rta = 1;

	            	printf("Exito en la carga. \n");

				}
				else
				{
					printf("Error con el archivo. \n");
				}
				fclose(pArchivo);
			}
	 		*flagA = 1;
		}
		else
		{
	 		printf("Carga de datos a partir de archivo, ya a sido realizada.\n");

		}
		return rta;
}


int controller_addComputer(LinkedList* pArrayListComputer, int* flagA, int* flagB)
{
	int rta = 0;
	int id = 1000;
	char descripcion[51];
	float precio;
	int idTipo; // 1=desktop, 2=laptop;
	char idTipoStr[51];

	eComputer* auxComputer = NULL;

	if(pArrayListComputer != NULL)
	{
		id = BuscarMayorId(pArrayListComputer);

		if(flagA == 0 && id == 0)
		{
			id = 1001;
		}
		else
		{
			id = id + 1;
		}

		printf("\tComputer ID: %d\n", id);
		GetString("\t\nIngrese descripcion: ", descripcion);
		precio = GetFloat("\t\nIngrese precio: ");
		idTipo = GetIntRange("\t\nIngrese tipo id: \n\t\t1 = DESKTOP. \n\t\t2 = LAPTOP.\n\t\t", 1, 2);
		OpcionTipoIdComputer(idTipo,idTipoStr);

		if(1== (ComputerSetId(auxComputer,id) && ComputerSetDescripcion(auxComputer, descripcion) && ComputerSetPrecio(auxComputer, precio) && ComputerSetIdTipo(auxComputer, idTipo)))
		{
			ll_add(pArrayListComputer, auxComputer);
			rta = 1;
			*flagB = 1;
			printf("Se realizo con exito el alta.\n");
		}
		else
		{
			Computer_delete(auxComputer);
		}


	}
	return rta;
}

int controller_editComputer(LinkedList* pArrayListComputer, int* flagA, int* flagB)
{
	int rta = 0;
	int id = 1000;
	char descripcion[51];
	float precio = 0;
	int idTipo; // 1=desktop, 2=laptop;
	char idTipoStr[51];
	int index;
	int opcion = 0;
	eComputer* auxComputer = NULL;

	if(*flagA == 1 || *flagB == 1)
	{
		ShowComputers(pArrayListComputer); // muestro lista

		if(pArrayListComputer != NULL)
		{
			printf("\nIngrese el numero de id a modificar: \n");
			scanf("%d", &id);

			index = SearchIdComputer(pArrayListComputer, id);
			if(index == -1)
			{
				printf("No existe pasajero con el dicho id.\n");
			}
			else
			{
				auxComputer = ll_get(pArrayListComputer, index);
				ShowComputer(auxComputer);

				MostrarMenuModificacion();

				do
				{
					switch(FuncionMenu("\tIngrese una opcion.",1,4))
					{
						case 1:
							GetString("\n\tIngrese descripcion: ", descripcion);
							ComputerSetDescripcion(auxComputer, descripcion);
						break;
						case 2:
							GetFloat("\n\tIngrese precio: ");
							ComputerSetPrecio(auxComputer, precio);
						break;
						case 3:
							idTipo = GetIntRange("\n\tIngrese tipo id: ", 1, 2);
							OpcionTipoIdComputer(idTipo, idTipoStr);
						break;
						case 4:
							opcion = 4;
							ShowComputer(auxComputer);
						break;
					}

				}while(opcion != 4);
				printf("Se realizo la modificacion correctamente.\n");
				rta = 1;
			}


		}
	}
	else
	{
		printf("Error para modificar debe dar de alta los datos. \n");
	}

	return rta;

}

int controller_removeComputer(LinkedList* pArrayListComputer, int* flagA, int* flagB)
{
	int rta = 0;
	int id;
	int index;
	char confirma;

	if(*flagA == 1 || *flagB == 1)
	{
		eComputer* auxComputer = NULL;

		if(pArrayListComputer != NULL)
		{
			printf("Ingrese ID: ");
			scanf("%d", &id);

			index = SearchIdComputer(pArrayListComputer, id);
			if(index == -1)
			{
				printf("\tNo se encontro el pasajero. \n");
			}
			else
			{
				auxComputer = ll_get(pArrayListComputer, index);
				ShowComputer(auxComputer);

				FuncConfirma("\tDesea confirmar la baja de los datos? S/N\n", &confirma, "\t\nError, ingrese nuevamente.\n");
				if(confirma == 'S')
				{
					ll_remove(pArrayListComputer, index);
					printf("Baja realizada con exito.\n");
					rta = 1;
				}
				else
				{
					printf("Error en la baja.\n");
				}

			}
		}


	}
	else
	{
		printf("Error, para eliminar datos debe dar de alta.\n");
	}

	return rta;
}

int controller_listComputer(LinkedList* pArrayListComputer, int* flagA, int* flagB)
{
	int rta = 0;

	if(pArrayListComputer != NULL && (*flagA == 1 || *flagB == 1))
	{
		printf("\t\t\t\t*** Lista de datos cargados ***\n\n");
		ShowComputers(pArrayListComputer);
		rta = 1;
	}
	else
	{
		printf("Error para listar datos. \n");

	}

	return rta;
}


int controller_sortComputer(LinkedList* pArrayListComputer, int* flagA, int* flagB)
{
	int rta = 0;
	int orden;
	int opcion;

	if(*flagA == 1 || *flagB ==1)
	{
		if(pArrayListComputer != NULL)
		{
			printf("\t1. Ordenar por id. \n");
			printf("\t2. Ordenar por descripcion. \n");
			printf("\t3. Ordenar por precio. \n");
			printf("\t4. Ordenar por idTipo. \n");
			printf("\t5. salir. \n");
			opcion = FuncionMenu("\tIngrese opcion: ",1,5);
			if(opcion != 5)
			{
				printf("\t\t0. Orden descendente. \n");
				printf("\t\t1. Orden ascendente. \n");
				orden = FuncionMenu("\t\tIngrese orden: ", 0, 1);
			}

			switch(opcion)
			{
				case 1:
					printf("\tAguarde un momento...\n");
					if(ll_sort(pArrayListComputer, CompararComputerIdTipo, orden) == 0)
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento ID. \n");
					}
					break;
				case 2:
					printf("\tAguarde un momento...\n");
					if(ll_sort(pArrayListComputer, CompararComputerDescripcion, orden) == 0)
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento descripcion. \n");
					}
					break;
				case 3:
					printf("\tAguarde un momento...\n");
					if(ll_sort(pArrayListComputer, CompararComputerPrecio, orden) == 0)
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento precio. \n");
					}
					break;
				case 4:
					printf("\tAguarde un momento...\n");
					if(ll_sort(pArrayListComputer, CompararComputerIdTipo, orden) == 0)
					{
						rta = 1;
					}
					else
					{
						printf("Error en el ordenamiento IDTipo. \n");
					}
					break;
				case 5:
					printf("\tSalio del sub-menu.\n");
					break;
			}
		}
		else
		{
			printf("Error en el ordenamiento.\n");
		}
	}
	else
	{
		printf("Error para ordenar primero debe dar de alta datos.\n");
	}
	return rta;
}


int controller_saveAsText(char* path , LinkedList* pArrayListComputer, int* flagA, int* flagB, int* flagC)
{
	int rta = 0;
	int id;
	char descripcion[51];
	float precio;
	int idTipo;
	FILE* pArchivo;
	eComputer* auxComputer = NULL;

	if(*flagA == 1 || *flagB == 1)
	{
		if(path != NULL && pArrayListComputer != NULL)
		{
			pArchivo = fopen(path, "w");
			if(pArchivo != NULL)
			{
				fprintf(pArchivo, "id, descripcion, precio, idTipo\n");
				for(int i=0; i<ll_len(pArrayListComputer); i++)
				{
					auxComputer = ll_get(pArrayListComputer, i);

					if(1== (ComputerGetId(auxComputer, &id) && ComputerGetDescripcion(auxComputer, descripcion) && ComputerGetPrecio(auxComputer, &precio) && ComputerGetIdTipo(auxComputer, &idTipo)))
					{
						fprintf(pArchivo, "%d, %s; %f; %d\n", id, descripcion, precio, idTipo);
						rta = 1;
						*flagC = 1;
					}
				}
				printf("Guardado con exito.\n");
			}
			else
			{
				printf("No se pudo abrir el archivo.\n");
			}
		}
	}
	else
	{
		printf("Error en guardar datos, primero debe de cargarlos.\n");
	}
	return rta;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListComputer, int* flagA, int* flagB, int* flagC)
{
	int rta = 0;


	return rta;
}


