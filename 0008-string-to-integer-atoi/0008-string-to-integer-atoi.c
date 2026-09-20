int myAtoi(char* s) {
 int i = 0, sign = 1, result = 0;

    
    while (s[i] == ' ') {
        i++;
    }

   
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    
   while (s[i] >= '0' && s[i] <= '9') {
    int digit = s[i] - '0';

    if (sign == 1) {
        if (result > 214748364 ||
            (result == 214748364 && digit > 7)) {
            return 2147483647;
        }
        result = result * 10 + digit;
    } else {
        if (result < -214748364 ||
            (result == -214748364 && digit > 8)) {
            return -2147483648;
        }
        result = result * 10 - digit;
    }

    i++;
}
    return result;
}