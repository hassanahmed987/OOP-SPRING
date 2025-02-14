#include <iostream>
#include <string>
using namespace std;

class FitnessTracker {
private:
    string userName;
    int dailyStepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
        FitnessTracker(string name, int goal) {
        userName = name;
        dailyStepGoal = goal;
        stepsTaken = 0;
        caloriesBurned = 0.0;
    }

    void logSteps(int steps) {
        if (steps > 0) {
            stepsTaken += steps;
            caloriesBurned += steps * 0.04;
            cout << steps << " steps logged." << endl;
        } else {
            cout << "Invalid number of steps!" << endl;
        }
    }

    bool checkGoal() {
        return stepsTaken >= dailyStepGoal;
    }

    void displayProgress() {
        cout << "Fitness Progress for " << userName << " today:" << endl;
        cout << "Steps taken: " << stepsTaken << " / " << dailyStepGoal << endl;
        cout << "Calories burned: " << caloriesBurned << " kcal" << endl;

        if (checkGoal()) {
            cout << "Congratulations! You met your daily step goal!" << endl;
        } else {
            cout << "Keep going! You haven't met your goal yet." << endl;
        }
    }
};
int main() {
    FitnessTracker laiba("Laiba", 10000);
    laiba.logSteps(3000);  
    laiba.logSteps(4000);  
    laiba.logSteps(2500);  
    laiba.displayProgress();
    return 0;
}
