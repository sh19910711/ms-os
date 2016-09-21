FROM ubuntu:16.04
MAINTAINER Seiya Nuta <nuta@seiya.me>

RUN apt-get update && apt-get install -qy build-essential zsh git python3-pip ruby git

# Build xtensa toolchain
RUN apt-get install -qy make unrar-free autoconf automake libtool gcc g++ gperf \
        flex bison texinfo gawk ncurses-dev libexpat-dev python-dev python python-serial \
        sed git unzip bash help2man wget bzip2 libtool-bin

RUN useradd builder # crosstool-NG denies root
USER builder
WORKDIR /tmp
RUN git clone --recursive https://github.com/pfalcon/esp-open-sdk.git
RUN make -C esp-open-sdk
USER root
RUN make -C esp-open-sdk install

RUN pip3 install termcolor jinja2 pyyaml
RUN git clone https://github.com/codestand/baseos /baseos

WORKDIR /baseos
ADD . /app

CMD make deploy APP_DIR=/app
