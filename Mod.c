
typedef long long ll;

ll mod(ll a, ll b, ll m) {
    a%=m;
    return !b?1:(((b&1)?a:1)*mod(a*a,b>>1,m)%m)%m;;
}