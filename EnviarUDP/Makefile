APP=EnviarUDP
SRC=$(APP).c
OBJ=$(APP).o
CC=gcc
PKG_CFLAGS=`pkg-config gstreamer-0.10 --cflags` 
PKG_LIBS=`pkg-config gstreamer-0.10 --libs`
CROSS_COMPILE=arm-linux-gnueabihf-

all: $(APP)

$(APP): $(SRC)
		$(CROSS_COMPILE)$(CC) $(PKG_CFLAGS) -o $(APP) $(SRC) $(PKG_LIBS) 

x86: 
		$(CC) $(PKG_CFLAGS) -o $(APP) $(SRC) $(PKG_LIBS) 
clean:
		rm $(APP)
