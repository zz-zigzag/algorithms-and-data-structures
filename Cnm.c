//C(m,n)=C(m,m-n)
//C(m,n)=C(m-1,n)+C(m-1,n-1)
long long Cnm(int n,int m) {
    if(m > n / 2) {
        m = n - m;
    }
    long long s = 1;
    for(int i = 0; i < m; ++i) {
        s *= n - i;
        s /= i + 1;
    }
    return s;
}