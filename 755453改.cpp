#include <iostream> 
using namespace std;

int main() { 

    struct pr{ 
      string s; 
      int p

; 
      int o; 
    }; 
    pr l[3]; 
     
     
    for (int i = 0;i < 3; i++){ 
      cout << "商品:"; 
      cin >> l[i].s; 
      cout << "價錢:"; 
      cin >> l[i].p; 
      cout << "數量"; 
      cin >> l[i].o; 
 
    } 
    int  temp = 0,total = 0; 
     string l2[999]; 
     int l3[999]; 
    
     
    while (true){ 
      cout << "你要的商品和數量(若無此商品就結束購買或沒貨限制次數999次):" << "\n"; 
 
      cin >> l2[temp]; 
      cout << "你要的數量"<<"\n"; 
      cin >> l3[temp]; 
       
 
      if(l2[temp] != l[0].s && l2[temp] != l[1].s && l2[temp] != l[2].s){ 
        break; 
      } 
      if(l2[temp] == l[0].s){ 
        l[0].o -= l3[temp]; 
        if (l[0].o < 0){ 
          cout << "沒貨了" << "\n"; 
          break; 
        } else { 
          cout  << "剩餘數量" << l[0].o << "\n"; 
          total += l[0].p * l3[temp]; 
        } 
      } else if (l2[temp] == l[1].s){ 
        l[1].o -= l3[temp]; 
        if (l[1].o < 0){ 
          cout << "沒貨了" << "\n"; 
          break; 
        } else { 
          cout << "剩餘數量" << l[1].o << "\n"; 
          total += l[1].p * l3[temp]; 
         } 
 
      } else if (l2[temp] == l[2].s){ 
        l[2].o -= l3[temp]; 
        if (l[2].o < 0){ 
          cout << "沒貨了" << "\n"; 
          break; 
        } else { 
          cout << "剩餘數量" << l[2].o << "\n"; 
          total += l[2].p * l3[temp]; 
 
        } 
         
       
      } 
      temp += 1; 
    }      
    string card,YN; 
       
    cout << "請輸入優惠代碼(Yes or No)"; 
    cin >> YN; 
       
    if (YN == "Yes"){ 
      cout << "請輸入代碼"; 
      cin >> card; 
         
      if (card == "llllll"){ 
        total -= 50; 
        cout << "滿意百減50"; 
 
      } else if (card == "gfvfvf"){ 
        total *= 0.8; 
        cout << "滿意百褶八折"; 
      } 
    } 
    cout<<"是否需要運送(Yes or NO)"; 
    string YN2; 
    cin >> YN2; 
    if (YN2 == "Yec"){ 
      if (total < 490){ 
        total += 60; 
        cout << "總金額:" << total; 
      } else { 
        cout  << "總金額:" << total; 
      } 
    } else { 
      cout << "總金額:" << total; 
    } 
}