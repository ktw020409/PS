#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[1001];
bool visited[1001];

void dfs(int x){
    visited[x] = true;
    
    for (int i = 0; i < adj[x].size(); i++){
        int index = adj[x][i];
        if (!visited[index]){
            dfs(index);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++){
        int v1, v2;
        cin >> v1 >> v2;
        
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    
    int cnt = 0;
    
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    
    cout << cnt << "\n";
    
    return 0;
}
