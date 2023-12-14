/*
 * Controller.h
 *
 *  Created on: 12 dic 2023
 *      Author: ruben
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_loadFromText(char* path , LinkedList* pArrayListComputer, int* flagA, int* flagB);
int controller_loadFromBinary(char* path , LinkedList* pArrayListComputer, int* flagA, int* flagB);
int controller_addComputer(LinkedList* pArrayListComputer, int* flagA, int* flagB);
int controller_editComputer(LinkedList* pArrayListComputer, int* flagA, int* flagB);
int controller_removeComputer(LinkedList* pArrayListComputer, int* flagA, int* flagB);
int controller_listComputer(LinkedList* pArrayListComputer, int* flagA, int* flagB);
int controller_sortComputer(LinkedList* pArrayListComputer, int* flagA, int* flagB);
int controller_saveAsText(char* path , LinkedList* pArrayListComputer, int* flagA, int* flagB, int* flagC);
int controller_saveAsBinary(char* path , LinkedList* pArrayListComputer, int* flagA, int* flagB, int* flagC);




#endif /* CONTROLLER_H_ */
