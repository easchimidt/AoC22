#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int top1Cal = 0, top2Cal = 0, top3Cal = 0, sumCal = 0;
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
            if (sumCal > top1Cal)
            {
                top3Cal = top2Cal;
                top2Cal = top1Cal;
                top1Cal = sumCal;
            }
            else if (sumCal > top2Cal)
            {
                top3Cal = top2Cal;
                top2Cal = sumCal;
            }
            else if (sumCal > top3Cal)
            {
                top3Cal = sumCal;
            }

            sumCal = 0;
        }
    }

    cout << top1Cal + top2Cal + top3Cal << endl;

    file.close();
    return 0;
}