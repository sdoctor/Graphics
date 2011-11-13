INCFLAGS = -I/Users/sdrakeley/Dropbox/classes/11Fall/6-837/vecmath
LINKFLAGS = -L/Users/sdrakeley/Dropbox/classes/11Fall/6-837/vecmath -lvecmath -lm
CFLAGS    = -g -Wall -Wextra -Wno-unused-parameter -ansi -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC #debugging compiler commands
CC = clang++
SRCS = main.cpp Image.cpp SceneParser.cpp OrthoCamera.cpp PerspectiveCamera.cpp Triangle.cpp Plane.cpp Sphere.cpp Group.cpp
OBJS = $(SRCS:.cpp=.o)
PROG = a4

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LINKFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -c -o $@ $(INCFLAGS)

clean:
	rm -f *.bak *.o core.* $(PROG) 
