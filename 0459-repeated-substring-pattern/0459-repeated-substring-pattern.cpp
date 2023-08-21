class Solution {
public:
    bool check(string s, string tmp, int i){
        for(; i<s.length(); i+= tmp.length()){
            // cout << s.substr(i, tmp.length()) << " " << tmp << endl;
            if(s.substr(i, tmp.length()) != tmp) return false;
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        string tmp = "";
        set<char> st;

        for(int i=0; i<s.length(); i++){
            if(st.find(s[i]) != st.end() && check(s, tmp, i)){
                return true;
            }
            tmp += s[i];
            st.insert(s[i]);
        }

        return false;
    }
};