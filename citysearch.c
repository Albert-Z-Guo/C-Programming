#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>



//define the key variables
char Name[30];
char StateCode[3];
int Population;
int Region;
int ZipCode;
struct city* next;



//define the structure of each city
struct city
{
    char Name[30];
    char StateCode[30];
    int Population;
    int Region;
    int ZipCode;
    struct city* next;
};



//define the StartPointer and the CurrentPointer 
struct city* StartPtr = NULL;
struct city* curr = NULL;



//create a structure called ptr locally
struct city* create_list(){
    printf("\nReading the text file and creating the list with headcity as %s...\n", Name);
    
    //allocate the space of the structure
    struct city* ptr = (struct city*)malloc(sizeof(struct city));
    if(NULL == ptr)
    {
        printf("\nCannot allocate the space for the new city\n");
        return NULL;
    }
    
    //assign the variables
    strcpy(ptr->Name, Name);
    strcpy(ptr->StateCode, StateCode);
    ptr->Population = Population;
    ptr->Region = Region;
    ptr->ZipCode = ZipCode;
    ptr->next = NULL;
    
	//define the StartPtr of the struct
    StartPtr = ptr;
    //assign CurrentPointer to point at the first struct
    curr = ptr;
   
    return ptr;
}



//create/add another structure also called ptr locally
struct city* AddCity(){
	//create a structure called ptr if there is no structure created yet
    if(NULL == StartPtr)
    {
        return (create_list());
    }
    
    //allocate the space of the structure
    struct city* ptr = (struct city*)malloc(sizeof(struct city));
    if(NULL == ptr)
    {
        printf("\nCannot allocate the space for the new city \n");
        return NULL;
    }
    
    //assign the variables
    strcpy(ptr->Name, Name);
    strcpy(ptr->StateCode, StateCode);
    ptr->Population = Population;
    ptr->Region = Region;
    ptr->ZipCode = ZipCode;
    ptr->next = NULL;
    
	//assign the CurrentPointer to point to the next struct
    curr->next = ptr;
    curr = ptr;
    
    return ptr;
}



//read the text file
void Read(){
//open the text file
FILE *InFilePtr;
InFilePtr = fopen("cities.txt","r");
if(InFilePtr == NULL){
	printf("Can't open cities.txt. Try again. Exiting...\n");
}

	char tempregion[3];
	char tempname[115];
	unsigned int tempzip;
	
	int i,j;
	for(i=0; i<115; i++)	
	{
		//scan the file; skip comma; and stop scanning
		fscanf(InFilePtr, "%[^,]s ", tempname);
		
		//convert all the city names to upper case
		for(j=0; j<strlen(tempname); j++)
		{
			tempname[j] = toupper(tempname[j]);
			if((tempname[j] == ' ' && (tempname[j+1] == ' ' || tempname[j+1] =='\t')) || tempname[j] == '\t')
			{
				//insert the 0 terminator
				tempname[j] = 0;
				break;
			}
		}
		
		//store the city name to the Name character array
		strcpy(Name,tempname);
		
		//scan the file; skip comma, space and tab; and stop scanning
		fscanf(InFilePtr, "%*[,' '\t]s");
		fscanf(InFilePtr, "%s , %u , %s , %u ", StateCode, &Population, tempregion, &ZipCode);
		
		tempzip = ZipCode;
		StateCode[2] = 0;
		tempregion[2] = 0;

		if(strcmp(tempregion,"NE")==0) Region = 0;

		else if(strcmp(tempregion,"NW")==0) Region = 1;

		else if(strcmp(tempregion,"SE")==0) Region = 2;

		else if(strcmp(tempregion,"SW")==0) Region = 3;

		else if(strcmp(tempregion,"MW")==0) Region = 4;

		else Region = 5;
		
		//add the read city (in this for loop)
		AddCity();
	}
	//close the text file
	fclose(InFilePtr);
}



