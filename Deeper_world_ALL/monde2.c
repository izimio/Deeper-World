#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include "ctype.h"
#define MAXIMUM(valeurActuelle,SeuilANePasDepasser) if(valeurActuelle > SeuilANePasDepasser) \
                                                        valeurActuelle =SeuilANePasDepasser;



int main()
{

typedef struct statistiques statistiques;
struct statistiques {

int armure;
int attaque;
int esquive;
int coupCritique;
int pointsDeVies;
int fuite;

};
// ====================   Variables Lambda ======================
FILE* fichier = NULL;
int i = 0;
int b = 0;
int xanogene;
int choix;
int choix1;
int choix2 = 2;
int choix3;
int choix4;
int choix5 = 1;
int ouvrirCoffre;
int degatsInflige;
int TrouverEscallier;
int BonfireLit = 0;
int etageActuel  =0;
int choixSPELL;
int nombreRandome = 0;
int c = 0;
int d = 0;
int e = 0;
int finBoucleLvl0 = 0;
int finBoucleLvl1 = 0;
int finBoucleLvl2 = 0;
int finBoucleLvl3 = 0;
int finBoucleLvl4 = 0;
int finBoucleLvl5 = 0;
int quizzSpinx = 0;
int VoltrexEnfouissement = 0;
int BonChoixVoltrex = 0;
int newGamePlus = 0;
// =================   STATISTIQUES ALEATOIRES ***** SALLES *****   =====================
int pourcentageCombats  = 40;
int pourcentageCampDeRepos  = 3 ;
int pourcentageEsquallier = 7;
int pourcentageSalleVide = 100;
int pourcentageTresor = 3;
int pourcentageSalleChoix = 50;
int pourcentageSalleSubmerge = 50;
int pourcentagePiege = 60;
int maxsalleAuTresor = 0;
int maxCombat = 0;
int maxSubmerge = 0;
int miniBoss = 0;
// ====================   Variables Sauvegardes ======================

int initialisationSaves;
int SavesMonde;
int SavesLevel;
int savesPV;
int savesXp;
// ====================   Variables HUD ====================================================

int gold = 0;
int pointsDexperience = 0;
int NiveauActuel = 0;
int MondeActuel = 0;
char pseudo[10];
int inventaire = 0;

int bonusXP = 0;
int bonuxGOLD = 0;

int LevelAventurier = 0;

// =================   STATISTIQUES ALEATOIRES *****COMBATS*****   ================================
int pourcentageEsquive;
int pourcentageCoupsCritique;
int potionsRouge  = 0;
int SmokeBomb = 0;
int BoostPP = 0;
int petitclef = 0;

int RefletTimmer = 0;

// =================   STATISTIQUES ALEATOIRES ***** SALLES *****   ===============================

// ================ BOUTIQUE  ==============
int choixBoutique = 0;
int choixobjets = 0;
int change =0;
int ChoixEscallier;
int AmuletteEscallier = 0;
int etageMAX;


// =================   STATISTIQUES ALEATOIRES ***** MONSTRES *****   ===============================

int pourcentageGobelins = 100;
int pourcentageFantomes = 20;
int pourcentageSquelettes = 40 ;
int pourcentageSorcieres = 20;
int NombreDeSalles =0;

statistiques NihilismeDeLaDeceptions;

NihilismeDeLaDeceptions.armure = 1;
NihilismeDeLaDeceptions.attaque = 9;
NihilismeDeLaDeceptions.coupCritique = 50;
NihilismeDeLaDeceptions.esquive = 10;
NihilismeDeLaDeceptions.pointsDeVies = 17;
NihilismeDeLaDeceptions.fuite = 0;


int NihilismeDeLaDeception;



int ADNihilismeDeLaDeception = 9;
int ADBebeDragon = 20;
int ADZombie = 11;
int ADFourmillion = 7;


statistiques BebeDragons;

BebeDragons.armure =0;
BebeDragons.attaque = 20;
BebeDragons.coupCritique = 20;
BebeDragons.esquive = 10;
BebeDragons.pointsDeVies = 20;
BebeDragons.fuite = 0;

int BebeDragon;

statistiques Fourmillions;

Fourmillions.armure = 3;
Fourmillions.attaque = 7;
Fourmillions.coupCritique = 20;
Fourmillions.esquive = 10;
Fourmillions.pointsDeVies = 40;
Fourmillions.fuite = 0;

int Fourmillion;

statistiques Zombies;

Zombies.armure = 2;
Zombies.attaque = 11;
Zombies.coupCritique = 30;
Zombies.esquive = 15;
Zombies.pointsDeVies = 25;

int Zombie;

statistiques GnomeLepreuxx;

GnomeLepreuxx.armure = 3;
GnomeLepreuxx.attaque = 20;
GnomeLepreuxx.coupCritique = 50;
GnomeLepreuxx.esquive = 25;
GnomeLepreuxx.pointsDeVies = 100;

int ADGnomeLepreux = 20;
int GnomeLepreux;





statistiques Voltrexx;

Voltrexx.armure = 2;
Voltrexx.attaque = 15;
Voltrexx.coupCritique = 20;
Voltrexx.esquive = 10;
Voltrexx.pointsDeVies = 220;



int Voltrex = 0;
int VoltrexVaincu = 0;


// =================   STATISTIQUES ALEATOIRES Joueur SPELL / STATS   =====================


statistiques aventurier;
aventurier.armure = 0;
aventurier.coupCritique = 33;
aventurier.esquive = 10;
aventurier.attaque = 5;


int PPSort1= 10;
int PPSort2= 5;
int PPSort3= 3;




// ========================================================================= DEBUT DU PROGRAMME ======================================================================




// ========================================================================  INITIALISATION DES SAUVEGRADES   ========================================================================
fichier = fopen("Saves/InitSaves.txt","r");
fscanf(fichier,"%d",&initialisationSaves);
fclose(fichier);


if(initialisationSaves != 578){
fichier = fopen("Saves/SauvegardeLevel.txt","w+");
fputs("0 ",fichier);
rewind(fichier);
fscanf(fichier,"%d",&SavesLevel);




fichier = fopen("Saves/SauvegardeExperience.txt","w+");

fputs("0 ",fichier);
rewind(fichier);
fscanf(fichier,"%d",&savesXp);

fclose(fichier);


fichier = fopen("Saves/SauvegardeAttaqueDammage.txt","w+");
rewind(fichier);
fscanf(fichier,"%d",&savesXp);

fclose(fichier);

fichier = fopen("Saves/SauvegardePV.txt","w+");
fputs("50 ",fichier);
rewind(fichier);
fscanf(fichier,"%d",&savesPV);
fclose(fichier);



fichier = fopen("Saves/SauvegardeMonde.txt","w+");
fputs("0 ",fichier);
rewind(fichier);
fscanf(fichier,"%d",&SavesMonde);
fclose(fichier);



fichier = fopen("Saves/SauvegardePseudo.txt","w+");
rewind(fichier);
fclose(fichier);
fclose(fichier);



fichier = fopen("Saves/InitSaves.txt","a+");
fputs("578",fichier);
fclose(fichier);




fichier = fopen("Saves/SauvegardeGold.txt","w+");
fputs("0",fichier);
fclose(fichier);




fichier = fopen("Saves/SauvegardeNiveauAventurier.txt","w+");
fputs("0 ",fichier);
rewind(fichier);
fscanf(fichier,"%d",&LevelAventurier);

fclose(fichier);


}


fichier = fopen("Saves/NEWGAME+.txt","r");
rewind(fichier);
fscanf(fichier,"%d",&newGamePlus);

fichier = fopen("Saves/SauvegardeLevel.txt","r");
rewind(fichier);
fscanf(fichier,"%d",&NiveauActuel);
fichier = fopen("Saves/SauvegardeExperience.txt","r");
rewind(fichier);
fscanf(fichier,"%d",&pointsDexperience);


fichier = fopen("Saves/SauvegardePV.txt","r");
rewind(fichier);
fscanf(fichier,"%d",&aventurier.pointsDeVies);


fichier = fopen("Saves/SauvegardeMonde.txt","r");
rewind(fichier);
fscanf(fichier,"%d",&MondeActuel);

fichier = fopen("Saves/SauvegardePseudo.txt","r");
rewind(fichier);
fscanf(fichier,"%s",&pseudo);

fichier = fopen("Saves/SauvegardeGold.txt","r");
rewind(fichier);
fscanf(fichier,"%d",&gold);


fichier = fopen("Saves/SauvegardeNiveauAventurier.txt","r");

rewind(fichier);
fscanf(fichier,"%d",&LevelAventurier);


fclose(fichier);

fichier = fopen("Saves/SauvegardeAttaqueDammage.txt","r");
rewind(fichier);
fscanf(fichier,"%d",&aventurier.attaque);
fclose(fichier);

// ================ XP LVL stats BOOST ET MOBS =============================
if(MondeActuel == 2){
switch(NiveauActuel){

case 1 :
  BebeDragons.pointsDeVies = 20;
NihilismeDeLaDeceptions.pointsDeVies = 17;
Fourmillions.pointsDeVies = 40;
Zombies.pointsDeVies = 25;

 ADNihilismeDeLaDeception = 9;
 ADBebeDragon = 20;
 ADZombie = 11;
 ADFourmillion = 7;
break;

case 2 :

BebeDragons.pointsDeVies = 20;
NihilismeDeLaDeceptions.pointsDeVies = 17;
Fourmillions.pointsDeVies = 40;
Zombies.pointsDeVies = 25;

 ADNihilismeDeLaDeception = 9;
 ADBebeDragon = 20;
 ADZombie = 11;
 ADFourmillion = 7;

break;


case 3 :

    BebeDragons.pointsDeVies = 25;
NihilismeDeLaDeceptions.pointsDeVies = 20;
Fourmillions.pointsDeVies = 45;
Zombies.pointsDeVies = 27;

 ADNihilismeDeLaDeception = 11;
 ADBebeDragon = 22;
 ADZombie = 14;
 ADFourmillion = 9;

break;

case 4 :

    BebeDragons.pointsDeVies = 25;
NihilismeDeLaDeceptions.pointsDeVies = 20;
Fourmillions.pointsDeVies = 45;
Zombies.pointsDeVies = 28;

 ADNihilismeDeLaDeception = 11;
 ADBebeDragon = 22;
 ADZombie = 14;
 ADFourmillion = 9;

break;

case 5 :

    BebeDragons.pointsDeVies = 25;
NihilismeDeLaDeceptions.pointsDeVies = 20;
Fourmillions.pointsDeVies = 45;
Zombies.pointsDeVies = 28;

 ADNihilismeDeLaDeception = 13;
 ADBebeDragon = 25;
 ADZombie = 15;
 ADFourmillion = 10;

break;


}
}

// ====================== NEW GAME PLUS  ======================
// ====================== NEW GAME PLUS  ======================
// ====================== NEW GAME PLUS  ======================
// ====================== NEW GAME PLUS  ======================
// ====================== NEW GAME PLUS  ======================
if(newGamePlus == 84464841){
MondeActuel = 2;

printf("\n\n\n          Bienvenue au NEW GAME + ! ici vous pouvez vous teleporter a n'importe quel moment de votre aventure\n           dans la Dry-Dry Toundra et dans l'Avenue des dechus");
printf("\n           Se teleporter a un moment precis de l'aventure ?\n 1 : OUI\n 2 : NON");
scanf("%d",&xanogene);
if(xanogene == 1){
    printf("\n\n\n        Tres bien !  Quel moment voulez vous revivre ? ");
    printf("\n 0 : Introduction");
    printf("\n 1 : Donjons 1 ");
    printf("\n 2 : Donjons 2 ");
    printf("\n 3 : Donjons 3 ");
    printf("\n 4 : Donjons 4 ");
    printf("\n 5 : BOSS VOLTREX ");
    scanf("%d",&NiveauActuel);
}
}

// ++++++++++++++++++++ NEW GAME PLUS ++++++++++++++++++++
// ++++++++++++++++++++ NEW GAME PLUS ++++++++++++++++++++
// ++++++++++++++++++++ NEW GAME PLUS ++++++++++++++++++++
// ++++++++++++++++++++ NEW GAME PLUS ++++++++++++++++++++
// ++++++++++++++++++++ NEW GAME PLUS ++++++++++++++++++++


// ++++++++++++++++++++++++++++++++ XP LVL STATS BOOST ET MOBS ++++++++++++++++++++++

// ============================================= MONDE 2 NIVEAU 0    =================================
// ============================================= MONDE 2 NIVEAU 0    =================================
// ============================================= MONDE 2 NIVEAU 0    =================================
// ============================================= MONDE 2 NIVEAU 0    =================================
// ============================================= MONDE 2 NIVEAU 0    =================================
// ============================================= MONDE 2 NIVEAU 0    =================================
// ============================================= MONDE 2 NIVEAU 0    =================================
// ============================================= MONDE 2 NIVEAU 0    =================================
// ============================================= MONDE 2 NIVEAU 0    =================================

// ======================================================================== MONDE 2 INTRODUCTION ========================================================================
if( MondeActuel == 2 && NiveauActuel == 0 && finBoucleLvl0 == 0){

printf("\n          Toutes mes felicitations pour avoir vaincu LORDSOUPEX !!\n          Ce n'etait pas une mince a faire mais vous l'avez fait !\n          Bravo a vous !!\n          A present ! prennez vos chapeau et votre creme solaire car nous nous dirigeons\n          Vers la Dry-Dry Toundra");
printf("\n          Un grand desert plutot vide mais ou quelques donjons subsistent...\n          Les legendes racontent que Voltrex un immense ver des sables empecherait quiconque de s'approcher de son antre...\n          Brrr bon et bien ^^ bon courage hein ?!");

NiveauActuel++;
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   FIN MONDE 2 INTRODUCTION ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}







// ========================================= MONDE 2 => 5 ============================
// ========================================= MONDE 2 => 5 ============================
// ========================================= MONDE 2 => 5 ============================
// ========================================= MONDE 2 => 5 ============================
// ========================================= MONDE 2 => 5 ============================
// ========================================= MONDE 2 => 5 ============================
// ========================================= MONDE 2 => 5 ============================
// ========================================= MONDE 2 => 5 ============================
// ========================================= MONDE 2 => 5 ============================
// ========================================= MONDE 2 => 5 ============================


while(MondeActuel == 2 && NiveauActuel <= 5 && Voltrex ==0){







if(MondeActuel == 2 && NiveauActuel == 1 && finBoucleLvl1 == 0){


        // INITIALISATION DES COMBATS ==================
     BebeDragons.pointsDeVies = 20;
NihilismeDeLaDeceptions.pointsDeVies = 17;
Fourmillions.pointsDeVies = 40;
Zombies.pointsDeVies = 25;

 ADNihilismeDeLaDeception = 9;
 ADBebeDragon = 20;
 ADZombie = 11;
 ADFourmillion = 7;
   // INITIALISATION DES COMBATS ++++++++++++++++++++++



system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n          BIENVENUE dans le MONDE 2 AVENTURIER  !\n          Laissez moi vous presenter ce nouveau monde !!  ");
printf("CLAP CLAP....");

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("                        Voici le merveilleux monde de DEEPER WORLD\n\n\n\n");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--X---|                          X BOSS X             |     ");
printf("\n     |     X --------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");
printf("\n\n\n          Bon nous voila au monde 2 les choses serieuses vont commencer...\n          Chaque X represente un donjon a affronter afin d'atteindre le boss et acceder au monde 2 !\n          Un donjon valide se transformera en O mais ca vous vous en souvenez !");
printf("\n          Au programme, nouveaux monstres, nouvelles salles, vos PV max ont augmente et vous gagnez 10 ad en plus ! Sans oublier  deux trois surprises que vous verrez bien :p");
aventurier.attaque = aventurier.attaque +10;
aventurier.pointsDeVies = 100;
printf("\n          Allez direction la boutique !\n           Allons voir si le marchand nous reserve des surprises ! ");


// ========================================== =====================   FIN DES DONJONS     ====================== ===============================================================
// ===============================  SELECTIONNER CAPACITE ===============================

// ++++++++++++++ SELECTIONNER CAPACITE +++++++++++++++++++++
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n     Bienvenu a la boutique ! Ici vous pouvez acheter ce que vous voulez tant que vous en avez les moyens !  \n\n\n\n");


printf("\n     ******************************************************************************      ");
printf("\n     |    ___    ______________________________________                           |     ");
printf("\n     |   |'o'|< |  Quelle bonne surprise,encore vous ! |   |**************|       |     ");
printf("\n     |   /||\\   | La boutique a un peu change regardez |   | Petite clef  |       |     ");
printf("\n     |    /\\    |  Bien... dsl pour l'inflation :c     |   |**************|       |     ");
printf("\n     |          |______________________________________|         50G(4)           |     ");
printf("\n     |                                                                            |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |         | Potion rouge |      |  Smoke Bomb  |      |   Boost PP   |       |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |               10G(1)                20G(2)                 35G(3)          |     ");
printf("\n     ******************************************************************************      ");




printf("\n          Alors ? Faire chauffer la carte bleu ?\n 1 : OUI\n 2 : NON ");

scanf("%d",&choix5);
if(choix5 == 2){
    printf("\n\n          Avec la crise du corona les temps sont dures...\n          Alors vous vous dirigez vers le donjons sans rien acheter");
}
while(choix5 == 1){
if(choix5 == 1){

 printf("\n\n          Tres bien ! que voulez vous acheter ?\n 1 : Potion rouge\n 2 : Smoke Bomb\n 3 : Boost PP\n 4 : Petit Clef\n 5 : Heuu j'ai change d'avis");
 scanf("%d",&choixobjets);

 switch(choixobjets){
case 1 : printf("\n\n\n          Potion rouge ! pour 10 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
}
if(choix4 == 1){
    change = gold -10;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 10;
        potionsRouge++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 2 : printf("\n\n\n          Smoke Bomb ! pour 20 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -20;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 20;
        SmokeBomb++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 3 : printf("\n\n\n          Boost PP ! pour 35 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -35;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 35;
        BoostPP++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 4 : printf("\n\n\n          Une petite clef : (un objet permettant d'ouvrir des coffres du desert !) pour 50 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

   printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -50;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 50;
        petitclef++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

// ======================================== ========================================    CHANGEMENT DE CHOIX   ============================================ ======================================== ======================================== ========================================
case 5 :
    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
 // SWITCH ACHETER
}
 // SI TU ACHETES OUI
}


// ===================================================  LVL 0 --> 1   ============



finBoucleLvl1++;
// ++++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 0    ++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 0    ++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 0    ++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 0    ++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 0    ++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 0    ++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 0    ++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 0    ++++++++++++++++++++++++++++++

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("                        Voici le merveilleux monde de DEEPER WORLD\n\n\n\n");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--X---|                          X BOSS X             |     ");
printf("\n     |    [O]--------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

printf("\n          Niveau actuel : %d",NiveauActuel);
printf("\n          Vous vous appretez a rentrer dans un donjon ! ");

}





// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================
// ============================ MONDE 1 NIVEAU 2 =========================

if(MondeActuel == 2 && NiveauActuel == 2 && finBoucleLvl2 == 0){


        // INITIALISATION DES COMBATS ==================
     BebeDragons.pointsDeVies = 20;
NihilismeDeLaDeceptions.pointsDeVies = 17;
Fourmillions.pointsDeVies = 40;
Zombies.pointsDeVies = 25;

 ADNihilismeDeLaDeception = 9;
 ADBebeDragon = 20;
 ADZombie = 11;
 ADFourmillion = 7;
   // INITIALISATION DES COMBATS ++++++++++++++++++++++


    etageActuel = 0;

        printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n     Bienvenu a la boutique ! Ici vous pouvez acheter ce que vous voulez tant que vous en avez les moyens !  \n\n\n\n");


printf("\n     ******************************************************************************      ");
printf("\n     |    ___    ______________________________________                           |     ");
printf("\n     |   |'o'|< |  Alors ce premier donjon bien passe ?|   |**************|       |     ");
printf("\n     |   /||\\   | Trifoullez ! il y a forcement quelque|   | Petite clef  |       |     ");
printf("\n     |    /\\    |  chose qui va vous plaire :)         |   |**************|       |     ");
printf("\n     |          |______________________________________|         50G(4)           |     ");
printf("\n     |                                                                            |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |         | Potion rouge |      |  Smoke Bomb  |      |   Boost PP   |       |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |               10G(1)                20G(2)                 35G(3)          |     ");
printf("\n     ******************************************************************************      ");




printf("\n          Alors ? Faire chauffer la carte bleu ?\n 1 : OUI\n 2 : NON ");

scanf("%d",&choix5);
if(choix5 == 2){
    printf("\n\n          Avec la crise du corona les temps sont dures...\n          Alors vous vous dirigez vers le donjons sans rien acheter");
}
while(choix5 == 1){
if(choix5 == 1){

 printf("\n\n          Tres bien ! que voulez vous acheter ?\n 1 : Potion rouge\n 2 : Smoke Bomb\n 3 : Boost PP\n 4 : Petit Clef\n 5 : Heuu j'ai change d'avis");
 scanf("%d",&choixobjets);

 switch(choixobjets){
case 1 : printf("\n\n\n          Potion rouge ! pour 10 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
}
if(choix4 == 1){
    change = gold -10;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 10;
        potionsRouge++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 2 : printf("\n\n\n          Smoke Bomb ! pour 20 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -20;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 20;
        SmokeBomb++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 3 : printf("\n\n\n          Boost PP ! pour 35 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -35;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 35;
        BoostPP++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 4 : printf("\n\n\n          Une petite clef : (un objet permettant d'ouvrir des coffres du desert !) pour 50 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

   printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -50;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 50;
        petitclef++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

// ======================================== ========================================    CHANGEMENT DE CHOIX   ============================================ ======================================== ======================================== ========================================
case 5 :
    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
 // SWITCH ACHETER
}
 // SI TU ACHETES OUI
}

printf("\n/\\");
scanf("%d",&xanogene);


printf("\n          En direction du second donjon...\n\n\n\n");
// ==============================================     DEBUT DU NIVEAU 2 ==============================================================================================







system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--X---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--X---|                          X BOSS X             |     ");
printf("\n     |     O<<-------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--X---|                          X BOSS X             |     ");
printf("\n     |     O<<<<-----|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--X---|                          X BOSS X             |     ");
printf("\n     |     O<<<<<<---|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--X---|                          X BOSS X             |     ");
printf("\n     |     O<<<<<<<<<#                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               #-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         #     |--X---|                          X BOSS X             |     ");
printf("\n     |     O<<<<<<<<<#                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               #<<---|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         #     |--X---|                          X BOSS X             |     ");
printf("\n     |     O<<<<<<<<<#                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               #<<<<-|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         #     |--X---|                          X BOSS X             |     ");
printf("\n     |     O<<<<<<<<<#                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               #<<<<<#  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         #     |--X---|                          X BOSS X             |     ");
printf("\n     |     O<<<<<<<<<#                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");


system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               #<<<<<#  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         #     #<-X---|                          X BOSS X             |     ");
printf("\n     |     O<<<<<<<<<#                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");


system("cls");
printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|---|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               #<<<<<#  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         #     #<[O]--|                          X BOSS X             |     ");
printf("\n     |     O<<<<<<<<<#                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");
printf("\n          Niveau actuel : %d",NiveauActuel);
printf("\n          Vous vous appretez a rentrer dans un donjon ! ");


finBoucleLvl2++;
}
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 2 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++




// =================================== MONDE 1 NIVEAU 3 ======================================================
// =================================== MONDE 1 NIVEAU 3 ======================================================
// =================================== MONDE 1 NIVEAU 3 ======================================================
// =================================== MONDE 1 NIVEAU 3 ======================================================
// =================================== MONDE 1 NIVEAU 3 ======================================================
// =================================== MONDE 1 NIVEAU 3 ======================================================
// =================================== MONDE 1 NIVEAU 3 ======================================================
// =================================== MONDE 1 NIVEAU 3 ======================================================
// =================================== MONDE 1 NIVEAU 3 ======================================================
// =================================== MONDE 1 NIVEAU 3 ======================================================




if(MondeActuel == 2 && NiveauActuel == 3 && finBoucleLvl3 == 0){


        // INITIALISATION DES COMBATS ==================
     BebeDragons.pointsDeVies = 25;
NihilismeDeLaDeceptions.pointsDeVies = 20;
Fourmillions.pointsDeVies = 45;
Zombies.pointsDeVies = 27;

 ADNihilismeDeLaDeception = 11;
 ADBebeDragon = 22;
 ADZombie = 14;
 ADFourmillion = 9;
   // INITIALISATION DES COMBATS ++++++++++++++++++++++


    etageActuel = 0;
finBoucleLvl3++;
        printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n     Bienvenu a la boutique ! Ici vous pouvez acheter ce que vous voulez tant que vous en avez les moyens !  \n\n\n\n");


printf("\n     ******************************************************************************      ");
printf("\n     |    ___    ______________________________________                           |     ");
printf("\n     |   |'o'|< |  DONNEZ DO DO DONNEZ DONNEZ MOI!     |   |**************|       |     ");
printf("\n     |   /||\\   | VOTRE MOULAGA  !!!!!                 |   | Petite clef  |       |     ");
printf("\n     |    /\\    | ca sonnait plus drole dans ma tete...|   |**************|       |     ");
printf("\n     |          |______________________________________|         50G(4)           |     ");
printf("\n     |                                                                            |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |         | Potion rouge |      |  Smoke Bomb  |      |   Boost PP   |       |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |               10G(1)                20G(2)                 35G(3)          |     ");
printf("\n     ******************************************************************************      ");




printf("\n          Alors ? Faire chauffer la carte bleu ?\n 1 : OUI\n 2 : NON ");

scanf("%d",&choix5);
if(choix5 == 2){
    printf("\n\n          Avec la crise du corona les temps sont dures...\n          Alors vous vous dirigez vers le donjons sans rien acheter");
}
while(choix5 == 1){
if(choix5 == 1){

 printf("\n\n          Tres bien ! que voulez vous acheter ?\n 1 : Potion rouge\n 2 : Smoke Bomb\n 3 : Boost PP\n 4 : Petit Clef\n 5 : Heuu j'ai change d'avis");
 scanf("%d",&choixobjets);

 switch(choixobjets){
case 1 : printf("\n\n\n          Potion rouge ! pour 10 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
}
if(choix4 == 1){
    change = gold -10;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 10;
        potionsRouge++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 2 : printf("\n\n\n          Smoke Bomb ! pour 20 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -20;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 20;
        SmokeBomb++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 3 : printf("\n\n\n          Boost PP ! pour 35 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -35;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 35;
        BoostPP++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 4 : printf("\n\n\n          Une petite clef : (un objet permettant d'ouvrir des coffres du desert !) pour 50 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

   printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -50;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 50;
        petitclef++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

// ======================================== ========================================    CHANGEMENT DE CHOIX   ============================================ ======================================== ======================================== ========================================
case 5 :
    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
 // SWITCH ACHETER
}
 // SI TU ACHETES OUI
}

printf("\n/\\");
scanf("%d",&xanogene);


printf("\n          En direction du troisieme donjon...\n\n\n\n");
// ==============================================     DEBUT DU NIVEAU 2 ==============================================================================================








system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|----|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|----|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O<<-|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|----|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O<<<#                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|----|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            #    |/                        |                |     ");
printf("\n     |               |-----|  2   #                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O<<<#                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|----#     |  /-------X---/          |                |     ");
printf("\n     |                            #    | /                       |                |     ");
printf("\n     |                            #    |/                        |                |     ");
printf("\n     |               |-----|  2   #                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O<<<#                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|-->>#     |  /-------X---/          |                |     ");
printf("\n     |                            #    | /                       |                |     ");
printf("\n     |                            #    |/                        |                |     ");
printf("\n     |               |-----|  2   #                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O<<<#                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X----|>>>>#     |  /-------X---/          |                |     ");
printf("\n     |                            #    | /                       |                |     ");
printf("\n     |                            #    |/                        |                |     ");
printf("\n     |               |-----|  2   #                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O<<<#                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X--->>>>>>#     |  /-------X---/          |                |     ");
printf("\n     |                            #    | /                       |                |     ");
printf("\n     |                            #    |/                        |                |     ");
printf("\n     |               |-----|  2   #                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O<<<#                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  X->>>>>>>>#     |  /-------X---/          |                |     ");
printf("\n     |                            #    | /                       |                |     ");
printf("\n     |                            #    |/                        |                |     ");
printf("\n     |               |-----|  2   #                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O<<<#                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                 [O]>>>>>>>>#     |  /-------X---/          |                |     ");
printf("\n     |                            #    | /                       |                |     ");
printf("\n     |                            #    |/                        |                |     ");
printf("\n     |               |-----|  2   #                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O<<<#                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");
printf("\n          Niveau actuel : %d",NiveauActuel);
printf("\n          Vous vous appretez a rentrer dans un donjon ! ");

}

// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 3 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++










// =============================== MONDE 1 NIVEAU 4 ====================================================
// =============================== MONDE 1 NIVEAU 4 ====================================================
// =============================== MONDE 1 NIVEAU 4 ====================================================
// =============================== MONDE 1 NIVEAU 4 ====================================================
// =============================== MONDE 1 NIVEAU 4 ====================================================
// =============================== MONDE 1 NIVEAU 4 ====================================================
// =============================== MONDE 1 NIVEAU 4 ====================================================
// =============================== MONDE 1 NIVEAU 4 ====================================================
// =============================== MONDE 1 NIVEAU 4 ====================================================




if(MondeActuel == 2 && NiveauActuel == 4 && finBoucleLvl4 ==0){
    etageActuel = 0;



    // INITIALISATION DES COMBATS ==================
     BebeDragons.pointsDeVies = 25;
NihilismeDeLaDeceptions.pointsDeVies = 20;
Fourmillions.pointsDeVies = 45;
Zombies.pointsDeVies = 28;

 ADNihilismeDeLaDeception = 11;
 ADBebeDragon = 22;
 ADZombie = 14;
 ADFourmillion = 9;
   // INITIALISATION DES COMBATS ++++++++++++++++++++++


finBoucleLvl4++;
       printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n     Bienvenu a la boutique ! Ici vous pouvez acheter ce que vous voulez tant que vous en avez les moyens !  \n\n\n\n");


printf("\n     ******************************************************************************      ");
printf("\n     |    ___    ______________________________________                           |     ");
printf("\n     |   |'o'|< |  Haaan... hein..Hna hna              |   |**************|       |     ");
printf("\n     |   /||\\   | *villageois dans minecraft haha...   |   | Petite clef  |       |     ");
printf("\n     |    /\\    | Bon... achetez et cassez vous pfff   |   |**************|       |     ");
printf("\n     |          |______________________________________|         50G(4)           |     ");
printf("\n     |                                                                            |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |         | Potion rouge |      |  Smoke Bomb  |      |   Boost PP   |       |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |               10G(1)                20G(2)                 35G(3)          |     ");
printf("\n     ******************************************************************************      ");




printf("\n          Alors ? Faire chauffer la carte bleu ?\n 1 : OUI\n 2 : NON ");

scanf("%d",&choix5);
if(choix5 == 2){
    printf("\n\n          Avec la crise du corona les temps sont dures...\n          Alors vous vous dirigez vers le donjons sans rien acheter");
}
while(choix5 == 1){
if(choix5 == 1){

 printf("\n\n          Tres bien ! que voulez vous acheter ?\n 1 : Potion rouge\n 2 : Smoke Bomb\n 3 : Boost PP\n 4 : Petit Clef\n 5 : Heuu j'ai change d'avis");
 scanf("%d",&choixobjets);

 switch(choixobjets){
case 1 : printf("\n\n\n          Potion rouge ! pour 10 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
}
if(choix4 == 1){
    change = gold -10;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 10;
        potionsRouge++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 2 : printf("\n\n\n          Smoke Bomb ! pour 20 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -20;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 20;
        SmokeBomb++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 3 : printf("\n\n\n          Boost PP ! pour 35 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -35;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 35;
        BoostPP++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 4 : printf("\n\n\n          Une petite clef : (un objet permettant d'ouvrir des coffres du desert !) pour 50 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

   printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -50;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 50;
        petitclef++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

// ======================================== ========================================    CHANGEMENT DE CHOIX   ============================================ ======================================== ======================================== ========================================
case 5 :
    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
 // SWITCH ACHETER
}
 // SI TU ACHETES OUI
}

printf("\n/\\");
scanf("%d",&xanogene);


printf("\n          En direction du quatrieme donjon...\n\n\n\n");
// ==============================================     DEBUT DU NIVEAU 2 ==============================================================================================










system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  O----|----|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  O<<-|----|     |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<------|          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<----|          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<<<--|          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<<<<<|          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    |  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<<<<<#          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    #  /-------X---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<<<<<#          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    #  /-------X---/          |                |     ");
printf("\n     |                            |    # /                       |                |     ");
printf("\n     |                            |    #/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<<<<<#          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    #  /-------X---/          |                |     ");
printf("\n     |                            |    # #                       |                |     ");
printf("\n     |                            |    ##                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<<<<<#          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    #  #<------X---/          |                |     ");
printf("\n     |                            |    # #                       |                |     ");
printf("\n     |                            |    ##                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<<<<<#          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    #  #<<<----X---/          |                |     ");
printf("\n     |                            |    # #                       |                |     ");
printf("\n     |                            |    ##                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<<<<<#          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    #  #<<<<<--X---/          |                |     ");
printf("\n     |                            |    # #                       |                |     ");
printf("\n     |                            |    ##                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<<<<<#          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    #  #<<<<<<<X---/          |                |     ");
printf("\n     |                            |    # #                       |                |     ");
printf("\n     |                            |    ##                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     #<<<<<<<<#          4    /---------|                |     ");
printf("\n     |                  O<<<<#----|    #  #<<<<<<[O]---/         |               |     ");
printf("\n     |                            |    # #                       |                |     ");
printf("\n     |                            |    ##                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");
printf("\n          Niveau actuel : %d",NiveauActuel);
printf("\n          Vous vous appretez a rentrer dans un donjon ! ");
}
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 4 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++




// ================================ MONDE 1 NIVEAU  5 ================================
// ================================ MONDE 1 NIVEAU  5 ================================
// ================================ MONDE 1 NIVEAU  5 ================================
// ================================ MONDE 1 NIVEAU  5 ================================
// ================================ MONDE 1 NIVEAU  5 ================================
// ================================ MONDE 1 NIVEAU  5 ================================
// ================================ MONDE 1 NIVEAU  5 ================================



if(MondeActuel == 2 && NiveauActuel == 5 && finBoucleLvl5 == 0){
    etageActuel = 0;



    // INITIALISATION DES COMBATS ==================
    BebeDragons.pointsDeVies = 25;
NihilismeDeLaDeceptions.pointsDeVies = 20;
Fourmillions.pointsDeVies = 45;
Zombies.pointsDeVies = 28;

 ADNihilismeDeLaDeception = 13;
 ADBebeDragon = 25;
 ADZombie = 15;
 ADFourmillion = 10;
   // INITIALISATION DES COMBATS ++++++++++++++++++++++



finBoucleLvl5++;
               printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n     Bienvenu a la boutique ! Ici vous pouvez acheter ce que vous voulez tant que vous en avez les moyens !  \n\n\n\n");


printf("\n     ******************************************************************************      ");
printf("\n     |    ___    ______________________________________                           |     ");
printf("\n     |   |'o'|< |  C'est deja le dernier donjon !      |   |**************|       |     ");
printf("\n     |   /||\\   | Le temps passe si vite dis donc !    |   | Petite clef  |       |     ");
printf("\n     |    /\\    | je vais brader une nouvelle fois !   |   |**************|       |     ");
printf("\n     |          |______________________________________|         0G(4)           |     ");
printf("\n     |                                                                            |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |         | Potion rouge |      |  Smoke Bomb  |      |   Boost PP   |       |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |               8G(1)                15G(2)                 30G(3)          |     ");
printf("\n     ******************************************************************************      ");




printf("\n          Alors ? Faire chauffer la carte bleu ?\n 1 : OUI\n 2 : NON ");

scanf("%d",&choix5);
if(choix5 == 2){
    printf("\n\n          Avec la crise du corona les temps sont dures...\n          Alors vous vous dirigez vers le donjons sans rien acheter");
}
while(choix5 == 1){
if(choix5 == 1){

 printf("\n\n          Tres bien ! que voulez vous acheter ?\n 1 : Potion rouge\n 2 : Smoke Bomb\n 3 : Boost PP\n 4 : Petit Clef\n 5 : Heuu j'ai change d'avis");
 scanf("%d",&choixobjets);

 switch(choixobjets){
case 1 : printf("\n\n\n          Potion rouge ! pour 8 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
}
if(choix4 == 1){
    change = gold -8;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 8;
        potionsRouge++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 2 : printf("\n\n\n          Smoke Bomb ! pour 15 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -15;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 15;
        SmokeBomb++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 3 : printf("\n\n\n          Boost PP ! pour 30 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -30;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 30;
        BoostPP++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 4 : printf("\n\n\n          Une petite clef : (un objet permettant d'ouvrir des coffres du desert !) pour 0 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

   printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -0;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 0;
        petitclef++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

// ======================================== ========================================    CHANGEMENT DE CHOIX   ============================================ ======================================== ======================================== ========================================
case 5 :
    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
 // SWITCH ACHETER
}
 // SI TU ACHETES OUI
}


printf("\n/\\");
scanf("%d",&xanogene);


printf("\n          En direction du donjon de BOSS...\n\n\n\n");
// ==============================================     DEBUT DU NIVEAU 5 ==============================================================================================










system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  O----|----|    |  /-------O---/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  O----|----|    |  /-------O<<-/          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    /---------|                |     ");
printf("\n     |                  O----|----|    |  /-------O<<<#          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    #<--------|                |     ");
printf("\n     |                  O----|----|    |  /-------O<<<#          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    #<<<------|                |     ");
printf("\n     |                  O----|----|    |  /-------O<<<#          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    #<<<<<<---|                |     ");
printf("\n     |                  O----|----|    |  /-------O<<<#          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    #<<<<<<<<-|                |     ");
printf("\n     |                  O----|----|    |  /-------O<<<#          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    #<<<<<<<<<#                |     ");
printf("\n     |                  O----|----|    |  /-------O<<<#          |                |     ");
printf("\n     |                            |    | /                       |                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");

system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    #<<<<<<<<<#                |     ");
printf("\n     |                  O----|----|    |  /-------O<<<#          #                |     ");
printf("\n     |                            |    | /                       #                |     ");
printf("\n     |                            |    |/                        |                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X BOSS X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");


system("cls");

printf("\n     ******************************************************************************      ");
printf("\n     |                              Monde 2 : Dry-Dry Toundra                     |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                  3     /--------|          4    #<<<<<<<<<#                |     ");
printf("\n     |                  O----|----|    |  /-------O<<<#          #                |     ");
printf("\n     |                            |    | /                       #                |     ");
printf("\n     |                            |    |/                        #                |     ");
printf("\n     |               |-----|  2   |                          XXXXXXXX             |     ");
printf("\n     |     1         |     |--O---|                          X[BOSS]X             |     ");
printf("\n     |     O---------|                                       XXXXXXXX             |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************      ");
printf("\n          Niveau actuel : %d",NiveauActuel);
printf("\n          Vous vous appretez a rentrer dans un donjon DE BOSS ! ");
}
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ MONDE 1 NIVEAU 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++












// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ FILLER
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ FILLER
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ FILLER
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ FILLER
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ FILLER
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ FILLER
















// =============== DEBUT VRAI DONJON ==============================================
// =============== DEBUT VRAI DONJON ==============================================
// =============== DEBUT VRAI DONJON ==============================================
// =============== DEBUT VRAI DONJON ==============================================
// =============== DEBUT VRAI DONJON ==============================================
// =============== DEBUT VRAI DONJON ==============================================

printf("\n\n\n               Vous entrez enfin dans le donjons !\n               Monde %d / niveau %d",MondeActuel,NiveauActuel);
printf("\n               Vous ouvrez la porte du Donjon");
printf("\n               Vous apercevez la premiere salle dans une humidite degoutante... le sable tombe des murs lentement.");
printf("\n               Etage actuel : %d",etageActuel);
printf("\n/\\");
scanf("%d",&xanogene);


srand(time(NULL));
 nombreRandome = rand() % 2;

 etageMAX = nombreRandome;
 etageMAX = etageMAX +2;



// NOMBRE DE LVL
printf("\n         *******************************");
printf("\n          Ce donjon possede %d etages ! ",etageMAX);
printf("\n         *******************************");
// NOMBRE DE LVL



while(aventurier.pointsDeVies > 0 && etageActuel < etageMAX){



// ================   CHANGEMENT DETAGE  ==============
if(etageActuel == 1 && c == 0){

    AmuletteEscallier = 0;
    c++;
}
if(etageActuel == 3 && d == 0 || etageActuel == 0 && e ==0){
    AmuletteEscallier = 0;
    d++;
        e++;
}
if(etageActuel == 2 && b==0){

            printf("\n*******************************************************************\n*******************************************************************\n*******************************************************************");
        printf("\n\n\n\n\n             Vous sortez la tete de l'escalier lentemant les murs de sables pouraient s'effondrer au moindre frolement\n             Vous continuez a travers ce dedalle sablonneux !");
        printf("\n             Etage actuel : %d",etageActuel);
        printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
AmuletteEscallier = 0;
    b++;
    Fourmillions.pointsDeVies = Fourmillions.pointsDeVies*1.5;
    Zombies.pointsDeVies = Zombies.pointsDeVies*1.5;
    BebeDragons.pointsDeVies = BebeDragons.pointsDeVies*1.5;
    NihilismeDeLaDeceptions.pointsDeVies = NihilismeDeLaDeceptions.pointsDeVies*1.5;
}

if(aventurier.pointsDeVies <= 0){
        for(i = 0 ; i<1500; i++){
            printf("§//010//1001 011101  0101001011  01//\\ //\\/  /\\//\\//\\//\\//\\");
        }
        system("cls");
        printf("\n             Vos yeux se plissent quant tout a coup la lumiere apparait, vous venez de mourir dans d'atroces souffrance\n             Enfin... maintenant vous ne sentez rien car c'est finit mais je vous jure que c'etait\n             écoeurant a voir...");
    printf("\n             ****************   GAME OVER   ****************\n             Vous n'avez malheursement pas survecu a ce donjon...\n             Il ne vous reste plus qua fermer le jeu et le rouvrir\n             Afin de recommencer a la derniere sauvegarde ! ");
    exit(1);
pointsDexperience = 0;
    gold = gold -10;
    aventurier.pointsDeVies = 50;

}

// +++++++++++++++++++ CHANGEMENT ETAGE 2 ++++++++++++++++++


// ============================SWITCH DES SALLES PAS TOUCHE GIGA IMPORTANT ============================================
// ============================SWITCH DES SALLES PAS TOUCHE GIGA IMPORTANT ============================================
// ============================SWITCH DES SALLES PAS TOUCHE GIGA IMPORTANT ============================================
// ============================SWITCH DES SALLES PAS TOUCHE GIGA IMPORTANT ============================================
// ============================SWITCH DES SALLES PAS TOUCHE GIGA IMPORTANT ============================================
// ============================SWITCH DES SALLES PAS TOUCHE GIGA IMPORTANT ============================================
// ============================SWITCH DES SALLES PAS TOUCHE GIGA IMPORTANT ============================================
// ============================SWITCH DES SALLES PAS TOUCHE GIGA IMPORTANT ============================================
// ============================SWITCH DES SALLES PAS TOUCHE GIGA IMPORTANT ============================================
// ============================SWITCH DES SALLES PAS TOUCHE GIGA IMPORTANT ============================================

srand(time(NULL));
nombreRandome = rand() % 30;

switch(nombreRandome){
// ========================== SALLE AU TRESOR ================================
// ========================== SALLE AU TRESOR ================================


case 1 :




    if( maxsalleAuTresor == 0){

 printf("\n            WOAAWW vous tombez nez a nez avec un immense coffre au tresor ! \n            il est ecrit : Celui qui osera m'ouvrir sera couvert d'or et de flammes !");
 printf("\n            Cela pourrait etre un piege ou alors une opportunite a ne pas manquer... que faire, l'ouvrir ? :\n1 : OUI\n2 : NON");
 scanf("%d",&ouvrirCoffre);
 if(ouvrirCoffre == 2){
    printf("\n            Par prudence ou par lachete, vous continuez votre route dans la salle suivante");
    NombreDeSalles++;
    ouvrirCoffre = 0;
    pourcentageEsquallier = pourcentageEsquallier *1.5;
 }
 if(ouvrirCoffre == 1){

     srand(time(NULL));
     nombreRandome = rand() % 10;

    printf("\n            Vous ouvrez le coffre");



    // UNLUCKY
    if(nombreRandome <= 2 ){

            switch(nombreRandome){
                case 0 :
        aventurier.pointsDeVies = aventurier.pointsDeVies *0.7;
        printf("\n            Le malheur s'abbat sur vous et les flammes recouvrent les murs !\n            vous ressentez la puissance de la RNG foireuse vous submerger et vous perdez 10 pourcent de vos PV\nPoints de vie : %d",aventurier.pointsDeVies);
      printf("\n/\\");
scanf("%d",&xanogene);
      break;
      case 1 : printf("\n          Soudain... des milliers de rats apparaissent de partout a travers les trous des murs\n          Vous etes terrorise et partez en courant...\n          Cependant sur le chemin vous perdez une potion de soin");
      potionsRouge--;
      printf("\n          potion rouge : %d",potionsRouge);
      break;

      case 2 : printf("\n          Un gnome lepreux apparait et il veut faire un jet de butin\n          Vous perdez votre mise et par consequent 5 Golds...");
      gold = gold -5;
      printf("\n         Vous devienne fou ?\n1 : OUI\n2 : NON");
      scanf("%d",&choix1);

      if(choix1 == 1){




        printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
GnomeLepreuxx.attaque = ADGnomeLepreux;
GnomeLepreux = GnomeLepreuxx.pointsDeVies;
// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
system("cls");
        printf("'PAS DE CA AVEC MOI S'en est TROP' VOUS NE FUIREZ PAS CE COMBAT *SLURP*");

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && GnomeLepreux > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du GnomeLepreux : %d",GnomeLepreux);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque+3 - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le GnomeLepreux aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque+15 - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(GnomeLepreux >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le GnomeLepreux repond a vous tirant des pieces dessus  ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du GnomeLepreux");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = GnomeLepreuxx.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= GnomeLepreuxx.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}










}


// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
}
printf("\n       ARRETEZ ARRETEZ ARRETEZ C'EST BON TENEZ VOICI VOS PIECE PFFFF");
gold = gold +50;
printf("\n       Gold +50\n gold : %d",gold);


      break;



    // SWITCH
    }
    // UNLUCKY
    }

// LUCKY

    if(nombreRandome >2){

       srand(time(NULL));
     nombreRandome = rand() % 4;

switch(nombreRandome){


       case 0 :



        printf("\n            Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n          Une potion tombe du ciel ! vous venez de recevoir une potion de soin supplementaire\n          Quelle chance !");
       potionsRouge++;
       printf("\n          potion rouge : %d",potionsRouge);
       printf("\n            Vous continuez votre route dans la salle suivante");
    printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);       break;

       case 1 : aventurier.attaque = aventurier.attaque + 4;
       printf("\n            Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n            Votre attaque a vu sa puissance augmenter !\nattaque : %d",aventurier.attaque);
       printf("\n            Vous continuez votre route dans la salle suivante");
          printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

       break;

       case 4 :
           printf("\n            Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n          Une grenade fumigene tombe du ciel ! Heuresement elle n'est pas degouippilé\n          Quelle chance !");
       SmokeBomb++;
       printf("\n          smoke Bomb : %d",SmokeBomb);
       printf("\n            Vous continuez votre route dans la salle suivante");


       break;

       case 3 : PPSort1 = 10; PPSort2 = 5; PPSort3 = 3;

       printf("\n          Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n          Vous sentez une odeur etrange..\n          Peu importe ce que c'est mais vous vous sentez mieux !\n          Vous recuperez tous vos PP\n Sort 1 : %d\n Sort 2 : %d\n Sort 3 : %d",PPSort1,PPSort2,PPSort3);
       printf("\n            Vous continuez votre route dans la salle suivante");
          printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);       break;

       case 2 : aventurier.pointsDeVies = aventurier.pointsDeVies + 50;
       MAXIMUM(aventurier.pointsDeVies,200);
       printf("\n            Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n            Vos etes frais comme un gardon et vous sentez votre energie vitale couler en vous \nPoints de vie: %d ",aventurier.pointsDeVies);
       printf("\n            Vous continuez votre route dans la salle suivante");
       printf("\n/\\");
scanf("%d",&xanogene);
       break;}
       // FIN DU SWITCH
}

ouvrirCoffre = 0;
NombreDeSalles++;
pourcentageEsquallier = pourcentageEsquallier *1.5;
}
// OUVRIR COFFRE OUI
if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");}
// FIN AMULETTE
}

 printf("\n/\\");
scanf("%d",&xanogene);
maxsalleAuTresor++;
NombreDeSalles++;
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
}
srand(time(NULL));
nombreRandome = rand() % 30;
break;

case 12 :





    if( maxsalleAuTresor == 0){

 printf("\n            WOAAWW vous tombez nez a nez avec un immense coffre au tresor ! \n            il est ecrit : Celui qui osera m'ouvrir sera couvert d'or et de flammes !");
 printf("\n            Cela pourrait etre un piege ou alors une opportunite a ne pas manquer... que faire, l'ouvrir ? :\n1 : OUI\n2 : NON");
 scanf("%d",&ouvrirCoffre);
 if(ouvrirCoffre == 2){
    printf("\n            Par prudence ou par lachete, vous continuez votre route dans la salle suivante");
    NombreDeSalles++;
    ouvrirCoffre = 0;
    pourcentageEsquallier = pourcentageEsquallier *1.5;
 }
 if(ouvrirCoffre == 1){

     srand(time(NULL));
     nombreRandome = rand() % 10;

    printf("\n            Vous ouvrez le coffre");



    // UNLUCKY
    if(nombreRandome <= 2 ){

            switch(nombreRandome){
                case 0 :
        aventurier.pointsDeVies = aventurier.pointsDeVies *0.7;
        printf("\n            Le malheur s'abbat sur vous et les flammes recouvrent les murs !\n            vous ressentez la puissance de la RNG foireuse vous submerger et vous perdez 10 pourcent de vos PV\nPoints de vie : %d",aventurier.pointsDeVies);
      printf("\n/\\");
scanf("%d",&xanogene);
      break;
      case 1 : printf("\n          Soudain... des milliers de rats apparaissent de partout a travers les trous des murs\n          Vous etes terrorise et partez en courant...\n          Cependant sur le chemin vous perdez une potion de soin");
      potionsRouge--;
      printf("\n          potion rouge : %d",potionsRouge);
      break;

      case 2 : printf("\n          Un gnome lepreux apparait et il veut faire un jet de butin\n          Vous perdez votre mise et par consequent 5 Golds...");
      gold = gold -5;
      printf("\n         Vous devienne fou ?\n1 : OUI\n2 : NON");
      scanf("%d",&choix1);

      if(choix1 == 1){




        printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
GnomeLepreuxx.attaque = ADGnomeLepreux;
GnomeLepreux = GnomeLepreuxx.pointsDeVies;
// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
system("cls");
        printf("'PAS DE CA AVEC MOI S'en est TROP' VOUS NE FUIREZ PAS CE COMBAT *SLURP*");

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && GnomeLepreux > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du GnomeLepreux : %d",GnomeLepreux);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque+3 - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le GnomeLepreux aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque+15 - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < GnomeLepreuxx.esquive){
    printf("\n              Le GnomeLepreux esquive votre attaque");
}

if(nombreRandome >= GnomeLepreuxx.esquive){
degatsInflige = aventurier.attaque - GnomeLepreuxx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

GnomeLepreux = GnomeLepreux - degatsInflige;
printf("\n             vous infligez %d points de degats au GnomeLepreux",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(GnomeLepreux >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le GnomeLepreux repond a vous tirant des pieces dessus  ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du GnomeLepreux");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = GnomeLepreuxx.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= GnomeLepreuxx.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}










}


// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
// ==================== COMBAT GNOME LPREUX =============================
}
printf("\n       ARRETEZ ARRETEZ ARRETEZ C'EST BON TENEZ VOICI VOS PIECE PFFFF");
gold = gold +50;
printf("\n       Gold +50\n gold : %d",gold);


      break;

    // SWITCH
    }
    // UNLUCKY
    }

// LUCKY

    if(nombreRandome >2){

       srand(time(NULL));
     nombreRandome = rand() % 4;

       switch(nombreRandome){
       case 0 :
           printf("\n            Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n          Une potion tombe du ciel ! vous venez de recevoir une potion de soin supplementaire\n          Quelle chance !");
       potionsRouge++;
       printf("\n          potion rouge : %d",potionsRouge);
       printf("\n            Vous continuez votre route dans la salle suivante");
    printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);       break;

       case 1 : aventurier.attaque = aventurier.attaque + 5;
       printf("\n            Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n            Votre attaque a vu sa puissance augmenter !\nattaque : %d",aventurier.attaque);
       printf("\n            Vous continuez votre route dans la salle suivante");
          printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

       break;

       case 4 :
           printf("\n            Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n          Une grenade fumigene tombe du ciel ! Heuresement elle n'est pas degouippilé\n          Quelle chance !");
       SmokeBomb++;
       printf("\n          smoke Bomb : %d",SmokeBomb);
       printf("\n            Vous continuez votre route dans la salle suivante");


       break;

       case 3 : PPSort1 = 10; PPSort2 = 5; PPSort3 = 3;

       printf("\n          Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n          Vous sentez une odeur etrange..\n          Peu importe ce que c'est mais vous vous sentez mieux !\n          Vous recuperez tous vos PP\n Sort 1 : %d\n Sort 2 : %d\n Sort 3 : %d",PPSort1,PPSort2,PPSort3);
       printf("\n            Vous continuez votre route dans la salle suivante");
          printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);       break;

       case 2 : aventurier.pointsDeVies = aventurier.pointsDeVies + 50;
       MAXIMUM(aventurier.pointsDeVies,200);
       printf("\n            Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n            Vos etes frais comme un gardon et vous sentez votre energie vitale couler en vous \nPoints de vie: %d ",aventurier.pointsDeVies);
       printf("\n            Vous continuez votre route dans la salle suivante");
       printf("\n/\\");
scanf("%d",&xanogene);
       break;}
       // FIN DU SWITCH
}

ouvrirCoffre = 0;
NombreDeSalles++;
pourcentageEsquallier = pourcentageEsquallier *1.5;
}
// OUVRIR COFFRE OUI
if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");}
// FIN AMULETTE
}

 printf("\n/\\");
scanf("%d",&xanogene);
maxsalleAuTresor++;
NombreDeSalles++;
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

}
srand(time(NULL));
nombreRandome = rand() % 28;

break;
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++


// ======================== SALLE DE CAMPS DE REPOS ======================
// ======================== SALLE DE CAMPS DE REPOS ======================
// ======================== SALLE DE CAMPS DE REPOS ======================
// ======================== SALLE DE CAMPS DE REPOS ======================
// ======================== SALLE DE CAMPS DE REPOS ======================
// ======================== SALLE DE CAMPS DE REPOS ======================
// ======================== SALLE DE CAMPS DE REPOS ======================
case 7 :


    printf("\n             A travers l'angoisse des salles vous trouvez un cercle de feu eteint, heuresement,\n            vous transportez toujours avec vous un bon vieux briquet !\n            Allumer le feu (ET FAIRE DANSER LES DIABLES ET LES DIEUX ?\n1 : OUI\n2 : NON");
    scanf("%d",&BonfireLit);
    if(BonfireLit == 2){
        printf("\n             Vous preferez ne pas toucher a cette chose la et vous continuez votre route dans la salle suivante");
        NombreDeSalles++;
        pourcentageEsquallier = pourcentageEsquallier *1.5;
        pourcentageTresor = pourcentageTresor*1.2;
        BonfireLit =0;}


    if(BonfireLit == 1){
            aventurier.pointsDeVies = aventurier.pointsDeVies +30;
            PPSort1  = PPSort1 +3;
            PPSort2  = PPSort2 +2;
            PPSort3  = PPSort3 +1;
           pourcentageCombats = pourcentageCombats * 1.5;
           maxCombat = maxCombat -3;
    printf("\n             Vous degainez votre briquet et faites virvolter une etincelle ce qui a pour effet d'allumer ce feu de camps.\n             et vous recuperez enormement de pv et quelques PP\n            PV : %d",aventurier.pointsDeVies);
    printf("\n             Cependant.... a present vous empestez une odeur etrange emise par le feu \n             (surement parceque les flemmes etaient violettes)\n             les monstres auront a present plus de chance d'apparaitre");
    NombreDeSalles++;
    pourcentageEsquallier = pourcentageEsquallier *1.5;
    pourcentageTresor = pourcentageTresor*1.2;
    BonfireLit =0;
    MAXIMUM(aventurier.pointsDeVies,200);

    srand(time(NULL));
nombreRandome = rand() % 10;

if(nombreRandome >=6){
  miniBoss = 1;
  printf("\n\n\n         Vous entendez un immense craquement... quelque chose vous a reperez...\n         Vous continuez votre route pas tres sereinement... ");
}

    }

    if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");}

    // AMULETTE
}
printf("\n/\\");
scanf("%d",&xanogene);
NombreDeSalles++;

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

break;
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++


case 18 :


    printf("\n             A travers l'angoisse des salles vous trouvez un cercle de feu eteint, heuresement,\n            vous transportez toujours avec vous un bon vieux briquet !\n            Allumer le feu (ET FAIRE DANSER LES DIABLES ET LES DIEUX ?\n1 : OUI\n2 : NON");
    scanf("%d",&BonfireLit);
    if(BonfireLit == 2){
        printf("\n             Vous preferez ne pas toucher a cette chose la et vous continuez votre route dans la salle suivante");
        NombreDeSalles++;
        pourcentageEsquallier = pourcentageEsquallier *1.5;
        pourcentageTresor = pourcentageTresor*1.2;
        BonfireLit =0;}


    if(BonfireLit == 1){
            aventurier.pointsDeVies = aventurier.pointsDeVies +30;
           pourcentageCombats = pourcentageCombats * 1.5;
           maxCombat = maxCombat -3;
           PPSort1  = PPSort1 +3;
            PPSort2  = PPSort2 +2;
            PPSort3  = PPSort3 +1;
    printf("\n             Vous degainez votre briquet et faites virvolter une etincelle ce qui a pour effet d'allumer ce feu de camps.\n             et vous recuperez enormement de pv et quelques PP\n            PV : %d",aventurier.pointsDeVies);
    printf("\n             Cependant.... a present vous empestez une odeur etrange emise par le feu \n             (surement parceque les flemmes etaient violettes)\n             les monstres auront a present plus de chance d'apparaitre");
    NombreDeSalles++;
    pourcentageEsquallier = pourcentageEsquallier *1.5;
    pourcentageTresor = pourcentageTresor*1.2;
    BonfireLit =0;
    MAXIMUM(aventurier.pointsDeVies,200);

       srand(time(NULL));
nombreRandome = rand() % 10;

if(nombreRandome >=6){
  miniBoss = 1;
  printf("\n\n\n         Vous entendez un immense craquement... quelque chose vous a reperez...\n         Vous continuez votre route pas tres sereinement... ");
}

}

    if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");}

    // AMULETTE
}
printf("\n/\\");
scanf("%d",&xanogene);
NombreDeSalles++;

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

break;
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++
// +++++++++++++++++++ SALLE DE CAMPS DE REPOS +++++++++++++++++++





// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================

case 3 :

srand(time(NULL));
nombreRandome = rand() % 7;


// ANNONCE COMBAT
switch(nombreRandome){
    case 1 :printf("\n             En entrant dans cette salle vous vous sentez mal a l'aise....\n             Malheursement,votre presentiments va bientot se confirmer car vous tombez nez a nez avec un monstre...");
    break;
    case 2 : printf("\n             Vous ressentez que le budget a augmenter et qu'il y a a present plusieurs phrases\n             pour annoncer les combats... donc enfin..bref c'est un combat quoi\n             GO");
    break;
    case 3 : printf("\n             DRRRDRRDRDRDRDDRDRDDDRDRDRD TU TU TU TU TUUTUTUTUTU TUTU TUTTUTU TUTUU TUTUTUTU *musique de pokemon*\n              LE COMBAT COMMENCE");
    break;
    case 4 :  printf("\n             C'est l'heure DU DU DU DU DUDU DU DU DUUUEEELELLL Le combat commence ! ");
    break;
    case 5 : printf("\n             bon bahh... monstre, ratatat,degat,fais chier merde enfin BREF quoi COMBAT BORDEL");
    break;
    case 0 : printf("\n             Un monstre se cache dans le coin de la piece ! \n             Il vous a reperer MINCE Le combat commence ! ");
    break;
    case 6 : printf("\n             L'obscurite devient pesante et vous vous sentez observe... ATTENTION UN MONSTRE VOUS SAUTE DESSUS !");
    break;
    case 7 : printf("\n             Cette salle ne vous dit rien qui va.... vous restez sur vos garde mais MALGRE CA vous tombez nez a nez avec un monstre..\n              LE COMBAT COMMENCE");
}



srand(time(NULL));
nombreRandome = rand() % 3;

// =================================================== DEBUT DU SWITHC COMBAT GOBELIN SQUELETTE FANTOME SORCIERE =======================================

switch(nombreRandome){
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Zombie\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Zombies.attaque = ADZombie;
Zombie = Zombies.pointsDeVies;
// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
system("cls");
        Zombie = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Zombie > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Zombie : %d",Zombie);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+3 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Zombie aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+15 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Zombie >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Zombie repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Zombie");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Zombies.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Zombies.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un fourmillion\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Fourmillions.attaque = ADFourmillion;
Fourmillion = Fourmillions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        Fourmillion = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fourmillion > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fourmillion : %d",Fourmillion);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;

        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+3 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Fourmillion aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+15 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fourmillion >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Fourmillion repond a votre attaque en jettant viollement son femur sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Fourmillion");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fourmillions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fourmillions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un BebeDragon\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
BebeDragons.attaque = ADBebeDragon;
BebeDragon = BebeDragons.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        BebeDragon = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && BebeDragon > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du BebeDragon : %d",BebeDragon);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+3 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le BebeDragon aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+15 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(BebeDragon >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le BebeDragon repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du BebeDragon");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = BebeDragons.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= BebeDragons.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Le nihilisme de la deception\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
NihilismeDeLaDeceptions.attaque = ADNihilismeDeLaDeception;
NihilismeDeLaDeception = NihilismeDeLaDeceptions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        NihilismeDeLaDeception = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && NihilismeDeLaDeception > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la NihilismeDeLaDeception : %d",NihilismeDeLaDeception);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+3 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le NihilismeDeLaDeception aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+15 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(NihilismeDeLaDeception >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le NihilismeDeLaDeception vous deprime et vous fait mal  ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du NihilismeDeLaDeception");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = NihilismeDeLaDeceptions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= NihilismeDeLaDeceptions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!



// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
}




// ===============================  REMISES DES RECOMPENSES ==================================

srand(time(NULL));
nombreRandome = rand() % 25;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 4;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 15;
    gold = gold + nombreRandome;
}


printf("\n             Pfiou... on s'en sort.... Allez poursuivons vers la salle suivante !\nRecompenses :\n Experiences + %d",bonusXP);
if(bonuxGOLD > 0){
    printf("\n Golds + %d",bonuxGOLD);
}

// ==========================  MONTEE DE LVL  ============================
if(pointsDexperience >= 100){


    printf("\n\n");
printf("\n     *********************************************************************************     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |//////////////////////////////**  LEVEL UP  **/////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////          Vos statistique augmentent !           ///////////////|     ");
printf("\n     |///////////////                  Attaque ++                     ///////////////|     ");
printf("\n     |///////////////                  Esquive ++                     ///////////////|     ");
printf("\n     |///////////////                  PV : Max         Niveau %d      ///////////////|     ",LevelAventurier+1);
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     ********************************************************************************|     ");

pointsDexperience = 0;
LevelAventurier++;
aventurier.attaque = aventurier.attaque +3;
aventurier.esquive = aventurier.esquive +3;
aventurier.pointsDeVies = 200;
PPSort1 = 10;
PPSort2 = 5;
PPSort3 = 3;


}

// ++++++++++ FIN MONTEE DE LVL +++++++++++
bonusXP = 0;
bonuxGOLD = 0;


// +++++++++++++++++++++++ REMISE DES RECOMPENSES ++++++++++++++++++++++




printf("\n\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

maxCombat++;
NombreDeSalles++;


break;
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++




case 2 :

srand(time(NULL));
nombreRandome = rand() % 7;


// ANNONCE COMBAT
switch(nombreRandome){
    case 1 :printf("\n             En entrant dans cette salle vous vous sentez mal a l'aise....\n             Malheursement,votre presentiments va bientot se confirmer car vous tombez nez a nez avec un monstre...");
    break;
    case 2 : printf("\n             Vous ressentez que le budget a augmenter et qu'il y a a present plusieurs phrases\n             pour annoncer les combats... donc enfin..bref c'est un combat quoi\n             GO");
    break;
    case 3 : printf("\n             DRRRDRRDRDRDRDDRDRDDDRDRDRD TU TU TU TU TUUTUTUTUTU TUTU TUTTUTU TUTUU TUTUTUTU *musique de pokemon*\n              LE COMBAT COMMENCE");
    break;
    case 4 :  printf("\n             C'est l'heure DU DU DU DU DUDU DU DU DUUUEEELELLL Le combat commence ! ");
    break;
    case 5 : printf("\n             bon bahh... monstre, ratatat,degat,fais chier merde enfin BREF quoi COMBAT BORDEL");
    break;
    case 0 : printf("\n             Un monstre se cache dans le coin de la piece ! \n             Il vous a reperer MINCE Le combat commence ! ");
    break;
    case 6 : printf("\n             L'obscurite devient pesante et vous vous sentez observe... ATTENTION UN MONSTRE VOUS SAUTE DESSUS !");
    break;
    case 7 : printf("\n             Cette salle ne vous dit rien qui va.... vous restez sur vos garde mais MALGRE CA vous tombez nez a nez avec un monstre..\n              LE COMBAT COMMENCE");
}



srand(time(NULL));
nombreRandome = rand() % 3;

// =================================================== DEBUT DU SWITHC COMBAT GOBELIN SQUELETTE FANTOME SORCIERE =======================================

switch(nombreRandome){
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Zombie\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Zombies.attaque = ADZombie;
Zombie = Zombies.pointsDeVies;
// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
system("cls");
        Zombie = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Zombie > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Zombie : %d",Zombie);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+3 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Zombie aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+15 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Zombie >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Zombie repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Zombie");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Zombies.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Zombies.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un fourmillion\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Fourmillions.attaque = ADFourmillion;
Fourmillion = Fourmillions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        Fourmillion = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fourmillion > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fourmillion : %d",Fourmillion);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;

        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+3 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Fourmillion aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+15 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fourmillion >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Fourmillion repond a votre attaque en jettant viollement son femur sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Fourmillion");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fourmillions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fourmillions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un BebeDragon\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
BebeDragons.attaque = ADBebeDragon;
BebeDragon = BebeDragons.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        BebeDragon = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && BebeDragon > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du BebeDragon : %d",BebeDragon);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+3 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le BebeDragon aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+15 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(BebeDragon >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le BebeDragon repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du BebeDragon");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = BebeDragons.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= BebeDragons.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Le nihilisme de la deception\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
NihilismeDeLaDeceptions.attaque = ADNihilismeDeLaDeception;
NihilismeDeLaDeception = NihilismeDeLaDeceptions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        NihilismeDeLaDeception = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && NihilismeDeLaDeception > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la NihilismeDeLaDeception : %d",NihilismeDeLaDeception);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+3 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le NihilismeDeLaDeception aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+15 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(NihilismeDeLaDeception >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le NihilismeDeLaDeception vous deprime et vous fait mal  ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du NihilismeDeLaDeception");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = NihilismeDeLaDeceptions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= NihilismeDeLaDeceptions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!



// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
}




// ===============================  REMISES DES RECOMPENSES ==================================

srand(time(NULL));
nombreRandome = rand() % 25;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 4;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 15;
    gold = gold + nombreRandome;
}


printf("\n             Pfiou... on s'en sort.... Allez poursuivons vers la salle suivante !\nRecompenses :\n Experiences + %d",bonusXP);
if(bonuxGOLD > 0){
    printf("\n Golds + %d",bonuxGOLD);
}

// ==========================  MONTEE DE LVL  ============================
if(pointsDexperience >= 100){


    printf("\n\n");
printf("\n     *********************************************************************************     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |//////////////////////////////**  LEVEL UP  **/////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////          Vos statistique augmentent !           ///////////////|     ");
printf("\n     |///////////////                  Attaque ++                     ///////////////|     ");
printf("\n     |///////////////                  Esquive ++                     ///////////////|     ");
printf("\n     |///////////////                  PV : Max         Niveau %d      ///////////////|     ",LevelAventurier+1);
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     ********************************************************************************|     ");

pointsDexperience = 0;
LevelAventurier++;
aventurier.attaque = aventurier.attaque +3;
aventurier.esquive = aventurier.esquive +3;
aventurier.pointsDeVies = 200;
PPSort1 = 10;
PPSort2 = 5;
PPSort3 = 3;


}

// ++++++++++ FIN MONTEE DE LVL +++++++++++
bonusXP = 0;
bonuxGOLD = 0;


// +++++++++++++++++++++++ REMISE DES RECOMPENSES ++++++++++++++++++++++




printf("\n\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

maxCombat++;
NombreDeSalles++;


break;
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++

// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================

case 9 :

srand(time(NULL));
nombreRandome = rand() % 7;


// ANNONCE COMBAT
switch(nombreRandome){
    case 1 :printf("\n             En entrant dans cette salle vous vous sentez mal a l'aise....\n             Malheursement,votre presentiments va bientot se confirmer car vous tombez nez a nez avec un monstre...");
    break;
    case 2 : printf("\n             Vous ressentez que le budget a augmenter et qu'il y a a present plusieurs phrases\n             pour annoncer les combats... donc enfin..bref c'est un combat quoi\n             GO");
    break;
    case 3 : printf("\n             DRRRDRRDRDRDRDDRDRDDDRDRDRD TU TU TU TU TUUTUTUTUTU TUTU TUTTUTU TUTUU TUTUTUTU *musique de pokemon*\n              LE COMBAT COMMENCE");
    break;
    case 4 :  printf("\n             C'est l'heure DU DU DU DU DUDU DU DU DUUUEEELELLL Le combat commence ! ");
    break;
    case 5 : printf("\n             bon bahh... monstre, ratatat,degat,fais chier merde enfin BREF quoi COMBAT BORDEL");
    break;
    case 0 : printf("\n             Un monstre se cache dans le coin de la piece ! \n             Il vous a reperer MINCE Le combat commence ! ");
    break;
    case 6 : printf("\n             L'obscurite devient pesante et vous vous sentez observe... ATTENTION UN MONSTRE VOUS SAUTE DESSUS !");
    break;
    case 7 : printf("\n             Cette salle ne vous dit rien qui va.... vous restez sur vos garde mais MALGRE CA vous tombez nez a nez avec un monstre..\n              LE COMBAT COMMENCE");
}



srand(time(NULL));
nombreRandome = rand() % 3;

// =================================================== DEBUT DU SWITHC COMBAT GOBELIN SQUELETTE FANTOME SORCIERE =======================================

switch(nombreRandome){
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Zombie\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Zombies.attaque = ADZombie;
Zombie = Zombies.pointsDeVies;
// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
system("cls");
        Zombie = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Zombie > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Zombie : %d",Zombie);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+3 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Zombie aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+15 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Zombie >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Zombie repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Zombie");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Zombies.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Zombies.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un fourmillion\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Fourmillions.attaque = ADFourmillion;
Fourmillion = Fourmillions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        Fourmillion = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fourmillion > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fourmillion : %d",Fourmillion);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;

        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+3 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Fourmillion aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+15 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fourmillion >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Fourmillion repond a votre attaque en jettant viollement son femur sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Fourmillion");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fourmillions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fourmillions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un BebeDragon\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
BebeDragons.attaque = ADBebeDragon;
BebeDragon = BebeDragons.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        BebeDragon = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && BebeDragon > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du BebeDragon : %d",BebeDragon);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+3 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le BebeDragon aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+15 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(BebeDragon >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le BebeDragon repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du BebeDragon");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = BebeDragons.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= BebeDragons.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Le nihilisme de la deception\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
NihilismeDeLaDeceptions.attaque = ADNihilismeDeLaDeception;
NihilismeDeLaDeception = NihilismeDeLaDeceptions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        NihilismeDeLaDeception = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && NihilismeDeLaDeception > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la NihilismeDeLaDeception : %d",NihilismeDeLaDeception);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+3 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le NihilismeDeLaDeception aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+15 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(NihilismeDeLaDeception >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le NihilismeDeLaDeception vous deprime et vous fait mal  ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du NihilismeDeLaDeception");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = NihilismeDeLaDeceptions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= NihilismeDeLaDeceptions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!



// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
}




// ===============================  REMISES DES RECOMPENSES ==================================

srand(time(NULL));
nombreRandome = rand() % 25;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 4;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 15;
    gold = gold + nombreRandome;
}


printf("\n             Pfiou... on s'en sort.... Allez poursuivons vers la salle suivante !\nRecompenses :\n Experiences + %d",bonusXP);
if(bonuxGOLD > 0){
    printf("\n Golds + %d",bonuxGOLD);
}

// ==========================  MONTEE DE LVL  ============================
if(pointsDexperience >= 100){


    printf("\n\n");
printf("\n     *********************************************************************************     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |//////////////////////////////**  LEVEL UP  **/////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////          Vos statistique augmentent !           ///////////////|     ");
printf("\n     |///////////////                  Attaque ++                     ///////////////|     ");
printf("\n     |///////////////                  Esquive ++                     ///////////////|     ");
printf("\n     |///////////////                  PV : Max         Niveau %d      ///////////////|     ",LevelAventurier+1);
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     ********************************************************************************|     ");

pointsDexperience = 0;
LevelAventurier++;
aventurier.attaque = aventurier.attaque +3;
aventurier.esquive = aventurier.esquive +3;
aventurier.pointsDeVies = 200;
PPSort1 = 10;
PPSort2 = 5;
PPSort3 = 3;


}

// ++++++++++ FIN MONTEE DE LVL +++++++++++
bonusXP = 0;
bonuxGOLD = 0;


// +++++++++++++++++++++++ REMISE DES RECOMPENSES ++++++++++++++++++++++




printf("\n\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

maxCombat++;
NombreDeSalles++;


break;
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++




case 11 :

srand(time(NULL));
nombreRandome = rand() % 7;


// ANNONCE COMBAT
switch(nombreRandome){
    case 1 :printf("\n             En entrant dans cette salle vous vous sentez mal a l'aise....\n             Malheursement,votre presentiments va bientot se confirmer car vous tombez nez a nez avec un monstre...");
    break;
    case 2 : printf("\n             Vous ressentez que le budget a augmenter et qu'il y a a present plusieurs phrases\n             pour annoncer les combats... donc enfin..bref c'est un combat quoi\n             GO");
    break;
    case 3 : printf("\n             DRRRDRRDRDRDRDDRDRDDDRDRDRD TU TU TU TU TUUTUTUTUTU TUTU TUTTUTU TUTUU TUTUTUTU *musique de pokemon*\n              LE COMBAT COMMENCE");
    break;
    case 4 :  printf("\n             C'est l'heure DU DU DU DU DUDU DU DU DUUUEEELELLL Le combat commence ! ");
    break;
    case 5 : printf("\n             bon bahh... monstre, ratatat,degat,fais chier merde enfin BREF quoi COMBAT BORDEL");
    break;
    case 0 : printf("\n             Un monstre se cache dans le coin de la piece ! \n             Il vous a reperer MINCE Le combat commence ! ");
    break;
    case 6 : printf("\n             L'obscurite devient pesante et vous vous sentez observe... ATTENTION UN MONSTRE VOUS SAUTE DESSUS !");
    break;
    case 7 : printf("\n             Cette salle ne vous dit rien qui va.... vous restez sur vos garde mais MALGRE CA vous tombez nez a nez avec un monstre..\n              LE COMBAT COMMENCE");
}



srand(time(NULL));
nombreRandome = rand() % 3;

// =================================================== DEBUT DU SWITHC COMBAT GOBELIN SQUELETTE FANTOME SORCIERE =======================================

switch(nombreRandome){
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Zombie\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Zombies.attaque = ADZombie;
Zombie = Zombies.pointsDeVies;
// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
system("cls");
        Zombie = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Zombie > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Zombie : %d",Zombie);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+3 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Zombie aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+15 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Zombie >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Zombie repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Zombie");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Zombies.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Zombies.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un fourmillion\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Fourmillions.attaque = ADFourmillion;
Fourmillion = Fourmillions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        Fourmillion = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fourmillion > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fourmillion : %d",Fourmillion);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;

        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+3 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Fourmillion aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+15 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fourmillion >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Fourmillion repond a votre attaque en jettant viollement son femur sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Fourmillion");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fourmillions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fourmillions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un BebeDragon\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
BebeDragons.attaque = ADBebeDragon;
BebeDragon = BebeDragons.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        BebeDragon = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && BebeDragon > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du BebeDragon : %d",BebeDragon);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+3 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le BebeDragon aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+15 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(BebeDragon >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le BebeDragon repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du BebeDragon");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = BebeDragons.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= BebeDragons.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Le nihilisme de la deception\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
NihilismeDeLaDeceptions.attaque = ADNihilismeDeLaDeception;
NihilismeDeLaDeception = NihilismeDeLaDeceptions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        NihilismeDeLaDeception = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && NihilismeDeLaDeception > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la NihilismeDeLaDeception : %d",NihilismeDeLaDeception);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+3 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le NihilismeDeLaDeception aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+15 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(NihilismeDeLaDeception >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le NihilismeDeLaDeception vous deprime et vous fait mal  ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du NihilismeDeLaDeception");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = NihilismeDeLaDeceptions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= NihilismeDeLaDeceptions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!



// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
}




// ===============================  REMISES DES RECOMPENSES ==================================

srand(time(NULL));
nombreRandome = rand() % 25;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 4;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 15;
    gold = gold + nombreRandome;
}


printf("\n             Pfiou... on s'en sort.... Allez poursuivons vers la salle suivante !\nRecompenses :\n Experiences + %d",bonusXP);
if(bonuxGOLD > 0){
    printf("\n Golds + %d",bonuxGOLD);
}

// ==========================  MONTEE DE LVL  ============================
if(pointsDexperience >= 100){


    printf("\n\n");
printf("\n     *********************************************************************************     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |//////////////////////////////**  LEVEL UP  **/////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////          Vos statistique augmentent !           ///////////////|     ");
printf("\n     |///////////////                  Attaque ++                     ///////////////|     ");
printf("\n     |///////////////                  Esquive ++                     ///////////////|     ");
printf("\n     |///////////////                  PV : Max         Niveau %d      ///////////////|     ",LevelAventurier+1);
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     ********************************************************************************|     ");

pointsDexperience = 0;
LevelAventurier++;
aventurier.attaque = aventurier.attaque +3;
aventurier.esquive = aventurier.esquive +3;
aventurier.pointsDeVies = 200;
PPSort1 = 10;
PPSort2 = 5;
PPSort3 = 3;


}

// ++++++++++ FIN MONTEE DE LVL +++++++++++
bonusXP = 0;
bonuxGOLD = 0;


// +++++++++++++++++++++++ REMISE DES RECOMPENSES ++++++++++++++++++++++




printf("\n\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

maxCombat++;
NombreDeSalles++;


break;
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++


// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================

case 19 :

srand(time(NULL));
nombreRandome = rand() % 7;


// ANNONCE COMBAT
switch(nombreRandome){
    case 1 :printf("\n             En entrant dans cette salle vous vous sentez mal a l'aise....\n             Malheursement,votre presentiments va bientot se confirmer car vous tombez nez a nez avec un monstre...");
    break;
    case 2 : printf("\n             Vous ressentez que le budget a augmenter et qu'il y a a present plusieurs phrases\n             pour annoncer les combats... donc enfin..bref c'est un combat quoi\n             GO");
    break;
    case 3 : printf("\n             DRRRDRRDRDRDRDDRDRDDDRDRDRD TU TU TU TU TUUTUTUTUTU TUTU TUTTUTU TUTUU TUTUTUTU *musique de pokemon*\n              LE COMBAT COMMENCE");
    break;
    case 4 :  printf("\n             C'est l'heure DU DU DU DU DUDU DU DU DUUUEEELELLL Le combat commence ! ");
    break;
    case 5 : printf("\n             bon bahh... monstre, ratatat,degat,fais chier merde enfin BREF quoi COMBAT BORDEL");
    break;
    case 0 : printf("\n             Un monstre se cache dans le coin de la piece ! \n             Il vous a reperer MINCE Le combat commence ! ");
    break;
    case 6 : printf("\n             L'obscurite devient pesante et vous vous sentez observe... ATTENTION UN MONSTRE VOUS SAUTE DESSUS !");
    break;
    case 7 : printf("\n             Cette salle ne vous dit rien qui va.... vous restez sur vos garde mais MALGRE CA vous tombez nez a nez avec un monstre..\n              LE COMBAT COMMENCE");
}



srand(time(NULL));
nombreRandome = rand() % 3;

// =================================================== DEBUT DU SWITHC COMBAT GOBELIN SQUELETTE FANTOME SORCIERE =======================================

switch(nombreRandome){
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Zombie\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Zombies.attaque = ADZombie;
Zombie = Zombies.pointsDeVies;
// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
system("cls");
        Zombie = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Zombie > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Zombie : %d",Zombie);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+3 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Zombie aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+15 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Zombie >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Zombie repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Zombie");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Zombies.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Zombies.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un fourmillion\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Fourmillions.attaque = ADFourmillion;
Fourmillion = Fourmillions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        Fourmillion = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fourmillion > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fourmillion : %d",Fourmillion);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;

        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+3 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Fourmillion aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+15 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fourmillion >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Fourmillion repond a votre attaque en jettant viollement son femur sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Fourmillion");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fourmillions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fourmillions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un BebeDragon\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
BebeDragons.attaque = ADBebeDragon;
BebeDragon = BebeDragons.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        BebeDragon = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && BebeDragon > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du BebeDragon : %d",BebeDragon);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+3 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le BebeDragon aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+15 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(BebeDragon >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le BebeDragon repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du BebeDragon");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = BebeDragons.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= BebeDragons.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Le nihilisme de la deception\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
NihilismeDeLaDeceptions.attaque = ADNihilismeDeLaDeception;
NihilismeDeLaDeception = NihilismeDeLaDeceptions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        NihilismeDeLaDeception = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && NihilismeDeLaDeception > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la NihilismeDeLaDeception : %d",NihilismeDeLaDeception);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+3 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le NihilismeDeLaDeception aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+15 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(NihilismeDeLaDeception >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le NihilismeDeLaDeception vous deprime et vous fait mal  ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du NihilismeDeLaDeception");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = NihilismeDeLaDeceptions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= NihilismeDeLaDeceptions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!



// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
}




// ===============================  REMISES DES RECOMPENSES ==================================

srand(time(NULL));
nombreRandome = rand() % 25;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 4;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 15;
    gold = gold + nombreRandome;
}


printf("\n             Pfiou... on s'en sort.... Allez poursuivons vers la salle suivante !\nRecompenses :\n Experiences + %d",bonusXP);
if(bonuxGOLD > 0){
    printf("\n Golds + %d",bonuxGOLD);
}

// ==========================  MONTEE DE LVL  ============================
if(pointsDexperience >= 100){


    printf("\n\n");
printf("\n     *********************************************************************************     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |//////////////////////////////**  LEVEL UP  **/////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////          Vos statistique augmentent !           ///////////////|     ");
printf("\n     |///////////////                  Attaque ++                     ///////////////|     ");
printf("\n     |///////////////                  Esquive ++                     ///////////////|     ");
printf("\n     |///////////////                  PV : Max         Niveau %d      ///////////////|     ",LevelAventurier+1);
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     ********************************************************************************|     ");

pointsDexperience = 0;
LevelAventurier++;
aventurier.attaque = aventurier.attaque +3;
aventurier.esquive = aventurier.esquive +3;
aventurier.pointsDeVies = 200;
PPSort1 = 10;
PPSort2 = 5;
PPSort3 = 3;


}

// ++++++++++ FIN MONTEE DE LVL +++++++++++
bonusXP = 0;
bonuxGOLD = 0;


// +++++++++++++++++++++++ REMISE DES RECOMPENSES ++++++++++++++++++++++




printf("\n\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

maxCombat++;
NombreDeSalles++;


break;
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++




case 20 :

srand(time(NULL));
nombreRandome = rand() % 7;


// ANNONCE COMBAT
switch(nombreRandome){
    case 1 :printf("\n             En entrant dans cette salle vous vous sentez mal a l'aise....\n             Malheursement,votre presentiments va bientot se confirmer car vous tombez nez a nez avec un monstre...");
    break;
    case 2 : printf("\n             Vous ressentez que le budget a augmenter et qu'il y a a present plusieurs phrases\n             pour annoncer les combats... donc enfin..bref c'est un combat quoi\n             GO");
    break;
    case 3 : printf("\n             DRRRDRRDRDRDRDDRDRDDDRDRDRD TU TU TU TU TUUTUTUTUTU TUTU TUTTUTU TUTUU TUTUTUTU *musique de pokemon*\n              LE COMBAT COMMENCE");
    break;
    case 4 :  printf("\n             C'est l'heure DU DU DU DU DUDU DU DU DUUUEEELELLL Le combat commence ! ");
    break;
    case 5 : printf("\n             bon bahh... monstre, ratatat,degat,fais chier merde enfin BREF quoi COMBAT BORDEL");
    break;
    case 0 : printf("\n             Un monstre se cache dans le coin de la piece ! \n             Il vous a reperer MINCE Le combat commence ! ");
    break;
    case 6 : printf("\n             L'obscurite devient pesante et vous vous sentez observe... ATTENTION UN MONSTRE VOUS SAUTE DESSUS !");
    break;
    case 7 : printf("\n             Cette salle ne vous dit rien qui va.... vous restez sur vos garde mais MALGRE CA vous tombez nez a nez avec un monstre..\n              LE COMBAT COMMENCE");
}



srand(time(NULL));
nombreRandome = rand() % 3;

// =================================================== DEBUT DU SWITHC COMBAT GOBELIN SQUELETTE FANTOME SORCIERE =======================================

switch(nombreRandome){
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Zombie\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Zombies.attaque = ADZombie;
Zombie = Zombies.pointsDeVies;
// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
system("cls");
        Zombie = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Zombie > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Zombie : %d",Zombie);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+3 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Zombie aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+15 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Zombie >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Zombie repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Zombie");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Zombies.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Zombies.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un fourmillion\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Fourmillions.attaque = ADFourmillion;
Fourmillion = Fourmillions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        Fourmillion = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fourmillion > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fourmillion : %d",Fourmillion);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;

        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+3 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Fourmillion aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+15 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fourmillion >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Fourmillion repond a votre attaque en jettant viollement son femur sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Fourmillion");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fourmillions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fourmillions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un BebeDragon\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
BebeDragons.attaque = ADBebeDragon;
BebeDragon = BebeDragons.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        BebeDragon = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && BebeDragon > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du BebeDragon : %d",BebeDragon);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+3 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le BebeDragon aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+15 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(BebeDragon >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le BebeDragon repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du BebeDragon");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = BebeDragons.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= BebeDragons.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Le nihilisme de la deception\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
NihilismeDeLaDeceptions.attaque = ADNihilismeDeLaDeception;
NihilismeDeLaDeception = NihilismeDeLaDeceptions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        NihilismeDeLaDeception = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && NihilismeDeLaDeception > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la NihilismeDeLaDeception : %d",NihilismeDeLaDeception);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+3 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le NihilismeDeLaDeception aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+15 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(NihilismeDeLaDeception >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le NihilismeDeLaDeception vous deprime et vous fait mal  ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du NihilismeDeLaDeception");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = NihilismeDeLaDeceptions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= NihilismeDeLaDeceptions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!



// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
}




// ===============================  REMISES DES RECOMPENSES ==================================

srand(time(NULL));
nombreRandome = rand() % 25;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 4;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 15;
    gold = gold + nombreRandome;
}


printf("\n             Pfiou... on s'en sort.... Allez poursuivons vers la salle suivante !\nRecompenses :\n Experiences + %d",bonusXP);
if(bonuxGOLD > 0){
    printf("\n Golds + %d",bonuxGOLD);
}

// ==========================  MONTEE DE LVL  ============================
if(pointsDexperience >= 100){


    printf("\n\n");
printf("\n     *********************************************************************************     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |//////////////////////////////**  LEVEL UP  **/////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////          Vos statistique augmentent !           ///////////////|     ");
printf("\n     |///////////////                  Attaque ++                     ///////////////|     ");
printf("\n     |///////////////                  Esquive ++                     ///////////////|     ");
printf("\n     |///////////////                  PV : Max         Niveau %d      ///////////////|     ",LevelAventurier+1);
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     ********************************************************************************|     ");

pointsDexperience = 0;
LevelAventurier++;
aventurier.attaque = aventurier.attaque +3;
aventurier.esquive = aventurier.esquive +3;
aventurier.pointsDeVies = 200;
PPSort1 = 10;
PPSort2 = 5;
PPSort3 = 3;


}

// ++++++++++ FIN MONTEE DE LVL +++++++++++
bonusXP = 0;
bonuxGOLD = 0;


// +++++++++++++++++++++++ REMISE DES RECOMPENSES ++++++++++++++++++++++




printf("\n\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

maxCombat++;
NombreDeSalles++;


break;
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++


// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================
// ====================== SALLE DE COMBAT =============================

case 21 :

srand(time(NULL));
nombreRandome = rand() % 7;


// ANNONCE COMBAT
switch(nombreRandome){
    case 1 :printf("\n             En entrant dans cette salle vous vous sentez mal a l'aise....\n             Malheursement,votre presentiments va bientot se confirmer car vous tombez nez a nez avec un monstre...");
    break;
    case 2 : printf("\n             Vous ressentez que le budget a augmenter et qu'il y a a present plusieurs phrases\n             pour annoncer les combats... donc enfin..bref c'est un combat quoi\n             GO");
    break;
    case 3 : printf("\n             DRRRDRRDRDRDRDDRDRDDDRDRDRD TU TU TU TU TUUTUTUTUTU TUTU TUTTUTU TUTUU TUTUTUTU *musique de pokemon*\n              LE COMBAT COMMENCE");
    break;
    case 4 :  printf("\n             C'est l'heure DU DU DU DU DUDU DU DU DUUUEEELELLL Le combat commence ! ");
    break;
    case 5 : printf("\n             bon bahh... monstre, ratatat,degat,fais chier merde enfin BREF quoi COMBAT BORDEL");
    break;
    case 0 : printf("\n             Un monstre se cache dans le coin de la piece ! \n             Il vous a reperer MINCE Le combat commence ! ");
    break;
    case 6 : printf("\n             L'obscurite devient pesante et vous vous sentez observe... ATTENTION UN MONSTRE VOUS SAUTE DESSUS !");
    break;
    case 7 : printf("\n             Cette salle ne vous dit rien qui va.... vous restez sur vos garde mais MALGRE CA vous tombez nez a nez avec un monstre..\n              LE COMBAT COMMENCE");
}



srand(time(NULL));
nombreRandome = rand() % 3;

// =================================================== DEBUT DU SWITHC COMBAT GOBELIN SQUELETTE FANTOME SORCIERE =======================================

switch(nombreRandome){
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Zombie\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Zombies.attaque = ADZombie;
Zombie = Zombies.pointsDeVies;
// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
system("cls");
        Zombie = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Zombie > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Zombie : %d",Zombie);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+3 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Zombie aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+15 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Zombie >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Zombie repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Zombie");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Zombies.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Zombies.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un fourmillion\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Fourmillions.attaque = ADFourmillion;
Fourmillion = Fourmillions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        Fourmillion = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fourmillion > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fourmillion : %d",Fourmillion);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;

        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+3 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Fourmillion aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+15 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fourmillion >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Fourmillion repond a votre attaque en jettant viollement son femur sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Fourmillion");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fourmillions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fourmillions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un BebeDragon\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
BebeDragons.attaque = ADBebeDragon;
BebeDragon = BebeDragons.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        BebeDragon = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && BebeDragon > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du BebeDragon : %d",BebeDragon);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+3 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le BebeDragon aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+15 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(BebeDragon >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le BebeDragon repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du BebeDragon");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = BebeDragons.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= BebeDragons.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Le nihilisme de la deception\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
NihilismeDeLaDeceptions.attaque = ADNihilismeDeLaDeception;
NihilismeDeLaDeception = NihilismeDeLaDeceptions.pointsDeVies;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        NihilismeDeLaDeception = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && NihilismeDeLaDeception > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la NihilismeDeLaDeception : %d",NihilismeDeLaDeception);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+3 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le NihilismeDeLaDeception aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+15 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(NihilismeDeLaDeception >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le NihilismeDeLaDeception vous deprime et vous fait mal  ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du NihilismeDeLaDeception");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = NihilismeDeLaDeceptions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= NihilismeDeLaDeceptions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!



// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
}




// ===============================  REMISES DES RECOMPENSES ==================================

srand(time(NULL));
nombreRandome = rand() % 25;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 4;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 15;
    gold = gold + nombreRandome;
}


printf("\n             Pfiou... on s'en sort.... Allez poursuivons vers la salle suivante !\nRecompenses :\n Experiences + %d",bonusXP);
if(bonuxGOLD > 0){
    printf("\n Golds + %d",bonuxGOLD);
}

// ==========================  MONTEE DE LVL  ============================
if(pointsDexperience >= 100){


    printf("\n\n");
printf("\n     *********************************************************************************     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |//////////////////////////////**  LEVEL UP  **/////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////          Vos statistique augmentent !           ///////////////|     ");
printf("\n     |///////////////                  Attaque ++                     ///////////////|     ");
printf("\n     |///////////////                  Esquive ++                     ///////////////|     ");
printf("\n     |///////////////                  PV : Max         Niveau %d      ///////////////|     ",LevelAventurier+1);
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     ********************************************************************************|     ");

pointsDexperience = 0;
LevelAventurier++;
aventurier.attaque = aventurier.attaque +3;
aventurier.esquive = aventurier.esquive +3;
aventurier.pointsDeVies = 200;
PPSort1 = 10;
PPSort2 = 5;
PPSort3 = 3;


}

