#ifndef CUSTCONTROLLER_H_INCLUDED
#define CUSTCONTROLLER_H_INCLUDED

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

struct Customer_ctrl {
    int i_PK;
    int i_current;
    int i_first;    // Premier element affichable
    int i_last;     // Dernier element affichable
    int i_nbAffichable; // Nombre d'elements affichable
};

typedef struct Customer_ctrl Customer_ctrl;

void initCustomer(Customer *);
void displayCustomer(Customer);
void createCustomer(Customer *,Customer_ctrl *);
void updateCustomer(Customer *);
void deleteCustomer(Customer *, Customer_ctrl *);
void cleanCustomer(Customer *,Customer_ctrl *);
void nextCustomer(Customer *, Customer_ctrl *);
void previousCustomer(Customer *, Customer_ctrl *);
int selectCustomer(Customer *,Customer_ctrl *);


#endif // CUSTCONTROLLER_H_INCLUDED
