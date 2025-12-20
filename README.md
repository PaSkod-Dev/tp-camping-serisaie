# Camping « La Cerisaie » - Gestion des Types d'Emplacement

Application en C pour gérer les types d'emplacement du camping. Les données sont stockées dans un fichier texte séquentiel.

## Fonctionnalités

- Ajouter, modifier, supprimer un type d'emplacement
- Consulter un type par son numéro
- Lister tous les types d'emplacement

Chaque type contient : numéro, nom, prix/jour/personne, surface, capacité max, description.

## Compilation

```bash
make
```

L'exécutable `cerisaie_types_emplacement.exe` sera créé.

Pour nettoyer : `make clean`

## Utilisation

```bash
./cerisaie_types_emplacement.exe
```

Menu interactif avec les options 1-5 pour les opérations CRUD, 0 pour quitter.

## Structure

```
src/
  include/types_emplacement.h    # Déclarations
  main.c                          # Menu principal
  types_emplacement.c             # Implémentation
```

Les données sont dans `types_emplacement.txt` au format :
```
numero nom prix surface capacite description
```

## Prérequis

- GCC (version 4.9+)
- Make

Pour Windows, voir [guide_compilation.md](guide_compilation.md).

## Auteurs

- EDOH BEDI Komi Godwin
- SEWONOU Pascal

**Dates** : 09/12/2025 - 19/12/2025

## Licence

MIT - Voir [LICENSE](LICENSE)
