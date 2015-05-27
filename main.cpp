/**
 *  Copyright 2015 Gabriel Nicolás González Ferreira <gabrielinuz@gmail.com>
 *
 *  Permission is hereby granted, free of charge, to any person obtaining
 *  a copy of this software and associated documentation files (the
 *  "Software"), to deal in the Software without restriction, including
 *  without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to
 *  permit persons to whom the Software is furnished to do so, subject to
 *  the following conditions:
 *
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 *  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 *  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 *  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**/

#ifdef __unix__
    #include <unistd.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <windows.h>
#endif // defined

#include <sstream>
#define TO_STRING( x ) dynamic_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

#include <ctime>
#include <string>
#include <iostream>

using namespace std;

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}
/*
    COMO DATO:
//    cout << timeinfo->tm_year << endl;
//    cout << timeinfo->tm_mon << endl;
//    cout << timeinfo->tm_mday << endl;

*/
void showTime()
{
    time_t timer;
    struct tm * timeinfo;
    time ( &timer );
    timeinfo = localtime ( &timer );

    string hours = TO_STRING(timeinfo->tm_hour);
    string minutes = TO_STRING(timeinfo->tm_min);
    string seconds = TO_STRING(timeinfo->tm_sec);

    if(hours.size() == 1){hours = "0"+hours;}
    if(minutes.size() == 1){minutes = "0"+minutes;}
    if(seconds.size() == 1){seconds = "0"+seconds;}

    cout << hours << ":" << minutes << ":" << seconds << endl;

    mktime ( timeinfo );
}

int main()
{
    while(1)
    {
        showTime();
        delay(1000);

        #ifdef __unix__
            system("clear");
        #elif defined(_WIN32) || defined(WIN32)
            system("cls");
        #endif // defined
    }
    return 0;
}

