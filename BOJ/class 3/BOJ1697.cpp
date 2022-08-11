#include <iostream>
#include <queue>
using namespace std;

int location[100001];
bool visited[100001];
queue<int> q;
int n, k, t;

void bfs(){
    while(!q.empty()){
        int x = q.front();
        if (x == k){
            return;
        }
        q.pop();
        
        int nx[3] = {x-1, x+1, 2*x};
        
        for (int i = 0; i < 3; i++){
            if (!visited[nx[i]] && 0 <= nx[i] && nx[i] <= 100000){
                visited[nx[i]] = true;
                location[nx[i]] = location[x] + 1;
                q.push(nx[i]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin >> n >> k;
    
    visited[n] = true;
    q.push(n);
    location[n] = 0;
    
    bfs();
    
    cout << location[k] << "\n";
    
    return 0;
}
