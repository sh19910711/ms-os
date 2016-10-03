# docker build -t codestand/baseos .
# docker run -v $PWD/examples/led-blink:/app -t codestand/baseos
FROM ubuntu:16.04
MAINTAINER Seiya Nuta <nuta@seiya.me>

RUN sed -i -e 's#http://archive.ubuntu.com/ubuntu/#mirror://mirrors.ubuntu.com/mirrors.txt#' /etc/apt/sources.list
RUN apt-get update && apt-get install -qy build-essential zsh git python3-pip ruby git wget
RUN pip3 install termcolor jinja2 pyyaml

# xtensa toolchain
RUN wget -q http://arduino.esp8266.com/linux64-xtensa-lx106-elf-gb404fb9.tar.gz
RUN tar xf linux64-xtensa-lx106-elf-gb404fb9.tar.gz -C /usr/local
ENV PATH=/usr/local/xtensa-lx106-elf/bin:$PATH

ADD . /baseos
WORKDIR /baseos
RUN git submodule update
CMD make deploy APP_DIR=/app
