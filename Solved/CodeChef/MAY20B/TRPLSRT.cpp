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

void foo(set<int>& s, int* arr, int& i1, int& i2,int& i3)
{
    bool found1 = false;
    for(auto it = s.begin(); it != s.end(); it++)
    {
        if (arr[arr[*it]] != *it)
        {
            if (arr[arr[arr[*it]]] == *it)
            {
                i1 = *it;
                i2 = arr[i1];
                i3 = arr[i2];
                break;
            }
            else
            {
                i1 = *it;
                i2 = arr[i1];
                i3 = arr[i2];
                break;
            }
        }
        else
        {
            if (!found1)
            {
                found1 = true;
                auto it2 = s.find(arr[*it]);
                auto it3 = s.begin();
                while (it3 == it or it3 == it2)
                {
                    it3++;
                }

                i1 = *it;
                i2 = *it2;
                i3 = *it3;
            }
        }
        
    }
}

int main()
{
    fastio;
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
    #endif
    
    int t, n, k;
    cin >> t;
    int arr[201000];
    while(t--)
    {
        set<int> s;
        vector<string> moves;
        cin >> n;
        cin >> k;

        foi(0, n)
        {
            int tmp;
            cin >> tmp;
            arr[i] = tmp-1;
            if (arr[i] != i)
            {
                s.insert(i);
            }
        }

        // for(int i: s)
        // {
        //     debug(i);
        // }

        if (s.size() == 0)
        {
            cout << 0 << '\n';
            continue;
        }

        if (s.size() < 3)
        {
            cout << -1 << '\n';
            continue;
        }

        while (s.size() > 2)
        {
            int i1;
            int i2;
            int i3;
            
            foo(s, arr, i1, i2, i3);

            stringstream ss;
            ss << i1 + 1 << ' ' << i2 + 1 << ' ' << i3 + 1;
            moves.push_back(ss.str());
            
            int a = arr[i1];
            int b = arr[i2];
            int c = arr[i3];

            arr[i2] = a;
            if (arr[i2] == i2)
            {
                s.erase(i2);
            }

            arr[i3] = b;
            if (arr[i3] == i3)
            {
                s.erase(i3);
            }

            arr[i1] = c;
            if (arr[i1] == i1)
            {
                s.erase(i1);
            }
        }

        if (s.size() > 0 || moves.size() > k)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << moves.size() << '\n';
            for(string & str: moves)
            {
                cout << str << '\n';
            }
        }
        
    }

    return 0;
}