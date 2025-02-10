FROM debian:bullseye

RUN apt update -y
RUN apt upgrade -y
RUN apt install nginx -y
RUN mkdir -p /etc/nginx/ssl

RUN apt install openssl -y
RUN openssl req -x509 -nodes -out /etc/nginx/ssl/lnunez-t.crt\
 -keyout /etc/nginx/ssl/lnunez-t.key -subj "/C=FR/ST=IDF/L=Paris/O=42/OU=42/CN=lnunez-t.42.fr/UID=lnunez-t"

COPY ./conf/nginx.conf /etc/nginx/conf.d

RUN mkdir -p /var/run/nginx
RUN chmod 755 /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]