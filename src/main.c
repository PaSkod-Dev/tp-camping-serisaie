/*
    NAME : main.c
    PURPOSE : Programme principal - Gestion des types d'emplacement
              Camping "La Cerisaie"
    AUTHORS : SEWONOU Pascal & EDOH BEDI Komi Godwin
    CREATED : 09/12/2025
    UPDATED : 20/12/2025
 */

#include <stdio.h>
#include "types_emplacement.h"
 
 /*----------------------------------------------------------------------
  * Fonction : vider_buffer
  * But      : Vide le buffer d'entree standard apres une saisie invalide
  * Entree   : Aucune
  * Sortie   : Aucune
  *-----------------------------------------------------------------------*/
 static void vider_buffer(void) {
     int c;
     while ((c = getchar()) != '\n' && c != EOF) {
         /* Consomme les caracteres restants */
     }
 }
 /* Fin vider_buffer */
 
 /*-------------------------------------------------
  * Fonction : afficher_menu
  * But      : Affiche le menu principal du programme
  * Entree   : Aucune
  * Sortie   : Aucune
  *-------------------------------------------------*/
 static void afficher_menu(void) {
     printf("\nMenu principal :\n");
     printf("1 - Ajouter un type d'emplacement\n");
     printf("2 - Modifier un type d'emplacement\n");
     printf("3 - Supprimer un type d'emplacement\n");
     printf("4 - Consulter un type d'emplacement\n");
     printf("5 - Lister tous les types d'emplacement\n");
     printf("0 - Quitter\n");
     printf("\nVotre choix : ");
 }
 /* Fin afficher_menu */
 
 /*------------------------------------------------------
  * Fonction : lire_choix
  * But      : Lit et valide le choix de l'utilisateur
  * Entree   : Aucune
  * Sortie   : Le choix de l'utilisateur (-1 si invalide)
  *------------------------------------------------------*/
 static int lire_choix(void) {
     int choix;
     int resultat;
     
     resultat = scanf("%d", &choix);
     
     if (resultat != 1) {
         vider_buffer();
         choix = -1;
     }
     
     return choix;
 }
 /* Fin lire_choix */
 
 /*--------------------------------------------------------------------
  * Fonction : traiter_choix
  * But      : Execute l'action correspondant au choix de l'utilisateur
  * Entree   : choix - numero de l'action a executer
  * Sortie   : Aucune
  *--------------------------------------------------------------------*/
 static void traiter_choix(int choix) {
     switch (choix) {
         case 1:
             ajouter_type_emplacement();
             break;
         case 2:
             modifier_type_emplacement();
             break;
         case 3:
             supprimer_type_emplacement();
             break;
         case 4:
             consulter_type_emplacement();
             break;
         case 5:
             lister_types_emplacement();
             break;
         case 0:
             printf("\nAu revoir !\n");
             break;
         default:
             printf("\nChoix invalide !\n");
             break;
     }
 }
 /* Fin traiter_choix */
 
 /*-------------------------------------------------------------------
  * Fonction : main
  * But      : Point d'entree du programme - Boucle principale du menu
  * Entree   : Aucune
  * Sortie   : 0 si execution reussie
  *-------------------------------------------------------------------*/
 int main(void) {
     int choix;
 
     printf("\n");
     printf("   _______________________________");
     printf("   GESTION DES TYPES D'EMPLACEMENT\n");
     printf("   Camping \"La Cerisaie\"\n");
     printf("   -------------------------------\n");
 
     do {
         afficher_menu();
         choix = lire_choix();
         traiter_choix(choix);
     } while (choix != 0);
 
     return 0;
 }

  //FIN DU FICHIER main.c