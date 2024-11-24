#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, start;
vector<vector<int>> graph(100001);
bool seen[100001] = {false};
int result[100001] = {0};

int cnt = 0;

void DFS(int y)
{
    if (seen[y]) return;   // 방문했는지 확인
    
    seen[y] = true;
    cnt++;
    result[y] = cnt;
    
    for (int i=0;i<graph[y].size();i++)        // DFS(y) 정점의 수
    {
        int current = graph[y][i];             // 순회 할 vertex의 번호
        DFS(current);
    }
}

int main()
{
    cin >> n >> m >> start;
    
    // n 정점의 수, m edge의 개수
    
    for (int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i=0;i<n;i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    
    DFS(start);
    
    for(int i=1;i<=n;i++)
    {
        cout << result[i] << '\n';
    }
    
}