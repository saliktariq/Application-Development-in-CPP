#include "PlaylistNode.h"

// Default constructor
PlaylistNode::PlaylistNode() {
   uniqueID = "none";
   songName = "none";
   artistName = "none";
   songLength = 0;
   nextNodePtr = nullptr;
}

// Parameterized constructor
PlaylistNode::PlaylistNode(string initID, string initSongName,
                           string initArtistName, int initSongLength,
                           PlaylistNode* nextLoc) {
   uniqueID = initID;
   songName = initSongName;
   artistName = initArtistName;
   songLength = initSongLength;
   nextNodePtr = nextLoc;
}

// Accessor functions
string PlaylistNode::GetID() const {
   return uniqueID;
}

string PlaylistNode::GetSongName() const {
   return songName;
}

string PlaylistNode::GetArtistName() const {
   return artistName;
}

int PlaylistNode::GetSongLength() const {
   return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
   return nextNodePtr;
}

// Mutator functions
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
   PlaylistNode* tmpNext = nextNodePtr;
   nextNodePtr = nodePtr;
   nodePtr->nextNodePtr = tmpNext;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
   nextNodePtr = nodePtr;
}

// Additional member functions
void PlaylistNode::PrintPlaylistNode() const {
   cout << "Unique ID: " << uniqueID << endl;
   cout << "Song Name: " << songName << endl;
   cout << "Artist Name: " << artistName << endl;
   cout << "Song Length (in seconds): " << songLength << endl;
}
