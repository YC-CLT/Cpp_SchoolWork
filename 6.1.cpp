#include <iostream>
#include <string>

using namespace std;

class Score {
private:
    int math;
    int eng;

public:
    void input() {
        cout << "请输入数学成绩：";
        cin >> math;
        cout << "请输入英语成绩：";
        cin >> eng;
    }

    void display() const {
        cout << "数学成绩：" << math << endl;
        cout << "英语成绩：" << eng << endl;
    }
};

class Person {
private:
    string name;
    int id;

public:
    void input() {
        cout << "请输入姓名：";
        cin >> name;
        cout << "请输入ID：";
        cin >> id;
    }

    void display() const {
        cout << "姓名：" << name << endl;
        cout << "ID：" << id << endl;
    }
};

class Student : public Person {
private:
    int old;
    string sno;
    Score score; 

public:
    void input() {
        Person::input(); 
        cout << "请输入年龄：";
        cin >> old;
        cout << "请输入学号：";
        cin >> sno;
        cout << "请输入成绩：" << endl;
        score.input(); 
    }

    void display() const {
        Person::display(); 
        cout << "年龄：" << old << endl;
        cout << "学号：" << sno << endl;
        cout << "成绩：" << endl;
        score.display(); 
    }
};

class Teacher : public Person {
private:
    string degree;
    string dep;

public:
    void input() {
        Person::input(); 
        cout << "请输入学历：";
        cin >> degree;
        cout << "请输入所在部门：";
        cin >> dep;
    }

    void display() const {
        Person::display(); 
        cout << "学历：" << degree << endl;
        cout << "所在部门：" << dep << endl;
    }
};

class Stud {
private:
    string addr;
    string tel;

public:
    void input() {
        cout << "请输入地址：";
        cin >> addr;
        cout << "请输入电话：";
        cin >> tel;
    }

    void display() const {
        cout << "地址：" << addr << endl;
        cout << "电话：" << tel << endl;
    }
};

int main() {
    Score c1; 
    Teacher t1;

    cout << "输入 score 对象 c1 的数据：" << endl;
    c1.input();

    cout << "输入 teacher 对象 t1 的数据：" << endl;
    t1.input();

    cout << "\nscore 对象 c1 的数据：" << endl;
    c1.display();

    cout << "teacher 对象 t1 的数据：" << endl;
    t1.display();

    return 0;
}