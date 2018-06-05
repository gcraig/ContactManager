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
    
    // Temporary input for new Contact
    char n[21];
    char pn[16];
    char bd[9];
    
    printf("Name:");
    scanf("%s", &n[0]);
    
    // Check to see if there is a duplicate Contact Name
    // If so, Return quietly to menu
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
    
    // Prompt to remove Contact
    char n[21];
    printf("Name:");
    scanf("%s", &n[0]);
    int found=0;
    
    // Search through Contacts
    for (int i=0; i<(ndx+1); i++) 
    {
        // If Contact found, remove it from list
        if (strcmp(Contact[i].Name, n) == 0)
        {
            for (int j = i; j < (ndx+1)/* length */; j++)
            {
                strcpy(Contact[j].Name, Contact[j+1].Name);
                strcpy(Contact[j].PhoneNumber, Contact[j+1].PhoneNumber);
                strcpy(Contact[j].Birthdate, Contact[j+1].Birthdate);
                found=1;
            }
        }
    }
    
    if (found) {
       // Already deleted, let's reset the index counter
       ndx = ndx - 1;
    } else {
      printf("NO MEMBER\n"); 
    }
    
    return;
    
    /*
    printf("-------------\n");
    printf("DEBUG: ndx: %d\n", ndx);
    printf("DEBUG: ShowAll()\n");
    ShowAll();
    printf("-------------\n");
    */
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
        // Invalid month
        /* Assuming all data is valid per the specification */
        /*
        printf("DEBUG: sizeof(birthdate): %d\n", sizeof(Contact[i].Birthdate));
        if (sizeof(Contact[i].Birthdate) < 6) {
           continue;
        }
        */
        
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
    
    // Temporary scratch space for Name, Phone number, and Birthdate
    // TODO: consistent naming to match other functions
    char temp[21], temp2[16], temp3[9];
    
    // Following used to show entered and sorted names; debug only
    // char sortedName[21][n], enteredName[21][n];

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
                
                strcpy(temp2, Contact[i].PhoneNumber);
                strcpy(Contact[i].PhoneNumber, Contact[j].PhoneNumber);
                strcpy(Contact[j].PhoneNumber, temp2);
                
                strcpy(temp3, Contact[i].Birthdate);
                strcpy(Contact[i].Birthdate, Contact[j].Birthdate);
                strcpy(Contact[j].Birthdate, temp3);
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
