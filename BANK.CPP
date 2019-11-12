// BANK MANAGEMENT SYSTEM
#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>

class bank   // bank class start
{
private:   // private access modifier
char uname[30],upass[10],name[50][50],city[50][50];
char mob[50][50],uid[50][50],atm[50][10],inb[50][10];
char chqbook[50][10];
int i,c,acno[50],find;
long accamt[50];
public:  // public access modifier
bank()    // bank class constructor
{
c=0;
accamt[50]=0;
strcpy(atm[50],"No");
strcpy(inb[50],"No");
strcpy(chqbook[50],"No");
}
void writings(); void userinput(); void usercheck();
void passinput(); void passcheck(); void loading();
void mainmenu(); void create(); void displays();
void deposit(); void withdrawl(); void status();
void services(); void servicestatus(); void modify();
void close(); void methodend(); void datetime();
int accountcheck(int);
}fp1;     // fp1 is the bank class object

void bank :: mainmenu()   // function contains menus
{                       // and calls to other functions
textcolor(15);     // for color of the text , 15 = white
label_3:      // defining label_3
while(1)       // while loop
{
clrscr();      // for screen clear
cout<<" ";
cout<<" ";
cout<<"\n\n\t\t\t  GS BANK MANAGEMENT SYSTEM ";
cout<<"\n\n\n\t\t 1. CREATE NEW ACCOUNT ";
cout<<"\n\t\t 2. CASH DEPOSIT ";
cout<<"\n\t\t 3. CASH WITHDRAWL ";
cout<<"\n\t\t 4. ACCOUNT STATUS ";
cout<<"\n\t\t 5. DISPLAY LIST OF ALL ACCOUNTS";
cout<<"\n\t\t 6. SERVICES (ATM,CHEQUE BOOK,INB etc) ";
cout<<"\n\t\t 7. MODIFY ACCOUNT ";
cout<<"\n\t\t 8. CLOSING ACCOUNT ";
cout<<"\n\t\t 9. EXIT ";
printf("\n\n\t\t ENTER YOUR CHOICE : ");
int chc;
cin>>chc;
	switch(chc)     // switch case construct
	{
		case 1:
		fp1.create();
		break;
		case 2:
		fp1.deposit();
		break;
		case 3:
		fp1.withdrawl();
		break;
		case 4:
		fp1.status();
		break;
		case 5:
		fp1.displays();
		break;
		case 6:
		fp1.services();
		break;
		case 7:
		fp1.modify();
		break;
		case 8:
		fp1.close();
		break;
		case 9:
		exit(0);
		break;
		default:
		gotoxy(35,18);
		cout<<"\n Invalid Choice ! ";
		goto label_3;   // jump to label_3
	}
   }
}

void bank :: userinput()   // takes username input from user
{
clrscr();
textcolor(15);      // for color of the text
gotoxy(26,10);              // move to the position (x,y)
cprintf("\n USERNAME : "); // output text with textcolor at given position
gets(uname);     // string input
}

void bank :: usercheck()  // username authentication
{
textcolor(15);         // color of the text
delay(400);               // wait for some time in miliseconds
	if(strcmp("gursewak",uname)==0)  // strcmp for string comparing
	{
	textcolor(15);   // color of the text
	gotoxy(38,13);           // move to (x,y)
	cprintf("\n VALID ! ");
	}
	else
	{
	textcolor(15);   // color of text
	gotoxy(37,13);       // move to (x,y)
	cprintf("\n INVALID ! ");
label_1:       // defining label_1
	delay(500);   // wait for some time in miliseconds
	clrscr();          // screen clear
	textcolor(15);   // color of text
	gotoxy(23,8);        // move to (x,y)
	cprintf("\n 1. ENTER AGAIN ");
	gotoxy(23,9);     // move to (x,y)
	cprintf("\n 2. EXIT ");
	gotoxy(23,10);    // move to (x,y)
	cprintf("\n ENTER YOUR CHOICE :  ");
	int cho;
	cin>>cho;
	switch(cho)  // switch case
	{
	case 1:
	clrscr();      // screen clear
	fp1.userinput();      // call to function userinput()
	fp1.usercheck();    // function call
	break;
	case 2:
	exit(0);          // normal termination
	break;
	default:
	cout<<"\n Invalid Choice ! ";
	goto label_1;  // jump to label_1
	}
	}
}

void bank :: passinput()   // password input
{
clrscr();
textcolor(15);
gotoxy(26,10);
cprintf("\n PASSWORD : ");
int i;
for(i=0; i<7; i++)
{
upass[i]=getch();
cout<<"*";
}
upass[i]='\0';
}

