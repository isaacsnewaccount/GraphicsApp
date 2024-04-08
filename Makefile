cxx = g++

#linkFlags = -lglfw3

output: main.o message.o
	$(cxx) main.o message.o -o lookdraw

main.o: main.cpp
	$(cxx) -c main.cpp

message.o: message.cpp message.h
	$(cxx) -c message.cpp

clean:
	rm main.o message.o lookdraw

#	main.cpp message.cpp