#include <iostream>
#include <algorithm>
using namespace std;

int memo[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            cin >> memo[i][j];
        }
    }
    
    int max = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0){
                memo[i][j] += memo[i-1][j];
            }
            else if (j == i){
                memo[i][j] += memo[i-1][j-1];
            }
            else if (memo[i-1][j-1] > memo[i-1][j]){
                memo[i][j] += memo[i-1][j-1];
            }
            else{
                memo[i][j] += memo[i-1][j];
            }
            
            if (max < memo[i][j]){
                max = memo[i][j];
            }
        }
    }
    
    cout << max << "\n";
    
    return 0;
}