void bank :: passcheck()   // password authentication
{
textcolor(15);
delay(600);
	if(strcmp("project",upass)==0)
	{
	textcolor(15);
	gotoxy(38,13);
	cprintf("\n VALID PASSWORD ! ");
	}
	else
	{
	textcolor(15);
	gotoxy(37,13);
	cprintf("\n INVALID PASSWORD ! ");
label_2:    // defining label_2
	delay(500);
	clrscr();
	textcolor(15);   // white color
	gotoxy(23,8);
	cprintf("\n 1. ENTER AGAIN ");
	gotoxy(23,9);
	cprintf("\n 2. EXIT ");
	gotoxy(23,10);
	cprintf("\n ENTER YOUR CHOICE :  ");
	int cho;
	cin>>cho;
	switch(cho)
	{
	case 1:
	clrscr();
	fp1.passinput();
	fp1.passcheck();
	break;
	case 2:
	exit(0);
	break;
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	goto label_2;  // jump to label_2
	}
	}
}

void bank :: loading()   // for designing purpose
{
clrscr();
int i;
textcolor(15);
gotoxy(4,8);
cprintf("\n LOADING.... ");
	for(i=1; i<=40; i++)    // for loop
	{
	textcolor(12);
	gotoxy(i+4,10);
	cprintf("#");
	gotoxy(46,10);
	cprintf("%0.2f %%",i*2.5);
	delay(100);
	}
	delay(200);
	textcolor(4);
	gotoxy(40,14);
	cprintf("Completed !");
}

void bank :: datetime()  // current date and time
{
struct date d;     // predefined structure date
getdate(&d);       // for system date
printf("\n DATE : %d-%d-%d",d.da_day,d.da_mon,d.da_year);
struct time t;     // predefined structure time
gettime(&t);       // for system time
printf("\t\t\t\t\t\tTIME - %d:%d:%d",t.ti_hour,t.ti_min,t.ti_sec);
}
void bank :: create()    // create an account
{
textcolor(15);
clrscr();
datetime();     // function call
cout<<"\n\n\t\t\t  CREATE AN ACCOUNT ";
cout<<"\n\n";
cout<<"\n\n\t\t Name  : ";
gets(name[c]);
cout<<"\n\n\t\t City  : ";
gets(city[c]);
cout<<"\n\n\t\t Mob.No: ";
gets(mob[c]);
cout<<"\n\n\t\t UID No: ";
gets(uid[c]);
fp1.loading();    // function call
textcolor(15);
gotoxy(25,15);
cprintf("\n Account Created Successfully ! ");
acno[c]=661+c;
textcolor(15);
cout<<"\n\n\t\t\t Your Account Number is : "<<acno[c];
c++;
methodend();
}

void bank :: displays()   // display the list of all accounts
{
textcolor(15);
clrscr();
cout<<"\n\n\t\t\t  LIST OF ALL ACCOUNTS \n\n";
cout<<"\n ACC NO     NAME  ";
cout<<"\n ------     ----- ";
int n=c;
	for(i=0; i<n; i++)     // for loop
	{
		if(acno[i]==0)
		continue;
	printf("\n %d        %s",acno[i],name[i]);
	}
methodend();   // function call
}

int bank :: accountcheck(int x)  // check account availability
{
int flag=-1;
	for(i=0; i<c; i++)
	{
	     if(x==acno[i])
	     {
	     find=i;
	     flag=1;
	     }
	}
return flag;
}

void bank :: deposit()   // cash deposit
{
clrscr();
int an,flag;
datetime();         // function call
cout<<"\n\n\t\t\t  CASH DEPOSIT \n\n";
cout<<"\n\n\t\t Enter Account No.  : ";
cin>>an;
flag=fp1.accountcheck(an);
	if(flag==-1)
	{
	cout<<"\n\t\t\t Account not found ! ";
	delay(2000);
label_4:  // defining label_4
	clrscr();
	textcolor(15);   // white color
	gotoxy(23,8);
	cprintf("\n 1. TRY AGAIN ");
	gotoxy(23,9);
	cprintf("\n 2. EXIT ");
	gotoxy(23,10);
	cprintf("\n ENTER YOUR CHOICE :  ");
	int cho;
	cin>>cho;
	switch(cho)  // switch case
	{
	case 1:
	clrscr();        // screen clear
	fp1.deposit();
	break;
	case 2:
	return;
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	goto label_4;  // jump to label_4
	}
	}
	cout<<"\n\n\t\t Current Balance : "<<accamt[find];
	cout<<"\n\n\t\t Enter Amount to deposit : ";
	long amt;
	cin>>amt;
	accamt[find]=accamt[find]+amt;
	fp1.loading();
	textcolor(15);
	gotoxy(25,15);
	cprintf("\n Amount Deposited Successfully ! ");
	textcolor(15);
	cout<<"\n\n\t\t\t Balance is : "<<accamt[find];
	methodend();
}

