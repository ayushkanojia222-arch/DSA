class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ts=0;
        int ct=0;
        int index=0;
        for(int i =0;i<gas.size();i++)
        {
            int net_fuel=gas[i]-cost[i];
            ts+=net_fuel;
            ct+=net_fuel;
             if (ct < 0) {
                index = i + 1; // Reset start to the next station
                ct = 0;       // Empty the tank for the fresh start
            }
        }if (ts<0)
        {
            return -1;
        }
        return index;
        
    }
};