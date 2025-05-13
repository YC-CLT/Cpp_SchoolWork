#include <iostream>
using namespace std;

class Point {
private:
    int x,y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // 前++
    Point& operator++() {
        ++x       ;
 ++y;
        return *this;
    }

    // 后++
    Point operator++(int) {
        Point temp = *this; // 当前
        ++x;
        ++y;
        return temp; // 自增前
    }

    // 输出流运算符
    friend ostream& operator<<(ostream& os, const Point& p);

    int getX() const { return x; }

    int getY() const { return y; }

    void setX(int x) { this->x = x; }

    void setY(int y) { this->y = y; }
};

    // 输出流运算符的实现
    ostream& operator<<(ostream& os, const Point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }

int main() {
    // 前++
    Point p1(2, 3);
    cout << "前++:" << endl;
    cout << "p1: " << p1 << endl;
    ++p1;
    cout << "前++后的p1: " << p1 << endl;

    // 后++
    Point p2(4, 5);
    cout << "\n后++:" << endl;
    cout << "初始p2: " << p2 << endl;
    Point p3 = p2++; // 后++，先保存再自增
    cout << "后++后的p2: " << p2 << endl;
    cout << "后++前的p3: " << p3 << endl;

    // 输出流
    cout << "\n输出流:" << endl;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;

    // 连续前++
    cout << "\n连续前++:" << endl;
    Point p4(0, 0);
    cout << "初始p4: " << p4 << endl;
    ++(++p4);
    cout << "连续前++后的p4: " << p4 << endl;

    // 连续后++
    cout << "\n连续后++:" << endl;
    Point p5(0, 0);
    cout << "初始p5: " << p5 << endl;
    p5++;
    p5++;
    cout << "连续后++的p5: " << p5 << endl;

    return 0;
}