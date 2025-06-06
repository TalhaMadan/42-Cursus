#!/bin/bash

if [ ! -f /etc/nginx/ssl/nginx.crt ]; then
echo "Nginx: setting up ssl ...";
openssl req -x509 -nodes -days 365 -newkey rsa:4096 -keyout /etc/nginx/ssl/nginx.key -out /etc/nginx/ssl/nginx.crt -subj "/C=TR/ST=Sariyer/L=Istanbul/O=42Istanbul/CN=tamadan.42.fr";
echo "Nginx: ssl is set up!";
fi

exec "$@"