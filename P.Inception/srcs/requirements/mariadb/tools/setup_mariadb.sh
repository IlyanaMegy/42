#! /bin/bash

# Couleurs
OLIVE='\033[0;32m'
LILAC='\033[0;35m'
NC='\033[0m'

set -e

echo -e "\n\n\t\t\t${LILAC}--------------------------${NC}"
echo -e "\t\t\t${LILAC}     __Setup MariaDB      ${NC}"
echo -e "\t\t\t${LILAC}--------------------------${NC}\n"

echo -e "${OLIVE}[INFO]${NC}\t Vérification des permissions sur /run/mysqld.."
mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld

echo -e "${OLIVE}[INFO]${NC}\t Vérification des permissions sur /var/lib/mysql..."
chown -R mysql:mysql /var/lib/mysql

# Initialiser la base de données si nécessaire
if [ ! -d /var/lib/mysql/mysql ]; then
    echo -e "${OLIVE}[INFO]${NC}\t Initialisation de la base de données..."
    mysqld --initialize-insecure --user=mysql --datadir=/var/lib/mysql
fi

# Lancer MariaDB en arrière-plan
echo -e "${OLIVE}[INFO]${NC}\t Démarrage temporaire de MariaDB pour configuration initiale..."
mysqld_safe --datadir=/var/lib/mysql &
pid="$!"

# Attendre que MariaDB soit prêt
echo -e "${OLIVE}[INFO]${NC}\t Attente de MariaDB..."
until mariadb -u root -e "SELECT 1" &>/dev/null; do
    sleep 1
done

# Sécuriser l'accès root et supprimer les bases par défaut
echo -e "${OLIVE}[INFO]${NC}\t Sécurisation de MariaDB..."
mariadb -u root <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';
DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;
FLUSH PRIVILEGES;
EOF

# Créer la base et l'utilisateur
echo -e "${OLIVE}[INFO]${NC}\t Création de la base et de l'utilisateur..."
mariadb -u root -p"${SQL_ROOT_PASSWORD}" <<EOF
CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO '${SQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

# Arrêter MariaDB proprement
echo -e "${OLIVE}[INFO]${NC}\t Arrêt temporaire de MariaDB..."
mysqladmin -u root -p"${SQL_ROOT_PASSWORD}" shutdown

# Redémarrer MariaDB en mode foreground avec la config finale
echo -e "${OLIVE}[INFO]${NC}\t  Redémarrage de MariaDB en mode foreground..."
exec mysqld_safe --datadir=/var/lib/mysql
