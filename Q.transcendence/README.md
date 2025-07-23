# Projet ft_transcendence

<p align="center">
  <img src="#" alt="ft_transcendence structure" width="400"/>
</p>

---

## **Introduction**

Le projet **ft_transcendence** est le projet final du tronc commun de 42. Il consiste à créer une application web complète centrée autour d'un jeu de Pong en ligne avec de nombreuses fonctionnalités sociales et techniques. Ce projet met en avant l'utilisation de technologies web modernes, Docker, et l'architecture fullstack.

---

### **1. Comprendre le projet**

ft_transcendence est une application web qui permet de :

- Jouer au Pong en ligne contre d'autres joueurs
- Gérer des profils utilisateurs avec authentification
- Créer des tournois et suivre des statistiques
- Intégrer des fonctionnalités sociales (chat, amis, etc.)

#### **Pourquoi ce projet ?**

- Maîtrise complète du développement web fullstack
- Compréhension des WebSockets pour le temps réel
- Gestion de la sécurité web et de l'authentification
- Architecture d'applications complexes avec Docker

#### **Technologies recommandées**

- **Backend** : FastAPI/Django (Python) ou NestJS (TypeScript)
- **Frontend** : React/Vue.js ou Vanilla JavaScript
- **Base de données** : PostgreSQL
- **Containerisation** : Docker & Docker Compose
- **WebSockets** : Socket.io ou WebSocket natif

### **1.3 Choix technologiques & Glossaire**

Cette section explique **pourquoi** le projet utilise la pile **NestJS + React** et définit tous les termes techniques employés dans ce README.

#### Pourquoi NestJS + React ?

| Critère | NestJS + React (choisi) | Alternatives (FastAPI, Django) |
|---------|------------------------|--------------------------------|
| Langage partagé | Tout en **TypeScript** → partage de types entre front et back | Python ↔︎ TypeScript : moins homogène |
| WebSockets | Module dédié `@nestjs/websockets` avec **Socket.io** intégré | Plus manuel (FastAPI) ou lourd (Django Channels) |
| Structure | Modules / Guards / Pipes → code modulaire et clair | Monolithique ou non-structuré |
| ORM | **Prisma** : schéma déclaratif, migrations simples | Alembic/SQLModel (FastAPI) ou Django ORM |

#### Glossaire rapide

- **Swagger** : générateur/visu interactif de la documentation REST. NestJS l’active via des **décorateurs** et expose `/api-docs`.

- **Bundler / Dev-server** : outil (ici **Vite**) qui regroupe le code JS/CSS en fichiers optimisés et sert l’app en live-reload pendant le dev.

- **Client TS typé + migrations** : Prisma génère un **client TypeScript** fortement typé pour interroger PostgreSQL, et des **migrations** versionnées du schéma.

- **Boilerplate** : portion de code répétitive et peu intéressante qu’un framework peut générer pour accélérer le démarrage.

- **Messages bi-directionnels event-based** : modèle WebSocket où client et serveur s’envoient des "events" dans les deux sens (ex. `ballMove`, `scoreUpdate`).

- **Auth sans session serveur** : authentification via **JWT** ; aucune session n’est stockée côté serveur — le token suffit.

- **Store léger pour l’état global React** : **Zustand** maintient un état partagé minimal sans la verbosité de Redux.

- **Workflows YAML** : fichiers `.github/workflows/*.yml` décrivant les étapes CI (lint, tests, build) déclenchées sur chaque push.

- **Modules / Guards / Pipes (NestJS)** :
  - **Module** : regroupe contrôleurs & services d’un domaine (ex. `AuthModule`).
  - **Guard** : filtre les requêtes (ex. vérifier un JWT).
  - **Pipe** : transforme / valide l’entrée (ex. parseInt sur un paramètre).

- **Prisma flow** :
  1. Écrire le schéma `schema.prisma`.
  2. `prisma migrate dev` : crée une migration SQL + met à jour la DB.
  3. `prisma generate` : régénère le client TS typé.

- **NestJS génère `/api-docs` grâce aux décorateurs** : en annotant un contrôleur avec `@ApiTags`, `@ApiResponse`, Nest + Swagger UI produisent la doc interactive.

---

### **2. Architecture du projet**

#### **Structure recommandée**

