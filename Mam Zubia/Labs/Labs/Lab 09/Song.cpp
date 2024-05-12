#include "Song.h"

Song::Song()
{
	songID = 0;
	title = "";
	artist = "";
	album = "";
	durationInSeconds = 0;
}
Song::Song(int id, string ti, string ar, string al, int du)
{
	songID = id;
	title = ti;
	artist = ar;
	album = al;
	durationInSeconds = du;
}
