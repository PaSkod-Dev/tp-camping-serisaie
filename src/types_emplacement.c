/*
 * Gestion des Types d'Emplacement - Camping "La Cerisaie"
 *
 * Implémentation des fonctions de gestion des types d'emplacement
 * en utilisant un fichier séquentiel texte.
 */

#include "types_emplacement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* FONCTIONS DE GESTION DES FICHIERS                                          */

FILE *ouvrir_fichier_lecture(const char *nom_fichier) {
  FILE *fichier = fopen(nom_fichier, "r");
  if (fichier == NULL) {
    printf("Le fichier %s n'existe pas encore.\n", nom_fichier);
  }
  return fichier;
}

FILE *ouvrir_fichier_ajout(const char *nom_fichier) {
  FILE *fichier = fopen(nom_fichier, "a");
  if (fichier == NULL) {
    printf("Erreur : impossible d'ouvrir le fichier %s en mode ajout.\n",
           nom_fichier);
  }
  return fichier;
}

FILE *ouvrir_fichier_ecriture(const char *nom_fichier) {
  FILE *fichier = fopen(nom_fichier, "w");
  if (fichier == NULL) {
    printf("Erreur : impossible d'ouvrir le fichier %s en mode ecriture.\n",
           nom_fichier);
  }
  return fichier;
}

void fermer_fichier(FILE *fichier) {
  if (fichier != NULL) {
    fclose(fichier);
    /* printf("Fichier ferme avec succes.\n");  // optionnel */
  }
}

/* LECTURE / ECRITURE DANS LE FICHIER                                         */

int lire_type_emplacement(FILE *fichier, TypeEmplacement *type) {
  /* Format : numero nom prix surface capacite description\n */
  int resultat =
      fscanf(fichier, "%d %49s %f %f %d %199[^\n]\n", &type->numero_type,
             type->nom, &type->prix_jour_personne, &type->surface_moyenne,
             &type->capacite_max_personnes, type->description);
  return (resultat == 6);
}

int ecrire_type_emplacement(FILE *fichier, const TypeEmplacement *type) {
  int resultat =
      fprintf(fichier, "%d %s %.2f %.2f %d %s\n", type->numero_type, type->nom,
              type->prix_jour_personne, type->surface_moyenne,
              type->capacite_max_personnes, type->description);
  return (resultat > 0);
}

/* FONCTIONS METIER SUR LES TYPES D'EMPLACEMENT                               */

int trouver_prochain_numero(void) {
  FILE *fichier;
  TypeEmplacement type;
  int numero_max = 0;

  fichier = ouvrir_fichier_lecture(NOM_FICHIER);
  if (fichier == NULL) {
    return 1; /* Premier numéro */
  }

  while (lire_type_emplacement(fichier, &type)) {
    if (type.numero_type > numero_max) {
      numero_max = type.numero_type;
    }
  }

  fermer_fichier(fichier);
  return numero_max + 1;
}

static void afficher_type_emplacement(const TypeEmplacement *type) {
  printf("\n--- Type d'emplacement numero %d ---\n", type->numero_type);
  printf("Nom : %s\n", type->nom);
  printf("Prix par jour et par personne : %.2f euros\n",
         type->prix_jour_personne);
  printf("Surface moyenne : %.2f m²\n", type->surface_moyenne);
  printf("Capacite maximale : %d personnes\n", type->capacite_max_personnes);
  printf("Description : %s\n", type->description);
  printf("------------------------------------\n");
}

void ajouter_type_emplacement(void) {
  FILE *fichier;
  TypeEmplacement nouveau_type;

  printf("\n=== AJOUT D'UN TYPE D'EMPLACEMENT ===\n");

  nouveau_type.numero_type = trouver_prochain_numero();
  printf("Numero de type : %d\n", nouveau_type.numero_type);

  printf("Nom du type d'emplacement : ");
  scanf(" %49[^\n]", nouveau_type.nom);

  printf("Prix par jour et par personne (en euros) : ");
  scanf("%f", &nouveau_type.prix_jour_personne);

  printf("Surface moyenne (en m²) : ");
  scanf("%f", &nouveau_type.surface_moyenne);

  printf("Capacite maximale (nombre de personnes) : ");
  scanf("%d", &nouveau_type.capacite_max_personnes);

  printf("Description : ");
  scanf(" %199[^\n]", nouveau_type.description);

  fichier = ouvrir_fichier_ajout(NOM_FICHIER);
  if (fichier == NULL) {
    printf("Erreur : impossible d'ajouter le type d'emplacement.\n");
    return;
  }

  if (ecrire_type_emplacement(fichier, &nouveau_type)) {
    printf("\nType d'emplacement ajoute avec succes !\n");
  } else {
    printf("\nErreur lors de l'ecriture dans le fichier.\n");
  }

  fermer_fichier(fichier);
}

