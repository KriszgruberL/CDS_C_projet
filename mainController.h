#ifndef MAINCONTROLLER_H_INCLUDED
#define MAINCONTROLLER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perso.h"
#include "Customer.h"
#include "Article.h"
#include "Order.h"

#define MAX 20

void Main_Ctrl();
void Customer_Ctrl(Customer *, Customer_ctrl *);
void Article_Ctrl(Article *, Article_ctrl * );
void Order_Ctrl(Order *, Order_ctrl *, Customer *, Customer_ctrl *);

#endif // MAINCONTROLLER_H_INCLUDED
