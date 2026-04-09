class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pairs(n);

        for(int i = 0; i < n; i++){
            pairs[i] = {position[i], speed[i]};
        }

        sort(pairs.rbegin(), pairs.rend());

        double prevTime = (double)(target - pairs[0].first) / pairs[0].second;
        int res = 1;

        for(int i = 1; i < n; i++){
            double curTime = (double)(target - pairs[i].first) / pairs[i].second;
            cout << prevTime << " " << curTime << endl;
            if(curTime > prevTime){
                res++;
                prevTime = curTime;
            }
        }

        return res;
    }
};
