#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <menus.h>
#include <conio.h>
#include <dos.h>

using namespace std;

void gotoxy (int x, int y)
{

COORD coord;
coord.X = x;
coord.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


int main()
{
    system("COLOR fc");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),252);

    gotoxy(54,11);
    cout<<"Hi THERE!";
    Sleep(1000);
    system("cls");
    gotoxy(54, 11);
    cout<<"Lets Start!"<<endl;
    Sleep(1000);
    gotoxy(54, 11);
    cout<<"This is Code-Decoders!"<<endl;
    Sleep(1000);
    system("cls");
     gotoxy(54, 11);
    cout<<"Have Fun!!"<<endl;
    Sleep(1000);
    menus call;
    system("cls");
    call.menu_selector(0);

}