// ++++++++++ FIN MONTEE DE LVL +++++++++++
bonusXP = 0;
bonuxGOLD = 0;


// +++++++++++++++++++++++ REMISE DES RECOMPENSES ++++++++++++++++++++++




printf("\n\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

maxCombat++;
NombreDeSalles++;


break;
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++
// +++++++++++++++++++++++ FIN SALLE DE COMBAT ++++++++++++++++++++++++++++






// ========================= SALLE PIEGE ========================
// ========================= SALLE PIEGE ========================
// ========================= SALLE PIEGE ========================
case 6 :






srand(time(NULL));
nombreRandome = rand() % 5;


switch(nombreRandome){
case 0 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.75;
    printf("\n             Vous entre dans une salle un peu etrange... tout a coup le sol se derobe sous vos pieds\n             Mince... la chute vous a fait mal... vous perdez 25 %% de vos pv\n             Malheuresement ce n'est pas le pire... vous tombez d'un etage...");
    etageActuel--;
    printf("\n\n         Etage actuel : %d",etageActuel);
    break;
case 1 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.85;
    printf("\n             Cette salle vous semble etrange a premiere vue... Mais bon vous entre quand meme et\n              MERRDDE le murs commencent a se refermer sur vous...\n             Vous courrez vers la salle suivante mais\n              vous vous tordez tout de me la cheville et perder 15%% de vos PV");
   break;
case 2 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.95;
    printf("\n             Mince... devant vous se dresse une labyrinthe couvert de pique...\n             Vous vous egratinez un peu en passant et perder 5%% de vos PV");
    break;
case 3 :
    printf("\n              Devant vous un scientifique fou vous attend pour vous sequestrer...\n              Vous courrez et lui volez une potion rouge !");
    potionsRouge++;
    break;
case 4 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.50;
    printf("\n               Cette salle semble etrange... et cela se confirme lorsque vous marchez\n               sur une plaque de pression ce qui fait apparaitre des flammes de partout...\n               Vous perdez la moitie de vos PV");
    break;
case 5 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.25;
    printf("\n               Cette salle est etrange... Tout a coup un voile noir apparait et vous tombez dans les pommes...\n               Une fois reveille vous vous sentez tres faible...\n               Vous avez perdu les 3/4 de vos PV... Mais qu'elle etait cette ombre...");

break;

}
    pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;
NombreDeSalles++;

if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

NombreDeSalles++;

if(aventurier.pointsDeVies <= 0){
        for(i = 0 ; i<1500; i++){
            printf("§//010//1001 011101  0101001011  01//\\ //\\/  /\\//\\//\\//\\//\\");
        }
        system("cls");
        printf("\n             Vos yeux se plissent quant tout a coup la lumiere apparait, vous venez de mourir dans d'atroces souffrance\n             Enfin... maintenant vous ne sentez rien car c'est finit mais je vous jure que c'etait\n             écoeurant a voir...");
    printf("\n             ****************   GAME OVER   ****************\n             Vous n'avez malheursement pas survecu a ce donjon...\n             Il ne vous reste plus qua fermer le jeu et le rouvrir\n             Afin de recommencer a la derniere sauvegarde ! ");
    exit(1);
pointsDexperience = 0;
    gold = gold -10;
    aventurier.pointsDeVies = 50;

}


break;

//+++++++++++++++++++++ SALLE PIEGEE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE PIEGEE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE PIEGEE ++++++++++++++++++++++



// ========================= SALLE PIEGE ========================
// ========================= SALLE PIEGE ========================
// ========================= SALLE PIEGE ========================
// ========================= SALLE PIEGE ========================
// ========================= SALLE PIEGE ========================
// ========================= SALLE PIEGE ========================


case 15 :


srand(time(NULL));
nombreRandome = rand() % 5;


switch(nombreRandome){
case 0 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.75;
    printf("\n             Vous entre dans une salle un peu etrange... tout a coup le sol se derobe sous vos pieds\n             Mince... la chute vous a fait mal... vous perdez 25 %% de vos pv\n             Malheuresement ce n'est pas le pire... vous tombez d'un etage...");
    etageActuel--;
    printf("\n\n         Etage actuel : %d",etageActuel);
    break;
case 1 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.85;
    printf("\n             Cette salle vous semble etrange a premiere vue... Mais bon vous entre quand meme et\n              MERRDDE le murs commencent a se refermer sur vous...\n             Vous courrez vers la salle suivante mais\n              vous vous tordez tout de me la cheville et perder 15%% de vos PV");
   break;
case 2 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.95;
    printf("\n             Mince... devant vous se dresse une labyrinthe couvert de pique...\n             Vous vous egratinez un peu en passant et perder 5%% de vos PV");
    break;
case 3 :
    printf("\n              Devant vous un scientifique fou vous attend pour vous sequestrer...\n              Vous courrez et lui volez une potion rouge !");
    potionsRouge++;
    break;
case 4 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.50;
    printf("\n               Cette salle semble etrange... et cela se confirme lorsque vous marchez\n               sur une plaque de pression ce qui fait apparaitre des flammes de partout...\n               Vous perdez la moitie de vos PV");
    break;
case 5 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.25;
    printf("\n               Cette salle est etrange... Tout a coup un voile noir apparait et vous tombez dans les pommes...\n               Une fois reveille vous vous sentez tres faible...\n               Vous avez perdu les 3/4 de vos PV... Mais qu'elle etait cette ombre...");

break;

}
    pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;
NombreDeSalles++;

if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

NombreDeSalles++;



if(aventurier.pointsDeVies <= 0){
        for(i = 0 ; i<1500; i++){
            printf("§//010//1001 011101  0101001011  01//\\ //\\/  /\\//\\//\\//\\//\\");
        }
        system("cls");
        printf("\n             Vos yeux se plissent quant tout a coup la lumiere apparait, vous venez de mourir dans d'atroces souffrance\n             Enfin... maintenant vous ne sentez rien car c'est finit mais je vous jure que c'etait\n             écoeurant a voir...");
    printf("\n             ****************   GAME OVER   ****************\n             Vous n'avez malheursement pas survecu a ce donjon...\n             Il ne vous reste plus qua fermer le jeu et le rouvrir\n             Afin de recommencer a la derniere sauvegarde ! ");
    exit(1);
pointsDexperience = 0;
    gold = gold -10;
    aventurier.pointsDeVies = 50;

}


break;

//+++++++++++++++++++++ SALLE PIEGEE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE PIEGEE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE PIEGEE ++++++++++++++++++++++


// ========================= SALLE PIEGE ========================
// ========================= SALLE PIEGE ========================
// ========================= SALLE PIEGE ========================
case 17 :






srand(time(NULL));
nombreRandome = rand() % 5;


switch(nombreRandome){
case 0 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.75;
    printf("\n             Vous entre dans une salle un peu etrange... tout a coup le sol se derobe sous vos pieds\n             Mince... la chute vous a fait mal... vous perdez 25 %% de vos pv\n             Malheuresement ce n'est pas le pire... vous tombez d'un etage...");
    etageActuel--;
    printf("\n\n         Etage actuel : %d",etageActuel);
    break;
case 1 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.85;
    printf("\n             Cette salle vous semble etrange a premiere vue... Mais bon vous entre quand meme et\n              MERRDDE le murs commencent a se refermer sur vous...\n             Vous courrez vers la salle suivante mais\n              vous vous tordez tout de me la cheville et perder 15%% de vos PV");
   break;
case 2 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.95;
    printf("\n             Mince... devant vous se dresse une labyrinthe couvert de pique...\n             Vous vous egratinez un peu en passant et perder 5%% de vos PV");
    break;
case 3 :
    printf("\n              Devant vous un scientifique fou vous attend pour vous sequestrer...\n              Vous courrez et lui volez une potion rouge !");
    potionsRouge++;
    break;
case 4 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.50;
    printf("\n               Cette salle semble etrange... et cela se confirme lorsque vous marchez\n               sur une plaque de pression ce qui fait apparaitre des flammes de partout...\n               Vous perdez la moitie de vos PV");
    break;
case 5 :
    aventurier.pointsDeVies = aventurier.pointsDeVies*0.25;
    printf("\n               Cette salle est etrange... Tout a coup un voile noir apparait et vous tombez dans les pommes...\n               Une fois reveille vous vous sentez tres faible...\n               Vous avez perdu les 3/4 de vos PV... Mais qu'elle etait cette ombre...");

break;

}
    pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;
NombreDeSalles++;

if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

NombreDeSalles++;




if(aventurier.pointsDeVies <= 0){
        for(i = 0 ; i<1500; i++){
            printf("§//010//1001 011101  0101001011  01//\\ //\\/  /\\//\\//\\//\\//\\");
        }
        system("cls");
        printf("\n             Vos yeux se plissent quant tout a coup la lumiere apparait, vous venez de mourir dans d'atroces souffrance\n             Enfin... maintenant vous ne sentez rien car c'est finit mais je vous jure que c'etait\n             écoeurant a voir...");
    printf("\n             ****************   GAME OVER   ****************\n             Vous n'avez malheursement pas survecu a ce donjon...\n             Il ne vous reste plus qua fermer le jeu et le rouvrir\n             Afin de recommencer a la derniere sauvegarde ! ");
    exit(1);
pointsDexperience = 0;
    gold = gold -10;
    aventurier.pointsDeVies = 50;

}


break;

//+++++++++++++++++++++ SALLE PIEGEE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE PIEGEE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE PIEGEE ++++++++++++++++++++++




// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================
case 8 :


    printf("\n               Vous arrivez a la fin d'un couloir et faites face a deux portes\n               Quelle porte choisir....\n 1 : DROITE\n 2 : GAUCHE");
    scanf("%d",&choix4);
    srand(time(NULL));
nombreRandome = rand() % 100;
if(nombreRandome >= 50){
    nombreRandome = 2;
}
if(nombreRandome < 50){
    nombreRandome = 1;
}
    if(choix4 == nombreRandome ){
        printf("\n               Devant vous apparait 3 nouvelles portes... On dirait que\n               vous avez fait le bon choix... Laquelle choisir...\n 1 : DROITE\n 2 : GAUCHE\n 3 : MILIEUX");
        scanf("%d",&choix4);
       srand(time(NULL));
       nombreRandome = rand() % 100;
       if(nombreRandome >= 66){
    nombreRandome = 3;
}
if(nombreRandome >= 33 && nombreRandome <66){
    nombreRandome = 2;
}
if(nombreRandome < 33){
    nombreRandome = 1;
}
if(choix4 == nombreRandome){
    printf("\n               Devant vous apparait 4 nouvelles portes Encore... On dirait que\n               vous avez Encore fait le bon choix... Laquelle choisir Maintenant...\n 1 : DROITE\n 2 : GAUCHE\n 3 : HAUT\n 4 : BAS");
    scanf("%d",&choix4);
    srand(time(NULL));


          srand(time(NULL));
       nombreRandome = rand() % 100;
       if(nombreRandome >= 75){
    nombreRandome = 4;
}
if(nombreRandome >= 50 && nombreRandome<75){
    nombreRandome = 3;
}
if(nombreRandome >= 25 && nombreRandome<50){
    nombreRandome = 2;
}
if(nombreRandome < 25){
    nombreRandome = 1;
}



if(choix4 != nombreRandome){
        printf("\n             INCROYABLE vous trouvez la sortie du donjons.... Quelle chance dis donc");
 etageActuel = etageMAX;}


}
}


if(choix4 != nombreRandome){
    printf("\n          Tres bien... rien ne s'est passe.. vous continuer vers la salle suivante");
}
     pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

NombreDeSalles++;

if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
NombreDeSalles++;


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

break;
// ++++++++++++++++++++++ SALLE CHOIX ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE CHOIX ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE CHOIX ++++++++++++++++++++++





// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================

case 13 :


    printf("\n               Vous arrivez a la fin d'un couloir et faites face a deux portes\n               Quelle porte choisir....\n 1 : DROITE\n 2 : GAUCHE");
    scanf("%d",&choix4);
    srand(time(NULL));
nombreRandome = rand() % 100;
if(nombreRandome >= 50){
    nombreRandome = 2;
}
if(nombreRandome < 50){
    nombreRandome = 1;
}
    if(choix4 == nombreRandome ){
        printf("\n               Devant vous apparait 3 nouvelles portes... On dirait que\n               vous avez fait le bon choix... Laquelle choisir...\n 1 : DROITE\n 2 : GAUCHE\n 3 : MILIEUX");
        scanf("%d",&choix4);
       srand(time(NULL));
       nombreRandome = rand() % 100;
       if(nombreRandome >= 66){
    nombreRandome = 3;
}
if(nombreRandome >= 33 && nombreRandome <66){
    nombreRandome = 2;
}
if(nombreRandome < 33){
    nombreRandome = 1;
}
if(choix4 == nombreRandome){
    printf("\n               Devant vous apparait 4 nouvelles portes Encore... On dirait que\n               vous avez Encore fait le bon choix... Laquelle choisir Maintenant...\n 1 : DROITE\n 2 : GAUCHE\n 3 : HAUT\n 4 : BAS");
    scanf("%d",&choix4);
    srand(time(NULL));


          srand(time(NULL));
       nombreRandome = rand() % 100;
       if(nombreRandome >= 75){
    nombreRandome = 4;
}
if(nombreRandome >= 50 && nombreRandome<75){
    nombreRandome = 3;
}
if(nombreRandome >= 25 && nombreRandome<50){
    nombreRandome = 2;
}
if(nombreRandome < 25){
    nombreRandome = 1;
}



if(choix4 != nombreRandome){
        printf("\n             INCROYABLE vous trouvez la sortie du donjons.... Quelle chance dis donc");
 etageActuel = etageMAX;}


}
}


if(choix4 != nombreRandome){
    printf("\n          Tres bien... rien ne s'est passe.. vous continuer vers la salle suivante");
}
     pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

NombreDeSalles++;

if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
NombreDeSalles++;


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

break;
// ++++++++++++++++++++++ SALLE CHOIX ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE CHOIX ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE CHOIX ++++++++++++++++++++++



// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================
// ========================= SALLE CHOIX ========================

case 23 :


     printf("\n\n           OH WOAAW... en detour de ce couloir vous croisez un Sphinx en pierre O.o\n           IL SE MET A BOUGGGGEEEEERRR AAAAHHH VITE IL FAUT FUIR\n1 : NON\n2 : OUI");
      scanf("%d",&choix5);
      if(choix5 == 2){
        printf("\n           Vous prenez vos jambes a votre cou et fuiyez ce sphinx en pierre etrange... peut etre qu'il etait gentil en fait....");
      }
      if(choix5 == 1){

        printf("\n           VOUS ETES FOU aaahhh\n\n           'SILENCE VOYAGEUR ! PAR QUELLE VAILLANCE OSEZ VOUS ME REVEILLEZ DE MON SOMMEIL !?!?");
        printf("\n           'FINALEMENT CE N'EST PAS UNE SI MAUVAISE NOUVELLE... je meurs de faim'");
        printf("\n           'JE VAIS VOUS DEVORER ! A MOINS QUE VOUS REPONDIEZ JUSTE A 3 QUESTIONS D'AFFILES ! ");
        printf("\n           TREVE DE BAVARDAGE ! COMMENCONS LE QUIZZ DU SPHINX ! ");

        printf("\n\n/\\");
scanf("%d",&xanogene);
NombreDeSalles++;
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);


srand(time(NULL));
nombreRandome = rand() % 3;


switch(nombreRandome){


case 0 :
while(quizzSpinx == 0){
    printf("\n           Je marche a 4 au leve, a 2 au midi et a 3 le soir ! QUI-SUIS-JE ????\n1 : Le Soleil\n2 : L'Homme\n3 : Ta GROSSE MERE\n 4 : XAVIER DUPONT DE LIGONNES");
       scanf("%d",&choix1);
       if(choix1 != 2){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;
       }
       if(choix1 == 2){

        printf("\n\n\n           Bien... mais sauriez vous repondre correctement a celle ci ? : ");
        printf("\n           Combien de PV possede Lord Soupex ?\n1 : 0\n2 : 50\n3 : 100\n4 : 150 ");
        scanf("%d",&choix1);
         if(choix1 != 1){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;}

        if(choix1 == 1){

            printf("\n           Et Oui ! il y avait un piege ! vu qu'il est mort il en a 0.... Bravo voyageur !\n           Voici la derniere question....");
            printf("\n           Quelle est la Masse du Boson de Higgs selon l'ATLAS 2018\n1 : 1g\n2 : 1 nano g\n3 : 124,97 ± 0,24 GeV\n4 : 125,35 ± 0,15 GeV");
scanf("%d",&choix1);
            if(choix1 != 3){
                    printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
                quizzSpinx++;
            }

            if(choix1 == 3){

                printf("\n           Bon... Bravo voyageur vous avez prouve votre valeur ! vous pouvez continuer votre aventure mais avant !!\n           Laissez moi vous recompenser pour vos bonnes reponses !\n Ad : +5");
                printf("\n           Une nouvelle fois ! FELICITATION");
                aventurier.attaque = aventurier.attaque +5;}


}
}



quizzSpinx++;


      // QUIZZ SPHINX
      }
break;


case 1 :
    while(quizzSpinx == 0){
    printf("\n           DONNEZ MOI l'orthographe correcte de ce celebre philosophe allemand !\n1 : Schopenhauer\n2 : Schoppenhauer\n3 : Schopenhawer\n4 : Schopennhauer");
       scanf("%d",&choix1);
       if(choix1 != 1){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;
       }
       if(choix1 == 1){

        printf("\n\n\n           Bien... mais sauriez vous repondre correctement a celle ci ? : ");
        printf("\n           Quelle age avait la copine de TK78 ?\n1 : 21\n2 : 23\n3 : 32\n4 : 16 ");
        scanf("%d",&choix1);
         if(choix1 != 4){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;}

        if(choix1 == 4){

            printf("\n           Et Oui ! il y avait un piege ! vu qu'il est mineur Ahaha.... Glauque eurk !\n           Voici la derniere question....");
            printf("\n           Combien possediez vous d'AD au monde 1 niveau 1 ?\n1 : 3\n2 : 6\n3 : 5\n4 : 4");
            scanf("%d",&choix1);

            if(choix1 != 3){
                    printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
                quizzSpinx++;
            }

            if(choix1 == 3){

                printf("\n           Bon... Bravo voyageur vous avez prouve votre valeur ! vous pouvez continuer votre aventure mais avant !!\n           Laissez moi vous recompenser pour vos bonnes reponses !\n Ad : +5");
                printf("\n           Une nouvelle fois ! FELICITATION");
                aventurier.attaque = aventurier.attaque +5;}


}
}




quizzSpinx++;

      // QUIZZ SPHINX
      }

break;

case 2 :
    while(quizzSpinx == 0){
    printf("\n           Donnez moi la raison pour laquelle Dr dissrespect a ete bann de twitch !!\n1 : Viol avere\n2 : insulte envers Twitch et ses employes\n3 : 'wtf les gars g ete ban'\n 4 : Whallah je c pa");
       scanf("%d",&choix1);
       if(choix1 != 4){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;
       }
       if(choix1 == 4){

        printf("\n\n\n           Bien... mais sauriez vous repondre correctement a celle ci ? : ");
        printf("\n           Parmis ces isotope lequel en est un stable du Seaborgium ?\n1 : 269Sg\n2 : 51Sg\n3 : 669Sg\n4 : 169Sg ");
        scanf("%d",&choix1);
         if(choix1 != 1){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;}

        if(choix1 == 1){

            printf("\n           Et Oui ! qui l'eu cru que 269Sg etait un isotope stable ahah.... !\n           Voici la derniere question....");
            printf("\n           Parmis ces numeros, lequel appartient a Gerard Heintz ?  ?\n1 : 06-12-87-42-93\n2 : 07-85-45-36-92\n3 : 06-87-01-28-99\n4 : 06-18-80-40-22");
    scanf("%d",&choix1);

            if(choix1 != 4){
                    printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
                quizzSpinx++;
            }

            if(choix1 == 4){

                printf("\n           Bon... Bravo voyageur vous avez prouve votre valeur ! vous pouvez continuer votre aventure mais avant !!\n           Laissez moi vous recompenser pour vos bonnes reponses !\n Ad : +5");
                printf("\n           Une nouvelle fois ! FELICITATION");
                aventurier.attaque = aventurier.attaque +5;}


}
}





quizzSpinx++;
      // QUIZZ SPHINX
      }

break;





}
// CHOIX OUI
}
    break;
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++



