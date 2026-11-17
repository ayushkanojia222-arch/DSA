class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_set<string> st(bank.begin(), bank.end());

        if (st.find(endGene) == st.end())
            return -1;

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        unordered_set<string> visited;
        visited.insert(startGene);

        string genes = "ACGT";

        while (!q.empty()) {
            auto [gene, steps] = q.front();
            q.pop();

            if (gene == endGene)
                return steps;

            for (int i = 0; i < gene.size(); i++) {
                
                char original = gene[i];

                for (char ch : genes) {
                    
                    gene[i] = ch;

                    if (st.find(gene) != st.end() &&
                        visited.find(gene) == visited.end()) {
                        
                        visited.insert(gene);
                        q.push({gene, steps + 1});
                    }
                }

                gene[i] = original;
            }
        }

        return -1;
    }
};