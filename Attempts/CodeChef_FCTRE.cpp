#include <bits/stdc++.h> 
using namespace std;

#define foi(a,b) for(int i = a; i < b; i++)
#define foj(a,b) for(int j = a; j < b; j++)
#define fok(a,b) for(int k = a; k < b; k++)

#define mod 1000000007

int price[100100];

void readInt(int &number) 
{
    bool negative = false; 
    register int c; 
    number = 0; 
    c = getchar(); 
    if (c == '-') 
    {
        negative = true; 
        c = getchar(); 
    } 
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48; 
    if (negative) 
        number *= -1; 
} 

map<int, unordered_set<int>> nodeAdj;

bool findPath(int curr, int next, int dest, unordered_set<int> &paths)
{
    if (next == dest)
        return true;

    unordered_set<int> &adjNodes = nodeAdj.find(next)->second;
    for (auto it = adjNodes.begin(); it != adjNodes.end(); it++)
    {
        if (*it == curr)
            continue;
            
        if (findPath(next, *it, dest, paths))
        {
            paths.insert(*it);
            return true;;
        }
    }

    return false;
}

#define MAXN 1000001
int spf[MAXN]; 
void sieve() 
{ 
	spf[1] = 1; 
	for (int i=2; i<MAXN; i++) 
		spf[i] = i; 
	for (int i=4; i<MAXN; i+=2) 
		spf[i] = 2; 
	for (int i=3; i*i<MAXN; i++) 
	{ 
		if (spf[i] == i) 
		{ 
			for (int j=i*i; j<MAXN; j+=i) 
				if (spf[j]==j) 
					spf[j] = i; 
		} 
	} 
} 

void getFactorization(int x, map<int, int>& ret) 
{ 
	while (x != 1) 
	{ 
		ret[spf[x]]++; 
		x = x / spf[x]; 
	} 
} 


void solve(unordered_set<int> paths)
{
    map<int, int> facts;
    // cout << paths.size() << endl;
    for (auto it = paths.begin(); it != paths.end(); it++)
    {
        getFactorization(price[(*it)-1], facts);
    }

    long long int res = 1;
    for(auto it: facts)
    {
        //cout << it.first << ' ' << it.second << endl;
        res *= (it.second + 1);
    }
    cout << res % mod << '\n';
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t, n;
    cin >> t;

    sieve();

    while(t--)
    {
        cin >> n;
        
        nodeAdj.clear();

        int x, y;
        foi(0, n-1)
        {
            cin >> x >> y;
            nodeAdj[x].insert(y);
            nodeAdj[y].insert(x);
        }

        foi(0, n)
        {
            cin >> price[i];
        }

        int q;
        cin >> q;

        
        foi(0, q)
        {
            int v, u;
            cin >> v >> u;

            unordered_set<int> path;
            path.insert(v);
            findPath(-1, v, u, path);
            // cout << "Path "<< v << ' ' << u << endl;
            // for (auto it = path.begin(); it != path.end(); it++)
            // {
            //     cout << *it << ' ';
            // }

            solve(path);
        }
    }

    return 0;
}