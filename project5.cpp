//  project5.cpp
//
//  Created by Tara Kreft
//

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "Song.h"
#include "SongList.h"

using namespace std;

void runUserChoice(int programChoice, char fileName[], SongList& library);
int displayChoices();

int displayChoices(){
    int usersChoice;
    cout << "\n" << "\n" << "What would you like to do? Please enter a number from the following key:" << endl;
    cout << "1 - view library" << endl;
    cout << "2 - remove song by index" << endl;
    cout << "3 - search for a song by artist" << endl;
    cout << "4 - search for a song by album" << endl;
    cout << "5 - enter a new song to the library" << endl;
    cout << "6 - quit this program" << endl;
    
    cin >> usersChoice;
    cin.clear();
    cin.ignore(100, '\n');
    
    return usersChoice;
}

void runUserChoice(int programChoice, char fileName[], SongList& library){
    
    Song     addedSong;
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    int      songSecs;
    char     albumTitle[maxChar];
    int      index;
    
    switch(programChoice){
        case 1:
            cout << "you have chosen option 1:" << endl;
            library.displaySongs();
            break;
        case 2:
            cout << "you have chosen option 2:" << endl;
           library.removeSong();
            library.saveLibrary(fileName);
            break;
        case 3:
            cout << "you have chosen option 3:" << endl;
            library.searchForArtist();
            break;
        case 4:
            cout << "you have chosen option 4:" << endl;
            library.searchForAlbum();
            break;
        case 5:
            cout << "you have chosen option 5:" << endl;
            library.addSong();
            library.saveLibrary(fileName);
            break;
        case 6:
            cout << endl;
            break;
        default:
            cout <<programChoice << " is an Invalid entry! Try again" << endl;
    }
}

int main()
{
    int      programChoice;
    char     fileName[] = "songs.txt";
    SongList library(fileName);
    
    cout << "Welcome to the music library interface!" << endl;
    
    programChoice = displayChoices();
    
    while(programChoice != 6){
        runUserChoice(programChoice, fileName, library);
        programChoice = displayChoices();
    }
    
    cout << "Thank you for using the music library. Your changes have been saved." << endl;
    
    return 0;
}










