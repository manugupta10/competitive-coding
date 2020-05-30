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

void solve()
{
    int n, k;
    cin >> n >> k;
    int temp;
    int prev = -1;
    int count = 0;
    foi(0, n)
    {
        cin >> temp;
        if (temp == k)
        {
            prev = k;
        }
        else if (prev == temp + 1)
        {
            if (temp == 1)
            {
                count++;
                prev = -1;
            }
            else
            {
                prev = temp;
            }
        }
        else
        {
            prev = -1;
        }
    }
    cout << count << endl;
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
    
    for(int x = 1; x <= t; x++)
    {
        cout << "Case #"<< x << ": ";
        solve();
    }

    return 0;
}