#include <iostream>
using namespace std;

int main() {
    struct shop {
        string name;
        int cost;
        int store;
    };

    shop product[3] = {
        {"a", 50, 10},
        {"b", 100, 20},
        {"c", 150, 30}
    };

    int buyNum = 0;
    int sum;
    int SelfBuyNum[3];
    int SelfCost[3];

    for (int i = 0; i < 3; i++) {
        cout << "購買" << product[i].name << "產品幾個: ";

        do {
            cin >> buyNum;
            if (buyNum > product[i].store) {
                cout << "數量不足，請重新輸入: ";
            }
        } while (buyNum > product[i].store);
        
        sum = sum + product[i].cost * buyNum;
        SelfBuyNum[i] = buyNum;
        SelfCost[i] = product[i].cost * buyNum;
    }
    
    string disacount[2] = {"s-50", "s*0.8"};

    cout << "輸入優惠代碼(沒有則填「0」): ";

    string inDisacount;
    cin >> inDisacount;
    int oriSum = sum;

    if (inDisacount == disacount[0]) {
        if (sum >= 100) {
            sum -= 50;
        } else {
            cout << "未滿100" << endl;
        }
    } else if (inDisacount == disacount[1]) {
        if (sum >= 100) {
            sum *= 0.8;
        } else {
            cout << "未滿100" << endl;
        }
    }

    int disacountNum = oriSum - sum;

    int shipFee = 0;
    if (sum < 490) {
        sum += 60;
        shipFee = 60;
    }

    cout << endl << "--------------------" << endl;
    cout << "------交易明細------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "購買" << product[i].name << ": " << SelfBuyNum[i] << "個，花費" << SelfCost[i] << "元" << endl;
    }
    cout << "優惠代碼折價" << disacountNum << "元" << endl;
    cout << "運費" << shipFee << "元" << endl;
    cout << "總金額為: " << sum << endl;
    cout << "--------------------" << endl;
    cout << "--------------------";
}
