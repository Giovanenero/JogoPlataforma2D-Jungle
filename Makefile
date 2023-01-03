all: compile link execute clean

compile:
	g++ -c Jungle++\src\*.cpp Jungle++\src\Entidade\*.cpp Jungle++\src\Entidade\Personagem\*.cpp Jungle++\src\Entidade\Personagem\Jogador\*.cpp Jungle++\src\Entidade\Personagem\Inimigo\*.cpp Jungle++\src\Entidade\Personagem\Inimigo\Chefao\*.cpp Jungle++\src\Gerenciador\*.cpp Jungle++\src\Lista\*.cpp Jungle++\src\Entidade\Obstaculo\*.cpp Jungle++\src\Animador\*.cpp Jungle++\src\Parallax\*.cpp Jungle++\src\Fase\*.cpp Jungle++\src\Estado\*.cpp Jungle++\src\Construtor\*.cpp Jungle++\src\Menu\*.cpp Jungle++\src\Menu\Botao\*.cpp Jungle++\src\Observador\*.cpp -I"SFML\include"

link:
	g++ *.o -Wall -o main -L"SFML\lib" -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

execute: 
	.\main.exe

clean:
	del *.o
	cls