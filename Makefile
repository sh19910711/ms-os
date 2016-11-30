$(VERBOSE).SILENT:

ifeq ($(APP_DIR),)
    $(error "APP_DIR is not set")
endif

APP_NAME ?= $(notdir $(APP_DIR))
CONFIG = ARCH=esp8266 TARGET=kernel APPS="channel-server esp8266-driver app" TARGET_FILE=image \
         CPPFLAGS=-Iapps/app/include CMDECHO='printf "\033[34m[%7s] %s\033[m\n"'


all: $(APP_DIR)/$(APP_NAME).esp8266.image

resea:
	git submodule update --init $@

resea/apps/app: $(wildcard api/*) $(APP_DIR)/application.yaml $(APP_DIR)/.config.yaml resea
	./mkapp $(APP_DIR) $@

$(APP_DIR)/$(APP_NAME).esp8266.image: $(wildcard api/*) $(APP_DIR)/application.yaml $(APP_DIR)/.config.yaml resea/apps/app
	cd resea && ./genconfig $(CONFIG)
	cd resea && make -j2
	cp resea/image $@
