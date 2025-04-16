#include <iostream>
#include <cmath>
using namespace std;

class HugeInteger {
    private:
        int digits[40];
        int size;
    public:
        HugeInteger() {
            for (int i = 0; i < 40; i++) {
                digits[i] = 0;
            } 
            size = 40;
        }

        void setInteger(int n) {
            for (int i = 0; i < 40; i++) {
                digits[i] = n % 10;
                n /= 10; 
                if (n == 0) {
                    this->size = i + 1;
                }
            }
            for (int i = 0; i < this->size; i++) {
                int temp = digits[i];
                digits[i] = digits[size - i - 1];
                digits[size - i - 1] = temp;
            }
        }
        void setInteger() {
            cout << "输入位数: ";
            cin >> size;
            if (size > 40) {
                cout << "位数超出限制" << endl;
                exit(1);
            }
            cout << "一个位一个位的输入: ";
                for (int i = 0; i < size; i++) {
                    cin >> digits[i]; 
                }
            }

        void print() {
            int i = 39;
            for (; i >= 0; i--) {
                if (digits[i] != 0)
                    break; 
            }
            for (int j = 0; j <= i; j++) {
                cout << digits[j]; 
            }
            cout << endl;
        }

        void add(HugeInteger& other, HugeInteger& result) {
            for (int i = 0; i < 40; i++) {
                result.digits[i] = this->digits[i] + other.digits[i];
            if (result.digits[i] >= 10) {
                result.digits[i] -= 10;
                result.digits[i + 1] += 1;
            }
        }
    }
};

int main() {
    cout << "202478030533 邹为一畅" << endl;
    HugeInteger h1;
    h1.setInteger(); 
    HugeInteger h2;
    h2.setInteger();
    HugeInteger h3;
    h1.add(h2, h3);
    h3.print();
    int n;
    cout << "输入一个整数: ";
    cin >> n;
    HugeInteger h4;
    h4.setInteger(n);
    h4.print();
    return 0;
}