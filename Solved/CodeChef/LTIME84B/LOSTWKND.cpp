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

    while(t--)
    {
        int req = 0;

        foi(0, 5)
        {
            int temp;
            cin >> temp;
            req += temp;
        }

        int p;
        cin >> p;

        req *= p;

        if (req > (24*5))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}