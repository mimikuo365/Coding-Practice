class Solution 
{
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        typedef vector<int> Type;
        priority_queue<Type, vector<Type>, greater<Type>> pq;
        Type selected_node{0, heights[0][0], 0, 0};
        bool visited_all = false;

        int rows = heights.size();
        int columns = heights[0].size();
        vector<vector<int>> visited(rows, vector<int>(columns, 0));
        // cout << rows << columns << endl;
        while (!visited_all)
        {
            // for (int i = 0; i < 4; i++)
            //     cout << selected_node[i];
            // cout << endl;
            int step = selected_node[0];
            int cur_value = selected_node[1];
            int cur_row = selected_node[2];
            int cur_col = selected_node[3];
            visited[cur_row][cur_col] = 1;

            if (cur_row == rows-1 && cur_col == columns-1)
                return step;            

            vector<vector<int>> neighbors{
                {cur_row + 1, cur_col},
                {cur_row - 1, cur_col},
                {cur_row, cur_col + 1},
                {cur_row, cur_col - 1}
            };
            for (int i = 0; i < 4; i++)
            {
                int neighbor_row = neighbors[i][0];
                int neighbor_col = neighbors[i][1];
                bool in_range = (neighbor_row >= 0) && (neighbor_row < rows)
                    && (neighbor_col >= 0) && (neighbor_col < columns);
                if (in_range)
                {
                    // cout << neighbor_row << neighbor_col << " ";
                    if (!visited[neighbor_row][neighbor_col])
                    {
                        int neighbor_value = heights[neighbor_row][neighbor_col];
                        int diff = abs(neighbor_value - cur_value);
                        if (diff < step)
                        {
                            diff = step;    
                        }
                        pq.push({diff, neighbor_value, neighbor_row, neighbor_col});
                    }   
                }
            }
            
            if (!pq.empty())
            {
                selected_node = pq.top(); pq.pop();
            }
            // else
            // {
            //     visited_all = true;                
            // }
            // cout << endl;
        }
        return 0;
    }
};
