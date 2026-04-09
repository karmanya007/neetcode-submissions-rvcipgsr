class Solution {
public:
    void dfs2(int r, int c, set<pair<int, int>> &visit, int prevHeight, vector<vector<int>> &heights){
        if(visit.count({r, c}) || r < 0 || c < 0 || r == heights.size() || c == heights[0].size() || heights[r][c] < prevHeight)
            return;

        visit.insert({r, c});

        dfs2(r, c + 1, visit, heights[r][c], heights);
        dfs2(r, c - 1, visit, heights[r][c], heights);
        dfs2(r + 1, c, visit, heights[r][c], heights);
        dfs2(r - 1, c, visit, heights[r][c], heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int ROWS = heights.size();
        int COLS = heights[0].size();

        set<pair<int,int>> pac, atl;

        for(int c = 0; c < COLS; c++){
            dfs2(0, c, pac, heights[0][c], heights);
            dfs2(ROWS - 1, c, atl, heights[ROWS - 1][c], heights);
        }
        for(int r = 0; r < ROWS; r++){
            dfs2(r, 0, pac, heights[r][0], heights);
            dfs2(r, COLS - 1, atl, heights[r][COLS - 1], heights);
        }

        for(int x = 0; x < ROWS; x++){
            for(int y = 0; y < COLS; y++){
                if(pac.count({x, y}) && atl.count({x, y})){
                    res.push_back({x, y});
                }
            }
        }

        return res;
    }
};
