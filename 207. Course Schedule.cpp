class Solution {
public:
bool canFinish(int nc, vector<vector<int>>& p) {
        vector<int> g[nc];
        vector<int> ind(nc);
        for(int i=0; i<p.size(); i++){
            g[p[i][0]].push_back(p[i][1]);
            ind[p[i][1]]++;
        }
        queue<int> q;
        for(int i=0; i<nc; i++){
            if(ind[i]==0) q.push(i);
        }
        int c = q.size();
        while(!q.empty()){
            int x= q.front();
            q.pop();
            for(auto y:g[x]){
                ind[y]--;
                if(ind[y]==0){
                    q.push(y);
                    c++;
                }
            }
        }
        if(c!=nc) return false;
        return true;
    }
};
