#include "Customer.h"

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

void createCustomer(Customer *c, Customer_ctrl *customer_ctrl) {
    c->i_idCustomer = customer_ctrl->i_PK;
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

    customer_ctrl->i_last = customer_ctrl->i_current = customer_ctrl->i_PK;
    customer_ctrl->i_PK++;
    customer_ctrl->i_nbAffichable++;
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

void deleteCustomer(Customer *c, Customer_ctrl *customer_ctrl){
    c->b_isDeleted = 1;
    customer_ctrl->i_nbAffichable--;
}

void cleanCustomer(Customer *c,Customer_ctrl *customer_ctrl){
    int i = 0;
    while ( c[i].b_isDeleted == 1 ){
        i++;
    }
    customer_ctrl->i_first = i;

    i = customer_ctrl->i_PK - 1 ;
    while ( c[i].b_isDeleted == 1 ){
        i--;
    }
    customer_ctrl->i_last = i;

}

void nextCustomer(Customer *c, Customer_ctrl *customer_ctrl){
    int i = customer_ctrl->i_current;
    if ( customer_ctrl->i_current == customer_ctrl->i_last ) {
        printf("\nYou are already on the last position");
    } else {
        i++;
        while ( c[i].b_isDeleted == 1 ){
            i++;
        }
        customer_ctrl->i_current = i;
    }
}


void previousCustomer(Customer *c, Customer_ctrl *customer_ctrl){
    int i = customer_ctrl->i_current;
    if ( customer_ctrl->i_current == customer_ctrl->i_first ) {
        printf("\nYou are already on the first position");
    } else {
        i--;
        while ( c[i].b_isDeleted == 1 ){
            i--;
        }
        customer_ctrl->i_current = i;
    }
}

int selectCustomer(Customer *c,Customer_ctrl *customer_ctrl){
    int i;
    int i_ch;

    do {
        for(i = customer_ctrl->i_first; i <= customer_ctrl->i_last; i++){
            if(c[i].b_isDeleted == 0){
                printf("\n%d | %s %s", c[i].i_idCustomer, c[i].s_lastname, c[i].s_firstname);
            }
        }

        printf("\nSelect the customer : ");
        i_ch=lireInt();

    } while ((i_ch < customer_ctrl->i_first) || (i_ch > customer_ctrl->i_last) || (c[i_ch].b_isDeleted == 1));

    customer_ctrl->i_current=i_ch;
    return i_ch;
}
