#include <iostream>
#include <string>
using namespace std;

class CException {
private:
    string type; 

public:
    CException(const string& t) : type(t) {}
    
    void Reason() const {
        cout << "Type: " << type << endl;
    }
};

// 触发异常
void fn1() {
    throw CException("Error");  // 抛出自定义异常
}

int main() {
    try {
        fn1();  // 调用可能抛出异常的函数
        cout << "This line won't be executed." << endl;
    } 
    catch (const CException& e) {
        e.Reason();  // 处理异常
    }
    
    return 0;
}
