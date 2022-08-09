#include <iostream>
using namespace std;

int main(){
    int n, five = 0;
    cin >> n;
    
    for (int i = 0; i <= n; i++){
        if (i != 0){
            if (i % 125 == 0)
                five += 3;
            
            else if (i % 25 == 0)
                five += 2;
            
            else if (i % 5 == 0)
                five++;
        }
    }
    
    cout << five;
    
    return 0;
}
