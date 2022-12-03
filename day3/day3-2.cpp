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

string parseRepeatedItem(const string& items1, const string& items2)
{
    string repeatedItems;

    for (int i = 0; i < items1.length(); ++i) 
    {
        for (int j = 0; j < items2.length(); ++j)
        {
            if (items1[i] == items2[j])
            {
                if (repeatedItems.find(items1[i]) == string::npos)
                {
                    repeatedItems += items1[i];
                }
            }
        }
    }
    return repeatedItems;
}

int main()
{
    int prioritySum = 0;
    string line1, line2, line3;
    
    fstream file;
    file.open("day3.in");

    if (!file.is_open())
    {
        cout << "Error opening file! Exiting..." << endl;
        return -1;
    }

    while (!file.eof())
    {
        getline(file, line1);
        getline(file, line2);
        getline(file, line3);

        string repeatedItems = parseRepeatedItem(parseRepeatedItem(line1, line2), line3);
        
        if (repeatedItems.length() == 1)
        {
            prioritySum += getItemPriority(repeatedItems[0]);
        }
    }

    cout << prioritySum << endl;

    file.close();
    return 0;
}