void bank :: withdrawl()  // cash withdrawl
{
clrscr();
int an,flag;
datetime();          // function call
cout<<"\n\n\t\t\t  CASH WITHDRAW \n\n";
cout<<"\n\n\t\t Enter Account No.  : ";
cin>>an;
flag=fp1.accountcheck(an);
	if(flag==-1)
	{
	cout<<"\n\t\t\t Account not found ! ";
	delay(2000);
label_5: // defining label_5
	clrscr();
	textcolor(15);   // white color
	gotoxy(23,8);   // move to (x,y)
	cprintf("\n 1. TRY AGAIN ");
	gotoxy(23,9);
	cprintf("\n 2. EXIT ");
	gotoxy(23,10);
	cprintf("\n ENTER YOUR CHOICE :  ");
	int cho;
	cin>>cho;
	switch(cho)
	{
	case 1:
	clrscr();
	fp1.withdrawl();
	break;
	case 2:
	return;
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	goto label_5;  // jump to label_5
	}
	}
	cout<<"\n\n\t\t Current Balance : "<<accamt[find];
	cout<<"\n\n\t\t Enter Amount to Withdraw : ";
	long amt;
	cin>>amt;
	accamt[find]=accamt[find]-amt;
	fp1.loading();
	textcolor(15);
	gotoxy(25,15);
	cprintf("\n Amount withdraw Successfully ! ");
	textcolor(15);
	cout<<"\n\n\t\t\t Balance is : "<<accamt[find];
	methodend();
}

void bank :: status()  // account status
{
clrscr();
int an,flag;
datetime();  // function call
cout<<"\n\n\t\t\t  ACCOUNTS STATUS \n\n";
cout<<"\n\n\t\t Enter Account No.  : ";
cin>>an;
flag=fp1.accountcheck(an);
	if(flag==-1)
	{
	cout<<"\n\t\t\t Account not found ! ";
	delay(2000);   // wait for 2 seconds
label_6:  // defining label_6
	clrscr();
	textcolor(15);   // white color
	gotoxy(23,8);
	cprintf("\n 1. TRY AGAIN ");
	gotoxy(23,9);
	cprintf("\n 2. EXIT ");
	gotoxy(23,10);
	cprintf("\n ENTER YOUR CHOICE :  ");
	int cho;
	cin>>cho;
	switch(cho)
	{
	case 1:
	clrscr();
	fp1.status();
	break;
	case 2:
	return;
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	goto label_6;  // jump to label_3
	}
	}
	cout<<"\n\n\t\t\t\t ACCOUNT STATUS ";
	cout<<"\n\n\n\t\t A/C No. :  "<<acno[find];
	cout<<"\n\t\t NAME    :  "<<name[find];
	cout<<"\n\t\t CITY    :  "<<city[find];
	cout<<"\n\t\t MOB.    :  "<<mob[find];
	cout<<"\n\t\t UID.    :  "<<uid[find];
	cout<<"\n\t\t BALANCE :  "<<accamt[find];
	methodend();
}

