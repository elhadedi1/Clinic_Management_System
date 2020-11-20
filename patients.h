#include <stdio.h>
#include <stdlib.h>
#include "std_types.h"
typedef struct UserData{ //Structure with 5 data variables
	uint8 ID;
	uint8 Name[15];
	uint8 age;
	uint8 gender;
	uint8 reservationNumber;
	struct UserData * link;
}userData;

extern uint8 reservations[5]; //an array that determines the available slots
//prototyping of functions
void addPatient(uint8 ID,uint8 age,uint8 name[15],uint8 gender);
void printPatients();
uint8 checkID(uint8 ID);
void editPatientRecord(uint8 ID,uint8 age,uint8 name[15],uint8 gender);
void addReservations(uint8 ID,uint8 slot);
uint8 checkForPreviousReservations(uint8 ID);
void viewReservations();
void cancelReservations(uint8 ID);
void view_patient();


