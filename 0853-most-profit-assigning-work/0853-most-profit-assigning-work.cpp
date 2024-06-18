class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        sort(worker.begin(),worker.end());
        vector<pair<int,int>>jobs;
        for (int i=0;i<n;i++) 
        {
            jobs.push_back({difficulty[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        int sum =0,best=0,j=0;
        for (int i=0;i<worker.size();i++)
        {
            while (j<n&&worker[i]>=jobs[j].first)
            {
                best=max(best,jobs[j].second);
                j++;
            }
            sum+=best;
        }
        return sum;
    }
};
