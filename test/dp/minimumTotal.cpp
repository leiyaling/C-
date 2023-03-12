int minimumTotal(vector<vector<int> > &triangle) {

        for(int i=1;i<triangle.size();i++)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                if(j==0)
                {
                    triangle[i][j]=triangle[i-1][j]+triangle[i][j];
                }
                else if(i==j)
                {
                    triangle[i][j]=triangle[i-1][j-1]+triangle[i][j];
                }
                else{
                    triangle[i][j]=min(triangle[i-1][j],triangle[i-1][j-1])+triangle[i][j];
                }
                
            }
        }
        int result = triangle[triangle.size() - 1][0];
        // min(F(n-1, i))在最后一行选出最小路径
        for (int i = 1; i < triangle.size(); i++){
            result = min(triangle[triangle.size() - 1][i], result);
         }
        return result;
    }