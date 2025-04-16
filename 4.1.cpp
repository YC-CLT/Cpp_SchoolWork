#include <iostream>
using namespace std;

class Rational {
private:
    int numerator;
    int denominator;
public:
    Rational(int n=1, int d=1) {
        if (d == 0) {
           cerr << "Error: Denominator cannot be zero." << endl;
           exit(1); 
        }
        numerator = n;
        denominator = d;
        simplify();
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b); 
    }

    void simplify() {
        int g = gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;
        if (denominator < 0) { 
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    void print() const {
        cout << double(numerator) / denominator << endl;
        if (denominator == 1)
            cout << numerator << endl;
        else
            cout << numerator << "/" << denominator << endl; 
    }

    Rational operator+(const Rational& other) const {
        return Rational(
            numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator
        );
    }
};

int main() {
    cout << "202478030533邹为一畅" << endl;	
    Rational r1(1, 2);
    Rational r2(3, 4);
    Rational r3 = r1 + r2;
    r3.print();
    return 0; 
}