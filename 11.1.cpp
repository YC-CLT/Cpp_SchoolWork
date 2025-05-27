#include <iostream>
#include <cctype>
using namespace std;

int main() {
    string current_num;
    int index = 1;
    char c;
    
    while (cin.get(c)) { 
        if (isdigit(c)) {
            current_num += c;  
        } else {
            if (!current_num.empty()) {  
                cout << "Digit string " << index++ << " is: " << current_num << endl;
                current_num.clear();
            }
        }
    }
    
    if (!current_num.empty()) {
        cout << "Digit string " << index << " is: " << current_num << endl;
    }
    
    return 0;
}
