#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void Registration();
extern void SortContacts();
extern void Delete();
extern void FindByBirth();
extern void ShowAll();
extern void Exit();
extern void Init();
extern int DisplayMenu();

// contact data
struct contact_s {
 char *name;
 char *phonenumber;
 char *birthdate;
};

// master contact information
struct contact_s **contacts;

// current contact in struct
// -1 means initial empty data set
int ndx=-1;

/*
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
    
    // temporary input for new contact
    char name[21];
    char phonenumber[16];
    char birthdate[9];
        
    printf("Name:");
    scanf("%s", &name[0]);
    
    // Check to see if there is a duplicate Contact Name
    // If so, Return quietly to menu
    for (int i=0; i<(ndx+1); i++) 
    {
        if (strcmp(name, Contact[i].Name) == 0)
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
*/



/*
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
            for (int j = i; j < (ndx+1); j++)
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
    
    //printf("-------------\n");
    //printf("DEBUG: ndx: %d\n", ndx);
    //printf("DEBUG: ShowAll()\n");
    //ShowAll();
    //printf("-------------\n");
    
}
*/


/*
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
        // Assuming all data is valid per the specification 
        //printf("DEBUG: sizeof(birthdate): %d\n", sizeof(Contact[i].Birthdate));
        //if (sizeof(Contact[i].Birthdate) < 6) {
        //   continue;
        //}
        
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
*/



/*
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
*/

/*
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
*/

/*
int DisplayMenu() 
{
    int number=0;
    printf("*****Menu*****\n");
    printf("<1.Registration><2.ShowAll><3.Delete><4.FindByBirth><5.Exit>\n");
    printf("Enter_the_menu_number:");   
    scanf("%d", &number);
    return number;
}
*/

