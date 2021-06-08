#include <iostream>
#include <vector>
using namespace std;

struct goods {
    vector<string> name;
    vector<int> prize;
    vector<int> num;
};

int main() {
    goods product;
    product.name = {"apple", "banana", "candy"};
    product.prize = {20, 35, 31};
    product.num = {7, 6, 7};

    goods buy;
    buy.name = {};
    buy.prize = {};
    buy.num = {};

    int the_id;
    int total = 0;
    string ID_50 = "GF356AS";
    string ID_08 = "QWER321";
    cout << "Name,Prize,Availble" << endl;
    for (int i = 0; i < size(product.name); i++) {
        cout << i + 1 << "." <<product.name[i] << "," 
            << product.prize[i] << "," << product.num[i] << endl;
    }
    cout << "請輸入產品代碼(停止請輸入 負數 ):";
    cin >> the_id;
    while (the_id >= 1) {
        int buy_num;
        the_id -= 1; //品項在vector的位置會-1
        if (the_id >= size(product.name)) {
            system("clear");
            cout << "沒有這個品項喔，請在試一次 >.<" << endl; // 位置和總產品數相同時也需要跳出 
        } else {
            string the_name;
            the_name = product.name[the_id];
            cout << "輸入購買數量:";
            cin >> buy_num;
            int buy_id = -1;
            for (int i = 0; i < size(buy.name); i++) {
                if (buy.name[i] == the_name) buy_id = i;
            }
            if (buy_id == -1) {
                system("clear");
                if (buy_num > product.num[the_id]) {
                    cout << "供給數量不足@@，請重新輸入!!-" << endl;
                } else {
                    buy.name.push_back(the_name);
                    buy.prize.push_back(product.prize[the_id]);
                    buy.num.push_back(buy_num);

                    product.num[the_id] -= buy_num;
                    total += (buy_num * product.prize[the_id]);
                }
            } else {
                system("clear");
                if (buy_num > product.num[the_id]) {
                    cout << "供給數量不足@@，請重新輸入!!" << endl;
                } else {
                    buy.num[buy_id] += buy_num;
                    product.num[the_id] -= buy_num;
                    total += (buy_num * product.prize[the_id]);
                }
            }
        }
        cout << "Name,Prize,Availble" << endl;
        for (int i = 0; i < size(product.name); i++) {
            cout << i + 1 << "." << product.name[i] << "," 
                << product.prize[i] << "," << product.num[i] << endl;
        }
        cout << "請輸入產品名稱(停止請輸入 負數 ):";
        cin >> the_id;
    }

    system("clear");
    if (total >= 100) {
        string paper;
        cout << "請輸入優惠代碼:(不輸入請打:>.<):";
        cin >> paper;
        system("clear");
        if (paper == ID_50) {
            total -= 50;
            cout << "折扣50元 OwO" << endl;
        } else if (paper == ID_08) {
            total *= 0.8;
            cout << "打8折 OwO" << endl;
        }
        else cout << "不打折" << endl;
    }
    
    cout << "購買明細:" << endl;
    cout << "名稱 ,價格 ,數量 ,小計" << endl;
    for (int i = 0; i < size(buy.name); i++) {  
            cout << i + 1 << "." << buy.name[i] << "," 
                << buy.prize[i] << "," << buy.num[i] << 
                "," << buy.num[i] * buy.prize[i] << endl;
    }
    if (total < 490) {
        total += 60;
        cout << "運費: 60" << endl;
    }
    cout << "總金額:" << total;
}