void consulter_type_emplacement(void) {
  FILE *fichier;
  TypeEmplacement type;
  int numero_recherche;
  int trouve = 0;

  printf("\n=== CONSULTATION D'UN TYPE D'EMPLACEMENT ===\n");
  printf("Numero du type d'emplacement a consulter : ");
  scanf("%d", &numero_recherche);

  fichier = ouvrir_fichier_lecture(NOM_FICHIER);
  if (fichier == NULL) {
    printf("Aucun type d'emplacement enregistre.\n");
    return;
  }

  while (lire_type_emplacement(fichier, &type)) {
    if (type.numero_type == numero_recherche) {
      afficher_type_emplacement(&type);
      trouve = 1;
      break;
    }
  }

  if (!trouve) {
    printf("Type d'emplacement numero %d introuvable.\n", numero_recherche);
  }

  fermer_fichier(fichier);
}

void lister_types_emplacement(void) {
  FILE *fichier;
  TypeEmplacement type;
  int nombre_types = 0;

  printf("\n=== LISTE DES TYPES D'EMPLACEMENT ===\n\n");

  fichier = ouvrir_fichier_lecture(NOM_FICHIER);
  if (fichier == NULL) {
    printf("Aucun type d'emplacement enregistre.\n");
    return;
  }

  while (lire_type_emplacement(fichier, &type)) {
    afficher_type_emplacement(&type);
    nombre_types++;
  }

  printf("\nTotal : %d type(s) d'emplacement.\n", nombre_types);

  fermer_fichier(fichier);
}

void modifier_type_emplacement(void) {
  FILE *fichier_lecture;
  FILE *fichier_ecriture;
  TypeEmplacement type;
  int numero_recherche;
  int trouve = 0;
  const char *nom_fichier_temp = "temp_types_emplacement.txt";

  printf("\n=== MODIFICATION D'UN TYPE D'EMPLACEMENT ===\n");
  printf("Numero du type d'emplacement a modifier : ");
  scanf("%d", &numero_recherche);

  fichier_lecture = ouvrir_fichier_lecture(NOM_FICHIER);
  if (fichier_lecture == NULL) {
    printf("Aucun type d'emplacement enregistre.\n");
    return;
  }

  fichier_ecriture = ouvrir_fichier_ecriture(nom_fichier_temp);
  if (fichier_ecriture == NULL) {
    printf("Erreur : impossible de creer le fichier temporaire.\n");
    fermer_fichier(fichier_lecture);
    return;
  }

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

      printf("Surface moyenne (actuelle : %.2f) : ", type.surface_moyenne);
      scanf("%f", &type.surface_moyenne);

      printf("Capacite maximale (actuelle : %d) : ",
             type.capacite_max_personnes);
      scanf("%d", &type.capacite_max_personnes);

      printf("Description (actuelle : %s) : ", type.description);
      scanf(" %199[^\n]", type.description);
    }

    ecrire_type_emplacement(fichier_ecriture, &type);
  }

  fermer_fichier(fichier_lecture);
  fermer_fichier(fichier_ecriture);

  if (!trouve) {
    printf("Type d'emplacement numero %d introuvable.\n", numero_recherche);
    remove(nom_fichier_temp);
  } else {
    remove(NOM_FICHIER);
    rename(nom_fichier_temp, NOM_FICHIER);
    printf("\nType d'emplacement modifie avec succes !\n");
  }
}

void supprimer_type_emplacement(void) {
  FILE *fichier_lecture;
  FILE *fichier_ecriture;
  TypeEmplacement type;
  int numero_recherche;
  int trouve = 0;
  const char *nom_fichier_temp = "temp_types_emplacement.txt";

  printf("\n=== SUPPRESSION D'UN TYPE D'EMPLACEMENT ===\n");
  printf("Numero du type d'emplacement a supprimer : ");
  scanf("%d", &numero_recherche);

  fichier_lecture = ouvrir_fichier_lecture(NOM_FICHIER);
  if (fichier_lecture == NULL) {
    printf("Aucun type d'emplacement enregistre.\n");
    return;
  }

  fichier_ecriture = ouvrir_fichier_ecriture(nom_fichier_temp);
  if (fichier_ecriture == NULL) {
    printf("Erreur : impossible de creer le fichier temporaire.\n");
    fermer_fichier(fichier_lecture);
    return;
  }

  while (lire_type_emplacement(fichier_lecture, &type)) {
    if (type.numero_type == numero_recherche) {
      trouve = 1;
      printf("\nType d'emplacement numero %d supprime.\n", numero_recherche);
    } else {
      ecrire_type_emplacement(fichier_ecriture, &type);
    }
  }

  fermer_fichier(fichier_lecture);
  fermer_fichier(fichier_ecriture);

  if (!trouve) {
    printf("Type d'emplacement numero %d introuvable.\n", numero_recherche);
    remove(nom_fichier_temp);
  } else {
    remove(NOM_FICHIER);
    rename(nom_fichier_temp, NOM_FICHIER);
    printf("Suppression terminee avec succes !\n");
  }
}