#include "Order.h"

void initOrder(Order *o) {
    o->i_idOrder = 0;
    o->i_FK_Customer = 0;
    strcpy(o->s_reference, "Unknown");
    strcpy(o->s_date, "Unknown");
    o->d_price=0.0;
    strcpy(o->s_status, "Unknown");

    o->b_isDeleted = 1;
}

void displayOrder(Order o) {
    if(o.b_isDeleted == 0){
        printf("\n Order id : %d", o.i_idOrder);
        printf("\n Name : %s", o.s_reference);
        printf("\n Category : %s", o.s_date);
        printf("\n Price : %.2lf", o.d_price);
    }
}

void createOrder(Order *o, Order_ctrl *order_ctrl) {
    o->i_idOrder = Order_ctrl->i_PK;
    o->b_isDeleted = 0;

    //printf("\n Please enter the Name : ");
    //lire(o->s_reference, 50);

    printf("\n Please enter Reference : ");
    lire(o->s_reference, 50);

    printf("\n Please enter the Date : ");
    lire(o->s_date, 50);

    printf("\n Please enter Status : ");
    lire(o->s_status, 50);

    printf("\n Please enter the Price : ");
    o->d_price=lireDouble();

    order_ctrl->i_last = order_ctrl->i_current = order_ctrl->i_PK;
    order_ctrl->i_PK++;
    order_ctrl->i_nbAffichable++;
}

void updateOrder(Order *o) {
    int i_choice = 0;
    do {
        do {
            printf("\nUpdate of o Order");
            printf("\n--------------------");

            printf("\n1. Name");
            printf("\n2. Category");
            printf("\n3. Price");
            printf("\n4. Back to previous menu");
            printf("\n--------------------");
            printf("\nEnter your choice : ");
            i_choice = lireInt();

        } while (i_choice < 0 || i_choice > 4);

        switch (i_choice) {
            case 1 :
                printf("\n Please enter the Name : ");
                lire(o->s_reference, 100);
                break;
            case 2 :
                printf("\n Please enter the Category : ");
                lire(o->s_date, 50);
                break;
            case 3 :
                printf("\n Please enter the Price : ");
                o->d_price=lireDouble();
                break;
            case 4 :
                printf("\n Previous menu ...");
                getchar();
                break;
            default:
                printf("Wrong choice ! Try again");
                break;

        }
    } while (i_choice != 4);
}

void deleteOrder(Order *o, Order_ctrl *order_ctrl){
    o->b_isDeleted = 1;
    order_ctrl->i_nbAffichable--;
}

void cleanOrder(Order *o,Order_ctrl *order_ctrl){
    int i = 0;
    while ( o[i].b_isDeleted == 1 ){
        i++;
    }
    order_ctrl->i_first = i;

    i = order_ctrl->i_PK - 1 ;
    while ( o[i].b_isDeleted == 1 ){
        i--;
    }
    order_ctrl->i_last = i;

}

void nextOrder(Order *o, Order_ctrl *order_ctrl){
    int i = order_ctrl->i_current;
    if ( order_ctrl->i_current == order_ctrl->i_last ) {
        printf("\nYou are already on the last position");
    } else {
        i++;
        while ( o[i].b_isDeleted == 1 ){
            i++;
        }
        order_ctrl->i_current = i;
    }
}


void previousOrder(Order *o, Order_ctrl *Order_ctrl){
    int i = Order_ctrl->i_current;
    if ( Order_ctrl->i_current == Order_ctrl->i_first ) {
        printf("\nYou are already on the first position");
    } else {
        i--;
        while ( o[i].b_isDeleted == 1 ){
            i--;
        }
        Order_ctrl->i_current = i;
    }
}
