int divide(int dividend, int divisor) {
if (dividend == (-2147483647 - 1) && divisor == -1) {
        return 2147483647;
    }

    long long a = dividend;
    long long b = divisor;
    long long quotient = 0;
    int negative = (a < 0) != (b < 0);

    if (a < 0) {
        a = -a;
    }

    if (b < 0) {
        b = -b;
    }

    for (int i = 31; i >= 0; i--) {
        if (a >= (b << i)) {
            a -= (b << i);
            quotient += (1LL << i);
        }
    }

    return negative ? -quotient : quotient;    
}