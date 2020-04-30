#include <bits/stdc++.h> 
using namespace std;

#define foi(a,b) for(int i = a; i < b; i++)
#define foj(a,b) for(int j = a; j < b; j++)
#define fok(a,b) for(int k = a; k < b; k++)
#define debug(a) cout << #a << ": " << a << endl;
#define debugArr(arr,n) cout <<#arr <<": "; foi(0, n) cout << arr[i] << ' '; cout << endl; 
#define mod 998244353L
#define lli long long int
#define vi vector<lli>

lli mul(lli& p1, lli& p2)
{
    return (p1*p2) % mod;
}

lli add(lli& p1, lli p2)
{
    return (p1+p2) % mod;
}

char AND(vi& p1, vi& p2, vi& res) 
{
    //0
    res[0] = add(res[0], mul(p1[0], p2[0]));
    res[0] = add(res[0], mul(p1[1], p2[0]));
    res[0] = add(res[0], mul(p1[2], p2[0]));
    res[0] = add(res[0], mul(p1[3], p2[0]));

    //1
    res[0] = add(res[0], mul(p1[0], p2[1]));
    res[1] = add(res[1], mul(p1[1], p2[1]));
    res[2] = add(res[2], mul(p1[2], p2[1]));
    res[3] = add(res[3], mul(p1[3], p2[1]));

    //a
    res[0] = add(res[0], mul(p1[0], p2[2]));
    res[2] = add(res[2], mul(p1[1], p2[2]));
    res[2] = add(res[2], mul(p1[2], p2[2]));
    res[0] = add(res[0], mul(p1[3], p2[2]));

    //A
    res[0]= add(res[0], mul(p1[0], p2[3]));
    res[3]= add(res[3], mul(p1[1], p2[3]));
    res[0]= add(res[0], mul(p1[2], p2[3]));
    res[3]= add(res[3], mul(p1[3], p2[3]));
}

char OR(vi& p1, vi& p2, vi& res) 
{
    //0
    res[0]= add(res[0], mul(p1[0], p2[0]));
    res[1]= add(res[1], mul(p1[1], p2[0]));
    res[2]= add(res[2], mul(p1[2], p2[0]));
    res[3]= add(res[3], mul(p1[3], p2[0]));

    //1
    res[1]= add(res[1], mul(p1[0], p2[1]));
    res[1]= add(res[1], mul(p1[1], p2[1]));
    res[1]= add(res[1], mul(p1[2], p2[1]));
    res[1]= add(res[1], mul(p1[3], p2[1]));

    //a
    res[2]= add(res[2], mul(p1[0], p2[2]));
    res[1]= add(res[1], mul(p1[1], p2[2]));
    res[2]= add(res[2], mul(p1[2], p2[2]));
    res[1]= add(res[1], mul(p1[3], p2[2]));

    //A
    res[3]= add(res[3], mul(p1[0], p2[3]));
    res[1]= add(res[1], mul(p1[1], p2[3]));
    res[1]= add(res[1], mul(p1[2], p2[3]));
    res[3]= add(res[3], mul(p1[3], p2[3]));
}

char XOR(vi& p1, vi& p2, vi& res) 
{
    //0
    res[0]= add(res[0], mul(p1[0], p2[0]));
    res[1]= add(res[1], mul(p1[1], p2[0]));
    res[2]= add(res[2], mul(p1[2], p2[0]));
    res[3]= add(res[3], mul(p1[3], p2[0]));

    //1
    res[1]= add(res[1],mul(p1[0], p2[1]));
    res[0]= add(res[0],mul(p1[1], p2[1]));
    res[3]= add(res[3],mul(p1[2], p2[1]));
    res[2]= add(res[2],mul(p1[3], p2[1]));

    //a
    res[2]= add(res[2], mul(p1[0], p2[2]));
    res[3]= add(res[3], mul(p1[1], p2[2]));
    res[0]= add(res[0], mul(p1[2], p2[2]));
    res[1]= add(res[1], mul(p1[3], p2[2]));

    //A
    res[3]= add(res[3], mul(p1[0], p2[3]));
    res[2]= add(res[2], mul(p1[1], p2[3]));
    res[1]= add(res[1], mul(p1[2], p2[3]));
    res[0]= add(res[0], mul(p1[3], p2[3]));
}

lli power(lli a , lli n)
{
	lli res = 1;
	
	while(n)
	{
		if(n & 1)
			res = (res * a) % mod;
		
		n >>= 1;
		a = (a * a) % mod;
	}
	
	return res;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    lli t;
    cin >> t;

    while(t--)
    {
        string exp;
        cin >> exp;

        stack<lli> stk1;
        stack<vi> stk2;
        
        lli cnt = 0;
        for(char a: exp)
        {
            if (a == '#')
            {
                cnt++;
                stk2.push(vi(4,1));
            }
            else if (a == '|' or a == '&' or a == '^')
            {
                stk1.push(a);
            }
            else if (a == ')')
            {
                vi op2 = stk2.top();
                stk2.pop();
                vi op1 = stk2.top();
                stk2.pop();
                
                vi res(4, 0);
                switch (stk1.top())
                {
                    case '&':
                        AND(op1, op2, res);
                        break;
                    case  '|':
                        OR(op1, op2, res);
                        break;
                    case  '^':
                        XOR(op1, op2, res);
                        break;
                }

                stk2.push(res);
                stk1.pop();
            }
        }

        lli d = power(power(4, cnt), mod-2);

        for(lli a: stk2.top())
            cout << (a*d) % mod << ' ';
        cout << endl;
            
    }

    return 0;
}