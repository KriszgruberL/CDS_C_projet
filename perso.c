#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#include"perso.h"

void viderBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

int lire(char *chaine, int longueur)
{
	char *positionEntree = NULL;
	if (fgets(chaine, longueur, stdin) != NULL)
	{
		positionEntree = strchr(chaine, '\n');
		if (positionEntree != NULL)
		{
			*positionEntree = '\0';
		}
		else
		{
			viderBuffer();
		}
		return 1;
	}
	else
	{
		viderBuffer();
		return 0;
	}
}

char lireCaractere()
{
	char caractere = 0;
	caractere = getchar(); /* On lit le premier caract�re
	//caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas d�j�
	// On lit les autres caract�res m�moris�s un � un jusqu'au \n (pour les effacer)*/
	while (getchar() != '\n') ;
	return caractere;
}

long lireLong()
{
	char nombreTexte[100] = {0};

	if (lire(nombreTexte, 100))
	{

		return strtol(nombreTexte, NULL, 10);
	}
	else
	{

		return 0;
	}
}

int lireInt()
{
	char nombreTexte[100] = {0};

	if (lire(nombreTexte, 100))
	{

		return atoi(nombreTexte);
	}
	else
	{

		return 0;
	}
}

void format(char *chaine, int longueur, char c)
{
	int i;

	for (i=0;i<longueur;i++)
		chaine[i]=c;
}

int continuer()
{
	char c;

	do
	{
		printf("\n Do you want to continue ? (Y/N)");
		c=lireCaractere();
	}while( c!='y' && c!='n' && c!='Y' && c!='N');

	if ( c=='y' || c=='Y')
		return 1;
	else
		return 0;
}

float lireFloat()
{
  	char nombreTexte[100] = {0};

	if (lire(nombreTexte, 100))
	{
		return strtof(nombreTexte, NULL);
	}
	else
	{
		return 0;
	}
}

double lireDouble()
{
  	char nombreTexte[100] = {0};

	if (lire(nombreTexte, 100))
	{
		return atof(nombreTexte);
	}
	else
	{
		return 0;
	}
}

void get_temps(Date *Date_du_jour)
{

    time_t timestamp;
    struct tm * t;

    timestamp = time(NULL);
    t = gmtime(&timestamp);

    Date_du_jour->i_jour=t->tm_mday;
    Date_du_jour->i_mois=t->tm_mon+1;
    Date_du_jour->i_annee=t->tm_year+1900;
}

int diff_temps(Date Date_de_debut, Date Date_de_fin)
{
    time_t now;
    struct tm newdate;
    struct tm newdate2;
    double seconds;

    time(&now);

    newdate = *localtime(&now);
    newdate2 = *localtime(&now);

    newdate.tm_hour = 0; newdate.tm_min = 0; newdate.tm_sec = 0;
    newdate.tm_mon = Date_de_debut.i_mois-1;
    newdate.tm_mday = Date_de_debut.i_jour;
    newdate.tm_year = Date_de_debut.i_annee - 1900;

    newdate2.tm_hour = 0; newdate2.tm_min = 0; newdate2.tm_sec = 0;
    newdate2.tm_mon = Date_de_fin.i_mois-1;
    newdate2.tm_mday = Date_de_fin.i_jour;
    newdate2.tm_year = Date_de_fin.i_annee - 1900;

    seconds = difftime(mktime(&newdate2),mktime(&newdate));

    return (int)seconds/(60*60*24);

}

Date lireDate()
{
    char c_Rep='y';
    Date d;
    printf("\n Do you want the current date ? (y/n)");
    c_Rep=lireCaractere();
    if (tolower(c_Rep)=='y')
    {
        get_temps(&d);
    }
    else
    {
        do
        {
            printf("\n Please enter the day :");
            d.i_jour=lireInt();
        }while(d.i_jour<0||d.i_jour>31);
        do
        {
            printf("\n Please enter the month :");
            d.i_mois=lireInt();
        }while(d.i_mois<0||d.i_mois>12);
        do
        {
            printf("\n Please enter the year :");
            d.i_annee=lireInt();
        }while(d.i_mois<0||d.i_mois>2100);
    }

    return d;
}

void DisplayDate(Date d)
{
    printf("%d ",d.i_jour);
    switch(d.i_mois)
    {
        case 1:
                printf("Janvier ");
                break;
        case 2:
                printf("F�vrier ");
                break;
        case 3:
                printf("Mars ");
                break;
        case 4:
                printf("Avril ");
                break;
        case 5:
                printf("Mai ");
                break;
        case 6:
                printf("Juin ");
                break;
        case 7:
                printf("Juillet ");
                break;
        case 8:
                printf("Ao�t ");
                break;
        case 9:
                printf("Septembre ");
                break;
        case 10:
                printf("Octobre ");
                break;
        case 11:
                printf("Novembre ");
                break;
        case 12:
                printf("D�cembre ");
                break;
        default : printf("inconnu ");
    }
    printf("%d ",d.i_annee);
}
