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

void getStr(int r, int s, string& str)
{
    foi(1,s+1)
        foj(1, r+1)
            str.push_back(j+48);
}

bool check(int r, int s, string &str)
{
    int x = 0;
    foi(1,r+1)
        foj(0, s)
            if (str[x++] != i+48)
                return false;
    return true;
}

void solve()
{
    int r, s;
    cin >> r >> s;
    string str;
    getStr(r, s, str);
    // cout <<'\n' << str << '\n';

    vector<pair<int, int>> moves;
    while(!check(r, s, str))
    {
        int p = 1;
        int q = str[0];
        while(str[p] == q)
            p++;

        int a,b = str.find_first_of(str[0],p);
        if (b == str.length()-1)
        {
            a = str.find_last_of(str[b],b-1)+1;
        }
        else
        {
            a = str.find_last_of(str[b+1],b-1)+1;
        }
        

        // debug(a);
        // debug(b);

        string A = str.substr(0,a);
        string B = str.substr(a,b-a+1);
        string C = str.substr(b+1);

        moves.push_back({A.length(), B.length()});

        str = B + A + C;
        // debug(A);
        // debug(B);
        // debug(C);
        // debug(str);
    }
    // cout << str << '\n';
    cout << moves.size() << '\n';

    for(auto m: moves)
    {
        cout << m.first << " " << m.second << '\n';
    }
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