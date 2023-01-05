class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ctr = 0, i = 0;
        while (i < points.size()) {
            int e = points[i][1];
            int next = i+1;
            int min_e = e;
            while (next < points.size() && points[next][0] <= min_e) {
                if (points[next][1] < min_e) 
                    min_e = points[next][1];
                next++;
            }
            i = next;
            ctr++;
        }
        return ctr;
    }
};
