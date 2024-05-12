#ifndef SONG_H
#define SONG_H
#include<string>
using namespace std;

class Song
{
public:
	int songID;
	string title;
	string artist;
	string album;
	int durationInSeconds;
	Song();
	Song(int id, string ti,string ar,string al,int du);
};
#endif // !SONG_H
