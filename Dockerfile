#
# $ cd led-blink && docker build -t app . && docker run -t app
#
FROM codestand/app-builder
MAINTAINER Seiya Nuta <nuta@seiya.me>

ADD . /app
WORKDIR /baseos
CMD make deploy APP_DIR=/app
