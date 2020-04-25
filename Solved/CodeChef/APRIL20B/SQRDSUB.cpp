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

//https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
int findSubArrOfSum(int arr[], int n, int sum) 
{ 
    unordered_map<int, int> prevSum; 
    int res = 0; 
    int currsum = 0; 
  
    for (int i = 0; i < n; i++) { 
        currsum += arr[i]; 
        if (currsum == sum)  
            res++;         
        if (prevSum.find(currsum - sum) !=  prevSum.end())  
            res += (prevSum[currsum - sum]); 
        prevSum[currsum]++; 
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
    
    int t, n;
    readInt(t);
    int arr[100100];

    while(t--)
    {
        readInt(n);
        foi(0, n)
        {
            int temp;
            readInt(temp);
            if (temp % 4 == 0)
                arr[i] = 2;
            else if (temp % 2 == 0)
                arr[i] = 1;
            else
                arr[i] = 0;
            
            // cout << arr[i] << ' ';
        }   
        
        // cout << endl;

        // 0(N^2) solution
        // int cnt = 0;
        // foi(0, n)
        // {
        //     int sum = 0;
        //     foj(i, n)
        //     {
        //         sum += arr[j];
        //         if (sum > 1)
        //         {
        //             cnt += n-j;
        //             break;
        //         }
        //         else if (sum != 1)
        //         {
        //             cnt++;
        //         }
        //     }
        // }

        // cout <<cnt << '\n';

        // O(N)
        cout << (n*(n+1)/2) - findSubArrOfSum(arr, n, 1) << '\n';

    }

    return 0;
}