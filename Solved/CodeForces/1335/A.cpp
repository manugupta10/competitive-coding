//Accepted Solution
#include <bits/stdc++.h> 
using namespace std;

#define foi(a,b) for(int i = a; i < b; i++)
#define foj(a,b) for(int j = a; j < b; j++)
#define fok(a,b) for(int k = a; k < b; k++)
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
    readInt(t);

    while(t--)
    {
        readInt(n);
        if (n%2 == 0)
        {
            n--;
        }

        cout << n/2 << '\n';
    }

    return 0;
}