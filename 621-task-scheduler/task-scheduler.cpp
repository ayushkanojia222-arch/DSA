class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Frequency of each task
        vector<int> freq(26, 0);

        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Max heap
        priority_queue<int> pq;

        for (int f : freq) {
            if (f > 0) {
                pq.push(f);
            }
        }

        int time = 0;

        while (!pq.empty()) {

            vector<int> temp;

            // One cycle has at most n + 1 tasks
            for (int i = 0; i <= n; i++) {

                if (!pq.empty()) {
                    int f = pq.top();
                    pq.pop();

                    f--;

                    if (f > 0) {
                        temp.push_back(f);
                    }

                    time++;
                }
                else {
                    // No task available
                    if (temp.empty())
                        break;

                    time++;
                }
            }

            // Put remaining tasks back
            for (int f : temp) {
                pq.push(f);
            }
        }

        return time;
    }
};