FROM ubuntu:16.04
MAINTAINER Seiya Nuta <nuta@seiya.me>

RUN apt-get update && apt-get install -qy build-essential zsh git python3-pip ruby git
RUN pip3 install termcolor jinja2 pyyaml
RUN git clone https://github.com/codestand/baseos /baseos

# Build xtensa toolchain
RUN apt-get install -qy make unrar-free autoconf automake libtool gcc g++ gperf \
        flex bison texinfo gawk ncurses-dev libexpat-dev python-dev python python-serial \
        sed git unzip bash help2man wget bzip2 libtool-bin

RUN useradd --system --no-create-home builder # crosstool-NG denies root
RUN chown builder /opt
USER builder
WORKDIR /opt
RUN git clone --recursive https://github.com/pfalcon/esp-open-sdk.git
WORKDIR /opt/esp-open-sdk
RUN git reset --hard d18f815c8d8f6774de4a35652d7305c49f4d1964
RUN make STANDALONE=n
USER root
