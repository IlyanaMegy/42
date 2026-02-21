FROM php:8.1-fpm

RUN apt-get update && apt-get install -y \
    libpng-dev \
    libjpeg62-turbo-dev \
    libfreetype6-dev \
    libzip-dev \
    zip \
    libonig-dev \
    && rm -rf /var/lib/apt/lists/*

RUN docker-php-ext-configure gd --with-freetype --with-jpeg \
    && docker-php-ext-install -j$(nproc) \
        gd \
        pdo_mysql \
        mysqli \
        mbstring \
        zip

RUN echo "upload_max_filesize = ${UPLOAD_MAX_SIZE:-10M}" > /usr/local/etc/php/conf.d/uploads.ini \
    && echo "post_max_size = ${POST_MAX_SIZE:-10M}" >> /usr/local/etc/php/conf.d/uploads.ini

WORKDIR /var/www/html
EXPOSE 9000
CMD ["php-fpm"]