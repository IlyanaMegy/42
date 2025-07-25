FROM node:18-alpine

# Création du répertoire de travail
WORKDIR /usr/src/app

# Installation de pnpm
RUN npm install -g pnpm

# Copie des fichiers de dépendances
COPY package.json pnpm-lock.yaml ./

# Installation de toutes les dépendances (y compris dev) pour la construction
RUN pnpm install --frozen-lockfile

# Copie du code source
COPY src/ ./src/
COPY tsconfig*.json ./
COPY nest-cli.json ./
COPY prisma/ ./prisma/

# Construction de l'application
RUN pnpm run build

# Suppression des dépendances de développement
RUN pnpm prune --prod

# Exposition du port
EXPOSE 8000

# Commande de démarrage
CMD ["node", "dist/main"]