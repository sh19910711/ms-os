ifeq ($(APP_DIR),)
    $(error "APP_DIR is not set")
endif

build: image

deploy:
	echo "TODO: insert deploy command here"

resea:
	git clone https://github.com/resea/resea

resea/apps/csapp: resea
	./build-app $@ $(APP_DIR)

image: $(wildcard api/*) $(wildcard $(APP_DIR)/*) resea/apps/csapp
	cd resea && make ARCH=esp8266 TARGET=kernel APPS="channel-server esp8266-driver csapp" TARGET_FILE=image # XXX
	cp resea/image $@
