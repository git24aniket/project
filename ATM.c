//============================================================================
// Name        : ATM.c
// Author      : Kumar Aniket
// Version     : 1.0
// Description : ATM machine in c language
//============================================================================

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
void menu(void);
void change(void);
void login(void);
void initial(void);
void conti(void);
void check(void);
void withdraw(void);
void deposit(void);
void transfer(void);
void quit(void);
double bal= 40000.00;
char pwd1[4];

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	initial();
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void initial()
{
	int pin;
	system("cls");
printf("\n\n*******************************************Welcome to XYZ Bank*******************************************\n\n\n");
printf("Please enter your initial pin as 3210\nplease Enter your 4 digit pin: ");
scanf("%d", &pin);
if (pin==3210)
change();
else {
	printf("\nwrong password\nPlease try again\n");
initial();
}


//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------- 


}
void menu(){
	int choice;
	system("cls");
	printf ("\n\n*******************************************Welcome to XYZ Bank*******************************************\n\n\n");
	printf ("\n************************Menu Options************************");
	printf ("\n\n1. Check balance\n2. Withdraw\n3. Deposit\n4. Fund Transfer\n5. Exit");
	printf ("\nplease enter your selection: ");
	scanf("%d", &choice);
	
switch (choice) {
case 1:
	check();
	break;
case 2:
	withdraw();
	break;
case 3:
	deposit();
	break;
case 4:
	transfer();
	break;
case 5:
	quit();
	break;
default:
	printf("\ninvalid selection\nPlease try again\n");
	system("pause");
	menu();
}
}


//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void change()
{
	extern char pwd1[4];
char pwd2[4], ch1, ch2;
char pass[4]= "3210";
int i,j;
printf("\nplease Enter a new 4 digit password: ");
for(i=0;i<4;i++)
{
ch1=getch();
pwd1[i]=ch1;
ch1='*';
printf("%c",ch1);
}
if(strcmp(pwd1,pass)==0)
{system("cls");
printf("\n\n*******************************************Welcome to XYZ Bank*******************************************\n\n\n");
printf("Sorry! You can't choose your initial pin. Please try again\n");
system("pause");
initial();
}
else
{
printf("\nplease confirm your new 4 digit pin: ");
for(j=0;j<4;j++)
{
ch2=getch();
pwd2[j]=ch2;
ch2='*';
printf("%c",ch2);
}
}
if(strcmp(pwd1,pwd2)==0)
{
	printf("\ncongrats! Your pin was successfully changed\n");
	system("pause");
	login();
}
else
{
	printf("\nYour Pin did not match, Please try again\n");
	change();
}
}



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void login()
{ char pwd3[4], ch3;
int k;
	system("cls");
	printf("\nEnter your pin to log in to your account: ");
	for(k=0;k<4;k++)
{
ch3=getch();
pwd3[k]=ch3;
ch3='*';
printf("%c",ch3);
}
	if(strcmp(pwd1,pwd3)==0)
	{menu();
	}
	else
	{printf("\nWrong pin entered\n\nplease try again\n\n");
	system("pause");
	login();
	}
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void contin(){
int cont;
	printf("\nDo you wish to continue?\nEnter 1 for yes\nEnter 0 for no\nEnter Here: ");
	scanf("%d",&cont);
	system("cls");
	if(cont==0)
	{ 
		quit();
	}
	else if(cont==1)
	{
		menu();
	}
	else
	{printf("\nWrong selection entered please try again...\n");
	system("pause");
	system("cls");	
	contin();
	}
}



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void check()
{extern double bal;
printf("\nyour current balance is INR %lf",bal);
contin();
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void withdraw()
{	extern double bal;
	double wd, lim1= 50000.00;
	printf("\nPlease Enter the amount (Max limit: INR 50,000 per transaction): ");
	scanf("%lf", &wd);
	if(wd>lim1)
	{
		printf("\nMax limit exceeded\n please try again\n");
		system("pause");
		menu();
	}
	else if(wd>bal)
	{
		printf("\ninsufficient balance in your account\n please try again\n");
		system("pause");
		menu();
	}
	if(wd<bal)
	{
		bal=bal-wd;
		printf("\n***your transaction was successful***\n your current balance is INR %lf", bal);
		contin();
	}
}



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void deposit()
{
	extern double bal;
	double cr, lim2=50000.00;
	printf("\nPlease Enter the amount (Max limit: INR 50,000 per transaction): ");
	scanf("%lf", &cr);
	if(cr>lim2)
	{
		printf("\nMax limit exceeded\n please try again\n");
		system("pause");
		menu();
	}
	else
	{
		bal=bal+cr;
		printf("\n***your transaction was successful***\n your current balance is INR %lf", bal);
		contin();
	}
}



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void transfer()
{	extern double bal;
	double tr, lim3= 50000;
	printf("\nPlease Enter the amount (Max limit: INR 50,000 per transaction): ");
	scanf("%lf", &tr);
	if(tr>lim3)
	{
		printf("\nMax limit exceeded\n please try again\n");
		system("pause");
		menu();
	}
	if(tr>bal)
	{
		printf("\ninsufficient balance in your account\n please try again\n");
		system("pause");
		menu();
	}
	if(tr<bal)
	{
		bal=bal-tr;
		printf("\n***your transaction was successful***\n your current balance is INR %lf", bal);
		contin();
	}
}



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void quit()
{	extern double bal;
    bal=40000;
	printf("\nThank You! for banking with us\n");
	system("pause");
	system("cls");
	initial();
}
