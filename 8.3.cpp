#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string num;
    string name;
    string sex;
    
public:

    Student(const string& num, const string& name, const string& sex) 
        : num(num), name(name), sex(sex) {}
    
    string getNum() const { return num; }
    string getName() const { return name; }
    string getSex() const { return sex; }
};

class Teacher {
private:
    string num;
    string name;
    string sex;
    
public:

    Teacher(const string& num, const string& name, const string& sex) 
        : num(num), name(name), sex(sex) {}
    
    // 转换
    Teacher(const Student& student) 
        : num(student.getNum()), name(student.getName()), sex(student.getSex()) {}
    
    void displayInfo() const {
        cout << "教师信息:" << endl;
        cout << "教工号: " << num << endl;
        cout << "姓名: " << name << endl;
        cout << "性别: " << sex << endl;
    }
};

int main() {

    Student student("1145141919810", "田所浩二", "男");
    
    // 转换
    Teacher teacher(student);
    
    teacher.displayInfo();
    
    return 0;
}