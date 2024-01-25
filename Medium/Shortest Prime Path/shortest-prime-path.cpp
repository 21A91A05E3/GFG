//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    bool isprime(int n)
      {
          if(n<2)
          return false;
          for(int i=2;i*i<=n;i++)
          {
              if(n%i==0)
              {
                  return false;
              }
          }
          return true;
      }
    
    int solve(int num1,int num2)
    {   
      //code here
     
      queue<pair<int,int>>q;
      int c=0;
      q.push({num1,0});
      if(num1==num2)
      {
          return 0;
      }
      vector<int>vis(10000,0);
      while(!q.empty())
      {
          
          int num = q.front().first;
          int ct = q.front().second;
          q.pop();
          vis[num]=1;
          //cout << " hi" << endl;
          for(int j=0;j<4;j++)
          {
              for(int i=0;i<10;i++)
              {
                  if(i==0 and j==0)
                  continue;
                 string s=to_string(num);
                 s[j]='0'+i;
                 int final=stoi(s);
                 if(vis[final]==1)
                 {
                     continue;
                 }
                  if(isprime(final))
                  {
                      //cout << "hiiii" << endl;
                      if(final==num2)
                      {
                          
                          return ct+1;
                      }
                      q.push({final,ct+1});
                  }
                  
              }
          }
      }
      return c;
      
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends