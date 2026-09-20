/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
int sLen = strlen(s);
    int wordLen = strlen(words[0]);
    int totalLen = wordLen * wordsSize;
    int tableSize = 10007;
    int uniqueCount = 0;

    int *result = malloc((sLen + 1) * sizeof(int));
    int *head = malloc(tableSize * sizeof(int));
    int *next = malloc(wordsSize * sizeof(int));
    int *need = calloc(wordsSize, sizeof(int));
    int *have = calloc(wordsSize, sizeof(int));
    char **uniqueWords = malloc(wordsSize * sizeof(char *));

    *returnSize = 0;

    for (int i = 0; i < tableSize; i++) {
        head[i] = -1;
    }

    for (int i = 0; i < wordsSize; i++) {
        unsigned long hash = 5381;

        for (int j = 0; j < wordLen; j++) {
            hash = ((hash << 5) + hash) + words[i][j];
        }

        int bucket = hash % tableSize;
        int index = head[bucket];

        while (index != -1 && strncmp(uniqueWords[index], words[i], wordLen) != 0) {
            index = next[index];
        }

        if (index == -1) {
            index = uniqueCount++;
            uniqueWords[index] = words[i];
            next[index] = head[bucket];
            head[bucket] = index;
        }

        need[index]++;
    }

    for (int offset = 0; offset < wordLen && offset < sLen; offset++) {
        memset(have, 0, uniqueCount * sizeof(int));

        int left = offset;
        int count = 0;

        for (int right = offset; right + wordLen <= sLen; right += wordLen) {
            unsigned long hash = 5381;

            for (int j = 0; j < wordLen; j++) {
                hash = ((hash << 5) + hash) + s[right + j];
            }

            int bucket = hash % tableSize;
            int index = head[bucket];

            while (index != -1 && strncmp(uniqueWords[index], s + right, wordLen) != 0) {
                index = next[index];
            }

            if (index == -1) {
                while (count > 0) {
                    unsigned long leftHash = 5381;

                    for (int j = 0; j < wordLen; j++) {
                        leftHash = ((leftHash << 5) + leftHash) + s[left + j];
                    }

                    int leftIndex = head[leftHash % tableSize];

                    while (strncmp(uniqueWords[leftIndex], s + left, wordLen) != 0) {
                        leftIndex = next[leftIndex];
                    }

                    have[leftIndex]--;
                    left += wordLen;
                    count--;
                }

                left = right + wordLen;
            } else {
                have[index]++;
                count++;

                while (have[index] > need[index]) {
                    unsigned long leftHash = 5381;

                    for (int j = 0; j < wordLen; j++) {
                        leftHash = ((leftHash << 5) + leftHash) + s[left + j];
                    }

                    int leftIndex = head[leftHash % tableSize];

                    while (strncmp(uniqueWords[leftIndex], s + left, wordLen) != 0) {
                        leftIndex = next[leftIndex];
                    }

                    have[leftIndex]--;
                    left += wordLen;
                    count--;
                }

                if (count == wordsSize) {
                    result[*returnSize] = left;
                    (*returnSize)++;
                }
            }
        }
    }

    free(head);
    free(next);
    free(need);
    free(have);
    free(uniqueWords);

    return result;   
}