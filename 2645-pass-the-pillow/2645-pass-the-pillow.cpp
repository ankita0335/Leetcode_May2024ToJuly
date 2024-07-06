class Solution {
public:
    int passThePillow(int n, int time) {
        int c=1;
        bool pass=true;
        while (time>0) 
        {
            if (pass) 
            {
                if (c==n) 
                {
                    pass=false; 
                    c--; 
                } 
                else
                {
                    c++;  
                }
            } 
            else 
            {
                if (c==1) 
                {
                    pass=true; 
                    c++;  
                } 
                else 
                {
                    c--; 
                }
            }
            time--;
        }
        return c;
    }
};
