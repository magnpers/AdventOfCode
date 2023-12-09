#include "DataFetch.h"
using namespace std;

int main()
{
    int calibrationSum = 0;

    string inputData = DataFetch::readFileToString("2");

    cout << inputData;
}