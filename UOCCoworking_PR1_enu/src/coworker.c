#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coworker.h"

void getCoworkerStr(tCoworker coworker, int maxSize, char *str) 
{
#ifdef TYPEDEF_COMPLETED
	snprintf(str,maxSize-1,"%d %s %s %s %d %d %d %s %d %d %d %d %.2f", 
        coworker.id, coworker.name, coworker.surname, coworker.docNumber, 
        coworker.birthDate.year, coworker.birthDate.month, coworker.birthDate.day, 
        coworker.birthCity, (int)coworker.status, (int)coworker.profile, coworker.bookingsCounter,
        coworker.points, coworker.satisfaction);
#endif
}

void getCoworkerObject(const char *str, tCoworker *coworker) 
{	
#ifdef TYPEDEF_COMPLETED
    int id;
    int status, profile;
    
    id= 0;
	sscanf(str, "%d %s %s %s %d %d %d %s %d %d %d %d %f", &(id), coworker->name, coworker->surname, 
        coworker->docNumber, &(coworker->birthDate.year), &(coworker->birthDate.month), &(coworker->birthDate.day),
        coworker->birthCity, &status, &profile, &coworker->bookingsCounter, 
        &coworker->points, &coworker->satisfaction);
	coworker->status = (tCivilState)(status);
	coworker->profile = (tProfessionalProfile)(profile);
	coworker->id = (tCoworkerId)(id);
#endif
}

int dateCmp( tDate d1, tDate d2 ) {
    
    int result;

    result= 0;
    if (d1.year > d2.year)
        result= 1;
    else if (d1.year < d2.year)
        result= -1;
    else {
        if (d1.month > d2.month)
            result= 1;
        else if (d1.month < d2.month)
            result= -1;
        else {
            if (d1.day > d2.day)
                result= 1;
            else if (d1.day < d2.day)
                result= -1;
        }
    }
    
    return result;
}

void coworkerTableInit(tCoworkerTable *coworkerTable) {
	
	coworkerTable->nCoworkers=0;
}

void convertToUpper( char *string )
{
    int i, len;
    char originalChar;
    
    len= strlen(string);
    for (i= 0; i < len; i++) {
        originalChar= string[i];
        if (originalChar >= 'a' && originalChar <= 'z') 
            string[i]= originalChar + 'A' - 'a';
    }
}

int strcmpUpper( char *s1, char *s2 )
{
    int result;
    result= 0;
/*************** PR1 EX3A *****************/
    char sA[MAX_LINE];
    char sB[MAX_LINE];
    
    strcpy( sA, s1 );
    strcpy( sB, s2 );
    convertToUpper( sA );
    convertToUpper( sB );
   
    result= strcmp(sA,sB);
/******************************************/
    return result;
}

