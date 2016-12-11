ifeq ($(APP_DIR),)
    $(error "APP_DIR is not set")
endif

BUILD_DIR ?= build
CONFIG = ARCH=esp8266 TARGET=kernel APPS="channel-server esp8266-driver app" TARGET_FILE=$(BUILD_DIR)/image \
         CPPFLAGS=-Iapps/app/include CMDECHO='printf "\033[34m[%7s] %s\033[m\n"' BUILD_DIR=$(BUILD_DIR)


all: $(APP_DIR)/app.esp8266.image

zipped-app:
	unzip -n $(ZIPFILE) -d $(APP_DIR)
	$(MAKE) APP_DIR=$(APP_DIR)

resea:
	git submodule update --init $@

resea/apps/app: $(wildcard api/*) $(APP_DIR)/application.yaml $(APP_DIR)/.config.yaml resea
	./mkapp $(APP_DIR) $@

$(APP_DIR)/app.esp8266.image: $(wildcard api/*) $(APP_DIR)/application.yaml $(APP_DIR)/.config.yaml resea/apps/app
	cd resea && ./genconfig $(CONFIG)
	cd resea && make -j2
	cp resea/$(BUILD_DIR)/image $@

$(VERBOSE).SILENT:
