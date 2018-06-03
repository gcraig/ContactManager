#include <stdio.h>
#include <string.h>

struct ContactStruct {
 char Name[21];
 char PhoneNumber[16];
 char Birthdate[9];
};

struct ContactStruct Contact[100];
struct ContactStruct *Contactptr;

void Registration()  // Contactptr *contact
{
    printf("Name:"); // do not change
    printf("Phone_number:"); // do not change
    printf("Birth:"); // do not change
}

void Delete()
{
    printf("Name:"); // do not change
}

void FindByBirth() 
{
    printf("Birth"); // do not change
}

void ShowAll()
{
    //char test[10] = {'t','t','t','t'};
    //printf("%s %s %s\n", test, test, test );
    
    Contact *c = &Contact[0];
    for (int i=0; i<len; i++)
    {
        if (++c) {
            printf("%s %s %s\n", c->Name, c->PhoneNumber, c->Birthdate);
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
    int number=0;

Menu:
    number=DisplayMenu();
   
    switch(number) {
        case 1: Registration(); break;
        case 2: ShowAll();      break;
        case 3: Delete();       break;
        case 4: FindByBirth();  break;
        case 5: Exit();         break;
    }
    
    goto Menu;
}
