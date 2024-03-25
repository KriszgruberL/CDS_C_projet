#include "mainController.h"

void Main_Ctrl(){

    int i_ch = 0;
    Customer_ctrl custCtrl ={0,0,0,0,0};
    Customer listCustomers[MAX];
    Article_ctrl artCtrl ={0,0,0,0,0};
    Article listArticles[MAX];

    do
    {
        system("cls");
        printf("\nManagement");
        printf("\n*******************");
        printf("\n1. Manage Customer");
        printf("\n2. Manage Article");
        printf("\n9. Exit");
        printf("\n Please enter your choice : ");
        i_ch=lireInt();

        switch(i_ch)
        {
            case 1 :
                    Customer_Ctrl(listCustomers, &custCtrl);
                    break;
            case 2 :
                    Article_Ctrl(listArticles, &artCtrl);
                    break;
            case 9 :
                    printf("\nBye bye");
                    getchar();
                    break;
            default :
                    printf("\n Wrong choice, try again");

        }
    }while(i_ch!=9);
}

void Customer_Ctrl(Customer *listCustomers, Customer_ctrl *custCtrl){
    int i_ch=0;
    do
    {
        if(custCtrl->i_nbAffichable==0)
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
                            createCustomer(&listCustomers[custCtrl->i_PK],custCtrl);
                            cleanCustomer(listCustomers, custCtrl);
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
                displayCustomer(listCustomers[custCtrl->i_current]);
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
                            createCustomer(&listCustomers[custCtrl->i_PK],custCtrl);
                            cleanCustomer(listCustomers,custCtrl);
                            break;
                    case 2 :
                            updateCustomer(&listCustomers[custCtrl->i_current]);
                            break;
                    case 3 :
                            deleteCustomer(&listCustomers[custCtrl->i_current],custCtrl);
                            cleanCustomer(listCustomers,custCtrl);

                            if ( custCtrl->i_nbAffichable != 0 ){
                                custCtrl->i_current = custCtrl->i_first;
                            }
                            break;

                    case 4 :
                            nextCustomer(listCustomers, custCtrl);
                            break;
                    case 5 :
                            previousCustomer(listCustomers,custCtrl);
                            break;
                    case 6 :
                            custCtrl->i_current=custCtrl->i_first;
                            break;
                    case 7 :
                            custCtrl->i_current=custCtrl->i_last;
                            break;
                    case 8 :
                            selectCustomer(listCustomers,custCtrl);
                            break;
                    case 9 :
                            printf("\n back to main menu");
                            getchar();
                            break;
                    default :
                            printf("\n Wrong choice, try again");
                            getchar();

                }
            }while(i_ch!=9&&custCtrl->i_nbAffichable!=0);
        }
    }while(i_ch!=9);

}

void Article_Ctrl(Article *listArticles, Article_ctrl *artCtrl){
    int i_ch;
    do
    {
        if(artCtrl->i_nbAffichable==0)
        {
            do
            {
                system("cls");
                printf("\nManagement Article");
                printf("\n*******************");
                printf("\n1. Create Article");
                printf("\n9. Back to main menu");
                printf("\n Please enter your choice : ");
                i_ch=lireInt();

                switch(i_ch)
                {
                    case 1 :
                            createArticle(&listArticles[artCtrl->i_PK],artCtrl);
                            cleanArticle(listArticles,artCtrl);
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
                displayArticle(listArticles[artCtrl->i_current]);
                printf("\n\nManagement Article");
                printf("\n*******************");
                printf("\n1. Create Article");
                printf("\n2. Update Article");
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
                            createArticle(&listArticles[artCtrl->i_PK],artCtrl);
                            cleanArticle(listArticles,artCtrl);
                            break;
                    case 2 :
                            updateArticle(&listArticles[artCtrl->i_current]);
                            break;
                    case 3 :
                            deleteArticle(&listArticles[artCtrl->i_current],artCtrl);
                            cleanArticle(listArticles,artCtrl);

                            if ( artCtrl->i_nbAffichable != 0 ){
                                artCtrl->i_current = artCtrl->i_first;
                            }
                            break;

                    case 4 :
                            nextArticle(listArticles, artCtrl);
                            break;
                    case 5 :
                            previousArticle(listArticles,artCtrl);
                            break;
                    case 6 :
                            artCtrl->i_current=artCtrl->i_first;
                            break;
                    case 7 :
                            artCtrl->i_current=artCtrl->i_last;
                            break;
                    case 8 :
                            selectArticle(listArticles,artCtrl);
                            break;
                    case 9 :
                            printf("\n back to main menu");
                            getchar();
                            break;
                    default :
                            printf("\n Wrong choice, try again");
                            getchar();

                }
            }while(i_ch!=9&&artCtrl->i_nbAffichable!=0);
        }
    }while(i_ch!=9);

}


