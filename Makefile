output: main.o message.o
	g++ main.o message.o -o lookdraw

main.o: main.cpp
	g++ -c main.cpp

message.o: message.cpp message.h
	g++ -c message.cpp

clean:
	rm main.o message.o lookdraw

#	main.cpp message.cpp