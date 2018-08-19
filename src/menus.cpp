#include "menus.h"
#include <iostream>
#include <gameplay.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <instruct.h>
#include <conio.h>
#include <credits.h>

using namespace std;

menus::menus()
{
    //ctor
}

void menus::menu_selector(int opt)
{

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);
    if(opt == 0)
    {
        main_menu();
    }
    else
        if(opt == 1)
        {
            level_menu();
        }
}

void menus::main_menu()
{
    //instruct show;
    string menu[4] = {"  Start Game", " Instructions","   Credits","    Exit"};
    pointer = 0;
    while(true)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);
        cout<<"\t\t\t\t\t\t\t Code Decoders :D"<<endl<<endl;
        for(int i = 0; i<4;i++)
        {
            if(pointer == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
                cout<<"\t\t\t\t\t\t\t "<<menu[i]<<endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),243);
                cout<<"\t\t\t\t\t\t\t "<<menu[i]<<endl;
            }
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);
        cout<<"\n\n\t\t\t\t\t\t     Press Space To Choose!"<<endl<<endl;

        while(true)
        {
            if(GetAsyncKeyState(VK_UP) != 0)
            {
                --pointer;
                if(pointer == -1)
                    pointer = 3;
                break;
            }
            else
                if(GetAsyncKeyState(VK_DOWN) != 0)
                {
                    ++pointer;
                    if(pointer == 4)
                        pointer = 0;
                    break;
                }
                else
                    if(GetAsyncKeyState(VK_SPACE) != 0)
                    {
                        switch(pointer)
                        {
                            case 0:level_menu();
                            break;
                            case 1: instruct().call();
                            break;
                            case 2: credits().call();
                            break;
                            case 3: exit(0);
                        }
                        break;
                    }


        }
        Sleep(100);
        system("cls");
    }


    }

void menus::level_menu()
{
    gameplay start;
    system("cls");
    Sleep(100);
    string l_menu[2] = {"     Easy","     Hard"};
    pointer = 0;
    while(true)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);
        system("cls");
        cout<<"\t\t\t\t\t\t\t  Choose level"<<endl<<endl;
        for(int i=0; i<2; i++)
        {
            if(pointer == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
                cout<<"\t\t\t\t\t\t\t "<<l_menu[i]<<endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),243);
                cout<<"\t\t\t\t\t\t\t "<<l_menu[i]<<endl;
            }
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);
        cout<<"\n\n\t\t\t\t\t\t     Press Space To Choose!"<<endl<<endl;

        while(true)
        {
            if(GetAsyncKeyState(VK_UP) != 0)
            {
                --pointer;
                if(pointer == -1)
                    pointer = 1;
                break;
            }
            else
                if(GetAsyncKeyState(VK_DOWN) != 0)
                {
                    ++pointer;
                    if(pointer == 2)
                        pointer = 0;
                    break;
                }
                else
                    if(GetAsyncKeyState(VK_SPACE) != 0)
                    {
                         start.gameplay_chooser(pointer);
                                    break;

                    }
        }
        Sleep(100);
    }
}

 void menus::restart()
{
    Sleep(1000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);
    system("cls");
    //menus re;
    string menu[2] = {"    Lets Play Again!", " Nah! That's All for today!"};
    int pointer = 0, x=0;
    while(true)
    {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);
        system("cls");
        cout<<"\t\t\t\t\t\t    Do you wan to play again?(press space to choose...)"<<endl<<endl;
        for(int i=0; i<2; i++)
        {
            if(pointer == i)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),244);
                cout<<"\t\t\t\t\t\t\t "<<menu[i]<<endl;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),243);
                cout<<"\t\t\t\t\t\t\t "<<menu[i]<<endl;
            }
        }

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),245);
        cout<<"\n\n\t\t\t\t\t\t     Press Space To Choose!"<<endl<<endl;

        while(true)
        {

            if(GetAsyncKeyState(VK_UP) != 0)
            {
                --pointer;
                if(pointer == -1)
                    pointer = 1;
                break;
            }
            else
                if(GetAsyncKeyState(VK_DOWN) != 0)
                {
                    ++pointer;
                    if(pointer == 2)
                        pointer = 0;
                    break;
                }
                else
                    if(GetAsyncKeyState(VK_SPACE) != 0)
                    {
                        switch(pointer)
                        {
                            case 0: menu_selector(0);
                                    break;
                            case 1: exit(0);
                                    break;
                        }
                    }
        }
        Sleep(100);
    }

        system("cls");

}
