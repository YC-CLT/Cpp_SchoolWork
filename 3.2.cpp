#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CStudent {
private:
    string name;
    string studentID;
    vector<double> grades;

public:

    CStudent(){};
    ~CStudent(){};	
    void inputInfo() {
        cout << "请输入学生姓名: "<<endl;
        cin >> name;
        cout << "请输入学号: "<<endl;
        cin >> studentID;
        
        int numCourses=3;
        cout << "请输入课程数量: "<<endl;
        cin >> numCourses;
        
        grades.resize(numCourses);
        for (int i = 0; i < numCourses; i++) {
            cout << "请输入第" << i + 1 << "门课程的成绩: ";
            cin >> grades[i];
        }
    }

    double avg(){
        if (grades.empty()) return 0.0;
        double sum = 0.0;
        for (auto grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

    void printInfo(){
        cout << "学生姓名: " << name << endl;
        cout << "学号: " << studentID << endl;
        cout << "各科成绩: ";
        for (int i = 0; i < grades.size(); i++) {
            cout << grades[i];
            if (i < grades.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        cout << "平均成绩: " << avg() << endl;
    }

    bool isFail(){
        return avg() < 60.0;
    }
};

int main() {
    cout << "202478030533邹为一畅"<<endl;
    int numStudents;
    cout << "请输入学生数量: ";
    cin >> numStudents;

    CStudent students[numStudents];

    for (int i = 0; i < numStudents; i++) {
        cout << "\n输入第" << i + 1 << "个学生的信息:" << endl;
        students[i].inputInfo();
    }

    cout << "\n所有学生信息:" << endl;
    for (int i = 0; i < numStudents; i++) {
        cout << "\n学生 " << i + 1 << " 信息:" << endl;
        students[i].printInfo();
    }

    int failCount = 0;
    for (int i = 0; i < numStudents; i++) {
        if (students[i].isFail()) {
            failCount++;
        }
    }
    cout << "\n不及格学生人数: " << failCount << endl;

    return 0;
}