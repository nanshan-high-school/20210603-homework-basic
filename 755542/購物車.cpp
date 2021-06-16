#include <iostream>
using namespace std;
int main() {
    struct buy {
        string names[3] = {"A", "B", "C"};
        int money[3] = {10, 20, 30};
        int box[3] = {50, 100, 150};
    };
    buy buy_struct;

    int to_total = 0;
    int total = 0;
    int name;
    int num;

    int outbox_ABC[3] = {0};
    int spend_ABC[3] = {0};

    while (true) {
        cout << "輸入要買的產品編號及數量，輸入 0 結束購買：";
        cin >> name;
        if (name == 0) {
            break;
        }

        cin >> num;
        
        if (buy_struct.box[name - 1] < num) {
            cout << "數量不足" << "\n";
            continue;
        }

        buy_struct.box[name - 1] -= num;
        outbox_ABC[name - 1] += num;

        to_total = buy_struct.money[name - 1] * num;
        total += to_total;
        spend_ABC[name - 1] += to_total;
    }
    int total_true = 0;
    total_true = total;

    string code;
    bool hasDiscount = false;

    
    if (total >= 100) {
        cout << "輸入優惠代碼或輸入 0 跳過:";
        cin >> code;
        if (code == "jack") {
            total -= 50;
            hasDiscount = true;
        } else if (code == "goodjack") {
            total *= 0.8;
            hasDiscount = true;
        } else if (code == "0") {
        } else {
            cout << "優惠代碼無效";
        }
    } else {
        cout << "未滿100元，無法使用折價券";
    }
    
    if (hasDiscount) {
        cout << "使用折價卷折抵:" << (total_true - total) << "元";
    }

    bool hasmove = false;
    if (total < 490) {
        hasmove = true;
        total += 60;
    }

    cout << "\n" << "-----------------" << "\n";
    cout << "購買明細" << "\n";
    for (int i = 0; i < 3; i++) {
        cout << buy_struct.names[i] << " " << "*" << " " << outbox_ABC[i] << " " << "=" << " " << spend_ABC[i] << "元" << "\n";
    }

    if (hasmove) {
        cout << "-----------------" << "\n";
        cout << "運費:60元" << "\n";
    }

    cout << "-----------------" << "\n";
    cout << "總金額為：" << total << "元";
}