void bank :: services()  // additional services
{
clrscr();
int an,flag,chc;
datetime();       // function call
cout<<"\n\n\t\t\t  ADDITIONAL SERVICES \n\n";
cout<<"\n\n\t\t Enter Account No.  : ";
cin>>an;
flag=fp1.accountcheck(an);
	if(flag==-1)
	{
	cout<<"\n\t\t\t Account not found ! ";
	delay(2000);
	clrscr();
	textcolor(15);   // white color
	gotoxy(23,8);
	cprintf("\n 1. TRY AGAIN ");
	gotoxy(23,9);
	cprintf("\n 2. EXIT ");
	gotoxy(23,10);
	cprintf("\n ENTER YOUR CHOICE :  ");
	int cho;
	cin>>cho;
	switch(cho)  // switch case
	{
	case 1:
	clrscr();
	fp1.services();
	break;
	case 2:
	return;
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	}
	}
label_12:   // defining label_12
	clrscr();
	cout<<"\n\n\t\t\t\t SERVICES ";
	cout<<"\n\n\n\t\t 1. ADD SERVICES ";
	cout<<"\n\t\t 2. REMOVE SERVICES ";
	cout<<"\n\t\t 3. ACCOUNT's SERVICE STATUS ";
	cout<<"\n\t\t 4. Exit ";
	cout<<"\n\t\t Enter Your Choice : ";
	cin>>chc;
	switch(chc)
	{
	case 1:
label_13:     // defining label_13
	clrscr();
	cout<<"\n\n\t\t\t\t ADD SERVICES ";
	cout<<"\n\n\n\t\t 1. ATM ";
	cout<<"\n\t\t 2. CHEQUE BOOK ";
	cout<<"\n\t\t 3. INTERNET BANKING ";
	cout<<"\n\t\t 4. EXIT ";
	cout<<"\n\t\t Enter Your Choice : ";
	int chc1;
	cin>>chc1;
	switch(chc1)
	{
	case 1:
	cout<<"\n\n\n\t\t ATM Service is Added !";
	strcpy(atm[find],"Yes");
	break;
	case 2:
	cout<<"\n\n\n\t\t CHEQUE BOOK Service is Added !";
	strcpy(chqbook[find],"Yes");
	break;
	case 3:
	cout<<"\n\n\n\t\t INTERNET BANKING Service is Added !";
	strcpy(inb[find],"Yes");
	break;
	case 4:
	goto label_12; // jump to label_12
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	goto label_13;   // jump to label_13
	}
	methodend();
	goto label_12;    // jump to label_12
	case 2:
label_14:  // defining label_14
	clrscr();
	cout<<"\n\n\t\t\t\t REMOVE SERVICES ";
	cout<<"\n\n\n\t\t 1. ATM ";
	cout<<"\n\t\t 2. CHEQUE BOOK ";
	cout<<"\n\t\t 3. INTERNET BANKING ";
	cout<<"\n\t\t 4. EXIT ";
	cout<<"\n\t\t Enter Your Choice : ";
	int chc2;
	cin>>chc2;
	switch(chc2)
	{
	case 1:
	cout<<"\n\n\n\t\t ATM Service is Removed !";
	strcpy(atm[find],"No");
	break;
	case 2:
	cout<<"\n\n\n\t\t CHEQUE BOOK Service is Removed !";
	strcpy(chqbook[find],"No");
	break;
	case 3:
	cout<<"\n\n\n\t\t INTERNET BANKING Service is Removed !";
	strcpy(inb[find],"No");
	break;
	case 4:
	goto label_12; // jump to label_12
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	goto label_14; // jump to label_14
	}
	methodend();
	goto label_12;   // jump to label_12
	case 3:
	cout<<"\n\n\t\t\t\t SERVICE STATUS OF ACCOUNT";
	cout<<"\n\n\n\t\t A/C No. :  "<<acno[find];
	cout<<"\n\t\t ATM             :  "<<atm[find];
	cout<<"\n\t\t CHEQUE BOOK     :  "<<chqbook[find];
	cout<<"\n\t\t INTERNET BANKING:  "<<inb[find];
	methodend();
	goto label_12;    // jump to label_12
	case 4:
	return;
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	goto label_12;    // jump to label_12
	}
}

