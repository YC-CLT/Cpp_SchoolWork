#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 定义公有货物类
class Goods {
public:
    int id;      // 编号
    double weight;  // 重量/kg
    double price;   // 价格/元
};

// 定义商店类
class Store {
private:
    vector<Goods> inventory; // 库存货物
    double totalWeight;      // 库存总重

public:
Store() : totalWeight(0) {}//构造
//买操作
    void purchaseGoods(const int& id, double weight, double price) {
        Goods newGoods = {id, weight, price};//直接赋值
        inventory.push_back(newGoods);//增加值
        totalWeight += weight;
        cout << "购入: 编号=" << id << ", 重量=" << weight << "kg, 价格=" << price << "元" << endl;
    }

    // 卖操作
    bool sellGoods(const int& id, double weight) {
        for (auto& goods : inventory) {
            if (goods.id == id) {
                if (goods.weight >= weight) {//判断够不够
                    goods.weight -= weight;
                    totalWeight -= weight;
                    cout << "卖出: 编号=" << id << ", 重量=" << weight << "kg" << endl;
                    return true;
                } else {
                    cout << "库存不足: 编号=" << id << ", 当前库存=" << goods.weight << "kg" << endl;
                    return false;
                }
            }
        }//异常处理
        cout << "未找到货物: 编号=" << id << endl;
        return false;
    }

    // 显示库存
    void displayInventory() const {
        cout << "当前库存:" << endl;
        for (const auto& goods : inventory) {
            cout << "编号: " << goods.id
                 << ", 重量: " << goods.weight << "kg"
                 << ", 价格: " << goods.price << "元" << endl;
        }
        cout << "库存总重: " << totalWeight << "kg" << endl;
    }
};

int main() {
    cout << "202478030533邹为一畅" << endl;
    Store store;

    // 模拟购入
    store.purchaseGoods(1, 100.5, 50.0); // 购进编号1的货物，重量100.5kg，价格50元
    store.purchaseGoods(2, 200.0, 60.0); // 购进编号2的货物，重量200kg，价格60元
    store.purchaseGoods(3, 150.3, 45.0); // 购进编号3的货物，重量150.3kg，价格45元

    // 显示库存
    store.displayInventory();

    // 模拟卖出货物
    store.sellGoods(1, 30.5); // 卖出编号G001的货物，重量30.5kg
    store.sellGoods(2, 100.0); // 卖出编号G002的货物，重量100kg
    store.sellGoods(4, 50.0);  // 卖出不存在的货物试试

    // 显示库存
    store.displayInventory();

    return 0;
}