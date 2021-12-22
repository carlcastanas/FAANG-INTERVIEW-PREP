/*  
    We've to find intersection of two vectors containing closed intervals. Here given that individual list are pairwise disjoint and sorted, so that's why we don't need to compare the 
    interval after merging as we were doing in merge intervals problem.

    Input: A = [[0,2],[5,10],[13,23],[24,25]], B = [[1,5],[8,12],[15,24],[25,26]]
    Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
    
    TC: O(m+n)
    Space: O(m+n) if output space is considered else O(1)
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) 
    {
        vector<vector<int>> merged;
        int i=0, j=0;
        while(i<A.size() && j<B.size())
        {
            int low = max(A[i][0], B[j][0]);
            int high=min(A[i][1], B[j][1]);
            
            if(low<=high)
                merged.emplace_back(vector<int> ({low, high}));
            
            if(A[i][1] < B[j][1])   // if ending of the first one is smaller than the second one, then move forward 
                i++;
            else
                j++;
        }
        
        return merged;
    }
};