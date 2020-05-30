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

bool findPair(map<int, multiset<int>>& m, int& a, int& b)
{
    for(auto p: m)
    {
        for(int x: p.second)
        {
            if (m[x].find(p.first) != m[x].end())
            {
                a = p.first;
                b = x;
                return true;
            }
        }
    }
    return false;
}

bool isInNet(int elm, int netId, int * arr, int *net, int n)
{
    foi(0, n)
    {
        if (arr[i] == elm and net[i] == netId)
        {
            return true;
        }
    }
    return false;
}

int checkNet(int n1, int n2, int * arr, int * net, int n)
{
    foi(0, n)
    {
        if (net[i] == n1)
        {
            if (net[arr[i]] == n2)
            {
                return i;
            }
        }
    }
    return -1;
}

void doubleExch(map<int, multiset<int>>& m, int * arr, int * net, int n, int& cnt)
{
    int a, b;
    while(findPair(m, a, b))
    {
        int f1 = checkNet(a, b, arr, net, n);
        int f2 = checkNet(b, a, arr, net, n);
        swap(arr[f1], arr[f2]);
        
        auto it = m[a].find(b);
        m[a].erase(it);
        
        it = m[b].find(a);
        m[b].erase(it);

        cnt++;
    }
}

void singleExch(map<int, multiset<int>>& m, int * arr, int * net, int n, int &cnt)
{
    foi(0, n)
    {
        if (net[i] != 0 and arr[i] != i)
        {
            int* loc = find(arr, arr + n, i);

            auto it = m[net[i]].find(net[arr[i]]);
            m[net[i]].erase(it);

            m[net[loc-arr]].insert(net[arr[i]]);
            it = m[net[loc-arr]].find(net[i]);
            m[net[loc-arr]].erase(it);
            
            swap(*loc, arr[i]);

            cnt++;
            break;
        }
    }
}

void printM(map<int, multiset<int>>& m)
{
    cout << "DEBUG: " << endl;
    for(auto p: m)
    {
        cout << p.first << ' ';
        for(int x: p.second)
        {
            cout << x << ' ';
        }
        cout <<  endl;
    }
}

bool areNetFixed(map<int, multiset<int>>& m)
{
    for(auto p: m)
    {
        if (p.second.size() > 0)
            return false;
    }
    return true;
}

void sortNet(int * arr, int * net, int n)
{
    foi(0, n)
    {
        if (arr[i] != i and net[i] != 0 and isInNet(i, net[i], arr, net, n))
        {
            int* loc = find(arr, arr + n, i);
            swap(*loc, arr[i]);
        }
    }
}

void genMap(map<int, multiset<int>>& m, int * arr, int * net, int n)
{
    foi(0, n)
    {
        if (i != arr[i] and net[i] != net[arr[i]])
        {
            m[net[i]].insert(net[arr[i]]);
        }
    }
}

void sortZero(int * arr, int * net, int n, int& cnt)
{
    foi(0, n)
    {
        if (net[i] == 0 and arr[i] != i)
        {
            int * loc = find(arr, arr + n, i);
            swap(arr[i], *loc);
            cnt++;
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
    
    int t, n, m;
    cin >> t;
    int arr[20];
    while(t--)
    {
        int net[20] = {0};
        cin >> n >> m;
        foi(0, n)
        {
            cin >> arr[i];
            arr[i]--;
        }

        set<int> clusters;

        int netId = 1;
        foi(0, m)
        {
            int t1, t2;
            cin >> t1 >> t2;
            if (net[t1-1] == 0 and net[t2-1] == 0)
            {  
                net[t1-1] = net[t2-1] = netId++;
            }
            else if (net[t1-1] == 0)
            {
                net[t1-1] = net[t2-1];
            }
            else if (net[t2-1] == 0)
            {
                net[t2-1] = net[t1-1];
            }
            else
            {
                int n1 = net[t1-1], n2 = net[t2-1];
                foj(0, n)
                {
                    if (net[j] == n1 or net[j] == n2)
                    {
                        net[j] = netId;
                    }
                }
                netId++;
            }
        }

        int cnt = 0;

        foi(0, n)
        {
            if (net[i] == 0 and i != arr[i])
            {
                int *f = find(arr, arr + n, i);
                swap(*f, arr[i]);
                cnt++;
            }
        }

        sortNet(arr, net, n);

        map<int, multiset<int>> m;
        genMap(m, arr, net, n);

        sortNet(arr, net, n);
        doubleExch(m, arr, net, n, cnt);
        sortNet(arr, net, n);
        
        while(!areNetFixed(m))
        {
            singleExch(m, arr, net, n, cnt);
            sortNet(arr, net, n);

            doubleExch(m, arr, net, n, cnt);
            sortNet(arr, net, n);
        }

        sortZero(arr, net, n, cnt);

        cout << cnt << '\n';
    }

    return 0;
}