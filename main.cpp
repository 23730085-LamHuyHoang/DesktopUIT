#include <iostream>
#include "kmin_console.h"
using namespace std;
#define DOT_RAN 79
#define MAX 100
#define LEN 1
#define XUONG 2
#define TRAI 3
#define PHAI 4

struct ToaDo
{
    int x;
    int y;
};

ToaDo ran[MAX];
 int soDot = 3;// so luong phan tu

 void khoiTaoRan();
void hienthiran();
void diChuyen(int huong);
void batSuKien(int &huong);
int main()
{
    /*for (int i = 0; i< 256; i++)
    {
        cout << i << ": " << (char)i << endl;
    }
    return 0;*/
khoiTaoRan();
     // game loop
     int x = 0, y = 0;
     int huong = TRAI;
     while(1)
     {

         clrscr();
         diChuyen(huong);
         hienthiran();
         batSuKien(huong);
        // gotoXY(x, y);
        //cout << (char)DOT_RAN;
        Sleep(500);
        //x++;
     }
}
void khoiTaoRan()
{
    ran[0].x = 4;
    ran[1].x = 5;
    ran[2].x = 6;
    ran[0].y = ran[1].y = ran[2].y = 1;
}
void hienthiran()
{
    for (int i = 0; i < soDot; i++)
    {
        gotoXY(ran[i].x, ran[i].y);
        cout << (char)DOT_RAN;
    }

}
void diChuyen(int huong)
{
    // dich qua phai 1 phan tu
    for(int i = soDot - 1; i >= 1; i--)
    {
        ran[i] = ran[i - 1];
    }
    switch (huong)
    {
  case LEN:
    ran[0].y--;
    break;
    case XUONG:
    ran[0].y++;
    break;
    case TRAI:
    ran[0].x--;
    break;
    case PHAI:
    ran[0].x++;
    break;
    }
}
void batSuKien(int &huong)
{
    int key = inputKey();
    if (key == KEY_UP)
    {
        huong = LEN;
    }
        else if (key == KEY_DOWN)
        {
            huong = XUONG;
        }
        else if (key == KEY_LEFT)
        {
            huong = TRAI;
        }
        else if(key == KEY_RIGHT)
        {
            huong = PHAI;
        }
}
