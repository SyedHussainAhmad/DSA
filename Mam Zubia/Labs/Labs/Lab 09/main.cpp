#include"MusicPlayer.h"

int main()
{
	Song s{1,"TU JAANE NA", "ATIF ASLAM", "HITS", 3};
	Song s1{2,"TERE BIN", "ARIJIT", "HITS 202", 4};
	MusicPlayer playlist;
	playlist.addSongToPlaylist(s);
	playlist.addSongToPlaylist(s1);
	playlist.displayPlaylist();
	playlist.moveForward();
	playlist.playPlaylist();
	playlist.moveForward();
	cout << "\n";
	playlist.displayCurrentSong();
	cout << "\n";
	playlist.moveBackward();
	cout << "\n";
	playlist.displayCurrentSong();
	cout << "\n";


	playlist.shufflePlaylist();
	playlist.displayPlaylist();

	return 0;
}