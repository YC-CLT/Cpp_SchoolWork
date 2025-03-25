#include <iostream>
using namespace std;

class Complex {
    private:
        int real, imag;
    public:
        Complex(int r = 0, int i =0):real(r),imag(i){};
        ~Complex(){};
        void setNunber(){
            cout << "Please enter the real and imaginary part of the complex number respectively:"<<endl;
            cin >> real >> imag;
        }
        void getNumber(){
            cout << "The complex number is: "<<real<<"+"<<imag<<"i"<<endl;
        }
};
int main(){
    cout << "202478030533邹为一畅"<<endl;
    Complex c1,c3;
    cout << "obj: "<<endl;
    c1.setNunber();
    c1.getNumber();

    Complex *c2=new Complex;
    cout << "ptr: "<<endl;
    c2->setNunber();
    c2->getNumber();
    delete c2;

    Complex &c4=c3;
    cout << "ref: "<<endl;
    c4.setNunber();
    c4.getNumber();

    return 0;
}