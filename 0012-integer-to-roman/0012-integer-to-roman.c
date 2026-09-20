char* intToRoman(int num) {
int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {
        "M", "CM", "D", "CD", "C", "XC", "L",
        "XL", "X", "IX", "V", "IV", "I"
    };

    char* result = malloc(16);
    int pos = 0;

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            char* symbol = symbols[i];

            while (*symbol != '\0') {
                result[pos++] = *symbol++;
            }

            num -= values[i];
        }
    }

    result[pos] = '\0';
    return result;  
}