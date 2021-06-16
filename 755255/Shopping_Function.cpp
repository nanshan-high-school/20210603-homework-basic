#include <iostream>
using namespace std;
#include <vector>
int main() {
    struct product{
        string name;
        int price;
        int stock;
        int buy;
    };
    product bear_doll;
    product penguin_doll;
    product flower_doll;

    bear_doll.name = "黑白熊";
    bear_doll.price = 300;
    bear_doll.stock = 30;
    
    penguin_doll.name = "企鵝";
    penguin_doll.price = 250;
    penguin_doll.stock = 10;

    flower_doll.name = "mopemope";
    flower_doll.price = 400;
    flower_doll.stock = 37;
    do {
        cout << bear_doll.name << endl << "價格:" << bear_doll.price << endl << "庫存:" << bear_doll.stock << "隻" << endl;
        cout << penguin_doll.name << endl << "價格" << penguin_doll.price << endl << "庫存" << penguin_doll.stock << "隻" << endl;
        cout << flower_doll.name << endl << "價格" << flower_doll.price << endl << "庫存" << flower_doll.stock << "隻" << endl << endl;

            do {
                cout << "黑白熊:";
                cin >> bear_doll.buy;
                if (bear_doll.buy <= bear_doll.stock) {
                    bear_doll.stock -= bear_doll.buy;
                    break;
                }
                cout << "超出庫存上限，請重新輸入"<< endl;
            } while (true);
            do {
                cout << "企鵝:";
                cin >> penguin_doll.buy;
                if (penguin_doll.buy <= penguin_doll.stock) {
                    penguin_doll.stock -= penguin_doll.buy;
                    break;
                }
                cout << "超出庫存上限，請重新輸入"<< endl;
            } while (true);
            do {
                cout << "mopemope:";
                cin >> flower_doll.buy;
                if (flower_doll.buy <= flower_doll.stock) {
                    flower_doll.stock -= flower_doll.buy;
                    break;
                }
                cout << "超出庫存上限，請重新輸入" << endl;
            } while (true);

        string discount_50 = "PH0321";
        bool discount_50_check = false;
        string discount_80 = "PH6035";
        bool discount_80_check = false;
        bool sum_less_than_490 = false;
        string discount_type;
        cout << "請輸入優惠代碼，若無則輸no" << endl;
        cin >> discount_type;

        int sum = bear_doll.buy * 300 + penguin_doll.buy * 250 + flower_doll.buy * 400;

        if (discount_type == "PH0321" && sum >= 100) {
            sum -= 50;
            discount_50_check = true;
        } else if (discount_type == "PH6035" && sum >= 100) {
            sum *= 0.8;
            discount_80_check = true;
        }

        if (sum < 490 && sum > 0) {
            sum += 60;
            sum_less_than_490 = true;
        }
        cout << "======================" << endl ;
        cout << "======================" << endl ;
        cout << "總金額:" << sum << endl << "黑白熊:" << bear_doll.buy << endl << "企鵝:" << penguin_doll.buy << endl << "mopemope:" << flower_doll.buy << endl;

        if (discount_50_check == true) {
            cout << "輸入PH0321滿百折50元"<< endl;
        } else if (discount_80_check == true) {
            cout << "輸入PH6035滿百8折"<< endl;
        }

        if (sum_less_than_490 == true) {
            cout << "低於490加+60元運費"<< endl;
        }
        cout << "======================" << endl ;
        cout << "======================" << endl ;
        string type;
        cout << "若要退出請打exit" << endl;
        cout << "若要再次購買請按0" << endl;
        cin >> type;
        if (type == "exit") {
            return 0;
        }
    } while (true);
}
