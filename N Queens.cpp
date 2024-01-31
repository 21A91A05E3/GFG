N-QUEENS

class Solution {
public:
    vector<vector<string>>ans;
    bool isvalid(int i,int j,int n,vector<string>&s)
    {
        int x=i,y=j;
        while(x>=0)
        {
            if(s[x][y]=='Q')return false;
            x--;
        }
        x=i,y=j;
        while(x>=0 and y>=0)
        {
            if(s[x][y]=='Q')return false;
            x--;
            y--;
        }
        x=i,y=j;
        while(x>=0 and y<n)
        {
            if(s[x][y]=='Q')return false;
            x--;
            y++;
        }

        return true;
    }
    void NQ(int i,int n,vector<string>s)
    {
        if(i==n)
        {
            ans.push_back(s);
            return;
        }
        for(int j=0;j<n;j++)
        {
            if(isvalid(i,j,n,s))
            {
                s[i][j]='Q';
                NQ(i+1,n,s);
                s[i][j]='.';
            }
        }
        return;
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>s(n,string(n,'.'));
        NQ(0,n,s);
        return ans;
    }
};
