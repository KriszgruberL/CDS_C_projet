#ifndef ARTICLECONTROLLER_H_INCLUDED
#define ARTICLECONTROLLER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perso.h"

#define MAX 20

struct Article {
    int i_idArticle;

    char s_name[50];
    char s_category[50];
    double d_price;

    int b_isDeleted;
    // boolean 1 -> deleted
    // 0 -> exist
};

typedef struct Article Article;

struct Article_ctrl {
    int i_PK;
    int i_current;
    int i_first;    // Premier element affichable
    int i_last;     // Dernier element affichable
    int i_nbAffichable; // Nombre d'elements affichable
};

typedef struct Article_ctrl Article_ctrl;

void initArticle(Article *);
void displayArticle(Article);
void createArticle(Article *,Article_ctrl *);
void updateArticle(Article *);
void deleteArticle(Article *, Article_ctrl *);
void cleanArticle(Article *,Article_ctrl *);
void nextArticle(Article *, Article_ctrl *);
void previousArticle(Article *, Article_ctrl *);
int selectArticle(Article *,Article_ctrl *);

#endif // ARTICLECONTROLLER_H_INCLUDED
