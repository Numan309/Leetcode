class Solution {
public:
    int strStr(string haystack, string needle) {
      for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                bool matches = true;
                for (int j = 1; j < needle.length(); j++) {
                    if (haystack[i + j] != needle[j]) {
                        matches = false;
                        break;
                    }
                }
                if (matches) {
                    return i;
                }
            }
        }
        return -1;
    }
};