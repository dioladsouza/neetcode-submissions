class CountSquares {
public:
    unordered_map<int, unordered_map<int, int>> mpp;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        mpp[x][y]++;
    }
    
    int getCount(int x, int y)
    {
        if(!mpp.count(x)) return 0;
        return mpp[x][y];
    }
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        if(!mpp.count(x)) return 0;

        int res = 0;

        for(auto& [y2, freq] : mpp[x])
        {
            if(y2 == y) continue;
            int len = abs(y2 - y);

            res += freq * getCount(x + len, y) * getCount(x + len, y2);
            res += freq * getCount(x - len, y) * getCount(x - len, y2);   
        }
        return res;
    }
};
