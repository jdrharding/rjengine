OBJS = rjmain.cpp rjengine.h rjengine.cpp texture.h texture.cpp texturemgr.h texturemgr.cpp sprite.h sprite.cpp event.h eventhandler.h eventhandler.cpp observer.h transportevent.h portal.h

CC = g++

CCFLAGS = -std=c++11

INCLUDE_PATHS = -IE:\Programming\SDLlibs\i686-w64-mingw32\include\SDL2

LIBRARY_PATHS = -LE:\Programming\SDLlibs\i686-w64-mingw32\lib

COMPILER_FLAGS = -w -Wl,-subsystem,console

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

OBJ_NAME = ..\bin\rjmain

all : $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)