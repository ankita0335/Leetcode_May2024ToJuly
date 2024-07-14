class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<string>q;
        q.push(start);
        unordered_set<string>vis;
        vis.insert(start);
        int level=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                string curr=q.front();
                q.pop();
                if(curr==end)
                {
                    return level;
                }
                for(char ch : "ACGT")
                {
                    for(int i=0;i<curr.length();i++)
                    {
                        string nbr=curr;
                        nbr[i]=ch;
                        if(vis.find(nbr)==vis.end() && st.find(nbr)!=st.end())
                        {
                            vis.insert(nbr);
                            q.push(nbr);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};