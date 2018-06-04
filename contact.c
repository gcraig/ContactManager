#include <stdio.h>
#include <string.h>

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
int idx=-1;

void Registration()
{
    idx++;
        
    if (idx > 99) {
       printf("OVERFLOW\n");
       idx--;
       return;    
    }
    
    char n[21];
    char pn[16];
    char bd[9];
    
    printf("Name:");
    scanf("%s", &n);
    
    // Check to see if there is a duplicate Contact Name
    // Return
    for (int i=0; i<(idx+1); i++) 
    {
        if (strcmp(n, Contact[i].Name) == 0)
        {
            idx--;
            return;
        }
    }
    
    printf("Phone_number:");
    scanf("%s", &pn);
    printf("Birth:");
    scanf("%s", &bd);
    
    strcpy(Contact[idx].Name, n);
    strcpy(Contact[idx].PhoneNumber, pn);
    strcpy(Contact[idx].Birthdate, bd);
    
    //TODO: sort the contact structure
    
    //Print total contacts in program
    printf("<<%d>>\n", idx + 1);
}

void Delete()
{
    if (idx < 0) 
    {
       printf("NO MEMBER\n"); 
       return;
    }
    
    char n[21];
    printf("Name:");
    scanf("%s", &n);
    int found=0;
    int idxc = idx; // keep original idx count
    
    //TODO: find member and remove
    for (int i=0; i<(idxc+1); i++) 
    {
        if (strcmp(n, Contact[i].Name) == 0)
        {
            found=1;
            
            // remove entry -- buggy
            /*
            for (int j=i; j<idxc; j++)
            {
                Contact[j].Name = Contact[j+1].Name;
                Contact[j].PhoneNumber = Contact[j+1].PhoneNumber;
                Contact[j].Birthdate = Contact[j+1].Birthdate;
            }
            */
            idx--;
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
    for (int i=0; i<(idx+1); i++) 
    {
        // Obtain Contact birth month
        m[0] = Contact[i].Birthdate[4];
        m[1] = Contact[i].Birthdate[5];
        m[2] = '\0';
        int month = atoi(m);
        
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
    if (idx < 0)
    {
       return;
    }
       
    for (int i=0; i<(idx+1); i++) 
    {
         printf("%s %s %s\n", 
           Contact[i].Name, 
           Contact[i].PhoneNumber, 
           Contact[i].Birthdate); 
    }
}

/*
void SortContacts()
{
    for (int i=0; i==idx; i++) 
    {
        // ? 
        if (i == idx) {
            // blank last entry
            // fix ndx
            goto Sorted;
        }
        
        if (strcmp(Contact[i].Name, Contact[i+1].Name) > 0)
        {
            strcpy(TempContact[i].Name, Contact[i+1].Name);
            strcpy(TempContact[i].PhoneNumber, Contact[i+1].PhoneNumber);
            strcpy(TempContact[i].Birthdate, Contact[i+1].Birthdate);
            
        } else
        if (strcmp(Contact[i].Name, Contact[i+1].Name) < 0)
        {
            strcpy(TempContact[i].Name, Contact[i].Name);
            strcpy(TempContact[i].PhoneNumber, Contact[i].PhoneNumber);
            strcpy(TempContact[i].Birthdate, Contact[i].Birthdate);
            
        } else
        if (strcmp(Contact[i].Name, Contact[i+1].Name) == 0)
        {
            strcpy(TempContact[i].Name, Contact[i].Name);
            strcpy(TempContact[i].PhoneNumber, Contact[i].PhoneNumber);
            strcpy(TempContact[i].Birthdate, Contact[i].Birthdate);
        }
    }

Sorted:    
           for (int i=0; i<(idx+1); i++) 
           {
               strcpy(Contact[i].Name, TempContact[i].Name);
               strcpy(Contact[i].PhoneNumber, TempContact[i].PhoneNumber);
               strcpy(Contact[i].Birthdate, TempContact[i].Birthdate);
           }
}
*/

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
