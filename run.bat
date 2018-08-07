g++ -c Source/td.cpp -o Source/td.o -ISFML/SFML/include
g++ Source/td.o -o Test.exe -LSFML/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system