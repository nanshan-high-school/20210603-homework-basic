#include <iostream>
#include <vector>
using namespace std;

int main() {
    int totalmoney = 0;
    string N[3] = {"超級小克車", "酒精", "口罩"};
    int M[3] = {1000, 50, 10};//錢
    int Q[3] = {1000, 10, 50};//數量

    struct buy {
        int name, Quantity;
    };
    
    buy buyStruct;
    while(true){
        system("clear");
        cout << "(標號1)超級小克車1000元 限量" << Q[0] << "個\n";
        cout << "(標號2)   酒精     50元 限量" << Q[1] << "個\n";
        cout << "(標號3)   口罩     10元 限量" << Q[2] << "個\n";
        cout << "==============================\n";
        cout << "請輸入標號(1~3) 其他標號為跳出\n";

        cin >> buyStruct.name;

        if (buyStruct.name <= 0 || buyStruct.name >= 4) {
            break;
        }
        //1~3
        cout << "請輸入數量\n";
        cin >> buyStruct.Quantity;
        if (Q[buyStruct.name - 1] - buyStruct.Quantity < 0) {
            cout << "庫存不夠\n";
        } else {//庫存夠
            totalmoney += M[buyStruct.name - 1] * buyStruct.Quantity;
            Q[buyStruct.name - 1] -= buyStruct.Quantity;
        }
    }
    //買完
    string code;
    cout << "購買完畢\n請輸入優惠代碼(滿100才有)\n";
    cin >> code;
    if (code == "badjack"){//滿 100 折 50
        if (totalmoney >= 100) {
            totalmoney -= 50;
            cout << "滿一百五十\n";
        }
    } else if (code == "free"){//滿一百八折
        if (totalmoney >= 100) {
            totalmoney *= 0.8;
            cout << "滿一百八折\n";
        }
    } else {
        cout << "輸入錯誤\n";
    }
    
    if (totalmoney < 490) {//運費
        totalmoney += 60;
    }

    cout << "你總共花費" << totalmoney << "元";
}
//產品 數量 金額
