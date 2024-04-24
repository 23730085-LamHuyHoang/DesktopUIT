#include <iostream>
#include "kmin_console.h"
using namespace std;
#define DOT_RAN 254
#define MAX 100
#define LEN 1
#define XUONG 2
#define TRAI 3
#define PHAI 4
#define TUONG_TREN 5
#define TUONG_DUOI 25
#define TUONG_TRAI 10
#define TUONG_PHAI 100


struct ToaDo
{
    int x;
    int y;
};

ToaDo ran[MAX];
    int soDot = 3;

void khoiTaoRan();
void hienThiRan(ToaDo dotCuoiCu);
ToaDo diChuyen(int huong);
void batSuKien(int &huong);
void veTuong();
bool kiemTraThua();
void xuLyThua();

int main()
{
    /*for (int i = 0; i< 256; i++)
    {
        cout << i << ": " << (char)i << endl;
    }
    return 0;*/
    khoiTaoRan();

    int x = 0, y = 0;
    int huong = PHAI;
    veTuong();
    while(1)
    {
        ToaDo dotCuoiCu = diChuyen(huong);
        batSuKien(huong);
        hienThiRan(dotCuoiCu);
        Sleep(300);
        if (kiemTraThua() == true)
            break;
    };
    xuLyThua();
}

void khoiTaoRan()
{
    ran[0].x = TUONG_TRAI + 7;
    ran[1].x = TUONG_TRAI + 6;
    ran[2].x = TUONG_TRAI + 5;
    ran[0].y = ran[1].y = ran[2].y = TUONG_TREN + 5;
}

void hienThiRan(ToaDo dotCuoiCu)
{
    for (int i = 0; i < soDot; i++)
    {
        gotoXY(ran[i].x, ran[i].y);
        cout << (char)DOT_RAN;
    }
    gotoXY(dotCuoiCu.x, dotCuoiCu.y);
    cout << " ";
}

ToaDo diChuyen(int huong)
{
    ToaDo dotCuoiCu = ran[soDot - 1];

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

    return dotCuoiCu;
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

void veTuong()
{
    for (int i = TUONG_TRAI; i <= TUONG_PHAI; i++)
    {
        gotoXY(i, TUONG_TREN);
        cout << (char)223;
        gotoXY(i, TUONG_DUOI);
        cout << (char)220;
    }
    for (int i = TUONG_TREN; i <= TUONG_DUOI; i++)
    {
        gotoXY(TUONG_TRAI, i);
        cout << (char)222;
        gotoXY(TUONG_PHAI, i);
        cout << (char)221;
    }
}

bool kiemTraThua()
{
    if (ran[0].y == TUONG_TREN || ran[0].y == TUONG_DUOI || ran[0].x == TUONG_TRAI + 1 || ran[0].x == TUONG_PHAI - 1)
        return true;
    return false;
}

void xuLyThua()
{
    Sleep(1000);
    clrscr();
    cout << "Game Over!!!";
}
