# ft_Transcendence

**ft_Transcendence** est une application web full-stack réalisée en **groupe** visant à concevoir une plateforme interactive en ligne intégrant un système d’authentification, une base de données et des fonctionnalités temps réel.

Le projet repose sur une architecture client / serveur permettant aux utilisateurs de :

- créer un compte et se connecter
- interagir avec d'autres utilisateurs
- jouer à un jeu multijoueur en ligne directement dans le navigateur
- consulter leurs statistiques et leur historique

Cette application intègre :

- un backend avec API REST
- une interface utilisateur dynamique
- un système d’authentification sécurisé
- une base de données
- des communications en temps réel via WebSockets

Ce projet m’a permis de travailler sur :

- le développement d’une application web full-stack
- la communication client / serveur
- les API REST
- la gestion d’authentification (sessions / tokens)
- les WebSockets (temps réel)
- la gestion de base de données
- le travail en équipe sur une architecture modulaire
- l’organisation de projet (répartition backend / frontend)

---

## 🚀 Lancer le projet en local

### ✅ Prérequis

Assurez-vous d’avoir installé :

- Docker  
- Docker Compose  
- Make  

---

### ⚙️ 1. Cloner le dépôt

```bash
git clone https://github.com/IlyanaMegy/42.git
cd 42/Q.Transcendence
```

---

### 🔐 2. Configurer les variables d’environnement

Créer un fichier `.env` à la racine du projet :

```bash
touch .env
```

Sous Windows (PowerShell) :

```powershell
New-Item -ItemType File .env
```

Exemple de configuration :

```env
HOST=localhost
LAN_IP=192.168.1.10

#ENV FOR RENDERING#

# DEFAULT:::UNCOMMENT OUT FOR PROD MODE WITHOUT OAUTH LAN#
NODE_ENV=production
FRONTEND_URL=https://${HOST}:8443
PORT=8443
NIPIO=""

# UNCOMMENT OUT FOR PROD MODE WITH OAUTH LAN#
# NODE_ENV=production
# FRONTEND_URL=https://${HOST}:8443
# PORT=8443
# NIPIO=.nip.io

#UNCOMMENT FOR DEV MODE (hotloading)#
# NODE_ENV=development
# FRONTEND_URL=https://${HOST}:5173
# PORT=5173
# NIPIO=""

######

#VAULT#
VAULT_ADDR=https://vault:8200
VAULT_TOKEN=your-vault-token
VAULT_SKIP_VERIFY=true
######

#URLS#
API_URL=https://${HOST}:3000
AUTH_SERVICE_URL=https://auth-service:3001
SOCIAL_SERVICE_URL=https://social-service:3002
PONG_SERVICE_URL=https://pong-service:3003
FRONTEND_URL_LOCAL=https://localhost:8443
FRONTEND_URL_LAN=https://${LAN_IP}:8443
######

#PORTS#
API_PORT=3000
AUTH_PORT=3001
SOCIAL_PORT=3002
PONG_PORT=3003
######

#SMTP INFO#
SMTP_HOST=smtp.gmail.com
SMTP_PORT=465
SMTP_EMAIL=your-email@gmail.com
SMTP_PASSWORD=your-app-password
######

#OAUTH#
GOOGLE_CLIENT_ID=your-google-client-id
GOOGLE_CLIENT_SECRET=your-google-client-secret
GOOGLE_REDIRECT_URI=https://${HOST}${NIPIO}:${PORT}/api/auth/oauth/google/callback
#GITHUB#
GITHUB_CLIENT_ID=your-github-client-id
GITHUB_CLIENT_SECRET=your-github-client-secret
GITHUB_REDIRECT_URI=https://${HOST}${NIPIO}:${PORT}/api/auth/oauth/github/callback
#42#
FORTYTWO_CLIENT_ID=your-42-client-id
FORTYTWO_CLIENT_SECRET=your-42-client-secret
FORTYTWO_REDIRECT_URI=https://${HOST}${NIPIO}:${PORT}/api/auth/oauth/fortytwo/callback
######

#AUTHENTICATION#
JWT_SECRET=your-jwt-secret
JWT_EXPIRE=24h
BCRYPT_ROUNDS=12
######

#DB AND OTHERS#
DATABASE_PATH=/app/data/transcendence.db
```

---

### 🏗️ 3. Build et lancement des conteneurs

Compiler et lancer l’infrastructure avec :

```bash
make
```

Ou :

```bash
docker-compose up --build
```

Note Windows : `make` et les scripts `.sh` nécessitent WSL ou Git Bash. Sinon, lance `docker-compose up --build` et ajuste `HOST`/`LAN_IP` manuellement dans `.env`.

---

### 🌐 4. Accéder à l’application

Une fois les conteneurs lancés :

👉 https://localhost:8443

---

### 🧹 5. Stopper l’infrastructure

```bash
make down
```

Pour supprimer également les vo