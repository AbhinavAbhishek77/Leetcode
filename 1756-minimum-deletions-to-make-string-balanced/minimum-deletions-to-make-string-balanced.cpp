class Solution {
public:
    int minimumDeletions(string s) {
        int temp = 0;
        int fin = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'b')
                temp++;
            else if (temp != 0) {
                temp--;
                fin++;
            }
        }

        return fin;
    }
};