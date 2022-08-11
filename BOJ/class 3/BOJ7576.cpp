#include <iostream>
#include <queue>
using namespace std;

int tomato[1001][1001];
int m, n;
queue<pair<int, int>> q;

int dy[4] = {-1, 0, 1, 0}; //상우하좌
int dx[4] = {0, 1, 0, -1};

void bfs(){
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (tomato[ny][nx] == 0 && 0 <= ny && ny < n && 0 <= nx && nx < m){
                q.push(make_pair(ny, nx));
                tomato[ny][nx] = tomato[y][x] + 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    cin >> m >> n;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int temp;
            cin >> temp;
            tomato[i][j] = temp;
            
            if (temp == 1){
                q.push(make_pair(i, j));
            }
        }
    }
    
    bfs();
    
    int ans = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (tomato[i][j] == 0){
                cout << "-1\n";
                return 0;
            }
            
            if (ans < tomato[i][j]){
                ans = tomato[i][j];
            }
        }
    }
    
    cout << ans - 1<< "\n";
    
    return 0;
}
