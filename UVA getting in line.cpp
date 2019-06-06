/*
  A simple backtracking problem
  Since constraints are very less
*/
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
vector<pair<ll,ll> >ans;
long double mini=bg;
ll maxi(ll a,ll b)
{
     if(a>b) return a;
     else    return b;
}
void sol(vector<pair<ll,ll> > vec,ll x[],ll y[],long double dist,ll n)
{
     if(vec.size()==n)
     {
		  if(dist<mini)
            {
			  mini=dist;
              ans=vec ;
            }
          return ;
     }
     ll i,j;
     ll last,second;
     if(vec.size()>0)
        {last=vec[vec.size()-1].first;second=vec[vec.size()-1].second;}
     else
        {last=0;second=0;}
     ff(i,n)
     {
          ll flag=1;
          ff(j,vec.size())
              if((x[i]==vec[j].first)&&(y[i]==vec[j].second))
               flag=0;
          if(flag==1)
          {
               vector<pair<ll,ll> >vec1;
               vec1=vec;
               vec1.pb(mp(x[i],y[i]));
               long double newdis=(x[i]-last)*(x[i]-last)+(y[i]-second)*(y[i]-second);
               if(vec.size()==0)
                 sol(vec1,x,y,dist,n);
               else
			     sol(vec1,x,y,dist+sqrt(newdis),n);   
          }
     }
}
void print(ll net)
{
   ll i;
   printf("**********************************************************\n");  
   printf("Network #%lld\n",net);  
   ff(i,ans.size()-1)     
   {
      long double dis;
      dis=(ans[i].first-ans[i+1].first)*(ans[i].first-ans[i+1].first)+(ans[i+1].second-ans[i].second)*(ans[i+1].second-ans[i].second);
      dis=sqrt(dis);
      printf("Cable requirement to connect (%lld,%lld) to (%lld,%lld) is %.2Lf feet.\n",ans[i].first,ans[i].second,ans[i+1].first,ans[i+1].second,dis+16);         
   }
   printf("Number of feet of cable required is %.2Lf.\n",mini+16*(ans.size()-1));
}
int main()
{
  ll n,net=1;
  while(cin>>n)
  {
     if(n==0)
       break;
     vector<pair<ll,ll> >vec1;  
     ll x[n],y[n],i;
     ff(i,n)
      gg(x[i],y[i]);
     sol(vec1,x,y,0,n);
     print(net);
     ans.clear();
     mini=bg;
     net++;
  }return 0;
}
