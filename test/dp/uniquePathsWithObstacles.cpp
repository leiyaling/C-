int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        // write code here

         // 申请F(i,j)空间，初始值为0
         int M=obstacleGrid.size();
         int N=obstacleGrid[0].size();
        vector<vector<int> > ret(M, vector<int>(N, 0));
        // 第0列中只要前面有障碍，后面都无法到达
        for(int i=0;i<M;i++)
        {
            if(obstacleGrid[i][0]==1)
                break;
            else
                ret[i][0]=1;
        }
        // 第0行中只要前面有障碍，后面都无法到达
        for(int j=0;j<N;j++)
        {
            if(obstacleGrid[0][j]==1)
                break;
            else
                ret[0][j]=1;
        }
        for(int i=1;i<M;i++)
        {
            for(int j=1;j<N;j++)
            {
                //obstacleGrid[i][j]有障碍，无法到达
                if(obstacleGrid[i][j]==1)
                    ret[i][j]=0;
                else
                    ret[i][j]=ret[i-1][j]+ret[i][j-1];
            }
        }
        return ret[M-1][N-1];
    }