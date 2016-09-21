build: image

resea:
	git clone https://github.com/resea/resea

resea/apps/csapp: resea
	./build-app $@ $(APP_DIR)

image: $(wildcard api/*) $(wildcard $(APP_DIR)/*) resea/apps/csapp
	cd resea && make ARCH=esp8266 TARGET=kernel APPS="channel-server esp8266-driver csapp" TARGET_FILE=image # XXX
	cp resea/image $@
