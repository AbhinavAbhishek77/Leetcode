class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int f = numBottles, e = 0, n = numExchange, b = 0;
int cnt=0;
        while (!(f == 0 && e < n)) {

            while (e >= n) {
                e -= n;
                n += 1;
                f += 1;
            }

            b += f;
            e += f;
            f = 0;
        }
        cout<<cnt;
        return b;


        //Approach 2
        //  int maxi = numBottles;
        // int cnt = 0;
        // while(maxi >= numExchange)
        // {
        //     maxi = maxi - numExchange + 1;
        //     numExchange++;
        //     cnt++;
        // }
    
        // return numBottles + cnt;
    }
};