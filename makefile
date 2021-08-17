tspsol.exe: tspsol.o
	g++ -o tspsol.exe -g tspsol.o
tspsol.o: tspsol.cpp
	g++ -c -g -Wall tspsol.cpp
clean:
	rm -f tspsol.exe tspsol.o
cleanall:
	rm -f tspsol.exe tspsol.o inputdat* outputdat* nearest*.dat sa*.dat tsp.pdf tspaverage.pdf
