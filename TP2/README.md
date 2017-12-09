# TP2 : Mémoire

## Exercice 1

> Insérer ici image

## Exercice 2

Fragmentation de la mémoire : pas assez de place disponible pour P6

## Exercice 3

Oui, car la pagination permet de segmenter la mémoire en distribuant les processus dans les espaces disponibles

## Exercice 4

L'OS s'occupe des traductions

## Exercice 5

1 page : 16 adresses

1 frame : 16 adresses

## Exercice 6

Faute de page caqr cette adresse n'était pas déclarée dans la table des pages

## Exercice 7

52 (qui est assigné) et 58 sont dans la même page

## Exercice 8

1 table de pages par processus, et le P2 n'avait pas de page assignée

## Exercice 9

Page replacement

## Question 10

4 adresses (pour le niveau 1) - Niveau 2 : 4 adresses

## Question 11

128/16 = 8 fautes de page

## Question 12

8 fautes de page à chaque changement de contexte

-> 8 fautes de page toutes les 10ms

## Question 13

|Adresse|Page|Offset|
|-------|----|------|
950|0|950
1851|0|1851
25354|3|1354
11842|1|3842

## Question 14

Nombre de frames : 8192

Nombre de pages : 262 144

### Adresse physique

Cadre 8192 = 2^13 = 13 bits nécessaires
Taille 128 = 2^7 = 7 bits nécessaires

|`xxxx xxxx xxxx x`|`xxx xxxx`|
|:----------------:|:--------:|
Cadre|Offset

### Adresse logique

Pages : 262 144 = 2^18 = 18 bits nécessaires
        Taille 128 = 2^7 = 7 bits nécessaires

|`xx xxxx xxxx xxxx x`|`xxx xxxx`|
|:-------------------:|:--------:|
Cadre|Offset

### Autre chose

10 237 = page 79 offset 125

Adresse physique :

|`1837`|`125`|
|:-------------------:|:--------:|
`1110 0101 111`|`111 1101`

## Question 15

64 pages, taille de la table des pages

64x32 = 2048 bits

64 entrées : 2^6 donc 

> A compléter en fait

## Question 17

2 accès mémoire économisés car accès niveau 1 + niveau 2 + accès mémoire = 3 au total

## Question 18

3 TLB :

- 1 ITLB (instruction)
- 2 DTLB (données)

## Question 19

4Gb de RAM

## Question 20

Il alloue `root` parce qu'on ne met rien dedans

## Question 21

Pas d'erreur car il décharge au fur et à mesure

## Question 22

4096

## Question 23

700 000 = 3Gb

## Exercice 24

__FIFO__

|Access sequence|0|2|4|6|8|6|4|2|0|1|3|2|4|7|6|3|2|0|
|---------------|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Pages in RAM|0|2|4|6|8|8|8|8|8|1|3|2|4|7|6|6|6|0|
| | |0|2|4|6|6|6|6|6|8|1|3|3|4|7|7|7|6|
| | | |0|2|4|4|4|4|4|6|8|1|2|3|4|4|4|7|
| | | | |0|2|2|2|2|2|4|6|8|1|2|3|3|3|4|
| | | | | |0|0|0|0|0|2|4|6|8|1|2|2|2|3|
||
|Page evicted| | | | | | | | | |0|2|4|6|8|1| | |2|
|Frame chosen (example)|0|1|2|3|4|3|2|1|0|0|1|2|3|4|0|1|2|2|

## Exercice 25

__LRU__

|Access sequence|0|2|4|6|8|6|4|2|0|1|3|2|4|7|6|3|2|0|
|---------------|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
|Pages in RAM|0|2|4|6|8|6|4|2|0|1|3|2|4|7|6|3|2|0|
| | |0|2|4|6|8|6|4|2|0|1|3|2|4|7|6|3|2|
| | | |0|2|4|4|8|6|4|2|0|1|3|2|4|7|6|3|
| | | | |0|2|2|2|8|6|4|2|0|1|3|2|4|7|6|
| | | | | |0|0|0|0|8|6|4|4|0|1|3|2|4|7|
||
|Page evicted| | | | | | | | | |8|6| | |0|1| | |4|
|Frame chosen (example)|0|1|2|3|4|3|2|1|0|4|3|1|2|0|4|3|1|2|
