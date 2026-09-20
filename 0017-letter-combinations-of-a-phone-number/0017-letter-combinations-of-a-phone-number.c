/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
char *letters[] = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    int length = strlen(digits);

    if (length == 0) {
        *returnSize = 0;
        return malloc(0);
    }

    int total = 1;

    for (int i = 0; i < length; i++) {
        total *= strlen(letters[digits[i] - '0']);
    }

    char **result = malloc(total * sizeof(char*));

    for (int i = 0; i < total; i++) {
        result[i] = malloc((length + 1) * sizeof(char));

        int value = i;

        for (int j = length - 1; j >= 0; j--) {
            char *options = letters[digits[j] - '0'];
            int optionCount = strlen(options);

            result[i][j] = options[value % optionCount];
            value /= optionCount;
        }

        result[i][length] = '\0';
    }

    *returnSize = total;
    return result;    
}