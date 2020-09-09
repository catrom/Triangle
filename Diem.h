#ifndef DIEM_H
#define DIEM_H

#include <iostream>
using namespace std;

class Diem {
    public:
        Diem();
        virtual ~Diem();
        Diem(float x, float y);

        void nhap();
        void xuat();
        void diChuyen(float vx, float vy);

        float getX() { return this->hoanhDo; }
        void setX(float x) { this->hoanhDo = x; }
        float getY() { return this->tungDo; }
        void setY(float y) { this->tungDo = y; }

    protected:

    private:
        float hoanhDo;
        float tungDo;
};

#endif // DIEM_H
