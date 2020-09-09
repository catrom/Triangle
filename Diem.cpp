#include "Diem.h"

Diem::Diem() {
    this->hoanhDo = 0;
    this->tungDo = 0;
}

Diem::Diem(float x, float y) {
    this->hoanhDo = x;
    this->tungDo = y;
}

Diem::~Diem() {
}

void Diem::nhap() {
    cout << "Nhap hoanh do: ";
    cin >> this->hoanhDo;
    cout << "Nhap tung do: ";
    cin >> this->tungDo;
}

void Diem::xuat() {
    cout << " (" << this->hoanhDo << "," << this->tungDo << ") ";
}

void Diem::diChuyen(float vx, float vy) {
    this->hoanhDo += vx;
    this->tungDo += vy;
}
