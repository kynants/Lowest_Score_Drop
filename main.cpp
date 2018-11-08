#include <iostream>
using namespace std;

// Variables
int testScore[4],
    testCount = 0,
    avgScore = 0,
    numOfTests = 0,
    countGetScore = 0;

void getScore() // Prompts user to enter each iteration of test scores.
{
    cout << "Enter the student's test score: ";
    cin >> testScore[testCount];
    while (testScore[testCount] < 0 || testScore[testCount] > 100) {
        cout << "Error! Test score must be within range of 0-100.\n";
        cout << "Enter the correct test score: ";
        cin >> testScore[testCount];
    }
    avgScore += testScore[testCount];   // Adds test score to the sum.
    testCount += 1;                     // Counts through testScore array.
    numOfTests += 1;                    // Adds tests to the sum.
    countGetScore += 1;                 // Counts 4 times getScore() is ran.
}


void calcAverage()  // Calculates the average of all the test scores.
{
    cout << "Average Score of Tests: " << avgScore / numOfTests << endl;
}


int findLowest()    // Finds the lowest test score.
{
    int lowestScore; // Used to compare scores and find the lowest.

    if (testScore[0] < testScore[1] &&
        testScore[0] < testScore[2] &&
        testScore[0] < testScore[3]) {
        lowestScore = testScore[0];
    } else if (testScore[1] < testScore[0] &&
               testScore[1] < testScore[2] &&
               testScore[1] < testScore[3]) {
        lowestScore = testScore[1];
    } else if (testScore[2] < testScore[0] &&
               testScore[2] < testScore[1] &&
               testScore[2] < testScore[3]) {
        lowestScore = testScore[2];
    } else {
        lowestScore = testScore[3];
    }
    cout << "Lowest test score: " << lowestScore;
}


int main()
{
    getScore();

    while (countGetScore != 4) {    // Runs getScore() 4 times.
        getScore();
    }

    calcAverage();
    findLowest();
    return 0;
}