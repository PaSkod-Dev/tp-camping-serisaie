# TP C – Camping « La Cerisaie »

Gestion des Types d’Emplacement**

Ce projet, développé en langage C dans le cadre du module de Génie Logiciel, implémente la gestion des **types d’emplacement** du camping *La Cerisaie*.
Il s’agit d’une application modulaire permettant la création, la mise à jour et la consultation des données, conservées dans un **fichier séquentiel texte**.

---

## **Objectif du TP**


Le travail porte spécifiquement sur :

* La **mise à jour** des informations relatives aux *types d’emplacement* (ajout, modification, recherche, affichage).
* La **gestion des données** dans un fichier texte séquentiel : `types_emplacement.txt`.
* L’utilisation d’une **architecture modulaire** en trois composantes :

  * fichier d’en-tête (`.h`),
  * fichier d’implémentation (`.c`),
  * fichier principal (`main.c`).

---

## **Structure du projet**

```text
src/
  main.c                 # Programme principal (menu principal et interactions)
  types_emplacement.c    # Implémentation des fonctions et procédures métier

include/
  types_emplacement.h    # Structure TypeEmplacement, prototypes des fonctions

types_emplacement.txt    # Fichier séquentiel contenant les données (créé/MAJ à l’exécution)

Makefile                 # Compilation automatisée du projet
```

---

## **Auteurs**

* **EDOH BEDI Komi Godwin**
* **SEWONOU Pascal** 
