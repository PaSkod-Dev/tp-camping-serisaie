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
  * Fonction : flush_in
  * But      : Vide le buffer d'entree standard apres une saisie invalide
  * Entree   : Aucune
  * Sortie   : Aucune
  *-----------------------------------------------------------------------*/
 static void flush_in(void) {
     int c;
     while ((c = getchar()) != '\n' && c != EOF) {
         /* Consomme les caracteres restants */
     }
 }
 /* Fin flush_in */
 
 /*-------------------------------------------------
  * Fonction : show_menu
  * But      : Affiche le menu principal du programme
  * Entree   : Aucune
  * Sortie   : Aucune
  *-------------------------------------------------*/
 static void show_menu(void) {
     printf("\nMenu principal :\n");
     printf("1 - Ajouter un type d'emplacement\n");
     printf("2 - Modifier un type d'emplacement\n");
     printf("3 - Supprimer un type d'emplacement\n");
     printf("4 - Consulter un type d'emplacement\n");
     printf("5 - Lister tous les types d'emplacement\n");
     printf("0 - Quitter\n");
     printf("\nVotre choix : ");
 }
 /* Fin show_menu */
 
 /*------------------------------------------------------
  * Fonction : get_choice
  * But      : Lit et valide le choix de l'utilisateur
  * Entree   : Aucune
  * Sortie   : Le choix de l'utilisateur (-1 si invalide)
  *------------------------------------------------------*/
 static int get_choice(void) {
     int choix;
     int resultat;
     
     resultat = scanf("%d", &choix);
     
     if (resultat != 1) {
         flush_in();
         choix = -1;
     }
     
     return choix;
 }
 /* Fin get_choice */
 
 /*--------------------------------------------------------------------
  * Fonction : do_choice
  * But      : Execute l'action correspondant au choix de l'utilisateur
  * Entree   : choix - numero de l'action a executer
  * Sortie   : Aucune
  *--------------------------------------------------------------------*/
 static void do_choice(int choix) {
     switch (choix) {
         case 1:
             add_type();
             break;
         case 2:
             edit_type();
             break;
         case 3:
             del_type();
             break;
         case 4:
             get_type();
             break;
         case 5:
             list_types();
             break;
         case 0:
             printf("\nAu revoir !\n");
             break;
         default:
             printf("\nChoix invalide !\n");
             break;
     }
 }
 /* Fin do_choice */
 
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
         show_menu();
         choix = get_choice();
         do_choice(choix);
     } while (choix != 0);
 
     return 0;
 }

  //FIN DU FICHIER main.c