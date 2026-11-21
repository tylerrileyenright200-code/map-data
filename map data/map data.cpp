#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main()
{
    map<int, string> numberWords;

    ifstream inputFile("numbersAsWords.txt");

    if (!inputFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    string word;

    // Store words 1 through 100 in the map
    for (int i = 1; i <= 100; i++)
    {
        getline(inputFile, word);
        numberWords.insert({ i, word });
    }

    inputFile.close();

    int number;

    cout << "Enter an integer between 1 and 199: ";
    cin >> number;

    if (number < 1 || number > 199)
    {
        cout << "Number out of range." << endl;
        return 1;
    }

    string result;

    if (number <= 100)
    {
        result = numberWords[number];
    }
    else
    {
        int remainder = number - 100;

        result = "one hundred";

        if (remainder > 0)
        {
            result += " ";

            if (remainder <= 100)
            {
                result += numberWords[remainder];
            }
        }
    }

    cout << result << endl;

    return 0;
}