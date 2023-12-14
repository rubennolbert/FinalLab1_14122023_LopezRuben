/*
 ============================================================================
 Name        : FinalLab1_14122023_Lopez-Ruben.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Carga_validacion.h"
#include "Controller.h"


int main(void)
{

	int option = 0;
	int flagArchivio = 0;
	int flagAlta = 0;
	int flagGuardar = 0;


		LinkedList *listaComputer = ll_newLinkedList();

		if(listaComputer==NULL)
			printf("Error en la carga de linkedList.\n");

		do
		{
			system("cls");
			MostrarMenu();
			switch(FuncionMenu("Seleccione una opcion.", 1, 10))
			{
				case 1: //cargar desde archivo .txt
					system("cls");

					system("pause");
					break;
				case 2: //alta
					system("cls");

					system("pause");
					break;
				case 3: //modificar
					system("cls");

					system("pause");
					break;
				case 4: //baja
					system("cls");

					system("pause");
					break;
				case 5: //listar
					system("cls");

					system("pause");
					break;
				case 6: //ordenar
					system("cls");

					system("pause");
					break;
				case 7: //guardar en archivo .txt
					system("cls");

					system("pause");
					break;
				case 8:  //salir
					if((flagGuardar == 0 && flagAlta == 0 && flagArchivio == 0) || flagGuardar == 1)
					{
						printf("usted salio del programa. \n");
						option = 10;
					}
					else
					{
						printf("Antes de salir deber guardar en archivo los datos cargados. \n");
					}
					system("pause");
					break;
			}

		}while(option!=10);

		ll_deleteLinkedList(listaComputer);


	return EXIT_SUCCESS;
}
