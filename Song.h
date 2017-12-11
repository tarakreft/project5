//
//  Song.h
//
//  Created by Tara Kreft
//

#ifndef Song_h
#define Song_h

const int maxChar = 20;

//class song model
class Song {
public:
    Song();
    Song(char songTitle[], char artistName[], int songMins, int songSecs, char albumTitle[], int index);
    
    ~Song();
    
    void getSongTitle(char songTitle[]) const;
    void getArtistName(char artistName[]) const;
    void getSongMins(int& songMins) const;
    void getSongSecs(int& songSecs) const;
    void getAlbumTitle(char albumtTitle[]) const;
    void getIndex(int& index) const;
    void printSong() const;
    
    void setSongTitle(const char songTitle[]);
    void setArtistName(const char artistName[]);
    void setSongMins(const int songMins);
    void setSongSecs(const int songSecs);
    void setAlbumTitle(const char albumtTitle[]);
    void setIndex(const int index);
    
private:
    char *  songTitle;
    char *  artistName;
    int     songMins;
    int     songSecs;
    char *  albumTitle;
    int     index;
};

#endif /* Song_h */
