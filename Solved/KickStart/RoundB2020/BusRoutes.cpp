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
    
    size_t arr[1100], tt = 1;
    while(t--)
    {
        cin >> n;
        cin >> d;
        
        foi(0, n) cin >> arr[i];

        arr[n-1] = arr[n-1] * (d/arr[n-1]);

        for(int i = n-2; i >= 0; i--)
        {
            arr[i] = arr[i] * (arr[i+1]/arr[i]);
        }
        
        cout << "Case #" << tt++ << ": " << arr[0] << '\n';
    }

    return 0;
}