case 4 :
// ============================= SALLE coffreSecret ==============================
// ============================= SALLE coffreSecret ==============================
// ============================= SALLE coffreSecret ==============================
// ============================= SALLE coffreSecret ==============================









if( maxSubmerge <= 1){

 printf("\n           Devant vous un UN COFFRE... cependant impossible de l'ouvrir sans clef\n           Voulez vous quand meme essayer ?\n 1 : OUI\n 2 : NON");
 scanf("%d",&choix4);
 if(choix4 == 1 && petitclef == 0){
    for(i = 0 ; i <2000 ; i++){
        printf("click clic  click clic click clic click clic click clic     click clic         click clic");
    }
    system("cls");
    printf("\n           le coffre refuse de s'ouvrir et vous avez declenche un piege...\n           Vous finissez ecrabouiller par les murs et mourrez...");
    aventurier.pointsDeVies = 0;
 }


 if(choix4 == 1 && petitclef == 1){
    for(i = 0 ; i <2000 ; i++){
        printf("click clic  click clic click clic click clic click clic     click clic         click clic");

    }
    system("cls");
   printf("\n           Vous parvenez a ouvrir le coffre !!\n           Dedans... QUOI... une viege carte toute naze pff ca ne servira jamais a rien ce machin... !!\n           Bon vous avez perdu votre temps et votre clef pour ca.... on va la sauvegarder au moins... !!");


printf("\n     ***********************************************************     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXX@@@@@@@@@@@@@@@@@XXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXXXXX@XXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXX         XXXXXXXXXXX@@XXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXX   WIN   XXXXXXX@@@@@XXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXX         XXXXXXX@XXXXXXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@@@@@XXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXX|     ");
printf("\n     ***********************************************************     ");

   // CARTE AU TRESOR

   fichier = fopen("Saves/CarteAuTresor.txt","w+");
fprintf(fichier,"\n     ***********************************************************     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXX@@@@@@@@@@@@@@@@@XXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXXXXX@XXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXX         XXXXXXXXXXX@@XXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXX   WIN   XXXXXXX@@@@@XXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXX         XXXXXXX@XXXXXXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@@@@@XXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXX|     ");
fprintf(fichier,"\n     ***********************************************************     ");
fclose(fichier);


   // CARTE AU TRESOR






   petitclef = 0;
 }
 if(choix4 == 2){

    printf("\n           Vous tournez le dos a ce coffre sans connaitre son contenu... \n           Mais avec au moins sain et sauf...");

 }
 NombreDeSalles++;
   pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

maxSubmerge++;
}
srand(time(NULL));
nombreRandome = rand() % 28;
break;

