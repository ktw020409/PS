#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, set[21] = {0, };
    cin >> n;
    
    string command;
    int x;
    
    for (int i = 0; i < n; i++){
        cin >> command;
        
        if (command == "add"){
            cin >> x;
            
            if (set[x] == 0){
                set[x] = 1;
            }
        }
        else if (command == "remove"){
            cin >> x;
            
            if (set[x] == 1){
                set[x] = 0;
            }
        }
        else if (command == "check"){
            cin >> x;
            
            if (set[x] == 1){
                cout << "1\n";
            }
            else{
                cout << "0\n";
            }
        }
        else if (command == "toggle"){
            cin >> x;
            
            if (set[x] == 0){
                set[x] = 1;
            }
            else{
                set[x] = 0;
            }
        }
        else if (command == "all"){
            for (int i = 1; i <= 20; i++){
                set[i] = 1;
            }
        }
        else if (command == "empty"){
            for (int i = 1; i <= 20; i++){
                set[i] = 0;
            }
        }
    }
    
    return 0;
}
