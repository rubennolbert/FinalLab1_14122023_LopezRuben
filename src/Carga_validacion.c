#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "Carga_validacion.h"

void MostrarMenu()
{
	printf("--------------------------------------------------------------------------------------\n");
	printf("************************************* Menu ABM ***************************************\n");
	printf("01. Cargar los datos desde el archivo data.csv (modo texto).\n");
	printf("02. Alta de datos.\n");
	printf("03. Modificar datos.\n");
	printf("04. Baja de datos.\n");
	printf("05. listar datos.\n");
	printf("06. Ordenar datos.\n");
	printf("07. Guardar los datos en el archivo data.csv (modo texto).\n");
	printf("08. salir.\n");
	printf("--------------------------------------------------------------------------------------\n");
}


void MostrarMenuModificacion()
{
	printf("\tMenu modificacion pasajero:\n");
	printf("\t1. Nombre:\n");
	printf("\tApellido:\n");
	printf("\t3 Precio:\n");
	printf("\t4. Codigo de vuelo:\n");
	printf("\t5. Estado de vuelo:\n");
	printf("\6. Estado de vuelo:\n");
	printf("\t7. salir de sub-menu:\n");
}

int ValidarNumero(int num, int limiteMin, int limiteMax)
{
	int respuesta = 1;

	    if(num < limiteMin || num > limiteMax /*|| ValidarCaracter(num)*/)
	    {
	        printf("Error, ingrese un numero dentro de los parametros %d - %d\n", limiteMin, limiteMax);
	        respuesta   = 0;
	    }
	     return respuesta;
}


int ValidarNumMayorCero(int num)
{
    int rta = 1;
    if(num<=0)
    {
        printf("\tERROR, ingrese un numero positivo. \n");
        rta = 0;
    }

    return rta;
}


int esSoloLetras(char cadena[])
{
   int i=0;
   int bool = 1;
   while(cadena[i] != '\0')
   {
       if((cadena[i] != ' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
           bool = 0;
       i++;
   }
   return bool;
}


int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}


int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}



int FuncionMenu(char mensaje[], int min, int max)
{
    int opcion;

    printf(mensaje);
    fflush(stdin);
    scanf("%d", &opcion);
    while(0 == ValidarNumero(opcion, min, max))
    {
        fflush(stdin);
        scanf("%d", &opcion);
    }
    printf("\n");

    return opcion;
}


int FuncConfirma(char mensaje[], char* letra, char MensajeError[])
{
	int rta = 0;
	char opcion;

	if(letra != NULL && mensaje != NULL && MensajeError != NULL)
	{


		printf("%s", mensaje);
	    fflush(stdin);
	    scanf("%c", &opcion);
	    opcion = toupper(opcion);

	    while(!(opcion == 'S' || opcion == 'N'))
	    {
	    	printf("%s", MensajeError);
	    	fflush(stdin);
			scanf("%c", &opcion);
			opcion = toupper(opcion);
	    }
	    *letra = opcion;
		rta = 1;
	}

	return rta;
}

void GetString(char mensaje[],char cadena[])
{

    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", cadena);
    while(0==esSoloLetras(cadena))
    {
    	printf("Ingrese letras. %s",mensaje);
		fflush(stdin);
		scanf ("%s", cadena);
    }
}


void GetStringNumber(char mensaje[],char cadena[])
{

    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", cadena);

}


float GetFloat(char mensaje[])
{
    float auxFloat;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%f",&auxFloat);
    while(0==ValidarNumMayorCero(auxFloat))
    {
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%f",&auxFloat);
    }
    return auxFloat;
}


int GetInt(char mensaje[])
{
    int auxInt;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxInt);

    return auxInt;
}


int GetIntRange(char mensaje[], int min, int max)
{
    int auxInt;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%d",&auxInt);
    while(0==ValidarNumero(auxInt, min, max))
    {
 		fflush(stdin);
		scanf("%d",&auxInt);
    }

    return auxInt;
}



char getNumeroAleatorio(int desde , int hasta, int iniciar)
{
    if(iniciar)
        srand(time(NULL));
    return desde + (rand() % (hasta + 1 - desde)) ;
}


int GetStringLetras(char mensaje[],char input[])
{
    char aux[256];
    GetString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int GetStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    GetString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int GetStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    GetString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


void OpcionTipoIdComputer(int tipoInt, char cadena[])
{
	switch(tipoInt)
	{
		case 1:
			strcpy(cadena, "Desktop");
			break;
		case 2:
			strcpy(cadena, "Laptop");
			break;

	}


}


void OpcionEstadoVuelo(int estadoVueloInt, char cadena[])
{
	switch(estadoVueloInt)
		{
			case 1:
				strcpy(cadena, "Aterrizado");
				break;
			case 2:
				strcpy(cadena, "En Horario");
				break;
			case 3:
				strcpy(cadena, "En Vuelo");
				break;
			case 4:
				strcpy(cadena, "Demorado");
				break;
		}
	// 1=Aterrizado, 2=En Horario, 3=En Vuelo, 4=Demorado
}



