#include "tamGiac.h"
#include <cstring>
tamGiac::tamGiac() {
    this->Dinh = new Diem[3];
    this->Dinh[0] = Diem(0,0);
    this->Dinh[1] = Diem(0,1);
    this->Dinh[2] = Diem(1,0);
}

tamGiac::~tamGiac() {
    delete []this->Dinh;
    this->Dinh = NULL;
}

tamGiac::tamGiac(Diem danhSachDiem[]) {
    this->Dinh = new Diem[3];
    for(int i = 0; i < 3; i++) {
        this->Dinh[i] = danhSachDiem[i];
    }
}

void tamGiac::nhap() {
    for(int i = 0; i < 3; i++) {
        cout << "Dinh " << i + 1 << " :\n";
        this->Dinh[i].nhap();
    }
}

void tamGiac::xuat() {
    cout << "\nCac dinh cua tam giac : ";
    for(int i = 0; i < 3; i++) {
        cout << endl;
        this->setConsoleColor(12 + i);
        this->Dinh[i].xuat();
    }
}

void tamGiac::xuLiDiChuyen(float vx, float vy) {
    for(int i = 0; i < 3; i++) {
        this->Dinh[i].diChuyen(vx, vy);
    }
}

void tamGiac::xuLiPhepQuay(float anpha) {
    for(int i = 0; i < 3; i++) {
        float x = this->Dinh[i].getX();
        float y = this->Dinh[i].getY();
        this->Dinh[i].setX(1.0 * x * cos(anpha) - 1.0 * y * sin(anpha));
        this->Dinh[i].setY(1.0 * x * sin(anpha) + 1.0 * y * cos(anpha));
    }
}

void tamGiac::xacDinhTrucTam() {
    float a = this->Dinh[2].getX() - this->Dinh[1].getX(),
          b = this->Dinh[2].getY() - this->Dinh[1].getY(),
          c = this->Dinh[0].getX() * a + this->Dinh[0].getY() * b,
          d = this->Dinh[2].getX() - this->Dinh[0].getX(),
          e = this->Dinh[2].getY() - this->Dinh[0].getY(),
          f = this->Dinh[1].getX() * d + this->Dinh[1].getY() * e;

    float D = a * e - b * d,
          Dx = c * e - b * f,
          Dy = a * f - c * d;

    this->trucTam.setX(Dx / D);
    this->trucTam.setY(Dy / D);
}

void tamGiac::xuLiThuPhong(float tiLe) {
    this->xacDinhTrucTam();
    for(int i = 0; i < 3; i++) {
        float a = this->trucTam.getX() + tiLe * (this->Dinh[i].getX() - this->trucTam.getX()),
              b = this->trucTam.getY() + tiLe * (this->Dinh[i].getY() - this->trucTam.getY());
        this->Dinh[i].setX(a);
        this->Dinh[i].setY(b);
    }
}

void tamGiac::veHeTruc() {
    setcolor(7);
    setlinestyle(0, 0, 1);

    line(400, 0, 400, 600);
    line(0, 300, 800, 300);

    for(int i = 25; i < 600; i += 25) { circle(400, i, 2); }
    for(int i = 25; i < 800; i += 25) { circle(i, 300, 2); }
}

void tamGiac::veTamGiac(int color) {
    this->veHeTruc();
    setcolor(color);
    setlinestyle(0, 0, 2);

    for(int i = 0; i < 2; i++) {
        for(int j = i + 1; j < 3; j++) {
            line(this->Dinh[i].getX() * 25 + 400, this->Dinh[i].getY() * -25 + 300,
                this->Dinh[j].getX() * 25 + 400, this->Dinh[j].getY() * -25 + 300);
        }
    }

    for(int i = 0; i < 3; i++) {
        setcolor(color ? 12 + i : color);
        circle(this->Dinh[i].getX() * 25 + 400, this->Dinh[i].getY() * -25 + 300, 3);
    }

    kbhit();
}

void tamGiac::xuLiNhanPhim() {
    while(true) {
        system("cls");
        this->veTamGiac(10);

        this->setConsoleColor(15);
        cout << "{ UP, RIGHT, LEFT, DOWN } de di chuyen\n";
        cout << "{ I / O } de phong to / thu nho\n";
        cout << "{ W / S } de quay tam giac\n";
        cout << "ESC de thoat chuong trinh\n";
        this->xuat();

        char c = getch();

        this->veTamGiac(0); // xoá tam giác cũ trên màn hình đồ hoạ

        if(c == 224) c = getch();  // bắt phím điều hướng
        if(c == 72) { // di chuyển lên
            this->xuLiDiChuyen(0,0.1);
        } else if(c == 80) { // di chuyển xuống
            this->xuLiDiChuyen(0,-0.1);
        } else if(c == 77) { // di chuyển sang phải
            this->xuLiDiChuyen(0.1,0);
        } else if(c == 75) { // di chuyển sang trái
            this->xuLiDiChuyen(-0.1,0);
        } else if(c == 'w' || c == 'W') {  // quay ngược chiều kim đồng hồ
            this->xuLiPhepQuay(0.05);
        } else if(c == 's' || c == 'S') {  // quay theo chiều kim đồng hồ
            this->xuLiPhepQuay(-0.05);
        } else if(c == 'i' || c == 'I') {  // phóng to
            this->xuLiThuPhong(1.05);
        } else if(c == 'o' || c == 'O') {  // thu nhỏ
            this->xuLiThuPhong(0.95);
        } else if(c == 27) { // thoát chương trình
            return;
        }
    }
}

void tamGiac::setConsoleColor(int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}

