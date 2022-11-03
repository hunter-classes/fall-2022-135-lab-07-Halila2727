CXXFLAGS = --coverage -g -O0

main: main.o unindent.o indent.o
	g++ -o $(CIXXFLAGS) main main.o unindent.o indent.o

main.o: main.cpp unindent.h indent.h
	g++ -c main.cpp unindent.h indent.h

unindent.o: unindent.cpp unindent.h
	g++ -c unindent.cpp unindent.h

indent.o: indent.cpp indent.h
	g++ -c indent.cpp indent.h

clean:
	rm -f main.o indent.o unindent.o indent.h.gch unindent.h.gch