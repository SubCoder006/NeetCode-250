class Solution {
public:
    bool isAlnum(char c) {
        if ((c >= '0' && c <= '9') ||
            (tolower(c) >= 'a' && tolower(c) <= 'z')) {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int st = 0, end = s.size() - 1;
        while(st < end){
            if(!isAlnum(s[st])){
                st++;
                continue;
            }
            if(!isAlnum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st]) != tolower(s[end])){
                return false;
            }
            st++; end--;
        }
        return true;
    }
};
