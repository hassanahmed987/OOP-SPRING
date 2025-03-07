#include <iostream>
#include <string>
using namespace std;

class Level {
private:
    string levelName;
    int difficulty;
public:
    Level() {} 

    Level(string name, int diff) {
        levelName = name;
        difficulty = diff;
    }

    void displayLevel() {
        cout << "Level: " << levelName << ", Difficulty: " << difficulty << endl;
    }
};

class VideoGame {
private:
    string title;
    string genre;
    Level* levels;  
    int levelCount;
public:
    VideoGame(string gameTitle, string gameGenre, int numLevels) {
        title = gameTitle;
        genre = gameGenre;
        levelCount = numLevels;
        levels = new Level[levelCount]; 
    }

    ~VideoGame() {
        delete[] levels; 
    }

    void addLevel(int index, string name, int difficulty) {
        if (index >= 0 && index < levelCount) {
            levels[index] = Level(name, difficulty);
        } else {
            cout << "Invalid level index!" << endl;
        }
    }

    void displayGameDetails() {
        cout << "Game: " << title << "   Genre: " << genre << endl;
        cout << "Levels in the game:" << endl;
        for (int i = 0; i < levelCount; i++) {
            levels[i].displayLevel();
        }
    }
};

int main() {
    VideoGame game("call of duty", "shooter", 3);

    game.addLevel(0, "The white house", 3);
    game.addLevel(1, "secret mission", 5);
    game.addLevel(2, "Dragon's Lair", 7);

    game.displayGameDetails();

    return 0;
}
