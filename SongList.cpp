//
//  SongList.cpp
//
//  Created by Tara Kreft
//

#include "SongList.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

SongList::SongList(){
    max = maxList;
    listOfSongs = new Song[max];
    songListSize = 0;
}

SongList::SongList(int initMax, const char fileName[]){
    max = initMax;
    listOfSongs = new Song[max];
    songListSize = 0;
    readLibrary(fileName);
}

//destructor
SongList::~SongList(){
    if(listOfSongs != NULL){
        delete [] listOfSongs;
    }
}

//read the song library file
void SongList::readLibrary(const char fileName[]){
        
    ifstream infile;
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    char     tempMins[4];
    int      songSecs;
    char     tempSecs[4];
    char     albumTitle[maxChar];
    int      index;
    char     tempIndex[4];
    Song     addedSong;
        
    infile.open(fileName);
        
    if(!infile){
        infile.clear();
        cout << "Could not open at this time." << endl;
        return;
    }

    while(infile.peek() != EOF){
        infile.get(songTitle, maxChar, ';');
        infile.get();
        infile.get(artistName, maxChar, ';');
        infile.get();
        infile.get(tempMins, 4, ';');
        infile.get();
        infile.get(tempSecs, 4, ';');
        infile.get();
        infile.get(albumTitle, maxChar, ';');
        infile.get();
        infile.get(tempIndex, 4, '\n');
        infile.ignore(100, '\n');
        
        songMins = atoi(tempMins);
        songSecs = atoi(tempSecs);
        index = atoi(tempIndex);
        
        if(songListSize == max){
            resize();
        }
        
        addedSong.setSongTitle(songTitle);
        addedSong.setArtistName(artistName);
        addedSong.setSongMins(songMins);
        addedSong.setSongSecs(songSecs);
        addedSong.setAlbumTitle(albumTitle);
        addedSong.setIndex(index);
      
        addedSong.getSongTitle(songTitle);
        addedSong.getArtistName(artistName);
        addedSong.getSongMins(songMins);
        addedSong.getSongSecs(songSecs);
        addedSong.getAlbumTitle(albumTitle);
        addedSong.getIndex(index);
        
        listOfSongs[songListSize].setSongTitle(songTitle);
        listOfSongs[songListSize].setArtistName(artistName);
        listOfSongs[songListSize].setSongMins(songMins);
        listOfSongs[songListSize].setSongSecs(songSecs);
        listOfSongs[songListSize].setAlbumTitle(albumTitle);
        listOfSongs[songListSize].setIndex(index);
        
        songListSize++;
        
        if(infile.peek() == EOF){
            return;
        }
    }
        
    infile.close();
}

//save song Library file
void SongList::saveLibrary(const char fileName[]) const {
    
    ofstream outfile;
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    int      songSecs;
    char     albumTitle[maxChar];
    int      index;
    
    outfile.open(fileName);
    if(!outfile){
        outfile.clear();
        cout << "Could not open at this time." << endl;
        return;
    }
    
    for(int i = 0; i < songListSize; i++){
        listOfSongs[i].getSongTitle(songTitle);
        listOfSongs[i].getArtistName(artistName);
        listOfSongs[i].getSongMins(songMins);
        listOfSongs[i].getSongSecs(songSecs);
        listOfSongs[i].getAlbumTitle(albumTitle);
        listOfSongs[i].getIndex(index);
        
        outfile << songTitle << ';' << artistName << ';' << songMins << ';' << songSecs << ';' << albumTitle << ';' << index << endl;
    }
    
    outfile.close();
}

//get songListSize
int SongList::getSongListSize() const {
    return songListSize;
}

//change size of songListSize
void SongList::resize(){
    Song *   tempSongList;
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    int      songSecs;
    char     albumTitle[maxChar];
    int      index;
    
    max *= 2;
    tempSongList = new Song[max];
    
    for(int i=0; i<songListSize; i++){
        listOfSongs[i].getSongTitle(songTitle);
        listOfSongs[i].getArtistName(artistName);
        listOfSongs[i].getSongMins(songMins);
        listOfSongs[i].getSongSecs(songSecs);
        listOfSongs[i].getAlbumTitle(albumTitle);
        listOfSongs[i].getIndex(index);
        
        tempSongList[i].setSongTitle(songTitle);
        tempSongList[i].setArtistName(artistName);
        tempSongList[i].setSongMins(songMins);
        tempSongList[i].setSongSecs(songSecs);
        tempSongList[i].setAlbumTitle(albumTitle);
        tempSongList[i].setIndex(index);
    }
    
    delete [] listOfSongs;
    
    listOfSongs = tempSongList;
    tempSongList = NULL;
}

