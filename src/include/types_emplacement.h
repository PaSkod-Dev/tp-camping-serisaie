#ifndef TYPES_EMPLACEMENT_H
#define TYPES_EMPLACEMENT_H

#include <stdio.h>

#define NOM_FICHIER "types_emplacement.txt"
#define TAILLE_NOM 50
#define TAILLE_DESCRIPTION 200

/* Structure pour représenter un type d'emplacement */
typedef struct {
    int numero_type;                    /* Numéro unique du type */
    char nom[TAILLE_NOM];               /* Nom du type (ex: "Tente", "Caravane") */
    float prix_jour_personne;           /* Prix par jour et par personne en euros */
    float surface_moyenne;              /* Surface moyenne en m² */
    int capacite_max_personnes;         /* Nombre maximum de personnes */
    char description[TAILLE_DESCRIPTION]; /* Description de l'emplacement */
} TypeEmplacement;

/* Fonctions de gestion de fichier */
FILE *ouvrir_fichier_lecture(const char *nom_fichier);
FILE *ouvrir_fichier_ajout(const char *nom_fichier);
FILE *ouvrir_fichier_ecriture(const char *nom_fichier);
void fermer_fichier(FILE *fichier);

int lire_type_emplacement(FILE *fichier, TypeEmplacement *type);
int ecrire_type_emplacement(FILE *fichier, const TypeEmplacement *type);

/* Fonctions métier sur les types d'emplacement */
int  trouver_prochain_numero(void);
void ajouter_type_emplacement(void);
void consulter_type_emplacement(void);
void lister_types_emplacement(void);
void modifier_type_emplacement(void);
void supprimer_type_emplacement(void);

#endif /* TYPES_EMPLACEMENT_H */