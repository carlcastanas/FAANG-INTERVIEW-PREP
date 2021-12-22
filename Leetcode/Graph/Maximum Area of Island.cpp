/*  
    Recursive DFS solution TC: O(r*c) and O(r*c) for call stack and similary if we use a seen matrix[][] 
    Here we're defining that island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical). But it could be 8 directional too :/
    
    TC & Space: O(M*N)
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int result=0;   
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[i].size(); j++)
            {
                if(grid[i][j] == 1)
                    result = max(result, maxArea(grid, i, j));
            }
        
        return result;
    }
    
private:
    int maxArea(vector<vector<int>>& grid, int r, int c)
    {
        if(r<0 || r>=grid.size() || c<0 || c>=grid[r].size() || grid[r][c]==0)
            return 0;
        
        grid[r][c]=0;   // mark the land
        
        return (1 + maxArea(grid, r-1, c) + maxArea(grid, r, c+1) + maxArea(grid, r+1, c) + maxArea(grid, r, c-1));     // explore all the four directions
    }
};

/* BFS Solution: Same TC but slower in execution */

int maxAreaOfIsland(vector<vector<int>>& grid) 
{
    int result=0;
    int m = grid.size(), n = grid[0].size(), count=0, offsets[] = {0, 1, 0, -1, 0};
    
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
        {
            if (grid[i][j] == 1) 
            {
                count = 1;
                grid[i][j] = 0;

                queue<pair<int, int>> todo;
                todo.push({i, j});
                while (!todo.empty()) 
                {
                    pair<int, int> p = todo.front();
                    todo.pop();
                    for (int k = 0; k < 4; k++) 
                    {
                        int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                        if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) 
                        {
                            grid[r][c] = 0;
                            count++;
                            todo.push({r, c});
                        }
                    }
                }
            }
            result = max(result, count);
        }
    return result;
}

/* Iterative method using a call stack */
class Solution {
    public int maxAreaOfIsland(int[][] grid) 
    {
        boolean[][] seen = new boolean[grid.length][grid[0].length];
        int[] dr = new int[]{1, -1, 0, 0};
        int[] dc = new int[]{0, 0, 1, -1};

        int ans = 0;
        for (int r0 = 0; r0 < grid.length; r0++) 
        {
            for (int c0 = 0; c0 < grid[0].length; c0++) 
            {
                if (grid[r0][c0] == 1 && !seen[r0][c0]) 
                {
                    int shape = 0;
                    Stack<int[]> stack = new Stack();
                    stack.push(new int[]{r0, c0});
                    seen[r0][c0] = true;
                    while (!stack.empty()) 
                    {
                        int[] node = stack.pop();
                        int r = node[0], c = node[1];
                        shape++;
                        for (int k = 0; k < 4; k++) 
                        {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if (0 <= nr && nr < grid.length && 0 <= nc && nc < grid[0].length && grid[nr][nc] == 1 && !seen[nr][nc]) 
                            {
                                stack.push(new int[]{nr, nc});
                                seen[nr][nc] = true;
                            }
                        }
                    }
                    ans = Math.max(ans, shape);
                }
            }
        }
        return ans;
    }
}