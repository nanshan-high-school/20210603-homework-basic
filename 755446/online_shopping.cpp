//-------------struct版本--------------//
//我改好少.....
#include <iostream>
#include <vector>
using namespace std;

struct product {
    string name;
    int price;
    int stocks;
};
/*struct cart {
    string names;
    int count;
    int sub_total;
};*/

int main() {
    product product[3];
    product[0].name = "product 1";
    product[0].price = 10;
    product[0].stocks = 7;
    product[1].name = "product 2";
    product[1].price = 40;
    product[1].stocks = 3;
    product[2].name = "product 3";
    product[2].price = 150;
    product[2].stocks = 10;

    vector<string> cartBuyProductName;
    vector<int> cartBuyCount;
    vector<int> cartBuySubTotal;

    int buyProduct;
    int buyCount;
    int total = 0;
    while (true) {
        cout << "輸入要買的產品編號及數量，輸入 0 結束購買： ";
        
        cin >> buyProduct;
        if (buyProduct == 0) {
            break;
        }

        cin >> buyCount;
        
        if (product[buyProduct - 1].stocks < buyCount) {
            cout << "數量不足" << endl;
            continue;
        }

        product[buyProduct - 1].stocks -= buyCount;

        int subTotal = product[buyProduct - 1].price * buyCount;
        total += subTotal;

        cartBuyProductName.push_back(product[buyProduct - 1].name);
        cartBuyCount.push_back(buyCount);
        cartBuySubTotal.push_back(subTotal);
    }
    
    string code;
    cout << "輸入優惠代碼或輸入 0 跳過: ";
    cin >> code;

    bool discount = false;

    if (code == "-50") {
        if (total >= 100) {
            total -= 50;
            discount = true;
        }
    } else if (code == "x0.8") {
        if (total >= 100) {
            total *= 0.8;
            discount = true;
        }
    }

    bool hasShippingFee = false;

    if (total < 490 && total != 0) {
        hasShippingFee = true;
        total += 60;
    }

    //cout << "總金額為：" << total;

    cout << endl << "-----------------" << endl;
    cout << "以下是你的購買明細:" << endl;
    int sub;
    for (int i = 0; i < cartBuyProductName.size(); i++) {
        cout << cartBuyProductName[i]
            << " * " << cartBuyCount[i]
            << " = " << cartBuySubTotal[i]
            << endl;
        sub += cartBuySubTotal[i];
    }
    if (discount) {
        cout << "使用折價卷 折抵: " << sub - total << endl;
    }

    if (hasShippingFee) {
        cout << endl << "-----------------" << endl;
        cout << "運費 60" << endl;
    }

    cout << endl << "-----------------" << endl;

    cout << "總金額為：" << total << endl;
}
