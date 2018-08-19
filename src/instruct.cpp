#include "instruct.h"
#include <menus.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

instruct::instruct()
{
}

void instruct::call()
{
    Sleep(100);
    system("cls");
    cout<<"                                                                      *INSTRUCTION*"<<endl<<endl;
    cout<<"                                        You are a Code Breaker, and your goal is to guess the code...."<<endl;
    cout<<"                                 The code can be of 4 numbers or 5 numbers depending on your choice of level..."<<endl;
    cout<<"                         The code is a sequence of numbers, and after each attempt you will get hints which will help you..."<<endl;
    cout<<"                                                  Those hints will tell you that your choice is right or wrong..."<<endl;

    cout<<"        ____ "<<endl;
    cout<<"       | *@ |"<<"  This is a Hint... It means that one of the Selected Number is Correct and is on the Correct Position!"<<endl;
    cout<<"       |____|"<<endl;

    cout<<"        ____ "<<endl;
    cout<<"       | ** |"<<"  This is another Hint... It means that one of the Selected Number is Correct but on the Wrong Position!"<<endl;
    cout<<"       |____|"<<endl<<endl<<endl;

    cout<<"                               **Also remember that the sequence of hints, DO NOT relate to actual code in any way..."<<endl;

    cout<<"\n\n PRESS ESCAPE(ESC) TO GO BACK TO MENU...";
    while(true)
    if(GetAsyncKeyState(VK_ESCAPE) != 0)
    {
            break;
    }
}