void Init() {

    /* %u vs %I64dx vs %zd, size_t=z, d=decimal */

    /*
    int max_num=0;
    printf("Max_num:");
    scanf("%d", &max_num);

    // number of records, not allocated memory
    // allocated memory = number of records + 1 for null terminator
    if (max_num < 1)
        max_num = 1;

    if (max_num > 100);
        max_num = 100;

    //max_num is to allocate memory space for structure pointer arrays
    //As receiving new information, allocate space for structure variable(s)
    //For structure members, need one extra space
    //In “delete“, free structure members and structure variables
    */

    //allocate and initialize struct
    //int i=0;
    //for (i=0; i<max_num; i++) {

    /*
    const int max_num = 1;
    struct contact_s contacts2[max_num];
    */

    // struct Contact_s *contacts = 
    struct contact_s *new_contact = malloc(sizeof(struct contact_s));

    printf("printing ...\n");
    printf("new_contact: %p\n", new_contact);
    //printf("contacts struct size: %u\n", sizeof(struct contact_s));
    printf("contacts struct size: %I64d\n", sizeof(struct contact_s));
    printf("new_contact size: %I64d\n", sizeof(new_contact));
   
    int name_size = 21;
    int phonenumber_size = 16;
    int birthdate_size = 9;

    /* create new contact */
    //add_contact(struct contact_s *contacts) { }
    
    new_contact->name =
        calloc(name_size, sizeof(*new_contact->name));

    new_contact->phonenumber =
        calloc(phonenumber_size, sizeof(*new_contact->phonenumber));

    new_contact->birthdate =
        calloc(birthdate_size, sizeof(*new_contact->birthdate));

    /* populate contact data */

    strcpy(new_contact->name, "Walter White");
    strcpy(new_contact->phonenumber, "2225551212");
    strcpy(new_contact->birthdate, "19990315");

    /*
    strcpy(contacts2[0].name, "Jesse Pinkman");
    strcpy(contacts2[0].phonenumber, "2225551212");
    strcpy(contacts2[0].birthdate, "20100315");
    */
    


    /* debug */
    
    printf("name: %s\n", new_contact->name);
    printf("phonenumber: %s\n", new_contact->phonenumber);
    printf("birthdate: %s\n", new_contact->birthdate);

    /*
    printf("name2: %s\n", contacts2[0].name);
    printf("phonenumber2: %s\n", contacts2[0].phonenumber);
    printf("birthdate2: %s\n", contacts2[0].birthdate);
    */
    
    printf("new_contact* size: %I64d\n", sizeof(*new_contact));
    printf("new_contact size: %I64d\n", sizeof(new_contact));



/////

    struct contact_s *new_contact2 = malloc(sizeof(struct contact_s));

    new_contact2->name =
        calloc(name_size, sizeof(*new_contact2->name));

    new_contact2->phonenumber =
        calloc(phonenumber_size, sizeof(*new_contact2->phonenumber));

    new_contact2->birthdate =
        calloc(birthdate_size, sizeof(*new_contact2->birthdate));

    /* populate contact data */

    strcpy(new_contact2->name, "Jesse Pinkman");
    strcpy(new_contact2->phonenumber, "2225551212");
    strcpy(new_contact2->birthdate, "19990315");
    
    printf("name: %s\n", new_contact2->name);
    printf("phonenumber: %s\n", new_contact2->phonenumber);
    printf("birthdate: %s\n", new_contact2->birthdate);    

/////

    const int max_num = 4;
    struct contact_s **cc = &new_contact;
    cc[1] = new_contact2;
    cc[2] = new_contact2;
    cc[3] = new_contact;
    
//    cc++;
//    cc = new_contact;
//    cc++;
//    cc = NULL;

      for (int j=0; j<max_num; j++) 
      {
          printf("-name: %s\n", cc[j]->name);
      }
    
    /*
    printf("-name: %s\n", cc[0]->name);
    printf("-name: %s\n", cc[1]->name);
    printf("-name: %s\n", cc[2]->name);
    */
    
    //printf("-name: %s\n", cc[1]->name);
    
    //printf("-phonenumber: %s\n", &cc->phonenumber);
    //printf("-birthdate: %s\n", &cc->birthdate);    

    

//    contacts[0] = &new_contact;
//    printf("-name: %s\n", contacts[0]->name);
//    printf("-phonenumber: %s\n", contacts[0]->phonenumber);
//    printf("-birthdate: %s\n", contacts[0]->birthdate);    
//    
//    contacts++;
//    contacts = &new_contact2;
//    contacts++;
//    contacts = NULL;


/*
    struct contact_s *cs[3];
    *cs = new_contact;
    *cs++;
    *cs = new_contact2;
    *c++;
    *cs = NULL;
*/    
    
//    printf("contacts TOTAL size: %I64d\n", sizeof(contacts));
//    printf("contacts* TOTAL size: %I64d\n", sizeof(*contacts));
//    int total=0;
    
    
    //void *ctr = &contacts[0];
    //struct contact_s *ctr = &contacts[0];
    //struct contact_s *ctr = &contacts[0][0];

    /*
    while (ctr++ != NULL) {
        total++;
    }
    */

    //printf("contact1: %s\n", ctr->name);
    //ctr++;
    //printf("contact2: %s\n", ctr->name);

        
    //printf("contacts TOTAL records: %d\n", total);        
    
    /* free contact */
    /* TODO: use free_contact(), free_contacts() as needed */

    free(new_contact->birthdate);
    free(new_contact->phonenumber);
    free(new_contact->name);
    free(new_contact);

    free(new_contact2->birthdate);
    free(new_contact2->phonenumber);
    free(new_contact2->name);
    free(new_contact2);

    free(contacts);
}

void Exit() {
    exit(0);
}

int main(void)
{
    Init(contacts);
}

/*
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
*/









    //char *name = malloc(name_size * sizeof(char*));
    //contacts->phonenumber = malloc(phonenumber_size * sizeof(char*)); // cppcheck says this style
    //contacts->phonenumber = calloc(phonenumber_size, sizeof(char*)); // cppcheck says this style
    //contacts->name
    // 21,16,9
    // new struct
    //contacts[0]->Name = malloc(21 * sizeof(char));
    //strcpy(contacts[i]->Name, "Georgie Porgie");
    //strcpy(contacts[i]->PhoneNumber, "12345678");
