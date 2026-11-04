class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start_idx = 0;
        int tank = 0; //current gas in tank
        int total = 0; //if total gas < cost, no solution
        for(int i = 0; i < gas.size(); i++)
        {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if(tank < 0)
            {
                start_idx = i + 1;
                tank = 0;
            }
        }
        return (total >= 0)?start_idx:-1;
    }
};