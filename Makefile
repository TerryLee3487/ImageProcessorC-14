CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -MMD -Werror=vla
OBJECTS = sepia.o flip.o rotate.o basic.o decorator.o ppm.o exception.o image.o main.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = a4q2

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

clean :
	rm ${DEPENDS} ${OBJECTS} ${EXEC}

-include ${DEPENDS} # reads the .d files and reruns dependencies
