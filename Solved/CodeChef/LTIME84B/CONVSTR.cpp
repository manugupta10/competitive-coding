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

int main()
{
    fastio;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    
    int t, n;
    cin >> t;

    char a[1000];
    char b[1000];

    while(t--)
    {
        cin >> n;

        map<char, int> ac, bc;
        foi(0, n)
        {
            cin >> a[i];
            ac[a[i]]++;
        }

        bool ok = true;
        set<char> diff;

        foi(0, n)
        {
            cin >> b[i];
            bc[b[i]]++;

            if (b[i] > a[i])
            {
                ok = false;
            }
            else if (b[i] != a[i])
            {
                diff.insert(b[i]);
            }
        }
        
        if (ok)
        {
            foi('a', 'z')
            {
                if (bc[i] > 0 and ac[i] == 0)
                {
                    ok = false;
                    break;
                }
            }
        }

        if (!ok)
        {
            cout << -1 << '\n';
            continue;
        }

        cout << diff.size() << '\n';
        for(auto it = diff.rbegin(); it != diff.rend(); it++)
        {
            vector<int> v;
            
            char *f = find(a, a+n, *it);
            v.push_back(f-a);

            foi(0, n)
            {
                if (*it == b[i] and a[i] != b[i])
                {
                    v.push_back(i);
                }
            }

            cout << v.size() << ' ';
            for(int x: v)
            {
                cout << x << ' ';
            }
            cout << '\n';
        }

    }

    return 0;
}