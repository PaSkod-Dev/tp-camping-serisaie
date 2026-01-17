<div align="center">

# Camping « La Cerisaie »
## Gestion des Types d'Emplacement

[![C](https://img.shields.io/badge/C-00599C?style=flat-square&logo=c&logoColor=white)]()
[![GCC](https://img.shields.io/badge/GCC-4.9+-A42E2B?style=flat-square)]()
[![Make](https://img.shields.io/badge/Make-GNU-427819?style=flat-square)]()
[![Licence MIT](https://img.shields.io/badge/Licence-MIT-blue?style=flat-square)]()
<!--  -->
![Camping La Cerisaie](Modélisation/image/camping.jpeg)

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
├── src/
│   ├── include/
│   │   └── cerisaie_types_emplacement.h     # Déclarations et structure SlotType
│   ├── main.c                                # Programme principal avec menu
│   └── cerisaie_types_emplacement.c          # Implémentation CRUD
│
├── Makefile                                  # Script de compilation
├── README.md                                 # Documentation du projet
├── guide_compilation.md                      # Guide installation Windows
└── LICENSE                                   # Licence du projet
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