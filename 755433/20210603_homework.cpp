#include <iostream>
using namespace std;

int main() {
    struct store {
        string name;
        int price;
        int stock;
    };

    // 定義各商品的數量、價格 (底下有此段測資)
    string n;
    int p, s, CommodityCount;
    cout << "請輸入商品數量：\n";
    cin >> CommodityCount;
    store commodity[CommodityCount];
    for (int i = 0; i < CommodityCount; i++) {
        cout << "商品" << i + 1 << "：\n";
        cout << "商品名稱：\n";
        cin >> n;
        cout << "價格：\n";
        cin >> p;
        cout << "剩餘數量：\n";
        cin >> s;
        commodity[i].name = n;
        commodity[i].price = p;
        commodity[i].stock = s;
    }

    // 消費者購買
    struct purchaser {
        string Pname;
        int Pcount;
        int Ptotal;
    };
    purchaser user[CommodityCount];
    for (int i = 0; i < CommodityCount; i++) {
        user[i].Pname = "";
        user[i].Pcount = 0;
        user[i].Ptotal = 0;
    }
    string BuyCommodityName;
    int BuyCommodityCount, total = 0;
    while (true) {
        cout << "請輸入購買的商品名稱，如果不購買則輸入0：\n";
        cin >> BuyCommodityName;

        if (BuyCommodityName == "0") {
            break;
        };

        // 是否有此商品
        bool nameTF = true;
        for (int i = 0; i < CommodityCount; i++) {
            if (BuyCommodityName == commodity[i].name) {
                nameTF = false;
                break;
            }
        }
        if (nameTF == true) {
            cout << "庫存無此商品，請再輸入一次。\n";
            continue;;
        }

        cout << "請輸入購買數量：\n";
        cin >> BuyCommodityCount;

        for (int i = 0; i < CommodityCount; i++) {
            if (BuyCommodityName == commodity[i].name) {
                if (commodity[i].stock < BuyCommodityCount) {
                    cout << "！庫存數量不足！\n";
                    continue;
                }
                commodity[i].stock -= BuyCommodityCount;
                total += commodity[i].price * BuyCommodityCount;
                user[i].Pname = commodity[i].name;
                user[i].Pcount += BuyCommodityCount;
                user[i].Ptotal += commodity[i].price * BuyCommodityCount;
            }
        }
    }

    // 是否有折價券
    string CouponYN, Coupon;
    cout << "是否有優惠券？請回答[y]或著[n]\n";
    cin >> CouponYN;
    if (CouponYN == "y") {
        cin >> Coupon;
        while (true) {
            if (Coupon == "zxcvbnm") { // 滿100折50 --> zxcvbnm
                if (total >= 100) {
                    total -= 50;
                    break;
                }
            } else if (Coupon == "asdfghjkl") { //滿100打8折 --> asdfghjkl
                if (total >= 100) {
                    total *= 0.8;
                    break;
                }
            } else if (Coupon == "0") {
                break;
            } else {
                cout << "！輸入錯誤，請再輸入一次。若放棄輸入則輸入0！\n";
            }
        }
    }

    // 是否運費
    bool shipping = false;
    if (total < 490) {
        shipping = true;
        total += 60;
    }

    //明細
    cout << endl << "_____購物明細_____" << endl;
    cout << endl << "總費用：" << total << endl;
    
    cout << "- - - - - - - - - \n";
    for (int i = 0; i < CommodityCount; i++) {
        if (user[i].Pname != "") {
            cout << user[i].Pname << " * " << user[i].Pcount << " = " << user[i].Ptotal << endl;
        }
    }

    if (shipping == true) {
        cout << "- - - - - - - - - \n";
        cout << "運費：60\n";
    }
    cout << "- - - - - - - - - " << endl << "應繳費用：" << total << endl;
    cout << "感謝您的購買，歡迎下次蒞臨選購。";
    // 資料測試：
    // 3
    // 1
    // 50
    // 10
    // 2
    // 40
    // 10
    // 3
    // 30
    // 10
}
