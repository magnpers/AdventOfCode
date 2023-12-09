#include <regex>
#include <iostream>
using namespace std;

namespace Day1
{
    inline void Run(string inputData)
    {
        int calibrationSum = 0;

        int size = inputData.length();
        string* numbers = new string[size];

        int numbersRow = 0;
        for (int i = 0; i < inputData.length(); i++)
        {
            char currChar = inputData[i];
            if (currChar == '\n')
                numbersRow++;
            else if (isdigit(currChar))
                numbers[numbersRow] += currChar;
        }

        int total = 0;

        for (int i = 0; i < numbersRow; i++)
        {
            string numberString = numbers[i];
            string tempString = "";

            if (numberString.length() < 2)
            {
                tempString += numberString[0];
                tempString += numberString[0];
            }
            else
            {
                tempString += numberString[0];
                tempString += numberString[numberString.length() - 1];
            }

            total += stoi(tempString);
        }

        std::cout << total;
    }
}