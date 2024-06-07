class Solution {
    //TC:o(n*k + f*k^2)
    //  n = no. of words in  dictionary
    // f = number of words in  sentence
    //k=  average length of each word
//SC:O(n*k)
public:
     string findingrootword(string& sentenceword, unordered_set<string>& sett) {
        for(int l = 1; l <= sentenceword.length(); l++) {
            string rootword = sentenceword.substr(0, l);
            if(sett.count(rootword)) {
                return rootword;
            }
        }
        return sentenceword;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> sett(dictionary.begin(), dictionary.end());
        stringstream ss(sentence);
        string word;
        string anss;
        while(getline(ss, word, ' ')) {
            anss += findingrootword(word, sett) + " ";
            // cout<<word<<" ";
        }
        anss.pop_back();
        return anss;
    }
};