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
    head = NULL;
    tail = NULL;
    songListSize = 0;
}

SongList::SongList(const char fileName[]){
    head = NULL;
    tail = NULL;
    songListSize = 0;
    readLibrary(fileName);
}

//destructor
SongList::~SongList(){
    Node * current = head;
    
    while(head != NULL){
        current = head->next;
        delete head;
        head = current;
    }
}

//read the song library file
void SongList::readLibrary(const char fileName[]){
        
    ifstream infile;
    char     currentSongTitle[maxChar];
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    char     tempMins[4];
    int      songSecs;
    char     tempSecs[4];
    char     albumTitle[maxChar];
    int      index = 0;
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
        infile.ignore(100, '\n');
        
        songMins = atoi(tempMins);
        songSecs = atoi(tempSecs);
        
        addedSong.setSongTitle(songTitle);
        addedSong.setArtistName(artistName);
        addedSong.setSongMins(songMins);
        addedSong.setSongSecs(songSecs);
        addedSong.setAlbumTitle(albumTitle);
        addedSong.setIndex(index);
    
        Node * newNode = new Node(addedSong);
        Node * previous = NULL;
        Node * current = head;
        
        while(current){
            current->data.getSongTitle(currentSongTitle);
            if(strcmp(songTitle, currentSongTitle) < 0){
                break;
            }
            
            previous = current;
            current = current->next;
        }
        
        newNode->next = current;
        
        if(!previous){
            head = newNode;
        }else{
            previous->next = newNode;
        }
        
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
    Node *   current;
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
    
    for(current = head; current; current=current->next){
        current->data.getSongTitle(songTitle);
        current->data.getArtistName(artistName);
        current->data.getSongMins(songMins);
        current->data.getSongSecs(songSecs);
        current->data.getAlbumTitle(albumTitle);
        current->data.getIndex(index);
        
        outfile << songTitle << ';' << artistName << ';' << songMins << ';' << songSecs << ';' << albumTitle << ';' << index << endl;
    }
    
    outfile.close();
}

//get songListSize
int SongList::getSongListSize() const {
    return songListSize;
}

//add a song
void SongList::addSong(){
    
    char     currentSongTitle[maxChar];
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    int      songSecs;
    char     albumTitle[maxChar];
    Song     addedSong;
    int      index = getSongListSize();
    
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
    
    Node * newNode = new Node(addedSong);
    Node * previous = NULL;
    Node * current = head;
    
    while(current){
        current->data.getSongTitle(currentSongTitle);
        if(strcmp(songTitle, currentSongTitle) < 0){
            break;
        }
        
        previous = current;
        current = current->next;
    }
    
    newNode->next = current;
    
    if(!previous){
        head = newNode;
    }else{
        previous->next = newNode;
    }
    
    songListSize++;
    
    addedSong.printSong();
}

// remove a song
void SongList::removeSong(){
   Node *   current = head;
   Node *   previous = NULL;
   int      count = 0;
   int      removeableIndex;

   
   cout << "Please enter the index of the song that you would like to remove:" << endl;
   cin >> removeableIndex;
   
   while(!cin || removeableIndex >= songListSize){
       cin.clear();
       cin.ignore(100, '\n');
       cout << "That is not a valid index, please try again:" << endl;
       cin >> removeableIndex;
   }
   cin.ignore(maxChar, '\n');

    while(current && count < removeableIndex){
        previous = current;
        current = current->next;
        count++;
    }
    
    if(!previous){
        head = current->next;
    }else if(current == tail){
        previous->next = current->next;
        tail = previous;
    }else{
        previous->next = current->next;
    }
    
    delete current;
    current = NULL;
    previous = NULL;

    songListSize--;
   
   cout << "the song with index " << removeableIndex << " has been removed." << endl;
   
}

//search by artist
void SongList::searchForArtist() const {
    Node * current;
    char   searchTerm[maxChar];
    char   artistName[maxChar];
    int    matches = 0;
    
    cout << "enter the artist you would like to search for: " << endl;
    
    cin.getline(searchTerm, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the artist:" << endl;
        cin.getline(searchTerm, maxChar, '\n');
    }
    
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    
    for(current=head; current!=NULL; current=current->next){
        current->data.getArtistName(artistName);
        if(strcmp(artistName, searchTerm) == 0){
            matches++;
            current->data.printSong();
        }
    }
    
    if(matches == 0){
        cout << "I'm sorry, there are no matches for that artist" << endl;
    }
}

//search by album
void SongList::searchForAlbum() const {
    Node * current;
    char   searchTerm[maxChar];
    char   albumTitle[maxChar];
    int    matches = 0;
    
    cout << "enter the album you would like to search for: " << endl;
    
    cin.getline(searchTerm, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the album:" << endl;
        cin.getline(searchTerm, maxChar, '\n');
    }
    
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    
    for(current=head; current!=NULL; current = current->next){
        current->data.getAlbumTitle(albumTitle);
        if(strcmp(albumTitle, searchTerm) == 0){
            matches++;
            current->data.printSong();
        }
    }
    
    if(matches == 0){
        cout << "I'm sorry, there are no matches for that album" << endl;
    }
}

//show all songs
void SongList::displaySongs() const{
    
    Node * current;
    char   songTitle[maxChar];
    char   artistName[maxChar];
    int    songMins;
    int    songSecs;
    char   albumTitle[maxChar];
    int    index;
    int    listSize = getSongListSize();
    int    counter = 0;
    
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    
    for(current=head; current; current=current->next){
        current->data.getSongTitle(songTitle);
        current->data.getArtistName(artistName);
        current->data.getSongMins(songMins);
        current->data.getSongSecs(songSecs);
        current->data.getAlbumTitle(albumTitle);
        current->data.setIndex(counter);
        current->data.getIndex(index);
        counter++;
        current->data.printSong();
        
    }
}











