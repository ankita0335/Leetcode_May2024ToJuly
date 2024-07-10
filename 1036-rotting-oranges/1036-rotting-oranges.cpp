class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh=0;
        int time=0;
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        if(fresh==0)
            return 0;
        while(!q.empty())
        {
            int size=q.size();
            int tmp=0;
            while(size--)
            {
                pair<int,int>frontt=q.front();
                q.pop();
                int x1=frontt.first;
                int y1=frontt.second;
                int xax[4]={1,-1,0,0};
                int yay[4]={0,0,1,-1};
                for(int i=0;i<4;i++)
                {
                    int x=xax[i]+x1;
                    int y=yay[i]+y1;
                    if(isValid(x,y,n,m,grid))
                    {
                        tmp++;
                        grid[x][y]=2;
                        q.push({x, y});
                    }
                }
            }
            if(tmp!=0) 
                time++;
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    time = 0;
                    break;
                }
            }
        }
        return (time==0) ? -1 : time ;
    }
};