#include <iostream>
#include <bits/stdc++.h>
#include "kmin_console.h"

using namespace std;

#define DOT_RAN 149
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
ToaDo hienThiMoi();
bool kiemTraDaAnMoi(ToaDo moi);
void themDot();

int main()
{
//    for (int i = 0; i< 256; i++)
//    {
//        cout << i << ": " << (char)i << endl;
//    }

    khoiTaoRan();

    int huong = PHAI;
    int diem = 0;
    veTuong();
    ToaDo moi = hienThiMoi();
    gotoXY(TUONG_TRAI, TUONG_TREN - 1);
    cout << "Diem: " << diem;
    while(1)
    {
        ToaDo dotCuoiCu = diChuyen(huong);
        batSuKien(huong);
        hienThiRan(dotCuoiCu);
        if(kiemTraDaAnMoi(moi) == true)
        {
            moi = hienThiMoi();
            themDot();
            diem++;
            gotoXY(TUONG_TRAI, TUONG_TREN - 1);
            cout << "Diem: " << diem;
        }
        Sleep(300);
        if (kiemTraThua() == true)
            break;
    };
    xuLyThua();

    srand(time(NULL));
    int k = rand() % 10;
    cout << k;

    return 0;
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
        cout << (char)35;
        gotoXY(i, TUONG_DUOI);
        cout << (char)35;
    }
    for (int i = TUONG_TREN; i <= TUONG_DUOI; i++)
    {
        gotoXY(TUONG_TRAI, i);
        cout << (char)35;
        gotoXY(TUONG_PHAI, i);
        cout << (char)35;
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
    Sleep(100);
    clrscr();
    cout << "Game Over!!!";
}

ToaDo hienThiMoi()
{
    srand(time(NULL));
    int x = (TUONG_TRAI+1) + rand()%(TUONG_PHAI - TUONG_TRAI - 1);
    int y = (TUONG_TREN+1) + rand()%(TUONG_DUOI - TUONG_TREN - 1);
    gotoXY(x, y);
    cout << "*";
    return ToaDo{x,y};
}

bool kiemTraDaAnMoi(ToaDo moi)
{
    if(ran[0].x == moi.x && ran[0].y == moi.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void themDot()
{
    ran[soDot] = ran[soDot - 1];
    soDot++;
}
