# Camping « La Cerisaie » - Gestion des Types d'Emplacement

Application console en langage C permettant de gérer les types d'emplacement d'un camping. Les données sont persistées dans un fichier texte séquentiel.

## Fonctionnalités

L'application propose un menu interactif permettant de :

- Ajouter un nouveau type d'emplacement
- Modifier un type d'emplacement existant
- Supprimer un type d'emplacement
- Consulter un type d'emplacement par son numéro
- Lister tous les types d'emplacement enregistrés

Chaque type d'emplacement est caractérisé par un numéro unique, un nom (Tente, Caravane, Camping-car, Bungalow, etc.) et un prix journalier par personne.

## Prérequis

- Compilateur GCC (version 4.9 ou supérieure)
- GNU Make
- Terminal compatible (Git Bash, MINGW64, Linux, macOS)

Pour les utilisateurs Windows, consultez le [guide de compilation](guide_compilation.md) pour l'installation de l'environnement.

## Compilation

Compiler le projet :

```bash
make
```

L'exécutable `cerisaie_types_emplacement.exe` sera généré à la racine du projet.

Nettoyer les fichiers générés :

```bash
make clean
```

## Utilisation

Lancer l'application :

```bash
./cerisaie_types_emplacement.exe
```

Le menu principal s'affiche avec les options suivantes :

```
Menu principal :
1 - Ajouter un type d'emplacement
2 - Modifier un type d'emplacement
3 - Supprimer un type d'emplacement
4 - Consulter un type d'emplacement
5 - Lister tous les types d'emplacement
0 - Quitter
```

## Structure du projet

```
tp-camping-serisaie/
├── src/
│   ├── include/
│   │   └── types_emplacement.h     # Déclarations et structure SlotType
│   ├── main.c                      # Programme principal avec menu interactif
│   └── types_emplacement.c         # Implémentation des fonctions métier
├── Makefile                        # Script de compilation
├── README.md                       # Documentation du projet
├── guide_compilation.md            # Guide d'installation pour Windows
└── LICENSE                         # Licence du projet
```

## Format des données

Les données sont stockées dans le fichier `types_emplacement.txt` au format texte :

```
numero nom prix
```

Exemple de contenu :

```
1 Tente 11.00
2 Caravane 13.50
3 Camping-car 18.00
4 Bungalow 25.00
```

## Architecture technique

Le projet adopte une architecture modulaire organisée en trois couches :

**Structure de données** : `SlotType` composée des champs `numero_type`, `nom` et `prix_jour_personne`.

**Couche d'accès aux fichiers** : Fonctions d'ouverture, fermeture, lecture et écriture du fichier séquentiel.

**Couche métier** : Opérations CRUD (Create, Read, Update, Delete) sur les types d'emplacement.

Chaque fonction est documentée selon les conventions académiques avec une cartouche décrivant son but, ses entrées et ses sorties.

## Auteurs

- EDOH BEDI Komi Godwin
- SEWONOU Pascal

École Polytechnique de Lomé (EPL) - Licence Professionnelle Génie Logiciel

**Période de développement** : 09/12/2025 - 20/12/2025

## Licence

Ce projet est distribué sous licence MIT. Voir le fichier [LICENSE](LICENSE) pour plus de détails.