#include "patients.h"


userData* head=NULL;

uint8 reservations[5]={1,1,1,1,1}; // by default all the Reservations are not reserved, The value of a certain reservation is set to 0 when it has been reserved

void addPatient(uint8 ID,uint8 age,uint8 name[15],uint8 gender)
{
	// a function that adds new patient records by adding new data in the struct
	uint8 i=0;
	userData *temp=(userData*)malloc(sizeof(userData)); //create new userData
	temp->ID=ID;
	temp->age=age;
	temp->reservationNumber=0;
	for(i=0;i<15;i++){temp->Name[i]=name[i];}
	temp->gender=gender;
	temp->link=NULL; // set the link of the newly created datatype struct to NULL
	if(head==NULL){
		head=temp; //in case of first element
	}
	else{
		userData* temp2 = head; //initialize userData 2 with head of list address
		while(temp2->link!=NULL)
		{ //loop through list to reach last address
			temp2=temp2->link;
		}
		temp2->link=temp; //set last address to new element
	}
}

void printPatients()
{ // a function that prints every single userData in the structure
	uint8 i=1,flag=0;
	userData *temp=head;

	while(temp!=NULL){
	    //while loop to loop through variables or data types of the struct until it reaches the last one
		flag++;
		printf("the ID of patient %u is %u \n", i,temp->ID);
		printf("the name of patient %u is %s ", i,temp->Name);
		printf("\nthe age of patient %u is %u \n", i,temp->age);
		printf("the gender of patient %u is %c \n", i,temp->gender);
		printf("\n\n");
		temp=temp->link;
		i++;
	}
	if(temp==NULL && flag==0){printf("\nNo patient IDs were entered.\n");}
}

void editPatientRecord(uint8 ID,uint8 age,uint8 name[15],uint8 gender){
	//a function that edits the content of a certain userData by knowing the ID of the patient
	uint8 i=0;
	userData *temp =head;
	while(temp!=NULL){
		if(ID==temp->ID)
		{	//if this is the right ID, change the data
		temp->age=age;
		for(i=0;i<15;i++){temp->Name[i]=name[i];}
		temp->gender=gender;
		}
		temp=temp->link;
	}
}

uint8 checkID(uint8 ID){
	// a function that returns 0 when the ID already exists and returns 1 when the ID doesn't exist
	uint8 flag=1,breakFlag=1;
	userData *temp=head;
	while(temp!=NULL && breakFlag!=0){
		if(ID==temp->ID){flag=0; breakFlag=0;} // when the desired ID is found set breakFlag=0 so that we don't have to loop through the rest of the linked list
		else{flag=1; breakFlag=1;}
		temp=temp->link;
	}
	return flag;
}

void addReservations(uint8 ID,uint8 slot){
	// a function to add reservations to the patiens by entering their ID and the number of the reservation slot
	userData *temp =head;
	uint8 breakFlag=1;
	slot++;
	while(temp!=NULL && breakFlag!=0){
		if(ID==temp->ID)
		{
			temp->reservationNumber=slot;
			breakFlag=0;
		}

		else{breakFlag=1;}
		temp=temp->link;
	}
}

uint8 checkForPreviousReservations(uint8 ID){
	userData *temp =head;
	uint8 breakFlag=1,flag=1;
	while(temp!=NULL && breakFlag!=0){
		if(ID==temp->ID)
		{
			if(temp->reservationNumber!=0){flag=0;}
			else{flag=1;}
			breakFlag=0;
		}
		else{breakFlag=1;}
		temp=temp->link;
	}
	return flag;
}

void viewReservations(){
	userData *temp =head;
	uint8 flag=0;
	while(temp!=NULL){
		printf("\nID: %d",temp->ID);
		if(temp->reservationNumber==1){printf(" - Reservation: from 2:00PM to 2:30PM\n");flag++;}
		else if(temp->reservationNumber==2){printf(" - Reservation: from 2:30PM to 3:00PM\n");flag++;}
		else if(temp->reservationNumber==3){printf(" - Reservation: from 3:00PM to 3:30PM\n");flag++;}
		else if(temp->reservationNumber==4){printf(" - Reservation: from 4:00PM to 4:30PM\n");flag++;}
		else if(temp->reservationNumber==5){printf(" - Reservation: from 4:30PM to 5:00PM\n");flag++;}
		else {printf(" - No reservation\n");}
		temp=temp->link;
	}
	if(temp==NULL && flag==0){printf("\nNo reservations are made yet\n");}
}
void cancelReservations(uint8 ID){
	userData *temp =head;
	uint8 breakFlag=1;
	while(temp!=NULL && breakFlag!=0){
		if(ID==temp->ID)
		{
			if(temp->reservationNumber==0){printf("\nNo reservation to cancel.\n");}
			else{
			    printf("\nCancelling Reservation....\n");
				reservations[(temp->reservationNumber)-1]=1; //set the reservation[i] to 1 indicating that it is free and can be reserved by other patients
				temp->reservationNumber=0;  // set the reservation number to 0 indicating that this patient doesn't have any reservations yet
				breakFlag=0;
			}
		}
		else{breakFlag=1;}
		temp=temp->link;
	}
}
void view_patient(){
    userData *temp =head;
    int ID;
    if(temp == NULL){
        printf("\nThere are no patients.\n");
    }
    else{
        printf("\nEnter patient ID : ");
        scanf("%d",&ID);
        while(temp!= NULL){
            if(ID == temp->ID){
                printf("the ID of patient is %u \n",temp->ID);
                printf("the name of patient  is %s ",temp->Name);
                printf("\nthe age of patient  is %u \n",temp->age);
                printf("the gender of patient  is %c \n",temp->gender);
                return;
            }
            else{
                temp = temp->link;
            }
        }
        printf("\nThis is wrong ID.\n");
    }
}
