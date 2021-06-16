#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<string> productnames = {"product 1", "product 2", "product 3"};
    vector<int> productprices = {100, 200, 300};
    vector<int> productstocks = {5, 5, 5};

    vector<string> cartproductnames;
    vector<int> cartproductcounts;
    vector<int> cartproducttotal;

    int buyproduct;
    int buycount;
    int total;

    while (true) {
        cout << "請輸入要買的產品編號及數量，輸入0結束:";

        cin >> buyproduct;

        if (buyproduct == 0) {
            break;
        }

        cin >> buycount;

        if (buycount > productstocks[buyproduct - 1]) {
            cout << "數量不足" << endl;
            continue;
        }

        productstocks[buyproduct - 1] -= buycount;

        int atotal = productprices[buyproduct - 1] * buycount;
        total += atotal;

        cartproductnames.push_back(productnames[buyproduct - 1]);
        cartproductcounts.push_back(buycount);
        cartproducttotal.push_back(atotal);
    }

    string code;
    cout << "輸入優惠代碼:";
    cin >> code;
    
    if (code == "-50") {
        if (total >= 100) {
            total -= 50;
        }
    } else if (code == "*0.8") {
        if (total >= 100) {
            total *= 0.8;
        }
    }

    bool shipping = false;
    
    if (total < 490) {
        shipping = true;
        total += 60;
    }

    cout << "總金額為:" << total << endl;

    cout << "------------------------" << endl;
    cout << "以下為你的購物明細" << endl;

    for (int i = 0; i < cartproductnames.size(); i++) {
        cout << cartproductnames[i] 
             << "*" << cartproductcounts[i] 
             << "=" << cartproducttotal[i] 
             << endl;
    }

    if (shipping == true) {
        cout << "------------------------" << endl;
        cout << "運費60" << endl;
    }
    cout << "------------------------" << endl;
    cout << "總金額為:" << total;
}
