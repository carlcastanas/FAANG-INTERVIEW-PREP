/* Naive approach is to build a map of vector with indexex sum as key, and reverse vector of even key but this would require Space Complexiy O(mn) other than output */

/*  Important concept of moving heads from both direction 
    TC: O(mn) : Space: O(1)
    
    Input:

        [ 1, 2, 3 ]
        [ 4, 5, 6 ]
        [ 7, 8, 9 ]

    Output:  [1,2,4,7,5,3,6,8,9]
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) 
    {
        if(matrix.size()==0)
            return {};

        int n=matrix.size(), m=matrix[0].size();
        
        vector<int> result(n*m);
        
        int row=0, col=0, k=0, direction=1; //direction 1 means moving up, 0 means moving down
        while(row<n && col<m)
        {
            result[k++] = matrix[row][col];
            
            int new_row = row + (direction==1?-1:1);
            int new_col = col + (direction==1?1:-1);
            
            if(new_row<0 || new_row==n || new_col<0 || new_col==m)  //if element is going out of bound, then change the head
            {
                if(direction==1)
                {
                    row += (col==m-1?1:0);
                    col += (col<m-1?1:0);
                }
                else
                {
                    col += (row==n-1?1:0);
                    row += (row<n-1?1:0);
                }
                
                direction = !direction;
            }
            else    //else move forward with next element
            {
                row = new_row;
                col = new_col;
            }
        }
        return result;
    }
};