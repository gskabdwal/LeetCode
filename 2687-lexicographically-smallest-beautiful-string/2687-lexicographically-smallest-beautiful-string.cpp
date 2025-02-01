class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        auto valid = [&](int i) {
            return (i < 1 || s[i] != s[i - 1]) && (i < 2 || s[i] != s[i - 2]);
        };
        for (int i = s.size() - 1; i >= 0; --i) {
            ++s[i];
            while (!valid(i))
                ++s[i];
            if (s[i] < 'a' + k) {
                for (i = i + 1; i < s.size(); ++i)
                    for (s[i] = 'a'; !valid(i); ++s[i]) ;
                return s;            
            }
        }
        return "";
    }
};