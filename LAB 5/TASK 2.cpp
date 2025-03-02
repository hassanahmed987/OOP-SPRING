#include <iostream>
#include <string>
using namespace std;

class University {
private:
    int id;
    string name;
    float *examscores;  
    int numScores;  

public:
    University(int rollnum, string names, float scores[], int count) {
        id = rollnum;
        name = names;
        numScores = count;
        examscores = new float[numScores];  

        for (int i = 0; i < numScores; i++) {
            examscores[i] = scores[i];  
        }
    }

    University(const University &obj) {
        id = obj.id;
        name = obj.name;
        numScores = obj.numScores;
        examscores = new float[numScores];  

        for (int i = 0; i < numScores; i++) {
            examscores[i] = obj.examscores[i];  
        }
        cout << "Student " << id << " copied successfully.\n";
    }

    void displayDetails() {
        cout << "ID: " << id << ", Name: " << name << ", Scores: ";
        for (int i = 0; i < numScores; i++) {
            cout << examscores[i] << " ";
        }
        cout << endl;
    }

    ~University() {
        delete[] examscores;  
        
    }
};

int main() {
    float scores[] = {76.9, 82.5, 90.3};

    University s1(1008, "Hassan", scores, 3);
    s1.displayDetails();

    University s2 = s1;
    s2.displayDetails();

    return 0;
}
