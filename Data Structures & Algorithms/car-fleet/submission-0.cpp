class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //stores position and speed of car as a pair of int
        vector<pair<int, int>> car;
        for(int i = 0; i < speed.size(); i++)
            car.push_back({position[i], speed[i]});

        sort(car.rbegin(), car.rend());
        vector<double> st;

        for(auto& it : car)
        { 
            st.push_back((double)(target - it.first)/it.second);
            if(st.size() >= 2 && st[st.size() - 1] <= st[st.size() - 2])
                st.pop_back();
        }
        return st.size();
    }
};
