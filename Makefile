CXXFLAGS = Wall –Wpedantic –O2

main: main.o unindent.o indent.o
	g++ -o main main.o unindent.o indent.o

main.o: main.cpp unindent.h indent.h
	g++ $(CIXXFLAGS) -c main.cpp unindent.h indent.h

unindent.o: unindent.cpp unindent.h
	g++ $(CIXXFLAGS) -c unindent.cpp unindent.h

indent.o: indent.cpp indent.h
	g++ $(CIXXFLAGS) -c indent.cpp indent.h

clean:
	rm -f main.o indent.o unindent.o indent.h.gch unindent.h.gch