//list all the cities
void List(){

//struct city* tmp;
struct city* ptr;

//define a ptr_temp pointer that points to the previous struct
struct city * PreviousPtr;

int i;
for (i=0; i<115; i++){
//define CurrentPointer to point at the beginning of the list
curr=StartPtr;

//define ptr to point at the second struct of the list
ptr=StartPtr->next;

while(ptr!=NULL){
	//if CurrentPointer is the StartPtr
	if (curr == StartPtr){
		if (strcmp(curr->Name,ptr->Name)>0){
			curr->next = ptr->next;
			ptr->next = curr;
			StartPtr = ptr;
		};
	}
	//store the previos pointer
	PreviousPtr = curr;
	
	//continue searching
	curr=ptr;
	ptr=ptr->next;
	if (ptr == NULL) break;
	
	//if CurrentPointer is not the StartPtr
	if(curr != StartPtr){
		if (strcmp(curr->Name,ptr->Name)>0){
			curr->next = ptr->next;
			ptr->next = curr;
			PreviousPtr->next = ptr;
		}
	}
}
}

//print the header
printf("\nCity Name\t\tZip Code\t\tState\t\tPopulation\t\tRegion\n");
printf("==============================================================================================\n");
struct city* pointer;
//print all the cities from the StartPointer
pointer = StartPtr;
char ReadRegion[6][6] = {"NE", "NW", "SE", "SW", "MW", "Other"};
while (pointer != NULL){
	printf("%-16s\t%d\t\t\t%s\t\t%d\t\t\t%s\n", pointer->Name,  pointer->ZipCode, pointer->StateCode, pointer->Population, ReadRegion[pointer->Region]);
	pointer = pointer->next;
}
}



//display the found cities
void DisplayFoundCity(struct city* ptr){
char ReadRegion[6][6] = {"NE", "NW", "SE", "SW", "MW", "Other"};

//print the found result
printf("==================================\n");
printf("City Name		:%s\n", ptr->Name);
printf("Located in State	:%s\n", ptr->StateCode);
printf("Zip Code		:%d\n", ptr->ZipCode);
printf("Population		:%d\n", ptr->Population);
printf("Region			:%s\n", ReadRegion[ptr->Region]);
printf("==================================\n");
}



//search any city in the list
void SearchCity(){
//char TempUserInput[30];
char UserInput[30];
int found=0;

printf("\nWhich city do you want me to search? ");
scanf("%s", UserInput);

//convert the User Input to upper case
int i = 0;
for(i=0; i<strlen(UserInput); i++){
	UserInput[i] = toupper(UserInput[i]);
}

printf("\nSearching %s...\n", UserInput);

//search from the StartPointer
struct city* ptr = StartPtr;

//initialize the SearchCity function
while (ptr != NULL){
	
	//SearchCity(ptr, UserInput);
	if(strcmp(UserInput, ptr->Name)==0){
		
		//printf("Found.\n");
		DisplayFoundCity(ptr);
		
		//counter update
		found = found+1;
	}
	ptr = ptr->next;
};
//determine the singular/plural form of the word "city"
if (found > 1) printf("%d cities found\n\n", found);
if (found <= 1) printf("%d city found\n\n", found);
}



