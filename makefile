all:
	g++ main.cpp ipp.cpp -o ipp
	./ipp
clean:
	rm -f ipp
