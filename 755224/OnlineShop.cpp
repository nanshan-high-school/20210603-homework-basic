#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    struct item {
        string name;
        int price;
        int instock;
    };
    vector<item> stock;
    cout << "品名     價格 庫存\n";
    stock.push_back({"Orange", 18, 23});
    stock.push_back({"Banana", 12, 45});
    stock.push_back({"Potato", 10, 36});
    for (auto temp: stock) {
        cout << temp.name << "    " << temp.price << "   " << temp.instock << endl;
    }
    vector<int> purchase_list (3,0);
    cout << "\n\n使用者輸入格式：商品名稱 修改數量（兩者之間要有半形空格）\n";
    cout << "若要結帳，請輸入：End\n";
    while (true) {
        string temp_string;
        cin >> temp_string;
        if (temp_string == "End") {
            break;
        }
        int quantity;
        cin >> quantity;
        for (int i = 0; i < 3; i++) {
            if (temp_string == stock[i].name) {
                if (quantity + purchase_list[i] > stock[i].instock) {
                    cout << "要求量過多，本商品只剩 " << 
                        stock[i].instock << " 個\n";
                    continue;
                }
                if (quantity + purchase_list[i] < 0) {
                    cout << "不能購買負數數量個東西！\n";
                    continue;
                }
                purchase_list[i] += quantity;
                cout << "現在 " << temp_string << " 的購買量：" << purchase_list[i] << endl;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < stock.size(); i++) {
        total += stock[i].price * purchase_list[i];
    }
    if (total <= 0) {
        return 0;
    }
    int discount = 0;
    cout << "\n\n您現在的消費金額為：" << total << " 元\n";
    cout << "若有優惠代碼，請現在輸入（沒有的話，請輸入：No）：";
    while(true) {
        string coupon;
        cin >> coupon;
        if (coupon == "No") {
            break;
        }
        if (coupon == "C-L") {
            if (total < 100) {
                cout << "金額不足 100 元，無法折扣\n優惠代碼：";
                continue;
            }
            total -= 50;
            discount = 50;
            cout << "折價成功，現在消費金額為：" << total << " 元\n";
            break;
        }
        if (coupon == ">C*.8") {
            if (total < 100) {
                cout << "金額不足 100 元，無法折扣\n優惠代碼：";
                continue;
            }
            total = ceil(total * 0.8);
            discount = total / 5;
            cout << "折價成功，現在消費金額為：" << total << " 元\n";
            break;
        }
    }

    cout << "您的消費金額為 "<< total << " 元";
    bool shipping = 0;
    if (total < 490) {
        cout << "，未超過 490 元，所以需支付 60 元的運費\n\n\n";
        shipping = 1;
        total += 60;
    } else {
        cout << "，超過了 490 元，所以不用付運費\n\n\n";
    }
    for (int i = 0; i < 3; i++) {
        if (purchase_list[i] == 0) {
            break;
        }
        cout << stock[i].name << ' ' << purchase_list[i] << " 個，" << purchase_list[i] * stock[i].price << " 元\n";
    }
    cout << "原始總金額：" << total << " 元"<< endl;
    if (discount != 0) {
        cout << "折價：" << discount << " 元" << endl;
    }
    if (shipping) {
        cout << "運費：60 元\n";
    }
    cout << "最終總金額：" << total << "\n感謝您的消費";
}
