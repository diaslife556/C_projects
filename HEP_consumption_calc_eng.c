#include <stdio.h>
#include <string.h>
//main terminal function where the action is selected
int Home(int *pointquery){
    int query;
printf("\n\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/");
printf("\nWelcome to PBZ calculator for consumed electricity! [HEP ELECTRICITY]\n");
printf("___________________________________________________\n");
printf("         /   /                 _______   ______       \n");
printf("        /   /      |     |    |         |      | \n");
printf("       /   /       |     |    |         |      ) \n");
printf("       --  --      |_____|    |_______  |_____/            \n");
printf("        /   /      |     |    |         |       \n");
printf("       /   /       |     |    |         |      \n");
printf("      /   /        |     |    |_______  |             \n");
printf("____________________________________________________\n");
printf("\n\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/");
do{
printf("\nChoose one of the options: \n1. [Cost calculation] \n2. [Bill details] \n3. [Output]\nChoose: ");
scanf("%d", &query);
*pointquery=query; //converts values ​​to int main, x to query
if (query!=1 && query!=2 && query!=3) {
printf("Selection error, please select one of the options by typing the number.\n");
}
}while (query!=1 && query!=2 && query!=3);
}
/////////////////////
//A function that outputs/confirms the inserted selection.
void CheckQuery(int *selection){
printf("\n\nChosen options %d\n\n", *selection);

}
/////////////////////
//a function that performs a single n-selection operation,
//*pbill-points to the variable total=0 to save the bill after each new iteration of the main terminal Home, fieldz-empty field for the number of hours
void Operations(int n, float *firstbill, int fieldz){
    char device[20+1];
    float bill=*firstbill;
    int *pointmember=fieldz; //Initialization of a pointer pointing to the first member of the array z
    int i;
    char response;

//selection by which the calculation is performed
if (n==1){
    while(strcmp(device,"STOP")!=0){ //a loop that runs until the user enters STOP
          printf("\nEnter which device you used for each hour over the past 30 days. \n(OPTIONS: [Boiler] [Tv] [ZoomCall] [Lighting] [AC] [Calculator] [STOP]): ");
          scanf("%s", &device);

            if (strcmp(device, "STOP") == 0) { //checking the selection, the electricity bill is increased for each device and the number of repetitions is written in the field pointed to by the pointmember
                break;
            } else if (strcmp(device, "Tv") == 0) {
                bill += 0.46*0.041468;
                *(pointmember+0)=*(pointmember+0)+1;
            } else if (strcmp(device, "ZoomCall") == 0) {
                bill += 0.33*0.041468;
                *(pointmember+1)=*(pointmember+1)+1;
            } else if (strcmp(device, "Lighting") == 0) {
                bill += 0.7*0.041468;
                *(pointmember+2)=*(pointmember+2)+1;
            } else if (strcmp(device, "AC") == 0) {
                bill += 0.03*0.041468;
                *(pointmember+3)=*(pointmember+3)+1;
            } else if (strcmp(device, "Boiler") == 0) {
                bill += 0.28*0.041468;
                *(pointmember+4)=*(pointmember+4)+1;
            } else if (strcmp(device, "Calculator") == 0) {
                bill += 0.00025*0.041468;
                *(pointmember+5)=*(pointmember+5)+1;
            } else {
                printf("Wrong Insert, try again: ");
            }
        }
    printf("This month's electricity bill is %.6f euro. (Including tax: %.6f+0.3 euro)", bill+0.3, bill);
    *firstbill=bill; //A pointer used to pass the bill amount to the next function
    CreateBill(firstbill); //As soon as the calculation is performed, the function for inserting the bill and data into a text document is triggered.
    }

//A selection that prints specifications and a personalized calculation using a bill
if (n==2){
    printf("\n\n\n\n\n\n\n\n\n\n Regarding the tariff item for the supply of household customers within the public service system, applicable from 1 April 2023: ");
    printf("\nYour current plan is 'Red model' at price (EUR/kWh) including tax = 0.041468");
    printf("\nHere is the consumption of your devices over every 24-hour period: ");
    printf("\n8K UHD 100Hz TV___________11,04 kWh(0,46 kWh per hour");
    printf("\nZoom call_________8 kWh (0,33 kWh per hour)");
    printf("\nLighting__________________17 kWh (0,7 kWh per hour)");
    printf("\nAC_____________________0,8 kWh(0,03 per hour)");
    printf("\nBoiler____________________6,69 kWh (0,28 kWh per hour)");
    printf("\nCalculator________________0,006 kWh(0,00025 kWh per hour");
if(bill==0){ //The personalized calculation is not displayed if the user has not yet completed the calculation step.
    printf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
    printf("\n You have not yet charged the bill for this month, calculate the costs and try to request the bill details again.");
}
else{
    do{printf("\nWould you like an estimate for the devices you use? [y/n]:");
    scanf(" %c", &response);
    if(response=='y'){
            printf("\n\n\n\n\n\n\n}/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
    for(i=0;i<6;i++){  //The loop prints all z array elements by advancing the pointer representing the number of hours of use.
            if(*(pointmember+i)>0){
                if (i==0)printf("\nTv consumption: %d h (%d * 0,019075 = %f)", *(pointmember+i), *(pointmember+i), *(pointmember+i)*0.019075);
                else if(i==1)printf("\n Zoom consumption: %d h (%d * 0,013684 = %f)", *(pointmember+i), *(pointmember+i), *(pointmember+i)*0.013684);
                else if(i==2)printf("\nLighting %d h (%d * 0,0290276 = %f)", *(pointmember+i), *(pointmember+i), *(pointmember+i)*0.0290276);
                else if(i==3)printf("\nAC %d h (%d * 0,001244 = %f)", *(pointmember+i), *(pointmember+i), *(pointmember+i)*0.001244);
                else if(i==4)printf("\nBoiler %d h (%d * 0,01161 = %f)", *(pointmember+i), *(pointmember+i), *(pointmember+i)*0.01161);
                else if(i==5)printf("\nCalculator %d h (%d * 0,000010367 = %f)", *(pointmember+i), *(pointmember+i), *(pointmember+i)*0.000010367);
            }
    }
    printf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");}
    else if(response=='n')
        break;
    else printf("\nNo selection has been made; please make your selection again.");}while(response!='y' && response!='n'); //A do-while loop that repeats a y/n question until the user enters one of those two letters.
}}

//An option that indicates the program has been shut down and terminates the entire program
if (n==3){
printf("\nThe program has been successfully shut down!");
}
}
/////////////////////
//Bill generation function using a pointer to the bill calculated in the Operations function
void CreateBill(float *FinalBill){
    struct Person{
    char name[20+1];
    char lastname[20+1];
    char address[30+1];
        int streetnumber;
}data;
    do{
    printf("\nEnter name:");
    scanf("%s", data.name);
    printf("\nEnter lastname:");
    scanf("%s", data.lastname);
    printf("\nEnter address (Use '_' instead of a space.):");
    scanf("%s", data.address);
    printf("\nEnter street number:");
    scanf("%d", &data.streetnumber);
    if(strlen(data.name)>21 || strlen(data.name)<=0 || strlen(data.lastname)>21 || strlen(data.lastname)<=0 || strlen(data.address)>31 || strlen(data.address)<=0)//provjera duljine svakog podatka
        printf("Data entry error. Please re-enter the data.\n");
    }while(strlen(data.name)>21 || strlen(data.name)<=0 || strlen(data.lastname)>21 || strlen(data.lastname)<=0 || strlen(data.address)>31 || strlen(data.address)<=0);
FILE *Insert=fopen("Bills.txt","w"); //opening and loading data from structure Person into the text document Bills.txt
if (Insert==NULL){
    printf("Error in bill printing");
}
else{
fprintf(Insert,"______________________________________\n");
fprintf(Insert,"__HEP-TOPLINARSTVO____________________\n");
fprintf(Insert,"PLATITELJ:________________Payment currency:EUR_____Amount:%.6f euro\n", *FinalBill+0.3);
fprintf(Insert,"%s|___________________________________________\n", data.name);
fprintf(Insert,"%s|___________________________________________\n", data.lastname);
fprintf(Insert,"%s %d   |_____________________________________\n", data.address, data.streetnumber);
fprintf(Insert,"_______________________________________________\n");
fprintf(Insert,"_______________________________________________\n");
fprintf(Insert,"PRIMATELJ:             |_______________________\n");
fprintf(Insert,"HEP-TOPLINARSTVO d.o.o.|_______________________\n");
fprintf(Insert,"MIŠEVEČKA 15A          |_______________________\n");
fprintf(Insert,"10000 ZAGREB           |_______________________\n");
fprintf(Insert,"_______________________|_______________________\n");
fclose(Insert);
printf("\n The bill has been successfully printed; please check your data folder.");
}}
//////////////////
int main(){
    int x=0; //Storing the selected query (1 to 3).
    float total=0; //We store the account value and pass it to other functions.
int *PointQuery=&x;
float *bill=&total;
int z[6]={0};
do{
Home(PointQuery);
CheckQuery(PointQuery);
Operations(x, bill, z);
}while(x!=3);
return 0;}
