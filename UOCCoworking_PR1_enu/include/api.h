#include "data.h"

/* 
 * Methods for application data management 
 */

/* Initialize the application data */
void appDataInit(tAppData *object);

/* Load the application data from file */
void appDataLoad(tAppData *object, tError *error);

/* Save the application data to a file */
void appDataSave(tAppData object, tError *error);

/* Allow to assign a path to the application data */
void appDataSetPath(tAppData *object, const char *path);

/* 
 * API
 */

/* Return a table with the coworkers */
void getCoworkers(tAppData object, tCoworkerTable *result);

/* Get the coworker information */
void getCoworker(tAppData object, tCoworkerId coworkerId, tCoworker *coworker, tError *retVal);

/* Add a new coworker */
void addCoworker(tAppData *object, tCoworker coworker, tError *retVal);

/* Remove a certain coworker */
void removeCoworker(tAppData *object, tCoworker coworker);

/* Return the table of coworking centers */
void getCoworkingCenters(tAppData object, tCoworkingCenterTable *result);

/* Get the coworking center information */
void getCoworkingCenter(tAppData object, tCoworkingCenterId coworkingCenterId, tCoworkingCenter *coworkingCenter, tError *retVal);

/* Add a new coworking center */
void addCoworkingCenter(tAppData *object, tCoworkingCenter coworkingCenter, tError *retVal);
