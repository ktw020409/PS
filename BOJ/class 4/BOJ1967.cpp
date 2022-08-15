#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> node[10001]; //first : 연결된 노드, second : 가중치
bool visited[10001];
int ans, rPoint;

void DFS(int x, int len){
    if (visited[x]){
        return;
    }
    
    visited[x] = true;
    
    if (ans < len){ //최장 길이 탐색
        rPoint = x;
        ans = len;
    }
    
    for (int i = 0; i < node[x].size(); i++){
        DFS(node[x][i].first, len + node[x][i].second);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int n, parent, child, weight;
    cin >> n;
    
    for (int i = 1; i < n; i++){
        cin >> parent >> child >> weight;
        
        node[parent].push_back(make_pair(child, weight)); //무방향 노드
        node[child].push_back(make_pair(parent, weight));
    }

    DFS(1, 0);
    
    for (int i = 0; i <= n; i++){ //초기화
        visited[i] = false;
    }
    ans = 0;
    
    DFS(rPoint, 0);
    
    cout << ans << "\n";
    
    return 0;
}
