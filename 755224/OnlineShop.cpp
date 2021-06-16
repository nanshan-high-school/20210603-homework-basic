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
    cout << "�~�W     ���� �w�s\n";
    stock.push_back({"Orange", 18, 23});
    stock.push_back({"Banana", 12, 45});
    stock.push_back({"Potato", 10, 36});
    for (auto temp: stock) {
        cout << temp.name << "    " << temp.price << "   " << temp.instock << endl;
    }
    vector<int> purchase_list (3,0);
    cout << "\n\n�ϥΪ̿�J�榡�G�ӫ~�W�� �ק�ƶq�]��̤����n���b�ΪŮ�^\n";
    cout << "�Y�n���b�A�п�J�GEnd\n";
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
                    cout << "�n�D�q�L�h�A���ӫ~�u�� " << 
                        stock[i].instock << " ��\n";
                    continue;
                }
                if (quantity + purchase_list[i] < 0) {
                    cout << "�����ʶR�t�Ƽƶq�ӪF��I\n";
                    continue;
                }
                purchase_list[i] += quantity;
                cout << "�{�b " << temp_string << " ���ʶR�q�G" << purchase_list[i] << endl;
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
    cout << "\n\n�z�{�b�����O���B���G" << total << " ��\n";
    cout << "�Y���u�f�N�X�A�в{�b��J�]�S�����ܡA�п�J�GNo�^�G";
    while(true) {
        string coupon;
        cin >> coupon;
        if (coupon == "No") {
            break;
        }
        if (coupon == "C-L") {
            if (total < 100) {
                cout << "���B���� 100 ���A�L�k�馩\n�u�f�N�X�G";
                continue;
            }
            total -= 50;
            discount = 50;
            cout << "������\�A�{�b���O���B���G" << total << " ��\n";
            break;
        }
        if (coupon == ">C*.8") {
            if (total < 100) {
                cout << "���B���� 100 ���A�L�k�馩\n�u�f�N�X�G";
                continue;
            }
            total = ceil(total * 0.8);
            discount = total / 5;
            cout << "������\�A�{�b���O���B���G" << total << " ��\n";
            break;
        }
    }

    cout << "�z�����O���B�� "<< total << " ��";
    bool shipping = 0;
    if (total < 490) {
        cout << "�A���W�L 490 ���A�ҥH�ݤ�I 60 �����B�O\n\n\n";
        shipping = 1;
        total += 60;
    } else {
        cout << "�A�W�L�F 490 ���A�ҥH���ΥI�B�O\n\n\n";
    }
    for (int i = 0; i < 3; i++) {
        if (purchase_list[i] == 0) {
            break;
        }
        cout << stock[i].name << ' ' << purchase_list[i] << " �ӡA" << purchase_list[i] * stock[i].price << " ��\n";
    }
    cout << "��l�`���B�G" << total << " ��"<< endl;
    if (discount != 0) {
        cout << "����G" << discount << " ��" << endl;
    }
    if (shipping) {
        cout << "�B�O�G60 ��\n";
    }
    cout << "�̲��`���B�G" << total << "\n�P�±z�����O";
}
