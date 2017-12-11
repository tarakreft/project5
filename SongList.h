//
//  SongList.h
//
//  Created by Tara Kreft
//

#ifndef SongList_h
#define SongList_h

#include "Song.h"

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
    
    struct Node {
        
        Song   data;
        Node * next;
        
        Node(const Song& songData){
            char     songTitle[maxChar];
            char     artistName[maxChar];
            int      songMins;
            int      songSecs;
            char     albumTitle[maxChar];
            int      index;
            
            songData.getSongTitle(songTitle);
            songData.getArtistName(artistName);
            songData.getSongMins(songMins);
            songData.getSongSecs(songSecs);
            songData.getAlbumTitle(albumTitle);
            songData.getIndex(index);
            
            songData.setSongTitle(songTitle);
            songData.setArtistName(artistName);
            songData.setSongMins(songMins);
            songData.setSongSecs(songSecs);
            songData.setAlbumTitle(albumTitle);
            songData.setIndex(index);
            
            next = NULL;
            
        }
    };
    
    Node * head;
    Node * tail;
    int    songListSize;
    
};

#endif /* SongList_h */
