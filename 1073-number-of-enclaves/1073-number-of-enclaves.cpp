class Solution {
public:
    bool isValid(int x,int y,int n,int m,vector<vector<int>>& grid)
    {
        if(x>=0 && y<m && x<n && y>=0 && grid[x][y]==1)
            return true;
        return false;
    }
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid)
    {
        grid[i][j]=0;
        int ax[4]={1,-1,0,0};
        int ay[4]={0,0,1,-1};
        for(int k=0;k<4;k++)
        {
            int x=ax[k]+i;
            int y=ay[k]+j;
            if(isValid(x,y,n,m,grid))
            {
                dfs(x,y,n,m,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //for first and last column
        for(int i=0;i<n;i++)
        {
            int j=0;
            if(grid[i][j]==1)
                dfs(i,j,n,m,grid);
            j=m-1;
            if(grid[i][j]==1)
                dfs(i,j,n,m,grid);
        }
        //for first and last row
        for(int j=0;j<m;j++)
        {
            int i=0;
            if(grid[i][j]==1)
                dfs(i,j,n,m,grid);
            i=n-1;
            if(grid[i][j]==1)
                dfs(i,j,n,m,grid);
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    c++;
                }
            }
        }
        return c;
    }
};