
#ifndef PERSO_H
#define PERSO_H

#include <time.h>

struct Date
{
    int i_jour;
    int i_mois;
    int i_annee;
};

typedef struct Date Date;

void viderBuffer();

/****************************************************
 * Nom : Lire
 * But : Encodage securise d'une chaine de caracteres
 * IN : chaine :> Variable contenant la chaine
 *      longueur : longueur maximum de la chaine
 * OUT : Flag de r�ussite
 * Version : 1.0
 * auteur : NOJ
 *****************************************************/
int lire(char *chaine, int longueur);

void format(char *chaine, int longueur, char c);

char lireCaractere();

long lireLong();

float lireFloat();

double lireDouble();

int lireInt();

int continuer();

void get_temps(Date *);

int diff_temps(Date, Date);

Date lireDate();

void DisplayDate(Date);

#endif


#ifndef PERSO_H
#define PERSO_H

#include <time.h>

struct Date
{
    int i_jour;
    int i_mois;
    int i_annee;
};

typedef struct Date Date;

void viderBuffer();

/****************************************************
 * Nom : Lire
 * But : Encodage securise d'une chaine de caracteres
 * IN : chaine :> Variable contenant la chaine
 *      longueur : longueur maximum de la chaine
 * OUT : Flag de r�ussite
 * Version : 1.0
 * auteur : NOJ
 *****************************************************/
int lire(char *chaine, int longueur);

void format(char *chaine, int longueur, char c);

char lireCaractere();

long lireLong();

float lireFloat();

double lireDouble();

int lireInt();

int continuer();

void get_temps(Date *);

int diff_temps(Date, Date);

Date lireDate();

void DisplayDate(Date);

#endif
