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
int newGamePlus = 0;
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
int Tuba = 0;

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

statistiques Gobelins;

Gobelins.armure = 0;
Gobelins.attaque = 3;
Gobelins.coupCritique = 20;
Gobelins.esquive = 10;
Gobelins.pointsDeVies = 7;
Gobelins.fuite = 0;

int ADGobelin = 3;
int ADfantome = 4;
int ADsorciere = 5;
int ADsquelette = 3;
int Gobelin;

statistiques Fantomes;

Fantomes.armure =1;
Fantomes.attaque = 4;
Fantomes.coupCritique = 20;
Fantomes.esquive = 10;
Fantomes.pointsDeVies = 11;
Fantomes.fuite = 0;

int Fantome;

statistiques Squelettes;

Squelettes.armure = 1;
Squelettes.attaque = 3;
Squelettes.coupCritique = 20;
Squelettes.esquive = 10;
Squelettes.pointsDeVies = 8;
Squelettes.fuite = 0;

int Squelette;

statistiques Sorcieres;

Sorcieres.armure = 2;
Sorcieres.attaque = 5;
Sorcieres.coupCritique = 20;
Sorcieres.esquive = 10;
Sorcieres.pointsDeVies = 15;
Sorcieres.fuite = 0;

int Sorciere;



statistiques LordSoupexx;

LordSoupexx.armure = 1;
LordSoupexx.attaque = 8;
LordSoupexx.coupCritique = 30;
LordSoupexx.esquive = 10;
LordSoupexx.pointsDeVies = 150;

int choixLordSoupex;
int ChoixAventurier;

int AdLordSoupex = 10;

int LordSoupex;

int LordSoupexVaincu = 0;
// =================   STATISTIQUES ALEATOIRES Joueur SPELL / STATS   =====================
int PtsDeCapacite = 5;
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
if(MondeActuel == 1){
switch(NiveauActuel){

case 1 :
  Gobelins.pointsDeVies =   7;
  Squelettes.pointsDeVies = 8;
  Fantomes.pointsDeVies = 11;
  Sorcieres.pointsDeVies = 15;

  ADGobelin =3;
  ADsquelette = 3;
  ADsorciere = 5;
  ADfantome = 4;
break;

case 2 :

    Gobelins.pointsDeVies =   7;
  Squelettes.pointsDeVies = 8;
  Fantomes.pointsDeVies = 11;
  Sorcieres.pointsDeVies = 15;

  ADGobelin =3;
  ADsquelette = 3;
  ADsorciere = 5;
  ADfantome = 4;

break;


case 3 :

    Gobelins.pointsDeVies =   10;
  Squelettes.pointsDeVies = 12;
  Fantomes.pointsDeVies = 15;
  Sorcieres.pointsDeVies = 21;

  ADGobelin =5;
  ADsquelette = 6;
  ADsorciere = 7;
  ADfantome = 6;

break;

case 4 :

    Gobelins.pointsDeVies =   10;
  Squelettes.pointsDeVies = 12;
  Fantomes.pointsDeVies = 15;
  Sorcieres.pointsDeVies = 21;

  ADGobelin =8;
  ADsquelette = 9;
  ADsorciere = 10;
  ADfantome = 9;

break;

case 5 :

    Gobelins.pointsDeVies =   15;
  Squelettes.pointsDeVies = 18;
  Fantomes.pointsDeVies = 21;
  Sorcieres.pointsDeVies = 30;

  ADGobelin =8;
  ADsquelette = 9;
  ADsorciere = 10;
  ADfantome = 9;

break;


}
}
switch(LevelAventurier){
case 1 :
    aventurier.attaque = aventurier.attaque +1;
    aventurier.esquive = aventurier.esquive +2;
break;

case 2 :
    aventurier.attaque = aventurier.attaque +2;
    aventurier.esquive = aventurier.esquive +2;

break;

case 3 :
    aventurier.attaque = aventurier.attaque +3;
    aventurier.esquive = aventurier.esquive +2;
break;

case 4 :
    aventurier.attaque = aventurier.attaque +4;
    aventurier.esquive = aventurier.esquive +2;
break;

case 5 :
    aventurier.attaque = aventurier.attaque +5;
    aventurier.esquive = aventurier.esquive +2;
break;

case 6 :
    aventurier.attaque = aventurier.attaque +5;;
    aventurier.esquive = aventurier.esquive +2;
break;

case 7 :
    aventurier.attaque = aventurier.attaque +5;
    aventurier.esquive = aventurier.esquive +2;
break;

case 8 :
    aventurier.attaque = aventurier.attaque +5;
    aventurier.esquive = aventurier.esquive +2;
break;

case 9 :
    aventurier.attaque = aventurier.attaque +5;
    aventurier.esquive = aventurier.esquive +2;
break;

case 10 :
    aventurier.attaque = aventurier.attaque +10;
    aventurier.esquive = aventurier.esquive +4;
break;


}

// ====================== NEW GAME PLUS  ======================
// ====================== NEW GAME PLUS  ======================
// ====================== NEW GAME PLUS  ======================
// ====================== NEW GAME PLUS  ======================
// ====================== NEW GAME PLUS  ======================
if(newGamePlus == 84464841){
MondeActuel = 1;

printf("\n\n\n          Bienvenue au NEW GAME + ! ici vous pouvez vous teleporter a n'importe quel moment de votre aventure\n           dans la FairWell Valley");
printf("\n           Se teleporter a un moment precis de l'aventure ?\n 1 : OUI\n 2 : NON");
scanf("%d",&xanogene);
if(xanogene == 1){
    printf("\n\n\n        Tres bien !  Quel moment voulez vous revivre ? ");
    printf("\n 0 : Introduction");
    printf("\n 1 : Donjons 1 ");
    printf("\n 2 : Donjons 2 ");
    printf("\n 3 : Donjons 3 ");
    printf("\n 4 : Donjons 4 ");
    printf("\n 5 : BOSS LORD SOUPEX ");
    scanf("%d",&NiveauActuel);
}
}

// ++++++++++++++++++++ NEW GAME PLUS ++++++++++++++++++++
// ++++++++++++++++++++ NEW GAME PLUS ++++++++++++++++++++
// ++++++++++++++++++++ NEW GAME PLUS ++++++++++++++++++++
// ++++++++++++++++++++ NEW GAME PLUS ++++++++++++++++++++
// ++++++++++++++++++++ NEW GAME PLUS ++++++++++++++++++++
// ++++++++++++++++++++++++++++++++ XP LVL STATS BOOST ET MOBS ++++++++++++++++++++++



// ======================================================================== MONDE 0 INTRODUCTION ========================================================================
if( MondeActuel == 0 && NiveauActuel == 0 && finBoucleLvl0 == 0){
printf("                              **************************************************\n                              ***                  BIENVENUE                 ***\n                              ***                    DANS                    ***\n                              ***               Deeper World                 ***\n                              ***                  EPISODE 2                 ***\n                              **************************************************");
printf("\n          Bienvenu aventurier ! Quel plaisir de vous retrouver apres les... incidents du dungeon Deeper....\n          Bon je vous dois des EXCUSES pour... ce que j'ai fait\n          Donc voila... Pardon aventurier....\n          Vous me pardonnez ?\n 1 : OUI\n 2 : NON ");
scanf("\n%d",&choix1);
if(choix1 > 1){
    printf("\n\n\n          Bon.... Je comprends mais vous savez tout le monde fait des erreurs.\n          Ecoutez je vous propose que l'on reparte sur de bonnes bases !\n          Etant le narrateur de ce nouvel opus je vais vous expliquer toutes les nouveautes !\n          Entrez dans le Deeper Wolrd et je vous expliquerai tout !");
}
if(choix1 == 1){
    printf("\n          Merci... Je m'en veux encore si vous saviez... Je me suis laisse emporter par des idees betes\n          Enfin...  Ecoutez je vous propose que l'on reparte sur de bonnes bases !\n          Etant le narrateur de ce nouvel opus je vais vous expliquer toutes les nouveautes !\n          Entrez dans le Deeper Wolrd et je vous expliquerai tout !");
}
printf("\n\n\nLorsque vous voyez ce signe, cela signifie qu'il faut TAPPER UN CHIFFRE et appuyer sur ENTRER pour continuer");
printf("\n/\\");
scanf("%d",&xanogene);

for(i = 0 ; i < 50 ; i++){
    printf("010101100101010010101101011000011010101010110101001");

}
system("cls");

// ======================================================================== HUD !!!!! ========================================================================
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n\n          Voila ! laissez moi vous expliquer les rudiments de ce nouveau jeu :)\n          Tout d'abord ! Incroyable mais vrai, il y a des sauvegardes !!\n          Bon... le jeu ne sauvegarde qu'a la fin d'un niveau donc mieux vaut ne pas tout fermer\n           avant d'avoir eu confirmation que tout a bien ete sauvegarde\n          En effet, ce jeu possede des sauvegarde ! Pourquoi ? Car il est beaucoup plus long que l'ancien !\n          Vous allez devoir vous aventurer dans les differents donjons du DEEPER WORLD\n          En effet, le DEEPER WORLD est compose de 3 mondes avec 5 donjons par monde");
printf("\n\n\n          Oh mais que Voilaje ? un HUD WOOOW le budget a du augmenter dis donc...\n          Vous savez au fond maintenant que le 4eme mur est pulveriser...\n          en fait je ne suis pas vivant, je suis simplemnet une ligne de commande ecrite par le programmeur\n          (message du programmeur) : c'est tres tres chiant de tout ecrire d'ailleurs...\n          BREF du coup voila un HUD ! je vais tout vous expliquer comment cela fonctionne");

printf("\n/\\");
scanf("%d",&xanogene);
system("cls");



printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n       ^^");
printf("\n       ||");
printf("\n          Voila votre pseudo... Bon pour l'instant vous vous appelez %c et c'est pas tres glorieux...\n          On va donc vous donner un PRENOM !!\n          Comment vous appelez vous (6 caractere PAS PLUS PAS MOIN) JE VOUS AURAIS PREVENU ?",pseudo);

scanf("\n\n%s",&pseudo);
printf("\n          Parfait ! vous vous appelez donc %s\n          Alors laissez moi simplement modifier tout ca !",pseudo);
fichier = fopen("Saves/SauvegardePseudo.txt","a+");
fprintf(fichier,"%s",pseudo);
fclose(fichier);
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n                            ^^");
printf("\n                            ||");
printf("\n          Ici, vous trouverez votre progression dans l'aventure ! actuellement vous etes au monde 0 et au niveau 0 \n          c'est normal car c'est toujours le tutoriel !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n                                                  ^^");
printf("\n                                                  ||");