// ++++++++++++++++++++++ SALLE SUBMERGER ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE SUBMERGER ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE SUBMERGER ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE SUBMERGER ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE SUBMERGER ++++++++++++++++++++++





case 14 :
// ============================= SALLE coffreSecret ==============================
// ============================= SALLE coffreSecret ==============================
// ============================= SALLE coffreSecret ==============================
// ============================= SALLE coffreSecret ==============================









if( maxSubmerge <= 1){

 printf("\n           Devant vous un UN COFFRE... cependant impossible de l'ouvrir sans clef\n           Voulez vous quand meme essayer ?\n 1 : OUI\n 2 : NON");
 scanf("%d",&choix4);
 if(choix4 == 1 && petitclef == 0){
    for(i = 0 ; i <2000 ; i++){
        printf("click clic  click clic click clic click clic click clic     click clic         click clic");
    }
    system("cls");
    printf("\n           le coffre refuse de s'ouvrir et vous avez declenche un piege...\n           Vous finissez ecrabouiller par les murs et mourrez...");
    aventurier.pointsDeVies = 0;
 }


 if(choix4 == 1 && petitclef == 1){
    for(i = 0 ; i <2000 ; i++){
        printf("click clic  click clic click clic click clic click clic     click clic         click clic");

    }
    system("cls");
   printf("\n           Vous parvenez a ouvrir le coffre !!\n           Dedans... QUOI... une viege carte toute naze pff ca ne servira jamais a rien ce machin... !!\n           Bon vous avez perdu votre temps et votre clef pour ca.... on va la sauvegarder au moins... !!");
   petitclef = 0;


printf("\n     ***********************************************************     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXX@@@@@@@@@@@@@@@@@XXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXXXXX@XXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXX         XXXXXXXXXXX@@XXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXX   WIN   XXXXXXX@@@@@XXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXX         XXXXXXX@XXXXXXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@@@@@XXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXX|     ");
printf("\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXX|     ");
printf("\n     ***********************************************************     ");


   // CARTE AU TRESOR

   fichier = fopen("Saves/CarteAuTresor.txt","w+");
fprintf(fichier,"\n     ***********************************************************     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXX@@@@@@@@@@@@@@@@@XXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXXXXX@XXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXX         XXXXXXXXXXX@@XXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXX   WIN   XXXXXXX@@@@@XXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXX         XXXXXXX@XXXXXXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@@@@@XXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXX|     ");
fprintf(fichier,"\n     |XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX@XXXXXXXXXXXX|     ");
fprintf(fichier,"\n     ***********************************************************     ");
fclose(fichier);


   // CARTE AU TRESOR






 }
 if(choix4 == 2){

    printf("\n           Vous tournez le dos a ce coffre sans connaitre son contenu... \n           Mais avec au moins sain et sauf...");

 }
 NombreDeSalles++;
   pourcentageEsquallier = pourcentageEsquallier*1.5;
pourcentageTresor = pourcentageTresor*1.2;

if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

maxSubmerge++;
}
srand(time(NULL));
nombreRandome = rand() % 28;
break;

// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++




case 22 :

srand(time(NULL));
nombreRandome = rand() % 4;

switch(nombreRandome){

  case 0 :
  printf("\n              Mince... Ou plutot tant mieux, une salle vide apparait sous vos yeux !");
  break;
  case 1 :
    printf("\n              Une salle vide s'offre un vous ! une bonne occasion pour se reposer et stacker l'escallier");
    break;
  case 2 :
    printf("\n              Quelle chance une salle vide c'est ce dont vous avez toujours reve ! ");
    break;
  case 3 :
    printf("\n              WOAAAWWW YESSS PUTAIN OUUAAAIIIS TROOPPP BIEN SA MERRE POULOULOULOU...\n              Une salle vide");
    break;
  case 4 :
    printf("\n              *INSEREZ UN MESSAGE POUR ANNONCER UNE SALLE VIDE");

}


  printf("\n              Vous continuez votre route vers la salle suivante");

   NombreDeSalles++;
   pourcentageEsquallier = pourcentageEsquallier *1.5;
   pourcentageTresor = pourcentageTresor*1.5;
   scanf("%d",&xanogene);

   if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);
NombreDeSalles++;
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

break;

// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++






// ========================= SALLE ESCALLIER ========================
// ========================= SALLE ESCALLIER ========================
// ========================= SALLE ESCALLIER ========================
// ========================= SALLE ESCALLIER ========================

case 10 :
    if(NombreDeSalles >= 4){

         printf("\n             IN-CRO-YABLE !! vous venez de trouver la salle de l'escalier QUELLE CHANCE !! FAITES PETER LES ETOILES\n             *****************************************************\n             *******************************\n             ***********************");

    printf("\n              Vous vous monter des maintenant a l'etage suivant ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&ChoixEscallier);

    if(ChoixEscallier == 2 ){
        printf("\n          Tres bien ! Vous pouvez continuer dans cet etage tout en vous\n           dirigeant a cet escallier via l'amulette quand vous voulez");
        AmuletteEscallier = 1;
        pourcentageEsquallier = 0;
    }
    if(ChoixEscallier == 1){
    printf("\n             Vous montez a present a l'etage superieur ! ");
    NombreDeSalles++;
    etageActuel++;
    pourcentageEsquallier = 7;
    printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |     Xp : %d/100      |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,pointsDexperience,aventurier.pointsDeVies,gold);}
    }
srand(time(NULL));
nombreRandome = rand() % 28;
break;
// ++++++++++++++++++++++++++    SALLE ESCALLIER   ++++++++++++++++++++++++
// ++++++++++++++++++++++++++    SALLE ESCALLIER   ++++++++++++++++++++++++
// ++++++++++++++++++++++++++    SALLE ESCALLIER   ++++++++++++++++++++++++
// ++++++++++++++++++++++++++    SALLE ESCALLIER   ++++++++++++++++++++++++

// ========================= SALLE ESCALLIER ========================
// ========================= SALLE ESCALLIER ========================
// ========================= SALLE ESCALLIER ========================
// ========================= SALLE ESCALLIER ========================


default :
    if(NombreDeSalles >= 10){
    printf("\n             IN-CRO-YABLE !! vous venez de trouver la salle de l'escalier QUELLE CHANCE !! FAITES PETER LES ETOILES\n             *****************************************************\n             *******************************\n             ***********************");

    printf("\n              Vous vous monter des maintenant a l'etage suivant ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&ChoixEscallier);

    if(ChoixEscallier == 2 ){
        printf("\n          Tres bien ! Vous pouvez continuer dans cet etage tout en vous\n           dirigeant a cet escallier via l'amulette quand vous voulez");
        AmuletteEscallier = 1;
        pourcentageEsquallier = 0;
    }
    if(ChoixEscallier == 1){
    printf("\n             Vous montez a present a l'etage superieur ! ");
    NombreDeSalles++;
    etageActuel++;
    pourcentageEsquallier = 7;
    printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |     Xp : %d/100      |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,pointsDexperience,aventurier.pointsDeVies,gold);}
}
break;
// ++++++++++++++++++++++++++    SALLE ESCALLIER   ++++++++++++++++++++++++
// ++++++++++++++++++++++++++    SALLE ESCALLIER   ++++++++++++++++++++++++
// ++++++++++++++++++++++++++    SALLE ESCALLIER   ++++++++++++++++++++++++
// ++++++++++++++++++++++++++    SALLE ESCALLIER   ++++++++++++++++++++++++



// ========================= SALLE VIDE =============================
// ========================= SALLE VIDE =============================
// ========================= SALLE VIDE =============================
// ========================= SALLE VIDE =============================
case 5 :

srand(time(NULL));
nombreRandome = rand() % 4;

switch(nombreRandome){

  case 0 :
  printf("\n              Mince... Ou plutot tant mieux, une salle vide apparait sous vos yeux !");
  break;
  case 1 :
    printf("\n              Une salle vide s'offre un vous ! une bonne occasion pour se reposer et stacker l'escallier");
    break;
  case 2 :
    printf("\n              Quelle chance une salle vide c'est ce dont vous avez toujours reve ! ");
    break;
  case 3 :
    printf("\n              WOAAAWWW YESSS PUTAIN OUUAAAIIIS TROOPPP BIEN SA MERRE POULOULOULOU...\n              Une salle vide");
    break;
  case 4 :
    printf("\n              *INSEREZ UN MESSAGE POUR ANNONCER UNE SALLE VIDE");

}


  printf("\n              Vous continuez votre route vers la salle suivante");

   NombreDeSalles++;
   pourcentageEsquallier = pourcentageEsquallier *1.5;
   pourcentageTresor = pourcentageTresor*1.5;
   scanf("%d",&xanogene);

   if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);
NombreDeSalles++;
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
break;
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++




case 16 :
// ========================= SALLE VIDE =============================
// ========================= SALLE VIDE =============================
// ========================= SALLE VIDE =============================
// ========================= SALLE VIDE =============================

srand(time(NULL));
nombreRandome = rand() % 4;

switch(nombreRandome){

  case 0 :
  printf("\n              Mince... Ou plutot tant mieux, une salle vide apparait sous vos yeux !");
  break;
  case 1 :
    printf("\n              Une salle vide s'offre un vous ! une bonne occasion pour se reposer et stacker l'escallier");
    break;
  case 2 :
    printf("\n              Quelle chance une salle vide c'est ce dont vous avez toujours reve ! ");
    break;
  case 3 :
    printf("\n              WOAAAWWW YESSS PUTAIN OUUAAAIIIS TROOPPP BIEN SA MERRE POULOULOULOU...\n              Une salle vide");
    break;
  case 4 :
    printf("\n              *INSEREZ UN MESSAGE POUR ANNONCER UNE SALLE VIDE");

}


  printf("\n              Vous continuez votre route vers la salle suivante");

   NombreDeSalles++;
   pourcentageEsquallier = pourcentageEsquallier *1.5;
   pourcentageTresor = pourcentageTresor*1.5;
   scanf("%d",&xanogene);

   if(AmuletteEscallier == 1){
    printf("\n        Voulez vous vous dirigez a l'etage suivant via l'amulette d'escallier ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix2);
    if(choix2 == 1){
            printf("\n         Vous vous dirigez ves la salle de l'escalier dont vous vous souvenez de la position");
        etageActuel++;
        AmuletteEscallier = 0;
    }
    if(choix2 == 2){
        printf("\n           Vous continuez votre route");
    }
}
printf("\n/\\");
scanf("%d",&xanogene);
NombreDeSalles++;
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
break;
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++



// ==================== SALLE DU SPHINX ====================
// ==================== SALLE DU SPHINX ====================
// ==================== SALLE DU SPHINX ====================
// ==================== SALLE DU SPHINX ====================
// ==================== SALLE DU SPHINX ====================
// ==================== SALLE DU SPHINX ====================

  case 26 :

      printf("\n\n           OH WOAAW... en detour de ce couloir vous croisez un Sphinx en pierre O.o\n           IL SE MET A BOUGGGGEEEEERRR AAAAHHH VITE IL FAUT FUIR\n1 : NON\n2 : OUI");
      scanf("%d",&choix5);
      if(choix5 == 2){
        printf("\n           Vous prenez vos jambes a votre cou et fuiyez ce sphinx en pierre etrange... peut etre qu'il etait gentil en fait....");
      }
      if(choix5 == 1){

        printf("\n           VOUS ETES FOU aaahhh\n\n           'SILENCE VOYAGEUR ! PAR QUELLE VAILLANCE OSEZ VOUS ME REVEILLEZ DE MON SOMMEIL !?!?");
        printf("\n           'FINALEMENT CE N'EST PAS UNE SI MAUVAISE NOUVELLE... je meurs de faim'");
        printf("\n           'JE VAIS VOUS DEVORER ! A MOINS QUE VOUS REPONDIEZ JUSTE A 3 QUESTIONS D'AFFILES ! ");
        printf("\n           TREVE DE BAVARDAGE ! COMMENCONS LE QUIZZ DU SPHINX ! ");

        printf("\n\n/\\");
scanf("%d",&xanogene);
NombreDeSalles++;
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);


srand(time(NULL));
nombreRandome = rand() % 3;


switch(nombreRandome){


case 0 :
while(quizzSpinx == 0){
    printf("\n           Je marche a 4 au leve, a 2 au midi et a 3 le soir ! QUI-SUIS-JE ????\n1 : Le Soleil\n2 : L'Homme\n3 : Ta GROSSE MERE \n 4 : XAVIER DUPONT DE LIGONNES");
       scanf("%d",&choix1);
       if(choix1 != 2){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;
       }
       if(choix1 == 2){

        printf("\n\n\n           Bien... mais sauriez vous repondre correctement a celle ci ? : ");
        printf("\n           Combien de PV possede Lord Soupex ?\n1 : 0\n2 : 50\n3 : 100\n4 : 150 ");
        scanf("%d",&choix1);
         if(choix1 != 1){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;}

        if(choix1 == 1){

            printf("\n           Et Oui ! il y avait un piege ! vu qu'il est mort il en a 0.... Bravo voyageur !\n           Voici la derniere question....");
            printf("\n           Quelle est la Masse du Boson de Higgs selon l'ATLAS 2018\n1 : 1g\n2 : 1 nano g\n3 : 124,97 ± 0,24 GeV\n4 : 125,35 ± 0,15 GeV");
scanf("%d",&choix1);
            if(choix1 != 3){
                    printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
                quizzSpinx++;
            }

            if(choix1 == 3){

                printf("\n           Bon... Bravo voyageur vous avez prouve votre valeur ! vous pouvez continuer votre aventure mais avant !!\n           Laissez moi vous recompenser pour vos bonnes reponses !\n Ad : +5");
                printf("\n           Une nouvelle fois ! FELICITATION");
                aventurier.attaque = aventurier.attaque +5;}


}
}



quizzSpinx++;


      // QUIZZ SPHINX
      }
break;


case 1 :
    while(quizzSpinx == 0){
    printf("\n           DONNEZ MOI l'orthographe correcte de ce celebre philosophe allemand !\n1 : Schopenhauer\n2 : Schoppenhauer\n3 : Schopenhawer\n4 : Schopennhauer");
       scanf("%d",&choix1);
       if(choix1 != 1){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;
       }
       if(choix1 == 1){

        printf("\n\n\n           Bien... mais sauriez vous repondre correctement a celle ci ? : ");
        printf("\n           Quelle age avait la copine de TK78 ?\n1 : 21\n2 : 23\n3 : 32\n4 : 16 ");
        scanf("%d",&choix1);
         if(choix1 != 4){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;}

        if(choix1 == 4){

            printf("\n           Et Oui ! il y avait un piege ! vu qu'il est mineur Ahaha.... Glauque eurk !\n           Voici la derniere question....");
            printf("\n           Combien possediez vous d'AD au monde 1 niveau 1 ?\n1 : 3\n2 : 6\n3 : 5\n4 : 4");
            scanf("%d",&choix1);

            if(choix1 != 3){
                    printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
                quizzSpinx++;
            }

            if(choix1 == 3){

                printf("\n           Bon... Bravo voyageur vous avez prouve votre valeur ! vous pouvez continuer votre aventure mais avant !!\n           Laissez moi vous recompenser pour vos bonnes reponses !\n Ad : +5");
                printf("\n           Une nouvelle fois ! FELICITATION");
                aventurier.attaque = aventurier.attaque +5;}


}
}




quizzSpinx++;

      // QUIZZ SPHINX
      }

break;

case 2 :
    while(quizzSpinx == 0){
    printf("\n           Donnez moi la raison pour laquelle Dr dissrespect a ete bann de twitch !!\n1 : Viol avere\n2 : insulte envers Twitch et ses employes\n3 : 'wtf les gars g ete ban'\n 4 : Whallah je c pa");
       scanf("%d",&choix1);
       if(choix1 != 4){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;
       }
       if(choix1 == 4){

        printf("\n\n\n           Bien... mais sauriez vous repondre correctement a celle ci ? : ");
        printf("\n           Parmis ces isotope lequel en est un stable du Seaborgium ?\n1 : 269Sg\n2 : 51Sg\n3 : 669Sg\n4 : 169Sg ");
        scanf("%d",&choix1);
         if(choix1 != 1){
            printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
        quizzSpinx++;}

        if(choix1 == 1){

            printf("\n           Et Oui ! qui l'eu cru que 269Sg etait un isotope stable ahah.... !\n           Voici la derniere question....");
            printf("\n           Parmis ces numeros, lequel appartient a Gerard Heintz ?  ?\n1 : 06-12-87-42-93\n2 : 07-85-45-36-92\n3 : 06-87-01-28-99\n4 : 06-18-80-40-22");
    scanf("%d",&choix1);

            if(choix1 != 4){
                    printf("\n           MAUVAISE REPONSE BIENVENU DANS MON VENTRE MOUHAHAHA ");
       printf("\n           Etage actuel -1 : %d",etageActuel);
                quizzSpinx++;
            }

            if(choix1 == 4){

                printf("\n           Bon... Bravo voyageur vous avez prouve votre valeur ! vous pouvez continuer votre aventure mais avant !!\n           Laissez moi vous recompenser pour vos bonnes reponses !\n Ad : +5");
                printf("\n           Une nouvelle fois ! FELICITATION");
                aventurier.attaque = aventurier.attaque +5;}


}
}





quizzSpinx++;
      // QUIZZ SPHINX
      }

break;





}
// CHOIX OUI

}
    break;
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++
// ++++++++++++++++++ SALLE SPHINX ++++++++++++++++++++++++











}
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ SWITCH DES SALLES PAS TOUCHE IMPORTANT +++++++++++++++++++++++++++++++



// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
// WHILE DONJON PAS TOUCHER JAMAIS DE LA VIE  ========================================================
}


if(aventurier.pointsDeVies <= 0){
        for(i = 0 ; i<1500; i++){
            printf("§//010//1001 011101  0101001011  01//\\ //\\/  /\\//\\//\\//\\//\\");
        }
        system("cls");
        printf("\n             Vos yeux se plissent quant tout a coup la lumiere apparait, vous venez de mourir dans d'atroces souffrance\n             Enfin... maintenant vous ne sentez rien car c'est finit mais je vous jure que c'etait\n             écoeurant a voir...");
    printf("\n             ****************   GAME OVER   ****************\n             Vous n'avez malheursement pas survecu a ce donjon...\n             Il ne vous reste plus qua fermer le jeu et le rouvrir\n             Afin de recommencer a la derniere sauvegarde ! ");
    exit(1);
pointsDexperience = 0;
    gold = gold -10;
    aventurier.pointsDeVies = 50;

}





// ====================================== MINI BOSS ==============================================
// ====================================== MINI BOSS ==============================================
// ====================================== MINI BOSS ==============================================
// ====================================== MINI BOSS ==============================================
// ====================================== MINI BOSS ==============================================
// ====================================== MINI BOSS ==============================================
// ====================================== MINI BOSS ==============================================
if(miniBoss >= 1){
    printf("\n        Oh... ");
printf("\n/\\");
scanf("%d",&xanogene);

printf("\n        Grrooooaaaaaaaaa");
printf("\n        Vos soupscons se sont averes vrais... les flammes ont attire un monstre et il vous a suivi jusqu'ici...");
printf("\n        Le combat commence ! ");




 srand(time(NULL));
nombreRandome = rand() % 3;

// =================================================== DEBUT DU SWITHC COMBAT GOBELIN SQUELETTE FANTOME SORCIERE =======================================

switch(nombreRandome){
case 0 : printf("\n               Vous faites face a un Zombie ENRAGE");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Zombies.attaque = ADZombie*1.5;
Zombie = Zombies.pointsDeVies*1.5;
// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
system("cls");
        Zombie = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Zombie > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Zombie : %d",Zombie);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+3 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Zombie aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque+15 - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Zombies.esquive){
    printf("\n              Le Zombie esquive votre attaque");
}

if(nombreRandome >= Zombies.esquive){
degatsInflige = aventurier.attaque - Zombies.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Zombie = Zombie - degatsInflige;
printf("\n             vous infligez %d points de degats au Zombie",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Zombie >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Zombie repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Zombie");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Zombies.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Zombies.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Zombie WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================
// ======================= COMBAT fourmillion  ====================

case 1 : printf("\n               Vous faites face a un Fourmillion ENRAGE");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
Fourmillions.attaque = ADFourmillion*1.5;
Fourmillion = Fourmillions.pointsDeVies*1.5;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        Fourmillion = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fourmillion > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fourmillion : %d",Fourmillion);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;

        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+3 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Fourmillion aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque+15 - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fourmillions.esquive){
    printf("\n              Le Fourmillion esquive votre attaque");
}

if(nombreRandome >= Fourmillions.esquive){
degatsInflige = aventurier.attaque - Fourmillions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fourmillion = Fourmillion - degatsInflige;
printf("\n             vous infligez %d points de degats au Fourmillion",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fourmillion >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Fourmillion repond a votre attaque en jettant viollement son femur sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Fourmillion");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fourmillions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fourmillions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Fourmillion WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================
// ======================= COMBAT bebedragon  ====================





case 2 : printf("\n               Vous faites face a un Bebe Dragon ENRAGE");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
BebeDragons.attaque = ADBebeDragon*1.5;
BebeDragon = BebeDragons.pointsDeVies*1.5;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        BebeDragon = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && BebeDragon > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du BebeDragon : %d",BebeDragon);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+3 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le BebeDragon aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque+15 - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < BebeDragons.esquive){
    printf("\n              Le BebeDragon esquive votre attaque");
}

if(nombreRandome >= BebeDragons.esquive){
degatsInflige = aventurier.attaque - BebeDragons.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

BebeDragon = BebeDragon - degatsInflige;
printf("\n             vous infligez %d points de degats au BebeDragon",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(BebeDragon >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le BebeDragon repond a votre attaque en se ruant sur vous ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du BebeDragon");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = BebeDragons.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= BebeDragons.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================
// ======================= COMBAT Nihilisme  ====================

case 3 : printf("\n               Vous faites face au NihilismeDeLaDeception ENRAGE");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
NihilismeDeLaDeceptions.attaque = ADNihilismeDeLaDeception*1.5;
NihilismeDeLaDeception = NihilismeDeLaDeceptions.pointsDeVies*1.5;

// ===============   UTILISATION SMOKE BOMB    =================
if(SmokeBomb > 0){
    printf("\n             Vous possedez une grenade fumigene ? Voulez vous l'utiliser pour fuir le combat ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        SmokeBomb--;
            for(i = 0 ; i < 2000 ; i++){
            printf("10101110101011010100010101");
        }
        system("cls");
        NihilismeDeLaDeception = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && NihilismeDeLaDeception > 0 ){

printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la NihilismeDeLaDeception : %d",NihilismeDeLaDeception);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}






printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+3 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le NihilismeDeLaDeception aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque+15 - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe au monstre");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < NihilismeDeLaDeceptions.esquive){
    printf("\n              Le NihilismeDeLaDeception esquive votre attaque");
}

if(nombreRandome >= NihilismeDeLaDeceptions.esquive){
degatsInflige = aventurier.attaque - NihilismeDeLaDeceptions.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

NihilismeDeLaDeception = NihilismeDeLaDeception - degatsInflige;
printf("\n             vous infligez %d points de degats au NihilismeDeLaDeception",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(NihilismeDeLaDeception >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le NihilismeDeLaDeception vous deprime et vous fait mal  ! ");
break;
case 1 :
    printf("\n              Ce monstre vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! il va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce monstre vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de monstre vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce monstre vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du NihilismeDeLaDeception");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = NihilismeDeLaDeceptions.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= NihilismeDeLaDeceptions.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT SORCIERE WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!
// INSEREZ ICI NOUVEAUX MOBS  !!



// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++FIN DU SWITCH COMBAT GOBELIN SQUELETTE FANTOME SORCIERE +++++++++++++++++++++++++++++++++++++
}




// ===============================  REMISES DES RECOMPENSES ==================================

srand(time(NULL));
nombreRandome = rand() % 25;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 4;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 15;
    gold = gold + nombreRandome;
}


printf("\n             Pfiou... on s'en sort.... Allez vite quittons ce donjon de malheur... !\nRecompenses :\n Experiences + %d",bonusXP);
if(bonuxGOLD > 0){
    printf("\n Golds + %d",bonuxGOLD);
}

// ==========================  MONTEE DE LVL  ============================
if(pointsDexperience >= 100){


    printf("\n\n");
printf("\n     *********************************************************************************     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |//////////////////////////////**  LEVEL UP  **/////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////          Vos statistique augmentent !           ///////////////|     ");
printf("\n     |///////////////                  Attaque ++                     ///////////////|     ");
printf("\n     |///////////////                  Esquive ++                     ///////////////|     ");
printf("\n     |///////////////                  PV : Max         Niveau %d      ///////////////|     ",LevelAventurier+1);
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     ********************************************************************************|     ");

pointsDexperience = 0;
LevelAventurier++;
aventurier.attaque = aventurier.attaque +3;
aventurier.esquive = aventurier.esquive +3;
aventurier.pointsDeVies = 200;
PPSort1 = 10;
PPSort2 = 5;
PPSort3 = 3;


}

// ++++++++++ FIN MONTEE DE LVL +++++++++++
bonusXP = 0;
bonuxGOLD = 0;


// +++++++++++++++++++++++ REMISE DES RECOMPENSES ++++++++++++++++++++++





printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);














}
// +++++++++++++++++++++++++++++++++++ MINI BOSS ++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++ MINI BOSS ++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++ MINI BOSS ++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++ MINI BOSS ++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++ MINI BOSS ++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++ MINI BOSS ++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++ MINI BOSS ++++++++++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++ MINI BOSS ++++++++++++++++++++++++++++++++++++++++++++++

if(aventurier.pointsDeVies <= 0){
        for(i = 0 ; i<1500; i++){
            printf("§//010//1001 011101  0101001011  01//\\ //\\/  /\\//\\//\\//\\//\\");
        }
        system("cls");
        printf("\n             Vos yeux se plissent quant tout a coup la lumiere apparait, vous venez de mourir dans d'atroces souffrance\n             Enfin... maintenant vous ne sentez rien car c'est finit mais je vous jure que c'etait\n             écoeurant a voir...");
    printf("\n             ****************   GAME OVER   ****************\n             Vous n'avez malheursement pas survecu a ce donjon...\n             Il ne vous reste plus qua fermer le jeu et le rouvrir\n             Afin de recommencer a la derniere sauvegarde ! ");
    exit(1);
pointsDexperience = 0;
    gold = gold -10;
    aventurier.pointsDeVies = 50;

}


// ====================================================================================   BOSS VOLTREX ===========================================
// ====================================================================================   BOSS VOLTREX ===========================================
// ====================================================================================   BOSS VOLTREX ===========================================
// ====================================================================================   BOSS VOLTREX ===========================================
// ====================================================================================   BOSS VOLTREX ===========================================
// ====================================================================================   BOSS VOLTREX ===========================================
// ====================================================================================   BOSS VOLTREX ===========================================
// ====================================================================================   BOSS VOLTREX ===========================================
// ====================================================================================   BOSS VOLTREX ===========================================
// ====================================================================================   BOSS VOLTREX ===========================================

if(MondeActuel == 2 && NiveauActuel == 5){

        for(b = 0 ; b< 3000 ; b++){
            printf("CKKRRIRIIIIICCCKKCKCRRRIIKKCKC SDQDSQDZZRUUUUUU VOK'Nejsdh");
        }
        system("cls");
        printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n\n        'Voj'ni ksa fjsundy cramo dsu'");
printf("\n         Toutes les legendes de la Dry-Dry Toundra parlent de ce monstre.... le Voltrex il est devenant nous....\n         Je suis autant effraye que fascine ! c'est fantastique de voir ca !!!....\n         Enfin... il va falloir le tuer si nous ne voulons as y passer... il n'a pas l'air de vouloir discuter...\n         Bon courage Aventurier");
printf("\n\n         'Val'sharah uijsu umla shu shu sjuhaaaaaaaaaaa");

Voltrex = Voltrexx.pointsDeVies;



// ============================== DEBUT DU COMBAT  VORTEX ===================================
while(aventurier.pointsDeVies > 0 && Voltrex > 0 ){





    // ========================  PHASE + VOLTREX =========================
     // ========================  PHASE + VOLTREX =========================
      // ========================  PHASE + VOLTREX =========================
       // ========================  PHASE + VOLTREX =========================
        // ========================  PHASE + VOLTREX =========================
         // ========================  PHASE + VOLTREX =========================
          // ========================  PHASE + VOLTREX =========================
           // ========================  PHASE + VOLTREX =========================
  if(aventurier.pointsDeVies > 0 && Voltrex < 70 && VoltrexEnfouissement == 0){

    printf("\n             Le Voltrex appeure s'enfouie dans le sol ");
    printf("\n             La plafond commence a s'effondrer !! il faut vite s'enfuire...");
    printf("\n             *CRRACCKK*");
    printf("\n\n\n             MINCE le Voltrex nous guette depuis le sol... il ne faut surtout pas marcher sur le sable...\n             Il faut absolument rester sur le bon chemin dans cette salle... MAIS COMMENT CONNAITRE le bon chemin...\n             Si seulement on avait une carte pour nous l'indiquer....");

// MONTEE ======================
// MONTEE ======================
// MONTEE ======================
// MONTEE ======================
i = 0;
while(i < 3 && aventurier.pointsDeVies > 0 && VoltrexEnfouissement == 0){
    printf("\n/\\");
scanf("%d",&xanogene);
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);


printf("\n             Ou allez....\n1 : HAUT\n2 : GAUCHE\n3 : DROITE\n4 : DERRIERE");
scanf("%d",&BonChoixVoltrex);


if(BonChoixVoltrex == 1){

    printf("\n             On dirait que tout va bien pour l'instant... Il faut continuer et vite !");
    i++;
}
if(BonChoixVoltrex != 1){
    printf("\n             AAAAARRGG le Voltrex nous attaque... ce n'est pas bon du tout\n             Il faut recommencer et reussir !\n Vous perdez 10 pv  ");

    aventurier.pointsDeVies = aventurier.pointsDeVies -10;
}


}
// MONTEE ++++++++++++++++++++++++++++++
// MONTEE ++++++++++++++++++++++++++++++
// MONTEE ++++++++++++++++++++++++++++++





// GAUCHE ======================
// GAUCHE ======================
// GAUCHE ======================
// GAUCHE ======================
i = 0;
while(i < 4 && aventurier.pointsDeVies > 0){
    printf("\n/\\");
scanf("%d",&xanogene);
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);


printf("\n             Ou allez....\n1 : HAUT\n2 : GAUCHE\n3 : DROITE\n4 : DERRIERE");
scanf("%d",&BonChoixVoltrex);


if(BonChoixVoltrex == 2){

    printf("\n             On dirait que tout va bien pour l'instant... Il faut continuer et vite !");
    i++;
}
if(BonChoixVoltrex != 2){
    printf("\n             AAAAARRGG le Voltrex nous attaque... ce n'est pas bon du tout\n             Il faut recommencer et reussir !\n Vous perdez 10 pv  ");
    aventurier.pointsDeVies = aventurier.pointsDeVies -10;
}


}
// GAUCHE ++++++++++++++++++++++++++++++
// GAUCHE ++++++++++++++++++++++++++++++
// GAUCHE ++++++++++++++++++++++++++++++





// MONTEE 2 ======================
// MONTEE 2 ======================
// MONTEE 2 ======================
// MONTEE 2 ======================
i = 0;
while(i < 3 && aventurier.pointsDeVies > 0){
    printf("\n/\\");
scanf("%d",&xanogene);
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);


printf("\n             Ou allez....\n1 : HAUT\n2 : GAUCHE\n3 : DROITE\n4 : DERRIERE");
scanf("%d",&BonChoixVoltrex);


if(BonChoixVoltrex == 1){

    printf("\n             On dirait que tout va bien pour l'instant... Il faut continuer et vite !");
    i++;
}
if(BonChoixVoltrex != 1){
    printf("\n             AAAAARRGG le Voltrex nous attaque... ce n'est pas bon du tout\n             Il faut recommencer et reussir !\n Vous perdez 10 pv  ");
    aventurier.pointsDeVies = aventurier.pointsDeVies -10;
}


}
// MONTEE 2 ++++++++++++++++++++++++++++++
// MONTEE 2 ++++++++++++++++++++++++++++++
// MONTEE 2 ++++++++++++++++++++++++++++++



// DROITE  ======================
// DROITE  ======================
// DROITE ======================
// DROITE ======================
i = 0;
while(i < 4 && aventurier.pointsDeVies > 0){
    printf("\n/\\");
scanf("%d",&xanogene);
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);


printf("\n             Ou allez....\n1 : HAUT\n2 : GAUCHE\n3 : DROITE\n4 : DERRIERE");
scanf("%d",&BonChoixVoltrex);


if(BonChoixVoltrex == 3){

    printf("\n             On dirait que tout va bien pour l'instant... Il faut continuer et vite !");
    i++;
}
if(BonChoixVoltrex != 3){
    printf("\n             AAAAARRGG le Voltrex nous attaque... ce n'est pas bon du tout\n             Il faut recommencer et reussir !\n Vous perdez 10 pv  ");
    aventurier.pointsDeVies = aventurier.pointsDeVies -10;
}


}
// DROITE  ++++++++++++++++++++++++++++++
// DROITE  ++++++++++++++++++++++++++++++
// DROITE  ++++++++++++++++++++++++++++++



// MONTEE 3 ======================
// MONTEE 3 ======================
// MONTEE 3 ======================
// MONTEE 3 ======================
i = 0;
while(i < 1 && aventurier.pointsDeVies > 0){
    printf("\n/\\");
scanf("%d",&xanogene);
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n             Ou allez....\n1 : HAUT\n2 : GAUCHE\n3 : DROITE\n4 : DERRIERE");
scanf("%d",&BonChoixVoltrex);


if(BonChoixVoltrex == 1){

    printf("\n             On dirait que tout va bien pour l'instant... Il faut continuer et vite !");
    i++;
}
if(BonChoixVoltrex != 1){
    printf("\n             AAAAARRGG le Voltrex nous attaque... ce n'est pas bon du tout\n             Il faut recommencer et reussir !\n Vous perdez 10 pv  ");
    aventurier.pointsDeVies = aventurier.pointsDeVies -10;
}


}
// MONTEE 3 ++++++++++++++++++++++++++++++
// MONTEE 3 ++++++++++++++++++++++++++++++
// MONTEE 3 ++++++++++++++++++++++++++++++



// DROITE 2 ======================
// DROITE 2 ======================
// DROITE 2 ======================
// DROITE 2 ======================
i = 0;
while(i < 1 && aventurier.pointsDeVies > 0){
    printf("\n/\\");
scanf("%d",&xanogene);
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n             Ou allez....\n1 : HAUT\n2 : GAUCHE\n3 : DROITE\n4 : DERRIERE");
scanf("%d",&BonChoixVoltrex);


if(BonChoixVoltrex == 3){

    printf("\n             On dirait que tout va bien pour l'instant... Il faut continuer et vite !");
    i++;
}
if(BonChoixVoltrex != 3){
    printf("\n             AAAAARRGG le Voltrex nous attaque... ce n'est pas bon du tout\n             Il faut recommencer et reussir !\n Vous perdez 10 pv  ");
    aventurier.pointsDeVies = aventurier.pointsDeVies -10;
}


}
// DROITE 2 ++++++++++++++++++++++++++++++
// DROITE 2 ++++++++++++++++++++++++++++++
// DROITE 2 ++++++++++++++++++++++++++++++











// MONTEE 4 ======================
// MONTEE 4 ======================
// MONTEE 4 ======================
// MONTEE 4 ======================
i = 0;
while(i < 2 && aventurier.pointsDeVies > 0){
    printf("\n/\\");
scanf("%d",&xanogene);
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);


printf("\n             Ou allez....\n1 : HAUT\n2 : GAUCHE\n3 : DROITE\n4 : DERRIERE");
scanf("%d",&BonChoixVoltrex);


if(BonChoixVoltrex == 1){

    printf("\n             On dirait que tout va bien pour l'instant... Il faut continuer et vite !");
    i++;
}
if(BonChoixVoltrex != 1){
    printf("\n             AAAAARRGG le Voltrex nous attaque... ce n'est pas bon du tout\n             Il faut recommencer et reussir !\n Vous perdez 10 pv  ");
    aventurier.pointsDeVies = aventurier.pointsDeVies -10;
}


}
// MONTEE 4 ++++++++++++++++++++++++++++++
// MONTEE 4 ++++++++++++++++++++++++++++++
// MONTEE 4 ++++++++++++++++++++++++++++++








// GAUCHE 2 ======================
// GAUCHE 2 ======================
// GAUCHE 2 ======================
// GAUCHE 2 ======================
i = 0;
while(i < 16 && aventurier.pointsDeVies > 0){
    printf("\n/\\");
scanf("%d",&xanogene);
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);


printf("\n             Ou allez....\n1 : HAUT\n2 : GAUCHE\n3 : DROITE\n4 : DERRIERE");
scanf("%d",&BonChoixVoltrex);


if(BonChoixVoltrex == 2){

    printf("\n             On dirait que tout va bien pour l'instant... Il faut continuer et vite !");
    i++;
}
if(BonChoixVoltrex != 2){
    printf("\n             AAAAARRGG le Voltrex nous attaque... ce n'est pas bon du tout\n             Il faut recommencer et reussir !\n Vous perdez 10 pv  ");
    aventurier.pointsDeVies = aventurier.pointsDeVies -10;
}


}
// GAUCHE 2 ++++++++++++++++++++++++++++++
// GAUCHE 2 ++++++++++++++++++++++++++++++
// GAUCHE 2 ++++++++++++++++++++++++++++++





// DERRIERE  ======================
// DERRIERE  ======================
// DERRIERE  ======================
// DERRIERE  ======================
i = 0;
while(i < 2 && aventurier.pointsDeVies > 0){
    printf("\n/\\");
scanf("%d",&xanogene);
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);



printf("\n             Ou allez....\n1 : HAUT\n2 : GAUCHE\n3 : DROITE\n4 : DERRIERE");
scanf("%d",&BonChoixVoltrex);


if(BonChoixVoltrex == 4){

    printf("\n             On dirait que tout va bien pour l'instant... Il faut continuer et vite !");
    i++;
}
if(BonChoixVoltrex != 4){
    printf("\n             AAAAARRGG le Voltrex nous attaque... ce n'est pas bon du tout\n             Il faut recommencer et reussir !\n Vous perdez 10 pv  ");
    aventurier.pointsDeVies = aventurier.pointsDeVies -10;
}


}
// DERRIERE  ++++++++++++++++++++++++++++++
// DERRIERE  ++++++++++++++++++++++++++++++
// DERRIERE  ++++++++++++++++++++++++++++++


if(aventurier.pointsDeVies <= 0){
        for(i = 0 ; i<1500; i++){
            printf("§//010//1001 011101  0101001011  01//\\ //\\/  /\\//\\//\\//\\//\\");
        }
        system("cls");
        printf("\n             Vos yeux se plissent quant tout a coup la lumiere apparait, vous venez de mourir dans d'atroces souffrance\n             Enfin... maintenant vous ne sentez rien car c'est finit mais je vous jure que c'etait\n             écoeurant a voir...");
    printf("\n             ****************   GAME OVER   ****************\n             Vous n'avez malheursement pas survecu a ce donjon...\n             Il ne vous reste plus qua fermer le jeu et le rouvrir\n             Afin de recommencer a la derniere sauvegarde ! ");
    exit(1);
pointsDexperience = 0;
    gold = gold -10;
    aventurier.pointsDeVies = 50;

}

printf("\n             Vous sortez enfin de ce bourbier !!! le COMBAT REPREND !! ");

VoltrexEnfouissement++;

}
   // +++++++++++++++++++++++++++ PHASE 2 VOLTREX +++++++++++++++++++++++++
   // +++++++++++++++++++++++++++ PHASE 2 VOLTREX +++++++++++++++++++++++++
   // +++++++++++++++++++++++++++ PHASE 2 VOLTREX +++++++++++++++++++++++++
   // +++++++++++++++++++++++++++ PHASE 2 VOLTREX +++++++++++++++++++++++++
   // +++++++++++++++++++++++++++ PHASE 2 VOLTREX +++++++++++++++++++++++++
   // +++++++++++++++++++++++++++ PHASE 2 VOLTREX +++++++++++++++++++++++++
   // +++++++++++++++++++++++++++ PHASE 2 VOLTREX +++++++++++++++++++++++++
   // +++++++++++++++++++++++++++ PHASE 2 VOLTREX +++++++++++++++++++++++++
   // +++++++++++++++++++++++++++ PHASE 2 VOLTREX +++++++++++++++++++++++++



printf("\n\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Voltrex : %d",Voltrex);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(Voltrex < 220 && Voltrex > 170){
printf("\n\n\n                                                   VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n      ///////////////////////////////////////////////////////////////////////////////////////////////////////////");
printf("\n     ************************************************************************************************************");
}
if(Voltrex <= 170 && Voltrex > 120){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     //////////////////////////////////////////////////////////////////////////                                  ");
printf("\n     ************************************************************************************************************");
}
if(Voltrex <= 120 && Voltrex > 70){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     //////////////////////////////////////////                                                                  ");
printf("\n     ************************************************************************************************************");
}
if(Voltrex <= 70 && Voltrex > 40){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ///////////////////////                                                                                     ");
printf("\n     ************************************************************************************************************");
}
if(Voltrex <= 40 && Voltrex > 20){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////                                                                                                        ");
printf("\n     ************************************************************************************************************");
}
if(Voltrex <= 20 && Voltrex > 1){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     //                                                                                                          ");
printf("\n     ************************************************************************************************************");
}



if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 20 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +20;
        potionsRouge--;
        printf("\n             Glou glou glou glou +20 PV !");
    }
}

