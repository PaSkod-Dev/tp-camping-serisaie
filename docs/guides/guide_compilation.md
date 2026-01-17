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

## Choix du terminal

### Git Bash (recommandé)

Git Bash est le terminal le plus compatible avec les Makefiles Unix. Il fonctionne parfaitement avec toutes les commandes.

**Utilisation :**
- Ouvrir Git Bash dans VS Code : Terminal → Nouveau terminal → Sélectionner "Git Bash"
- Ou ouvrir Git Bash directement depuis le dossier du projet

### PowerShell

Le Makefile est compatible avec PowerShell. Si vous rencontrez quand même des erreurs :

**Solution 1 :** Utiliser Git Bash (recommandé pour éviter tout problème)

**Solution 2 :** Compiler manuellement :
```powershell
gcc -Wall -Wextra -Werror -std=c99 -Isrc/include -o cerisaie_types_emplacement.exe src/main.c src/types_emplacement.c
```

**Solution 3 :** Pour nettoyer manuellement dans PowerShell (si `make clean` échoue) :
```powershell
Remove-Item cerisaie_types_emplacement.exe -ErrorAction SilentlyContinue
```

### VS Code Terminal intégré

VS Code peut utiliser différents terminaux :
- **Git Bash** : Fonctionne parfaitement, utilisez-le si disponible
- **PowerShell** : Peut avoir des problèmes, préférez Git Bash
- **CMD** : Moins recommandé, utilisez Git Bash

**Changer le terminal dans VS Code :**
1. Ouvrir le terminal (Ctrl + `)
2. Cliquer sur la flèche à côté du "+"
3. Sélectionner "Git Bash" ou "Sélectionner le profil du terminal par défaut"

## Compilation

### Avec Git Bash (recommandé)

**Git Bash est fortement recommandé pour utiliser `make`.** Il fonctionne parfaitement avec toutes les commandes.

```bash
cd tp-camping-serisaie
make
./cerisaie_types_emplacement.exe
```

Nettoyer : `make clean`

**Après compilation, vous verrez :**
- Les fichiers objets : `src/main.o` et `src/types_emplacement.o`
- L'exécutable : `cerisaie_types_emplacement.exe`

### Avec PowerShell

**Important :** `make` peut avoir des problèmes dans PowerShell. Si vous obtenez des erreurs, utilisez Git Bash ou compilez manuellement.

**Compilation manuelle dans PowerShell :**
```powershell
# Compiler les fichiers objets
gcc -Wall -Wextra -Werror -std=c99 -Isrc/include -c src/main.c -o src/main.o
gcc -Wall -Wextra -Werror -std=c99 -Isrc/include -c src/types_emplacement.c -o src/types_emplacement.o

# Lier les objets en exécutable
gcc -Wall -Wextra -Werror -std=c99 -Isrc/include -o cerisaie_types_emplacement.exe src/main.o src/types_emplacement.o
```

**Nettoyer manuellement :**
```powershell
Remove-Item cerisaie_types_emplacement.exe, src\*.o -ErrorAction SilentlyContinue
```

## Compilation manuelle

Si le Makefile ne fonctionne pas, compilez manuellement :

**Git Bash / PowerShell :**
```bash
gcc -Wall -Wextra -Werror -std=c99 -Isrc/include -o cerisaie_types_emplacement.exe src/main.c src/types_emplacement.c
```

**Exécution :**
```bash
./cerisaie_types_emplacement.exe
```

## Dépannage

- **"make: command not found"** → GCC/Make pas installé ou pas dans le PATH
- **Erreurs avec `make` dans PowerShell** → **Utilisez Git Bash** (recommandé) ou compilez manuellement (voir section PowerShell ci-dessus)
- **"rm: command not found" (PowerShell)** → Utilisez Git Bash ou compilez manuellement
- **"undefined reference"** → Fichier `.c` manquant dans le Makefile
- **"permission denied"** → Fermer l'exécutable et relancer
- **Warnings avec `-Werror`** → Corriger le code ou retirer `-Werror` du Makefile
- **Pas de fichiers objets (.o) après compilation** → Normal si compilation directe, utilisez le Makefile modifié pour voir les fichiers objets
- **Erreurs avec `make clean` (PowerShell)** → Utilisez Git Bash ou supprimez manuellement les fichiers

## Résumé : Quel terminal utiliser ?

| Terminal | `make` | Compilation manuelle | Recommandation |
|----------|--------|---------------------|----------------|
| **Git Bash** | 🟢 Fonctionne | 🟢 Fonctionne | ⭐ **Recommandé** |
| **PowerShell** | ⚠️ Peut échouer | 🟢 Fonctionne | Utiliser Git Bash ou compiler manuellement |
| **VS Code (Git Bash)** | 🟢 Fonctionne | 🟢 Fonctionne | ⭐ **Recommandé** |
| **VS Code (PowerShell)** | ⚠️ Peut échouer | 🟢 Fonctionne | Changer pour Git Bash |