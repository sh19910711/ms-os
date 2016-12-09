$(VERBOSE).SILENT:

APP_NAME  ?= $(notdir $(APP_DIR))
BUILD_DIR ?= build
CONFIG = ARCH=esp8266 TARGET=kernel APPS="channel-server esp8266-driver app" TARGET_FILE=$(BUILD_DIR)/image \
         CPPFLAGS=-Iapps/app/include CMDECHO='printf "\033[34m[%7s] %s\033[m\n"' BUILD_DIR=$(BUILD_DIR)


all: $(APP_DIR)/$(APP_NAME).esp8266.image

ZIPPED_APP_DIR = $(dir $(abspath $(ZIPFILE)))app
zipped-app:
	mkdir $(ZIPPED_APP_DIR)
	unzip $(ZIPFILE) -d $(ZIPPED_APP_DIR)
	$(MAKE) APP_DIR=$(ZIPPED_APP_DIR)

resea:
	git submodule update --init $@

resea/apps/app: $(wildcard api/*) $(APP_DIR)/application.yaml $(APP_DIR)/.config.yaml resea
	./mkapp $(APP_DIR) $@

$(APP_DIR)/$(APP_NAME).esp8266.image: $(wildcard api/*) $(APP_DIR)/application.yaml $(APP_DIR)/.config.yaml resea/apps/app
	cd resea && ./genconfig $(CONFIG)
	cd resea && make -j2
	cp resea/$(BUILD_DIR)/image $@
