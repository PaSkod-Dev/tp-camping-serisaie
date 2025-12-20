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
  * Fonction : fopen_r
  * But      : Ouvre un fichier en mode lecture
  * Entree   : filename- chemin du fichier a ouvrir
  * Sortie   : Pointeur vers le fichier ouvert, NULL si echec
  *----------------------------------------------------------*/
 FILE *fopen_r(const char *filename) {
     FILE *fichier = fopen(filename, "r");
     if (fichier == NULL) {
         printf("Le fichier %s n'existe pas encore.\n", filename);
     }
     return fichier;
 }
 /* Fin fopen_r */
 
 /*---------------------------------------------------------
  * Fonction : fopen_a
  * But      : Ouvre un fichier en mode ajout (append)
  * Entree   : filename- chemin du fichier a ouvrir
  * Sortie   : Pointeur vers le fichier ouvert, NULL si echec
  *----------------------------------------------------------*/
 FILE *fopen_a(const char *filename) {
     FILE *fichier = fopen(filename, "a");
     if (fichier == NULL) {
         printf("Erreur : impossible d'ouvrir le fichier %s en mode ajout.\n",
                filename);
     }
     return fichier;
 }
 /* Fin fopen_a */
 
 /*----------------------------------------------------------------
  * Fonction : fopen_w
  * But      : Ouvre un fichier en mode ecriture (ecrase le contenu)
  * Entree   : filename- chemin du fichier a ouvrir
  * Sortie   : Pointeur vers le fichier ouvert, NULL si echec
  *-----------------------------------------------------------------*/
 FILE *fopen_w(const char *filename) {
     FILE *fichier = fopen(filename, "w");
     if (fichier == NULL) {
         printf("Erreur : impossible d'ouvrir le fichier %s en mode ecriture.\n",
                filename);
     }
     return fichier;
 }
 /* Fin fopen_w */
 
 /*-------------------------------------------------------
  * Fonction : fclose_f
  * But      : Ferme un fichier prealablement ouvert
  * Entree   : fichier - pointeur vers le fichier a fermer
  * Sortie   : Aucune
  *-------------------------------------------------------*/
 void fclose_f(FILE *fichier) {
     if (fichier != NULL) {
         fclose(fichier);
     }
 }
 /* Fin fclose_f */
 
 //FONCTIONS DE LECTURE / ECRITURE DANS LE FICHIER
 
 /*----------------------------------------------------------------
  * Fonction : read_type
  * But      : Lit un type d'emplacement depuis un fichier texte
  * Entree   : fichier - pointeur vers le fichier ouvert en lecture
  *            type    - pointeur vers la structure a remplir
  * Sortie   : 1 si lecture reussie, 0 sinon
  *-----------------------------------------------------------------*/
 int read_type(FILE *fichier, SlotType *type) {
     int resultat = fscanf(fichier, "%d %49s %f", 
                           &type->numero_type,
                           type->nom, 
                           &type->prix_jour_personne);
     return (resultat == 3);
 }
 /* Fin read_type */
 
 /*----------------------------------------------------------------
  * Fonction : write_type
  * But      : Ecrit un type d'emplacement dans un fichier texte
  * Entree   : fichier - pointeur vers le fichier ouvert en ecriture
  *            type    - pointeur vers la structure a ecrire
  * Sortie   : 1 si ecriture reussie, 0 sinon
  *----------------------------------------------------------------*/
 int write_type(FILE *fichier, const SlotType *type) {
     int resultat = fprintf(fichier, "%d %s %.2f\n", 
                            type->numero_type, 
                            type->nom,
                            type->prix_jour_personne);
     return (resultat > 0);
 }
 /* Fin write_type */
 
 //FONCTIONS METIER SUR LES TYPES D'EMPLACEMENT
 
 /*---------------------------------------------------------------------------
  * Fonction : next_id
  * But      : Trouve le prochain numero disponible pour un type d'emplacement
  * Entree   : Aucune
  * Sortie   : Prochain numero disponible (max + 1)
  *----------------------------------------------------------------------------*/
 int next_id(void) {
     FILE *fichier;
     SlotType type;
     int numero_max = 0;
     int prochain_numero = 1;
 
     fichier = fopen_r(FILE_NAME);
     
     if (fichier != NULL) {
         while (read_type(fichier, &type)) {
             if (type.numero_type > numero_max) {
                 numero_max = type.numero_type;
             }
         }
         fclose_f(fichier);
         prochain_numero = numero_max + 1;
     }
 
     return prochain_numero;
 }
 /* Fin next_id */
 
 /*-------------------------------------------------------------
  * Fonction : show_type
  * But      : Affiche les informations d'un type d'emplacement
  * Entree   : type - pointeur vers la structure a afficher
  * Sortie   : Aucune
  *-------------------------------------------------------------*/
 static void show_type(const SlotType *type) {
     printf("\n- Type d'emplacement numero %d -\n", type->numero_type);
     printf("Nom : %s\n", type->nom);
     printf("Prix par jour et par personne : %.2f euros\n",
            type->prix_jour_personne);
     printf("------------------------------------\n");
 }
 /* Fin show_type */
 
 /*-------------------------------------------------------------------
  * Fonction : add_type
  * But      : Ajoute un nouveau type d'emplacement dans le fichier
  * Entree   : Aucune (saisie interactive)
  * Sortie   : Aucune
  *-------------------------------------------------------------------*/
 void add_type(void) {
     FILE *fichier;
     SlotType nouveau_type;
     int succes = 0;
 
     printf("\n== AJOUT D'UN TYPE D'EMPLACEMENT ==\n");
 
     nouveau_type.numero_type = next_id();
     printf("Numero de type : %d\n", nouveau_type.numero_type);
 
     printf("Nom du type d'emplacement : ");
     scanf(" %49[^\n]", nouveau_type.nom);
 
     printf("Prix par jour et par personne (en euros) : ");
     scanf("%f", &nouveau_type.prix_jour_personne);
 
     fichier = fopen_a(FILE_NAME);
     
     if (fichier != NULL) {
         succes = write_type(fichier, &nouveau_type);
         fclose_f(fichier);
         
         if (succes) {
             printf("\nType d'emplacement ajoute avec succes !\n");
         } else {
             printf("\nErreur lors de l'ecriture dans le fichier.\n");
         }
     } else {
         printf("Erreur : impossible d'ajouter le type d'emplacement.\n");
     }
 }
 /* Fin add_type */
 
 /*---------------------------------------------------------------------
  * Fonction : get_type
  * But      : Recherche et affiche un type d'emplacement par son numero
  * Entree   : Aucune (saisie interactive)
  * Sortie   : Aucune
  *----------------------------------------------------------------------*/
 void get_type(void) {
     FILE *fichier;
     SlotType type;
     int numero_recherche;
     int trouve = 0;
 
     printf("\n== CONSULTATION D'UN TYPE D'EMPLACEMENT ==\n");
     printf("Numero du type d'emplacement a consulter : ");
     scanf("%d", &numero_recherche);
 
     fichier = fopen_r(FILE_NAME);
     
     if (fichier != NULL) {
         while (read_type(fichier, &type) && !trouve) {
             if (type.numero_type == numero_recherche) {
                 show_type(&type);
                 trouve = 1;
             }
         }
         fclose_f(fichier);
         
         if (!trouve) {
             printf("Type d'emplacement numero %d introuvable.\n", numero_recherche);
         }
     } else {
         printf("Aucun type d'emplacement enregistre.\n");
     }
 }
 /* Fin get_type */
 
 /*------------------------------------------------------------
  * Fonction : list_types
  * But      : Affiche tous les types d'emplacement enregistres
  * Entree   : Aucune
  * Sortie   : Aucune 
  *------------------------------------------------------------*/
 void list_types(void) {
     FILE *fichier;
     SlotType type;
     int nombre_types = 0;
 
     printf("\n== LISTE DES TYPES D'EMPLACEMENT ==\n\n");
 
     fichier = fopen_r(FILE_NAME);
     
     if (fichier != NULL) {
         while (read_type(fichier, &type)) {
             show_type(&type);
             nombre_types++;
         }
         printf("\nTotal : %d type(s) d'emplacement.\n", nombre_types);
         fclose_f(fichier);
     } else {
         printf("Aucun type d'emplacement enregistre.\n");
     }
 }
 /* Fin list_types */
 
 /*--------------------------------------------------------------
  * Fonction : edit_type
  * But      : Modifie un type d'emplacement existant
  * Entree   : Aucune (saisie interactive)
  * Sortie   : Aucune
  * Methode  : Utilise un fichier temporaire pour la reecriture
  *-------------------------------------------------------------*/
 void edit_type(void) {
     FILE *fichier_lecture;
     FILE *fichier_ecriture;
     SlotType type;
     int numero_recherche;
     int trouve = 0;
     int fichiers_ouverts = 0;
     const char *filename_temp = "temp_types_emplacement.txt";
 
     printf("\n== MODIFICATION D'UN TYPE D'EMPLACEMENT ==\n");
     printf("Numero du type d'emplacement a modifier : ");
     scanf("%d", &numero_recherche);
 
     fichier_lecture = fopen_r(FILE_NAME);
     
     if (fichier_lecture != NULL) {
         fichier_ecriture = fopen_w(filename_temp);
         
         if (fichier_ecriture != NULL) {
             fichiers_ouverts = 1;
             
             while (read_type(fichier_lecture, &type)) {
                 if (type.numero_type == numero_recherche) {
                     trouve = 1;
 
                     printf("\nAnciennes informations :\n");
                     show_type(&type);
 
                     printf("\nNouvelles informations :\n");
                     printf("Nom du type d'emplacement (actuel : %s) : ", type.nom);
                     scanf(" %49[^\n]", type.nom);
 
                     printf("Prix par jour et par personne (actuel : %.2f) : ",
                            type.prix_jour_personne);
                     scanf("%f", &type.prix_jour_personne);
                 }
                 write_type(fichier_ecriture, &type);
             }
             
             fclose_f(fichier_ecriture);
         } else {
             printf("Erreur : impossible de creer le fichier temporaire.\n");
         }
         
         fclose_f(fichier_lecture);
     } else {
         printf("Aucun type d'emplacement enregistre.\n");
     }
 
     if (fichiers_ouverts) {
         if (!trouve) {
             printf("Type d'emplacement numero %d introuvable.\n", numero_recherche);
             remove(filename_temp);
         } else {
             remove(FILE_NAME);
             rename(filename_temp, FILE_NAME);
             printf("\nType d'emplacement modifie avec succes !\n");
         }
     }
 }
 /* Fin edit_type */
 
 /*-------------------------------------------------------------
  * Fonction : del_type
  * But      : Supprime un type d'emplacement du fichier
  * Entree   : Aucune (saisie interactive)
  * Sortie   : Aucune
  * Methode  : Utilise un fichier temporaire pour la reecriture
  *-------------------------------------------------------------*/
 void del_type(void) {
     FILE *fichier_lecture;
     FILE *fichier_ecriture;
     SlotType type;
     int numero_recherche;
     int trouve = 0;
     int fichiers_ouverts = 0;
     const char *filename_temp = "temp_types_emplacement.txt";
 
     printf("\n== SUPPRESSION D'UN TYPE D'EMPLACEMENT ==\n");
     printf("Numero du type d'emplacement a supprimer : ");
     scanf("%d", &numero_recherche);
 
     fichier_lecture = fopen_r(FILE_NAME);
     
     if (fichier_lecture != NULL) {
         fichier_ecriture = fopen_w(filename_temp);
         
         if (fichier_ecriture != NULL) {
             fichiers_ouverts = 1;
             
             while (read_type(fichier_lecture, &type)) {
                 if (type.numero_type == numero_recherche) {
                     trouve = 1;
                     printf("\nType d'emplacement numero %d supprime.\n", numero_recherche);
                 } else {
                     write_type(fichier_ecriture, &type);
                 }
             }
             
             fclose_f(fichier_ecriture);
         } else {
             printf("Erreur : impossible de creer le fichier temporaire.\n");
         }
         
         fclose_f(fichier_lecture);
     } else {
         printf("Aucun type d'emplacement enregistre.\n");
     }
 
     if (fichiers_ouverts) {
         if (!trouve) {
             printf("Type d'emplacement numero %d introuvable.\n", numero_recherche);
             remove(filename_temp);
         } else {
             remove(FILE_NAME);
             rename(filename_temp, FILE_NAME);
             printf("Suppression terminee avec succes !\n");
         }
     }
 } 
 //FIN DU FICHIER types_emplacement.c