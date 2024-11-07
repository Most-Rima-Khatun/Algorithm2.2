#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n+1);
    vector<int>deg(n+1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    queue<int>q;
    for(int i = 1; i <= n; i++){
        if(deg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto c: adj[node]){
            deg[c]--;
            if(deg[c] == 0) q.push(c);
        }
        cout << node << ' ';
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int test = 1;
    // cin>>test;
    while(test--)
        solve();
}