int coworkerCmp(tCoworker d1, tCoworker d2) {
	
	int result = 0;

/*************** PR1 EX3B *****************/
    result= strcmpUpper(d1.name,d2.name);
    if (result==EQUAL)
    {
        result= strcmpUpper(d1.surname,d2.surname);
        if (result==EQUAL)
        {
            result= strcmpUpper(d1.docNumber,d2.docNumber);
            if (result==EQUAL)
            {
                result= dateCmp(d1.birthDate, d2.birthDate);
                if (result==EQUAL)
                {
                    result= strcmpUpper(d1.birthCity, d2.birthCity);
                    if (result==EQUAL)
                    {
                        if (d1.status > d2.status)
                            result = HIGHER;
                        else if (d1.status < d2.status)
                            result = SMALLER;
                        else{
                            if (d1.profile > d2.profile)
                                result = HIGHER;
                            else if (d1.profile < d2.profile)
                                result = SMALLER;
                            else{
                                if (d1.bookingsCounter > d2.bookingsCounter)
                                    result = HIGHER;
                                else if (d1.bookingsCounter < d2.bookingsCounter)
                                    result = SMALLER;
                                else {
                                    if (d1.points > d2.points)
                                        result = HIGHER;
                                    else if (d1.points < d2.points)
                                        result = SMALLER;
                                    else {
                                        if (d1.satisfaction > d2.satisfaction)
                                            result = HIGHER;
                                        else if (d1.satisfaction < d2.satisfaction)
                                            result = SMALLER;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
/******************************************/

    return result;
}

void coworkerCpy(tCoworker *dst, tCoworker src) 
{    
#ifdef TYPEDEF_COMPLETED
    dst->id = src.id; 
    strcpy(dst->name,src.name);
    strcpy(dst->surname,src.surname);
    strcpy(dst->docNumber,src.docNumber);
    dst->birthDate.year = src.birthDate.year;
    dst->birthDate.month = src.birthDate.month;
    dst->birthDate.day = src.birthDate.day;
    strcpy(dst->birthCity,src.birthCity);
    dst->status = src.status;
    dst->profile = src.profile;    
    dst->bookingsCounter = src.bookingsCounter;
    dst->points= src.points;
    dst->satisfaction= src.satisfaction;
#endif
}

void coworkerTableAdd(tCoworkerTable *tabCoworker, tCoworker coworker, tError *retVal) {

	*retVal = OK;

	/* Check if there enough space for the new coworker */
	if(tabCoworker->nCoworkers>=MAX_COWORKERS)
		*retVal = ERR_MEMORY;

	if (*retVal == OK) {
		/* Add the new coworker to the end of the table */
		coworkerCpy(&tabCoworker->table[tabCoworker->nCoworkers],coworker);
		tabCoworker->nCoworkers++;
	}

}

int coworkerTableFind(tCoworkerTable tabCoworker, tCoworkerId id) {

	int i, idx;
    
    i= 0;
    idx= NO_COWORKER;
	while(i< tabCoworker.nCoworkers && idx==NO_COWORKER) {
		/* Check if the id is the same */
		if(tabCoworker.table[i].id==id) {
			idx = i;
		}
		i++;
	}
	
	return idx;
}

void coworkerTableDel(tCoworkerTable *tabCoworker, tCoworker coworker) 
{	
/*************** PR1 EX7 *****************/
	int i;
    int pos;

    pos = coworkerTableFind(*tabCoworker,coworker.id);
    if (pos!=NO_COWORKER)
    {
        for(i=pos; i<tabCoworker->nCoworkers-1; i++) {    
            coworkerCpy(&tabCoworker->table[i],tabCoworker->table[i+1]);
        }
        tabCoworker->nCoworkers=tabCoworker->nCoworkers-1;    
    }
/******************************************/
}

void coworkerTableSave(tCoworkerTable tabCoworker, const char* filename, tError *retVal) {
	
	FILE *fout;
	int i;
	char str[MAX_LINE];
	*retVal = OK;
	
	/* Open the output file */
	if((fout=fopen(filename, "w"))==0) {
		*retVal = ERR_CANNOT_WRITE;
	} else {
	
        /* Save all coworkers to the file */
        for(i=0;i<tabCoworker.nCoworkers;i++) {
            getCoworkerStr(tabCoworker.table[i], MAX_LINE, str);
            fprintf(fout, "%s\n", str);
        }
            
        /* Close the file */
        fclose(fout);
	}
}

void coworkerTableLoad(tCoworkerTable *tabCoworker, const char* filename, tError *retVal) {
		
	FILE *fin;
	char line[MAX_LINE];
	tCoworker newCoworker;

	*retVal = OK;

	/* Initialize the output table */
	coworkerTableInit(tabCoworker);
	
	/* Open the input file */
	if((fin=fopen(filename, "r"))!=NULL) {

		/* Read all the lines */
		while(!feof(fin) && tabCoworker->nCoworkers<MAX_COWORKERS) {
			/* Remove any content from the line */
			line[0] = '\0';
			/* Read one line (maximum 511 chars) and store it in "line" variable */
			fgets(line, MAX_LINE-1, fin);
			/* Ensure that the string is ended by 0*/
			line[MAX_LINE-1]='\0';
			if(strlen(line)>0) {
				/* Obtain the object */
				getCoworkerObject(line, &newCoworker);
				/* Add the new coworker to the output table */
				coworkerTableAdd(tabCoworker, newCoworker, retVal);		
			}
		}
		/* Close the file */
		fclose(fin);
		
	}else {
		*retVal = ERR_CANNOT_READ;
	}
}

int calculateAge( tDate birthDate )
{
   return 2020 - birthDate.year;
}

void coworkerTableSelectCoworkers(tCoworkerTable coworkers, char *city, tCoworkerTable *result) 
{
/*************** PR1 EX4A *****************/
	int i, age;
    tError retVal;
    tCivilState status;
    tProfessionalProfile profile;
    
	coworkerTableInit(result);
	for(i=ZERO;i<coworkers.nCoworkers;i++) {
		if (strcmp(city, coworkers.table[i].birthCity)!=EQUAL){
            age= calculateAge(coworkers.table[i].birthDate);
            status= coworkers.table[i].status;
            profile= coworkers.table[i].profile;
            if (age >= 25 && age <= 35 && status == SINGLE && 
                (profile == OCCASIONAL || profile == EMPLOYEE || profile == PARTNER))
                coworkerTableAdd(result, coworkers.table[i], &retVal);
		}
	}
/******************************************/
}

void coworkerTableSelectSatisfiedCoworkers(tCoworkerTable coworkers, tCoworkerTable *result) {

/*************** PR1 EX4B *****************/
	int i;
    tError retVal;
    
	coworkerTableInit(result);
	for(i=ZERO;i<coworkers.nCoworkers;i++) {
		if (coworkers.table[i].satisfaction > MIN_SATISFACTION && coworkers.table[i].bookingsCounter >= MIN_BOOKINGS) {
			coworkerTableAdd(result, coworkers.table[i], &retVal);
		}
	}
/******************************************/
}

float coworkerTableGetAvgPointsPerBooking(tCoworkerTable tabCoworker) 
{
    float avg= 0.0;
/*************** PR1 EX6A *****************/
	int i, accPoints, accBookings;

    accPoints= ZERO;
    accBookings= ZERO;
	for(i=ZERO;i<tabCoworker.nCoworkers;i++) {
        accPoints += tabCoworker.table[i].points;
        accBookings += tabCoworker.table[i].bookingsCounter;        
	}
    if (accBookings > ZERO)
        avg= (float)(accPoints) / (float)(accBookings);
/******************************************/
    return avg;
}

void coworkerTableGetMaxSatisfactionPerAgeInterval(tCoworkerTable tabCoworker,
     float *upto29, float *between30and44, float *between45and59, float *from60) 
{
/*************** PR1 EX6B *****************/
int i, age;
    *upto29= ZERO;
    *between30and44= ZERO;
    *between45and59= ZERO;
    *from60= ZERO;

	for(i = ZERO;i < tabCoworker.nCoworkers;i++) {
        age= calculateAge(tabCoworker.table[i].birthDate);
        if (age < AGE_INTERVAL_FIRST_LIMIT) {
            if (tabCoworker.table[i].satisfaction > *upto29)
                *upto29 = tabCoworker.table[i].satisfaction;
        } 
        else if (age < AGE_INTERVAL_SECOND_LIMIT) {
            if (tabCoworker.table[i].satisfaction > *between30and44)
                *between30and44 = tabCoworker.table[i].satisfaction;      
        }
        else if (age < AGE_INTERVAL_THIRD_LIMIT) {
            if (tabCoworker.table[i].satisfaction > *between45and59)
                *between45and59 = tabCoworker.table[i].satisfaction;      
        }
        else {
            if (tabCoworker.table[i].satisfaction > *from60)
                *from60 = tabCoworker.table[i].satisfaction;
        }
	}
/******************************************/
}

