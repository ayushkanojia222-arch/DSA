class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);

        // Store last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        stack<char> st;
        vector<bool> seen(26, false);

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Already present
            if (seen[c - 'a'])
                continue;

            // Remove larger characters if they occur again later
            while (!st.empty() &&
                   st.top() > c &&
                   last[st.top() - 'a'] > i) {

                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            seen[c - 'a'] = true;
        }

        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};