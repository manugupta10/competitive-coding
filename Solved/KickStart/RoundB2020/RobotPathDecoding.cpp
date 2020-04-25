#include <bits/stdc++.h> 
using namespace std;

#define foi(a,b) for(int i = a; i < b; i++)
#define foj(a,b) for(int j = a; j < b; j++)
#define fok(a,b) for(int k = a; k < b; k++)
#define debug(a) cout << #a << ": " << a << endl;
#define debugArr(arr,n) cout <<#arr <<": "; foi(0, n) cout << arr[i] << ' '; cout << endl; 
#define mod 1000000007

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t, n;
    size_t d;
    cin >> t;
    
    int tt = 1;
    while(t--)
    {
        string p;
        cin >> p;

        map<char, size_t> moves;
        stack<int> mul;
        int cmul = 1;
        foi(0, p.length())
        {
            if (p[i] >= 65 && p[i] <= 90)
            {
                moves[p[i]] += cmul;
            }
            else if (p[i] == '(')
            {
                cmul *= mul.top();
            }
            else if (p[i] == ')')
            {
                cmul /= mul.top();
                mul.pop();
            }
            else
            {
                mul.push(p[i]-48);
            }
        }

        // for(auto a: moves)
        // {
        //     cout << a.first << ' ' << a.second << endl;
        // }
        // cout  << endl;

        long long int y = moves['S'] - moves['N'];
        y %= 1000000000;
        y += 1;
        if (y <= 0)
         y += 1000000000;

        long long int x = moves['E'] - moves['W'];
        x %= 1000000000;
        x += 1;
        if (x <= 0)
         x += 1000000000;

        cout << "Case #" << tt++ << ": " << x << ' ' << y << '\n';
    }

    return 0;
}