class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // TC:O(N3)
        //  int cnt = 0;
        //  for (int i = 0; i < arr.size(); i++) {
        //      int a = 0;
        //      for (int j = i + 1; j < arr.size(); j++) {
        //          a ^= arr[j - 1];
        //          int b = 0;
        //          for (int k = j; k < arr.size(); k++) {
        //              b ^= arr[k];
        //              if (a == b)
        //                  cnt++;
        //          }
        //      }
        //  }
        //  return cnt;

        // //Approach 2
        //TC: O(N2)
        //SC:O(1)
        int n = arr.size();
        int prefixxorr[n + 1];
        prefixxorr[0] = 0;
        // find prefixxorr
        int currxorr = 0;
        for (int i = 0; i < n; i++) {
            currxorr = currxorr ^ arr[i];
            prefixxorr[i + 1] = currxorr;
        }
        int cnt = 0;
        //check in prefixxorr array
        for (int i = 0; i <= n; i++) {
            for (int k = i + 1; k <= n; k++) {
                if (prefixxorr[i] == prefixxorr[k])
                    cnt += (k - i - 1);
            }
        }
        return cnt;
    }
};