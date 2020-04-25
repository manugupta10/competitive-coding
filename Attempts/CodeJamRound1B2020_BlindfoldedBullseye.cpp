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
    
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
    
    int t, n, a, b, tt = 1;
    cin >> t;
    
    while(t--)
    {
        cin >> n >> a >> b;
        int x = 0, y = 1000000000, X, Y;
        string s;
        int cnt = 300;
        while(cnt--)
        {
            cout << x << y << endl;
            cin >> s;
            if (s == "MISS")
            {
                y--;
            }
            else if (s == "HIT")
            {
                Y = y - a/2;
            }
        }

        x = 1000000000, y = 0;
        while(cnt--)
        {
            cout << x << y << endl;
            cin >> s;
            if (s == "MISS")
            {
                x--;
            }
            else if (s == "HIT")
            {
                X = x - a/2;
            }
        }

        cout << X << Y << endl;
        cin >> s;
        if (s != "CENTER")
        {
            exit(0);
        }
    }

    return 0;
}