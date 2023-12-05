#include <iostream>
#include "DataFetch.h"
using namespace std;


int main()
{
    string inputData = DataFetch::readFileToString("1");
    cout << inputData;

}