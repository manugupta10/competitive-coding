//Round 1A 2020 - Code Jam 2020: Pattern Matching
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

bool areCompBack(string p1, string p2)
{
    for (auto it1 = p1.rbegin(), it2 = p2.rbegin(); it1 != p1.rend() and it2 != p2.rend(); it1++, it2++)
    {
        if (*it1 != *it2)
        {
            return false;
        }
    }
    return true;
}

bool areCompFront(string p1, string p2)
{
    for (auto it1 = p1.begin(), it2 = p2.begin(); it1 != p1.end() and it2 != p2.end(); it1++, it2++)
    {
        if (*it1 != *it2)
        {
            return false;
        }
    }
    return true;
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
        string s;
        unordered_set<string> vec;
        bool possible = true;
        string sp, ep;
        cout << "Case #" << tc++ << ": ";
        fok(0, n)
        {
            cin >> s;
            if (s.front() == '*' and s.back() == '*')
            {
                string newS;
                foj(0, s.length())
                {
                    if (s[j] != '*')
                        newS.push_back(s[j]);
                }
                vec.insert(newS);
                cout << "DEBUG: " << newS << endl;
            }
            else if(s.back() == '*')
            {
                s = s.substr(0, s.length()-1);
                if (!sp.empty() and !areCompFront(sp, s))
                {
                    possible = false;
                    break;
                }

                if (s.length() > sp.length())
                {
                    sp.clear();
                    string newS;
                    foj(0, s.length()-1)
                        sp.push_back(s[j]);
                }
            }
            else if (s.front() == '*')
            {
                s = s.substr(1);
                if (!ep.empty() and !areCompBack(ep, s))
                {
                    possible = false;
                    break;
                }
                
                if (s.length() > ep.length())
                {
                    ep.clear();
                    string newS;
                    foj(1, s.length())
                        ep.push_back(s[j]);
                }
            }
        }

        if (!possible)
            cout << "*\n";
        else 
        {
            cout << sp;
            for (auto it = vec.begin(); it != vec.end(); it++)
            {
                cout << *it;
            }
            cout << ep << '\n';
        }
    }

    return 0;
}