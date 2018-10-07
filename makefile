
myspeller: main.o enquiry.o incomplete2.o
	g++ main.o enquiry.o incomplete2.o -o myspeller
	
main.o: main.cpp
	g++ -c main.cpp

enquiry.o: enquiry.cpp
	g++ -c enquiry.cpp

incomplete.o: incomplete2.cpp
	g++ -c incomplete2.cpp

clean:
	rm *.o myspeller