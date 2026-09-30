class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int num:arr)
        {
            mp[num]++;
                    }
                    priority_queue<pair<int,int>>pq;
                    for(auto it:mp)
                    {
                        pq.push({it.second,it.first});
                    }
                    int n =arr.size();
                    int c=0;
                    int r=0;
                    while(r<n/2)
                    {
                        int freq=pq.top().first;
                        pq.pop();
                        r+=freq;
                        c++;
                    }
                    return c;
        
    }
};