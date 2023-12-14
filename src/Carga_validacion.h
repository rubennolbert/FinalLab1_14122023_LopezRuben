/*
 * Carga_validacion.h
 *
 *  Created on: 12 dic 2023
 *      Author: ruben
 */

#ifndef CARGA_VALIDACION_H_
#define CARGA_VALIDACION_H_


void MostrarMenu();

void MostrarMenuModificacion();

int ValidarNumero(int num, int limiteMin, int limiteMax);

int ValidarNumMayorACero(int num);

int esSoloLetras(char cadena[]);
int esNumerico(char str[]);
int esNumericoFlotante(char str[]);
int esAlfaNumerico(char str[]);

int FuncionMenu(char cadena[], int min, int max);

int FuncConfirma(char mensaje[], char* letra, char MensajeError[]);


void GetString(char mensaje[], char cadena[]);
void GetStringNumero(char mensaje[], char cadena[]);
float GetFloat(char mensaje[]);
int GetInt(char mensaje[]);
int GetIntRange(char mensaje[],int min, int max);
char getNumeroAleatorio(int desde , int hasta, int iniciar);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);


void OpcionTipoIdComputer(int tipoPasajeInt, char cadena[]);

void OpcionEstadoVuelo(int estadoVueloInt, char cadena[]);





#endif /* CARGA_VALIDACION_H_ */
