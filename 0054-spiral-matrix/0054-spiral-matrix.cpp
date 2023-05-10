class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        vector<int> ans;
        int i,j,l=0,r=matrix[0].size(),b=matrix.size(),t=0;
        
        //first understand that basic idea is to keep on decrementing the right+(r) and bottom(b) increment the left(l) and top(t) and as soon as the condition does not satisfy
        //it comes out of the below loop
        
        while(l<r && t<b)
        {
            j=l;
            //incrementing the j from left to just before right
            //to get the top row
            
            while(j<r)
            {
                ans.push_back(matrix[t][j]);
                j++;
            }
            
            //incrementing top as the first row is done till end
            t++;
            
            //going from just the newly updated top tp the index below the bottom to get right column
            i=t;
            while(i<b)
            {
                ans.push_back(matrix[i][r-1]);
                i++;
            }
            //decrementing  right as the rightmost column is done till end and we need to began from right most column-1
            r--;
            
            
            //but before begining we need to be sure that we are not traversing hte same bottom row again 
            //so that is why checking if whether the top is atleast one above the bottom hence there is scope to traverse
            //bottom row from right to left
            if(b>t)
            {
                j=r-1;
                
                while(j>=l)
                {
                    ans.push_back(matrix[b-1][j]);
                    j--;
                }
                
                b--;
            }
            
            
            //but before begining we need to be sure that we are not traversing hte same left column again 
            //so that is why checking if whether the left is atleast one before the bottom hence there is scope to traverse
            //lwft column from bottom to top
            if(r>l)
            {
                i=b-1;
                
                while(i>=t)
                {
                    ans.push_back(matrix[i][l]);
                    i--;
                }
                
                l++;
            }
        }
        
        return ans;
    }
};