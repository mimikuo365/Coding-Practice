class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> notFirst (n);
        vector<int> selectedNodes;
        for(int i=0; i < edges.size(); i++)
        {
            notFirst[edges[i][1]] = 1;
        } 
        for (int i=0; i < n; i++)
        {
            if (notFirst[i] == 0)
            {
                selectedNodes.push_back(i);
            }
        }
        return selectedNodes;
    }
};
