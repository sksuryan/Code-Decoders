#include "rnumgen.h"
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

rnumgen::rnumgen(int r[])
{
    int i[6],j;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);

    cout<<"START YOUR GUESS FROM THESE NUMBERS:- "<<endl;

    cout<<"                                             ____ "<<" ____"<<"  ____"<<"  ____"<<"  ____"<<"  ____"<<endl;

    srand(time(NULL));

    i[0] = rand()%6;

    ///LOOPS FOR RANDOM NUMBER GENERATION...

    for(j= 1;;j++)
    {
        i[1] = rand()%6;
        if(i[1] != i[0])
            break;
    }

    for(j= 1;;j++)
    {
        i[2] = rand()%6;
        if(i[2] != i[0] && i[2] != i[1])
            break;
    }

    for(j= 1;;j++)
    {
        i[3] = rand()%6;
        if(i[3] != i[0] && i[3] != i[1] && i[3] != i[2])
            break;
    }

    for(j= 1;;j++)
    {
        i[4] = rand()%6;
        if(i[4] != i[0] && i[4] != i[1] && i[4] != i[2] && i[4] != i[3])
            break;
    }

    for(j= 1;;j++)
    {
        i[5] = rand()%6;
        if(i[5] != i[0] && i[5] != i[1] && i[5] != i[2] && i[5] != i[3] && i[5] != i[4])
            break;
    }
    cout<<"                                            ";

    for(j=0; j<6; j++)
    {
        cout<<"| "<<r[i[j]]<<"  |";
    }
    cout<<"\n                                            |____|"<<"|____|"<<"|____|"<<"|____|"<<"|____|"<<"|____|"<<endl;


    Sleep(500);
}