printf("\n          Ici, se trouve votre experience\n          C'est extremement pratique, en effet car a chaque fois que vous turez un monste vous obtiendrez un peu d'xp\n          Une fois a 100 pts vous monterez de niveau ce qui vous offrira de supers bonus ! !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n                                                                              ^^");
printf("\n                                                                              ||");
printf("\n          Voila vos points de vie !\n          Tres pratique tout de meme de connaitre ses PV en permanence ");

printf("\n/\\");
scanf("%d",&xanogene);
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n                                                                                                          ^^");
printf("\n                                                                                                          ||");
printf("\n          Et pour finir voici vous Golds, vos obtenez des golds en terminant des donjons\n          ou en accomplissant des objectifs secondaires !\n          Avec ces golds vous pourrez acheter des objets (ATTENTION LES OBJETS NE SONT PAS SAUVEGARDES)\n          Donc mieux vaut tout utiliser avant de quitter !");

printf("\n/\\");
scanf("%d",&xanogene);
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
printf("\n\n\n\n          Voila ! Je crois bien que c'est tout... du moins pour l'HUD ! \n          Maintenant, le JEU EN LUI MEME !\n\n\n          Vous allez traverser plusieurs donjons ! le fonctionnement est le meme que pour DUNGEON DEEPER\n          Cependant quelques subitilites sont modifies !\n          En effet, allons donc voir les modification :  \n - les combats  : sont au tour par tour et l'avantage sera tire au sort! les contrecoups n'existent cependant plus !\n    Vous possedez a present 3 sorts avec des charges differentes et une auto attaque, l'armure fonctionne differement\n - Les salles au tresor  : il n'y en a plus qu'une par etage mais sont pourcentage augmente a chaque salle\n    si vous perceverez vous tomberez forcement sur une !\n    les bonus restent sensiblement les memes\n - Les salles de repos : restent les memes mais subissent quelques correctifs d'equilibrage\n - Les salles vides : existent toujours mais apparaisseront beaucoup moins\n - Les salles d'escalier : subissent de gros changement. En effet, a present une fois la salle trouvez vous pouvez\n    continuer a decouvrir l'etage actuel et vous teleporter a l'etage suivant a votre guise\n    parfait pour chercher la salle de tresor ! ");

printf("\n/\\");
scanf("%d",&xanogene);
printf("\n\n\n ============== les NOUVELLES SALLES ==============");
printf("\n\n - Les salles de choix : vous offre la possibilite de choisir ou aller : droite ou gauche ce qui modifiera la suite de l'etage\n - Les Salles piegees : abaisse le pourcentage d'escallier et vous fera subir un malus\n - Les salles submergees : necessite un objet special et vous permettra parfois de vous teleporter a l'etage suivant\n - Les salles de Boss : feront apparaitre un monstre tres puissant au dernier etage");
printf("\n/\\");

printf("\n          Voila quelques changements mais je pense que le mieux est de vous laisser voir tout ca par vous meme !\n          Amusez vous bien car\n\n\n          VOUS RENTREZ DANS LE DEEPER WORLD  ");
printf("\n/\\");
scanf("%d",&xanogene);

// ===================================================  Monde 0 --> 1   ============
fichier = fopen("Saves/SauvegardeMonde.txt","w+");
fputs("1",fichier);
rewind(fichier);
fscanf(fichier,"%d",&MondeActuel);
fclose(fichier);

finBoucleLvl0++;


fichier = fopen("Saves/SauvegardeLevel.txt","w+");
fputs("1",fichier);
rewind(fichier);
fscanf(fichier,"%d",&NiveauActuel);
fclose(fichier);
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++   FIN MONDE 0 INTRODUCTION ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}







// ========================================= MONDE 1 => 5 ============================
// ========================================= MONDE 1 => 5 ============================
// ========================================= MONDE 1 => 5 ============================
// ========================================= MONDE 1 => 5 ============================
// ========================================= MONDE 1 => 5 ============================
// ========================================= MONDE 1 => 5 ============================
// ========================================= MONDE 1 => 5 ============================
// ========================================= MONDE 1 => 5 ============================
// ========================================= MONDE 1 => 5 ============================
// ========================================= MONDE 1 => 5 ============================


