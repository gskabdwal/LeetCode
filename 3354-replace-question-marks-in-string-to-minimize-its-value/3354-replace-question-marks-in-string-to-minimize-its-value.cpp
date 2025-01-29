
class Solution {
public:
	int c[26], d[26];
    string minimizeStringValue(string s) {
    	int k = 0;
    	for (char v: s) {
    		if (v != '?') c[v - 'a']++;
    		else k++;
    	}
    	for (int i = 0; i < 26; i++) d[i] = c[i];
    	for (int i = 0; i < k; i++) {
    		int mn = 0;
    		for (int j = 1; j < 26; j++) {
    			if (d[j] < d[mn]) mn = j;
    		}
    		d[mn]++;
    	}
    	for (char &v: s) {
    		if (v == '?') {
    			for (int i = 0; i < 26; i++) {
    				if (c[i] < d[i]) {
    					c[i]++;
    					v = i + 'a';
    					break;
    				}
    			}
    		}
    	}
    	return s;
    }
};