void bank :: modify() // account modifications
{
clrscr();
char etc[50];
int an,flag;
datetime();  // function call
cout<<"\n\n\t\t\t  MODIFY AN ACCOUNT \n\n";
cout<<"\n\n\t\t Enter Account No.  : ";
cin>>an;
flag=fp1.accountcheck(an);
	if(flag==-1)
	{
	cout<<"\n\t\t\t Account not found ! ";
	delay(2000);
label_8:  // defining label_8
	clrscr();
	textcolor(15);   // white color
	gotoxy(23,8);
	cprintf("\n 1. TRY AGAIN ");
	gotoxy(23,9);
	cprintf("\n 2. EXIT ");
	gotoxy(23,10);
	cprintf("\n ENTER YOUR CHOICE :  ");
	int cho;
	cin>>cho;
	switch(cho)
	{
	case 1:
	clrscr();
	fp1.modify();
	break;
	case 2:
	return;
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	goto label_8;  // jump to label_8
	}
	}
label_9: // defining label_9
	clrscr();
	cout<<"\n\n\t\t\t\t MODIFY OPTION ";
	cout<<"\n\n\n\t\t 1. A/C No.  ";
	cout<<"\n\t\t 2. NAME    ";
	cout<<"\n\t\t 3. CITY    ";
	cout<<"\n\t\t 4. MOB.    ";
	cout<<"\n\t\t 5. UID.    ";
	cout<<"\n\t\t Enter Your Choice : ";
	int cho2;
	cin>>cho2;
	switch(cho2)
	{
	case 1:
	cout<<"\n\n\t\t\t\t MODIFICATION ";
	cout<<"\n\n\n\t\t Enter New A/C No. :  ";
	int temp;
	cin>>temp;
	acno[find]=temp;
	break;
	case 2:
	cout<<"\n\n\t\t\t\t MODIFICATION ";
	cout<<"\n\n\n\t\t Enter new NAME    :  ";
	etc[50];
	gets(etc);
	strcpy(name[find],etc);
	break;
	case 3:
	cout<<"\n\n\t\t\t\t MODIFICATION ";
	cout<<"\n\n\n\t\t Enter new CITY    :  ";
	etc[50];
	gets(etc);
	strcpy(city[find],etc);
	break;
	case 4:
	cout<<"\n\n\t\t\t\t MODIFICATION ";
	cout<<"\n\n\n\t\t Enter new MOB.    :  ";
	etc[50];
	gets(etc);
	strcpy(mob[find],etc);
	break;
	case 5:
	cout<<"\n\n\t\t\t\t MODIFICATION ";
	cout<<"\n\n\n\t\t Enter new UID.    :  ";
	char etc[50];
	gets(etc);
	strcpy(uid[find],etc);
	break;
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	goto label_9;  // jump to label_9
	}
	clrscr();
	fp1.loading();
	textcolor(15);
	gotoxy(25,15);
	cprintf("\n Account Modified Successfully ! ");
	textcolor(15);
	cout<<"\n\n\t\t\t Check Account Status for effect ";
	methodend();
}

void bank :: close()  // closing an account
{
clrscr();
int an,flag;
datetime();
cout<<"\n\n\t\t\t  CLOSING AN ACCOUNT \n\n";
cout<<"\n\n\t\t Enter Account No.  : ";
cin>>an;
flag=fp1.accountcheck(an);
	if(flag==-1)
	{
	cout<<"\n\t\t\t Account not found ! ";
	delay(2000);
label_7:    // defining label_7
	clrscr();
	textcolor(15);   // white color
	gotoxy(23,8);
	cprintf("\n 1. TRY AGAIN ");
	gotoxy(23,9);
	cprintf("\n 2. EXIT ");
	gotoxy(23,10);
	cprintf("\n ENTER YOUR CHOICE :  ");
	int cho;
	cin>>cho;
	switch(cho)   // switch case
	{
	case 1:
	clrscr();
	fp1.close();
	break;
	case 2:
	return;
	default:
	gotoxy(35,18);
	cprintf("\n Invalid Choice ! ");
	goto label_7;  // jump to label_7
	}
	}
	acno[find]=0;
	strcpy(name[find],"000");
	strcpy(city[find],"000");
	strcpy(mob[find],"000");
	strcpy(uid[find],"000");
	accamt[find]=0;
	cout<<"\n\n\t\t\t\t ACCOUNT CLOSED ! ";
	methodend();
}

void bank :: methodend()  // for pause till any key be press on keyboard
{
textcolor(15);
gotoxy(25,20);
cprintf("\n ENTER ANY KEY FOR MAIN MENU ! ");
getch();
}

void bank::writings()    // title screen of the project
{
	    delay(500);
	    textcolor(12);
	    gotoxy(36,4);
	    cprintf("PROJECT");
	    delay(500);
	    textcolor(12);
	    gotoxy(38,6);
	    cprintf("ON");
	    delay(500);
	    textcolor(12);
	    gotoxy(28,8);
	    cprintf("BANK MANAGEMENT SYSTEM");
	    delay(500);
	    textcolor(9);
	    gotoxy(25,12);
	    cprintf("SUB. TO :-");
	    textcolor(14);
	    cprintf("  PROF. GURPREET SINGH GHALI");
	    delay(500);
	    textcolor(9);
	    gotoxy(25,14);
	    cprintf("SUB. BY :-");
	    textcolor(14);
	    cprintf("  GURSEWAK SINGH");
	    textcolor(5);
	    gotoxy(27,19);
	    cprintf("PRESS ANY KEY TO CONTINUE...");
	    getch();
}

void main()   // main() function start
{
clrscr();           //  screen clear
fp1.writings();      // call to writings()
fp1.userinput();     // call to userinput()
fp1.usercheck();     // call to usercheck()
fp1.passinput();     // call to passinput()
fp1.passcheck();     // call to passcheck()
fp1.loading();       // call to loading()
fp1.mainmenu();      // call to mainmenu()
getch();          // wait till any key be press from keyboard
}