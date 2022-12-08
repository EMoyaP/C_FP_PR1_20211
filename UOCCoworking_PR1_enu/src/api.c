#include <stdio.h>
#include <math.h>
#include <string.h>
#include <api.h>
#include "coworker.h"
#include "coworkingcenter.h"

void appDataInit(tAppData *object) {
	/* Set parent folder as the default path */
	strcpy(object->path, "../");
	
	/* Initialize the coworker table */
	coworkerTableInit(&(object->coworkers));
	
	/* Initialize the coworking centers table */
	coworkingCenterTableInit(&(object->coworkingCenters));
}

void appDataLoad(tAppData *object, tError *retVal) {
	char path[MAX_LINE];
	*retVal = OK;
	
	/* Load the table of coworking centers */
	snprintf(path,MAX_PATHNAME+MAX_FILENAME,"%scoworkingcenters.txt", object->path);
	coworkingCenterTableLoad(&(object->coworkingCenters), path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error reading the file of coworking centers\n");
	}

	/* Load the table of coworkers */
	snprintf(path,MAX_PATHNAME+MAX_FILENAME,"%scoworkers.txt", object->path);
	coworkerTableLoad(&(object->coworkers), path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error reading the file of coworkers\n");
	}
}

void appDataSave(tAppData object, tError *retVal)  {
	char path[MAX_LINE];
	*retVal = OK;
	
	/* Save the table of coworking centers */
	snprintf(path,MAX_PATHNAME+MAX_FILENAME,"%scoworkingcenters.txt", object.path);
	coworkingCenterTableSave(object.coworkingCenters, path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error saving the file of coworking centers\n");
	}
	
	/* Save the table of coworkers */
	snprintf(path,MAX_PATHNAME+MAX_FILENAME,"%scoworkers.txt", object.path);
	coworkerTableSave(object.coworkers, path, retVal);
	if(*retVal!=OK) {
		printf("ERROR: Error saving the file of coworkers\n");
	}
}

void appDataSetPath(tAppData *object, const char *path)  {		
	strncpy(object->path, path, MAX_PATHNAME);	
}


/*********************** 
 *        API
 **********************/

void getCoworkingCenters(tAppData object, tCoworkingCenterTable *result) {
	*result = object.coworkingCenters;	
}

void getCoworkingCenter(tAppData object, tCoworkingCenterId coworkingCenterId, tCoworkingCenter *coworkingCenter, tError *retVal) {
	
	int i;
	*retVal = OK;

	/* Check if there is a coworking center with this id */
	i = coworkingCenterTableFind(object.coworkingCenters, coworkingCenterId);
	if (i!=NO_COWORKINGCENTER) {
		coworkingCenterCpy(coworkingCenter,object.coworkingCenters.table[i]);
	} else {
		*retVal = ERR_ENTRY_NOT_FOUND;
	}
}

void addCoworkingCenter(tAppData *object, tCoworkingCenter coworkingCenter, tError *retVal) 
{
	*retVal = OK;
	tCoworkingCenter tmp;

	/* Check if there is another coworking center with the same id */
	getCoworkingCenter(*object, coworkingCenter.id, &tmp, retVal);
	if(*retVal==OK) {
		*retVal = ERR_DUPLICATED_ENTRY;
	} else {
		/* Add the new coworking center using the coworking center table method */
		coworkingCenterTableAdd(&(object->coworkingCenters), coworkingCenter, retVal);
	}
}

void getCoworkers(tAppData object, tCoworkerTable *result) {
	*result = object.coworkers;	
}

void getCoworker(tAppData object, tCoworkerId id, tCoworker *coworker, tError *retVal) {
	
	int i;
	*retVal = OK;
	
	/* Check if there is a coworker with this id */
	i = coworkerTableFind(object.coworkers, id);
	if (i!=NO_COWORKER) {
		coworkerCpy(coworker,object.coworkers.table[i]);
	} else {
		*retVal = ERR_ENTRY_NOT_FOUND;
	}
}

void addCoworker(tAppData *object, tCoworker coworker, tError *retVal) {
	*retVal = OK;
	tCoworker tmpCoworker;
    
	/* Check if there is another coworker with the same id */
	getCoworker(*object, coworker.id, &tmpCoworker, retVal);
	if(*retVal==OK) {
		*retVal = ERR_DUPLICATED_ENTRY;
	} else {
		/* Add the new coworker using the coworker table method */
		coworkerTableAdd(&(object->coworkers), coworker, retVal);
	}
}

void removeCoworker(tAppData *object, tCoworker coworker) 
{	
	/* Call the method from the coworkers table*/
	coworkerTableDel(&(object->coworkers), coworker);
}
