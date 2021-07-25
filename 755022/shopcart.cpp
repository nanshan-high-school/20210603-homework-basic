#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

typedef struct shop shop;
struct shop {
    string name;
    int price;
    int stock;
};

int main() {
    shop shopp[] = {
        {.name = "pen", .price = 500, .stock = 10},
        {.name = "bag", .price = 5, .stock = 8},
        {.name = "hat", .price = 20, .stock = 5}
    };

    vector<string> cartname;
    vector<int> cartstock;
    vector<int> cartsubtotal;

    cout << "產品" << "  " << "價格" << "  " << "數量" << "  " << endl;
    for(int i = 0; i < 3; i ++) {
        cout << shopp[i].name  << "  " << shopp[i].price << "  " << shopp[i].stock << "  " << endl;
    }

    int buyname, buystock, total = 0;
    while(true) {
        cout << "輸入要買的產品編號及數量，輸入 0 結束購買：";
        cin >> buyname;
        if (buyname == 0) {
            break;
        }

        cin >> buystock;
        if(shopp[buyname - 1].stock < buystock) {
            cout << "數量不足" << endl;
            continue;
        }

        shopp[buyname - 1].stock -= buystock;

        int subtotal = shopp[buyname - 1].price * buystock;
        total += subtotal;

        cartname.push_back(shopp[buyname - 1].name);
        cartstock.push_back(buystock);
        cartsubtotal.push_back(subtotal);
    }

    string salecode;
    cout << "輸入優惠代碼或按 0 跳過：";
    cin >> salecode;
    if (salecode == "-50") {
        if (total >= 100) {
            total -= 50;
        }
    } else if (salecode == "x0.8") {
        if (total >= 100) {
            total *= 0.8;
        }
    }

    if (salecode == "0") {
        total += 0;
    }

    int shipfree = 0;
    if (total < 490) {
        shipfree = 1;
        total += 60;
    }

    cout << "總金額為：" << total;
    cout << endl << "-----------------" << endl;
    cout << "以下是你的購買明細" << endl;

    for (int i = 0; i < cartname.size(); i++) {
        cout << cartname[i]
            << " * " << cartstock[i]
            << " = " << cartsubtotal[i]
            << endl;
    }

    if (shipfree == 1) {
        cout << endl << "-----------------" << endl;
        cout << "運費 +60" << endl;
    }

    cout << endl << "-----------------" << endl;
    cout << "總金額為：" << total;
}
