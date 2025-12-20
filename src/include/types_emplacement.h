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
 
 #define FILE_NAME "types_emplacement.txt"
 #define NAME_LEN 50
 
 //STRUCTURES
 
 /*------------------------------------------------------------------------
  * Structure : SlotType
  * But       : Represente un type d'emplacement dans le camping
  * Champs    : numero_type       - Numero unique du type
  *             nom               - Nom du type (Tente, Caravane, etc.)
  *             prix_jour_personne - Prix par jour et par personne en euros
  *-------------------------------------------------------------------------*/
 typedef struct {
     int numero_type;
     char nom[NAME_LEN];
     float prix_jour_personne;
 } SlotType;
 
 //PROTOTYPES DES FONCTIONS DE GESTION DE FICHIER
 
 FILE *fopen_r(const char *fiename);
 FILE *fopen_a(const char *filename);
 FILE *fopen_w(const char *filename);
 void fclose_f(FILE *fichier);
 
 //PROTOTYPES DES FONCTIONS DE LECTURE / ECRITURE
 
 int read_type(FILE *fichier, SlotType *type);
 int write_type(FILE *fichier, const SlotType *type);
 
 //PROTOTYPES DES FONCTIONS METIER
 
 int  next_id(void);
 void add_type(void);
 void get_type(void);
 void list_types(void);
 void edit_type(void);
 void del_type(void);
 
 #endif /* TYPES_EMPLACEMENT_H */
 
 //FIN DU FICHIER types_emplacement.h