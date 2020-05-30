#include <bits/stdc++.h> 
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define foi(a,b) for(int i = a; i < b; i++)
#define foj(a,b) for(int j = a; j < b; j++)
#define fok(a,b) for(int k = a; k < b; k++)
#define debug(a) cout << #a << ": " << a << endl;
#define debugArr(arr,n) cout <<#arr <<": "; foi(0, n) cout << arr[i] << ' '; cout << endl; 
#define mod 1000000007
#define lli long long int


int main()
{
    fastio;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    
    int t, n, q;
    cin >> t;
    map<char, int> m;

    while(t--)
    {
        m.clear();
        cin >> n >> q;
        string s;
        cin >> s;
        for(char c: s)
        {
            m[c]++;
        }

        int c;
        foi(0, q)
        {
            int qu = 0;
            cin >> c;
            for(auto p: m)
            {
                qu += max(p.second-c, 0);
            }
            cout << qu << '\n';
        }

    }

    return 0;
}