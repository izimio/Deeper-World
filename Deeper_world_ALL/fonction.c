
int triple(int nombre){

return nombre*3;

}
int carre(int nombre){

return nombre*nombre;
}


void decoupeMinute(int *minutes, int *heures){


*heures = *heures +*minutes /60;
*minutes = *minutes % 60;
}


void copieTableau(int vraiTableau[], int fauxTableau[], int tailleTableau){
int i =0;

while(i < tailleTableau){

    fauxTableau[i] = vraiTableau[i];
    i++;

}



}



char lireCaractere(){

char caractere = 0;
caractere = getchar();
caractere = toupper(caractere);

while(getchar() != '\n');
return caractere;

}


int gagne(int lettreTrouvee[]){
int i =0;
int joueurGgane = 1;

for (i = 0 ; i < 6 ; i++){
    if (lettreTrouvee[i] == 0)
        joueurGgane = 0;
}
return joueurGgane;
}


int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    int i = 0;
    int bonneLettre = 0;

    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i]) // Si la lettre y est
        {
            bonneLettre = 1; // On mémorise que c'était une bonne lettre
            lettreTrouvee[i] = 1; // On met à 1 la case du tableau de booléens correspondant à la lettre actuelle
        }
    }

    return bonneLettre;
}

int Victoire(int ligneHaut[],int ligneMilieu[],int ligneBas[], int win){

if(ligneHaut[1] == 1 && ligneHaut[2] == 1 && ligneHaut[3] == 1){
    win++;
}
if(ligneMilieu[1] == 1 && ligneMilieu[2] == 1 && ligneMilieu[3] == 1){
    win++;
}
if(ligneBas[1] == 1 && ligneBas[2] == 1 && ligneBas[3] == 1){
    win++;
}

return win;

}


// ---------------------------------------





void ordonnerTableau(int tableau[], int tailleTableau){

int i,k,f;

for (f = 0 ; f < tailleTableau ; f++){
for (i = 1 ; i < tailleTableau ; i++){

k = tableau[i] - tableau[i-1];

if(k <= 0){


    tableau[i] = tableau[i-1];
    tableau[i-1] = tableau[i-1] + k;
}




}


}

}







int exposant(int n,int exposant){

int i = 0;
int x = 1;
int resultat = 0;

for(i =0 ; i < exposant ; i++){

x  = x*n;

resultat = x;
}
return resultat;




}


int racineCarre(int n,int exposant){

float division;
int i = 0;
int x = 1;
int resultat = 0;

for(i =0 ; i < exposant ; i++){

x  = x*n;

resultat = x;
}
return resultat;




}

