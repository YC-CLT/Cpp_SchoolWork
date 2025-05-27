#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main() {
    ifstream fileA("a.txt");
    ifstream fileB("b.txt");
    ofstream fileC("c.txt");

    if (!fileA.is_open() || !fileB.is_open()) {
        cerr << "输入错误" << endl;
        return 1;
    }

    vector<char> mergedChars;

    char ch;
    while (fileA.get(ch)) {
        if (isalpha(ch)) {  
            mergedChars.push_back(toupper(ch));  
        }
    }

    while (fileB.get(ch)) {
        if (isalpha(ch)) {
            mergedChars.push_back(toupper(ch));
        }
    }

    sort(mergedChars.begin(), mergedChars.end());

    fileC << "    ";  
    for (char c : mergedChars) {
        fileC << c;
    }

    fileA.close();
    fileB.close();
    fileC.close();

    cout << "ok" << endl;
    return 0;
}
