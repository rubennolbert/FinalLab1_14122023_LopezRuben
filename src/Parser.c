#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Computer.h"



/** \brief Parsea los datos los datos de al entidad desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListeComputer LinkedList*
 * \return int
 *
 */
int parser_eComputerFromText(FILE* pFile , LinkedList* pArrayListeComputer)
{
	int rta = 0;
	eComputer* auxeComputer = NULL;
	char id[21];
	char descripcion[51];
	char price[21];
	char idTipo[21];
	int cantDatos;

	if(pFile != NULL && pArrayListeComputer != NULL)
	{
		while(feof(pFile) == 0) // !feof()
		{
			cantDatos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, descripcion, price, idTipo);
			if(cantDatos==4)
			{
				auxeComputer = Computer_newParametros(id, descripcion, price, idTipo);
				if(auxeComputer != NULL)
				{
					ll_add(pArrayListeComputer, auxeComputer);
					rta = 1;
				}
				else
				{
					Computer_delete(auxeComputer);
					auxeComputer = NULL;
				}
			}
			else
			{
				printf("Error en lectura de datos del archivo.\n");
			}
		}
	}
    return rta;
}

/** \brief Parsea los datos los datos de la entidad desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListeComputer LinkedList*
 * \return int
 *
 */
int parser_eComputerFromBinary(FILE* pFile , LinkedList* pArrayListeComputer)
{
	int rta = 0;
	int cantDatos;

	eComputer* auxeComputer;

	if(pFile != NULL && pArrayListeComputer != NULL)
	{
		while(0==feof(pFile)) // !feof()
		{
			auxeComputer = Computer_new();
			if(auxeComputer != NULL)
			{
				cantDatos = fread(auxeComputer, sizeof(eComputer), 1, pFile);
				if(cantDatos == 1)
				{
						ll_add(pArrayListeComputer, auxeComputer);
 						rta = 1;
				}
			}
		}
	}

    return rta;
}
