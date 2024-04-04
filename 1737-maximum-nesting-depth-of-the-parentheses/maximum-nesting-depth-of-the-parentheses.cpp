class Solution {
public:
    int mmdepth(string s) {
  int n=s.size();
        stack<char> fg;
        int dd = 0;
        int md = 0;
        for (char c : s)
         {
            if (c == ')')
             {
                if (!fg.empty())
                 {
                    fg.pop();
                    dd--;
                } else 
                {
                    return -1;
                }
            }

            else if (c == '(')
             {
                fg.push(c);
                dd++;
                md = max(md, dd);
            }
        }

        return fg.empty()?md:-1;
    }
    int maxDepth(string s) {
        return mmdepth(s);
    }
};