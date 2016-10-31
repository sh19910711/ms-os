$(VERBOSE).SILENT:

ifeq ($(APP_DIR),)
    $(error "APP_DIR is not set")
endif

APP_NAME ?= $(notdir $(APP_DIR))

all: $(APP_DIR)/$(APP_NAME).esp8266.image

resea/apps/csapp: resea
	./mkapp $(APP_DIR) $@

$(APP_DIR)/$(APP_NAME).esp8266.image: $(wildcard api/*) $(APP_DIR)/application.yaml $(APP_DIR)/.config.yaml resea/apps/csapp
	cd resea && make ARCH=esp8266 TARGET=kernel APPS="channel-server esp8266-driver csapp" TARGET_FILE=image CPPFLAGS=-Iapps/csapp/include
	cp resea/image $@
