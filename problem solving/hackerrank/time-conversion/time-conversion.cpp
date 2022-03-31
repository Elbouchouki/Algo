#include <bits/stdc++.h>
using namespace std;
//
string timeConversion(string s)
{
    int hour = stoi(s.substr(0, 2));

    if (s.substr(8, 2) != "AM")
    {
        if (hour != 12)
            hour += 12;
    }
    else
    {
        if (hour == 12)
            hour = 0;
    }

    stringstream ss;
    ss << setfill('0') << setw(2) << hour;
    ss << ":";
    ss << s.substr(3, 2);
    ss << ":";
    ss << s.substr(6, 2);
    return ss.str();
}

int main()
{
    cout << timeConversion("07:05:45PM") << endl;
    cout << timeConversion("12:40:22AM") << endl;
    cout << timeConversion("12:40:22PM") << endl;

    return 0;
}