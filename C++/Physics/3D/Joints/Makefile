##----------------------------------------------------------------------------
## The MIT License
## Took the basics from Polycode Examples
##----------------------------------------------------------------------------

CC=g++
POLYCODE_HOME=${HOME}/workspace/Polycode/Release/Linux/Framework
CFLAGS=-g -I${POLYCODE_HOME}/Core/Dependencies/include -I${POLYCODE_HOME}/Core/Dependencies/include/AL -I${POLYCODE_HOME}/Core/include -I${POLYCODE_HOME}/Modules/include -I${POLYCODE_HOME}/Modules/Dependencies/include -I${POLYCODE_HOME}/Modules/Dependencies/include/bullet
LDFLAGS=-lrt -ldl -lpthread ${POLYCODE_HOME}/Core/lib/libPolycore.a ${POLYCODE_HOME}/Core/Dependencies/lib/libfreetype.a ${POLYCODE_HOME}/Core/Dependencies/lib/liblibvorbisfile.a ${POLYCODE_HOME}/Core/Dependencies/lib/liblibvorbis.a ${POLYCODE_HOME}/Core/Dependencies/lib/liblibogg.a ${POLYCODE_HOME}/Core/Dependencies/lib/libopenal.so ${POLYCODE_HOME}/Core/Dependencies/lib/libphysfs.a ${POLYCODE_HOME}/Core/Dependencies/lib/libpng15.a ${POLYCODE_HOME}/Core/Dependencies/lib/libz.a -lGL -lGLU -lSDL ${POLYCODE_HOME}/Modules/lib/libPolycode2DPhysics.a ${POLYCODE_HOME}/Modules/Dependencies/lib/libBox2D.a ${POLYCODE_HOME}/Modules/lib/libPolycode3DPhysics.a ${POLYCODE_HOME}/Modules/Dependencies/lib/libBulletDynamics.a ${POLYCODE_HOME}/Modules/Dependencies/lib/libBulletCollision.a ${POLYCODE_HOME}/Modules/Dependencies/lib/libLinearMath.a -lX11

default: Joints

clean:
	rm Joints

Joints:
	$(CC) $(CFLAGS) -I./src ./src/main.cpp src/HelloPolycodeApp.cpp -o Joints $(LDFLAGS)

