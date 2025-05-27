#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    string id;
    string gender;
};

void writeToFile(const Student& stu, ofstream& outFile) {
    outFile << "姓名:" << stu.name << endl;
    outFile << "学号:" << stu.id << endl;
    outFile << "性别:" << stu.gender << endl << endl;
}

void displayFromFile() {
    ifstream inFile("stureginfo.txt");
    string line;
    
    cout << "\n所有注册学生信息如下:\n";
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

int main() {
    ofstream outFile("stureginfo.txt", ios::app);
    Student stu;
    
    cout << "输入格式:姓名 学号 性别 (输入0 0 0结束)" << endl;
    
    while (true) {
        cout << "\n请输入学生信息(姓名 学号 性别): ";
        cin >> stu.name >> stu.id >> stu.gender;
        
        if (stu.name == "0" && stu.id == "0" && stu.gender == "0") {
            break;
        }
        
        writeToFile(stu, outFile);
        cout << "ok" << endl;
    }
    
    outFile.close();
    displayFromFile();
    
    return 0;
}
