# Guide de Compilation

## Installation (Windows)

### Option 1 : MinGW (recommandé)

1. Télécharger MinGW-w64 sur [winlibs.com](https://winlibs.com/) - version UCRT runtime
2. Extraire dans `C:\mingw64`
3. Ajouter `C:\mingw64\bin` au PATH (Variables d'environnement)
4. Redémarrer le terminal
5. Vérifier : `gcc --version` et `make --version`

### Option 2 : MSYS2

1. Installer [MSYS2](https://www.msys2.org/)
2. Dans le terminal MSYS2 : `pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make`

## Compilation

```bash
cd tp-camping-serisaie
make
./cerisaie_types_emplacement.exe
```

Nettoyer : `make clean`

## Compilation manuelle

Si le Makefile ne fonctionne pas :

```bash
gcc -Wall -Wextra -std=c99 -Isrc/include -o cerisaie_types_emplacement.exe src/main.c src/types_emplacement.c
```

## Dépannage

- **"make: command not found"** → GCC/Make pas installé ou pas dans le PATH
- **"undefined reference"** → Fichier `.c` manquant dans le Makefile
- **"permission denied"** → Fermer l'exécutable et relancer
- **Warnings avec `-Werror`** → Corriger le code ou retirer `-Werror` du Makefile