```bash
transcendence/
├── docker-compose.yml
├── .env
├── Makefile
├── README.md
├── backend/
│   ├── Dockerfile
│   ├── requirements.txt
│   ├── app/
│   │   ├── api/          # Endpoints REST
│   │   ├── auth/         # Authentification
│   │   ├── game/         # Logique Pong
│   │   ├── models/       # Modèles de données
│   │   └── websockets/   # Gestion temps réel
│   └── config/
├── frontend/
│   ├── Dockerfile
│   ├── package.json
│   ├── src/
│   │   ├── components/   # Composants React/Vue
│   │   ├── pages/        # Pages de l'app
│   │   ├── game/         # Interface Pong
│   │   ├── styles/       # CSS/SCSS
│   │   └── utils/        # Utilitaires JS
│   └── public/
├── database/
│   ├── Dockerfile
│   ├── init.sql
│   └── config/
├── nginx/
│   ├── Dockerfile
│   ├── nginx.conf
│   └── ssl/
└── monitoring/           # Si module bonus
    ├── prometheus/
    └── grafana/
```

#### **Services Docker**

- **nginx** : Reverse proxy et serveur web
- **backend** : API REST et WebSockets
- **frontend** : Interface utilisateur
- **database** : PostgreSQL pour les données
- **redis** : Cache et sessions (optionnel)

---

### **3. Modules du projet**

#### **🎯 Partie obligatoire**

- Application web fonctionnelle
- Jeu Pong jouable en temps réel
- Authentification utilisateurs
- Interface utilisateur responsive
- Docker setup complet
- Base de données PostgreSQL
- Sécurité web (HTTPS, protection XSS/CSRF)

#### **💎 Modules bonus mineurs (5 points)**

- **Monitoring** : Prometheus + Grafana pour les métriques
- **Multiple Languages** : Support de 3+ langues
- **All Devices Support** : Responsive design complet
- **Browser Compatibility** : Support navigateurs supplémentaires
- **Accessibility** : Support utilisateurs malvoyants
- **SSR Integration** : Server-Side Rendering

---

### **4. Setup de développement**

#### **Prérequis**

- Docker et Docker Compose installés
- Git configuré
- Éditeur de code (VS Code recommandé)
- Navigateur web moderne

#### **Installation des outils sur Windows**

Voici la liste minimale d'outils que j'utilise **sous Windows** pour développer le projet :

