FROM debian:bullseye

# Mise à jour, installation de MariaDB et nettoyage des fichiers inutiles
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y mariadb-server wget

# Création des répertoires nécessaires pour MariaDB et réglage des permissions
RUN mkdir -p /run/mysqld && \
    chown -R mysql:mysql /run/mysqld && \
    chmod 775 /run/mysqld 

# Vérification de l'utilisateur mysql
RUN grep mysql /etc/passwd

# Copier le fichier de configuration MariaDB
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copier le script de setup et ajout des permissions d'exécution
COPY tools/setup_mariadb.sh ./setup_mariadb.sh
RUN chmod +x ./setup_mariadb.sh

# Exposition du port MariaDB
EXPOSE 3306

# Lancement du script de setup lors du démarrage du conteneur
CMD ["bash", "./setup_mariadb.sh"]
