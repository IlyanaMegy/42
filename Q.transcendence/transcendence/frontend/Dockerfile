# # Étape de construction
# FROM node:18-alpine as dev-stage

# WORKDIR /app

# # Copie des fichiers de dépendances
# COPY package*.json ./
# COPY pnpm-lock.yaml* ./

# # Installation des dépendances
# RUN npm install -g pnpm
# RUN pnpm install

# # Copie du code source
# COPY . .

# # Construction de l'application
# RUN pnpm run build

# # Étape d'exécution
# FROM nginx:alpine

# # Copie de la configuration Nginx
# COPY nginx.conf /etc/nginx/nginx.conf

# # Création du répertoire pour les fichiers statiques
# RUN mkdir -p /usr/share/nginx/html

# # Copie des fichiers construits
# COPY --from=builder /app/dist /usr/share/nginx/html

# # Exposition du port
# EXPOSE 80

# # Commande pour garder Nginx en premier plan
# CMD ["nginx", "-g", "daemon off;"]

# ==============================================================================
# Étape 1 : Base de développement (dev-stage)
# ==============================================================================
FROM node:18-alpine AS dev-stage

# Définir le répertoire de travail
WORKDIR /app

# Copier les fichiers de dépendances et les installer
COPY package*.json ./
RUN npm install -g pnpm
RUN pnpm install

# Copier tout le reste du code (sera écrasé par le volume Docker)
COPY . .

# La commande par défaut pour le développement : lance le serveur de Vite
# Vite écoutera sur toutes les interfaces réseau (0.0.0.0) pour être accessible
# depuis l'extérieur du conteneur.
CMD ["pnpm", "run", "dev", "--host"]


# ==============================================================================
# Étape 2 : Builder de production (build-stage)
# ==============================================================================
FROM node:18-alpine AS build-stage

WORKDIR /app

COPY package*.json ./
RUN npm install -g pnpm
RUN pnpm install

# Copier tout le code source pour le build
COPY . .

# Construire l'application pour la production
RUN pnpm run build


# ==============================================================================
# Étape 3 : Serveur de production (production-stage)
# ==============================================================================
FROM nginx:alpine AS production-stage

# Copier les fichiers statiques construits depuis l'étape précédente
COPY --from=build-stage /app/dist /usr/share/nginx/html

# Copier la configuration Nginx personnalisée
COPY nginx.conf /etc/nginx/nginx.conf

# Exposer le port 80
EXPOSE 80

# La commande par défaut pour la production : lance le serveur Nginx
CMD ["nginx", "-g", "daemon off;"]