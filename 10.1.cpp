#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFile("data.txt");
    if (!inFile.is_open()) {
        cerr << "无法输入" << endl;
        return 1;
    }
    ofstream outFile("newdata.txt");
    if (!outFile.is_open()) {
        cerr << "无法输出" << endl;
        inFile.close();
        return 1;
    }

    string line;
    int lineNumber = 1;
    while (getline(inFile, line)) {
        outFile << lineNumber << ": " << line << endl;
        lineNumber++;
    }

    inFile.close();
    outFile.close();

    cout << "ok" << endl;
    return 0;
}
