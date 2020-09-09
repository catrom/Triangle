#ifndef TAMGIAC_H
#define TAMGIAC_H

#include <iostream>
#include <math.h>
#include <conio.h>
#include "Diem.h"
#include "graphics.h"
using namespace std;

class tamGiac {
    public:
        tamGiac();
        virtual ~tamGiac();
        tamGiac(Diem danhSachDiem[]); // khởi tạo tam giác từ mảng các điểm có sẵn

        void nhap();
        void xuat();

        void xuLiDiChuyen(float vx, float vy);
        void xuLiPhepQuay(float anpha);
        void xuLiThuPhong(float tiLe);
        void xuLiNhanPhim();

        void veHeTruc();
        void veTamGiac(int color);
        void xacDinhTrucTam(); // xác định trực tâm, dùng cho việc thu phóng tam giác

        void setConsoleColor(int color); // đặt màu chữ trong màn hình console

    protected:

    private:
        Diem *Dinh;
        Diem trucTam;
};

#endif // TAMGIAC_H
