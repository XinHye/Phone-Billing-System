#include <stdio.h>
#include <stdlib.h> 
#include <conio.h> 
#include <windows.h> 
#include <ctype.h> 

struct customer { 
 char name[50]; 
 char ic[15]; 
 char phonenum[20]; 
 char address[50]; 
} c; 
 
void addcusinf(); 
void listcusinf(); 
void cuspay(); 
 
 
int main() { 
  
 system("cls"); 
 printf("\n\n\n\n\t\t\t\t****************************************************************"); 
 printf("\n\n\t\t\t\t--------------Welcome to the Phone Billing System!--------------"); 
    printf("\n\n\t\t\t\t****************************************************************"); 
    printf("\n\n\n\n\t\t\t\tPress any key to continue..."); 
     
    getch(); 
    system ("cls"); 
     
    char choice; 
    while (1) { 
        system("cls"); 
        printf("Please enter your choice---->\n\n"); 
        printf("\t\t\t\t************************************\n"); 
        printf("\t\t\t\t# A # Add new customer information #\n"); 
        printf("\t\t\t\t************************************\n"); 
        printf("\t\t\t\t# B # List of customer information #\n"); 
        printf("\t\t\t\t************************************\n"); 
        printf("\t\t\t\t# C # Bill payment of one customer #\n"); 
        printf("\t\t\t\t************************************\n"); 
        printf("\t\t\t\t# D # Exit                         #\n"); 
        printf("\t\t\t\t************************************\n"); 
        printf("\nYour choice: "); 
        choice = getche(); 
        choice = toupper(choice); 
     switch (choice) { 
            case 'A': 
                addcusinf(); 
                break; 
 
            case 'B': 
                listcusinf(); 
                break; 
 
            case 'C': 
                cuspay(); 
                break; 
             
       
            /*When the user want to exit the system*/ 
            case 'D': 
                system("cls"); 
                printf("Thank you for using our service!"); 
                exit (0); 
                break; 
 
            /*When the user does not give a correct input for the system*/ 
            default: 
                system ("cls"); 
                printf ("Incorrect input\nPress any key to continue"); 
                getch(); 
   } 
  } 
} 
 
void addcusinf() { 
  
 FILE *f; 
 char test; 
  
 f = fopen ("services.txt", "ab+"); 
 if (f == NULL) { 
  f = fopen("services.txt", "wb+"); 
  system("cls"); 
  printf("Press any key to continue..."); 
  getch(); 
 } 
 while (1) { 
  system("cls"); 
  sleep(1); 
  printf ("Enter your full name: "); 
  fflush(stdin); 
  scanf ("%[^\n]%*c", &c.name); 
   
  printf ("Enter your I.C: "); 
  scanf ("%s", &c.ic); 
   
  printf ("Enter your address: "); 
  fflush(stdin); 
  scanf ("%[^\n]%*c", &c.address); 
   
  printf ("Enter your phone number: "); 
  scanf ("%s", &c.phonenum); 
   
  fwrite(&c, sizeof(c), 1, f); 
  fflush (stdin); 
   
  printf("\n\nRecord is SUCCESSFULLY added"); 
  printf("\nPress 'esc' key to exit or Press any other key to add other record"); 
   
  test = getche(); 
  if (test == 27) 
   break; 
 } 
 fclose(f); 
 system("cls"); 
} 
 
void listcusinf() { 
 int i; 
  
 FILE *f; 
  
 if((f = fopen("services.txt", "rb")) == NULL)  
  exit(0); 
 system("cls"); 
  
 printf ("List of Customer Information\n"); 
   
 while (fread(&c, sizeof(c), 1, f) == 1){ 
   
  printf("\n"); 
   
  for(i = 0; i < 79;i++) 
   printf("-"); 
  printf("\n"); 
  printf("Name         : %s\nI.C          : %s\nAddress      : %s\nPhone number : %s\n", c.name, c.ic, c.address, c.phonenum); 
  } 
  for(i = 0; i < 79;i++) 
   printf("-"); 
   
 fclose(f); 
 printf("\n\nPress Any Key To Go Back"); 
 getch(); 
 system("cls"); 
} 
 
