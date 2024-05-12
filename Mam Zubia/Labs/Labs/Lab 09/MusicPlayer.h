#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include"DoubleLinkedList.h"
#include"Song.h"

class MusicPlayer
{
	DoubleLinkedList<Song> playlist;
	DNode<Song>* currentSongNode;
public:
	MusicPlayer();
	void addSongToPlaylist(const Song & song);
	void removeSongFromPlaylist(int songId);
	void playPlaylist();
	void moveForward();
	void moveBackward();
	void displayPlaylist();
	void displayCurrentSong();
	void shufflePlaylist();
	void mergePlaylists(DoubleLinkedList<Song> & playlist2);
	void deleteNthSongFromEnd(int n);
};

MusicPlayer::MusicPlayer()
{
	currentSongNode = nullptr;
}

inline void MusicPlayer::addSongToPlaylist(const Song& song)
{
	if (currentSongNode == nullptr)
	{
		currentSongNode = playlist.head;
	}
	playlist.addToTail(song);
}

inline void MusicPlayer::removeSongFromPlaylist(int songId)
{
	DNode<Song>* current = playlist.head;
	bool findFlag = false;
	while (current != nullptr && !findFlag)
	{
		if (current->data.songID == songId)
		{
			if (current == currentSongNode)
			{
				currentSongNode = currentSongNode->next;
			}

			if (current == playlist.head)
			{
				current->next->prev = nullptr;
				playlist.head = current->next;
			}
			else if (current == playlist.tail)
			{
				current->prev->next = nullptr;
				playlist.tail = current->prev;
			}
			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}

			delete current;
			findFlag = true;
		}
		current = current->next;
	}
}

inline void MusicPlayer::playPlaylist()
{
	cout << "Playing Playlist:\n";
	DNode<Song>* temp = currentSongNode;
	while (temp != nullptr)
	{
		cout << temp->data.title << " ";
		temp = temp->next;
	}
}

inline void MusicPlayer::moveForward()
{
	if (currentSongNode->next!=nullptr)
	{
		currentSongNode = currentSongNode->next;
	}
}

inline void MusicPlayer::moveBackward()
{
	if (currentSongNode->prev)
	{
		currentSongNode = currentSongNode->prev;
	}
}

inline void MusicPlayer::displayPlaylist()
{
	cout << "The playlist contains following songs:\n";
	DNode<Song>* temp = playlist.head;
	while (temp != nullptr)
	{
		cout << temp->data.title << "\n";
		temp = temp->next;
	}
}

inline void MusicPlayer::displayCurrentSong()
{
	cout << "Current Song is:" << '\t';
	cout << currentSongNode->data.title;
}

inline void MusicPlayer::shufflePlaylist()
{
	int index = 0;
	DNode<Song>* current = playlist.head;
	playlist.head = current->next;
	DNode<Song>* temp;
	while (current != nullptr)
	{
		if (index%2==0 && current->next!=nullptr)
		{
			temp = current->next;
			current->next = current->next->next;
			temp->next = current;
		}
		current = current->next;
		index++;
	}
}

inline void MusicPlayer::deleteNthSongFromEnd(int n)
{
	DNode<Song>* current = playlist.tail;
	if (n<0)
	{
		return;
	}
	else if(n==1)
	{
		current->prev->next = nullptr;
		playlist.tail = current->prev;
		delete current;
	}
	int index = 1;
	bool findFlag = false;
	while (current != nullptr && !findFlag)
	{
		if (index == n)
		{
			if (current == currentSongNode)
			{
				currentSongNode = currentSongNode->prev;
			}
			if (current == playlist.head)
			{
				current->next->prev = nullptr;
				playlist.head = current->next;
			}
			else if (current == playlist.tail)
			{
				current->prev->next = nullptr;
				playlist.tail = current->prev;
			}
			else
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;
			}
			delete current;
			findFlag = true;
		}
		index++;
		current = current->prev;
	}
}

inline void MusicPlayer::mergePlaylists(DoubleLinkedList<Song>& other)
{
	DoubleLinkedList<Song> mergedList;

	DNode<Song>* current1 = playlist.head;
	DNode<Song>* current2 = other.head;

	while (current1 != nullptr && current2 != nullptr)
	{
		if (current1->data.songID <= current2->data.songID)
		{
			mergedList.addToTail(current1->data);
			current1 = current1->next;
		}
		else
		{
			mergedList.addToTail(current2->data);
			current2 = current2->next;
		}
	}

	while (current1 != nullptr)
	{
		mergedList.addToTail(current1->data);
		current1 = current1->next;
	}

	while (current2 != nullptr)
	{
		mergedList.addToTail(current2->data);
		current2 = current2->next;
	}
}

#endif // !MUSIC_PLAYER_H
