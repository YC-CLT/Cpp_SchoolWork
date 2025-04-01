#include <iostream>
using namespace std;

class CPoint {
    public:
        CPoint(): x(0), y(0) {};
        CPoint(int xv, int yv) : x(xv), y(yv) {};
        CPoint( CPoint& A) : x(A.x), y(A.y) {};

        void Print()  {
            cout << "(" << x << ", " << y << ")" << endl;
        }

    ~CPoint(){};

    private:
    int x;
    int y;
};


int main() {
    cout << "202478030533邹为一畅"<<endl;

    CPoint point1;
    cout << "直接";
    point1.Print();

    int a, b;
    cout << "请输入两个整数：";
    cin >> a >> b;

    CPoint point2(a, b);
    cout << "构造";
    point2.Print();  

    CPoint point3(point2);
    cout << "拷贝";
    point3.Print();  
    return 0;
}