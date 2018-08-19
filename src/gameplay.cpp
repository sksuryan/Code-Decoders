#include "gameplay.h"
#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>
#include <rnumgen.h>
#include <stdio.h>
#include <menus.h>

using namespace std;

void gotoxy (long x, long y)
{

COORD coord;
coord.X = x;
coord.Y = y;

SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


void getcursorxy(int &x, int &y)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        x = csbi.dwCursorPosition.X;
        y = csbi.dwCursorPosition.Y;
    }

}
gameplay::gameplay()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),248);

    srand(time(NULL));
    random[0] = rand()%10;

    ///LOOPS FOR RANDOM NUMBER GENERATION...
    for(i= 1;;i++)
    {
        random[1] = rand()%10;
        if(random[1] != random[0])
            break;
    }

    for(i= 1;;i++)
    {
        random[2] = rand()%10;
        if(random[2] != random[0] && random[2] != random[1])
            break;
    }

    for(i= 1;;i++)
    {
        random[3] = rand()%10;
        if(random[3] != random[0] && random[3] != random[1] && random[3] != random[2])
            break;
    }

    for(i= 1;;i++)
    {
        random[4] = rand()%10;
        if(random[4] != random[0] && random[4] != random[1] && random[4] != random[2] && random[4] != random[3])
            break;
    }

    for(i= 1;;i++)
    {
        random[5] = rand()%10;
        if(random[5] != random[0] && random[5] != random[1] && random[5] != random[2] && random[5] != random[3] && random[5] != random[4])
            break;
    }

}

void gameplay::gameplay_chooser(int a)
{
    if(a == 0)
    {
        gameplay_easy();
    }
    else
        if(a == 1)
        {
            gameplay_hard();
        }

}

void gameplay::gameplay_easy()
 {
     int x,y;
     int count1;


    system("cls");


    rnumgen write(random);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),241);

    cout<<"      ____ "<<" ____"<<"  ____"<<"  ____"<<endl;
    cout<<"     |    |"<<"|    |"<<"|    |"<<"|    |"<<endl;
    cout<<"     |____|"<<"|____|"<<"|____|"<<"|____|"<<endl;
    cout<<"     NOW ENTER 4 NUMBERS"<<endl;
    cout<<"     *One Single Number at a time*"<<endl;
    for(int z = 1;;z++)
    {
        if(z%2 == 0)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),241);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),243);

        cout<<"     ATTEMPT :-"<<z<<endl;
        getcursorxy(x,y);
        do
       {
           for(int j=0;j<4;j++)
           {
               cout<<"     "<<j+1<<": ";
               cin>>choosen[j];
           }
            count1 =0;

           for(i=0;i<6;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(random[i] == choosen[j])
                        count1++;
                }
            }

              if(count1 != 4)
              {
                  cout<<"You have added some Invalid Numbers! \n Please Try Again :- ";
                  cout<<count1;
                  Sleep(1000);
                  gotoxy(x,y);
                for(int i=0;i<10;i++)
                    cout<<"                                                                                                    "<<endl;
                gotoxy(x,y);
              }

        }while(count1 != 4);

        gotoxy(x,y);

        check_easy(random,choosen);
        cout<<endl;

    }
 }


