#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int biggestCal = 0, sumCal = 0;
    string currentLine;
    
    fstream file;
    file.open("day1.in");

    if (!file.is_open())
    {
        cout << "Error opening file! Exiting..." << endl;
        return -1;
    }

    while (getline(file, currentLine))
    {
        if (currentLine.length() > 0)
        {
            sumCal += stoi(currentLine);
        }
        else
        {
            if (sumCal > biggestCal)
            {
                biggestCal = sumCal;
            }
            sumCal = 0;
        }
    }

    cout << biggestCal << endl;

    file.close();
    return 0;
}