void cuspay() { 
  
 FILE *f; 
 char name[20]; 
 int internet; // choose 1g/4g internet package 
 int numop; 
 int typop; // types of operator called 
 int chop;  
 int time; //24 hours 
 float duration; //minutes of the calls 
 int sms; 
 float scall, ssms, dcall, dsms, tscall, tssms, tdcall, tdsms, tcharge, rental, amount, servicestax, tax, package; 
 int i; 
  
 int find = 1; 
 f = fopen("services.txt","rb+");
 fflush(stdin); 
 system("cls"); 
 printf("Please enter the existed user name: "); 
 scanf("%[^\n]%*c", &name); 
 printf("\n\n\n"); 
 while(fread(&c, sizeof(c), 1, f) == 1) { 
   
  if (strcmp(c.name, name) == 0){ 
   system("cls"); 
   printf("\t\t\t\tUser %s is founded.\n\n", name); 
   find = 0; 
    
   //choose internet package 
   printf("\t\t\t\tPlease choose the INTERNET PACKAGE---->\n"); 
   printf("\t\t\t\t1. 1G Internet Package\n"); 
   printf("\t\t\t\t2. 4G Internet Package\n"); 
   printf("\t\t\t\tInternet Package: "); 
   scanf("%d", &internet); 
 
   //choose the operator 
   printf("\n\t\t\t\tServices Operator: "); 
   printf("\n\t\t\t\t1. DIGI"); 
   printf("\n\t\t\t\t2. CELCOME"); 
   printf("\n\t\t\t\t3. HOTLINK");
   printf("\n\t\t\t\t4. TUNETALK");
   printf("\n\t\t\t\t5. MAXIS");
   printf("\n\t\t\t\t6. U-MOBILE");
   printf("\n\t\t\t\tPlease choose SERVICES OPERATOR for %s: ", name); 
   scanf("%d", &typop); 
   printf("\t\t\t\tThe services operator for %s is %d", name, typop); 
   
   //numbers of operator contacted 
   printf("\n"); 
   printf("\n\t\t\t\tTotal operator called: "); 
   scanf("%d", &numop); 
    
    
   for (i = 0; i < numop; i++){ 
    printf("\n\t\t\t\tOperator %d ---> ", i+1); 
     
    printf("\n\t\t\t\tCalled to Services Operator: "); 
    fflush(stdin); 
    scanf("%d", &chop); 
     
     
    printf("\t\t\t\tTime called (in 24-hour)   : "); 
    scanf("%d", &time); 
     
    printf("\t\t\t\tDuration (in minutes)      : "); 
    scanf("%f", &duration); 
     
    printf("\t\t\t\tTotal SMS sent             : "); 
    scanf("%d", &sms); 
     
     
    if (chop == typop) { 
     if (time >= 700 && time <= 1900) { 
      scall = 0.15*duration; 
      ssms = 0.10*sms; 
     } 
     else { 
      scall = 0.08*duration; 
      ssms = 0.10*sms; 
     } 
    } 
    else if (chop != typop) { 
     if (time >= 700 && time <= 1900) { 
      dcall = 0.30*duration; 
      dsms = 0.20*sms; 
     } 
     else { 
      dcall = 0.20*duration; 
      dsms = 0.20*sms; 
     } 
    } 
   } 
      
    
   tax = 0.10; 
   rental = 20.00; 
   tssms = ssms; 
   tdsms = dsms; 
   tscall = scall; 
   tdcall = dcall; 
    
   system("cls"); 
   printf("\t\t\t%s Bills", c.name); 
   printf("\n__________________________________________________________________"); 
   printf("\n"); 
   printf("\nCustomer Name                             : %s", c.name); 
   printf("\nIC                                        : %s", c.ic); 
   printf("\nAddress                                   : %s", c.address); 
   printf("\nPhone no                                  : %s", c.phonenum); 
   printf("\n___________________________________________________________________"); 
   printf("\n"); 
   printf("\nMonthly Rental                            : RM %.2f", rental); 
   printf("\nMonthly SMS charge  (same operator)       : RM %.2f", tssms); 
   printf("\nMonthly SMS charge  (different operator)  : RM %.2f", tdsms); 
   printf("\nMonthly CALL charge (same operator)       : RM %.2f", tscall); 
   printf("\nMonthly CALL charge (different operator)  : RM %.2f", tdcall); 
    
   if (internet == 1) { 
    package = 50; 
    tcharge = tssms + tdsms + tscall + tdcall + package +rental; 
    servicestax = tcharge*tax; 
    amount = tcharge + servicestax; 
    printf("\nInternet Package (%dG)                     : RM %.2f", internet, package); 
    printf("\n___________________________________________________________________"); 
    printf("\n"); 
    printf("\nTotal Charges                             : RM %.2f", tcharge); 
    printf("\nServices tax                              : RM %.2f", servicestax); 
    printf("\n___________________________________________________________________"); 
    printf("\n"); 
    printf("\nTotal Amount Due                          : RM %.2f", amount); 
    printf("\n___________________________________________________________________"); 
    printf("\n"); 
   } 
   else if (internet == 2) { 
    package = 80; 
    tcharge = tssms + tdsms + tscall + tdcall + package + rental; 
    servicestax = tcharge*tax; 
    amount = tcharge + servicestax;
    printf("\nInternet Package (%dG)                     : RM %.2f", internet, package); 
    printf("\n___________________________________________________________________"); 
    printf("\n"); 
    printf("\nTotal Charges                             : RM %.2f", tcharge); 
    printf("\nServices tax                              : RM %.2f", servicestax); 
    printf("\n___________________________________________________________________"); 
    printf("\n"); 
    printf("\nTotal Amount Due                          : RM %.2f", amount); 
    printf("\n___________________________________________________________________"); 
    printf("\n"); 
   } 
      
   break; 
  } 
  else if (find == 1) { 
   system("cls"); 
   fflush(stdin); 
   printf("\n\n\n\t\t\t\tSorry! User is NOT FOUNDED in the database.\n\n"); 
   printf("\t\t\t\tPlease input new user name in add customer information.\n"); 
   printf("\t\t\t\tPress any key to go back..."); 
  } 
 } 
  
 getch(); 
 fclose(f); 
 system("cls");  
}
