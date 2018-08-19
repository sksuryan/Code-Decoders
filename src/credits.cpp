#include "credits.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

credits::credits()
{
    //ctor
}

void credits::call()
{
    system("cls");
    cout<<"                                                                     ***CREDITS!***"<<endl;
    cout<<"                            Developer Name:- RAY"<<endl;
    cout<<"                            Special Credits:- TO ALL MY FRIENDS FOR TRYING THIS GAME, FOR SUGGESTIONS, FOR MOTIVATION!"<<endl;
    cout<<"                            "<<endl<<endl<<endl;
    cout<<"\n\n PRESS ESCAPE(ESC) TO GO BACK TO MENU...";
    while(true)
    if(GetAsyncKeyState(VK_ESCAPE) != 0)
    {
            break;
    }
}
