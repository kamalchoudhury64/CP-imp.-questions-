#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll bg=1234567890123;
#define ff(i,n) for(i=0;i<n;i++)
#define gg1(n1) cin>>n1;
#define gg(n1,n2) cin>>n1>>n2;
#define gg3(n1,n2,n3) cin>>n1>>n2>>n3;
#define hh(n) cout<<n<<endl;
#define t top
#define p push
#define pb push_back
#define mp make_pair
ll maxi(ll a,ll b)
{
     if(a>b) return a;
     else    return b;
}
int main()
{
  ll t;
  cin>>t;
  while(t--)
  {
  	   
	ll n,i,j;
	cin>>n;
	ll wind[n/100][10],dp[n/100+1][10];
	for(j=9;j>=0;j--)
	   for(i=0;i<n/100+1;i++) 
   	   	   dp[i][j]=bg;
	for(j=9;j>=0;j--)
	   for(i=0;i<n/100;i++) 
   	   	 cin>>wind[i][j];
   	dp[0][0]=0;   	 
 	for(i=0;i<n/100;i++)
 	{
 	  	for(j=0;j<10;j++)
 	   	{
 	   	   if(dp[i][j]!=bg)
			{
			  dp[i+1][j]=min(dp[i+1][j],dp[i][j]+30-wind[i][j]);
			  if(j-1>=0)
			   dp[i+1][j-1]=min(dp[i+1][j-1],dp[i][j]+20-wind[i][j]);
			  if(j+1<=9)
			   dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+60-wind[i][j]); 
			}   	   	
		}
	}
	printf("%lld",dp[n/100][0]);
	cout<<endl; 	
	  cout<<endl;
  }return 0;
}
