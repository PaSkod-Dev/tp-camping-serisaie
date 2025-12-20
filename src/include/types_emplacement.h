/*
    NAME : types_emplacement.h
    PURPOSE : Declaration de la structure et des fonctions de gestion
              des types d'emplacement du camping "La Cerisaie"
    AUTHORS : SEWONOU Pascal & EDOH BEDI Komi Godwin
    CREATED : 09/12/2025
    UPDATED : 20/12/2025
 */

 #ifndef TYPES_EMPLACEMENT_H
 #define TYPES_EMPLACEMENT_H
 
 #include <stdio.h>
 
 //CONSTANTES
 
 #define NOM_FICHIER "types_emplacement.txt"
 #define TAILLE_NOM 50
 
 //STRUCTURES
 
 /*------------------------------------------------------------------------
  * Structure : TypeEmplacement
  * But       : Represente un type d'emplacement dans le camping
  * Champs    : numero_type       - Numero unique du type
  *             nom               - Nom du type (Tente, Caravane, etc.)
  *             prix_jour_personne - Prix par jour et par personne en euros
  *-------------------------------------------------------------------------*/
 typedef struct {
     int numero_type;
     char nom[TAILLE_NOM];
     float prix_jour_personne;
 } TypeEmplacement;
 
 //PROTOTYPES DES FONCTIONS DE GESTION DE FICHIER
 
 FILE *ouvrir_fichier_lecture(const char *nom_fichier);
 FILE *ouvrir_fichier_ajout(const char *nom_fichier);
 FILE *ouvrir_fichier_ecriture(const char *nom_fichier);
 void fermer_fichier(FILE *fichier);
 
 //PROTOTYPES DES FONCTIONS DE LECTURE / ECRITURE
 
 int lire_type_emplacement(FILE *fichier, TypeEmplacement *type);
 int ecrire_type_emplacement(FILE *fichier, const TypeEmplacement *type);
 
 //PROTOTYPES DES FONCTIONS METIER
 
 int  trouver_prochain_numero(void);
 void ajouter_type_emplacement(void);
 void consulter_type_emplacement(void);
 void lister_types_emplacement(void);
 void modifier_type_emplacement(void);
 void supprimer_type_emplacement(void);
 
 #endif /* TYPES_EMPLACEMENT_H */
 
 //FIN DU FICHIER types_emplacement.h