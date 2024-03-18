#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perso.h"

#define MAX 20

struct Customer {
    int i_idCustomer;

    char s_lastname[100];
    char s_firstname[50];
    char s_address[100];
    char s_number[20];
    char s_zipCode[8];
    char s_city[50];

    int b_isDeleted;
    // boolean 1 -> deleted
    // 0 -> exist
};

typedef struct Customer Customer;

struct Cust_Ctrl {
    int i_PK;
    int i_current;
    int i_first;    // Premier element affichable
    int i_last;     // Dernier element affichable
    int i_nbAffichable; // Nombre d'elements affichable
};

typedef struct Cust_Ctrl Cust_Ctrl;

void initCustomer(Customer *);
void displayCustomer(Customer);
void createCustomer(Customer *,Cust_Ctrl *);
void updateCustomer(Customer *);
void deleteCustomer(Customer *, Cust_Ctrl *);
void cleanCustomer(Customer *,Cust_Ctrl *);
void nextCustomer(Customer *, Cust_Ctrl *);
void previousCustomer(Customer *, Cust_Ctrl *);

int main() {
    Cust_Ctrl custCtrl ={0,0,0,0,0};
    Customer customers[MAX];

    int i_ch;

    do
    {
        if(custCtrl.i_nbAffichable==0)
        {
            do
            {
                system("cls");
                printf("\nManagement Customer");
                printf("\n*******************");
                printf("\n1. Create Customer");
                printf("\n9. Back to main menu");
                printf("\n Please enter your choice : ");
                i_ch=lireInt();

                switch(i_ch)
                {
                    case 1 :
                            createCustomer(&customers[custCtrl.i_PK],&custCtrl);
                            displayCustomer(customers[custCtrl.i_current]);
                            cleanCustomer(customers,&custCtrl);
                            break;
                    case 9 :
                            printf("\n back to main menu");
                            getchar();
                            break;
                    default :
                            printf("\n Wrong choice, try again");

                }
            }while(i_ch!=1 && i_ch!=9);
        }
        else
        {
            do
            {
                system("cls");
                displayCustomer(customers[custCtrl.i_current]);
                printf("\n\nManagement Customer");
                printf("\n*******************");
                printf("\n1. Create Customer");
                printf("\n2. Update Customer");
                printf("\n3. Delete");
                printf("\n4. Next");
                printf("\n5. Previous");
                printf("\n6. First");
                printf("\n7. Last");
                printf("\n8. Select");
                printf("\n9. back to main menu");
                printf("\n Please enter your choice : ");
                i_ch=lireInt();

                switch(i_ch)
                {
                    case 1 :
                            createCustomer(&customers[custCtrl.i_PK],&custCtrl);
                            cleanCustomer(customers,&custCtrl);
                            break;
                    case 2 :
                            updateCustomer(&customers[custCtrl.i_current]);
                            break;
                    case 3 :
                            deleteCustomer(&customers[custCtrl.i_current],&custCtrl);
                            cleanCustomer(customers,&custCtrl);

                            if ( custCtrl.i_nbAffichable != 0 ){
                                custCtrl.i_current = custCtrl.i_first;
                            }
                            break;

                    case 4 :
                            nextCustomer(customers, &custCtrl);
                            break;
                    case 5 :
                            previousCustomer(customers,&custCtrl);
                            break;
                    case 6 :
                            custCtrl.i_current=custCtrl.i_first;
                            break;
                    case 7 :
                            custCtrl.i_current=custCtrl.i_last;
                            break;
                    case 8 :
                            //selectCustomer(customers,custCtrl);
                            break;
                    case 9 :
                            printf("\n back to main menu");
                            getchar();
                            break;
                    default :
                            printf("\n Wrong choice, try again");
                            getchar();

                }
            }while(i_ch!=9&&custCtrl.i_nbAffichable!=0);
        }
    }while(i_ch!=9);

    int i;

//Initialisation de la liste
    for (i=0; i<MAX;i++){
        initCustomer(&customers[i]);
    }


    /*initCustomer(&c1);
    displayCustomer(c1);

    createCustomer(&c1, 0);
    displayCustomer(c1);

    updateCustomer(&c1);
    displayCustomer(c1);

    deleteCustomer(&c1);
    printf("\n Il est mort");
    displayCustomer(c1);*/

    return 0;
}


