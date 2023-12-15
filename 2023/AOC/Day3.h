#include <regex>
#include <iostream>
#include <map>

using namespace std;

namespace Day3
{
	inline void ControlRows(string* row1, string* row2, int rowLength, int& summary)
	{
		for (int i = 0; i <= row1->length(); i++)
		{
			char currChar = (*row1)[i];

			if (isdigit(currChar))
			{

			}
			else
			{
				if (currChar != '.')
				{

				}
			}
		}
	}

    inline void Run(string inputData)
    {
        int calibrationSum = 0;

        int size = inputData.length();
        string* compareRow1 = new string[100];
        string* compareRow2 = new string[100];
		
		int summary;
        int inputRow = 1;

		int i = 0, rowLength = 0;

		while (i < inputData.length())
		{

			char currChar = inputData[i];

			if(inputRow == 1)
				compareRow1[i] = currChar;
			else
				compareRow2[i] = currChar;

			if (currChar == '\n')
			{
				if(inputRow == 1)
					ControlRow(compareRow1);
				else
					ControlRow(compareRow2);

				if (inputRow == 1)
				{
					ControlRows(compareRow1, compareRow2);
					inputRow = 2;
				}
				else 
				{
					compareRow2[i] = currChar;
					compareRow1 = compareRow2;

					compareRow2 = new string[100];
				}
				rowLength = 0;
			}

			if (i + 1 < inputData.length())
				i++;
			rowLength++;
				
		}
			cout << "The summary = " << summary;
	}

        //std::cout << total;
    }
}