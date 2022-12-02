#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getShapeValue(char& shape)
{
    if (shape == 'X') return 1;
    if (shape == 'Y') return 2;
    if (shape == 'Z') return 3;
    return 0;
}

int checkOutcome(char& shape1, char& shape2)
{
    // shape1 wins
    if (shape1 == 'A' && shape2 == 'Z') return 0;
    if (shape1 == 'B' && shape2 == 'X') return 0;
    if (shape1 == 'C' && shape2 == 'Y') return 0;

    // tie
    if (shape1 == 'A' && shape2 == 'X') return 3;
    if (shape1 == 'B' && shape2 == 'Y') return 3;
    if (shape1 == 'C' && shape2 == 'Z') return 3;
    
    // shape2 wins
    if (shape1 == 'A' && shape2 == 'Y') return 6;
    if (shape1 == 'B' && shape2 == 'Z') return 6;
    if (shape1 == 'C' && shape2 == 'X') return 6;

    return 0;
}

int main()
{
    int totalScore = 0;
    string currentLine;
    
    fstream file;
    file.open("day2.in");

    if (!file.is_open())
    {
        cout << "Error opening file! Exiting..." << endl;
        return -1;
    }

    while (getline(file, currentLine))
    {
        totalScore += getShapeValue(currentLine[2]);
        totalScore += checkOutcome(currentLine[0], currentLine[2]);
    }

    cout << totalScore << endl;

    file.close();
    return 0;
}