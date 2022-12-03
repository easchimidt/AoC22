#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getItemPriority(char item)
{
    int itemAscii = item;
    if (itemAscii >= 65 && itemAscii <= 90) return itemAscii - 38;
    else if (itemAscii >= 97 && itemAscii <= 122) return itemAscii - 96;
    return 0;
}

char findRepeatedItem(const string& bag1, const string& bag2)
{
    char item;
    for (int i = 0; i < bag1.length(); ++i)
    {
        for (int j = 0; j < bag1.length(); ++j)
        {
            if (bag1[i] == bag2[j])
            {
                item = bag1[i];
                break;
            }
        }
    }
    return item;
}

int main()
{
    int prioritySum = 0;
    string currentLine, bag1, bag2;
    
    fstream file;
    file.open("day3.in");

    if (!file.is_open())
    {
        cout << "Error opening file! Exiting..." << endl;
        return -1;
    }

    while (getline(file, currentLine))
    {
        int halfLen = currentLine.length() / 2;
        bag1 = currentLine.substr(0, halfLen);
        bag2 = currentLine.substr(halfLen, halfLen);

        prioritySum += getItemPriority(findRepeatedItem(bag1, bag2));        
    }

    cout << prioritySum << endl;

    file.close();
    return 0;
}