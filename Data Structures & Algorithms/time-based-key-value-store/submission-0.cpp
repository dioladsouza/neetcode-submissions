class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> mpp;

public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if(mpp.find(key) == mpp.end())
            return "";

        vector<pair<int, string>>& v = mpp[key];

        int low = 0;
        int high = v.size() - 1;
        string ans = "";

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(v[mid].first <= timestamp) {
                ans = v[mid].second;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
