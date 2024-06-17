class Solution {
public:
    bool judgeSquareSum(int c) {
        long long s=0, e=sqrt(c);

        while(s<=e)
        {
            long long x=(long long)(s*s) + (long long)(e*e);
            if(x==c) return true;
            else if(x<c)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        return false;
    }
};