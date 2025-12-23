FROM debian:bullseye

RUN apt-get update -y && apt-get upgrade -y && apt-get install -y nginx openssl

# Creation du dossier qui stocke le certificat et la clef pour une connexion sécurisée.
RUN mkdir -p /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-out /etc/nginx/ssl/inception.crt \
	-keyout /etc/nginx/ssl/inception.key \
	-subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=ilymegy.42.fr/UID=ilymegy"

RUN chmod 644 /etc/nginx/ssl/inception.key /etc/nginx/ssl/inception.crt

# Creation du dossier qui stocke les fichiers de config de NGINX
RUN mkdir -p /var/run/nginx
COPY conf/nginx.conf /etc/nginx/nginx.conf

# RUN chmod 755 /var/www/html
# RUN chown -R www-data:www-data /var/www/html

EXPOSE 443

# Lance NGINX en premier plan pour que le container ne se stop pas.
CMD ["nginx", "-g", "daemon off;"] 
