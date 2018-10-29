
SwordQuest: main.o Game.o Space.o Space1.o Space2.o Space3.o Space4.o Space5.o Space6.o Space7.o Space8.o Space9.o Space10.o Space11.o Space12.o Space13.o Space14.o Space15.o Space16.o Space17.o Space18.o Space19.o Space20.o Space21.o Space22.o Space23.o Space24.o Space25.o Characters.o Container.o Objects.o 
	g++ main.cpp Game.cpp Space.cpp Space1.cpp Space2.cpp Space3.cpp Space4.cpp Space5.cpp Space6.cpp Space7.cpp Space8.cpp Space9.cpp Space10.cpp Space11.cpp Space12.cpp Space13.cpp Space14.cpp Space15.cpp Space16.cpp Space17.cpp Space18.cpp Space19.cpp Space20.cpp Space21.cpp Space22.cpp Space23.cpp Space24.cpp Space25.cpp Characters.cpp Container.cpp Objects.cpp -o SwordQuest

main.o: main.cpp
	g++ -c main.cpp

Game.o: Game.hpp Game.cpp
	g++ -c Game.cpp

Space.o: Space.hpp Space.cpp
	g++ -c Space.cpp

Space1.o: Space1.hpp Space1.cpp
	g++ -c Space1.cpp

Space2.o: Space2.hpp Space2.cpp
	g++ -c Space2.cpp

Space3.o: Space3.hpp Space3.cpp
	g++ -c Space3.cpp

Space4.o: Space4.hpp Space4.cpp
	g++ -c Space4.cpp

Space5.o: Space5.hpp Space5.cpp
	g++ -c Space5.cpp

Space6.o: Space6.hpp Space6.cpp
	g++ -c Space6.cpp

Space7.o: Space7.hpp Space7.cpp
	g++ -c Space7.cpp

Space8.o: Space8.hpp Space8.cpp
	g++ -c Space8.cpp

Space9.o: Space9.hpp Space9.cpp
	g++ -c Space9.cpp

Space10.o: Space10.hpp Space10.cpp
	g++ -c Space10.cpp

Space11.o: Space11.hpp Space11.cpp
	g++ -c Space11.cpp

Space12.o: Space12.hpp Space12.cpp
	g++ -c Space12.cpp

Space13.o: Space13.hpp Space13.cpp
	g++ -c Space13.cpp

Space14.o: Space14.hpp Space14.cpp
	g++ -c Space14.cpp

Space15.o: Space15.hpp Space15.cpp
	g++ -c Space15.cpp

Space16.o: Space16.hpp Space16.cpp
	g++ -c Space16.cpp

Space17.o: Space17.hpp Space17.cpp
	g++ -c Space17.cpp

Space18.o: Space18.hpp Space18.cpp
	g++ -c Space18.cpp

Space19.o: Space19.hpp Space19.cpp
	g++ -c Space19.cpp

Space20.o: Space20.hpp Space20.cpp
	g++ -c Space20.cpp

Space21.o: Space21.hpp Space21.cpp
	g++ -c Space21.cpp

Space22.o: Space22.hpp Space22.cpp
	g++ -c Space22.cpp

Space23.o: Space23.hpp Space23.cpp
	g++ -c Space23.cpp

Space24.o: Space24.hpp Space24.cpp
	g++ -c Space24.cpp

Space25.o: Space25.hpp Space25.cpp
	g++ -c Space25.cpp

Characters.o: Characters.hpp Characters.cpp
	g++ -c Characters.cpp

Container.o: Container.hpp Container.cpp
	g++ -c Container.cpp

Objects.o: Objects.hpp Objects.cpp
	g++ -c Objects.cpp

clean:
	rm *.o SwordQuest
