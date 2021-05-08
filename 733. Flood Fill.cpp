class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        queue<pair<int, int>> g; 
        g.push(make_pair(sr, sc));
        int val = image[sr][sc];
        int x_size = image.size();
        int y_size = image[0].size();
        vector<vector<int>> visited (x_size, vector<int>(y_size, 0));
        while(!g.empty())
        {
            pair<int, int> cur = g.front();
            g.pop();

            // cout << cur.first << cur.second << endl;
            image[cur.first][cur.second] = newColor;        
            if (visited[cur.first][cur.second] == 0)
            {
                visited[cur.first][cur.second] = 1;
                if (cur.first >= 0 && cur.second >= 1 && image[cur.first][cur.second - 1] == val)
                    g.push(make_pair(cur.first, cur.second - 1));     
                if (cur.first >= 0 && cur.second < y_size - 1 && image[cur.first][cur.second + 1] == val)
                    g.push(make_pair(cur.first, cur.second + 1));
                if (cur.first >= 1 && cur.second >= 0 && image[cur.first - 1][cur.second] == val)                
                    g.push(make_pair(cur.first - 1, cur.second));
                if (cur.first < x_size - 1 && cur.second >= 0 && image[cur.first + 1][cur.second] == val)
                    g.push(make_pair(cur.first + 1, cur.second));
                
            }
        }
        return image;
    }
};
