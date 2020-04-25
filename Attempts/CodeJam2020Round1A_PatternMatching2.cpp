//Round 1A 2020 - Code Jam 2020: Pattern Matching
#include <bits/stdc++.h> 
using namespace std;

#define foi(a,b) for(int i = a; i < b; i++)
#define foj(a,b) for(int j = a; j < b; j++)
#define fok(a,b) for(int k = a; k < b; k++)
#define debug(a) cout << #a << ": " << a << endl;
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
    cin >> t;
    int tc = 1;
    while(t--)
    {
        cin >> n;

        vector<string> vec;
        vector<string> perfs;
        vector<string> sufs;

        string longest_pref, longest_suf;

        foi(0,n)
        {
            string s;
            cin >> s;

            if (s.front() == '*' and s.back() == '*')
            {
                vec.push_back(s);
                continue;
            }
            
            if (s.back() == '*')
            {
                int j;
                for (j = 0; j < s.length(); j++)
                    if (s[j] == '*')
                        break;
                string temp = s.substr(0, j);
                perfs.push_back(temp);
                if (temp.length() > longest_pref.length())
                    longest_pref = temp;
                temp = s.substr(j);
                if (temp != "*")
                    vec.push_back(temp);
            }
            
            if (s.front() == '*')
            {
                int j;
                for (j = s.length(); j >= 0; j--)
                    if (s[j] == '*')
                        break;
                string temp = s.substr(j+1);
                sufs.push_back(temp);
                if (temp.length() > longest_suf.length())
                    longest_suf = temp;
                temp = s.substr(0, j+1);
                if (temp != "*")
                    vec.push_back(temp);
            }         
        }
        
        bool ok = true;
        for(auto s: sufs)
        {
            string temp = longest_suf.substr(longest_suf.length() - s.length());
            if (temp != s)
            {
                ok = false;
                break;       
            }
        }
        for(auto s: perfs)
        {
            string temp = longest_pref.substr(0, s.length());
            if (temp != s)
            {
                ok = false;
                break;
            }
        }

        foi(0, vec.size())
            cout << vec[i] << endl;
        cout << endl;
        foi(0, perfs.size())
            cout << perfs[i] << endl;
        cout << endl;
        foi(0, sufs.size())
            cout << sufs[i] << endl;
        cout << endl;
    }

    return 0;
}