#include <iostream>
#include <vector>
using namespace std;

vector<int> virus[101];
bool visited[100];
int ans;

void dfs(int x){
    visited[x] = true;
    ++ans;
    
    for (int i = 0; i < virus[x].size(); i++){
        int index = virus[x][i];
        
        if (!visited[index]){
            dfs(index);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int n, edge;
    cin >> n;
    cin >> edge;
    
    for (int i = 0; i < edge; i++){
        int v1, v2;
        cin >> v1 >> v2;
        
        virus[v1].push_back(v2);
        virus[v2].push_back(v1);
    }
    
    dfs(1);
    
    cout << ans - 1; //1번 컴퓨터 제외
    
    return 0;
}
