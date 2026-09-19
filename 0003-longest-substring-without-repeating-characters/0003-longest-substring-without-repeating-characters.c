int lengthOfLongestSubstring(char* s) {
   int last[256] = {0};
    int start = 0;
    int longest = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char ch = s[i];

        if (last[ch] > start) {
            start = last[ch];
        }

        int length = i - start + 1;

        if (length > longest) {
            longest = length;
        }

        last[ch] = i + 1;
    }

    return longest; 
}