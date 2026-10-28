class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> p;

        for(int i = 0; i < n; i++){
            p.push_back({position[i], speed[i]});
        }

        // Sort by position desc
        sort(p.rbegin(), p.rend());

        int res = 1;
        double prevTime = (target - p[0].first) / (1.0 * p[0].second);

        for(int i = 1; i < n; i++){
            double curTime = (target - p[i].first) / (1.0 * p[i].second);
            
            if(curTime > prevTime){
                res++;
                prevTime = curTime;
            }
        } 

        return res;
    }
};
