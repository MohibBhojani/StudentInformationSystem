#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
//--------------------------------------
//---------Functions Declaration--------
//--------------------------------------
void add(void);
void search(void);
void del(void);
void list(void);
//-----------------Structure Declaration--------
struct
{
    char uni[20];
    char dis[20];
    char rno[20];
    char name[20];
    char loc[100];
    char num[20];
    char gpa[20];
}student;
//------------------Declaration Of Global Variables-------
char ca,l[10],p[4],stdnum[10];
int choice,shift,found,length,tc,bc,ps;
FILE *fp;
//-------------Starting Of Main Function------------------
void main(void)
{
clrscr();
textcolor(0);
textbackground(15);
clrscr();
char inf[400]={"\n\n\n\t\t\t\t\b\b\b!! CPPS PROJECT !!\n\n\t\t\t\tGROUP MEMBERS\n\n\t\t\Nawazish Rabbani\t\tMusadiq Chohan\n\t\t2014-CE-015\t\t\t2014-CE-014\n\n\n\n\t\tDawood Shamim\t\t\tAbdul Muhib\n\t\t2014-CE-002\t\t\t2014-CE-040\n\n\t\t\t\tSubmitted To:\n\t\t\t1.Sir Muzzammil Ahmed Khan.\n\t\t\t2.Miss Zainab Zakir.\n\t\t\t3.Sir Masood.\n\n\n\t\t\t\t\t\tCreated By:\n\t\t\t\t\t\t\"DAMN CREATORS\"\n\t\t\tPress Enter To Continue..........."};
for(int y=0;y<strlen(inf);y++)
{
printf("%c",inf[y]);
delay(50);}
getch();
clrscr();
//-----------------------PROGRAM PASSWORD---------------
printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\tUSER LOGIN:");
fflush(stdin);
gets(l);
printf("\n\n\t\t\t\tPASSWORD:");
ps=0;
while(ps<5)
{
p[ps]=getch();
if(p[ps]=='\r')break;
ps++;
printf("*");
}

if(strcmp(p,"DAMN\r")==0)
	{
clrscr();
   L1:
   for(int a=0;a<80;a++)
{
printf("%c",30);
delay(10);
}
for(int b=0;b<1;b++)
{
printf("\n\n\t\t\t%7c CPPS PROJECT %c\n\n",6,6);
delay(10);
}
for(int c=0;c<80;c++)
{
printf("%c",30);
delay(10);
}
	printf("\n\n\t\t\t%c STUDENT INFORMATION SYSTEM %c",6,6);
	printf("\n\n\t\t\t 1) Add Student data \n\n\t\t\t 2) Search Student Data \n\n\t\t\t 3) Remove Student Data \n\n\t\t\t 4) Complete List \n\n\t\t\t 5) Quit ");
	printf("\n\n\t\t\t Select Option : ");

      scanf("%d",&choice);
      switch(choice)
      {
       //------------------For Adding Data--------------------
       case  1:
       L2:
       add();
       L:
       printf("\nA student information has been added successfully...\n");
       printf("\n\n1 -> Wish to add another record to database");
       printf("\n2 -> Wish to move to Main Menu");
       printf("\n3 -> Exit from Program\n");
       scanf("%d",&shift);
       if(shift==1){clrscr();
	goto L2;        }
       if(shift==2){clrscr();
	goto L1;        }
       if(shift==3)
	break;
       if(shift!=1&&2&&3){
	printf("\nEnter a valid choice");
	goto L;
	}
       //--------------------------For Searching Data----------------------
       case 2:
       L4:
       search();
       L5:
       printf("\n\n1 -> Search another information");
       printf("\n2 -> Go back to Main Menu");
       printf("\n3 -> Exit ");
       printf("\n\n Select Option : ");
	scanf("%d",&shift);
       if(shift==1)
       {clrscr();
	goto L4;}
       if(shift==2)
       {clrscr();
	goto L1;}
       if(shift==3)
	exit(1);
       if(shift!=1&&2&&3){
	printf("\nEnter a valid choice");
	goto L5;
	}
       case 3:
       L6:
       //-------------------For Removing Data------------------
       del();
       L7:
       printf("\n\n1 -> Remove another Record?..");
       printf("\n2 -> Go back to Main Menu");
       printf("\n3 -> Exit from Program\n");
       printf("\n\n Select Option : ");
       scanf("%d",&shift);
       if(shift==1){
       clrscr();
	goto L6;}
       if(shift==2){
	clrscr();
	goto L1;}
	if(shift==3)
	exit(1);
	if(shift!=1&&2&&3){
	printf("\n\nEnter a valid choice");
	goto L7;
	}
       case 4:
	list();
	printf("\npress Enter To go back to menu .........");
	getch();
	clrscr();
	goto L1;
	break;
       case 5:
       exit(1);
       break;
       default :
	  printf(" Bad choice...Enter the choice again...\n");
	  goto L1;
	}
	getch();
	}
	else
	{
	clrscr();
	printf("\n\n\n\n\n\n\n\n\n\t\t! WRONG  PASSWORD !\n\n\n\n\n\t\t\t\tExiting Program........... ");
	delay(1500);
	exit(1);
	}
//-------------------------------------------
//-------------Function Definitions----------
//-------------------------------------------
}
void add(void)
{
clrscr();
       printf("\t\t\t %c ADD STUDENT DATA %c\n\n",6,6);
       printf("\n\nEnter University Name:");
       fflush(stdin);
       gets(student.uni);
       printf("\nEnter Discipline:");
       gets(student.dis);
       printf("\nRoll number: ");
       gets(student.rno);
       printf("\nName:");
       gets(student.name);
       printf("\nPresent Address:");
       gets(student.loc);
       printf("\nCell Number:");
       gets(student.num);
       printf("\nGpa(Max 4) : ");
       gets(student.gpa);
       fp=fopen("sis.txt","a+");
       fwrite(&student,sizeof(student),1,fp);
       fclose(fp);
}
void search(void)
{
clrscr();
       printf("\nEnter the rollnumber: ");
       fflush(stdin);
       gets(stdnum);
       printf("Searching record with rollnumber=%s.\n",stdnum);
	   if((fp=fopen("sis.txt","r"))==NULL)
	{
	    printf(" ! The File\"sis.txt\" not Found \n\n");
	}
	else
	{  found=0;
	    while(!feof(fp))
		{

		fread(&student,sizeof(student),1,fp);
		if(strcmp(student.rno,stdnum)==0)
		   { found=1;
		     printf("\nThe record is found.");
		     printf("\nUniversity:%s\nDiscipline:%s\nRoll Num:%s\nName:%s\nAddress:%s\nCell Num:%s\nGPA:%s\n",student.uni,student.dis,student.rno,student.name,student.loc,student.num,student.gpa);
		     }
		}
		if(found==0)
		printf("\n\n\tNOT FOUND ! !");
	}

}
void del(void)
{
	clrscr();
	printf("\nEnter the Roll Num to delete Data : ");
	fflush(stdin);
	gets(stdnum);

   FILE *ft;
   fp=fopen("sis.txt","r");
   ft=fopen("temp.txt","w");
   rewind(fp);
   while(fread(&student,sizeof(student),1,fp)==1)
   {
      {
      if (strcmp(student.rno,stdnum)==0)
      { printf("\n\nDeleting Record containing Roll num :%s ",stdnum); }
      }
   if (strcmp(student.rno,stdnum)!=0)
     {
      fwrite(&student,sizeof(student),1,ft);
     }
   }
   fclose(fp);
   fclose(ft);
   printf("\n\n\t\"Record Deleted....!!!\"");
   remove("sis.txt");
   rename("temp.txt","sis.txt");
}
void list(void)
{
clrscr();

	printf("\t\t\t %c Complete List %c\n\n",6,6);
	fp=fopen("sis.txt","r");
	while( fread(&student,sizeof(student),1,fp)==1 )
	printf("\nUniversity:%s\nDiscipline:%s\nRoll Num:%s\nName:%s\nAddress:%s\nCell Number:%s\nGPA:%s\n",student.uni,student.dis,student.rno,student.name,student.loc,student.num,student.gpa);
	fclose(fp);
}

