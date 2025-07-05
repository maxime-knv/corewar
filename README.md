# Corewar Compiler

Ce projet est une implémentation en C d’un compilateur et simulateur de combat binaire inspiré du jeu Corewar. Il a été développé dans le cadre d’un projet visant à compiler, charger en mémoire, et exécuter des programmes concurrents selon des règles strictes.

## Compilation

Le projet est entièrement écrit en C. Pour compiler le projet avec l'interface visuelle (basée sur la bibliothèque ncurses), utilisez la commande suivante :

```
make ncurses
```

## Lancement

Une fois compilé, le programme se lance avec la commande suivante :

```
./corewar
```

Il est impératif de fournir exactement **4 champions** en argument. Ces fichiers doivent se trouver dans le dossier `champ`.

### Exemple

```
./corewar champ/champ1.cor champ/champ2.cor champ/champ3.cor champ/champ4.cor
```

## Structure du projet

* `src/` – Contient le code source principal du simulateur et du chargeur de programme.
* `champ/` – Contient les fichiers `.cor` des champions compilés à charger dans l’arène.
* `includes/` – Fichiers d’en-tête du projet.
* `Makefile` – Permet de compiler le projet avec ou sans interface ncurses.

## Auteur

Projet réalisé par Maxime Kournikov.

---
