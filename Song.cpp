//
//  Song.cpp
//
//  Created by Tara Kreft
//

#include "Song.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

//default constructor
Song::Song(){
    songTitle = new char[strlen("no Title")+1];
    strcpy(songTitle, "no Title");
    artistName = new char[strlen("no Artist")+1];
    strcpy(artistName, "no Artist");
    songMins = 0;
    songSecs = 0;
    albumTitle = new char[strlen("no Album")+1];
    strcpy(albumTitle, "no Album");
    index = 0;
}

//constructor
Song::Song(char songTitle[], char artistName[], int songMins, int songSecs, char albumTitle[], int index){
    this->songTitle = new char[strlen(songTitle)+1];
    strcpy(this->songTitle, songTitle);
    this->artistName = new char[strlen(artistName)+1];
    strcpy(this->artistName, artistName);
    this->songMins = songMins;
    this->songSecs = songSecs;
    this->albumTitle = new char[strlen(albumTitle)+1];
    strcpy(this->albumTitle, albumTitle);
    this->index = index;
}

//destructor
Song::~Song(){
    if(songTitle != NULL){
        delete [] songTitle;
    }
    if(artistName != NULL){
        delete [] artistName;
    }
    if(albumTitle != NULL){
        delete [] albumTitle;
    }

}

//following functions will sets the internal value to the parameter
void Song::getSongTitle(char songTitle[]) const{
    strcpy(songTitle, this->songTitle);
}

void Song::getArtistName(char artistName[]) const{
    strcpy(artistName, this->artistName);
}

void Song::getSongMins(int& songMins) const{
    songMins = this->songMins;
}

void Song::getSongSecs(int& songSecs) const{
    songSecs = this->songSecs;
}

void Song::getAlbumTitle(char albumTitle[]) const{
    strcpy(albumTitle, this->albumTitle);
}

void Song::getIndex(int& index) const{
    index = this->index;
}

//print function
void Song::printSong() const{
    cout << left << setw(maxChar) << songTitle << setw(maxChar) << artistName << setw(7) << songMins << setw(7) << songSecs << setw(maxChar) << albumTitle << setw(5) << index << endl;
}

//following functions set the song values
void Song::setSongTitle(const char songTitle[]){
    if(this->songTitle != NULL){
        delete [] this->songTitle;
    }
    this->songTitle = new char[strlen(songTitle)+1];
    strcpy(this->songTitle, songTitle);
}

void Song::setArtistName(const char artistName[]){
    if(this->artistName != NULL){
        delete [] this->artistName;
    }
    this->artistName = new char[strlen(artistName)+1];
    strcpy(this->artistName, artistName);
}

void Song::setSongMins(const int songMins){
    this->songMins = songMins;
}

void Song::setSongSecs(const int songSecs){
    this->songSecs = songSecs;
}

void Song::setAlbumTitle(const char albumTitle[]){
    if(this->albumTitle != NULL){
        delete [] this->albumTitle;
    }
    this->albumTitle = new char[strlen(albumTitle)+1];
    strcpy(this->albumTitle, albumTitle);
}

void Song::setIndex(const int index){
    this->index = index;
}