- [Docker Desktop (WSL 2)](https://www.docker.com/products/docker-desktop/)
- [Git](https://git-scm.com/downloads)
- [Node.js LTS](https://nodejs.org/)
- [Python (incl. pip)](https://www.python.org/downloads/windows/)

Une fois installés, vérifie les versions :

```bash
C:\Users\ilymegy>docker --version
Docker version 28.3.2, build 578ccf6

C:\Users\ilymegy>docker-compose --version
Docker Compose version v2.38.2-desktop.1

C:\Users\ilymegy>git --version
git version 2.47.1.windows.2

C:\Users\ilymegy>node --version
v22.17.1

C:\Users\ilymegy>python --version
Python 3.13.5

C:\Users\ilymegy>pip --version
pip 25.1.1 from C:\Users\ilymegy\AppData\Local\Programs\Python\Python313\Lib\site-packages\pip (python 3.13)
```

**Base de données**

Installe quelques **CLI Node** qui vont grandement simplifier la vie :

- **pnpm** : gestionnaire de paquets ultra-rapide (alternative à npm/yarn).
- **@nestjs/cli** : génère la structure d’un projet NestJS, des modules, contrôleurs, tests…
- **prisma** : outil de migrations + client TypeScript typé pour PostgreSQL.

```bash
# gestionnaire rapide
npm install -g pnpm

# CLI NestJS
pnpm add -g @nestjs/cli

# Prisma
pnpm add -g prisma
```

---

#### **Installation sur les PCs de l'école (Ubuntu)**

```bash
# Cloner le projet
git clone <votre-repo> transcendence
cd transcendence

# Créer le fichier d'environnement
cp .env.example .env

# Éditer .env avec vos configurations
-

# Lancer l'application
make up
# ou
docker-compose up --build
```

#### **Variables d'environnement (.env)**

```bash
# Database
POSTGRES_DB=transcendence
POSTGRES_USER=user
POSTGRES_PASSWORD=password
POSTGRES_HOST=database

# Backend
SECRET_KEY=your-secret-key
JWT_SECRET=your-jwt-secret
DEBUG=true

# Frontend
REACT_APP_API_URL=http://localhost:8000
REACT_APP_WS_URL=ws://localhost:8000

# SSL (pour production)
SSL_CERT_PATH=/etc/ssl/certs/transcendence.crt
SSL_KEY_PATH=/etc/ssl/private/transcendence.key
```

---

### **5. Développement par phases**

#### **Phase 1 : Infrastructure**

- Setup Docker Compose
- Configuration base de données
- API backend minimal
- Interface frontend basique

#### **Phase 2 : Authentification**

- Système de connexion/inscription
- Gestion des profils utilisateurs
- JWT tokens et sécurité
- Upload d'avatars

#### **Phase 3 : Jeu Pong**

- Canvas HTML5 et logique de jeu
- WebSockets pour le multijoueur
- Interface de jeu responsive
- Système de score

#### **Phase 4 : Fonctionnalités sociales**

- Historique des matchs
- Classements et statistiques
- Système d'amis (optionnel)
- Chat en temps réel (optionnel)

---

### **6. Commandes utiles**

#### **Docker**

```bash
# Lancer l'application
make up
docker-compose up --build

# Arrêter l'application
make down
docker-compose down

# Voir les logs
docker-compose logs -f backend
docker-compose logs -f frontend

# Accéder à un conteneur
docker exec -it transcendence_backend_1 bash
docker exec -it transcendence_database_1 psql -U user -d transcendence

# Nettoyer
make clean
docker system prune -a

# Se connecter à PostgreSQL
docker exec -it transcendence_database_1 psql -U user -d transcendence

# Commandes SQL utiles
\dt                    # Lister les tables
\d users              # Décrire la table users
SELECT * FROM users;  # Voir tous les utilisateurs
```

#### **Backend (FastAPI exemple)**

```bash
# Installer les dépendances
pip install -r requirements.txt

# Lancer en mode développement
uvicorn app.main:app --reload --host 0.0.0.0 --port 8000

# Migrations de base de données
alembic upgrade head
alembic revision --autogenerate -m "Add users table"
```

#### **Frontend (React exemple)**

```bash
# Installer les dépendances
npm install

# Lancer en mode développement
npm start

# Build pour production
npm run build

# Tests
npm test
```

---

### **7. Tests et vérifications**

#### **Vérifier que tout fonctionne**

1. **Conteneurs actifs**

```bash
docker ps
# Vous devez voir : nginx, backend, frontend, database
```

2. **Accès à l'application**

- Frontend : <http://localhost:3000>
- Backend API : <http://localhost:8000/docs> (FastAPI)
- Base de données : localhost:5432

3. **Tests fonctionnels**

- Inscription/connexion utilisateur
- Création et modification de profil
- Lancement d'une partie de Pong
- Jeu multijoueur en temps réel

#### **Debugging**

```bash
# Logs en temps réel
docker-compose logs -f

# Vérifier la santé des conteneurs
docker-compose ps

# Redémarrer un service
docker-compose restart backend

# Reconstruire après changements
docker-compose up --build
```

---

### **8. Ressources utiles**

#### **Documentation officielle**

- [Docker Documentation](https://docs.docker.com/)
- [PostgreSQL Docs](https://www.postgresql.org/docs/)
- [FastAPI Documentation](https://fastapi.tiangolo.com/)
- [React Documentation](https://react.dev/)
- [Socket.io Guide](https://socket.io/docs/)

#### **Tutoriels spécialisés**

- [WebSocket avec JavaScript](https://developer.mozilla.org/en-US/docs/Web/API/WebSocket)
- [HTML5 Canvas pour jeux](https://developer.mozilla.org/en-US/docs/Web/API/Canvas_API/Tutorial)
- [JWT Authentication](https://jwt.io/introduction/)
- [Docker Compose pour développeurs](https://docs.docker.com/compose/gettingstarted/)

#### **Outils de développement**

- **Postman** : Test des APIs
- **pgAdmin** : Interface PostgreSQL
- **VS Code Extensions** : Docker, Python, JavaScript
- **Browser DevTools** : Debug frontend et WebSockets

---

### **9. Conseils de développement**

#### **Bonnes pratiques**

- **Commencez simple** : Version MVP d'abord, puis ajoutez les fonctionnalités
- **Testez régulièrement** : Chaque feature doit fonctionner avant de passer à la suivante
- **Documentez votre code** : Commentaires et README détaillés
- **Utilisez Git efficacement** : Commits réguliers, branches par feature
- **Sécurité dès le début** : Ne laissez pas la sécurité pour la fin

#### **Gestion d'équipe**

- **Répartition des tâches** : Backend, Frontend, DevOps, Design
- **Communication** : Slack, Discord, ou autre outil de chat
- **Code review** : Relecture croisée des pull requests
- **Intégration continue** : Tests automatisés si possible

#### **Debugging courant**

- **CORS errors** : Vérifiez la configuration nginx et backend
- **WebSocket déconnexions** : Implémentez la reconnexion automatique
- **Performance** : Optimisez les requêtes DB et le rendu frontend
- **Sécurité** : Validez toutes les entrées utilisateur

---

## **📋 CHECKLIST DE PROGRESSION**

### **🏗️ Phase 1 : Infrastructure & Setup**

- [ ] Créer la structure de projet
- [ ] Configurer Docker Compose
- [ ] Setup PostgreSQL avec volumes
- [ ] Configuration Nginx de base
- [ ] Variables d'environnement (.env)
- [ ] Makefile avec commandes utiles
- [ ] Repository Git initialisé

### **⚙️ Phase 2 : Backend API**

- [ ] Framework backend choisi et installé
- [ ] Modèles de données (User, Game, etc.)
- [ ] Endpoints d'authentification
  - [ ] POST /auth/register
  - [ ] POST /auth/login
  - [ ] GET /auth/me
- [ ] Endpoints utilisateurs
  - [ ] GET /users/{id}
  - [ ] PUT /users/{id}
  - [ ] POST /users/avatar
- [ ] Endpoints de jeu
  - [ ] POST /games/create
  - [ ] GET /games/{id}
  - [ ] GET /users/{id}/history
- [ ] Middleware de sécurité (CORS, JWT)
- [ ] Tests API avec Postman

### **🎨 Phase 3 : Frontend Interface**

- [ ] Framework frontend choisi et configuré
- [ ] Système de routing
- [ ] Pages principales créées
  - [ ] Login/Register
  - [ ] Dashboard/Profile
  - [ ] Game interface
  - [ ] Lobby/Matchmaking
- [ ] Composants réutilisables
- [ ] Gestion d'état (Context/Redux)
- [ ] Styles CSS/SCSS de base
- [ ] Responsive design mobile
- [ ] Connexion API backend

### **🎮 Phase 4 : Jeu Pong**

- [ ] Canvas HTML5 configuré
- [ ] Logique de jeu implémentée
  - [ ] Raquettes joueurs
  - [ ] Balle avec physique
  - [ ] Détection collisions
  - [ ] Système de score
- [ ] WebSockets pour multijoueur
  - [ ] Connexion/déconnexion
  - [ ] Synchronisation état jeu
  - [ ] Gestion latence
- [ ] Interface de jeu (HUD)
- [ ] Contrôles clavier/souris
- [ ] Animations et effets
- [ ] Mode spectateur (optionnel)

### **🔐 Phase 5 : Authentification & Sécurité**

- [ ] Système JWT complet
- [ ] Hachage mots de passe (bcrypt)
- [ ] Validation des entrées
- [ ] Protection CSRF
- [ ] Protection XSS
- [ ] HTTPS configuré
- [ ] Rate limiting API
- [ ] Logs de sécurité

### **📊 Phase 6 : Fonctionnalités sociales**

- [ ] Profils utilisateurs complets
- [ ] Historique des matchs
- [ ] Statistiques joueurs
- [ ] Classements/leaderboards
- [ ] Système d'amis (optionnel)
- [ ] Chat en temps réel (optionnel)
- [ ] Notifications (optionnel)

### **🏆 Phase 7 : Modules Bonus**

#### **Server-Side Pong + API (10 pts)**

- [ ] Logique Pong côté serveur
- [ ] API endpoints pour le jeu
- [ ] Documentation API
- [ ] Tests unitaires

#### **Monitoring Prometheus/Grafana (5 pts)**

- [ ] Prometheus configuré
- [ ] Métriques applicatives
- [ ] Grafana dashboards
- [ ] Alertes configurées

#### **Multiple Languages (5 pts)**

- [ ] Système i18n configuré
- [ ] 3+ langues supportées
- [ ] Sélecteur de langue
- [ ] Traductions complètes

#### **Accessibility (5 pts)**

- [ ] Support screen readers
- [ ] Alt text pour images
- [ ] Navigation clavier
- [ ] Contraste élevé
- [ ] Taille texte ajustable

#### **Advanced 3D Graphics (10 pts)**

- [ ] Babylon.js intégré
- [ ] Pong en 3D fonctionnel
- [ ] Effets visuels avancés
- [ ] Performance optimisée

### **🚀 Phase 8 : Finalisation**

- [ ] Tests complets de l'application
- [ ] Optimisation des performances
- [ ] Documentation utilisateur
- [ ] Documentation technique
- [ ] Déploiement de production
- [ ] Backup et restauration
- [ ] Monitoring en production

### **📝 Phase 9 : Documentation & Présentation**

- [ ] README.md complet
- [ ] Guide d'installation
- [ ] Guide utilisateur
- [ ] Documentation API
- [ ] Diagrammes d'architecture
- [ ] Présentation de soutenance
- [ ] Démonstration vidéo

---

### **🎯 Objectifs par semaine**

**Semaine 1-2** : Infrastructure + Backend API ✅  
**Semaine 3** : Frontend + Authentification ✅  
**Semaine 4-5** : Jeu Pong + WebSockets ✅  
**Semaine 6** : Fonctionnalités sociales ✅

---
