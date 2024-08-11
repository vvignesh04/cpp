#include <iostream>
#include <string>

using namespace std;

class Song {
public:
    string title;
    string artist;
    Song* next;
    Song* prev;

    Song(string t, string a) : title(t), artist(a), next(nullptr), prev(nullptr) {}
};

class MusicPlaylist {
private:
    Song* head;
    Song* current; // Pointer to the current song

public:
    MusicPlaylist() : head(nullptr), current(nullptr) {}

    void addSong(const string& title, const string& artist) {
        Song* newSong = new Song(title, artist);
        if (!head) {
            head = newSong;
            head->next = head;
            head->prev = head;
            current = head; // Set the current song to head when the first song is added
        } else {
            Song* tail = head->prev;
            tail->next = newSong;
            newSong->prev = tail;
            newSong->next = head;
            head->prev = newSong;
        }
    }

    void removeSong(const string& title) {
        if (!head) return;

        Song* current = head;
        do {
            if (current->title == title) {
                if (current == head && head->next == head) {
                    delete head;
                    head = nullptr;
                    this->current = nullptr; // Set the current song to nullptr when the last song is removed
                    return;
                }

                Song* prev = current->prev;
                Song* next = current->next;

                prev->next = next;
                next->prev = prev;

                if (current == head) {
                    head = next;
                }

                if (current == this->current) {
                    this->current = next; // Move the current song pointer to the next song
                }

                delete current;
                return;
            }
            current = current->next;
        } while (current != head);
    }

    void displayPlaylist() {
        if (!head) {
            cout << "Playlist is empty.\n";
            return;
        }

        Song* current = head;
        do {
            cout << "Title: " << current->title << ", Artist: " << current->artist << "\n";
            current = current->next;
        } while (current != head);
    }

    Song* selectSong(int index) {
        if (!head) {
            cout << "Playlist is empty.\n";
            return nullptr;
        }

        Song* current = head;
        int count = 0;
        do {
            if (count == index) {
                this->current = current; // Set the current song to the selected song
                cout << "Selected Song:\n";
                cout << "Title: " << current->title << ", Artist: " << current->artist << "\n";
                return current;
            }
            current = current->next;
            count++;
        } while (current != head);

        cout << "Invalid index.\n";
        return nullptr;
    }

    void goToNextSong() {
        if (!current) {
            cout << "Playlist is empty or no song is selected.\n";
            return;
        }

        current = current->next;
        cout << "Next Song:\n";
        cout << "Title: " << current->title << ", Artist: " << current->artist << "\n";
    }

    void goToPrevSong() {
        if (!current) {
            cout << "Playlist is empty or no song is selected.\n";
            return;
        }

        current = current->prev;
        cout << "Previous Song:\n";
        cout << "Title: " << current->title << ", Artist: " << current->artist << "\n";
    }

    ~MusicPlaylist() {
        if (!head) return;

        Song* current = head;
        do {
            Song* next = current->next;
            delete current;
            current = next;
        } while (current != head);

        head = nullptr;
    }
};

int main() {
    MusicPlaylist playlist;

    playlist.addSong("Song 1", "Artist 1");
    playlist.addSong("Song 2", "Artist 2");
    playlist.addSong("Song 3", "Artist 3");

    cout << "Music Playlist:\n";
    playlist.displayPlaylist();

    playlist.removeSong("Song 2");

    cout << "\nAfter removing 'Song 2':\n";
    playlist.displayPlaylist();

    cout << "\nSelecting song at index 1:\n";
    playlist.selectSong(1);

    cout << "\nGoing to the next song:\n";
    playlist.goToNextSong();

    cout << "\nGoing to the previous song:\n";
    playlist.goToPrevSong();

    return 0;
}
