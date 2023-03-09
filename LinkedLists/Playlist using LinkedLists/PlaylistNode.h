#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

#include <iostream>
using namespace std;

class PlaylistNode {
   public:
      // Constructors
      PlaylistNode();
      PlaylistNode(string initID, string initSongName,
                   string initArtistName, int initSongLength,
                   PlaylistNode* nextLoc = nullptr);

      // Accessor functions
      string GetID() const;
      string GetSongName() const;
      string GetArtistName() const;
      int GetSongLength() const;
      PlaylistNode* GetNext() const;

      // Mutator functions
      void InsertAfter(PlaylistNode* nodePtr);
      void SetNext(PlaylistNode* nodePtr);

      // Additional member functions
      void PrintPlaylistNode() const;

   private:
      string uniqueID;
      string songName;
      string artistName;
      int songLength;
      PlaylistNode* nextNodePtr;
};

#endif

