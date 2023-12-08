//#include <regex>
//#include "DataFetch.h"
//using namespace std;
//
//
//int main()
//{
//    int calibrationSum = 0;
//
//    string inputData = DataFetch::readFileToString("1");
//    int size = inputData.length();
//    string* numbers = new string[size];
//
//    int numbersRow = 0;
//    for (int i = 0; i < inputData.length(); i++) 
//    {
//        char currChar = inputData[i];
//        if (currChar == '\n')
//            numbersRow++;
//        else if (isdigit(currChar))
//            numbers[numbersRow] += currChar;
//    }
//
//    int total = 0;
//
//    for (int i = 0; i < numbersRow; i++)
//    {
//        string numberString = numbers[i];
//        string tempString = "";
//
//        if (numberString.length() < 2)
//        {
//            tempString += numberString[0];
//            tempString += numberString[0];
//        }
//        else
//        {
//            tempString += numberString[0];
//            tempString += numberString[numberString.length() - 1];
//        }
//
//        total += stoi(tempString);
//    }
//
//    std::cout << total;
//}