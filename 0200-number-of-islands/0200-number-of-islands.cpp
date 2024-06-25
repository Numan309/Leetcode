class Solution {
public:
      int r,c;
        int row[4]={1,-1,0,0};
        int col[4]={0,0,1,-1};
      bool valid(int i, int j) {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    int numIslands(vector<vector<char>>& grid) {
       r = grid.size();
       c = grid[0].size();
        queue<pair<int,int>>q;
        int cnt = 0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1')
                {
                    cnt++;
                    q.push(make_pair(i,j));
                    grid[i][j]='0';
                  
                  while(!q.empty())
                  {
                      int new_i=q.front().first;
                      int new_j=q.front().second;
                      q.pop();
                      //Check all four directions
                      for(int k=0;k<4;k++)
                      {
                          int ni = new_i+row[k];
                          int nj = new_j+col[k];
                          if(valid(ni,nj)&&grid[ni][nj]=='1'){
                              grid[ni][nj]='0';
                              q.push(make_pair(ni,nj));
                          }
                      }
                  }
                }
            }
        }
        return cnt;
    }
};