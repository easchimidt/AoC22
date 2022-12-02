#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getShapeValue(char shape)
{
    if (shape == 'A') return 1;
    if (shape == 'B') return 2;
    if (shape == 'C') return 3;
    return 0;
}

int getDesiredOutcomeValue(char& shape)
{
    if (shape == 'X') return 0;
    if (shape == 'Y') return 3;
    if (shape == 'Z') return 6;
    return 0;
}

int getDesiredOutcomeShapeValue(char& shape1, char& shape2)
{
    // need to lose
    if (shape2 == 'X')
    {
        if (shape1 == 'A') return getShapeValue('C');
        if (shape1 == 'B') return getShapeValue('A');
        if (shape1 == 'C') return getShapeValue('B');
    }

    // need to tie
    if (shape2 == 'Y')
    {
        return getShapeValue(shape1);
    } 
    
    // need to win
    if (shape2 == 'Z')
    {
        if (shape1 == 'A') return getShapeValue('B');
        if (shape1 == 'B') return getShapeValue('C');
        if (shape1 == 'C') return getShapeValue('A');
    } 

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
        totalScore += getDesiredOutcomeShapeValue(currentLine[0], currentLine[2]);
        totalScore += getDesiredOutcomeValue(currentLine[2]);
    }

    cout << totalScore << endl;

    file.close();
    return 0;
}