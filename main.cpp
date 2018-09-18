#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; i++)
#define lp(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define clr(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define ull unsigned long long
#define ll long long
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define mp make_pair
#define inn freopen("in.in","r",stdin)
#define outt freopen("out.out","w",stdout)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define all(v) ((v).begin()), ((v).end())

long long compute_hash(string const& s)
{
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s)
    {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}
vector<vector<int>> adj;
const int N = (int)1e6 + 5, M = 3005;
int vis[N], dist[N], done[N];
int n, r, m;
int main ()
{
    ios;
    //inn;outt;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>r>>m;

        clr(vis, 0);
        clr(dist, 0);
        clr(done, 0);
        adj = vector<vector<int>>(n+2);

        lp(i, r)
        {
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        queue<pair<int, int>> q;
        int level = 1;

        lp(i, m)
        {
            int k, s;
            cin>>k>>s;
            if(s)
                q.push(make_pair(k, s));
            else
                done[k] = 1;
            vis[k] = 1;
        }

        bool flag = false;
        while(q.size())
        {
            int sz = q.size();
            if(flag)
                break;
            while(sz--)
            {
                pair<int, int> tmp = q.front();
                q.pop();
                int src = tmp.first;
                int rem = tmp.second;
                if(done[src]==1)
                {
                    flag = true;
                    break;
                }
                vis[src] = true;
                for(auto child : adj[src])
                {
                    if(!vis[child])
                    {
                        dist[child] = dist[src] + 1;
                        vis[child] = 1;
                        if(dist[child] <= rem)
                            q.push(make_pair(child, rem));
                    }
                }
                done[src]++;
            }
        }
        rep(i, 1, n)
        {
            if(!done[i])
            {
                flag = true;
                break;
            }
            //cout<<done[i]<<" | ";
        }
        flag?cout<<"No\n":cout<<"Yes\n";
    }
    return 0;
}
