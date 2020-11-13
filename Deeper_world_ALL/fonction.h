

#ifdef DEF_TRIPLE
#define DEF_TRPLE
int triple(int nombre);
#endif // DECOUPEMINUTE

#ifdef CAREE
#define CAREE
int carre(int nombre);
#endif // CAREE

#ifdef DECOUPEMINUTE
#define DECOUPEMINUTE
void decoupeMinute(int *minutes, int *heures);
#endif // DECOUPEMINUTE


#ifdef COPIETABLEAUX
#define COPIETABLEAUX
void copieTableau(int vraiTableau[], int fauxTableau[], int tailleTableau);
#endif // COPIETABLEAUX

#ifdef RANDOM
#define RANDOM
srand(time(NULL));
#endif // RANDOM

#ifdef lirecara
#define lirecara
char lireCaractere();
#endif // lirecara

#ifdef morpion
#define morpion
int Victoire(int ligneHaut[],int ligneMilieu[],int ligneBas[], int win);
#endif // morpion

#ifdef ordonner
#define ordonner
void ordonnerTableau(int tableau[], int tailleTableau);
#endif // ordonner

#ifdef exposant
#define exposant
int exposant(int n,int exposant);
#endif // exposant