void initCustomer(Customer *c) {
    c->i_idCustomer = 0;
    strcpy(c->s_lastname, "Unknown");
    strcpy(c->s_firstname, "Unknown");
    strcpy(c->s_address, "Unknown");
    strcpy(c->s_number, "Unknown");
    strcpy(c->s_zipCode, "Unknown");
    strcpy(c->s_city, "Unknown");

    c->b_isDeleted = 1;
}

void displayCustomer(Customer c) {
    if(c.b_isDeleted == 0){
        printf("\n Customer id : %d", c.i_idCustomer);
        printf("\n Last name : %s", c.s_lastname);
        printf("\n First name : %s", c.s_firstname);
        printf("\n Address : %s", c.s_address);
        printf("\n Number : %s", c.s_number);
        printf("\n Zip Code : %s", c.s_zipCode);
        printf("\n City : %s", c.s_city);
    }
}

void createCustomer(Customer *c, Cust_Ctrl *ctrl) {
    c->i_idCustomer = ctrl->i_PK;
    c->b_isDeleted = 0;

    printf("\n Please enter the last name : ");
    lire(c->s_lastname, 100);

    printf("\n Please enter the first name : ");
    lire(c->s_firstname, 50);

    printf("\n Please enter the address : ");
    lire(c->s_address, 100);

    printf("\n Please enter the number : ");
    lire(c->s_number, 20);

    printf("\n Please enter the zip code : ");
    lire(c->s_zipCode, 8);

    printf("\n Please enter the city : ");
    lire(c->s_city, 50);

    ctrl->i_last = ctrl->i_current = ctrl->i_PK;
    ctrl->i_PK++;
    ctrl->i_nbAffichable++;
}

void updateCustomer(Customer *c) {
    int i_choice = 0;
    do {
        do {
            printf("\nUpdate of a customer");
            printf("\n--------------------");

            printf("\n1. Last name");
            printf("\n2. First name");
            printf("\n3. Address");
            printf("\n4. Number");
            printf("\n5. Zip Code");
            printf("\n6. City");
            printf("\n7. Back to previous menu");
            printf("\n--------------------");
            printf("\nEnter your choice : ");
            i_choice = lireInt();

        } while (i_choice < 0 || i_choice > 7);

        switch (i_choice) {
            case 1 :
                printf("\n Please enter the last name : ");
                lire(c->s_lastname, 100);
                break;
            case 2 :
                printf("\n Please enter the first name : ");
                lire(c->s_firstname, 50);
                break;
            case 3 :
                printf("\n Please enter the address : ");
                lire(c->s_address, 100);
                break;
            case 4 :
                printf("\n Please enter the number : ");
                lire(c->s_number, 20);
                break;
            case 5 :
                printf("\n Please enter the zip code : ");
                lire(c->s_zipCode, 8);
                break;
            case 6 :
                printf("\n Please enter the city : ");
                lire(c->s_city, 50);
                break;
            case 7 :
                printf("\n Previous menu ...");
                getchar();
                break;
            default:
                printf("Wrong choice ! Try again");
                break;

        }
    } while (i_choice != 7);
}

void deleteCustomer(Customer *c, Cust_Ctrl *ctrl){
    c->b_isDeleted = 1;
    ctrl->i_nbAffichable--;
}

void cleanCustomer(Customer *c,Cust_Ctrl *ctrl){
    int i = 0;
    while ( c[i].b_isDeleted == 1 ){
        i++;
    }
    ctrl->i_first = i;

    i = ctrl->i_PK - 1 ;
    while ( c[i].b_isDeleted == 1 ){
        i--;
    }
    ctrl->i_last = i;

}

void nextCustomer(Customer *c, Cust_Ctrl *ctrl){
    int i = ctrl->i_current;
    if ( ctrl->i_current == ctrl->i_last ) {
        printf("\nYou are already on the last position");
    } else {
        i++;
        while ( c[i].b_isDeleted == 1 ){
            i++;
        }
        ctrl->i_current = i;
    }
}

//TODO Error here to check
void previousCustomer(Customer *c, Cust_Ctrl *ctrl){
    int i = ctrl->i_current;
    if ( ctrl->i_current == ctrl->i_last ) {
        printf("\nYou are already on the last position");
    } else {
        i--;
        while ( c[i].b_isDeleted == 1 ){
            i--;
        }
        ctrl->i_current = i;
    }
}
