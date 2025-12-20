/*
    NAME : types_emplacement.c
    PURPOSE : Implementation des fonctions de gestion des types d'emplacement
              en utilisant un fichier sequentiel texte.
    AUTHORS : SEWONOU Pascal & EDOH BEDI Komi Godwin
    CREATED : 09/12/2025
    UPDATED : 20/12/2025
 */

 #include "types_emplacement.h"
 #include <stdio.h>
 
 //FONCTIONS DE GESTION DES FICHIERS
 
 /*---------------------------------------------------------
  * Fonction : ouvrir_fichier_lecture
  * But      : Ouvre un fichier en mode lecture
  * Entree   : nom_fichier - chemin du fichier a ouvrir
  * Sortie   : Pointeur vers le fichier ouvert, NULL si echec
  *----------------------------------------------------------*/
 FILE *ouvrir_fichier_lecture(const char *nom_fichier) {
     FILE *fichier = fopen(nom_fichier, "r");
     if (fichier == NULL) {
         printf("Le fichier %s n'existe pas encore.\n", nom_fichier);
     }
     return fichier;
 }
 /* Fin ouvrir_fichier_lecture */
 
 /*---------------------------------------------------------
  * Fonction : ouvrir_fichier_ajout
  * But      : Ouvre un fichier en mode ajout (append)
  * Entree   : nom_fichier - chemin du fichier a ouvrir
  * Sortie   : Pointeur vers le fichier ouvert, NULL si echec
  *----------------------------------------------------------*/
 FILE *ouvrir_fichier_ajout(const char *nom_fichier) {
     FILE *fichier = fopen(nom_fichier, "a");
     if (fichier == NULL) {
         printf("Erreur : impossible d'ouvrir le fichier %s en mode ajout.\n",
                nom_fichier);
     }
     return fichier;
 }
 /* Fin ouvrir_fichier_ajout */
 
 /*----------------------------------------------------------------
  * Fonction : ouvrir_fichier_ecriture
  * But      : Ouvre un fichier en mode ecriture (ecrase le contenu)
  * Entree   : nom_fichier - chemin du fichier a ouvrir
  * Sortie   : Pointeur vers le fichier ouvert, NULL si echec
  *-----------------------------------------------------------------*/
 FILE *ouvrir_fichier_ecriture(const char *nom_fichier) {
     FILE *fichier = fopen(nom_fichier, "w");
     if (fichier == NULL) {
         printf("Erreur : impossible d'ouvrir le fichier %s en mode ecriture.\n",
                nom_fichier);
     }
     return fichier;
 }
 /* Fin ouvrir_fichier_ecriture */
 
 /*-------------------------------------------------------
  * Fonction : fermer_fichier
  * But      : Ferme un fichier prealablement ouvert
  * Entree   : fichier - pointeur vers le fichier a fermer
  * Sortie   : Aucune
  *-------------------------------------------------------*/
 void fermer_fichier(FILE *fichier) {
     if (fichier != NULL) {
         fclose(fichier);
     }
 }
 /* Fin fermer_fichier */
 
 //FONCTIONS DE LECTURE / ECRITURE DANS LE FICHIER
 
 /*----------------------------------------------------------------
  * Fonction : lire_type_emplacement
  * But      : Lit un type d'emplacement depuis un fichier texte
  * Entree   : fichier - pointeur vers le fichier ouvert en lecture
  *            type    - pointeur vers la structure a remplir
  * Sortie   : 1 si lecture reussie, 0 sinon
  *-----------------------------------------------------------------*/
 int lire_type_emplacement(FILE *fichier, TypeEmplacement *type) {
     int resultat = fscanf(fichier, "%d %49s %f", 
                           &type->numero_type,
                           type->nom, 
                           &type->prix_jour_personne);
     return (resultat == 3);
 }
 /* Fin lire_type_emplacement */
 
 /*----------------------------------------------------------------
  * Fonction : ecrire_type_emplacement
  * But      : Ecrit un type d'emplacement dans un fichier texte
  * Entree   : fichier - pointeur vers le fichier ouvert en ecriture
  *            type    - pointeur vers la structure a ecrire
  * Sortie   : 1 si ecriture reussie, 0 sinon
  *----------------------------------------------------------------*/
 int ecrire_type_emplacement(FILE *fichier, const TypeEmplacement *type) {
     int resultat = fprintf(fichier, "%d %s %.2f\n", 
                            type->numero_type, 
                            type->nom,
                            type->prix_jour_personne);
     return (resultat > 0);
 }
 /* Fin ecrire_type_emplacement */
 
 //FONCTIONS METIER SUR LES TYPES D'EMPLACEMENT
 
 /*---------------------------------------------------------------------------
  * Fonction : trouver_prochain_numero
  * But      : Trouve le prochain numero disponible pour un type d'emplacement
  * Entree   : Aucune
  * Sortie   : Prochain numero disponible (max + 1)
  *----------------------------------------------------------------------------*/
 int trouver_prochain_numero(void) {
     FILE *fichier;
     TypeEmplacement type;
     int numero_max = 0;
     int prochain_numero = 1;
 
     fichier = ouvrir_fichier_lecture(NOM_FICHIER);
     
     if (fichier != NULL) {
         while (lire_type_emplacement(fichier, &type)) {
             if (type.numero_type > numero_max) {
                 numero_max = type.numero_type;
             }
         }
         fermer_fichier(fichier);
         prochain_numero = numero_max + 1;
     }
 
     return prochain_numero;
 }
 /* Fin trouver_prochain_numero */
 
 /*-------------------------------------------------------------
  * Fonction : afficher_type_emplacement
  * But      : Affiche les informations d'un type d'emplacement
  * Entree   : type - pointeur vers la structure a afficher
  * Sortie   : Aucune
  *-------------------------------------------------------------*/
 static void afficher_type_emplacement(const TypeEmplacement *type) {
     printf("\n- Type d'emplacement numero %d -\n", type->numero_type);
     printf("Nom : %s\n", type->nom);
     printf("Prix par jour et par personne : %.2f euros\n",
            type->prix_jour_personne);
     printf("------------------------------------\n");
 }
 /* Fin afficher_type_emplacement */
 
 /*-------------------------------------------------------------------
  * Fonction : ajouter_type_emplacement
  * But      : Ajoute un nouveau type d'emplacement dans le fichier
  * Entree   : Aucune (saisie interactive)
  * Sortie   : Aucune
  *-------------------------------------------------------------------*/
 void ajouter_type_emplacement(void) {
     FILE *fichier;
     TypeEmplacement nouveau_type;
     int succes = 0;
 
     printf("\n== AJOUT D'UN TYPE D'EMPLACEMENT ==\n");
 
     nouveau_type.numero_type = trouver_prochain_numero();
     printf("Numero de type : %d\n", nouveau_type.numero_type);
 
     printf("Nom du type d'emplacement : ");
     scanf(" %49[^\n]", nouveau_type.nom);
 
     printf("Prix par jour et par personne (en euros) : ");
     scanf("%f", &nouveau_type.prix_jour_personne);
 
     fichier = ouvrir_fichier_ajout(NOM_FICHIER);
     
     if (fichier != NULL) {
         succes = ecrire_type_emplacement(fichier, &nouveau_type);
         fermer_fichier(fichier);
         
         if (succes) {
             printf("\nType d'emplacement ajoute avec succes !\n");
         } else {
             printf("\nErreur lors de l'ecriture dans le fichier.\n");
         }
     } else {
         printf("Erreur : impossible d'ajouter le type d'emplacement.\n");
     }
 }
 /* Fin ajouter_type_emplacement */
 
 /*---------------------------------------------------------------------
  * Fonction : consulter_type_emplacement
  * But      : Recherche et affiche un type d'emplacement par son numero
  * Entree   : Aucune (saisie interactive)
  * Sortie   : Aucune
  *----------------------------------------------------------------------*/
 void consulter_type_emplacement(void) {
     FILE *fichier;
     TypeEmplacement type;
     int numero_recherche;
     int trouve = 0;
 
     printf("\n== CONSULTATION D'UN TYPE D'EMPLACEMENT ==\n");
     printf("Numero du type d'emplacement a consulter : ");
     scanf("%d", &numero_recherche);
 
     fichier = ouvrir_fichier_lecture(NOM_FICHIER);
     
     if (fichier != NULL) {
         while (lire_type_emplacement(fichier, &type) && !trouve) {
             if (type.numero_type == numero_recherche) {
                 afficher_type_emplacement(&type);
                 trouve = 1;
             }
         }
         fermer_fichier(fichier);
         
         if (!trouve) {
             printf("Type d'emplacement numero %d introuvable.\n", numero_recherche);
         }
     } else {
         printf("Aucun type d'emplacement enregistre.\n");
     }
 }
 /* Fin consulter_type_emplacement */
 
 /*------------------------------------------------------------
  * Fonction : lister_types_emplacement
  * But      : Affiche tous les types d'emplacement enregistres
  * Entree   : Aucune
  * Sortie   : Aucune 
  *------------------------------------------------------------*/
 void lister_types_emplacement(void) {
     FILE *fichier;
     TypeEmplacement type;
     int nombre_types = 0;
 
     printf("\n== LISTE DES TYPES D'EMPLACEMENT ==\n\n");
 
     fichier = ouvrir_fichier_lecture(NOM_FICHIER);
     
     if (fichier != NULL) {
         while (lire_type_emplacement(fichier, &type)) {
             afficher_type_emplacement(&type);
             nombre_types++;
         }
         printf("\nTotal : %d type(s) d'emplacement.\n", nombre_types);
         fermer_fichier(fichier);
     } else {
         printf("Aucun type d'emplacement enregistre.\n");
     }
 }
 /* Fin lister_types_emplacement */
 
 /*--------------------------------------------------------------
  * Fonction : modifier_type_emplacement
  * But      : Modifie un type d'emplacement existant
  * Entree   : Aucune (saisie interactive)
  * Sortie   : Aucune
  * Methode  : Utilise un fichier temporaire pour la reecriture
  *-------------------------------------------------------------*/
 void modifier_type_emplacement(void) {
     FILE *fichier_lecture;
     FILE *fichier_ecriture;
     TypeEmplacement type;
     int numero_recherche;
     int trouve = 0;
     int fichiers_ouverts = 0;
     const char *nom_fichier_temp = "temp_types_emplacement.txt";
 
     printf("\n== MODIFICATION D'UN TYPE D'EMPLACEMENT ==\n");
     printf("Numero du type d'emplacement a modifier : ");
     scanf("%d", &numero_recherche);
 
     fichier_lecture = ouvrir_fichier_lecture(NOM_FICHIER);
     
     if (fichier_lecture != NULL) {
         fichier_ecriture = ouvrir_fichier_ecriture(nom_fichier_temp);
         
         if (fichier_ecriture != NULL) {
             fichiers_ouverts = 1;
             
             while (lire_type_emplacement(fichier_lecture, &type)) {
                 if (type.numero_type == numero_recherche) {
                     trouve = 1;
 
                     printf("\nAnciennes informations :\n");
                     afficher_type_emplacement(&type);
 
                     printf("\nNouvelles informations :\n");
                     printf("Nom du type d'emplacement (actuel : %s) : ", type.nom);
                     scanf(" %49[^\n]", type.nom);
 
                     printf("Prix par jour et par personne (actuel : %.2f) : ",
                            type.prix_jour_personne);
                     scanf("%f", &type.prix_jour_personne);
                 }
                 ecrire_type_emplacement(fichier_ecriture, &type);
             }
             
             fermer_fichier(fichier_ecriture);
         } else {
             printf("Erreur : impossible de creer le fichier temporaire.\n");
         }
         
         fermer_fichier(fichier_lecture);
     } else {
         printf("Aucun type d'emplacement enregistre.\n");
     }
 
     if (fichiers_ouverts) {
         if (!trouve) {
             printf("Type d'emplacement numero %d introuvable.\n", numero_recherche);
             remove(nom_fichier_temp);
         } else {
             remove(NOM_FICHIER);
             rename(nom_fichier_temp, NOM_FICHIER);
             printf("\nType d'emplacement modifie avec succes !\n");
         }
     }
 }
 /* Fin modifier_type_emplacement */
 
 /*-------------------------------------------------------------
  * Fonction : supprimer_type_emplacement
  * But      : Supprime un type d'emplacement du fichier
  * Entree   : Aucune (saisie interactive)
  * Sortie   : Aucune
  * Methode  : Utilise un fichier temporaire pour la reecriture
  *-------------------------------------------------------------*/
 void supprimer_type_emplacement(void) {
     FILE *fichier_lecture;
     FILE *fichier_ecriture;
     TypeEmplacement type;
     int numero_recherche;
     int trouve = 0;
     int fichiers_ouverts = 0;
     const char *nom_fichier_temp = "temp_types_emplacement.txt";
 
     printf("\n== SUPPRESSION D'UN TYPE D'EMPLACEMENT ==\n");
     printf("Numero du type d'emplacement a supprimer : ");
     scanf("%d", &numero_recherche);
 
     fichier_lecture = ouvrir_fichier_lecture(NOM_FICHIER);
     
     if (fichier_lecture != NULL) {
         fichier_ecriture = ouvrir_fichier_ecriture(nom_fichier_temp);
         
         if (fichier_ecriture != NULL) {
             fichiers_ouverts = 1;
             
             while (lire_type_emplacement(fichier_lecture, &type)) {
                 if (type.numero_type == numero_recherche) {
                     trouve = 1;
                     printf("\nType d'emplacement numero %d supprime.\n", numero_recherche);
                 } else {
                     ecrire_type_emplacement(fichier_ecriture, &type);
                 }
             }
             
             fermer_fichier(fichier_ecriture);
         } else {
             printf("Erreur : impossible de creer le fichier temporaire.\n");
         }
         
         fermer_fichier(fichier_lecture);
     } else {
         printf("Aucun type d'emplacement enregistre.\n");
     }
 
     if (fichiers_ouverts) {
         if (!trouve) {
             printf("Type d'emplacement numero %d introuvable.\n", numero_recherche);
             remove(nom_fichier_temp);
         } else {
             remove(NOM_FICHIER);
             rename(nom_fichier_temp, NOM_FICHIER);
             printf("Suppression terminee avec succes !\n");
         }
     }
 } 
 //FIN DU FICHIER types_emplacement.c