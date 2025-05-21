class Solution {
public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = deadline.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        sort(jobs.rbegin(), jobs.rend());

        int maxDeadline = 0;
        for (int i = 0; i < n; i++) {
            maxDeadline = max(maxDeadline, deadline[i]);
        }

        vector<int> slot(maxDeadline + 1, -1);

        int countJobs = 0;
        int totalProfit = 0;

        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            for (int j = d; j >= 1; j--) {
                if (slot[j] == -1) {
                    slot[j] = p;
                    totalProfit += p;
                    countJobs++;
                    break;
                }
            }
        }

        return {countJobs, totalProfit};
    }
};
