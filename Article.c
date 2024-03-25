#include "Article.h"

void initArticle(Article *a) {
    a->i_idArticle = 0;
    strcpy(a->s_name, "Unknown");
    strcpy(a->s_category, "Unknown");
    a->d_price=0.0;

    a->b_isDeleted = 1;
}

void displayArticle(Article a) {
    if(a.b_isDeleted == 0){
        printf("\n Article id : %d", a.i_idArticle);
        printf("\n Name : %s", a.s_name);
        printf("\n Category : %s", a.s_category);
        printf("\n Price : %.2lf", a.d_price);
    }
}

void createArticle(Article *a, Article_ctrl *article_ctrl) {
    a->i_idArticle = article_ctrl->i_PK;
    a->b_isDeleted = 0;

    printf("\n Please enter the Name : ");
    lire(a->s_name, 50);

    printf("\n Please enter the Category : ");
    lire(a->s_category, 50);

    printf("\n Please enter the Price : ");
    a->d_price=lireDouble();

    article_ctrl->i_last = article_ctrl->i_current = article_ctrl->i_PK;
    article_ctrl->i_PK++;
    article_ctrl->i_nbAffichable++;
}

void updateArticle(Article *a) {
    int i_choice = 0;
    do {
        do {
            printf("\nUpdate of a Article");
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
                lire(a->s_name, 100);
                break;
            case 2 :
                printf("\n Please enter the Category : ");
                lire(a->s_category, 50);
                break;
            case 3 :
                printf("\n Please enter the Price : ");
                a->d_price=lireDouble();
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

void deleteArticle(Article *a, Article_ctrl *Article_ctrl){
    a->b_isDeleted = 1;
    Article_ctrl->i_nbAffichable--;
}

void cleanArticle(Article *a,Article_ctrl *Article_ctrl){
    int i = 0;
    while ( a[i].b_isDeleted == 1 ){
        i++;
    }
    Article_ctrl->i_first = i;

    i = Article_ctrl->i_PK - 1 ;
    while ( a[i].b_isDeleted == 1 ){
        i--;
    }
    Article_ctrl->i_last = i;

}

void nextArticle(Article *a, Article_ctrl *Article_ctrl){
    int i = Article_ctrl->i_current;
    if ( Article_ctrl->i_current == Article_ctrl->i_last ) {
        printf("\nYou are already on the last position");
    } else {
        i++;
        while ( a[i].b_isDeleted == 1 ){
            i++;
        }
        Article_ctrl->i_current = i;
    }
}


void previousArticle(Article *a, Article_ctrl *Article_ctrl){
    int i = Article_ctrl->i_current;
    if ( Article_ctrl->i_current == Article_ctrl->i_first ) {
        printf("\nYou are already on the first position");
    } else {
        i--;
        while ( a[i].b_isDeleted == 1 ){
            i--;
        }
        Article_ctrl->i_current = i;
    }
}

int selectArticle(Article *a,Article_ctrl *article_ctrl){
    int i;
    int i_ch;

    do {
        for(i = article_ctrl->i_first; i <= article_ctrl->i_last; i++){
            if(a[i].b_isDeleted == 0){
                printf("\n%d | %s %s", a[i].i_idArticle, a[i].s_name, a[i].s_category);
            }
        }

        printf("\nSelect the article : ");
        i_ch=lireInt();

    } while ((i_ch < article_ctrl->i_first) || (i_ch > article_ctrl->i_last) || (a[i_ch].b_isDeleted == 1));

    article_ctrl->i_current=i_ch;
    return i_ch;
}