//add a city with all corresponding information to the list
void Add(){

char tempregion[3];
int found=0;
int a;

printf("\nAdding city...");

printf("\nName: ");
scanf("%s", Name);

//convert the new city's name to upper case
for(a=0; a<strlen(Name); a++){
	Name[a] = toupper(Name[a]);
}

printf("State Code (Please enter the state code abbreviation. E.g. NY means New York): ");
scanf("%s", StateCode);

//convert the new city's State Code to upper case
for(a=0; a<strlen(StateCode); a++){
	StateCode[a] = toupper(StateCode[a]);
}

printf("Zip Code: ");
scanf("%d", &ZipCode);

printf("Population: ");
scanf("%d", &Population);

printf("Region (Please enter the region abbreviation. E.g. NE means North East): ");
scanf("%s", tempregion);

//convert the new city's Region to upper case
for(a=0; a<strlen(tempregion); a++){
	tempregion[a] = toupper(tempregion[a]);
}

//search any possible overlap in the list from the StartPointer
struct city* ptr = StartPtr;

while (ptr != NULL){
	
	//SearchCity(ptr, UserInput);
	if(strcmp(Name, ptr->Name)==0 && strcmp(StateCode, ptr->StateCode)==0){
		printf("\nCity, State pair already exists, not adding...\n");
		found = found+1;
	}
	ptr = ptr->next;
};

//add the city to the list if there is no overlap in the list
if (!found){	
	//define a new struct to be added to the list
	struct city* ptr = (struct city*)malloc(sizeof(struct city));
	
	//insert the 0 terminator
	tempregion[2] = 0;

	if(strcmp(tempregion,"NE")==0)
		Region = 0;
	
	else if(strcmp(tempregion,"NW")==0) Region = 1;

	else if(strcmp(tempregion,"SE")==0) Region = 2;

	else if(strcmp(tempregion,"SW")==0) Region = 3;

	else if(strcmp(tempregion,"MW")==0) Region = 4;

	else Region = 5;		
	
	strcpy(ptr->Name, Name);
	strcpy(ptr->StateCode, StateCode);
	ptr->Population = Population;
	ptr->Region = Region;
	ptr->ZipCode = ZipCode;
	ptr->next = NULL;
    
	//assign the CurrentPointer to point to the next struct
	curr->next = ptr;
	curr = ptr;

	printf("\nThis new city is successfully added to database.\n");
}
}



//delete a city from the list
void Delete(){

int a;
int Choice;
int found=0;
char Name[30];
int counter=0;
char match_state[4][3];

printf("\nWhich city do you want to delete?");
scanf("%s", Name);

//convert the city's name to upper case
for(a=0; a<strlen(Name); a++){
		Name[a] = toupper(Name[a]);
};

//search any possible overlap in the list from the StartPointer
struct city* ptr = StartPtr;

//define a tmp pointer that points to NULL originally
struct city* tmp = NULL;

//define a ptr_temp pointer that points to the previous struct
struct city *ptr_temp;

//search through the list
while (ptr != NULL){
	if(strcmp(Name, ptr->Name)==0){
		printf("%d) Delete %s, %s\n", ++found, ptr->Name, ptr->StateCode);
		strcpy(match_state[counter++],ptr->StateCode);
	}
	ptr = ptr->next;
};

if (found==0) printf("\nThe city you want to delete doesn't exist.\n");

if (found>0){
	//scan user's choice
	scanf("%d", &Choice);
	Choice--;
	
	//if the city that the user wants to delete is at the beginning of the list
	ptr = StartPtr;
	if((strcmp(Name, ptr->Name)==0)&&(strcmp(match_state[Choice],ptr->StateCode)==0)){
		StartPtr = ptr->next;
		free(ptr);
		printf("\nThe city is deleted successfully.\n\n");
	}

	//define tmp to point at the beginning of the list
	tmp=StartPtr;

	//define ptr to point at the second struct of the list
	ptr=StartPtr->next;

	while(ptr!=NULL){
		//compare both the city name and the state code
		if((strcmp(Name, ptr->Name)==0)&&(strcmp(match_state[Choice],ptr->StateCode)==0)){
		
			//let the pointer, which originally points to the struct that the ptr(the struct pointer) points, point to the next struct 
			tmp->next = ptr->next;
			
			//let the pointer ptr_temp point to the struct to be deleted
			ptr_temp = ptr;
			
			//continue moving the ptr(the struct pointer) to the next struct
			ptr=ptr->next;
			
			//free the memory of the struct to be deleted
			free(ptr_temp);
			printf("\nThe city is deleted successfully.\n\n");
			break;
		}
		else{
			//let the pointer tmp point to the struct that the ptr(the struct pointer)
			tmp=ptr;
			//continue moving the ptr(the struct pointer) to the next struct
			ptr=ptr->next;
		}
	}
}

}



