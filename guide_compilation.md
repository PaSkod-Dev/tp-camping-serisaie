# Guide de Compilation C sur Windows

##  Installation de GCC et Make

### Option 1 : MinGW (Recommandé)

1. **Télécharger MinGW-w64**
   - Aller sur [winlibs.com](https://winlibs.com/)
   - Télécharger la version **UCRT runtime** (Win64 - GCC)
   - Extraire dans `C:\mingw64`

2. **Ajouter au PATH**
   - Ouvrir les paramètres système → Variables d'environnement
   - Dans "Path", ajouter : `C:\mingw64\bin`
   - Redémarrer le terminal

3. **Vérifier l'installation**
   ```bash
   gcc --version
   make --version
   ```

### Option 2 : MSYS2 (Alternative)

1. Installer [MSYS2](https://www.msys2.org/)
2. Dans le terminal MSYS2 :
   ```bash
   pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-make
   ```

---

##  Structure du Projet

```
tp-camping-serisaie/
├── src/
│   ├── include/
│   │   └── types_emplacement.h
│   ├── main.c
│   └── types_emplacement.c
├── Makefile
└── README.md
```

---

## ⚙️ Configuration du Makefile

Créer un fichier `Makefile` à la racine :

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -Isrc/include
SRC = src/main.c src/types_emplacement.c
OBJ = $(SRC:.c=.o)
TARGET = camping

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	del /Q src\*.o $(TARGET).exe 2>nul || exit 0

.PHONY: all clean
```

---

##  Compilation et Exécution

### Étape 1 : Ouvrir le terminal
- **Git Bash** (recommandé) ou **PowerShell**
- Se placer dans le dossier du projet :
  ```bash
  cd tp-camping-serisaie
  ```

### Étape 2 : Compiler
```bash
make
```

### Étape 3 : Exécuter
```bash
./camping.exe
```

### Étape 4 : Nettoyer (optionnel)
```bash
make clean
```

---

##  Dépannage

### Erreur : "make: command not found"
- GCC/Make pas installé ou pas dans le PATH
- Solution : Vérifier l'installation et le PATH

### Erreur : "undefined reference"
- Fichier `.c` manquant dans le Makefile
- Solution : Ajouter tous les `.c` dans `SRC`

### Erreur : "permission denied"
- Fichier en cours d'utilisation
- Solution : Fermer l'exécutable et relancer

### Warnings avec `-Werror`
- Les warnings deviennent des erreurs
- Solution : Corriger le code ou retirer `-Werror`

---

##  Compilation Manuelle (sans Makefile)

Si le Makefile ne fonctionne pas :

```bash
gcc -Wall -Wextra -std=c99 -Isrc/include -o camping.exe src/main.c src/types_emplacement.c
```

Puis exécuter :
```bash
./camping.exe
```

---

##  Checklist Rapide

- [ ] GCC et Make installés
- [ ] PATH configuré
- [ ] Terminal redémarré
- [ ] `gcc --version` fonctionne
- [ ] `make --version` fonctionne
- [ ] Makefile créé
- [ ] `make` compile sans erreur
- [ ] `./camping.exe` s'exécute

---

## Commandes Essentielles

| Commande | Description |
|----------|-------------|
| `make` | Compile le projet |
| `make clean` | Supprime les fichiers compilés |
| `./camping.exe` | Exécute le programme |
| `gcc --version` | Vérifie l'installation de GCC |

Bon développement ! 