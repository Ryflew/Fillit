# Projet Fillit for 42.
### Règle:
Le but est de faire le plus petit «carré» possible (qui peut contenir des trous) avec une liste donnée de tétriminos, mais la disposition doit être telle qu'elle renvoie la première solution possible en les plaçant récursivement à partir du coin supérieur gauche.

## Compilation
Faite `make`, un exécutable appelé fillit devrait compiler directement.

## Usage
`./fillit [file]`

Exemple:
```
./fillit tetris/test_8

.AABB..
AACCB..
.CC.BDD
.EE.DD.
EEFFGG.
.FFGGHH
....HH.
```
