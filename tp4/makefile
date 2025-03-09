Liste-main: Liste-main.o Liste.o Liste_Rapide.o Maillon.o
	g++ -Wall -g -o Liste-main Liste-main.o Liste.o Liste_Rapide.o Maillon.o
Liste_Rapide.o: Liste_Rapide.cpp Liste_Rapide.hpp Liste.hpp
	g++ -Wall -g -c Liste_Rapide.cpp
Liste.o: Liste.cpp Liste.hpp
	g++ -Wall -g -c Liste.cpp
Maillon.o: Maillon.cpp Maillon.hpp
	g++ -Wall -g -c Maillon.cpp
Liste-main.o: Liste-main.cpp Liste.hpp Liste_Rapide.hpp
	g++ -Wall -g -c Liste-main.cpp
clean:
	rm -f *.o
mrproper: clean
	rm -f Liste-main