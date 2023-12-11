#include <string>
#include <iostream>
using namespace std;

namespace Day2
{
	inline void SkipGameNumber(int &i, string &inputData)
	{
		while (inputData[i] != ':' && i < inputData.length())
			i++;
	}

	inline void ResetGameNumbers(int &r, int &g, int &b)
	{
		r = 0;
		g = 0;
		b = 0;
	}

	inline bool CheckGame(int &r, int &g, int &b)
	{
		int rTotal = 12, gTotal = 13, bTotal = 14;

		if (r <= rTotal && g <= gTotal && b <= bTotal)
			return true;
		else
			return false;
	}

	inline bool Compare(int& r, int& g, int& b)
	{

	}

	inline void Run(string inputData, bool firstVersion)
	{

		int size = inputData.size();

		int gameNr = 1;
		bool gameOk = true, foundDigit = false;
		int idSum = 0, powerSum = 0;

		int r = 0, g = 0, b = 0, i = 0;
		string tmpIntString = "";

		SkipGameNumber(i, inputData);


		while (i < inputData.length())
		{
			if (firstVersion)
			{
				char currChar = inputData[i];

				if (foundDigit == false) // Version 1 for day 2
				{
					if (currChar == '\n')
					{
						if (CheckGame(r, g, b))
							idSum += gameNr;
						else
							cout << "Game nr" << gameNr << " was not ok, skipping to next" << '\n';

						gameNr++;
						ResetGameNumbers(r, g, b);
						SkipGameNumber(i, inputData);
					}
					else if (currChar == ';')
					{
						if (CheckGame(r, g, b) == false)
						{
							cout << "Game nr" << gameNr << " was not ok, skipping to next" << '\n';
							SkipGameNumber(i, inputData);
							gameNr++;
						}
						ResetGameNumbers(r, g, b);
					}
					else if (isdigit(currChar))
					{
						tmpIntString += currChar;
						foundDigit = true;
					}

					if (i + 1 < inputData.length())
						i++;
				}
				else
				{
					while (isdigit(currChar))
					{
						tmpIntString += currChar;
						i++;
						currChar = inputData[i];
					}
					while (isalpha(currChar) == false)
					{
						i++;
						currChar = inputData[i];
					}

					switch (inputData[i])
					{
					case 'r':
						r += stoi(tmpIntString);
						break;
					case 'g':
						g += stoi(tmpIntString);
						break;
					case 'b':
						b += stoi(tmpIntString);
						break;
					default:
						break;
					}
					foundDigit = false;
					tmpIntString = "";
				}
			}
			else // Version 2 for day 2
			{
				char currChar = inputData[i];

				if (foundDigit == false)
				{
					if (currChar == '\n')
					{
						int sum = r * g * b;
						powerSum += sum;
						gameNr++;
						ResetGameNumbers(r, g, b);
						SkipGameNumber(i, inputData);
					}
					else if (isdigit(currChar))
					{
						tmpIntString += currChar;
						foundDigit = true;
					}

					if (i + 1 < inputData.length())
						i++;
				}
				else
				{
					while (isdigit(currChar))
					{
						tmpIntString += currChar;
						i++;
						currChar = inputData[i];
					}
					while (isalpha(currChar) == false)
					{
						i++;
						currChar = inputData[i];
					}

					switch (inputData[i])
					{
					case 'r':
						if (r < stoi(tmpIntString) || r == 0)
							r = stoi(tmpIntString);
						break;
					case 'g':
						if (g < stoi(tmpIntString) || g == 0)
							g = stoi(tmpIntString);
						break;
					case 'b':
						if (b < stoi(tmpIntString) || b == 0)
							b = stoi(tmpIntString);
						break;
					default:
						break;
					}
					foundDigit = false;
					tmpIntString = "";
				}
			}
		}
		if (firstVersion)
			cout << "IdSum = " << idSum;
		else
			cout << "powerSum = " << powerSum;
	}
}