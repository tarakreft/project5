CC = g++
CPPFLAGS = -Wall -g -std=c++11

make:
	$(CC) -o app project5.cpp Song.cpp SongList.cpp

.PHONY: clean
clean:
	$(info -- cleaning the directory -- )
	rm -f app
