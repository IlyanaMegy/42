# Camagru - Application Web de Montage Photo

[Sujet](ressources/en.subject.pdf)

**Camagru** est une application web qui permet de créer des montages photo avec webcam et filtres GIF.

## Fonctionnalités principales

- Capture photo via webcam
- Superposition d'images avec canal alpha
- Galerie publique avec likes/commentaires
- Système complet d'utilisateurs

## Stack technique

- Backend : PHP (standard library uniquement)
- Frontend : HTML/CSS/JavaScript natif
- Base de données : SQL
- Containerisation : Docker

## Termes Clés et Concepts Techniques

### Backend PHP

- **PHP Standard Library** : Uniquement fonctions natives PHP, pas de frameworks externes
- **MVC** : Modèle-Vue-Contrôleur pour structurer l'application
- **Sessions** : Gestion authentification utilisateur
- **Mail** : Envoi emails de confirmation/notification

### Frontend

- **getUserMedia()** : API JavaScript pour accéder webcam/micro
- **DOM Manipulation** : Modification dynamique interface
- **Responsive Design** : Adaptation mobile/desktop
- **Form Validation** : Vérification saisies utilisateur

### Sécurité

- **CSRF** : Cross Site Request Forgery protection
- **XSS** : Cross Site Scripting prevention
- **SQL Injection** : Protection requêtes SQL
- **Password Hashing** : Stockage sécurisé mots de passe

### Base de Données

- **SQL** : Langage requêtes base données
- **Relations** : Liens entre tables (users, images, comments, likes)
- **Transactions** : Opérations atomiques

### Image Processing

- **Canal Alpha** : Transparence images PNG/GIF
- **Superposition** : Combinaison deux images
- **GD Library** : Manipulation images PHP

### Containerisation

- **Docker** : Isolation environnement
- **docker-compose** : Orchestration services
- **Volumes** : Partage fichiers host/container

### Web Concepts

- **HTTP** : Protocole communication web
- **Cookies/Sessions** : Maintien état utilisateur
- **REST** : Architecture API
- **CORS** : Cross Origin Resource Sharing

## Roadmap

[Roadmap](ressources/ROADMAP.md)

### Phase 1. Infrastructure Base

#### Configuration Docker pour Camagru

Pour Camagru, tu as besoin de 4 services essentiels :

- **Nginx** : Serveur web (port 8080)
- **PHP-FPM** : Traitement PHP
- **MySQL** : Base de données (port 3306)
- **MailDev** : Test emails (port 8081)

## RUN

```bash
# PowerShell
$env:OS="alpine"; docker-compose build php

# CMD
set OS=alpine && docker-compose build php

docker-compose up -d
```
