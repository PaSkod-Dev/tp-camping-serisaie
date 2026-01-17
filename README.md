<div align="center">

# Camping « La Cerisaie »
## Gestion des Types d'Emplacement

[![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)]()
[![GCC](https://img.shields.io/badge/GCC-4.9+-A42E2B?style=flat-square)]()
[![Make](https://img.shields.io/badge/Make-GNU-427819?style=flat-square)]()
[![Licence MIT](https://img.shields.io/badge/Licence-MIT-blue?style=flat-square)]()
<!--  -->
![Camping La Cerisaie](docs\modelisation\images\camping.jpeg)
<!--  -->
*Application console en langage C pour la gestion des types d'emplacement du camping Cerisaie avec persistance de données en fichier texte séquentiel.*

</div>

---

## Fonctionnalités

L'application propose un menu interactif permettant de :

-  **Ajouter** un nouveau type d'emplacement
-  **Modifier** un type d'emplacement existant
-  **Supprimer** un type d'emplacement
-  **Consulter** un type d'emplacement par son numéro
-  **Lister** tous les types d'emplacement enregistrés

**Caractéristiques d'un type d'emplacement :**
- Numéro unique (identifiant)
- Nom (Tente, Caravane, Camping-car, Bungalow, etc.)
- Prix journalier par personne

---

##  Prérequis

| Composant | Version minimale |
|:----------|:-----------------|
| **Compilateur GCC** | 4.9+ |
| **GNU Make** | - |
| **Terminal** | Git Bash, MINGW64, Linux, macOS |

>  **Windows** : Consultez le [guide de compilation](guide_compilation.md) pour l'installation de l'environnement.

---

##  Compilation

**Compiler le projet :**
```bash
make
```
L'exécutable `cerisaie_types_emplacement.exe` sera généré à la racine du projet.

**Nettoyer les fichiers générés :**
```bash
make clean
```

---

##  Utilisation

**Lancer l'application :**
```bash
./cerisaie_types_emplacement.exe
```

**Menu principal affiché :**
```
Menu principal :
1 - Ajouter un type d'emplacement
2 - Modifier un type d'emplacement
3 - Supprimer un type d'emplacement
4 - Consulter un type d'emplacement
5 - Lister tous les types d'emplacement
0 - Quitter
```

---

## 📁 Structure du projet

```
tp-camping-serisaie/
│
├── 📁 build/                           # Fichiers de compilation
│   ├── bin/                            # Exécutables
│   └── obj/                            # Fichiers objets (.o)
│
├── 📁 data/                            # Données
│   ├── samples/                        # Données d'exemple
│   │   └── types_emplacement.txt
│   └── exports/                        # Fichiers générés
│       └── factures/                   # Factures PDF/TXT
│
├── 📁 docs/                            # Documentation
│   ├── modelisation/                   # Modélisation BDD
│   │   ├── images/                     # Schémas MCD/MLD
│   │   │   ├── camping.jpeg
│   │   │   ├── mcd.png
│   │   │   └── mld.png
│   │   └── modelisation.md
│   │
│   ├── specifications/                 # Spécifications
│   │   ├── pdf/
│   │   │   ├── Analyse gestion location Cerisaie.pdf
│   │   │   └── modelisation-camping-cerisaie_Vfinal.pdf
│   │   └── modelisation.md
│   │
│   └── guides/                         # Guides techniques
│       └── guide_compilation.md
│
├── 📁 src/                             # Code source
│   │
│   ├── entities/                       # Entités du domaine
│   │   ├── client/
│   │   │   ├── client.h
│   │   │   └── client.c
│   │   ├── sejour/
│   │   │   ├── sejour.h
│   │   │   └── sejour.c
│   │   ├── emplacement/
│   │   │   ├── emplacement.h
│   │   │   ├── emplacement.c
│   │   │   ├── types_emplacement.h
│   │   │   └── types_emplacement.c
│   │   ├── sport/
│   │   │   ├── sport.h
│   │   │   └── sport.c
│   │   └── location_sport/
│   │       ├── location_sport.h
│   │       └── location_sport.c
│   │
│   ├── services/                       # Logique métier
│   │   ├── facturation/
│   │   │   ├── facturation.h
│   │   │   └── facturation.c
│   │   ├── gestion_sejour/
│   │   │   ├── gestion_sejour.h
│   │   │   └── gestion_sejour.c
│   │   └── gestion_location/
│   │       ├── gestion_location.h
│   │       └── gestion_location.c
│   │
│   ├── utils/                          # Utilitaires
│   │   ├── validation.h
│   │   └── validation.c
│   │
│   ├── ui/                             # Interface utilisateur
│   │   ├── menu.h
│   │   ├── menu.c
│   │   ├── affichage.h
│   │   ├── affichage.c
│   │   ├── saisie.h
│   │   └── saisie.c
│   │
│   └── main.c                          # Point d'entrée
│
├── 📁 tests/                           # Tests unitaires
│   ├── test_client.c
│   ├── test_sejour.c
│   ├── test_facturation.c
│   └── test_location_sport.c
│
├── .gitignore                          # Exclusions Git
├── LICENSE                             # Licence MIT
├── Makefile                            # Script de compilation
├── README.md                           # Ce fichier
```

---

##  Format des données

Les données sont stockées dans `cerisaie_types_emplacement.txt` au format :

```
numero nom prix
```

**Exemple de contenu :**
```
1 Tente 11.00
2 Caravane 13.50
3 Camping-car 18.00
4 Bungalow 25.00
```

---

##  Architecture technique

Le projet adopte une architecture modulaire en **trois couches** :

<div align="center">

| Couche | Responsabilité |
|:-------|:---------------|
| **Structure de données** | `SlotType` (numero_type, nom, prix_jour_personne) |
| **Accès aux fichiers** | Ouverture, fermeture, lecture, écriture séquentielle |
| **Couche métier** | Opérations CRUD (Create, Read, Update, Delete) |

</div>

Chaque fonction est documentée selon les conventions académiques avec une cartouche décrivant son but, ses entrées et ses sorties.

 Consultez l'[énoncé du projet](cerisaie_enonce.pdf) pour les spécifications détaillées.

---

## 👨‍💻 Auteurs

**EDOH BEDI Komi Godwin** • **SEWONOU Pascal**

*École Polytechnique de Lomé (EPL) - Licence Professionnelle Génie Logiciel*

**Période de développement** : 09/12/2025 - 20/12/2025

---

##  Licence

Ce projet est distribué sous **licence MIT**. Voir le fichier [LICENSE](LICENSE) pour plus de détails.

---

<div align="center">

*Développé avec **passion** et **détérmination** dans le cadre de notre formation en Génie Logiciel à l'EPL*

</div>
