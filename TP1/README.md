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

# Partie 2

L'objectif des questions suivantes est d'appeler une fonction system après une interruption software.

## Question 1

```C
void sys_reboot(){
int sys_call = 1;
  // Met la valeur sys_call dans r0
	__asm("mov r0, %0" : "=r"(sys_call): :"r0");
  // Lance une interruption software pour rentrer en 'privileged mode'
	__asm("SWI #0");
 }
 ```
## Question 2

Implémentation de la fonction `sys_handler` qui ne fait rien du tout dans `sys_call.c`
Cette fonction n'est jamais invoqué car elle n'est jamais appelée.
Pour l'appeler il faut modifier `init.s`

Remplacer:
```C
swi_asm_handler:
	b swi_asm_handler
```
Par:
```C
swi_asm_handler:
	b swi_handler
```

De cette façon les interruptions SWI sont délégués à notre fonction.

## Question 3

Dans la fonction `swi_handler` de `sys_call.c`
On récupère la valeur qu'on avait stocké précédement dans le registre r0 à l'aide de:
```C
__asm("mov %0, r0" : "=r"(param));
```
A l'aide d'un switch autour de param, on appele la fonction voulue.
Si le param n'est pas géré, on appele une méthode `PANIC()` qui panique.

Pour le param 1, on appele `do_sys_reboot()`
```C
void do_sys_reboot(){
  //Jump à l'adresse 0x8000
	__asm("b 0x8000");
}
```
En sautant à l'adresse 0x8000, le programme arrive au reset. 
Le programme recommence alors au début.

## Question 4 - 5

Le programme passe les tests, il rentre dans un état d'interruption, fait un appel système (ici reboot) et après le reboot le programme se relance.

-------------------------------------------------------

L'objectif des questions suivantes est maintenant de faire un appel système, puis retourner à l'exécution normale du programme.

## Question 6 

Pas grand chose à dire.

## Question 7

Le problème est que l'état des registres n'est pas sauvergardé notament l'état du registre `lr`,
ce regisre contient l'adresse de retour après avoir terminé une fonction. 

## Question 8

Pour sauvergarder l'état des registres on utilise:
```C
__asm("stmfd sp!, {r1-r12, lr}");
```
Les valeurs présentent dans les registres sont alors copiées dans la pile.

Après l'éxecuction des appels systèmes (à la fin de `swi_handler`), on recharge les registres à l'aide de :
```C
__asm("ldmfd sp!, {r1-r12, pc}^");
```
NB: lr devient pc, en effet afin que le programme retourne à l'état d'avant l'interruption, il faut
que pc contienne l'adresse de retour.

## Question 9 - 10

I DONT KNOW

## Question 11

En effet tout se passe bien, enfin on pense.

Eh oui Jamy, il y a encore un problème, en effet le stack pointer est incrémenté (ou plutôt décrémenté)
à chaque interruption.

Pour règler ce problème, il faut dire à arm de ne pas toucher au stack pointer.
On écrit alors:
```C
__attribute__ ((naked)) void swi_handler(void){
	...
}
```
On pourrait aussi résoudre le problème en sauvant le stack pointer dans la pile mais bon ...

## Question 13

Les tests se déroulent comme prévus. Et on est heureux.
