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

void displayOrder(Order o, Customer *c) {
    if(o.b_isDeleted == 0){
        printf("\n Order : %d", o.i_idOrder);
        printf("\n Name : %s %s", c[o.i_FK_Customer].s_lastname, c[o.i_FK_Customer].s_firstname);
        printf("\n Reference : %s", o.s_reference);
        printf("\n Date : %s", o.s_date);
        printf("\n Status : %s", o.s_status);
        printf("\n Price : %.2lf", o.d_price);
    }
}

void createOrder(Order *o, Order_ctrl *order_ctrl, Customer *c, Customer_ctrl *cust_Ctrl) {
    o->i_idOrder = order_ctrl->i_PK;
    o->b_isDeleted = 0;
    o->i_FK_Customer=selectCustomer(c, cust_Ctrl);

    //printf("\n Please enter the Name : ");
    //lire(o->s_reference, 50);

    printf("\n Please enter Reference : ");
    lire(o->s_reference, 50);

    printf("\n Please enter Date : ");
    lire(o->s_date, 50);

    printf("\n Please enter Status : ");
    lire(o->s_status, 50);

    printf("\n Please enter Price : ");
    o->d_price=lireDouble();

    order_ctrl->i_last = order_ctrl->i_current = order_ctrl->i_PK;
    order_ctrl->i_PK++;
    order_ctrl->i_nbAffichable++;
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

int selectOrder(Order *o,Order_ctrl *order_ctrl){
    int i;
    int i_ch;

    do {
        for(i = order_ctrl->i_first; i <= order_ctrl->i_last; i++){
            if(o[i].b_isDeleted == 0){
                printf("\n%d | %s | %s",o[i].i_idOrder, o[i].s_reference, o[i].s_date);
            }
        }

        printf("\nSelect the article : ");
        i_ch=lireInt();

    } while ((i_ch < order_ctrl->i_first) || (i_ch > order_ctrl->i_last) || (o[i_ch].b_isDeleted == 1));

    order_ctrl->i_current=i_ch;
    return i_ch;
}

