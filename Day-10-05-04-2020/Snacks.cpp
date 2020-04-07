#include<bits/stdc++.h>
using namespace std;

int ctr = 0;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[],
                    vector<bool> &visited)
{
    visited[u] = true;
    //cout << u << " ";
    //ctr++;
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
        {
            ctr++;
            DFSUtil(adj[u][i], adj, visited);
        }
}

void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
        {
            //ctr++;
            DFSUtil(u, adj, visited);
        }

}

// Driver code
int main()
{
    int n, k, temp1, temp2, i;
    set<pair<int, int>> s;
    cin >> n >> k;
    int V = 6;
    vector<int> adj[V];

    for(i=0;i<k;i++)
    {
        cin >> temp1 >> temp2;
        if(s.count(pair<int, int>(temp1, temp2))>0 || s.count(pair<int, int>(temp1, temp2))>0)
            continue;
        addEdge(adj, temp1, temp2);
    }
    DFS(adj, V);
    cout << ctr;
    return 0;
}
