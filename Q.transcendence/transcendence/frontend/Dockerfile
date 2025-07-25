# Étape de construction
FROM node:18-alpine as builder

WORKDIR /app

# Copie des fichiers de dépendances
COPY package*.json ./
COPY pnpm-lock.yaml* ./

# Installation des dépendances
RUN npm install -g pnpm
RUN pnpm install

# Copie du code source
COPY . .

# Construction de l'application
RUN pnpm run build

# Étape d'exécution
FROM nginx:alpine

# Copie de la configuration Nginx
COPY nginx.conf /etc/nginx/nginx.conf

# Création du répertoire pour les fichiers statiques
RUN mkdir -p /usr/share/nginx/html

# Copie des fichiers construits
COPY --from=builder /app/dist /usr/share/nginx/html

# Exposition du port
EXPOSE 80

# Commande pour garder Nginx en premier plan
CMD ["nginx", "-g", "daemon off;"]