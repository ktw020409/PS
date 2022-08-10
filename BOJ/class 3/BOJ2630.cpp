#include <iostream>
using namespace std;

int matrix[128][128];
int white, blue;

void divide(int n, int x, int y){
    bool checkWhite = true, checkBlue = true;
    
    for (int i = x; i < x + n; i++){
        for (int j = y; j < y + n; j++){
            if (matrix[i][j] == 0){ //해당 구간의 색종이 중 하나라도 blue가 있을 때
                checkBlue = false;
            }
            else{ //해당 구간의 색종이 중 하나라도 white가 있을 때
                checkWhite = false;
            }
        }
    }
    
    if (checkWhite){
        ++white;
        return;
    }
    if (checkBlue){
        ++blue;
        return;
    }
    
    divide(n/2, x, y);
    divide(n/2, x, y + n/2);
    divide(n/2, x + n/2, y);
    divide(n/2, x + n/2, y + n/2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int n;
    cin >> n;
    
    int temp;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> temp;
            matrix[i][j] = temp;
        }
    }

    divide(n, 0, 0);
    
    cout << white << "\n" << blue << "\n";

    return 0;
}
