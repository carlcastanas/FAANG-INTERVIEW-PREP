/*
    https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0
    Array + Dynamic Programming
    
    a[i] is no. of strings of length i ending with zero   
    We can append both 0/1 to strig ending with 0 so a[i] = a[i-1]+b[i-1]
    b[i] is no. of strings of length i ending with one
    wheras we can only append 0 to string ending with 1 so b[i] = a[i-1]
*/


#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i;
        cin>>n;
        int a[n],b[n];
        a[0]=1, b[0]=1;
        for(i=1;i<n;i++)
        {
            a[i]=(a[i-1]%mod + b[i-1]%mod)%mod;
            b[i]=a[i-1];
        }
        ll ans = (a[n-1]%mod + b[n-1]%mod)%mod;
        cout<<ans<<"\n";
    }
	return 0;
}