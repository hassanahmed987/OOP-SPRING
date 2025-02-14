#include <iostream>
#include <string>

using namespace std;

class MusicPlayer {
private:
    string playlist[100];
    int songCount;
    string currentlyPlayingSong;

public:
    MusicPlayer() {
        songCount = 0;
    }

    void addSong(const string& song) {
        if (songCount < 100) {
            playlist[songCount++] = song;
            cout << "Added: " << song << " to the playlist.\n";
        } else {
            cout << "Playlist is full. Cannot add more songs.\n";
        }
    }

    void removeSong(const string& song) {
        int index = -1;
        for (int i = 0; i < songCount; i++) {
            if (playlist[i] == song) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            for (int i = index; i < songCount - 1; i++) {
                playlist[i] = playlist[i + 1];
            }
            songCount--;
            cout << "Removed: " << song << " from the playlist.\n";
        } else {
            cout << "Song not found in the playlist.\n";
        }
    }

    void playSong(const string& song) {
        bool found = false;
        for (int i = 0; i < songCount; i++) {
            if (playlist[i] == song) {
                found = true;
                break;
            }
        }
        if (found) {
            currentlyPlayingSong = song;
            cout << "Now playing: " << song << "\n";
        } else {
            cout << "Song not found in the playlist.\n";
        }
    }

    void displayPlaylist() {
        if (songCount == 0) {
            cout << "Playlist is empty.\n";
            return;
        }
        cout << "Playlist: \n";
        for (int i = 0; i < songCount; i++) {
            cout << "- " << playlist[i] << "\n";
        }
    }
};

int main() {
    MusicPlayer player;

    player.addSong("Song A");
    player.addSong("Song B");
    player.addSong("Song C");

    player.displayPlaylist();

    player.playSong("Song B");
    player.removeSong("Song A");
    player.displayPlaylist();

    return 0;
}
