# Inception

**Inception** est un projet visant à mettre en place une architecture web complète en environnement conteneurisé à l’aide de **Docker**.

L’objectif est de déployer et configurer plusieurs services interconnectés au sein d’une même infrastructure :

- un serveur web NGINX avec HTTPS (TLS)
- un CMS WordPress
- une base de données MariaDB

Chaque service est isolé dans son propre conteneur Docker et configuré pour communiquer avec les autres via un réseau interne sécurisé.

Ce projet permet de se familiariser avec :

- la conteneurisation avec Docker
- l’orchestration de services avec Docker Compose
- la gestion de bases de données
- la configuration de serveur web (NGINX)
- la mise en place du protocole HTTPS (TLS)
- la persistance des données via des volumes Docker
- la communication entre services dans une architecture web

---

## 🚀 Lancer le projet en local

### ✅ Prérequis

Assurez-vous d’avoir installé :

- Docker  
- Docker Compose  
- Make  

Sur Linux :

```bash
sudo apt update
sudo apt install docker.io docker-compose make
```

Puis lancer Docker :

```bash
sudo systemctl start docker
```

---

### ⚙️ 1. Cloner le dépôt

```bash
git clone https://github.com/IlyanaMegy/Inception.git
cd Inception
```

---

### 🔐 2. Configurer les variables d’environnement

Créer un fichier `.env` à la racine du projet :

```bash
touch .env
```

Exemple de configuration :

```env
SQL_DATABASE=wordpress
SQL_ROOT_PASSWORD=rootpassword
SQL_USER=wpuser
SQL_PASSWORD=wppassword
SQL_HOST=mariadb:3306

# Utilisateur WordPress admin
WP_ADMIN_USER=admin
WP_ADMIN_PASSWORD=adminpassword
WP_ADMIN_EMAIL=admin@test.com

# Utilisateur WordPress classique
WP_USER=user
WP_USER_PASSWORD=mdp1userpassword312
WP_USER_EMAIL=user@example.com

DOMAIN_NAME=ilymegy.42.fr
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

---

### 🌐 4. Accéder au site

Une fois les conteneurs lancés :

👉 https://localhost

Le certificat TLS est auto-signé, votre navigateur affichera donc un avertissement de sécurité (comportement attendu).

```bash
# 🧹 Stopper l’infrastructure
make down
```
