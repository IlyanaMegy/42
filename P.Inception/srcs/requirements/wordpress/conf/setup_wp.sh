#!/bin/bash

# Couleurs
CYAN='\033[0;36m'
LILAC='\033[0;35m'
OLIVE='\033[0;32m'
NC='\033[0m'

set -e

echo -e "\n\n\t\t\t${LILAC}--------------------------${NC}"
echo -e "\t\t\t${LILAC}     __Setup Wordpress    ${NC}"
echo -e "\t\t\t${LILAC}--------------------------${NC}\n"

echo -e "${OLIVE}[INFO]${NC}\t Vérification de l'existence du répertoire /var/www/wordpress"
cd /var/www/wordpress

echo -e "${OLIVE}[INFO]${NC}\t Vérification des permissions sur /var/www/wordpress..."
cd /var/www/wordpress
chmod -R 755 /var/www/wordpress/
chown -R www-data:www-data /var/www/wordpress


# Supprime tous les fichiers existants dans le dossier wordpress
find /var/www/wordpress/ -mindepth 1 -delete

# Télécharge la dernière version de Wordpress et attend la fin du téléchargement avant de continuer
echo -e "${CYAN}[DO]${NC}\t Téléchargement de Wordpress..."
wp core download --allow-root --path="/var/www/wordpress"
sleep 10

# Configure Wordpress pour se connecter à la base de données MariaDB
echo -e "${CYAN}[DO]${NC}\t Configuration de Wordpress..."
wp core config --dbhost=mariadb:3306 --dbname="$SQL_DATABASE" --dbuser="$SQL_USER" --dbpass="$SQL_PASSWORD" --allow-root --path="/var/www/wordpress"

# Installe Wordpress avec les paramètres du site spécifiés
echo -e "${CYAN}[DO]${NC}\t Installation de Wordpress avec les paramètres du site spécifiés..."
wp core install --url="https://${DOMAIN_NAME}" --title="Inception" --admin_user="$WP_ADMIN_USER" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" --allow-root --path="/var/www/wordpress"

# Crée un nouvel utilisateur auteur avec les variables d'environnement
echo -e "${CYAN}[DO]${NC}\t Création d'un nouvel utilisateur..."
wp user create "$WP_USER" "$WP_USER_EMAIL" --user_pass="$WP_USER_PASSWORD" --role=author --allow-root --path="/var/www/wordpress"

# Vide le cache pour éviter tout conflit
wp cache flush --allow-root

# Configure PHP-FPM pour écouter sur le port TCP 9000 afin de pouvoir communiquer avec le serveur web dans le conteneur
echo -e "${OLIVE}[INFO]${NC}\t Configuration de PHP-FPM..."
sed -i '36 s@/run/php/php7.4-fpm.sock@9000@' /etc/php/7.4/fpm/pool.d/www.conf
mkdir -p /run/php

# Démarre PHP-FPM au premier plan pour que le conteneur reste actif
/usr/sbin/php-fpm7.4 -F