void Advanced_Region_Search() {
//search from the beginning of the list
struct city* ptr = StartPtr;

int NE=0;
int NW=0;
int SE=0;
int SW=0;
int MW=0;
int Other=0;

//search through the list
while (ptr != NULL){
	if(ptr->Region==0) NE=NE+1;
	if(ptr->Region==1) NW=NW+1;
	if(ptr->Region==2) SE=SE+1;
	if(ptr->Region==3) SW=SW+1;
	if(ptr->Region==4) MW=MW+1;
	if(ptr->Region==5) Other=Other+1;
	
	//search through the list
	ptr = ptr->next;
};

//print the search result
printf("\nNORTH EAST		%d\n", NE);
printf("NORTH WEST		%d\n", NW);
printf("SOUTH EAST		%d\n", SE);
printf("SOUTH WEST		%d\n", SW);
printf("MID WEST		%d\n", MW);
printf("Other			%d\n", Other);
}



void Advanced_State_Search(){

int found;
int i;
//the number of states
int a=0;
int n=0;
char StateCodeCharArray[115][3];
int StateCodeintArray[115];

struct city* ptr = StartPtr;

strcpy(StateCodeCharArray[0], ptr->StateCode);
StateCodeintArray[0] = 0;

while(ptr != NULL){
	
	found = 0;
	
	for(i=0; i<(a+1); i++){
		//if the same state code is found
		if (strcmp(StateCodeCharArray[i], ptr->StateCode)==0){
			StateCodeintArray[i] = StateCodeintArray[i]+1;
			found = 1;
			break;
		}
	}
	
	if (!found){
		a=a+1;
		strcpy(StateCodeCharArray[a], ptr->StateCode);
		StateCodeintArray[a] = 1;
	}
	
	//search through the list
	ptr = ptr->next;
}

printf("\n");
for (n=0; n<a; n++){
	printf("%s		%d cities\n", StateCodeCharArray[n], StateCodeintArray[n]);
}

}



void Advanced_Population_Search(){
int a=0;
int b=0;
int c=0;
int d=0;
int e=0;
int f=0;

//search from the beginning of the list
struct city* ptr = StartPtr;

while (ptr != NULL){
	if (ptr->Population > 2000000) f=f+1;
	if (ptr->Population > 1400000 && ptr->Population < 2000000) a=a+1;
	if (ptr->Population > 1000000 && ptr->Population < 1399999) b=b+1;
	if (ptr->Population > 600000 && ptr->Population < 999999) c=c+1;
	if (ptr->Population > 100000 && ptr->Population < 599999) d=d+1;
	if (ptr->Population > 0 && ptr->Population < 100000) e=e+1;

//search through the list
ptr = ptr->next;
}

printf("\nPopulation above 2,000,000			%d cities\n", f);
printf("Population 2,000,000 - 1,400,000		%d cities\n", a);
printf("Population 1,399,999 - 1,000,000		%d cities\n", b);
printf("Population 999,999 - 600,000			%d cities\n", c);
printf("Population 599,999 - 100,000			%d cities\n", d);
printf("Population under 100,000			%d cities\n", e);
}



//advanced search options
void Advanced(){
int i;
char UserChoice[15];

printf("\nPlease choose an advanced search option: State, Region, Population ");

//scan the user input
scanf ("%s",UserChoice);
	
//convert the user input to all upper case
	for(i=0; i<strlen(UserChoice); i++){
		UserChoice[i] = toupper(UserChoice[i]);
	}

if(strcmp(UserChoice,"STATE")==0) Advanced_State_Search();

else if(strcmp(UserChoice,"REGION")==0) Advanced_Region_Search();

else if(!strcmp(UserChoice,"POPULATION")) Advanced_Population_Search();

else printf("\nInvalid Option.\n");
}



int main (){
//Read the text file and create the linked list
Read();

while (1){
	printf("\nWhat would you like me to do? Search/Delete/Add/List/Advanced/Exit: ");

	char option[15];
	int a;

	//scan the user input
	scanf ("%s",option);
	
	//convert the user input to all upper case
	for(a=0; a<strlen(option); a++){
		option[a] = toupper(option[a]);
	}

	if(!strcmp(option,"SEARCH")) SearchCity();

	else if(!strcmp(option,"DELETE")) Delete();

	else if(!strcmp(option,"ADD")) Add();

	else if(!strcmp(option,"LIST")) List();

	else if(!strcmp(option,"ADVANCED")) Advanced();

	else if(!strcmp(option,"EXIT")) break;
	
	else printf("\nInvalid Option. ");
}
}