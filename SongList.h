//
//  SongList.h
//
//  Created by Tara Kreft
//

#ifndef SongList_h
#define SongList_h

#include "Song.h"

const int maxList = 100;

//songlist Model
class SongList {
public:
    SongList();
    SongList(int initMax, const char fileName[]);
    
    ~SongList();
    
    void readLibrary(const char fileName[]);
    void saveLibrary(const char fileName[]) const;
    int  getSongListSize() const;
    void addSong();
    void removeSong();
    void searchForArtist() const;
    void searchForAlbum() const;
    void displaySongs() const;
    
private:
    Song * listOfSongs;
    int    songListSize;
    int    max;
    
    void   resize();
};

#endif /* SongList_h */
