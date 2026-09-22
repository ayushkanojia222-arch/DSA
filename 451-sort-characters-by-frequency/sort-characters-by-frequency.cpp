class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char ch:s){
            mp[ch]++;
            }
            priority_queue<pair<int,char>>pq;
            for(auto it:mp){
                pq.push({it.second,it.first});
            }
            string ans;
            while(!pq.empty()){
                auto top = pq.top();
                pq.pop();

                int freq = top.first;
                char ch = top.second;
                  for(int i = 0; i < freq; i++) {
                ans += ch;
            }
            }
return ans;
        
    }
};