#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 100000000

vector<pair<int, int>> vertex[20001];
int result[20001];

void dijkstra(int start){ //다익스트라 알고리즘 사용
    priority_queue<pair<int, int>> pq; //배열을 이용한 다익스트라는 시간초과 발생 -> priority queue 사용
    
    pq.push(make_pair(0, start)); //초기값 설정
    result[start] = 0;
    
    while (!pq.empty()){
        int distance = -pq.top().first; //min heap으로 사용하기 위해 -부호 붙임
        int cur = pq.top().second;
        pq.pop();
        
        if (result[cur] < distance){
            continue;
        }
        
        for (int i = 0; i < vertex[cur].size(); i++){
            int weight = vertex[cur][i].first;
            int next = vertex[cur][i].second;
            
            if (distance + weight < result[next]){
                result[next] = distance + weight;
                pq.push(make_pair(-result[next], next));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int V, E;
    cin >> V >> E;
    
    for (int i = 1; i <= V; i++){
        result[i] = INF;
    }
    
    int K;
    cin >> K;
    
    for (int i = 0; i < E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        
        vertex[u].push_back(make_pair(w, v)); //v == next node, w == weight, !중요! : priority queue는 pair의 first 값을 먼저 비교하기 때문에 w를 first로 설정한다.
    }
    
    dijkstra(K);
    
    for (int i = 1; i <= V; i++){
        if (result[i] == INF){
            cout << "INF\n";
        }
        else{
            cout << result[i] << "\n";
        }
    }
    
    return 0;
}
