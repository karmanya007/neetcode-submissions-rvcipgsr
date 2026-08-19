class Solution {
public:
    bool isEatable(vector<int> &piles, int h, int k){
        int time = 0;
        for(int &p : piles){
            time += ceil((p * 1.0) / k);
            if(time > h) return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = r;

        while(l <= r){
            int k = l + (r - l) / 2;

            if(isEatable(piles, h, k)){
                res = min(res, k);
                r = k - 1;
            }
            else{
                l = k + 1;
            }
        }

        return res;
    }
};
