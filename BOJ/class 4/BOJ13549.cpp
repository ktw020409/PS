#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define INF 200000000

int dist[100001];
int N, K, ans;

void BFS(){ //0-1 BFS
    deque<int> dq;
    dq.push_back(N);
    dist[N] = 0;
    
    while (!dq.empty()){
        int current = dq.front();
        dq.pop_front();
        
        if (current == K){
            return;
        }
        
        int move[3] = {current - 1, current + 1, 2 * current}; //왼쪽, 오른쪽, 순간이동
        
        if (0 <= move[0] && dist[current] + 1 < dist[move[0]]){ //가중치 == 1
            dist[move[0]] = dist[current] + 1;
            dq.push_back(move[0]);
        }
        
        if (move[1] <= 100000 && dist[current] + 1 < dist[move[1]]){ //가중치 == 1
            dist[move[1]] = dist[current] + 1;
            dq.push_back(move[1]);
        }
        
        if (move[2] <= 100000 && dist[current] < dist[move[2]]){ //가중치 == 0
            dist[move[2]] = dist[current];
            dq.push_front(move[2]);
        }
    }
}

int main(){
    cin >> N >> K;
    
    fill(dist, dist + 100001, INF);
    BFS();
    
    cout << dist[K] << "\n";
    
    return 0;
}
