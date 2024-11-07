#include<bits/stdc++.h>
#define N 100000
using namespace std;

vector<int>a(N), seg(4*N);

int build(int node, int left, int right){
    if(left == right){
        seg[node] = a[left];
        return seg[node];
    }
    int mid = (left+right)/2;
    int sum = build(2*node, left, mid);
    int sum1 = build(2*node + 1, mid+1, right);

    return seg[node] = sum + sum1;
}

int update(int node, int l, int r, int left, int right, int val){
    if(right < l || left > r) return seg[node];
    if(left == right && left == l){
        seg[node] = val;
        return seg[node];
    }

    int mid = (left+right)/2;
    int sum = update(2*node, l, r, left, mid, val);
    int sum1 = update(2*node + 1, l, r, mid+1, right, val);

    return seg[node] = sum + sum1;
}

int query(int node, int l, int r, int left, int right){
    if(right < l || left > r) return 0;
    if(l <= left && r >= right) return seg[node];
    int mid = (left+right)/2;
    return query(2*node, l, r, left, mid) + query(2*node + 1, l, r, mid+1, right);
}
void solve()
{
    int node;
    cin>>node;
    int value;
    cin>>value;
    for(int  i = 0 ; i < node ; i++)
    {
        cin>>a[i];
    }
    build(node,0,node-1);
    int l,r;
    while(cin>>l>>r){
        query(node,l,r,0,node-1);
        update(node,l,r,0,node-1,value);
    }
    for(auto e : seg)
    {
        cout<<e<<" ";
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