if(BoostPP > 0){
         printf("\n             Vous possedez un Boost de PP ? Voulez vous l'utiliser pour recuperez instantanement tout vos PP ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        PPSort1 = 10;
        PPSort2 = 5;
        PPSort3 = 3;
        BoostPP--;
        printf("\n            Sniiff un petit rail de je ne sais quoi et on repart comme en 40 ! PP :  MAX");
    }
}


printf("\n\n");
printf("\n     ******************************************************************************     ");
printf("\n     |                                                                            |     ");
printf("\n     |                     1                               2                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Tourbillon d'acier  %d/10  |   | Reflet de Lame      %d/5   |       |     ",PPSort1,PPSort2);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                      3                              4                      |     ");
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |        | Frappe fatale         %d/3 |   |Coups de poing    /Infini  |       |     ",PPSort3);
printf("\n     |        |---------------------------|   |---------------------------|       |     ");
printf("\n     |                                                                            |     ");
printf("\n     |                                                                            |     ");
printf("\n     ******************************************************************************     ");
printf("\n             Selectionnez un sort : ");
scanf("%d",&choixSPELL);

switch(choixSPELL){
    // SPELL 1
    case 1 :
        if(PPSort1 >0){
printf("\n              Vous tournoyez sur vous meme ce qui lacere l'ennemie\n             Vous infligez de gros degats au monstre !");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Voltrexx.esquive){
    printf("\n              Le Voltrex esquive votre attaque");
}

if(nombreRandome >= Voltrexx.esquive){
degatsInflige = aventurier.attaque+3 - Voltrexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Voltrex = Voltrex - degatsInflige;
printf("\n             vous infligez %d points de degats au Voltrex",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Voltrexx.esquive){
    printf("\n              Le Voltrex esquive votre attaque");
}

if(nombreRandome >= Voltrexx.esquive){
degatsInflige = aventurier.attaque - Voltrexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Voltrex = Voltrex - degatsInflige;
printf("\n             vous infligez %d points de degats au Voltrex",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le Voltrex aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Voltrexx.esquive){
    printf("\n              Le Voltrex esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Voltrexx.esquive){
    printf("\n              Le Voltrex esquive votre attaque");
}

if(nombreRandome >= Voltrexx.esquive){
degatsInflige = aventurier.attaque - Voltrexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Voltrex = Voltrex - degatsInflige;
printf("\n             vous infligez %d points de degats au Voltrex",degatsInflige);
}
// PAS ASSEZ DE PP SORT 2
}
break;







// SPELL 3
case 3 :
if(PPSort3 >0){
printf("\n              Vous ciblez un point vital de l'ennemie et plantez votre epee en plein dedans\n             Vous infligez des degats colossaux\n             ");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Voltrexx.esquive){
    printf("\n              Le Voltrex esquive votre attaque");
}

if(nombreRandome >= Voltrexx.esquive){
degatsInflige = aventurier.attaque+15 - Voltrexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Voltrex = Voltrex - degatsInflige;
printf("\n             vous infligez %d points de degats au Voltrex",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Voltrexx.esquive){
    printf("\n              Le Voltrex esquive votre attaque");
}

if(nombreRandome >= Voltrexx.esquive){
degatsInflige = aventurier.attaque - Voltrexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Voltrex = Voltrex - degatsInflige;
printf("\n             vous infligez %d points de degats au Voltrex",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 5;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe a Voltrexx");
    break;
        case 1 :
            printf("\n              Vous frappez viollement la bouche du monstre");
            break;
        case 2 :
            printf("\n              Vous preparez une bonne castagne selon le tuto de Jhonny et frapper le monstre");
            break;
        case 3 :
            printf("\n              Vous offre une salade de phalange au monstre en le frappant en plein torse");
            break;
        case 4 :
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille du monstre ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Voltrexx.esquive){
    printf("\n              Le Voltrex esquive votre attaque");
}

if(nombreRandome >= Voltrexx.esquive){
degatsInflige = aventurier.attaque - Voltrexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Voltrex = Voltrex - degatsInflige;
printf("\n             vous infligez %d points de degats au Voltrex",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================
if(Voltrex < 220 && Voltrex > 170){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n      ///////////////////////////////////////////////////////////////////////////////////////////////////////////");
printf("\n     ************************************************************************************************************");
}
if(Voltrex <= 170 && Voltrex > 120){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     //////////////////////////////////////////////////////////////////////////                                  ");
printf("\n     ************************************************************************************************************");
}
if(Voltrex <= 120 && Voltrex > 70){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     //////////////////////////////////////////                                                                  ");
printf("\n     ************************************************************************************************************");
}
if(Voltrex <= 70 && Voltrex > 40){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ///////////////////////                                                                                     ");
printf("\n     ************************************************************************************************************");
}
if(Voltrex <= 40 && Voltrex > 20){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////                                                                                                ");
printf("\n     ************************************************************************************************************");
}
if(Voltrex <= 20 && Voltrex > 1){
printf("\n\n\n                                                  VOLTREX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     //                                                                                                          ");
printf("\n     ************************************************************************************************************");
}






if(Voltrex >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le Voltrex repond a vous tirant des pieces dessus  ! ");
break;
case 1 :
    printf("\n              le Voltrexx vous jette viollement un crachat... Eurk");
    break;
case 2 :
    printf("\n              Cette chose immonde sort du plafond et vous fouette de sa queue");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! le Voltrexx va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque ce Voltrexx vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de Voltrexx vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              Ce Voltrexx vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage du Voltrex");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Voltrexx.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Voltrexx.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             Ce vil monstre vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}







}
// COMBAT PHASE 1
for(b = 0 ; b< 5000 ; b++){
printf("\n CRIIIIIIIIIIIIIIBUUUUUZUZUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUJJJJJJJJJJJJJJJJJJJJJJ             ");
}
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n\n\n                                                VOLTREX(MORT)                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n                                                                                                                 ");
printf("\n     ************************************************************************************************************");


printf("\n             Le monstre git sur le sol agonisant... Une odeur putride commence a remplir la piece...\n         Peu importe !! VOUS AVEZ TUE LE VOLTREX !");
printf("\n             FELICITATION !!");


VoltrexVaincu++;


if(VoltrexVaincu == 1){
srand(time(NULL));
nombreRandome = rand() % 150;
nombreRandome = nombreRandome +100;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;
printf("\n XP  : + %d",bonusXP);

srand(time(NULL));
nombreRandome = rand() % 4;


     srand(time(NULL));
nombreRandome = rand() % 100;
nombreRandome = nombreRandome +50;
    gold = gold + nombreRandome;
    printf("\n GOLD  : + %d",nombreRandome);




// ==========================  MONTEE DE LVL  ============================
if(pointsDexperience >= 100){


    printf("\n\n");
printf("\n     *********************************************************************************     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |//////////////////////////////**  LEVEL UP  **/////////////////////////////////|     ");
printf("\n     |//////////////////////////////****************/////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////          Vos statistique augmentent !           ///////////////|     ");
printf("\n     |///////////////                  Attaque ++                     ///////////////|     ");
printf("\n     |///////////////                  Esquive ++                     ///////////////|     ");
printf("\n     |///////////////                  PV : Max         Niveau %d      ///////////////|     ",LevelAventurier+1);
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     |///////////////////////////////////////////////////////////////////////////////|     ");
printf("\n     ********************************************************************************|     ");

pointsDexperience = 0;
LevelAventurier++;
aventurier.attaque = aventurier.attaque +3;
aventurier.esquive = aventurier.esquive +3;
aventurier.pointsDeVies = 200;
PPSort1 = 10;
PPSort2 = 5;
PPSort3 = 3;


}

// ++++++++++ FIN MONTEE DE LVL +++++++++++
bonusXP = 0;
bonuxGOLD = 0;


// +++++++++++++++++++++++ REMISE DES RECOMPENSES ++++++++++++++++++++++

}


}





printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/50      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);


// ++++++++++++++++++++++++++++++++++ BOSS VOLTREX       1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS VOLTREX       1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS VOLTREX       1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS VOLTREX       1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS VOLTREX       1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS VOLTREX       1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS VOLTREX       1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS VOLTREX       1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS VOLTREX       1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS VOLTREX       1 - 5 ++++++++++++++++++++++++++++++++++++++

if(aventurier.pointsDeVies <= 0){
        for(i = 0 ; i<1500; i++){
            printf("§//010//1001 011101  0101001011  01//\\ //\\/  /\\//\\//\\//\\//\\");
        }
        system("cls");
        printf("\n             Vos yeux se plissent quant tout a coup la lumiere apparait, vous venez de mourir dans d'atroces souffrance\n             Enfin... maintenant vous ne sentez rien car c'est finit mais je vous jure que c'etait\n             écoeurant a voir...");
    printf("\n             ****************   GAME OVER   ****************\n             Vous n'avez malheursement pas survecu a ce donjon...\n             Il ne vous reste plus qua fermer le jeu et le rouvrir\n             Afin de recommencer a la derniere sauvegarde ! ");
    exit(1);
pointsDexperience = 0;
    gold = gold -10;
    aventurier.pointsDeVies = 50;

}








// ======================================   FIN DU DONJON ============================================
// ======================================   FIN DU DONJON ============================================
// ======================================   FIN DU DONJON ============================================
// ======================================   FIN DU DONJON ============================================
// ======================================   FIN DU DONJON ============================================
// ======================================   FIN DU DONJON ============================================
// ======================================   FIN DU DONJON ============================================
// ======================================   FIN DU DONJON ============================================
// ======================================   FIN DU DONJON ============================================
// ======================================   FIN DU DONJON ============================================
printf("\n        Oh... ");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

for(i = 0 ; i < 4000 ; i++){

    printf("////////////////");
}
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);





if(MondeActuel == 2 && NiveauActuel != 5){
        srand(time(NULL));
nombreRandome = rand() % 30;
bonuxGOLD = nombreRandome;
bonuxGOLD = bonuxGOLD +5;
        gold = gold + bonuxGOLD;
printf("\n     *******************************************************************************      ");
printf("\n     |                                                                             |     ");
printf("\n     |                          *************************                          |     ");
printf("\n     |                                 FELICITATION                                |     ");
printf("\n     |                          *************************                          |     ");
printf("\n     |                            RECOMPENSE : %d Golds                            |     ",bonuxGOLD);
printf("\n     |                                                                             |     ");
printf("\n     |          Vous sortez VIVANT de ce donjon et vous pouvez continuer           |     ");
printf("\n     |                          Votre AVENTURE dans le                             |     ");
printf("\n     |                               DEEPER WORLD                                  |     ");
printf("\n     |                                                                             |     ");
printf("\n     *******************************************************************************      ");

printf("\n\n\n           Stage %d/%d ===> Stage %d/%d",MondeActuel,NiveauActuel,MondeActuel,NiveauActuel+1);
NiveauActuel++;
}

if(MondeActuel == 2 && NiveauActuel == 5 && VoltrexVaincu == 1){
    srand(time(NULL));
nombreRandome = rand() % 50;
bonuxGOLD = nombreRandome;
bonuxGOLD = bonuxGOLD +5;
gold = gold + bonuxGOLD;
printf("\n     *******************************************************************************      ");
printf("\n     |                                                                             |     ");
printf("\n     |                          *************************                          |     ");
printf("\n     |                                 FELICITATION                                |     ");
printf("\n     |                          *************************                          |     ");
printf("\n     |                            RECOMPENSE : %d Golds                             |     ",bonuxGOLD);
printf("\n     |                                                                             |     ");
printf("\n     |          Vous sortez VIVANT de ce donjon et vous pouvez continuer           |     ");
printf("\n     |                          Votre AVENTURE dans le                             |     ");
printf("\n     |                               DEEPER WORLD                                  |     ");
printf("\n     |                                  MONDE 3                                    |     ");
printf("\n     *******************************************************************************      ");

printf("\n\n\n           Stage %d/%d ===> Stage %d/%d",MondeActuel,NiveauActuel,MondeActuel+1,NiveauActuel-5);
MondeActuel++;
NiveauActuel = 0;




// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES
// MESSAGE DE CHANGER DE PROGRAMME !!!! ET COPIER COLLER LES SAVES

}


bonuxGOLD = 0;
// ======================================================================================================    REINITIALISATION DES VARIABLES  =======================================================================================================

// ====================   Variables Lambda ======================
 i = 0;
 b = 0;
 xanogene;
 choix;
 choix1;
 choix2 = 2;
 choix3;
 choix4;
 choix5 = 1;
 BonfireLit = 0;
 etageActuel  =0;

 nombreRandome = 0;
 c = 0;
 d = 0;
 e = 0;
// =================   STATISTIQUES ALEATOIRES ***** SALLES *****   =====================
 pourcentageCombats  = 70;
 pourcentageCampDeRepos  = 3 ;
 pourcentageEsquallier = 7;
 pourcentageSalleVide = 100;
 pourcentageTresor = 3;
 pourcentageSalleChoix = 40;
 pourcentageSalleSubmerge = 1;
 pourcentagePiege = 20;
 maxsalleAuTresor = 0;
 maxCombat = 0;
 maxSubmerge = 0;
 miniBoss = 0;
 AmuletteEscallier = 0;
 quizzSpinx = 0;
// ====================   Variables Sauvegardes ======================
// ====================   Variables HUD ====================================================


// =================   STATISTIQUES ALEATOIRES ***** SALLES *****   ===============================

// ================ BOUTIQUE  ==============
 choixBoutique = 0;
 choixobjets = 0;
 change =0;
 ChoixEscallier;
 AmuletteEscallier = 0;
 etageMAX = 0;


// =================   STATISTIQUES ALEATOIRES ***** MONSTRES *****   ===============================










// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ REININITALISATION DES VARIABLES +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
 printf("\n     De retour vers la carte des niveaux ");
    for(i = 0 ; i< 10000 ; i++){
    printf(":.:.:.:.:.:.:.:.:.:.:.:.:.:.:.:.");}

    printf("\n\n\n Sauvegarde en cours...");
   for(i = 0 ; i <3000 ; i++){

   }




// =============================== SAUVEGARDE DE LA PARTIE =================================





fichier = fopen("Saves/SauvegardeLevel.txt","w+");
rewind(fichier);
fprintf(fichier,"%d  ",NiveauActuel);



fclose(fichier);

fichier = fopen("Saves/SauvegardeExperience.txt","w+");
rewind(fichier);
fprintf(fichier,"%d  ",pointsDexperience);



fclose(fichier);


fichier = fopen("Saves/SauvegardePV.txt","w+");
rewind(fichier);
fprintf(fichier,"%d  ",aventurier.pointsDeVies);




fclose(fichier);

fichier = fopen("Saves/SauvegardeMonde.txt","w+");
rewind(fichier);
fprintf(fichier,"%d  ",MondeActuel);


fclose(fichier);


fichier = fopen("Saves/SauvegardeGold.txt","w+");
rewind(fichier);
fprintf(fichier,"%d  ",gold);



fclose(fichier);


fichier = fopen("Saves/SauvegardeNiveauAventurier.txt","w+");
rewind(fichier);
fprintf(fichier,"%d  ",LevelAventurier);



fclose(fichier);


fichier = fopen("Saves/SauvegardeAttaqueDammage.txt","w+");
rewind(fichier);
fprintf(fichier,"%d",aventurier.attaque);

fclose(fichier);


// ++++++++++++++++++++++ SAUVEGARDE DE LA PARTIE +++++++++++++++++++++++++++++++++++++
   printf("\n Partie Sauvegarde ! ");

  printf("\n/\\");
scanf("%d",&xanogene);

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/200      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);


}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   MONDE 1 LVL 1 ==> 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   MONDE 1 LVL 1 ==> 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   MONDE 1 LVL 1 ==> 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   MONDE 1 LVL 1 ==> 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   MONDE 1 LVL 1 ==> 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   MONDE 1 LVL 1 ==> 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   MONDE 1 LVL 1 ==> 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   MONDE 1 LVL 1 ==> 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   MONDE 1 LVL 1 ==> 5 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
printf("\n     Merci beaucoup d'avour joue au Monde 2 de Deeper World !!\n afin de poursuivre vers le monde 3 veuillez copier coller votre sauvegarde dans le dossier 'saves'\n du dossier Monde 3 !");
printf("\n     Une fois cela fait !! vous n'avez plus qu'a lancer le nouveau programme et a vous amuser :)");

// MAIN
}




