#include <iostream>
#include <algorithm>
using namespace std;

int sticker[2][100000]; //스티커 점수
int memo[2][100000]; //구간별 최댓값 저장

void DP(int n){
    memo[0][0] = sticker[0][0]; //memo 배열 초기화
    memo[1][0] = sticker[1][0];
    
    for (int i = 1; i < n; i++){
        memo[0][i] = max(memo[1][i-1], memo[1][i-2]) + sticker[0][i];
        memo[1][i] = max(memo[0][i-1], memo[0][i-2]) + sticker[1][i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++){
        int n;
        cin >> n;
        
        int temp;
        for (int j = 0; j < n; j++){
            cin >> temp;
            sticker[0][j] = temp;
        }
        for (int j = 0; j < n; j++){
            cin >> temp;
            sticker[1][j] = temp;
        }
        
        DP(n);
        
        cout << max(memo[0][n-1], memo[1][n-1]) << "\n";
    }
    
    return 0;
}
