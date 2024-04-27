#include <iostream>
#include <bits/stdc++.h>
#include "kmin_console.h"

using namespace std;

#define DOT_RAN 'o'         // Hình ảnh tọa độ của một đốt rắn
#define MAX 100             // Số đốt rắn
#define LEN 1               // Mã hướng của rắn
#define XUONG 2             // Mã hướng của rắn
#define TRAI 3              // Mã hướng của rắn
#define PHAI 4              // Mã hướng của rắn
#define TUONG_TREN 5        // Vị trí của tường trên
#define TUONG_DUOI 25       // Vị trí của tường dưới
#define TUONG_TRAI 10       // Vị trí của tường trai
#define TUONG_PHAI 70      // Vị trí của tường phai

// Tọa độ console
struct ToaDo
{
    int x;
    int y;
};

ToaDo ran[MAX]; // Tọa độ của các đốt rắn
int soDot = 3;  //Số đốt rắn
int tocDo = 300; // Tốc độ rắn

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
bool kiemTraRanChamThan();

int main()
{
    cout << "--------------------" << "WELCOME TO SNAKE GAME" << "--------------------" << endl;
    cout << "\nNhap Ten Nguoi Choi: ";
    string tenNguoiChoi; getline(cin, tenNguoiChoi);
    clrscr();
    ShowCur(0);
    khoiTaoRan();
    int huong = PHAI;
    int diem = 0;
    veTuong();
    ToaDo moi = hienThiMoi();
    gotoXY(TUONG_TRAI, TUONG_TREN - 2);
    cout << "Nguoi Choi: " << tenNguoiChoi;
    gotoXY(TUONG_TRAI, TUONG_TREN - 1);
    cout << "Diem: " << diem;

    // Game loop
    while(1)
    {
        ToaDo dotCuoiCu = diChuyen(huong);
        batSuKien(huong);
        hienThiRan(dotCuoiCu);
        if(kiemTraRanChamThan() == true)
        {
                break;
        }
        if(kiemTraDaAnMoi(moi) == true)
        {
            moi = hienThiMoi();
            themDot();
            diem++;
            tocDo-=20;
            gotoXY(TUONG_TRAI, TUONG_TREN - 1);
            cout << "Diem: " << diem;
        }
        Sleep(tocDo);
        if (kiemTraThua() == true)
            break;
    };
    xuLyThua();

    return 0;
}

// KHởi tạo 3 nốt đầu tiên của rắn
void khoiTaoRan()
{
    ran[0].x = TUONG_TRAI + 7;
    ran[1].x = TUONG_TRAI + 6;
    ran[2].x = TUONG_TRAI + 5;
    ran[0].y = ran[1].y = ran[2].y = TUONG_TREN + 5;
}

// Hiển thị rắn theo tọa độ đã lưu trong mảng
void hienThiRan(ToaDo dotCuoiCu)
{
    gotoXY(ran[0].x, ran[0].y);
    cout << "@";
    for (int i = 1; i < soDot; i++)
    {
        gotoXY(ran[i].x, ran[i].y);
        cout << (char)DOT_RAN;
    }
    gotoXY(dotCuoiCu.x, dotCuoiCu.y);
    cout << " ";
}

// Cập nhật tọa độ của các đốt rắn khi rắn di chuyển
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

// Hàm xác định hướng di chuyển của rắn
void batSuKien(int &huong)
{
    int key = inputKey();
    if (key == KEY_UP && huong!=XUONG)
    {
        huong = LEN;
    }
    else if (key == KEY_DOWN && huong!=LEN)
    {
        huong = XUONG;
    }
    else if (key == KEY_LEFT && huong!=PHAI)
    {
        huong = TRAI;
    }
    else if(key == KEY_RIGHT && huong!= TRAI)
    {
        huong = PHAI;
    }
}

// Hàm dùng đẻ vẽ tường
void veTuong()
{
    for (int i = TUONG_TRAI; i <= TUONG_PHAI; i++)
    {
        gotoXY(i, TUONG_TREN);
        cout << "#";
        gotoXY(i, TUONG_DUOI);
        cout << "#";
    }
    for (int i = TUONG_TREN; i <= TUONG_DUOI; i++)
    {
        gotoXY(TUONG_TRAI, i);
        cout << "#";
        gotoXY(TUONG_PHAI, i);
        cout << "#";
    }
}

// Kiểm tra những trường hợp mà game over
bool kiemTraThua()
{
    if (ran[0].y == TUONG_TREN || ran[0].y == TUONG_DUOI || ran[0].x == TUONG_TRAI + 1 || ran[0].x == TUONG_PHAI - 1)
        return true;
    return false;
}

// Hàm xử lý khi game over
void xuLyThua()
{
    Sleep(100);
    clrscr();
    cout << "Game Over!!!";
}

// Hiển thị mồi
ToaDo hienThiMoi()
{
    srand(time(NULL));
    int x = (TUONG_TRAI+1) + rand()%(TUONG_PHAI - TUONG_TRAI - 1);
    int y = (TUONG_TREN+1) + rand()%(TUONG_DUOI - TUONG_TREN - 1);
    gotoXY(x, y);
    cout << "*";
    return ToaDo{x,y};
}


// Kiểm tra đã ăn mồi hay chưa
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

// Thêm đốt mới khi rắn ăn trúng mồi
void themDot()
{
    ran[soDot] = ran[soDot - 1];
    soDot++;
}

// Kiểm tra xem có chạm thân hay không
bool kiemTraRanChamThan()
{
    for(int i = 1; i <= DOT_RAN; i++)
    {
        if((ran[0].x == ran[i].x) && (ran[0].y == ran[i].y))
        {
            return true;
        }
    }
    return false;
}
