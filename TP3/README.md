# TP3 : Gestion mémoire

## Questions 1 et 2

4 processeurs

## Question 3

Probablement des adresses physiques car elles ne doivent pas bouger

## Question 4

`SYSTEM RAM` :

|Adresses|Taille|
|--------|------|
|`9f7ff - 1000`||
|`4000 3fff - 2020 0000`|16 GB|
|`1fff ffff - 0010 0000`|0,5 GB|
|`d9ff ffff - d9c0 7000`|0,006 GB|
|`11edf ffff - 10000 000`|72 GB|

## Question 5

8GB de swap (cmd: `free`)

## Question 6

`malloc`

``` c
non_init[1024]; // --> STACK
init[4] = {1,2,3,4}; // --> STACK 
```

## Question 7
```
heap:  	0x231c010
stack: 	0x34acd680
main():	0x004005dd
bss:		0x00601058
data:		0x00601048

## Question 8

virtuelles

## Question 9

VmSize = 4208 kB

