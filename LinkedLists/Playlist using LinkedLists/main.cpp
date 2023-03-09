#include <iostream>

#include "PlaylistNode.cpp"

using namespace std;

void ClearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}



void PrintMenu(const string playlistTitle) {
   cout << playlistTitle << " PLAYLIST MENU" << endl;
   cout << "a - Add song" << endl;
   cout << "d - Remove song" << endl;
   cout << "c - Change position of song" << endl;
   cout << "s - Output songs by specific artist" << endl;
   cout << "t - Output total time of playlist (in seconds)" << endl;
   cout << "o - Output full playlist" << endl;
   cout << "q - Quit" << endl << endl;
   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   string uniqueID, songName, artistName;
   int songLength, currPos, newPos, totalSeconds = 0, count = 1;
   PlaylistNode* tmpNodePtr = nullptr;
   PlaylistNode* songNodePtr = nullptr;
   PlaylistNode* prevNodePtr = nullptr;
   // PlaylistNode* node1Ptr = nullptr;
   // PlaylistNode* node2Ptr = nullptr;
   // PlaylistNode* node3Ptr = nullptr;
   // PlaylistNode* node4Ptr = nullptr;

   switch(option) {
      
            case 'q':
         break;
         
         
      case 'a':
      {
                  cout << "ADD SONG" << endl;
         cout << "Enter song's unique ID:" << endl;
         cin >> uniqueID;
         cout << "Enter song's name:" << endl;
         cin.ignore();
         getline(cin, songName);
         cout << "Enter artist's name:" << endl;
         getline(cin, artistName);
         cout << "Enter song's length (in seconds):";
         cout << endl;
         cin >> songLength;
         cout<<endl;

         tmpNodePtr = new PlaylistNode(uniqueID, songName, artistName, songLength);
         if (headNode == nullptr) {
            headNode = tmpNodePtr;
         }
         else {
            prevNodePtr = headNode;
            while (prevNodePtr->GetNext() != nullptr) {
               prevNodePtr = prevNodePtr->GetNext();
            }
            prevNodePtr->InsertAfter(tmpNodePtr);
         }
       //  cout << "\"" << songName << "\" added to playlist." << endl << endl;
         break;
      }


      case 'd':
      {
         cout << "REMOVE SONG" << endl;
         cout << "Enter song's unique ID:" << endl;
         cin >> uniqueID;

         tmpNodePtr = headNode;
         prevNodePtr = nullptr;
         while (tmpNodePtr != nullptr && tmpNodePtr->GetID() != uniqueID) {
            prevNodePtr = tmpNodePtr;
            tmpNodePtr = tmpNodePtr->GetNext();
         }

         if (tmpNodePtr != nullptr) {
            songNodePtr = tmpNodePtr;
            if (prevNodePtr != nullptr) {
               prevNodePtr->SetNext(tmpNodePtr->GetNext());
            }
            else {
               headNode = tmpNodePtr->GetNext();
            }
            delete songNodePtr;
            cout << "\"" << songNodePtr->GetSongName() << "\" removed." << endl << endl;
         }
         else {
            cout << "Song with unique ID \"" << uniqueID << "\" not found in playlist." << endl << endl;
         }
         break;
      }
      
         

     case 'c':
      {
         cout << "CHANGE POSITION OF SONG" << endl;
         cout << "Enter song's current position:" << endl;
         cin >> currPos;
         cout << "Enter new position for song:" << endl;
         cin >> newPos;

         int count = 1;
         PlaylistNode* node1Ptr = nullptr;
         PlaylistNode* node2Ptr = nullptr;
         PlaylistNode* node3Ptr = nullptr;
         PlaylistNode* node4Ptr = nullptr;
         PlaylistNode* prevNodePtr = nullptr;
         PlaylistNode* tmpNodePtr = headNode;

         while (tmpNodePtr != nullptr) {
            if (count == currPos) {
               node1Ptr = prevNodePtr;
               node2Ptr = tmpNodePtr;
            }
            if (count == newPos) {
               node3Ptr = tmpNodePtr;
               node4Ptr = tmpNodePtr->GetNext();
            }
            prevNodePtr = tmpNodePtr;
            tmpNodePtr = tmpNodePtr->GetNext();
            count++;
         }
         if (node1Ptr == nullptr && node3Ptr == headNode) {
            headNode = node2Ptr;
            node1Ptr = headNode;
         }
         else if (node1Ptr == nullptr && node3Ptr != headNode) {
            node2Ptr->SetNext(node4Ptr);
            node3Ptr->InsertAfter(node2Ptr);
            headNode = node3Ptr;
         }
         else if (node2Ptr->GetNext() == node3Ptr) {
            node2Ptr->SetNext(node4Ptr);
            node3Ptr->SetNext(node2Ptr);
         }
         else if (node3Ptr == nullptr) {
            node1Ptr->SetNext(node2Ptr->GetNext());
            node2Ptr->SetNext(nullptr);
            prevNodePtr = headNode;
            while (prevNodePtr->GetNext() != nullptr) {
               prevNodePtr = prevNodePtr->GetNext();
            }
            prevNodePtr->SetNext(node2Ptr);
         }
         else {
            node1Ptr->SetNext(node2Ptr->GetNext());
            node2Ptr->SetNext(node4Ptr);
            node3Ptr->InsertAfter(node2Ptr);
         }
         cout << "\"" << node2Ptr->GetSongName() << "\" moved to position " << newPos << endl << endl;
         break;
      }

         

      case 's':
         {
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
         cout << "Enter artist's name:" << endl;
         cout<< endl;
         cin.ignore();
         getline(cin, artistName);

         tmpNodePtr = headNode;
         count = 1;
         while (tmpNodePtr != nullptr) {
            if (tmpNodePtr->GetArtistName() == artistName) {
               cout << count << "." << endl;
               tmpNodePtr->PrintPlaylistNode();
               cout << endl;
            }
            tmpNodePtr = tmpNodePtr->GetNext();
            count++;
         }
         break;
         }

      case 't':
      {
         cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
         tmpNodePtr = headNode;
         while (tmpNodePtr != nullptr) {
            totalSeconds += tmpNodePtr->GetSongLength();
            tmpNodePtr = tmpNodePtr->GetNext();
         }
         cout << "Total time: " << totalSeconds << " seconds" << endl << endl;
         break;
      }
         

      case 'o':
      {
          cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
         tmpNodePtr = headNode;
         count = 1;
         if (tmpNodePtr == nullptr) {
            cout << "Playlist is empty" << endl << endl;
         }
         else {
            while (tmpNodePtr != nullptr) {
               cout << count << "." << endl;
               tmpNodePtr->PrintPlaylistNode();
               cout << endl;
               tmpNodePtr = tmpNodePtr->GetNext();
               count++;
            }
         }
         break;
      }
        



      default:
         cout << "Invalid choice. Please enter a valid choice" << endl;
                  break;
   }
   //ClearConsole();
   return headNode;
}

int main() {
   string playlistTitle;
   char menuChoice;
   PlaylistNode* headNode = nullptr;

   cout << "Enter playlist's title:" << endl;
   getline(cin, playlistTitle);
   cout << endl;

   menuChoice = ' ';
   while (menuChoice != 'q') {
      PrintMenu(playlistTitle);
      cout << "Choose an option:" << endl;
      cin >> menuChoice;
   //   cout << endl;
      headNode = ExecuteMenu(menuChoice, playlistTitle, headNode);
   }

   return 0;
}