while(MondeActuel == 1 && NiveauActuel <= 5 && LordSoupexVaincu ==0){



// ============================================= MONDE 1 NIVEAU 0    =================================
// ============================================= MONDE 1 NIVEAU 0    =================================
// ============================================= MONDE 1 NIVEAU 0    =================================
// ============================================= MONDE 1 NIVEAU 0    =================================
// ============================================= MONDE 1 NIVEAU 0    =================================
// ============================================= MONDE 1 NIVEAU 0    =================================
// ============================================= MONDE 1 NIVEAU 0    =================================
// ============================================= MONDE 1 NIVEAU 0    =================================
// ============================================= MONDE 1 NIVEAU 0    =================================




if(MondeActuel == 1 && NiveauActuel == 1 && finBoucleLvl1 == 0){


        // INITIALISATION DES COMBATS ==================
     Gobelins.pointsDeVies =   7;
  Squelettes.pointsDeVies = 8;
  Fantomes.pointsDeVies = 11;
  Sorcieres.pointsDeVies = 15;

  ADGobelin =3;
  ADsquelette = 3;
  ADsorciere = 5;
  ADfantome = 4;
   // INITIALISATION DES COMBATS ++++++++++++++++++++++



system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n          BIENVENU dans le DEEPER WORLD !\n          Laissez moi vous presentez le monde  ");
printf("CLAP CLAP....");

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("                        Voici le merveilleux monde de DEEPER WORLD\n\n\n\n");
printf("\n     ******************************************************************************      ");
printf("\n     |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n     |   --- X ----- X  -|      3                                                  |     ");
printf("\n     |                   | ---- X -----|                                           |     ");
printf("\n     |                                 |            5                              |     ");
printf("\n     |                                 4         XXXXXXXX                          |     ");
printf("\n     |                                 X - - - - X BOSS X                          |     ");
printf("\n     |                                           XXXXXXXX                          |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
printf("\n     ******************************************************************************      ");
printf("\n\n\n          Voici la FairWell Valley : le monde 1\n          Chaque X represente un donjon a affronter afin d'atteindre le boss et acceder au monde 2 !\n          Un donjon valide se transformera en O ");
printf("\n          Voila donc je pense que c'est parti pour commencer le jeu... Ah non suis-je bete...\n          Allez donc faireun tour a la boutique   !! ");


// ========================================== =====================   FIN DES DONJONS     ====================== ===============================================================
// ===============================  SELECTIONNER CAPACITE ===============================

// ++++++++++++++ SELECTIONNER CAPACITE +++++++++++++++++++++
printf("\n/\\");
scanf("%d",&xanogene);
gold = gold +5;

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n     Bienvenu a la boutique ! Ici vous pouvez acheter ce que vous voulez tant que vous en avez les moyens !  \n\n\n\n");
printf("\n     Allez je suis d'humeur clemente aujourd'hui ! je vais donc vous offrir 5g pour commencer ! ");


printf("\n     ******************************************************************************      ");
printf("\n     |    ___    ______________________________________                           |     ");
printf("\n     |   |'o'|< | Bievenue dans ma boutique Aventurier |   |**************|       |     ");
printf("\n     |   /||\\   | N'hesitez pas a regarder ici et la ! |   |     Tuba     |       |     ");
printf("\n     |    /\\    | Quelque chose pourrait vous plaire.. |   |**************|       |     ");
printf("\n     |          |______________________________________|         100G(4)          |     ");
printf("\n     |                                                                            |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |         | Potion rouge |      |  Smoke Bomb  |      |   Boost PP   |       |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |               5G(1)                10G(2)                 25G(3)           |     ");
printf("\n     ******************************************************************************      ");




printf("\n          Alors ? Faire chauffer la carte bleu ?\n 1 : OUI\n 2 : NON ");

scanf("%d",&choix5);
if(choix5 == 2){
    printf("\n\n          Avec la crise du corona les temps sont dures...\n          Alors vous vous dirigez vers le donjons sans rien acheter");
}
while(choix5 == 1){
if(choix5 == 1){

 printf("\n\n          Tres bien ! que voulez vous acheter ?\n 1 : Potion rouge\n 2 : Smoke Bomb\n 3 : Boost PP\n 4 : Tuba\n 5 : Heuu j'ai change d'avis");
 scanf("%d",&choixobjets);

 switch(choixobjets){
case 1 : printf("\n\n\n          Potion rouge ! pour 5 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
}
if(choix4 == 1){
    change = gold -5;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 5;
        potionsRouge++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 2 : printf("\n\n\n          Smoke Bomb ! pour 10 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -10;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 10;
        SmokeBomb++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 3 : printf("\n\n\n          Boost PP ! pour 25 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -25;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 25;
        BoostPP++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 4 : printf("\n\n\n          Tuba : (un objet permettant de traverser les salles submergees !) pour 100 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

   printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -100;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 100;
        Tuba++;
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

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n\n\n");


printf("\n     ******************************************************************************      ");
printf("\n     |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n     |   ---[O] ----- X  -|      3                                                 |     ");
printf("\n     |                   | ---- X -----|                                           |     ");
printf("\n     |                                 |            5                              |     ");
printf("\n     |                                 4         XXXXXXXX                          |     ");
printf("\n     |                                 X - - - - X BOSS X                          |     ");
printf("\n     |                                           XXXXXXXX                          |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
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

if(MondeActuel == 1 && NiveauActuel == 2 && finBoucleLvl2 == 0){


        // INITIALISATION DES COMBATS ==================
     Gobelins.pointsDeVies =   7;
  Squelettes.pointsDeVies = 8;
  Fantomes.pointsDeVies = 11;
  Sorcieres.pointsDeVies = 15;

  ADGobelin =3;
  ADsquelette = 3;
  ADsorciere = 5;
  ADfantome = 4;
   // INITIALISATION DES COMBATS ++++++++++++++++++++++


    etageActuel = 0;

        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n\n\n\n");
printf("\n     ******************************************************************************      ");
printf("\n     |    ___    ______________________________________                           |     ");
printf("\n     |   |'o'|< | Bievenue dans ma boutique Aventurier |   |**************|       |     ");
printf("\n     |   /||\\   | Heureux de vous revoir en vie        |   |     Tuba     |       |     ");
printf("\n     |    /\\    | Quelque chose pourrait vous plaire ? |   |**************|       |     ");
printf("\n     |          |______________________________________|         100G(4)          |     ");
printf("\n     |                                                                            |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |         | Potion rouge |      |  Smoke Bomb  |      |   Boost PP   |       |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |               5G(1)                10G(2)                 25G(3)           |     ");
printf("\n     ******************************************************************************      ");




printf("\n          Alors ? Faire chauffer la carte bleu ?\n 1 : OUI\n 2 : NON ");

scanf("%d",&choix5);
if(choix5 == 2){
    printf("\n\n          Avec la crise du corona les temps sont dures...\n          Alors vous vous dirigez vers le donjons sans rien acheter");
}
while(choix5 == 1){
if(choix5 == 1){

 printf("\n\n          Tres bien ! que voulez vous acheter ?\n 1 : Potion rouge\n 2 : Smoke Bomb\n 3 : Boost PP\n 4 : Tuba\n 5 : Heuu j'ai change d'avis");
 scanf("%d",&choixobjets);

 switch(choixobjets){
case 1 : printf("\n\n\n          Potion rouge ! pour 5 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
}
if(choix4 == 1){
    change = gold -5;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 5;
        potionsRouge++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 2 : printf("\n\n\n          Smoke Bomb ! pour 10 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -10;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 10;
        SmokeBomb++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 3 : printf("\n\n\n          Boost PP ! pour 25 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -25;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 25;
        BoostPP++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 4 : printf("\n\n\n          Tuba : (un objet permettant de traverser les salles submergees !) pour 100 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

   printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -100;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 100;
        Tuba++;
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








printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O>------X---|      3                                                  |   ");
printf("\n                 |                   | ---- X -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");



printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O>>-----X--|      3                                                   |   ");
printf("\n                 |                  |---- X -----|                                             |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************     ");

system("cls");
printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O>>>----X---|      3                                                  |   ");
printf("\n                 |                   |---- X -----|                                            |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");
for(i = 0 ; i< 1000 ; i++){

}
system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O>>>>---X--|      3                                                   |   ");
printf("\n                 |                  |----- X -----|                                            |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************     ");

system("cls");
printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O>>>>>--X---|      3                                                  |   ");
printf("\n                 |                   |----- X -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O>>>>>>-X--|      3                                                   |   ");
printf("\n                 |                  |----- X -----|                                            |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************     ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O>>>>>>>X--|      3                                                   |   ");
printf("\n                 |                  |----- X -----|                                            |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************     ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O------[O]--|      3                                                  |   ");
printf("\n                 |                   |----- X -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************     ");

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n\n\n");


printf("\n     ******************************************************************************      ");
printf("\n     |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n     |   ----X -----[O] -|      3                                                  |     ");
printf("\n     |                   | ---- X -----|                                           |     ");
printf("\n     |                                 |            5                              |     ");
printf("\n     |                                 4         XXXXXXXX                          |     ");
printf("\n     |                                 X - - - - X BOSS X                          |     ");
printf("\n     |                                           XXXXXXXX                          |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
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




if(MondeActuel == 1 && NiveauActuel == 3 && finBoucleLvl3 == 0){


        // INITIALISATION DES COMBATS ==================
     Gobelins.pointsDeVies =    10;
  Squelettes.pointsDeVies = 14;
  Fantomes.pointsDeVies = 15;
  Sorcieres.pointsDeVies = 20;

  ADGobelin =7;
  ADsquelette = 5;
  ADsorciere = 10;
  ADfantome = 7;
   // INITIALISATION DES COMBATS ++++++++++++++++++++++


    etageActuel = 0;
finBoucleLvl3++;
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n\n\n\n");
printf("\n     ******************************************************************************      ");
printf("\n     |    ___    ______________________________________                           |     ");
printf("\n     |   |'o'|< | Bievenue dans ma boutique Aventurier |   |**************|       |     ");
printf("\n     |   /||\\   | Ravi de vous savoir toujours en vie  |   |     Tuba     |       |     ");
printf("\n     |    /\\    | Quelque chose pourrait vous plaire ? |   |**************|       |     ");
printf("\n     |          |______________________________________|         100G(4)          |     ");
printf("\n     |                                                                            |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |         | Potion rouge |      |  Smoke Bomb  |      |   Boost PP   |       |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |               5G(1)                10G(2)                 25G(3)           |     ");
printf("\n     ******************************************************************************      ");




printf("\n          Alors ? Faire chauffer la carte bleu ?\n 1 : OUI\n 2 : NON ");

scanf("%d",&choix5);
if(choix5 == 2){
    printf("\n\n          Avec la crise du corona les temps sont dures...\n          Alors vous vous dirigez vers le donjons sans rien acheter");
}
while(choix5 == 1){
if(choix5 == 1){

 printf("\n\n          Tres bien ! que voulez vous acheter ?\n 1 : Potion rouge\n 2 : Smoke Bomb\n 3 : Boost PP\n 4 : Tuba\n 5 : Heuu j'ai change d'avis");
 scanf("%d",&choixobjets);

 switch(choixobjets){
case 1 : printf("\n\n\n          Potion rouge ! pour 5 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
}
if(choix4 == 1){
    change = gold -5;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 5;
        potionsRouge++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 2 : printf("\n\n\n          Smoke Bomb ! pour 10 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -10;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 10;
        SmokeBomb++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 3 : printf("\n\n\n          Boost PP ! pour 25 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -25;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 25;
        BoostPP++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 4 : printf("\n\n\n          Tuba : (un objet permettant de traverser les salles submergees !) pour 100 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

   printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -100;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 100;
        Tuba++;
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








printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O>--|      3                                                  |   ");
printf("\n                 |                   | ---- X -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");



printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O>>-|      3                                                  |   ");
printf("\n                 |                   |---- X -----|                                            |     ");
printf("\n                 |                                |            5                               |     ");
printf("\n                 |                                4         XXXXXXXX                           |     ");
printf("\n                 |                                X - - - - X BOSS X                           |     ");
printf("\n                 |                                          XXXXXXXX                           |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************     ");

system("cls");
printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O>>>#      3                                                  |   ");
printf("\n                 |                   |---- X -----|                                            |     ");
printf("\n                 |                                |            5                               |     ");
printf("\n                 |                                4         XXXXXXXX                           |     ");
printf("\n                 |                                X - - - - X BOSS X                           |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");
for(i = 0 ; i< 1000 ; i++){

}
system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O>>#      3                                                   |   ");
printf("\n                 |                  #----- X -----|                                            |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************     ");

system("cls");
printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O>>>#      3                                                  |   ");
printf("\n                 |                   #>>--- X -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");
printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O>>>#      3                                                  |   ");
printf("\n                 |                   #>>>-- X -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");
printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O>>>#      3                                                  |   ");
printf("\n                 |                   #>>>>- X -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");
printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O>>>#      3                                                  |   ");
printf("\n                 |                   #>>>>> X -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");
printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O>>>#      3                                                  |   ");
printf("\n                 |                   #>>>>>[O] -----|                                          |     ");
printf("\n                 |                                  |            5                             |     ");
printf("\n                 |                                  4         XXXXXXXX                         |     ");
printf("\n                 |                                  X - - - - X BOSS X                         |     ");
printf("\n                 |                                            XXXXXXXX                         |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");


system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n\n\n");


printf("\n     ******************************************************************************      ");
printf("\n     |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n     |   ----X------ X  -|      3                                                  |     ");
printf("\n     |                   | ----[O]-----|                                           |     ");
printf("\n     |                                 |            5                              |     ");
printf("\n     |                                 4         XXXXXXXX                          |     ");
printf("\n     |                                 X - - - - X BOSS X                          |     ");
printf("\n     |                                           XXXXXXXX                          |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
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




if(MondeActuel == 1 && NiveauActuel == 4 && finBoucleLvl4 ==0){
    etageActuel = 0;



    // INITIALISATION DES COMBATS ==================
     Gobelins.pointsDeVies =   10;
  Squelettes.pointsDeVies = 12;
  Fantomes.pointsDeVies = 15;
  Sorcieres.pointsDeVies = 21;

   ADGobelin =7;
  ADsquelette = 5;
  ADsorciere = 10;
  ADfantome = 7;
   // INITIALISATION DES COMBATS ++++++++++++++++++++++


finBoucleLvl4++;
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n\n\n\n");
printf("\n     ******************************************************************************      ");
printf("\n     |    ___    ______________________________________                           |     ");
printf("\n     |   |'o'|< | Bievenue dans ma boutique Aventurier |   |**************|       |     ");
printf("\n     |   /||\\   | Encore vous heuu je veux dire super !|   |     Tuba     |       |     ");
printf("\n     |    /\\    | Quelque chose pourrait vous plaire ? |   |**************|       |     ");
printf("\n     |          |______________________________________|         100G(4)          |     ");
printf("\n     |                                                                            |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |         | Potion rouge |      |  Smoke Bomb  |      |   Boost PP   |       |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |               5G(1)                10G(2)                 25G(3)           |     ");
printf("\n     ******************************************************************************      ");




printf("\n          Alors ? Faire chauffer la carte bleu ?\n 1 : OUI\n 2 : NON ");

scanf("%d",&choix5);
if(choix5 == 2){
    printf("\n\n          Avec la crise du corona les temps sont dures...\n          Alors vous vous dirigez vers le donjons sans rien acheter");
}
while(choix5 == 1){
if(choix5 == 1){

 printf("\n\n          Tres bien ! que voulez vous acheter ?\n 1 : Potion rouge\n 2 : Smoke Bomb\n 3 : Boost PP\n 4 : Tuba\n 5 : Heuu j'ai change d'avis");
 scanf("%d",&choixobjets);

 switch(choixobjets){
case 1 : printf("\n\n\n          Potion rouge ! pour 5 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
}
if(choix4 == 1){
    change = gold -5;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 5;
        potionsRouge++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 2 : printf("\n\n\n          Smoke Bomb ! pour 10 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -10;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 10;
        SmokeBomb++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 3 : printf("\n\n\n          Boost PP ! pour 25 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -25;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 25;
        BoostPP++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 4 : printf("\n\n\n          Tuba : (un objet permettant de traverser les salles submergees !) pour 100 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

   printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -100;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 100;
        Tuba++;
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

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O >----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");


system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O >>---|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O >>>--|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O >>>>-|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O >>>>>|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O >>>>>#                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O >>>>>#                                           |     ");
printf("\n                 |                                 #            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 X - - - - X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O >>>>>#                                           |     ");
printf("\n                 |                                 #            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                [O] - - - - X BOSS X                         |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n\n\n");


printf("\n     ******************************************************************************      ");
printf("\n     |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n     |   ----X------ X  -|      3                                                  |     ");
printf("\n     |                   | ---- X -----|                                           |     ");
printf("\n     |                                 |            5                              |     ");
printf("\n     |                                 4         XXXXXXXX                          |     ");
printf("\n     |                                [O] - - - - X BOSS X                         |     ");
printf("\n     |                                           XXXXXXXX                          |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
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



if(MondeActuel == 1 && NiveauActuel == 5 && finBoucleLvl5 == 0){
    etageActuel = 0;



    // INITIALISATION DES COMBATS ==================
    Gobelins.pointsDeVies =   15;
  Squelettes.pointsDeVies = 17;
  Fantomes.pointsDeVies = 18;
  Sorcieres.pointsDeVies = 25;

  ADGobelin =8;
  ADsquelette = 9;
  ADsorciere = 10;
  ADfantome = 9;
   // INITIALISATION DES COMBATS ++++++++++++++++++++++



finBoucleLvl5++;
        system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n\n\n\n");
printf("\n     ******************************************************************************      ");
printf("\n     |    ___    ______________________________________                           |     ");
printf("\n     |   |'o'|< | ENCORE VOUS BORDEL !?!?!?!?!?!?      |   |**************|       |     ");
printf("\n     |   /||\\   | le prochain donjon est dur je vais   |   |    Tuba      |       |     ");
printf("\n     |    /\\    | vous brader un peu les prix rien :)  |   |**************|       |     ");
printf("\n     |          |______________________________________|         100G(4)          |     ");
printf("\n     |                                                                            |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |         | Potion rouge |      |  Smoke Bomb  |      |   Boost PP   |       |     ");
printf("\n     |         |**************|      |**************|      |**************|       |     ");
printf("\n     |               3G(1)                7G(2)                 20G(3)           |     ");
printf("\n     ******************************************************************************      ");




printf("\n          Alors ? Faire chauffer la carte bleu ?\n 1 : OUI\n 2 : NON ");

scanf("%d",&choix5);
if(choix5 == 2){
    printf("\n\n          Avec la crise du corona les temps sont dures...\n          Alors vous vous dirigez vers le donjons sans rien acheter");
}
while(choix5 == 1){
if(choix5 == 1){

 printf("\n\n          Tres bien ! que voulez vous acheter ?\n 1 : Potion rouge\n 2 : Smoke Bomb\n 3 : Boost PP\n 4 : Tuba\n 5 : Heuu j'ai change d'avis");
 scanf("%d",&choixobjets);

 switch(choixobjets){
case 1 : printf("\n\n\n          Potion rouge ! pour 3 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
}
if(choix4 == 1){
    change = gold -3;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 3;
        potionsRouge++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 2 : printf("\n\n\n          Smoke Bomb ! pour 7 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

    printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -7;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 7;
        SmokeBomb++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 3 : printf("\n\n\n          Boost PP ! pour 20 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
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
        BoostPP++;
    }
    if(change < 0 ){
        printf("\n          PAIEMENT REFUSE\n          Vous n'avez pas assez d'argent ! ");
    }

  printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
  }

break;

case 4 : printf("\n\n\n          Tuba : (un objet permettant de traverser les salles submergees !) pour 100 Golds, etes vous sur ?\n 1 : OUI\n 2 : NON");
scanf("%d",&choix4);
if(choix4 == 2 ){

   printf("\n\n          Continuer a faire les boutiques ?\n 1 : OUI\n 2 : NON");
  scanf("%d",&choix5);
}
if(choix4 == 1){
    change = gold -100;
    if(change >= 0){
        printf("\n          PAIEMENT ACCEPTE\n          Merci de faire confiance a ma boutique ! bon courage voyageur ! ");
        gold = gold - 100;
        Tuba++;
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

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 O= - - - -X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");


system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 O=>- - - -X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");


system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 O=>= - - -X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 O=>=>- - -X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 O=>=>= - -X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 O=>=>=>- -X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 O=>=>=>= -X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 O=>=>=>=>-X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 O=>=>=>=>>X BOSS X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");

system("cls");

printf("\n                 *******************************************************************************      ");
printf("\n                 |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n                 |   ----O-------O---|      3                                                  |   ");
printf("\n                 |                   | ---- O -----|                                           |     ");
printf("\n                 |                                 |            5                              |     ");
printf("\n                 |                                 4         XXXXXXXX                          |     ");
printf("\n                 |                                 O=>=>=>=>>X[BOSS]X                          |     ");
printf("\n                 |                                           XXXXXXXX                          |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 |                                                                             |     ");
printf("\n                 *******************************************************************************      ");


system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);printf("\n\n\n");


printf("\n     ******************************************************************************      ");
printf("\n     |       1       2                 Monde 1 : FairWell Valley :                 |     ");
printf("\n     |   ----x------ X  -|      3                                                  |     ");
printf("\n     |                   | ---- X -----|                                           |     ");
printf("\n     |                                 |            5                              |     ");
printf("\n     |                                 4         XXXXXXXX                          |     ");
printf("\n     |                                 X - - - - X[BOSS]X                          |     ");
printf("\n     |                                           XXXXXXXX                          |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
printf("\n     |                                                                             |     ");
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
printf("\n               Vous apercevez la premiere salle dans une obscurite troublante.");
printf("\n               Etage actuel : %d",etageActuel);
printf("\n/\\");
scanf("%d",&xanogene);


srand(time(NULL));
 nombreRandome = rand() % 2;

 etageMAX = nombreRandome;
 etageMAX++;



// NOMBRE DE LVL
printf("\n         *******************************");
printf("\n          Ce donjon possede %d etages ! ",etageMAX);
printf("\n         *******************************");
// NOMBRE DE LVL



while(aventurier.pointsDeVies > 0 && etageActuel < etageMAX){



// ================   CHANGEMENT DETAGE  ==============


if(etageActuel == 1 && b==0){

            printf("\n*******************************************************************\n*******************************************************************\n*******************************************************************");
        printf("\n\n\n\n\n             Vous sortez la tete de l'escalier lentemant car le dernier etage s'offre a vous\n             Vous continuez a travers ce dedalle !");
        printf("\n             Etage actuel : %d",etageActuel);
        printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
AmuletteEscallier = 0;
    b++;
    Gobelins.pointsDeVies = Gobelins.pointsDeVies*1.5;
    Sorcieres.pointsDeVies = Sorcieres.pointsDeVies*1.5;
    Squelettes.pointsDeVies = Squelettes.pointsDeVies*1.5;
    Fantomes.pointsDeVies = Fantomes.pointsDeVies*1.5;
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
nombreRandome = rand() % 26;

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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);       break;

       case 1 : aventurier.attaque = aventurier.attaque + 2;
       printf("\n            Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n            Votre attaque a vu sa puissance augmenter !\nattaque : %d",aventurier.attaque);
       printf("\n            Vous continuez votre route dans la salle suivante");
          printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);       break;

       case 2 : aventurier.pointsDeVies = aventurier.pointsDeVies + 30;
       MAXIMUM(aventurier.pointsDeVies,100);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
// +++++++++++++++++    FIN SALLE AU TRESOR PAS TOUCHE   ++++++++++++++++++++++++++++
}
srand(time(NULL));
nombreRandome = rand() % 26;
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


      // BOSS SECRET
      // BOSS SECRET
      // BOSS SECRET
      // BOSS SECRET
      // BOSS SECRET

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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);       break;

       case 1 : aventurier.attaque = aventurier.attaque + 2;
       printf("\n            Une voix retentie dans tout le donjons murmurant : Vous serez couvert d'or");
       printf("\n            Votre attaque a vu sa puissance augmenter !\nattaque : %d",aventurier.attaque);
       printf("\n            Vous continuez votre route dans la salle suivante");
          printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);       break;

       case 2 : aventurier.pointsDeVies = aventurier.pointsDeVies + 30;
       MAXIMUM(aventurier.pointsDeVies,100);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

}
srand(time(NULL));
nombreRandome = rand() % 26;

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
            aventurier.pointsDeVies = aventurier.pointsDeVies +20;
            PPSort1  = PPSort1 +3;
            PPSort1  = PPSort2 +2;
            PPSort1  = PPSort3 +1;
           pourcentageCombats = pourcentageCombats * 1.5;
           maxCombat = maxCombat -3;
    printf("\n             Vous degainez votre briquet et faites virvolter une etincelle ce qui a pour effet d'allumer ce feu de camps.\n             et vous recuperez enormement de pv et quelques PP\n            PV : %d",aventurier.pointsDeVies);
    printf("\n             Cependant.... a present vous empestez une odeur etrange emise par le feu \n             (surement parceque les flemmes etaient violettes)\n             les monstres auront a present plus de chance d'apparaitre");
    NombreDeSalles++;
    pourcentageEsquallier = pourcentageEsquallier *1.5;
    pourcentageTresor = pourcentageTresor*1.2;
    BonfireLit =0;
    MAXIMUM(aventurier.pointsDeVies,100);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

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
            aventurier.pointsDeVies = aventurier.pointsDeVies +20;
           pourcentageCombats = pourcentageCombats * 1.5;
           maxCombat = maxCombat -3;
           PPSort1  = PPSort1 +3;
            PPSort1  = PPSort2 +2;
            PPSort1  = PPSort3 +1;
    printf("\n             Vous degainez votre briquet et faites virvolter une etincelle ce qui a pour effet d'allumer ce feu de camps.\n             et vous recuperez enormement de pv et quelques PP\n            PV : %d",aventurier.pointsDeVies);
    printf("\n             Cependant.... a present vous empestez une odeur etrange emise par le feu \n             (surement parceque les flemmes etaient violettes)\n             les monstres auront a present plus de chance d'apparaitre");
    NombreDeSalles++;
    pourcentageEsquallier = pourcentageEsquallier *1.5;
    pourcentageTresor = pourcentageTresor*1.2;
    BonfireLit =0;
    MAXIMUM(aventurier.pointsDeVies,100);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

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
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Gobelin\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Gobelin = Gobelins.pointsDeVies;
Gobelins.attaque = ADGobelin;

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
        Gobelin = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Gobelin > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Gobelin : %d",Gobelin);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+3 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le gobelin aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+15 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Gobelin >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le gobelin repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Gobelin");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Gobelins.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Gobelins.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Squelette\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Squelette = Squelettes.pointsDeVies;
Squelettes.attaque = ADsquelette;

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
        Squelette = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Squelette > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Squelette : %d",Squelette);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+3 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le squelette aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+15 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Squelette >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le squelette repond a votre attaque en jettant viollement son femur sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Squelette");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Squelettes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Squelettes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Fantome\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Fantome = Fantomes.pointsDeVies;
Fantomes.attaque = ADfantome;

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
        Fantome = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fantome > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fantome : %d",Fantome);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+3 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le fantome aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+15 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fantome >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le fantome repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Fantome");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fantomes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fantomes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Une sorciere\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Sorciere = Sorcieres.pointsDeVies;
Sorcieres.attaque = ADsorciere;

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
        Sorciere = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Sorciere > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la Sorciere : %d",Sorciere);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La Sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+3 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             La sorciere aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+15 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Sorciere >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              La Sorciere repond a votre attaque en vous jettant une potion dessus  ! ");
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
    printf("\n              Vous esquivez l'attage de la Sorciere");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Sorcieres.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Sorcieres.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
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
nombreRandome = rand() % 15;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 5;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 6;
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
aventurier.pointsDeVies = 100;
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Gobelin\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Gobelin = Gobelins.pointsDeVies;
Gobelins.attaque = ADGobelin;

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
        Gobelin = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Gobelin > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Gobelin : %d",Gobelin);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+3 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le gobelin aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+15 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Gobelin >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le gobelin repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Gobelin");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Gobelins.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Gobelins.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Squelette\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Squelette = Squelettes.pointsDeVies;
Squelettes.attaque = ADsquelette;

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
        Squelette = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Squelette > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Squelette : %d",Squelette);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+3 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le squelette aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+15 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Squelette >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le squelette repond a votre attaque en jettant viollement son femur sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Squelette");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Squelettes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Squelettes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Fantome\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Fantome = Fantomes.pointsDeVies;
Fantomes.attaque = ADfantome;

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
        Fantome = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fantome > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fantome : %d",Fantome);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+3 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le fantome aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+15 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fantome >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le fantome repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Fantome");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fantomes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fantomes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Une sorciere\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Sorciere = Sorcieres.pointsDeVies;
Sorcieres.attaque = ADsorciere;

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
        Sorciere = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Sorciere > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la Sorciere : %d",Sorciere);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La Sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+3 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             La sorciere aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+15 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Sorciere >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              La Sorciere repond a votre attaque en vous jettant une potion dessus  ! ");
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
    printf("\n              Vous esquivez l'attage de la Sorciere");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Sorcieres.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Sorcieres.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
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
nombreRandome = rand() % 15;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 5;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 6;
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
aventurier.pointsDeVies = 100;
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Gobelin\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Gobelin = Gobelins.pointsDeVies;
Gobelins.attaque = ADGobelin;

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
        Gobelin = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Gobelin > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Gobelin : %d",Gobelin);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+3 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le gobelin aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+15 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Gobelin >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le gobelin repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Gobelin");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Gobelins.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Gobelins.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Squelette\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Squelette = Squelettes.pointsDeVies;
Squelettes.attaque = ADsquelette;

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
        Squelette = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Squelette > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Squelette : %d",Squelette);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+3 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le squelette aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+15 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Squelette >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le squelette repond a votre attaque en jettant viollement son femur sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Squelette");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Squelettes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Squelettes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Fantome\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Fantome = Fantomes.pointsDeVies;
Fantomes.attaque = ADfantome;

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
        Fantome = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fantome > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fantome : %d",Fantome);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+3 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le fantome aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+15 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fantome >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le fantome repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Fantome");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fantomes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fantomes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Une sorciere\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Sorciere = Sorcieres.pointsDeVies;
Sorcieres.attaque = ADsorciere;

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
        Sorciere = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Sorciere > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la Sorciere : %d",Sorciere);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La Sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+3 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             La sorciere aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+15 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Sorciere >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              La Sorciere repond a votre attaque en vous jettant une potion dessus  ! ");
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
    printf("\n              Vous esquivez l'attage de la Sorciere");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Sorcieres.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Sorcieres.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
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
nombreRandome = rand() % 15;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 5;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 6;
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
aventurier.pointsDeVies = 100;
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Gobelin\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Gobelin = Gobelins.pointsDeVies;
Gobelins.attaque = ADGobelin;

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
        Gobelin = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Gobelin > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Gobelin : %d",Gobelin);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+3 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le gobelin aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+15 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Gobelin >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le gobelin repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Gobelin");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Gobelins.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Gobelins.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Squelette\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Squelette = Squelettes.pointsDeVies;
Squelettes.attaque = ADsquelette;

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
        Squelette = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Squelette > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Squelette : %d",Squelette);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+3 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le squelette aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+15 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Squelette >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le squelette repond a votre attaque en jettant viollement son femur sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Squelette");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Squelettes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Squelettes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Fantome\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Fantome = Fantomes.pointsDeVies;
Fantomes.attaque = ADfantome;

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
        Fantome = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fantome > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fantome : %d",Fantome);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+3 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le fantome aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+15 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fantome >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le fantome repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Fantome");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fantomes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fantomes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Une sorciere\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Sorciere = Sorcieres.pointsDeVies;
Sorcieres.attaque = ADsorciere;

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
        Sorciere = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Sorciere > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la Sorciere : %d",Sorciere);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La Sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+3 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             La sorciere aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+15 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Sorciere >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              La Sorciere repond a votre attaque en vous jettant une potion dessus  ! ");
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
    printf("\n              Vous esquivez l'attage de la Sorciere");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Sorcieres.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Sorcieres.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
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
nombreRandome = rand() % 15;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 5;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 6;
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
aventurier.pointsDeVies = 100;
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Gobelin\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Gobelin = Gobelins.pointsDeVies;
Gobelins.attaque = ADGobelin;

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
        Gobelin = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Gobelin > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Gobelin : %d",Gobelin);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+3 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le gobelin aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+15 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Gobelin >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le gobelin repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Gobelin");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Gobelins.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Gobelins.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Squelette\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Squelette = Squelettes.pointsDeVies;
Squelettes.attaque = ADsquelette;

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
        Squelette = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Squelette > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Squelette : %d",Squelette);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+3 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le squelette aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+15 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Squelette >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le squelette repond a votre attaque en jettant viollement son femur sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Squelette");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Squelettes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Squelettes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Fantome\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Fantome = Fantomes.pointsDeVies;
Fantomes.attaque = ADfantome;

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
        Fantome = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fantome > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fantome : %d",Fantome);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+3 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le fantome aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+15 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fantome >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le fantome repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Fantome");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fantomes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fantomes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Une sorciere\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Sorciere = Sorcieres.pointsDeVies;
Sorcieres.attaque = ADsorciere;

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
        Sorciere = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Sorciere > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la Sorciere : %d",Sorciere);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La Sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+3 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             La sorciere aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+15 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Sorciere >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              La Sorciere repond a votre attaque en vous jettant une potion dessus  ! ");
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
    printf("\n              Vous esquivez l'attage de la Sorciere");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Sorcieres.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Sorcieres.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
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
nombreRandome = rand() % 15;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 5;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 6;
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
aventurier.pointsDeVies = 100;
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Gobelin\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Gobelin = Gobelins.pointsDeVies;
Gobelins.attaque = ADGobelin;

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
        Gobelin = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Gobelin > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Gobelin : %d",Gobelin);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+3 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le gobelin aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+15 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Gobelin >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le gobelin repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Gobelin");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Gobelins.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Gobelins.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Squelette\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Squelette = Squelettes.pointsDeVies;
Squelettes.attaque = ADsquelette;

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
        Squelette = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Squelette > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Squelette : %d",Squelette);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+3 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le squelette aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+15 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Squelette >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le squelette repond a votre attaque en jettant viollement son femur sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Squelette");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Squelettes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Squelettes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Fantome\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Fantome = Fantomes.pointsDeVies;
Fantomes.attaque = ADfantome;

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
        Fantome = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fantome > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fantome : %d",Fantome);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+3 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le fantome aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+15 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fantome >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le fantome repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Fantome");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fantomes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fantomes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Une sorciere\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Sorciere = Sorcieres.pointsDeVies;
Sorcieres.attaque = ADsorciere;

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
        Sorciere = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Sorciere > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la Sorciere : %d",Sorciere);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La Sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+3 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             La sorciere aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+15 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Sorciere >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              La Sorciere repond a votre attaque en vous jettant une potion dessus  ! ");
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
    printf("\n              Vous esquivez l'attage de la Sorciere");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Sorcieres.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Sorcieres.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
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
nombreRandome = rand() % 15;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 5;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 6;
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
aventurier.pointsDeVies = 100;
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
case 0 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Gobelin\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Gobelin = Gobelins.pointsDeVies;
Gobelins.attaque = ADGobelin;

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
        Gobelin = -5;

    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++



// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Gobelin > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Gobelin : %d",Gobelin);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+3 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le gobelin aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque+15 - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
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


if(nombreRandome < Gobelins.esquive){
    printf("\n              Le gobelin esquive votre attaque");
}

if(nombreRandome >= Gobelins.esquive){
degatsInflige = aventurier.attaque - Gobelins.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Gobelin = Gobelin - degatsInflige;
printf("\n             vous infligez %d points de degats au Gobelin",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
// ===========  CHANGEMENT DE TOUR ================






if(Gobelin >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le gobelin repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Gobelin");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Gobelins.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Gobelins.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
}
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT GOBELIN WHILE PV O ++++++++++++++++++++++++++++++++
}
break;





// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================
// ======================= COMBAT SQUELETTE  ====================

case 1 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Squelette\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Squelette = Squelettes.pointsDeVies;
Squelettes.attaque = ADsquelette;

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
        Squelette = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Squelette > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Squelette : %d",Squelette);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+3 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le squelette aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque+15 - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
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


if(nombreRandome < Squelettes.esquive){
    printf("\n              Le squelette esquive votre attaque");
}

if(nombreRandome >= Squelettes.esquive){
degatsInflige = aventurier.attaque - Squelettes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Squelette = Squelette - degatsInflige;
printf("\n             vous infligez %d points de degats au Squelette",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Squelette >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le squelette repond a votre attaque en jettant viollement son femur sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Squelette");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Squelettes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Squelettes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT Squelette WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================
// ======================= COMBAT FANTOME  ====================





case 2 : printf("\n             Juste devant vous se dresse un monstre hideux... Un Fantome\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Fantome = Fantomes.pointsDeVies;
Fantomes.attaque = ADfantome;

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
        Fantome = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Fantome > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV du Fantome : %d",Fantome);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+3 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             Le fantome aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque+15 - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
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


if(nombreRandome < Fantomes.esquive){
    printf("\n              Le fantome esquive votre attaque");
}

if(nombreRandome >= Fantomes.esquive){
degatsInflige = aventurier.attaque - Fantomes.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Fantome = Fantome - degatsInflige;
printf("\n             vous infligez %d points de degats au Fantome",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Fantome >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              Le fantome repond a votre attaque en se ruant sur vous ! ");
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
    printf("\n              Vous esquivez l'attage du Fantome");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Fantomes.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Fantomes.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT fANTOME WHILE PV O ++++++++++++++++++++++++++++++++
}
break;






// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================
// ======================= COMBAT SORCIERE  ====================

case 3 : printf("\n             Juste devant vous se dresse un monstre hideux... Une sorciere\n             Le Combat commence !");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);Sorciere = Sorcieres.pointsDeVies;
Sorcieres.attaque = ADsorciere;

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
        Sorciere = -5;
    }
}
// ++++++++++++++++   UTILISATION SMOKE BOMB    +++++++++++

// ============================== DEBUT DU COMBAT  GOBELIN ===================================
while(aventurier.pointsDeVies > 0 && Sorciere > 0 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de la Sorciere : %d",Sorciere);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La Sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+3 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             La sorciere aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque+15 - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
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


if(nombreRandome < Sorcieres.esquive){
    printf("\n              La sorciere esquive votre attaque");
}

if(nombreRandome >= Sorcieres.esquive){
degatsInflige = aventurier.attaque - Sorcieres.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

Sorciere = Sorciere - degatsInflige;
printf("\n             vous infligez %d points de degats a la Sorciere",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================






if(Sorciere >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n              La Sorciere repond a votre attaque en vous jettant une potion dessus  ! ");
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
    printf("\n              Vous esquivez l'attage de la Sorciere");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = Sorcieres.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= Sorcieres.coupCritique){
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);}
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
nombreRandome = rand() % 15;
bonusXP = nombreRandome;

pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 5;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 6;
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
aventurier.pointsDeVies = 100;
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

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
nombreRandome = rand() % 1;
nombreRandome++;
    if(choix4 == nombreRandome ){
        printf("\n               Devant vous apparait 3 nouvelles portes... On dirait que\n               vous avez fait le bon choix... Laquelle choisir...\n 1 : DROITE\n 2 : GAUCHE\n 3 : MILIEUX");
        scanf("%d",&choix4);
       srand(time(NULL));
nombreRandome = rand() % 3;
nombreRandome++;
if(choix4 == nombreRandome){
    printf("\n               Devant vous apparait 4 nouvelles portes Encore... On dirait que\n               vous avez Encore fait le bon choix... Laquelle choisir Maintenant...\n 1 : DROITE\n 2 : GAUCHE\n 3 : HAUT\n 4 : BAS");
    scanf("%d",&choix4);
    srand(time(NULL));
nombreRandome = rand() % 4;
nombreRandome++;
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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

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
nombreRandome = rand() % 1;
nombreRandome++;
    if(choix4 == nombreRandome ){
        printf("\n               Devant vous apparait 3 nouvelles portes... On dirait que\n               vous avez fait le bon choix... Laquelle choisir...\n 1 : DROITE\n 2 : GAUCHE\n 3 : MILIEUX");
        scanf("%d",&choix4);
       srand(time(NULL));
nombreRandome = rand() % 3;
nombreRandome++;
if(choix4 == nombreRandome){
    printf("\n               Devant vous apparait 4 nouvelles portes Encore... On dirait que\n               vous avez Encore fait le bon choix... Laquelle choisir Maintenant...\n 1 : DROITE\n 2 : GAUCHE\n 3 : HAUT\n 4 : BAS");
    scanf("%d",&choix4);
    srand(time(NULL));
nombreRandome = rand() % 4;
nombreRandome++;
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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

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


   printf("\n               Vous arrivez a la fin d'un couloir et faites face a deux portes\n               Quelle porte choisir....\n 1 : DROITE\n 2 : GAUCHE");
    scanf("%d",&choix4);
    srand(time(NULL));
nombreRandome = rand() % 1;
nombreRandome++;
    if(choix4 == nombreRandome ){
        printf("\n               Devant vous apparait 3 nouvelles portes... On dirait que\n               vous avez fait le bon choix... Laquelle choisir...\n 1 : DROITE\n 2 : GAUCHE\n 3 : MILIEUX");
        scanf("%d",&choix4);
       srand(time(NULL));
nombreRandome = rand() % 3;
nombreRandome++;
if(choix4 == nombreRandome){
    printf("\n               Devant vous apparait 4 nouvelles portes Encore... On dirait que\n               vous avez Encore fait le bon choix... Laquelle choisir Maintenant...\n 1 : DROITE\n 2 : GAUCHE\n 3 : HAUT\n 4 : BAS");
    scanf("%d",&choix4);
    srand(time(NULL));
nombreRandome = rand() % 4;
nombreRandome++;
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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

break;
// ++++++++++++++++++++++ SALLE CHOIX ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE CHOIX ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE CHOIX ++++++++++++++++++++++




case 4 :
// ============================= SALLE SUBMERGEE ==============================
// ============================= SALLE SUBMERGEE ==============================
// ============================= SALLE SUBMERGEE ==============================
// ============================= SALLE SUBMERGEE ==============================









if( maxSubmerge <= 1){

 printf("\n           Devant vous un escallier... cependant il est totalement submerge par les eaux\n           Voulez vous quand meme y aller ? cela pourrait etre dangereux...\n 1 : OUI\n 2 : NON");
 scanf("%d",&choix4);
 if(choix4 == 1 && Tuba == 0){
    for(i = 0 ; i <2000 ; i++){
        printf("Bloops  Bloops Bloops Bloops Bloopps     Bloops         Bloops");
    }
    system("cls");
    printf("\n           Malheursement vous n'arrivez pas a rejoindre la surface a temps...\n           Vous mourrez de noyade");
    aventurier.pointsDeVies = 0;
 }


 if(choix4 == 1 && Tuba == 1){
    for(i = 0 ; i <2000 ; i++){
        printf("Bloops  Bloops Bloops Bloops Bloopps     Bloops         Bloops");

    }
    system("cls");
   printf("\n           Vous parvenez a rejoindre la sortie de cette masse d'eau et ... WOW\n           Vous sortez par les douves et parvenez a rejoindre la fin du donjon plus tot que prevu !!\n           Bon vous avez perdu votre tuba dans la bataille mais qu'importe !!");
   Tuba = 0;
   etageActuel = etageMAX;
 }
 if(choix4 == 2){

    printf("\n           Vous repartez de ce point d'eau sans savoir ce qu'il y a derriere\n           Mais avec au moins un minimum de bon sens...");

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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

maxSubmerge++;
}
srand(time(NULL));
nombreRandome = rand() % 26;
break;

// ++++++++++++++++++++++ SALLE SUBMERGER ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE SUBMERGER ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE SUBMERGER ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE SUBMERGER ++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE SUBMERGER ++++++++++++++++++++++





case 14 :
// ============================= SALLE SUBMERGEE ==============================
// ============================= SALLE SUBMERGEE ==============================
// ============================= SALLE SUBMERGEE ==============================
// ============================= SALLE SUBMERGEE ==============================









if( maxSubmerge <= 1){

 printf("\n           Devant vous un escallier... cependant il est totalement submerge par les eaux\n           Voulez vous quand meme y aller ? cela pourrait etre dangereux...\n 1 : OUI\n 2 : NON");
 scanf("%d",&choix4);
 if(choix4 == 1 && Tuba == 0){
    for(i = 0 ; i <2000 ; i++){
        printf("Bloops  Bloops Bloops Bloops Bloopps     Bloops         Bloops");

    }
    system("cls");
    printf("\n           Malheursement vous n'arrivez pas a rejoindre la surface a temps...\n           Vous mourrez de noyade");
    aventurier.pointsDeVies = 0;
 }


 if(choix4 == 1 && Tuba == 1){
    for(i = 0 ; i <2000 ; i++){
        printf("Bloops  Bloops Bloops Bloops Bloopps     Bloops         Bloops");

    }
    system("cls");
   printf("\n           Vous parvenez a rejoindre la sortie de cette masse d'eau et ... WOW\n           Vous sortez par les douves et parvenez a rejoindre la fin du donjon plus tot que prevu !!\n           Bon vous avez perdu votre tuba dans la bataille mais qu'importe !!");
   Tuba = 0;
   etageActuel = etageMAX;
 }
 if(choix4 == 2){

    printf("\n           Vous repartez de ce point d'eau sans savoir ce qu'il y a derriere\n           Mais avec au moins un minimum de bon sens...");

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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

maxSubmerge++;
}
srand(time(NULL));
nombreRandome = rand() % 26;
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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |     Xp : %d/100      |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,pointsDexperience,aventurier.pointsDeVies,gold);}
    }
srand(time(NULL));
nombreRandome = rand() % 26;
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
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |     Xp : %d/100      |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,pointsDexperience,aventurier.pointsDeVies,gold);}
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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
break;
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++
// ++++++++++++++++++++++ SALLE VIDE ++++++++++++++++++++++++++




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


// ==================================== BOSS LORD SOUPEX MONDE 1 - 5 ======================================
// ==================================== BOSS LORD SOUPEX MONDE 1 - 5 ======================================
// ==================================== BOSS LORD SOUPEX MONDE 1 - 5 ======================================
// ==================================== BOSS LORD SOUPEX MONDE 1 - 5 ======================================
// ==================================== BOSS LORD SOUPEX MONDE 1 - 5 ======================================
// ==================================== BOSS LORD SOUPEX MONDE 1 - 5 ======================================
// ==================================== BOSS LORD SOUPEX MONDE 1 - 5 ======================================
// ==================================== BOSS LORD SOUPEX MONDE 1 - 5 ======================================
// ==================================== BOSS LORD SOUPEX MONDE 1 - 5 ======================================
// ==================================== BOSS LORD SOUPEX MONDE 1 - 5 ======================================



if(MondeActuel == 1 && NiveauActuel == 5){


    printf("\n             'PAS SI VITE'.....");
    printf("\n             'VOUS PENSIEZ POUVOIR SORTIR DE MON DONJON ET DE LA FAIRWELL VALLEY AINSI ??!?!?!'.....");
    printf("\n             'PETIT ARROGANT VOUS ALLEZ PERIR ICI ET MAINTENANT !!'");
    printf("\n             ' VOUS NE SORTIREZ PAS DE CE DONJON VIVANT BATTEZ VOUS  !!! ");

    printf("\n/\\");
scanf("%d",&xanogene);
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n         Bon la c'est compliqe aventurier... Vous faites face a LORD SOUPEX... l'hote de ce donjon...");
printf("\n         Il est repute pour ne pas etre commode mais la.... c'est gros quand meme...");
printf("\n         Je crois bien que vous n'allez pas avoir le choix... il va falloir vous battre alors allez y ! ");
printf("\n           JE CROIS EN VOUS AVENTURIER :) ");

 printf("\n/\\");
scanf("%d",&xanogene);
system("cls");

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

printf("\n      Statistique de Lord Soupex : \n attaque : %d\n Coup Critique : %d\n Points de Vie : %d",LordSoupexx.attaque,LordSoupexx.coupCritique,LordSoupexx.pointsDeVies);

LordSoupex = LordSoupexx.pointsDeVies;

// =====================================  DEBUT DU COMBAT LORD SOUPEX ! !!!!!! +======================================
// =====================================  DEBUT DU COMBAT LORD SOUPEX ! !!!!!! +======================================
// =====================================  DEBUT DU COMBAT LORD SOUPEX ! !!!!!! +======================================
// =====================================  DEBUT DU COMBAT LORD SOUPEX ! !!!!!! +======================================
// =====================================  DEBUT DU COMBAT LORD SOUPEX ! !!!!!! +======================================
// =====================================  DEBUT DU COMBAT LORD SOUPEX ! !!!!!! +======================================
// =====================================  DEBUT DU COMBAT LORD SOUPEX ! !!!!!! +======================================
// =====================================  DEBUT DU COMBAT LORD SOUPEX ! !!!!!! +======================================
// =====================================  DEBUT DU COMBAT LORD SOUPEX ! !!!!!! +======================================
// =====================================  DEBUT DU COMBAT LORD SOUPEX ! !!!!!! +======================================



while(aventurier.pointsDeVies > 0 && LordSoupex > 30 ){


printf("\nVos PV : %d",aventurier.pointsDeVies);
printf("\nPV de LordSoupex : %d",LordSoupex);


printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(LordSoupex < 150 && LordSoupex > 120){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n      ///////////////////////////////////////////////////////////////////////////////////////////////////////////");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 120 && LordSoupex > 90){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////////////////////////////////////////////////////////////////////////                            ");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 90 && LordSoupex > 60){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     //////////////////////////////////////////////////////////                                                  ");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 60 && LordSoupex > 30){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////////////////////////////                                                                        ");
printf("\n     ************************************************************************************************************");
}




if(potionsRouge > 0){
         printf("\n             Vous possedez une potion rouge ? Voulez vous l'utiliser pour recuperez instantanement 10 PV ?\n 1 : OUI\n 2 : NON");
    scanf("%d",&choix);
    if(choix == 1){
        aventurier.pointsDeVies = aventurier.pointsDeVies +10;
        potionsRouge--;
        printf("\n             Glou glou glou glou +10 PV !");
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


if(nombreRandome < LordSoupexx.esquive){
    printf("\n               LordSoupex esquive votre attaque");
}

if(nombreRandome >= LordSoupexx.esquive){
degatsInflige = aventurier.attaque+3 - LordSoupexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

LordSoupex = LordSoupex - degatsInflige;
printf("\n             vous infligez %d points de degats a LordSoupex",degatsInflige);
}


PPSort1--;
        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le tourbillon d'acier...\n              Vous assenez un coup de poing au monstre a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < LordSoupexx.esquive){
    printf("\n              LordSoupex esquive votre attaque");
}

if(nombreRandome >= LordSoupexx.esquive){
degatsInflige = aventurier.attaque - LordSoupexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

LordSoupex = LordSoupex - degatsInflige;
printf("\n             vous infligez %d points de degats a LordSoupex",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;






// SPELL 2
case 2 :

if(PPSort2 >0){
printf("\n              Vous faites reflechir un rayon de lumiere sur l'ennemie ce qui l'eblouit grandement\n             LordSoupex aura plus de mal a vous toucher pour les 3 prochains tours");

srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < LordSoupexx.esquive){
    printf("\n              LordSoupex esquive le rayon de lumiere");
}
RefletTimmer = 3;

PPSort2--;
// PP SORT 2 OUI
}

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser le reflet de lame...\n              Vous assenez un coup de poing a LordSoupex a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < LordSoupexx.esquive){
    printf("\n              LordSoupex esquive votre attaque");
}

if(nombreRandome >= LordSoupexx.esquive){
degatsInflige = aventurier.attaque - LordSoupexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

LordSoupex = LordSoupex - degatsInflige;
printf("\n             vous infligez %d points de degats a LordSoupex",degatsInflige);
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


if(nombreRandome < LordSoupexx.esquive){
    printf("\n              LordSoupex esquive votre attaque");
}

if(nombreRandome >= LordSoupexx.esquive){
degatsInflige = aventurier.attaque+15 - LordSoupexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

LordSoupex = LordSoupex - degatsInflige;
printf("\n             vous infligez %d points de degats a LordSoupex",degatsInflige);
}


PPSort3--;

        }

        if(PPSort1 <= 0){
            printf("\n              Vous n'avez plus la force d'utiliser Frappe Fatale...\n              Vous assenez un coup de poing a LordSoupex a la place");
      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < LordSoupexx.esquive){
    printf("\n              LordSoupex esquive votre attaque");
}

if(nombreRandome >= LordSoupexx.esquive){
degatsInflige = aventurier.attaque - LordSoupexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

LordSoupex = LordSoupex - degatsInflige;
printf("\n             vous infligez %d points de degats a LordSoupex",degatsInflige);
}

// PAS ASSEZ DE PP
}
break;





case 4 :
    srand(time(NULL));
nombreRandome = rand() % 7;
    switch(nombreRandome){
        case 0 :
    printf("\n              Vous assenez une frappe a LordSoupex");
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
            printf("\n              Vous lechez votre doigt avant de le mettre dans l'oreille de LordSoupex ce qui lui fait mal");
            break;
        case 5 :
            printf("\n              Vous passer a tabac cette vile creature ");
            default : printf("\n             VOUS PREPAREZ UNE BONNE SOUSOUPE DE SOUPEX !!");
            break;

    }


      srand(time(NULL));
nombreRandome = rand() % 100;


if(nombreRandome < LordSoupexx.esquive){
    printf("\n              LordSoupex esquive votre attaque");
}

if(nombreRandome >= LordSoupexx.esquive){
degatsInflige = aventurier.attaque - LordSoupexx.armure;

      srand(time(NULL));
nombreRandome = rand() % 100;

if(nombreRandome <= aventurier.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE ! ");
    printf("\n              Vos degats sont doubles");

}

LordSoupex = LordSoupex - degatsInflige;
printf("\n             vous infligez %d points de degats a LordSoupex",degatsInflige);
}
break;

}

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);// ===========  CHANGEMENT DE TOUR ================
if(LordSoupex < 150 && LordSoupex > 120){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n      ///////////////////////////////////////////////////////////////////////////////////////////////////////////");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 120 && LordSoupex > 90){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////////////////////////////////////////////////////////////////////////                            ");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 90 && LordSoupex > 60){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     //////////////////////////////////////////////////////////                                                  ");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 60 && LordSoupex > 30){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////////////////////////////                                                                        ");
printf("\n     ************************************************************************************************************");
}





if(LordSoupex >0){


srand(time(NULL));
nombreRandome = rand() % 6;


switch(nombreRandome){
case 0 :
printf("\n                 LordSoupex repond a votre attaque en vous preparant une bonne SOUSOUPE  ! ");
break;
case 1 :
    printf("\n              LORD SOUPEX VOUS CRIS VIOLLEMENT PITIEZ MONSIEUR DESSUS ");
    break;
case 2 :
    printf("\n              LordSoupex fonce sur vous et vous frappe de ses phallanges");
    break;
case 3 :
    printf("\n              Aaaaa Aaaaahhh courrez !!! LordSoupex va nous bifler... Aoutch... vous trebuchez et vous faites mal");
    break;
case 4 :
    printf("\n              Vous subissez une terrible humiliation lorsque LordSoupex vous vola votre pousse... \n              vous decidez de vous planter pour purger votre ame");
    break;
case 5 :
    printf("\n              Cet encule de LordSoupex vous frappe en plein dans le genoux");
    break;
case 6 :
    printf("\n              LordSoupex vous explique comment l'insulte 'encule' est LGBTQ+ phobe... vous vous ennuiyez au point de vous frappez\n              pour ressentir un peu de vie ");
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(RefletTimmer >0){
    aventurier.esquive = 60;
    RefletTimmer--;
}

if(nombreRandome < aventurier.esquive){
    printf("\n              Vous esquivez l'attage de LordSoupex");
}

// SI LATTAQUE TOUCHE
if(nombreRandome >= aventurier.esquive){

degatsInflige = LordSoupexx.attaque - aventurier.armure;

if(aventurier.armure > 0){
    aventurier.armure--;
}



srand(time(NULL));
nombreRandome = rand() % 100;



if(nombreRandome <= LordSoupexx.coupCritique){
    degatsInflige = degatsInflige*2;
    printf("\n              COUP CRITIQUE Le monstre double ses degats");
}

printf("\n             LordSoupex vous a fait mal... et pas qu'un peu vous perdez %d points de vie",degatsInflige);
aventurier.pointsDeVies = aventurier.pointsDeVies - degatsInflige;

}


aventurier.esquive = 10;

printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
if(LordSoupex < 150 && LordSoupex > 120){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n      ///////////////////////////////////////////////////////////////////////////////////////////////////////////");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 120 && LordSoupex > 90){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////////////////////////////////////////////////////////////////////////                            ");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 90 && LordSoupex > 60){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     //////////////////////////////////////////////////////////                                                  ");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 60 && LordSoupex > 30){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////////////////////////////                                                                        ");
printf("\n     ************************************************************************************************************");
}


}
}
// +++++++++++++++++++++++++++++ COMBAT LORD SOUPEX P1 ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT LORD SOUPEX P1 ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT LORD SOUPEX P1 ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT LORD SOUPEX P1 ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT LORD SOUPEX P1 ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT LORD SOUPEX P1 ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT LORD SOUPEX P1 ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT LORD SOUPEX P1 ++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++ COMBAT LORD SOUPEX P1 ++++++++++++++++++++++++++++++++

// ============================== P2 PIERRE PAPPIER SICSEUA =======================
// ============================== P2 PIERRE PAPPIER SICSEUA =======================
// ============================== P2 PIERRE PAPPIER SICSEUA =======================
// ============================== P2 PIERRE PAPPIER SICSEUA =======================
// ============================== P2 PIERRE PAPPIER SICSEUA =======================
// ============================== P2 PIERRE PAPPIER SICSEUA =======================


printf("\n          'FINI DE JOUER !! VOUS ETES PATHETIQUE3'");
printf("\n          ' IL EST L'HEURE DE TERMINER CE COMBAT COMMES DES HOMMES !!");
printf("\n          ' BATTEZ VOUS AU PIERRE PAPIER SCISEAUX");



while(aventurier.pointsDeVies > 0 && LordSoupex > 0){

printf("\n/\\");
scanf("%d",&xanogene);
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

if(LordSoupex <= 60 && LordSoupex > 30){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////////////////////////////                                                                        ");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 30 && LordSoupex > 20){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////////////////                                                                                    ");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 20 && LordSoupex > 10){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ////////////                                                                                                ");
printf("\n     ************************************************************************************************************");
}
if(LordSoupex <= 10 && LordSoupex > 0){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n     ///                                                                                                         ");
printf("\n     ************************************************************************************************************");
}
printf("\n        'CHOISSISEZ ET VITE !!!\n 1 : PIERRE\n 2 : PAPPIER\n 3 : CISEAUX ");
scanf("%d",&ChoixAventurier);

srand(time(NULL));
nombreRandome = rand() % 3;
choixLordSoupex = nombreRandome;
choixLordSoupex++;

printf("\n          '1... 2...3 PIERRE....PAPPIER...CISEAUX !'");

printf("\n/\\");
scanf("%d",&xanogene);

// ==============================   EGALITE  ==============================
// ==============================   EGALITE  ==============================
// ==============================   EGALITE  ==============================
// ==============================   EGALITE  ==============================
if(ChoixAventurier == 1 && choixLordSoupex == 1){
        printf("\n\n\n\n                        PIERRE // PIERRE");
        printf("\n\n EGALITE ! PAS DE VAINQUEUR ! ");
printf("\n          'Arggg EGALITE.... REJOUEZ !!'");



}
if(ChoixAventurier == 2 && choixLordSoupex == 2){
        printf("\n\n\n\n                        PAPIER // PAPIER");
        printf("\n\n EGALITE ! PAS DE VAINQUEUR ! ");
printf("\n          'Arggg EGALITE.... REJOUEZ !!'");



}
if(ChoixAventurier == 3 && choixLordSoupex == 3){
        printf("\n\n\n\n                        CISEAUX // CISEAUX");
        printf("\n\n EGALITE ! PAS DE VAINQUEUR ! ");
printf("\n          'Arggg EGALITE.... REJOUEZ !!'");
}
// ++++++++++++++++++++++ EGALITE +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ EGALITE +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ EGALITE +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ EGALITE +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ EGALITE +++++++++++++++++++++++++++++


// ==============================   VICTOIRE LORDSOUPEX  ==============================
// ==============================   VICTOIRE LORDSOUPEX  ==============================
// ==============================   VICTOIRE LORDSOUPEX  ==============================
// ==============================   VICTOIRE LORDSOUPEX  ==============================


if(ChoixAventurier == 1 && choixLordSoupex == 2){
        printf("\n\n\n\n                        PIERRE // PAPIER");
        printf("\n\n Victoire de LORDSOUPEX ! ");

printf("\n          'Haha !!! ET VLAN J'AI GAGNE CETTE MANCHE !!'");
printf("\nPV -10");
aventurier.pointsDeVies = aventurier.pointsDeVies -10;



}
if(ChoixAventurier == 2 && choixLordSoupex == 3){
        printf("\n\n\n\n                        PAPIER // CISEAUX");
        printf("\n\n Victoire de LORDSOUPEX ! ");

printf("\n          'Haha !!! ET VLAN J'AI GAGNE CETTE MANCHE !!'");
printf("\nPV -10");
aventurier.pointsDeVies = aventurier.pointsDeVies -10;



}
if(ChoixAventurier == 3 && choixLordSoupex == 1){
        printf("\n\n\n\n                        CISEAUX // PIERRE");
        printf("\n\n Victoire de LORDSOUPEX ! ");

printf("\n          'Haha !!! ET VLAN J'AI GAGNE CETTE MANCHE !!'");
printf("\nPV -10");
aventurier.pointsDeVies = aventurier.pointsDeVies -10;
}

// ++++++++++++++++++++++ VICTOIRE LORDSOUPEX +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ VICTOIRE LORDSOUPEX +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ VICTOIRE LORDSOUPEX +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ VICTOIRE LORDSOUPEX +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ VICTOIRE LORDSOUPEX +++++++++++++++++++++++++++++




// ==============================   VICTOIRE AVENTURIER  ==============================
// ==============================   VICTOIRE AVENTURIER  ==============================
// ==============================   VICTOIRE AVENTURIER  ==============================
// ==============================   VICTOIRE AVENTURIER  ==============================


if(ChoixAventurier == 2 && choixLordSoupex == 1){
        printf("\n\n\n\n                        PAPIER // PIERRE");
        printf("\n\n Victoire de l'aventurieur ! ");

printf("\n          'OUI BON CA VA.... ENCORE !!'");
printf("\n LORD SOUPEX  -10");
LordSoupex = LordSoupex -10;



}
if(ChoixAventurier == 3 && choixLordSoupex == 2){
        printf("\n\n\n\n                        CISEAUX // PAPIER ");
        printf("\n\n Victoire de l'aventurieur ! ");

printf("\n          'OUI BON CA VA.... ENCORE !!'");
printf("\n LORD SOUPEX  -10");
LordSoupex = LordSoupex -10;



}
if(ChoixAventurier == 1 && choixLordSoupex == 3){
        printf("\n\n\n\n                        PIERRE // CISEAUX");

        printf("\n\n Victoire de l'aventurieur ! ");
printf("\n          'OUI BON CA VA.... ENCORE !!'");
printf("\n LORD SOUPEX  -10");
LordSoupex = LordSoupex -10;
}

// ++++++++++++++++++++++ VICTOIRE AVENTURIER  +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ VICTOIRE AVENTURIER +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ VICTOIRE AVENTURIER +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ VICTOIRE AVENTURIER +++++++++++++++++++++++++++++
// ++++++++++++++++++++++ VICTOIRE AVENTURIER +++++++++++++++++++++++++++++

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
// ++++++++++++++++++++++++++ P2 LORD SOUPEX ++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++ P2 LORD SOUPEX ++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++ P2 LORD SOUPEX ++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++ P2 LORD SOUPEX ++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++ P2 LORD SOUPEX ++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++ P2 LORD SOUPEX ++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++ P2 LORD SOUPEX ++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++ P2 LORD SOUPEX ++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++ P2 LORD SOUPEX ++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++ P2 LORD SOUPEX ++++++++++++++++++++++++++++++++++++++++
system("cls");
if(LordSoupex <= 0){
printf("\n\n\n                                                  LORD SOUPEX                                                    ");
printf("\n     ************************************************************************************************************");
printf("\n                                                                                                                 ");
printf("\n     ************************************************************************************************************");

printf("\n        AAAAARRRRGGGGGGGGGGG LA SSSOOOUUUSSSOOOUUUPPE NOOOOOOOOOOOOOOOOOOOOOOOOOOOON");
printf("\n/\\");
scanf("%d",&xanogene);

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

for(i = 0; i < 3000 ; i++){

    printf("Noooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo");
}
system("cls");

system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
printf("\n\n\n                                                  LORD SOUPEX(MORT)                                          ");
printf("\n     ************************************************************************************************************");
printf("\n                                                                                                                 ");
printf("\n     ************************************************************************************************************");


// ===============================  REMISES DES RECOMPENSES ==================================

srand(time(NULL));
nombreRandome = rand() % 100;
bonusXP = nombreRandome;
bonusXP = bonusXP +50;
pointsDexperience = pointsDexperience + bonusXP;

srand(time(NULL));
nombreRandome = rand() % 5;

if(nombreRandome == 2){
     srand(time(NULL));
nombreRandome = rand() % 6;
    gold = gold + nombreRandome;
}

LordSoupexVaincu++;
printf("\n             VOUS AVEZ VAINCU LORD SOUPEX ! MONDE 1 TERMINE !\nRecompenses :\n Experiences + %d",bonusXP);
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
aventurier.pointsDeVies = 100;
PPSort1 = 10;
PPSort2 = 5;
PPSort3 = 3;
}
// IF LORD SOUPEX MORT
}
}
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++ BOSS LORD SOUPEX MONDE 1 - 5 ++++++++++++++++++++++++++++++++++++++










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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);

for(i = 0 ; i < 4000 ; i++){

    printf("////////////////");
}
system("cls");
printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);





if(MondeActuel == 1 && NiveauActuel != 5){
        srand(time(NULL));
nombreRandome = rand() % 20;
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
NiveauActuel++;
printf("\n\n\n           Stage %d/%d ===> Stage %d/%d",MondeActuel,NiveauActuel,MondeActuel,NiveauActuel+1);
}

if(MondeActuel == 1 && NiveauActuel == 5 && LordSoupexVaincu){
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
printf("\n     |                                  MONDE 2                                    |     ");
printf("\n     *******************************************************************************      ");

printf("\n\n\n           Stage %d/%d ===> Stage %d/%d",MondeActuel,NiveauActuel,MondeActuel+1,NiveauActuel-5);
MondeActuel++;
NiveauActuel = 0;
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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);
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

printf("\n     *************************************************************************************************************     \n       %s  |     Stage : %d / %d      |  LVL : %d   |  Xp : %d/100    |    Pts de Vie : %d/100      |  Golds : %d              \n     *************************************************************************************************************     ",pseudo,MondeActuel,NiveauActuel,LevelAventurier,pointsDexperience,aventurier.pointsDeVies,gold);





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




printf("\n     Merci beaucoup d'avour joue au Monde 1 de Deeper World !!\n afin de poursuivre vers le monde 2 veuillez copier coller votre sauvegarde dans le dossier 'saves'\n du dossier Monde 2 !");
printf("\n     Une fois cela fait !! vous n'avez plus qu'a lancer le nouveau programme et a vous amuser :)");
// MAIN
}

























































































