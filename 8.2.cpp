#include <iostream>

class Matrix {
private:
    double elements[2][3]; 

public:
    //初始化
    Matrix() {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                elements[i][j] = 0.0;
    }

    // +运算
    Matrix operator+(const Matrix& other) const {
        Matrix result;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                result.elements[i][j] = elements[i][j] + other.elements[i][j];
        return result;
    }

    // <<运算
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j)
                os << matrix.elements[i][j] << "\t";
            os << std::endl;
        }
        return os;
    }

    // >>运算
    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                is >> matrix.elements[i][j];
        return is;
    }
};

int main() {
    Matrix a, b, c;

    std::cout << "请输入2×3矩阵a的元素：" << std::endl;
    std::cin >> a;

    std::cout << "请输入2×3矩阵b的元素：" << std::endl;
    std::cin >> b;

    c = a + b;

    std::cout << "矩阵a是：" << std::endl;
    std::cout << a << std::endl;

    std::cout << "矩阵b是：" << std::endl;
    std::cout << b << std::endl;

    std::cout << "矩阵a + b的结果是：" << std::endl;
    std::cout << c << std::endl;

    return 0;
}