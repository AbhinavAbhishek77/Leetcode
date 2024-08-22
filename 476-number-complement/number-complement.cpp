class Solution {
public:
    int findComplement(int num) {
        //      int result = 0;
        // while (num > 0) {
        //     result <<= 1;
        //     if (num & 1) {
        //         result |= 1;
        //     }
        //     num >>= 1;
        // }
        // return result;

        string bit = "";
        int x = num;
        while (x) {
            if (x & 1) {
                bit = ('0') + bit;
            } else {
                bit = ('1') + bit;
            }
            x >>= 1;
        }
        // cout << bit << endl;
        int n = bit.size();
        int ans=0;
       for(int i=0;i<n;i++)
       {
           ans<<=1;
           if(bit[i]=='1')
           {
            ans |=1;

           }
       }

        return ans;
    }
};