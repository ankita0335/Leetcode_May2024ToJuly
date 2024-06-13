class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int ans=0;
        sort(seats.begin(),seats.end(),greater<int>());
        sort(students.begin(),students.end(),greater<int>());
        for(int i=0;i<students.size();i++)
        {
            ans+=abs(students[i]-seats[i]);
        }
        return ans;
    }
};