//add a song
void SongList::addSong(){
    
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    int      songSecs;
    char     albumTitle[maxChar];
    Song     addedSong;
    int      index = getSongListSize();
    
    if(songListSize == max){
        resize();
    }
    
    cout << "Please enter the title of the song you are add to the library:";
    cin.getline(songTitle, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the title:" << endl;
        cin.getline(songTitle, maxChar, '\n');
    }
    
    cout << "Please enter the artist's name of the song you are adding to the library:";
    cin.getline(artistName, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the artist's name:" << endl;
        cin.getline(artistName, maxChar, '\n');
    }
    
    cout << "Please enter the minutes of the song you are adding to the library:";
    cin >> songMins;
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Not Valid. Please re-enter the minutes:" << endl;
        cin >> songMins;
    }
    cin.ignore(maxChar, '\n');

    cout << "Please enter the seconds of the song you are adding to the library:";
    cin >> songSecs;
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Not Valid. Please re-enter the seconds:" << endl;
        cin >> songSecs;
    }
    cin.ignore(maxChar, '\n');

    cout << "Please enter the album title of the song you are adding to the library:";
    cin.getline(albumTitle, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the album title:" << endl;
        cin.getline(albumTitle, maxChar, '\n');
    }
    
    addedSong.setSongTitle(songTitle);
    addedSong.setArtistName(artistName);
    addedSong.setSongMins(songMins);
    addedSong.setSongSecs(songSecs);
    addedSong.setAlbumTitle(albumTitle);
    addedSong.setIndex(index);
    
    addedSong.getSongTitle(songTitle);
    addedSong.getArtistName(artistName);
    addedSong.getSongMins(songMins);
    addedSong.getSongSecs(songSecs);
    addedSong.getAlbumTitle(albumTitle);
    addedSong.getIndex(index);

    listOfSongs[songListSize].setSongTitle(songTitle);
    listOfSongs[songListSize].setArtistName(artistName);
    listOfSongs[songListSize].setSongMins(songMins);
    listOfSongs[songListSize].setSongSecs(songSecs);
    listOfSongs[songListSize].setAlbumTitle(albumTitle);
    listOfSongs[songListSize].setIndex(index);
    
    addedSong.printSong();
    
    songListSize++;
}

// remove a song
void SongList::removeSong(){
   
   char     songTitle[maxChar];
   char     artistName[maxChar];
   int      songMins;
   int      songSecs;
   char     albumTitle[maxChar];
   int      index;
   int      removeableIndex;
   bool     indexFound = false;
   
   cout << "Please enter the index of the song that you would like to remove:" << endl;
   cin >> removeableIndex;
   
   while(!cin || removeableIndex >= songListSize){
       cin.clear();
       cin.ignore(100, '\n');
       cout << "That is not a valid index, please try again:" << endl;
       cin >> removeableIndex;
   }
   cin.ignore(maxChar, '\n');

   for(int i = 0; i < songListSize; i++){
       
       if(songListSize == max){
           resize();
       }
       
       if(indexFound == true){
        

           listOfSongs[i + 1].getSongTitle(songTitle);
           listOfSongs[i + 1].getArtistName(artistName);
           listOfSongs[i + 1].getSongMins(songMins);
           listOfSongs[i + 1].getSongSecs(songSecs);
           listOfSongs[i + 1].getAlbumTitle(albumTitle);
           listOfSongs[i + 1].getIndex(index);

           index--;

           listOfSongs[i].setSongTitle(songTitle);
           listOfSongs[i].setArtistName(artistName);
           listOfSongs[i].setSongMins(songMins);
           listOfSongs[i].setSongSecs(songSecs);
           listOfSongs[i].setAlbumTitle(albumTitle);
           listOfSongs[i].setIndex(index);

       } else if(i == removeableIndex){
           indexFound = true;
           
           listOfSongs[i + 1].getSongTitle(songTitle);
           listOfSongs[i + 1].getArtistName(artistName);
           listOfSongs[i + 1].getSongMins(songMins);
           listOfSongs[i + 1].getSongSecs(songSecs);
           listOfSongs[i + 1].getAlbumTitle(albumTitle);
           listOfSongs[i + 1].getIndex(index);

           index--;

           listOfSongs[i].setSongTitle(songTitle);
           listOfSongs[i].setArtistName(artistName);
           listOfSongs[i].setSongMins(songMins);
           listOfSongs[i].setSongSecs(songSecs);
           listOfSongs[i].setAlbumTitle(albumTitle);
           listOfSongs[i].setIndex(index);
       } else {

        cout << "searching by index..." << endl;
       }
   }

      songListSize--;
   
   cout << "the song with index " << removeableIndex << " has been removed." << endl;
   
}

//search by artist
void SongList::searchForArtist() const {
    char searchTerm[maxChar];
    char artistName[maxChar];
    int  matches = 0;
    
    cout << "enter the artist you would like to search for: " << endl;
    
    cin.getline(searchTerm, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the artist:" << endl;
        cin.getline(searchTerm, maxChar, '\n');
    }
    
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    
    for(int i=0; i < songListSize; i++){
        listOfSongs[i].getArtistName(artistName);
        if(strcmp(artistName, searchTerm) == 0){
            matches++;
            listOfSongs[i].printSong();
        }
    }
    
    if(matches == 0){
        cout << "I'm sorry, there are no matches for that artist" << endl;
    }
}

//search by album
void SongList::searchForAlbum() const {
    char searchTerm[maxChar];
    char albumTitle[maxChar];
    int  matches = 0;
    
    cout << "enter the album you would like to search for: " << endl;
    
    cin.getline(searchTerm, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the album:" << endl;
        cin.getline(searchTerm, maxChar, '\n');
    }
    
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    
    for(int i=0; i < songListSize; i++){
        listOfSongs[i].getAlbumTitle(albumTitle);
        if(strcmp(albumTitle, searchTerm) == 0){
            matches++;
            listOfSongs[i].printSong();
        }
    }
    
    if(matches == 0){
        cout << "I'm sorry, there are no matches for that album" << endl;
    }
}

//show all songs
void SongList::displaySongs() const{
    
    char   songTitle[maxChar];
    char   artistName[maxChar];
    int    songMins;
    int    songSecs;
    char   albumTitle[maxChar];
    int    index;
    int    listSize = getSongListSize();
    
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    
    for(int i = 0; i < listSize; i++){
        listOfSongs[i].getSongTitle(songTitle);
        listOfSongs[i].getArtistName(artistName);
        listOfSongs[i].getSongMins(songMins);
        listOfSongs[i].getSongSecs(songSecs);
        listOfSongs[i].getAlbumTitle(albumTitle);
        listOfSongs[i].getIndex(index);
        
        listOfSongs[i].printSong();
        
    }
}











