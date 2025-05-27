#include <iostream>
#include <algorithm>
#include <vector>
#include <functional> 
using namespace std;

int main() {
    
    vector<int> numbers = {1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    
    
    int target = 8;
    auto it = find(numbers.begin(), numbers.end(), target);
    if (it != numbers.end()) {
        cout << "元素 " << target << " 在数组中的位置是: " 
                  << distance(numbers.begin(), it) << endl;
    } else {
        cout << "未找到元素 " << target << endl;
    }
    
    
    sort(numbers.begin(), numbers.end());
    cout << "升序排序结果: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    
    sort(numbers.begin(), numbers.end(), greater<int>());
    cout << "降序排序结果: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
