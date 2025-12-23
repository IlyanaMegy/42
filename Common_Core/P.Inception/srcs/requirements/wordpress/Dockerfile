FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y

# installs PHP FastCGI Process Manager
# used to serve PHP apps in web server env
RUN apt-get install -y wget php7.4 php-fpm php-mysql mariadb-client zsh git curl netcat mycli iputils-ping

# Install WP-CLI command line inferface for WordPress
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

# 9000 is the default port for PHP-FPM
EXPOSE 9000

# Copy configuration files and give permissions
COPY conf/setup_wp.sh /setup_wp.sh
RUN ls -alc /setup_wp.sh
RUN  chmod +x /setup_wp.sh

ENTRYPOINT ["/setup_wp.sh"]
