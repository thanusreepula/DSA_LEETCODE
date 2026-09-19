char* longestPalindrome(char* s) {
  int n = strlen(s);
    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < n; i++) {
        // Odd palindrome: "aba"
        int left = i;
        int right = i;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }

        // Even palindrome: "abba"
        left = i;
        right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLength) {
                start = left;
                maxLength = right - left + 1;
            }
            left--;
            right++;
        }
    }

    char* answer = malloc(maxLength + 1);

    for (int i = 0; i < maxLength; i++) {
        answer[i] = s[start + i];
    }

    answer[maxLength] = '\0';

    return answer;   
}