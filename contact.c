#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Registration();
void SortContacts();
void Delete();
void FindByBirth();
void ShowAll();
void Exit();
int DisplayMenu();

// Contact Data
struct Contact_s {
 char Name[21];
 char PhoneNumber[16];
 char Birthdate[9];
};

// Master Contact information
struct Contact_s Contact[100];

// Temp space for Sorting
struct Contact_s TempContact[100]; 

// Current Contact in Structure
// -1 means initial empty data set
int ndx=-1;

void Registration()
{
    ndx++;
        
    if (ndx > 99) {
       printf("OVERFLOW\n");
       ndx--;
       return;    
    }
    
    char n[21];
    char pn[16];
    char bd[9];
    
    printf("Name:");
    scanf("%s", &n[0]);
    
    // Check to see if there is a duplicate Contact Name
    // If so, Return
    for (int i=0; i<(ndx+1); i++) 
    {
        if (strcmp(n, Contact[i].Name) == 0)
        {
            ndx--;
            return;
        }
    }
    
    printf("Phone_number:");
    scanf("%s", &pn[0]);
    printf("Birth:");
    scanf("%s", &bd[0]);
    
    // Add new Contact
    strcpy(Contact[ndx].Name, n);
    strcpy(Contact[ndx].PhoneNumber, pn);
    strcpy(Contact[ndx].Birthdate, bd);
    
    // Arrange Contact structure
    SortContacts();
        
    // Print total Contacts in program
    printf("<<%d>>\n", ndx + 1);
}

void Delete()
{
    // Print none early if no data
    if (ndx < 0) 
    {
       printf("NO MEMBER\n"); 
       return;
    }
    
    // Remove deleted Contact
    char n[21];
    printf("Name:");
    scanf("%s", &n[0]);
    int found=0;
    int ndxc = ndx; // keep original ndx count
    
    //TODO: find member and remove
    for (int i=0; i<(ndxc+1); i++) 
    {
        if (strcmp(n, Contact[i].Name) == 0)
        {
            found=1;
            
            // remove entry -- buggy
            /*
            for (int j=i; j<ndxc; j++)
            {
                Contact[j].Name = Contact[j+1].Name;
                Contact[j].PhoneNumber = Contact[j+1].PhoneNumber;
                Contact[j].Birthdate = Contact[j+1].Birthdate;
            }
            */
            ndx--;
        }
    }
    
    if (!found)
       printf("NO MEMBER\n"); 
}

void FindByBirth() 
{
    // Search for birthdate in month
    int month=0, searchMonth=0;
    char m[3];
    
    printf("Birth:"); // *** TYPO in specs
    scanf("%d", &searchMonth);
        
    // Print out Contacts with matching birthdates
    for (int i=0; i<(ndx+1); i++) 
    {
        // Obtain Contact birth month
        m[0] = Contact[i].Birthdate[4];
        m[1] = Contact[i].Birthdate[5];
        m[2] = '\0';
        month = atoi(m);
        
        // Compare against searched month
        if (month == searchMonth)
        {
         printf("%s %s %s\n", 
           Contact[i].Name, 
           Contact[i].PhoneNumber, 
           Contact[i].Birthdate); 
        }
    }
}

void ShowAll()
{
    if (ndx < 0)
    {
       return;
    }
       
    for (int i=0; i<(ndx+1); i++) 
    {
         printf("%s %s %s\n", 
           Contact[i].Name, 
           Contact[i].PhoneNumber, 
           Contact[i].Birthdate); 
    }
}

void SortContacts()
{
    // No need to sort only 1 entry
    if (ndx < 1) {
        return;
    }

    int n = ndx+1;
    int i, j;
    char temp[21];
    //used to show entered and sorted names; debug only
    //char sortedName[21][n], enteredName[21][n];

    for (i = 0; i < n - 1 ; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            // Classic bubble like sort
            // Inner loop j is to sort names after the current one
            if (strcmp(Contact[i].Name, Contact[j].Name) > 0) 
            {
                strcpy(temp, Contact[i].Name);
                strcpy(Contact[i].Name, Contact[j].Name);
                strcpy(Contact[j].Name, temp);
            }
        }
    }    
}

int DisplayMenu() 
{
    int number=0;
    printf("*****Menu*****\n");
    printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
    printf("Enter_the_menu_number:");   
    scanf("%d", &number);
    return number;
}

void Exit() {
    exit(0);
}

int main()
{
    int selection=0;
    
Menu:
    selection=DisplayMenu();
   
    switch(selection) {
        case 1: Registration(); break;
        case 2: ShowAll();      break;
        case 3: Delete();       break;
        case 4: FindByBirth();  break;
        case 5: Exit();         break;
    }
    
    goto Menu;
}
