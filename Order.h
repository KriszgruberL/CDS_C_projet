#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perso.h"
#include "Customer.h"

#define MAX 20

struct Order {
    int i_idOrder;

    int i_FK_Customer;
    char s_reference[50];
    char s_date[50];
    double d_price;
    char s_status[50];

    int b_isDeleted;
    // boolean 1 -> deleted
    // 0 -> exist
};

typedef struct Order Order;

struct Order_ctrl {
    int i_PK;
    int i_current;
    int i_first;    // Premier element affichable
    int i_last;     // Dernier element affichable
    int i_nbAffichable; // Nombre d'elements affichable
};

typedef struct Order_ctrl Order_ctrl;

void initOrder(Order *);
void displayOrder(Order, Customer *);
void createOrder(Order *, Order_ctrl *, Customer *, Customer_ctrl *);
void deleteOrder(Order *, Order_ctrl *);
void cleanOrder(Order *,Order_ctrl *);
void nextOrder(Order *, Order_ctrl *);
void previousOrder(Order *, Order_ctrl *);
int selectOrder(Order *,Order_ctrl *);

#endif // ORDER_H_INCLUDED
