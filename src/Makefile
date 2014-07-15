OBJS = rjmain.cpp rjengine.h rjengine.cpp

CC = g++

INCLUDE_PATHS = -IE:\Programming\SDLlibs\i686-w64-mingw32\include\SDL2

LIBRARY_PATHS = -LE:\Programming\SDLlibs\i686-w64-mingw32\lib

COMPILER_FLAGS = -w -Wl,-subsystem,console

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

OBJ_NAME = ..\bin\rjmain

all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)