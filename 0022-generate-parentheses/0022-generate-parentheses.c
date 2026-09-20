/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
char **result = malloc(1430 * sizeof(char *));
    char current[17];
    int total = 1 << (2 * n);

    *returnSize = 0;

    for (int mask = 0; mask < total; mask++) {
        int balance = 0;
        int valid = 1;

        for (int i = 0; i < 2 * n; i++) {
            if (mask & (1 << i)) {
                current[i] = '(';
                balance++;
            } else {
                current[i] = ')';
                balance--;
            }

            if (balance < 0) {
                valid = 0;
                break;
            }
        }

        if (valid && balance == 0) {
            current[2 * n] = '\0';
            result[*returnSize] = malloc(2 * n + 1);

            for (int i = 0; i <= 2 * n; i++) {
                result[*returnSize][i] = current[i];
            }

            (*returnSize)++;
        }
    }

    return result;    
}