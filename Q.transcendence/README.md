# Projet ft_transcendence

_ ilymegy

<!-- <p align="center">
  <img src="#" alt="ft_transcendence structure" width="400"/>
</p> -->

## **Sommaire**

- [Introduction](#0-introduction)
- [Comprendre le projet](#1-comprendre-le-projet)
- [Choix techniques](#2-choix-techniques)
- [Petit cours de web](#3-petit-cours-de-web)
- [Architecture du projet](#4-architecture-du-projet)
- [Setup](#5-setup)
- [Commandes utiles](#6-commandes-utiles)
- [Développement](#7-développement-par-phases)
- [Checklist de progression](#8-checklist-de-progression)
- [Ressources utiles](#9-ressources-utiles)

### **0. Introduction**

Le projet **ft_transcendence** est le projet final du tronc commun de 42. Il consiste à créer une application web complète centrée autour d'un jeu de Pong en ligne avec de nombreuses fonctionnalités sociales et techniques. Ce projet met en avant l'utilisation de technologies web modernes, Docker, et l'architecture fullstack.

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

#### **Services Docker**

- **nginx** : Reverse proxy et serveur web
- **backend** : API REST et WebSockets
- **frontend** : Interface utilisateur
- **database** : PostgreSQL pour les données
- **redis** : Cache et sessions (optionnel)

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

### **2. Choix techniques**

#### **Vite : L'outil de build ultra-rapide**

Vite est un outil de build moderne qui améliore considérablement l'expérience de développement frontend.

***Avantages clés***

- **Démarrage instantané du serveur** : Contrairement à Create React App qui peut prendre plusieurs secondes, Vite démarre en quelques millisecondes.
- **HMR (Hot Module Replacement) ultra-rapide** : Les modifications dans le code sont reflétées instantanément dans le navigateur, sans rechargement complet de la page.
- **Optimisation des performances** :
  - **ESM natif** : Utilise les modules ES natifs du navigateur
  - **Chargement à la volée** : Ne compile que les fichiers nécessaires
  - **Pré-compilation des dépendances** : Les dépendances sont pré-compilées une seule fois
- **Configuration minimale** : Moins de fichiers de configuration que webpack, tout en restant personnalisable.

***Comparaison Vite vs Create React App (CRA)***

| Fonctionnalité | Vite | Create React App |
|----------------|------|-----------------|
| Temps de démarrage | ⚡ Instantané | 🐢 Plus lent |
| HMR | ⚡ Instantané | 🐢 Plus lent |
| Configuration | 🔧 Minimale | 📦 Pré-configurée |
| Flexibilité | 🔥 Très flexible | 🔄 Moins flexible |
| Production Build | ⚡ Ultra-rapide | 🐢 Plus lent |

***Pourquoi Vite pour ft_transcendence ?***

1. **Productivité accrue** : Développement plus fluide avec des rechargements quasi-instantanés
2. **Optimisé pour ES Modules** : Parfait pour les projets modernes
3. **Léger et rapide** : Important pour une application de jeu comme Pong
4. **Support TypeScript natif** : Pas besoin de configuration supplémentaire
5. **Écosystème riche** : Nombreux plugins officiels et communautaires

---

#### **Pourquoi NestJS + React ?**

| Critère | NestJS + React (choisi) | Alternatives (FastAPI, Django) |
|---------|------------------------|--------------------------------|
| Langage partagé | Tout en **TypeScript** → partage de types entre front et back | Python ↔︎ TypeScript : moins homogène |
| WebSockets | Module dédié `@nestjs/websockets` avec **Socket.io** intégré | Plus manuel (FastAPI) ou lourd (Django Channels) |
| Structure | Modules / Guards / Pipes → code modulaire et clair | Monolithique ou non-structuré |
| ORM | **Prisma** : schéma déclaratif, migrations simples | Alembic/SQLModel (FastAPI) ou Django ORM |

---

### **3. Petit cours de web**

#### **Qu'est-ce qu'une application web ?**

Imagine que tu veux créer un restaurant :

🏪 Le restaurant = ton application web (ex: ton jeu Pong)
👨‍🍳 La cuisine = le backend (là où on prépare les plats)
🍽️ La salle = le frontend (là où les clients mangent)
📋 Le carnet de commandes = la base de données (où on stocke les infos)
🚪 Le serveur = l'API (qui fait le lien entre cuisine et salle)

Concrètement pour ton projet Pong :
Frontend : ce que tu vois (le jeu, les boutons, les scores)
Backend : ce qui calcule (logique du jeu, qui gagne, sauvegarder les scores)
Base de données : où on stocke (profils joueurs, historique des parties)

---

#### **Les langages de base du web**

HTML = La structure (les murs de ta maison)

```html
<h1>Mon titre</h1>
<p>Mon paragraphe</p>
<button>Mon bouton</button>
```

C'est comme les murs et pièces de ta maison.

CSS = Le style (la décoration)

```css
h1 { color: blue; font-size: 24px; }
```

C'est la peinture, les meubles, la déco.

JavaScript = L'interactivité (l'électricité)

```javascript
button.onclick = function() { alert("Coucou !"); }
```

C'est ce qui fait que les lumières s'allument quand tu appuies sur l'interrupteur.

---

#### **Client vs Serveur (la base de TOUT)**

Imagine que tu commandes une pizza :

🏠 TOI (client) ← → 🍕 PIZZERIA (serveur)

Tu demandes une pizza (requête)
La pizzeria prépare la pizza
La pizzeria te renvoie la pizza (réponse)
En web :
🖥️ TON NAVIGATEUR (client) ← → 🏢 SERVEUR WEB (serveur)

Tu tapes google.com (requête)
Le serveur Google prépare la page
Google t'envoie la page HTML/CSS/JS (réponse)

---

#### **Frontend vs Backend (en détail)**

🎨 FRONTEND = Ce que TU vois
Où ça tourne : Dans ton navigateur (Chrome, Firefox...)
Langages : HTML, CSS, JavaScript
Exemples : Boutons, animations, formulaires, menus
⚙️ BACKEND = Ce que tu NE vois PAS
Où ça tourne : Sur un serveur (ordinateur distant)
Langages : Python, JavaScript (Node.js), Java, PHP...
Exemples : Vérifier ton mot de passe, sauvegarder tes données, calculer ton score
🔄 Comment ils communiquent ?
Via des API (Application Programming Interface) = des "portes" pour échanger des infos.

Exemple concret avec ton Pong :

Tu cliques "Jouer" (frontend)
Le frontend dit au backend "Lance une partie !" (API)
Le backend crée la partie et répond "OK, partie créée !" (API)
Le frontend affiche "Partie en cours..." (frontend)

 Base de données (ton carnet magique)
Une base de données = un carnet ultra-organisé qui retient TOUT.

Exemple avec des utilisateurs :

```sql
TABLE "users"
```

```markdown
| id | nom | email | score |
|----|-----|-------|-------|
| 1 | Alice | <alice@mail.com> | 1250 |
| 2 | Bob | <bob@mail.com> | 890 |
| 3 | Charlie | <charlie@mail.com> | 2100 |
```

Pourquoi c'est important ?

- Persistance : Même si tu fermes l'app, tes données restent
- Partage : Plusieurs utilisateurs peuvent accéder aux mêmes données
- Recherche : Tu peux retrouver "tous les joueurs avec un score > 1000"

---

#### **Les Frameworks** (tes super-outils)

Un framework = une boîte à outils avec des fonctions toutes prêtes.

Analogie : Construire une maison

Sans framework : Tu fabriques chaque clou, chaque planche, chaque vis à la main 😵
Avec framework : Tu as déjà des murs préfabriqués, des portes standard, etc. 😎
Pour le web :
Sans framework : Tu écris tout le code JavaScript à la main
Avec React : Tu as des "composants" tout prêts (boutons, formulaires...)

Pour le projet j'utilise la pile **NestJS + React** et définit tous les termes techniques employés dans ce README.

---

#### **React (ton framework frontend)**

> Qu'est-ce que React ?

React est un framework JavaScript qui permet de créer des composants réutilisables.

Exemple simple :

```jsx
function BoutonJouer() {
  return <button>Jouer au Pong !</button>;
}

function App() {
  return (
    <div>
      <h1>Mon Super Pong</h1>
      <BoutonJouer />
      <BoutonJouer />  {/* Je peux le réutiliser ! */}
    </div>
  );
}
```

Pourquoi c'est génial ?

- Réutilisable : Un composant = une pièce LEGO (genre le bouton jouer)
- Réactif : Si une donnée change l'affichage se met à jour automatiquement (si tu change le score le score se met à jour)
- Organisé : Chaque bout de ton interface est dans son propre fichier (le bouton jouer est dans le fichier bouton_jouer.js)

---

#### **NestJS (ton framework backend)**

> Qu'est-ce que NestJS ?

NestJS est un framework Node.js qui permet de créer des applications web et des services backend. Il organise ton backend en modules bien rangés.

Exemple d'utilisation :

```typescript
@Controller('pong')
export class PongController {
  @Get()
  getHello(): string {
    return 'Hello World!';
  }
}
```

Exemple d'organisation :

```typescript
AuthModule (tout ce qui concerne la connexion)
├── AuthController (les routes : /login, /register)
├── AuthService (la logique : vérifier le mot de passe)
└── AuthGuard (la sécurité : "es-tu connecté ?")

GameModule (tout ce qui concerne le jeu)
├── GameController (les routes : /start-game, /move-paddle)
├── GameService (la logique : calculer la position de la balle)
└── GameGateway (WebSockets : envoyer les positions en temps réel)
```

Les super-pouvoirs de NestJS :

- Modules : Tout est bien organisé par domaine
- Injection de dépendances : Les services se "branchent" automatiquement
- Décorateurs : @Get(), @Post() pour créer des routes facilement
- Swagger automatique : La documentation de ton API se génère toute seule !

#### **TypeScript (JavaScript avec des super-pouvoirs)**

JavaScript normal :

```javascript
function additionner(a, b) {
  return a + b;
}

additionner(5, "hello"); // 😱 Ça marche mais ça donne "5hello" !
```

TypeScript :

```typescript
function additionner(a: number, b: number): number {
  return a + b;
}

additionner(5, "hello"); // ❌ ERREUR ! TypeScript dit "Non !"
```

Pourquoi c'est trop bien ?

- Sécurité : Moins de bugs bizarres
- Autocomplétion : Ton éditeur connaît tes variables
- Partage de types : Frontend et backend parlent le même langage

---

#### **Prisma (ton assistant base de données)**

Le problème sans Prisma :

```sql
SELECT users.name, games.score 
FROM users 
JOIN games ON users.id = games.user_id 
WHERE games.score > 1000;
```

😵 Du SQL à la main = galère !

Avec Prisma :

```typescript
const topPlayers = await prisma.user.findMany({
  include: { games: true },
  where: { games: { some: { score: { gt: 1000 } } } }
});
```

😎 Du TypeScript lisible !

Les super-pouvoirs de Prisma :

- Schéma visuel : Tu décris tes tables en langage simple
- Migrations automatiques : Prisma met à jour ta base de données
- Client typé : Autocomplétion pour toutes tes requêtes
- Sécurité : Protection contre les injections SQL

---

#### **WebSockets (le temps réel magique)**

Le problème avec HTTP classique :

```markdown
Joueur 1 : "Je bouge ma raquette !" → Serveur
Serveur : "OK reçu" → Joueur 1
...
Joueur 2 : "Où est la balle ?" → Serveur  
Serveur : "Elle est là" → Joueur 2
```

😵 Trop lent pour un jeu en temps réel !

Avec WebSockets :

```markdown
Serveur ↔ Joueur 1 ↔ Joueur 2
🔄 Connexion permanente : tout le monde reçoit les infos instantanément !
```
  
Exemple concret avec Socket.io :

```typescript
// Backend (NestJS)
@WebSocketGateway()
export class GameGateway {
  @SubscribeMessage('paddle-move')
  handlePaddleMove(client: Socket, data: { x: number, y: number }) {
    // Diffuser à tous les joueurs
    this.server.emit('paddle-updated', data);
  }
}

// Frontend (React)
socket.on('paddle-updated', (data) => {
  // Mettre à jour la position de la raquette
  setPaddlePosition(data);
});
```

---

#### **Docker (tes conteneurs magiques)**

Analogie : Les conteneurs de transport

```markdown
🚢 Un conteneur Docker = une boîte standardisée qui contient tout ce qu'il faut pour faire tourner ton app.
```

Le problème sans Docker :

```markdown
Ton PC : "Ça marche chez moi !" 😎
PC de ton pote : "Ça marche pas !" 😭
Serveur de prod : "Ça plante !" 💥
```

Avec Docker Ça marche pareil partout !

Exemple pour ton projet :

```yaml
# docker-compose.yml
services:
  backend:
    build: ./backend
    ports:
      - "3001:3001"
    
  frontend:
    build: ./frontend  
    ports:
      - "3000:3000"
      
  database:
    image: postgres:15
    environment:
      POSTGRES_DB: transcendence
Une seule commande : docker-compose up → Tout démarre ! 🚀
```

---

#### **API REST**

> Ça va être comment frontend et backend se parlent

***REST*** = **RE**presentational **S**tate **T**ransfer (façon standardisée de communiquer)

Exemple avec ton Pong :

```typescript
// Frontend demande
GET /api/users/123        → "Donne-moi le profil du joueur 123"
POST /api/games           → "Crée une nouvelle partie"
PUT /api/games/456        → "Met à jour la partie 456"
DELETE /api/games/456     → "Supprime la partie 456"

// Backend répond
{
  "id": 123,
  "username": "Alice",
  "score": 1250,
  "games_played": 42
}
```

---

#### **Hooks React (La logique réutilisable)**

```tsx
// hooks/useGame.ts
function useGame() {
  const [score, setScore] = useState(0);
  const [isPlaying, setIsPlaying] = useState(false);
  
  const startGame = () => {
    setIsPlaying(true);
    // Logique de démarrage...
  };
  
  return { score, isPlaying, startGame };
}

// pages/Game.tsx
function Game() {
  const { score, isPlaying, startGame } = useGame();
  
  return (
    <div>
      <p>Score: {score}</p>
      {!isPlaying && <button onClick={startGame}>Jouer</button>}
    </div>
  );
}
```

---

#### **JWT (Authentification sans session)**

```typescript
// Quand tu te connectes
POST /api/auth/login
{
  "email": "alice@mail.com",
  "password": "motdepasse"
}

// Serveur répond avec un token
{
  "access_token": "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..."
}

// Ensuite, pour chaque requête
GET /api/profile
Headers: { "Authorization": "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9..." }
```

---

### **4. Architecture du projet**

```markdown
transcendence/
├── docker-compose.yml              # 🎭 Le chef d'orchestre : lance tout
├── .env                            # 🔐 Secrets et config (mots de passe, URLs)
├── Makefile                        # 📝 Commandes utiles
│
├── backend/                        # 🟢 NestJS + TypeScript
│   ├── Dockerfile
│   ├── package.json                # 🔄 Node.js
│   ├── tsconfig.json               # 🔄 Configuration TypeScript
│   ├── nest-cli.json               # 🔄 Configuration NestJS
│   ├── src/
│   │   ├── main.ts                 # 🔄 Point d'entrée NestJS
│   │   ├── app.module.ts           # 🔄 Module racine
│   │   ├── auth/                   # 🟢 Module d'authentification
│   │   │   ├── auth.module.ts
│   │   │   ├── auth.controller.ts
│   │   │   ├── auth.service.ts
│   │   │   └── auth.guard.ts
│   │   ├── game/                   # 🟢 Module de jeu
│   │   │   ├── game.module.ts
│   │   │   ├── game.controller.ts
│   │   │   ├── game.service.ts
│   │   │   └── game.gateway.ts     # 🔄 WebSockets
│   │   └── users/                  # 🟢 Module utilisateurs
│   │       ├── users.module.ts
│   │       ├── users.controller.ts
│   │       └── users.service.ts
│   └── prisma/                     # 🔄 Prisma ORM (structure de la BDD)
│       ├── schema.prisma           # 🔄 Schéma de base de données
│       └── migrations/             # 🔄 Migrations auto-générées
│
├── frontend/                       # 🟢 React + TypeScript
│   ├── Dockerfile
│   ├── package.json
│   ├── tsconfig.json               # 🔄 TypeScript pour React
│   ├── vite.config.ts              # 🔄 Configuration Vite
│   ├── src/
│   │   ├── main.tsx                # 🔄 Point d'entrée React
│   │   ├── App.tsx                 # 🔄 Composant racine
│   │   ├── components/             # 🟢 Composants React (🧩 Pièces LEGO réutilisables)
│   │   │   ├── Navbar.tsx
│   │   │   ├── Button.tsx
│   │   │   └── GameCanvas.tsx
│   │   ├── pages/                  # 🟢 Pages de l'app (écran complet)
│   │   │   ├── Home.tsx
│   │   │   ├── Game.tsx
│   │   │   └── Profile.tsx
│   │   ├── hooks/                  # 🔄 Custom hooks React (logique réutilisable)
│   │   ├── services/               # 🔄 API calls (interactions avec le backend)
│   │   ├── types/                  # 🔄 Types TypeScript partagés
│   │   └── styles/                 # 🟢 CSS/SCSS
│   └── public/
│
├── database/                       # 🟢 PostgreSQL
│
├── nginx/                          # 🟢 Reverse proxy
│   ├── Dockerfile
│   ├── nginx.conf
│   └── ssl/
│
└── monitoring/                     # 🟢 Module bonus
    ├── prometheus/
    └── grafana/
```

⚙️ **Backend/ (Le cerveau)**

Pourquoi séparé par modules ?

- Maintenance : Bug dans l'auth ? Tu touches que le dossier auth/
- Réutilisation : Le module users/ peut servir à d'autres projets
- Tests : Tu peux tester chaque module indépendamment

Exemple concret :

```typescript
// auth/auth.controller.ts → Routes de connexion
@Post('login')
login(@Body() credentials) { ... }

// game/game.controller.ts → Routes de jeu  
@Post('start-game')
startGame(@User() player) { ... }

// game/game.gateway.ts → WebSockets temps réel
@SubscribeMessage('paddle-move')
handlePaddleMove(client, data) { ... }
```

🎨 **Frontend/ (L'interface)**

Pourquoi séparé ?

Components : Un bouton = un fichier → réutilisable partout
Pages : Chaque écran = un fichier → navigation claire
Services : Toutes les requêtes API au même endroit
Types : Partage des types entre front et back
Exemple concret :

```tsx
// components/Button.tsx
export function Button({ onClick, children }) {
  return <button onClick={onClick}>{children}</button>;
}

// pages/Game.tsx  
import { Button } from '../components/Button';
function Game() {
  return <Button onClick={startGame}>Jouer !</Button>;
}

// services/gameApi.ts
export async function startGame() {
  return fetch('/api/game/start', { method: 'POST' });
}
```

🗄️ **Database/ (La mémoire)**

```bash
database/
└── # Juste l'image PostgreSQL officielle
```

Pourquoi séparé ?

- Isolation : La DB tourne dans son propre conteneur
- Sécurité : Pas d'accès direct depuis l'extérieur
- Backup : Volumes Docker séparés pour sauvegarder
- Scaling : On peut changer de DB sans toucher au code

🚪 **Nginx/ (Le portier)**

```bash
nginx/
├── nginx.conf         # 🛡️ Règles de routage et sécurité
└── ssl/               # 🔒 Certificats HTTPS
```

Pourquoi un **reverse proxy** ?

```bash
Internet → Nginx → Frontend (port 3000)
              └──→ Backend (port 3001)
```

- Sécurité : Une seule porte d'entrée
- HTTPS : Certificats SSL centralisés
- Cache : Images/CSS mis en cache
- Load balancing : Répartir la charge (bonus)

> ❔ ***Mais Qu'est-ce qu'un Reverse Proxy ?***

Imagine un grand hôtel :

```bash
🏨 HÔTEL (ton serveur)
├── 🍽️ Restaurant (Frontend - port 3000)
├── 🏊 Piscine (Backend - port 3001)  
├── 🛏️ Chambres (Database - port 5432)
└── 🚪 Réceptionniste (Nginx) ← Point d'entrée UNIQUE
```

Sans réceptionniste (problématique), un client qui veut se diriger vers le restaurant doit connaître l'étage et la porte, pareil pour la piscine et les chambres.

Avec réceptionniste (Nginx) :

```bash
Client : "Bonjour !" → au réceptionniste
Réceptionniste : "Restaurant ? Par ici !" → Redirige vers port 3000
Réceptionniste : "Piscine ? Par là !" → Redirige vers port 3001
Réceptionniste : "Chambres ? Par là !" → Redirige vers port 5432
```

🔄 Comment ça marche concrètement ?

*Sans Nginx* :

```bash
👤 Utilisateur
├── <https://monsite.com:3000> → Frontend React
└── <https://monsite.com:3001> → Backend NestJS
```

Problèmes...

- 😵 L'utilisateur doit connaître les ports
- 🚫 CORS (Cross-Origin) : navigateur bloque les requêtes entre ports
- 🔓 Pas de HTTPS centralisé
- 😰 Plusieurs points d'entrée = failles de sécurité

*Avec Nginx* :

```bash
👤 Utilisateur → <https://monsite.com> (port 443)
                        ↓
                   🚪 Nginx (reverse proxy)
                        ↓
        ┌───────────────┼───────────────┐
        ↓               ↓               ↓
   Frontend         Backend        Database
  (port 3000)     (port 3001)    (port 5432)
```

⚙️ Configuration Nginx

```nginx
# nginx/nginx.conf
server {
    listen 80;
    server_name localhost;

    # Frontend (pages web)
    location / {
        proxy_pass http://frontend:3000;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
    }

    # Backend API
    location /api/ {
        proxy_pass http://backend:3001;
        proxy_set_header Host $host;
        proxy_set_header X-Real-IP $remote_addr;
    }

    # WebSockets (temps réel)
    location /socket.io/ {
        proxy_pass http://backend:3001;
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection "upgrade";
    }
}
```

🎯 Les avantages pour le projet Pong

- Une seule URL

  - <https://monpong.com/>          → Page d'accueil (React)
  - <https://monpong.com/game>      → Jeu Pong (React)  
  - <https://monpong.com/api/login> → Connexion (NestJS)
  - <https://monpong.com/api/game>  → API jeu (NestJS)

- Sécurité renforcée

  - 🔒 HTTPS centralisé : Un seul certificat SSL
  - 🛡️ Firewall : Nginx filtre les requêtes malveillantes
  - 🚫 Ports cachés : L'extérieur ne voit que le port 80/443

- Performance

  - ⚡ Cache statique : Images, CSS, JS mis en cache
  - 📦 Compression : Gzip automatique
  - 🚀 Load balancing : Répartir la charge (si plusieurs backends)

- Développement simplifié

  - 🔄 Pas de CORS : Tout vient du même domaine
  - 🛠️ Hot reload : Nginx redirige vers Vite dev server
  - 📱 Mobile friendly : Même URL sur tous les appareils

Exemple concret

```markdown
Scénario : Joueur lance une partie

1. 👤 Joueur tape : <https://monpong.com/game>
↓
2. 🚪 Nginx : "C'est une page ? → Frontend !"
↓  
3. 🎨 React affiche la page de jeu
↓
4. 🎮 Joueur clique "Jouer" → fetch('/api/start-game')
↓
5. 🚪 Nginx : "C'est /api/ ? → Backend !"
↓
6. ⚙️ NestJS crée la partie → WebSocket
↓
7. 🚪 Nginx : "WebSocket ? → Backend aussi !"
↓
8. 🎨 React reçoit "Partie créée !" en temps réel
Résultat : L'utilisateur ne voit qu'une seule URL, mais Nginx orchestre tout en arrière-plan ! 🎭
```

🔄 **Comment tout communique ?**

```mermaid
    User[👤 Utilisateur] --> Nginx[🚪 Nginx]
    Nginx --> Frontend[🎨 React]
    Nginx --> Backend[⚙️ NestJS]
    Frontend -.WebSocket.-> Backend
    Backend --> Database[🗄️ PostgreSQL]
    Backend --> Prisma[🔧 Prisma ORM]
```

Et en gros ça donne ça :

```markdown
┌─────────────────┐    ┌─────────────────┐
│   NAVIGATEUR    │    │     SERVEUR     │
│                 │    │                 │
│  ┌───────────┐  │    │  ┌───────────┐  │
│  │  React    │  │◄──►│  │  NestJS   │  │
│  │(Frontend) │  │    │  │(Backend)  │  │
│  └───────────┘  │    │  └───────────┘  │
│                 │    │        │        │
│  ┌───────────┐  │    │  ┌───────────┐  │
│  │Socket.io  │  │◄──►│  │Socket.io  │  │
│  │(Temps     │  │    │  │(Gateway)  │  │
│  │ réel)     │  │    │  └───────────┘  │
│  └───────────┘  │    │        │        │
└─────────────────┘    │  ┌───────────┐  │
                       │  │ Prisma    │  │
                       │  │(ORM)      │  │
                       │  └───────────┘  │
                       │        │        │
                       │  ┌───────────┐  │
                       │  │PostgreSQL │  │
                       │  │(Database) │  │
                       │  └───────────┘  │
                       └─────────────────┘
```

Flow d'une action :

```markdown
User clique "Jouer" → Frontend
Frontend → HTTP → Nginx → Backend
Backend → Prisma → Database (créer partie)
Backend → WebSocket → Frontend (confirmer)
Frontend affiche "Partie créée !"
```

---

### **5. Setup**

#### **Installation des outils sur Windows**

Voici la liste minimale d'outils que j'utilise **sous Windows** :

- [Docker Desktop (WSL 2)](https://www.docker.com/products/docker-desktop/)
- [Git](https://git-scm.com/downloads)
- [Node.js LTS](https://nodejs.org/)
- [Python (incl. pip)](https://www.python.org/downloads/windows/)

Une fois installés je vérifie les versions :

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

#### **Initialisation du projet**

Voici les commandes pour initialiser mon projet :

```bash
# Initialiser le backend NestJS
cd backend
nest new . --package-manager pnpm --skip-git

# Installer les dépendances backend
pnpm add @nestjs/websockets @nestjs/config @nestjs/jwt @nestjs/passport passport-jwt socket.io @prisma/client
pnpm add -D prisma @types/passport-jwt

# Initialiser Prisma
npx prisma init

# Initialiser le frontend React/Vite
cd ../frontend
pnpm create vite . --template react-ts

# Installer les dépendances frontend
pnpm install
pnpm add axios socket.io-client zustand @chakra-ui/react @emotion/react @emotion/styled framer-motion
```

> Pour la petite explication des dépendances
**Backend :**

- `@nestjs/websockets` : Pour la communication en temps réel (jeu en ligne, chat)
- `@nestjs/config` : Gestion des variables d'environnement
- `@nestjs/jwt` & `passport-jwt` : Authentification sécurisée avec JWT
- `socket.io` : Implémentation des WebSockets
- `@prisma/client` : ORM pour la base de données
- `prisma` (dev) : Outils de développement pour les migrations

**Frontend :**

- `axios` : Requêtes HTTP vers l'API
- `socket.io-client` : Connexion WebSocket avec le serveur
- `zustand` : Gestion d'état légère et performante
- `@chakra-ui/react` : Composants UI modernes et accessibles
- `@emotion/*` : Styles en JS requis par Chakra UI
- `framer-motion` : Animations fluides

Et on arrive à une structure comme ça :

```bash
transcendence/
├── backend/               # Code source du backend
│   ├── src/               # Code source NestJS
│   ├── prisma/            # Schéma et migrations Prisma
│   ├── Dockerfile         # Configuration Docker
│   └── ...
├── frontend/              # Code source du frontend
│   ├── src/               # Composants React
│   ├── public/            # Fichiers statiques
│   └── ...
├── docker-compose.yml     # Configuration des conteneurs
└── .env                   # Variables d'environnement
```

#### **Initialisation complète du projet**

Après avoir exécuté les commandes d'installation voici comment obtenir une structure complète avec toutes les dépendances :

```bash
# Installer les dépendances du backend
cd backend
pnpm install

# Générer le client Prisma
npx prisma generate

# Installer les dépendances du frontend
cd ../frontend
pnpm install

# Configurer le .env docker-compose.yml et les Dockerfiles
...

# Démarrer les conteneurs Docker
cd ..
docker-compose up -d
```

Cette séquence va

1. Installer tous les modules Node.js nécessaires dans `backend/node_modules`
2. Générer le client Prisma pour interagir avec la base de données
3. Installer toutes les dépendances frontend dans `frontend/node_modules`
4. Lancer les conteneurs Docker (base de données + backend)

> **Note** : Le premier démarrage peut prendre quelques minutes car Docker doit télécharger et construire les images nécessaires.

#### **Base de données**

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

#### **Frontend (React + Vite + TypeScript)**

```bash
# Installer les dépendances
pnpm install

# Lancer en mode développement
pnpm dev

# Build pour production
pnpm build

# Prévisualiser le build de production localement
pnpm preview

# Lancer les tests
pnpm test

# Lancer le linter
pnpm lint

# Formater le code
pnpm format
```

#### **Backend (NestJS + Prisma)**

```bash
# Installer les dépendances
pnpm install

# Lancer en mode développement (avec rechargement à chaud)
pnpm run start:dev

# Build pour production
pnpm run build

# Lancer en production
pnpm run start:prod

# Exécuter les migrations Prisma
npx prisma migrate dev --name init

# Générer le client Prisma
npx prisma generate

# Lancer les tests
pnpm test

# Lancer le linter
pnpm lint

# Formater le code
pnpm format
```

#### **Accès à l'application**

- Frontend : <http://localhost:3000>
- Backend API : <http://localhost:8000/docs> (FastAPI)
- Base de données : localhost:5432

---

### **7. Développement par phases**

#### **Infrastructure**

- Setup Docker Compose
- Configuration base de données
- API backend minimal
- Interface frontend basique

#### **Authentification**

- Système de connexion/inscription
- Gestion des profils utilisateurs
- JWT tokens et sécurité
- Upload d'avatars

#### **Jeu Pong**

- Canvas HTML5 et logique de jeu
- WebSockets pour le multijoueur
- Interface de jeu responsive
- Système de score

#### **Fonctionnalités sociales**

- Historique des matchs
- Classements et statistiques
- Système d'amis (optionnel)
- Chat en temps réel (optionnel)

#### **Ma progression personnelle**

#### **Backend (NestJS)**

- Serveur opérationnel sur `localhost:8000`
  - Route de base (`/`) et santé (`/health`)
  - Configuration des contrôleurs et services

- Configuration Docker optimisée
  - Multi-stage build
  - Gestion des dépendances de production

- Intégration de Prisma avec PostgreSQL
  - Schéma de base de données défini
  - Migrations configurées
  - Client Prisma généré

#### **La Base de données**

- Conteneur PostgreSQL fonctionnel
  - Persistance des données avec volumes Docker
  - Configuration sécurisée

- Outils installés
  - Prisma ORM
  - @prisma/client
  - pg (driver PostgreSQL)

#### **Frontend**

- Configuration React + Vite + TypeScript
- Intégration de Chakra UI
- Gestion d'état avec Zustand

- Composants principaux
  - Authentification
  - Tableau de bord
  - Interface de jeu

#### **Fonctionnalités à implémenter**

- Système d'authentification
- Logique du jeu Pong
- Chat en temps réel
- Gestion des matchs et classements

---

### **8. Checklist de progression**

#### **🏗️ Phase 1 : Infrastructure & Setup**

- [x] Créer la structure de projet
- [X] Configurer Docker Compose
- [X] Setup PostgreSQL avec volumes
- [ ] Configuration Nginx de base
- [ ] Variables d'environnement (.env)
- [ ] Makefile avec commandes utiles
- [ ] Repository Git initialisé

#### **⚙️ Phase 2 : Backend API**

- [X] Framework backend choisi et installé
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

#### **🎨 Phase 3 : Frontend Interface**

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

#### **🎮 Phase 4 : Jeu Pong**

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

#### **🔐 Phase 5 : Authentification & Sécurité**

- [ ] Système JWT complet
- [ ] Hachage mots de passe (bcrypt)
- [ ] Validation des entrées
- [ ] Protection CSRF
- [ ] Protection XSS
- [ ] HTTPS configuré
- [ ] Rate limiting API
- [ ] Logs de sécurité

#### **📊 Phase 6 : Fonctionnalités sociales**

- [ ] Profils utilisateurs complets
- [ ] Historique des matchs
- [ ] Statistiques joueurs
- [ ] Classements/leaderboards
- [ ] Système d'amis (optionnel)
- [ ] Chat en temps réel (optionnel)
- [ ] Notifications (optionnel)

#### **🏆 Phase 7 : Modules Bonus**

##### **Server-Side Pong + API (10 pts)**

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

---

### **9. Ressources utiles**

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
- **Browser DevTools** : Debug frontend et WebSockets

#### Links

- [docker-compose.yml](https://github.com/Nimon77/ft_transcendence/blob/main/docker-compose.yml)