void gameplay::gameplay_hard()
 {
     int x,y;
     system("cls");


    rnumgen write(random);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),241);

     int count1;

     cout<<"      ____ "<<" ____"<<"  ____"<<"  ____"<<"  ____"<<endl;
     cout<<"     |    |"<<"|    |"<<"|    |"<<"|    |"<<"|    |"<<endl;
     cout<<"     |____|"<<"|____|"<<"|____|"<<"|____|"<<"|____|"<<endl;
     cout<<"     NOW ENTER 5 NUMBERS"<<endl;
     cout<<"     *One Single Number at a time*"<<endl;

    for(int z = 1;;z++)
    {
        if(z%2 == 0)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),241);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),243);

        cout<<"     ATTEMPT :-"<<z<<endl;
        getcursorxy(x,y);
       do
       {
        for(int j = 0;j<5;j++)
        {
            cout<<"     "<<j+1<<": ";
            cin>>choosen[j];
        }

    count1 =0;

           for(i=0;i<6;i++)
            {
                for(int j=0;j<5;j++)
                {
                    if(random[i] == choosen[j])
                        count1++;
                }
            }

            if(count1 != 5)
              {
                  cout<<"You have added some Invalid Numbers! \n Please Try Again :- ";
                  cout<<count1;
                  Sleep(1000);
            gotoxy(x,y);
                for(int i=0;i<10;i++)
                    cout<<"                                                                                                    "<<endl;
                gotoxy(x,y);
              }

        }while(count1 != 5);
    gotoxy(x,y);
    check_hard(random,choosen);
    cout<<endl;
    }
 }

 void gameplay::check_easy(int random[], int choosen[4])
 {
   int count1 = 0, count2 = 0;

   for(int i =0;i<4;i++)
        if(random[i] == choosen[i])
            count1++;

    if(count1==4)
    {
        youwin();
    }

    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            if(random[i] == choosen[j])
                ++count2;

    cout<<"                                               Hints:-"<<endl;

    cout<<"                 ";

    for(int i=0;i<4;i++)
    {
        cout<<" ____ ";
    }

    cout<<"       ";

    for(int i = 0;i<(count1);i++)
    {
        cout<<" ____ ";
    }

    for(int i = 0;i<(count2-count1);i++)
    {
        cout<<" ____ ";
    }

    cout<<endl;

    cout<<"                 ";

    for(int i = 0;i<4;i++)
    {
        cout<<"|  "<<choosen[i]<<" |";
    }

    cout<<"       ";

    for(int i = 0;i<count1;i++)
    {
        cout<<"| *@ |";
    }

    for(int i=0; i<(count2-count1);i++)
    {
        cout<<"| ** |";
    }

    cout<<endl;

    cout<<"                 ";

    for(int i = 0;i<4;i++)
    {
        cout<<"|____|";
    }

    cout<<"       ";

    for(int i = 0;i<(count1);i++)
    {
        cout<<"|____|";
    }

    for(int i = 0;i<(count2-count1);i++)
    {
        cout<<"|____|";
    }
 }

void gameplay::check_hard(int random[], int choosen[])
 {
    int count1 = 0, count2 = 0;
    for(int i =0;i<5;i++)
        if(random[i] == choosen[i])
            count1++;

    if(count1==5)
    {
        youwin();
    }

    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(random[i] == choosen[j])
                ++count2;
    cout<<"                                               Hints:-"<<endl;

    cout<<"                 ";

    for(int i=0;i<5;i++)
    {
        cout<<" ____ ";
    }

    cout<<"       ";

    for(int i = 0;i<(count1);i++)
    {
        cout<<" ____ ";
    }

    for(int i = 0;i<(count2-count1);i++)
    {
        cout<<" ____ ";
    }

    cout<<endl;

    cout<<"                 ";

    for(int i = 0;i<5;i++)
    {
        cout<<"|  "<<choosen[i]<<" |";
    }

    cout<<"       ";

    for(int i = 0;i<count1;i++)
    {
        cout<<"| *@ |";
    }

    for(int i=0; i<(count2-count1);i++)
    {
        cout<<"| ** |";
    }

    cout<<endl;

    cout<<"                 ";

    for(int i = 0;i<5;i++)
    {
        cout<<"|____|";
    }

    cout<<"       ";

    for(int i = 0;i<(count1);i++)
    {
        cout<<"|____|";
    }

    for(int i = 0;i<(count2-count1);i++)
    {
        cout<<"|____|";
    }
}

 void gameplay::youwin()
 {
     system("cls");
      gotoxy(54,11);
    cout<<"YOU WON!";
    Sleep(1000);
    gotoxy(54, 11);
    cout<<"WELL PLAYED!!"<<endl;
    Sleep(1000);
    Sleep(1000);
    menus call;
    system("cls");
    menus again;
    again.restart();
 }
