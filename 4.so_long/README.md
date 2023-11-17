## Projet SO_LONG

![game_screen](https://cdn.discordapp.com/attachments/889061317321838627/1142052289499107368/game_screen.png)

* [Introduction](#introduction)
* [Utilisation](#utilisation)
* [liens](#liens)

## Introduction

Le [projet](./resources/fr.subject.pdf) est de créer un jeu 2D en utilisant la bibliothèque graphique [MinilibX](https://harm-smits.github.io/42docs/libs/minilibx/images.html) et le langage C.
Ce projet est un jeu simple où le joueur doit collecter tous les objets de la carte et atteindre la sortie, le joueur ne peut se déplacer que horizontalement et verticalement, la carte est composée de murs, d'espaces vides, d'objets à collectionner et la sortie, le joueur perd s'il entre en collision avec un ennemi.

## Utilisation

> Premièrement assurez-vous d'avoir bien telecharge la [Minilibx](https://github.com/42Paris/minilibx-linux) pour ensuite la mettre a la racine de votre projet.

Donc clonez le projet, et faites un `make` une fois la Minilibx a la racine du dossier :

`cd so_long`

`cp <chemin_dossier_Minilibx>/minilibx-linux .`

`make`

Pour lancer le programme exécutez `./so_long` suivi de la map a afficher (elles se trouvent dans le dossier `/maps`) :

`./so_long maps/42.ber`

Libre a vous de créer vos propres maps du moment qu'elles respectent les règles suivantes :

- la map doit être rectangulaire et entourée de murs (représentés par des **1**)
- la map doit contenir un personnage **P**, des collectibles **C**, un ennemi au moins **B** et une sortie **E**
- les collectibles et la sortie doivent être accessibles

Voici quelques exemples de maps :


<p align="center">
  <img src="https://cdn.discordapp.com/attachments/889061317321838627/1159163505677709362/42ber.png?ex=651ee2a3&is=651d9123&hm=4498556cc22015b8398048df30313632ecdb7d05f81ba8ae04d4ada73572ed5d raw=true" alt="method"/>
</p>


<p align="center">
  <img src="https://cdn.discordapp.com/attachments/889061317321838627/1159163494655078430/bigber.png?ex=651ee2a1&is=651d9121&hm=29374a7df67c3b8dc82825e2bca04e45054afd91737dfb2af7a7c6ac3bf58a14&raw=true" alt="method"/>
</p>


<p align="center">
  <img src="https://cdn.discordapp.com/attachments/889061317321838627/1159163477206773890/quickber.png?ex=651ee29d&is=651d911d&hm=2abf76f50bec0fd9732f12461faefb9a749de46bd2b32328cfb9cec1dedfcb7f&raw=true" alt="method"/>
</p>

## liens

https://anyconv.com/fr/convertisseur-de-png-en-xpm

https://harm-smits.github.io/42docs/libs/minilibx/images.html

https://github.com/42Paris/minilibx-linux


