int GCD(int a,int b) {
    return b > 0 ? GCD(b, a % b) : a;
}

int GCD(int a,int b) {
    while (b > 0) {
        a = a % b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
}

int GCD(int a,int b) {
    while(a) {
        a^= b^= a^= b %= a;
    }
    return b;
}