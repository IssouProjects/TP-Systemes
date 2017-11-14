# TP1 : Privilèges

## Question 2

### Section `text`
||Adresse|
|----|-----|
Début|`8000`
Fin|`917c`

### Section `bss`
||Adresse|
|----|-----|
Début|`91ac`
Fin|`960c`


### Fonctions du `kmain`

|Fonction|Début|Fin|
|--------|-----|---|
`compute_volume`|`9128`|`9178`
`dummy`|`90c4`|`90c8`
`div`|`90cc`|`9124`
`kmain`|`917c`|`91a8`

## Question 3
Registres utilisés par `div()` :
```
r0, r1, r2, r3, sp
```

Variable `result` dans `r3`.

C'est le compilateur qui a choisi ces registres.

## Question 4
Adresse de `rad` : `#9600` avec `sp 95fc`
Le stack pointer descend
`sp` pointe la 1ère adresse libre

## Question 5
`sp` initial : `0x960c`

`sp` : `0x95e4`

``` bash
0x960c  0
0x9608  8098    # Adresse d'où on est partis dans la main
0x9600  5       # Variable locale
0x95f8  9168    # Adresse d'où on est partis dans la fonction
0x95f0  7d      # Variable locale
0x95e8  5       # Variable locale
0x95e0  20b     # Variable locale
```

## Question 6

### `dummy`

|when|`lr` address|description|
|----|------------|-----------|
before call|`0x8098`|address of after `main`
after call|`0x9190`|address of instruction after `dummy` call

### `compute_volume`

|when|`lr` address|description|
|----|------------|-----------|
before call|`0x8098`|address of after `main`
after call|`0x9198`|address of instruction after `compute_volume` call

### `div`

|when|`lr` address|description|
|----|------------|-----------|
before call|`0x9198`|address of after `compute_volume` call
after call|`0x9164`|address of instruction after `div` call

**L'instruction `bl` update `lr` automatiquement**

-----

## Question 7

Utiliser `bl`

-----

## Question 9

`SYSTEM mode`

## Question 10

before|after
------|-----
`0x400001df`|`0x40001d3`
SYSTEM|SVC

## Question 11

||before|after|
|---|------|-----|
`lr` address|`0x400001df`|`0x40001d3`
desc|infinite loop after `kmain`|reset

## Question 12

On ne peut pas repasser en SVC car l'utilisateur n'a pas les droits
