<p align="center">
  <img src="https://cdn.discordapp.com/attachments/889061317321838627/1158799834447355994/push_swap.png?ex=651d8ff1&is=651c3e71&hm=5d3eef9f92b17571391b9615e86aaaca12f31dd71acb491453bdf1d570098219&raw=true" alt="push_swap project"/>
</p>

## Projet PUSH_SWAP

* [Introduction](#introduction)
* [Utilisation](#utilisation)
* [Methode](#methode)
* [liens](#liens)

## Introduction

Le [projet](./resources/fr.subject.pdf)  Push swap  est un exercice d’algorithmie simple et efficace : il faut trier de  
la donnée.  
Vous avez à votre disposition un ensemble d’entiers, deux piles et un ensemble d’ins-  
tructions pour manipuler celles-ci.  
Votre but ? Écrire un programme en C nommé  push_swap  qui calcule et affiche sur  
la sortie standard le plus petit programme, fait d’instructions du  langage Push swap,  
permettant de trier les entiers passés en paramètres.

<p align="center">
  <img src="https://cdn.discordapp.com/attachments/889061317321838627/1158799849832063008/method.png?ex=651d8ff5&is=651c3e75&hm=49459e883d91b2573b49bd653b546b9ee5b395e5648dbe372c521a2f1c873b3e&raw=true" alt="method"/>
</p>

---

command  | action |
---|------|
`sa` | swap a - swap the first 2 elements at the top of *stack_a*					|
`sb` | swap b - swap the first 2 elements at the top of *stack_b*	|
`ss` | sa and sb at the same time |
`pa` | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty|
`pb` | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty |
`ra` | rotate a - shift up all elements of *stack_a* by 1. The first element becomes the last one			|
`rb` | rotate b - shift up all elements of *stack_b* by 1. The first element becomes the last one 		|
`rr` | ra and rb at the same time			|
`rra` |  reverse rotate a - shift down all elements of *stack_a* by 1. The last element becomes the first one	|
`rrb` |  reverse rotate b - shift down all elements of *stack_b* by 1. The last element becomes the first one	|
`rrr` | rra and rrb at the same time		|

---
Scores pour evaluation :
trier 3 nombres en <= 3 operations

trier 5 nombres en <= 12 operations

trier 100 nombres en :
700 operations max score
900 operations
1100 operations
1300 operations
1500 operations min score

trier 500 nombres en :
5500 operations max score
7000 operations
8500 operations
10000 operations
11500 operations min score

## Utilisation

`cd push_swap`

`make`

`./push_swap <nombres a trier>`

Les nombres peuvent etre passes :

* en simples arguments `./push_swap 1 3 7 4 2`
* dans une chaine de caracteres `./push_swap "1 3 7 4 2"` 
* dans une variable d'environnement `ARG="1 3 7 4 2"; ./push_swap $ARG`

> rajouter un ` | wc -l` pour avoir le nombre de commandes effectuees lors du tri.

De la meme facon nous pouvons utiliser le checker pour verifier notre programme :
 ` ./checker 5 2 3 1 4`
` ./checker "-50 -400 -20 -1 -100"`
 ` ./checker "-22" "35" "40" "-15" "75"`

On peut lancer les deux en meme temps avec cette commande :
` ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG`

Et pour voir le programme en action on utilise le visualizer :

    python3 pyviz.py `ruby -e "puts (1..100).to_a.shuffle.join(' ')"`

<p align="center">
  <img src="https://cdn.discordapp.com/attachments/889061317321838627/1158801495840534599/push_swap_visualizer.gif?ex=651d917e&is=651c3ffe&hm=07ad4d8013395af60e7ee9c77ffbcde60932716d028c8449357a1a7740f62b99&raw=true" alt="visualizer"/>
</p>

## Methode

Afin de trier la pile, j'en ai profité pour pratiquer la récursion dans toutes les fonctions possibles et développé cet algorithme inspiré du tri rapide :

 - Trouver la mediane de la stack_a
 - Push les plus petits nombres de la stack_a vers la stack_b
 - Push back de stack_b a stack_a en suivant cette regle :
	 -  si le nombre fait partie de des plus grands nombres de la stack_b, pushez vers stack_a,
	 - si le nombre suit les nombres tries, pushez vers stack_a et faire la rotation pour le placer a la fin de stack_a.
- lorsque tous les nombres sont de nouveau dans stack_a, on repete le processus jusqu'a ce que la premiere moitie de la liste soit triee
- On trouve la deuxieme moitiee non triee et on repete cette methode
- repeter l'algorithme jusqu'a ce que stack_a soit triee et complete.

## liens
Push swap par [anyaschukin](https://github.com/anyaschukin/Push_Swap/tree/master)
Explications du projet [ici](https://medium.com/@msouiyeh/not-your-typical-42network-push-swap-cc583f863a90)
Plus de [ressources](https://push_swap.simple.ink/resources-6af6a8eb190b46e3aad85e9a2d4486c7)...
Github du [Visualizer](https://github.com/o-reo/push_swap_visualizer)
Push swap [tester](https://github.com/laisarena/push_swap_tester)

