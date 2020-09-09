#include <iostream>
#include <windows.h>
#include "graphics.h"
#include "Diem.h"
#include "tamGiac.h"

using namespace std;

int main() {
    system("mode 40, 21");
    initwindow(800, 600);

    int choose;
    float vx, vy;
    float anpha;
    float tiLe;
    tamGiac A;
    A.veHeTruc();

    while(true) {
        system("cls");
        A.setConsoleColor(15);

        cout << "--------| MENU |--------\n";
        cout << "1. Nhap cac dinh tam giac\n";
        cout << "2. Xuat tam giac\n";
        cout << "3. Tinh tien\n";
        cout << "4. Phep quay\n";
        cout << "5. Thu phong\n";
        cout << "6. Thao tac tren che do do hoa\n";
        cout << "7. Thoat chuong trinh\n\n";
        cout << "--> "; cin >> choose;

        switch (choose) {
            case 1: A.veTamGiac(0); // xoá tam giác cũ trên màn hình đồ hoạ
                    A.veHeTruc();
                    A.nhap();
                    break;
            case 2: A.veTamGiac(10);
                    A.xuat();
                    _getch();
                    break;
            case 3: cout << "\nNhap vx : "; cin >> vx;
                    cout << "Nhap vy: "; cin >> vy;
                    A.veTamGiac(0); // xoá tam giác cũ trên màn hình đồ hoạ
                    A.xuLiDiChuyen(vx, vy);
                    A.veTamGiac(10);
                    _getch();
                    break;
            case 4: cout << "\nNhap goc anpha : "; cin >> anpha;
                    A.veTamGiac(0); // xoá tam giác cũ trên màn hình đồ hoạ
                    A.xuLiPhepQuay(anpha);
                    A.veTamGiac(10);
                    _getch();
                    break;
            case 5: cout << "\nNhap ti le thu phong : "; cin >> tiLe;
                    A.veTamGiac(0); // xoá tam giác cũ trên màn hình đồ hoạ
                    A.xuLiThuPhong(tiLe);
                    A.veTamGiac(10);
                    _getch();
                    break;
            case 6: A.xuLiNhanPhim();
                    break;
            case 7: closegraph();
                    return 0;
        }
    }

    closegraph();
    return 0;
}
