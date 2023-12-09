#include <time.h>
#include "DataFetch.h"
#include "Day1.h"
#include "Day2.h"
using namespace std;

int main()
{
    int manualDay = 1;

    struct tm newtime;
    __int64 ltime;
    char buf[26];
    errno_t err;

    _time64(&ltime);

    // Obtain coordinated universal time:
    err = _gmtime64_s(&newtime, &ltime);
    if (err)
    {
        printf("Invalid Argument to _gmtime64_s.");
    }

    asctime_s(buf, 26, &newtime);

    int dayOfMonth = newtime.tm_mday;

    if (manualDay != 0)
        dayOfMonth = manualDay;

    string dayOfMonthStr;

    stringstream string_object_name;
    string_object_name << dayOfMonth;
    string_object_name >> dayOfMonthStr;

    string data = DataFetch::readFileToString(dayOfMonth);
    switch (dayOfMonth)
    {
    case 1:
        Day1::Run(data);
        break;
    case 2:
        Day2::Run(data);
        break;
    default:
        break;
    }

    return 1;
}