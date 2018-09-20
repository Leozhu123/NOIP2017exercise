#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <string>

#if __cplusplus >= 201103L
#define reg
#else
#define reg register
#endif
#define FOK (ch != EOF)
#define SEP (ch == ' ' || ch == '\n' || ch == '\t')
#define DSEP (!isdigit(ch))
#define NEQ(a, b) ((a) - (b) > 1e-6)

class FastIO {
    char rbuf[1000002], wbuf[1000002], b, *p1, *p2;
    int rs, ws, S;
    public:
        FastIO() : b(1), p1(rbuf), p2(wbuf), rs(1000000), ws(-1), S(1000000) {}
        ~FastIO() { fwrite(wbuf, 1, ws + 1, stdout); }
#if __cplusplus >= 201103L
        FastIO(const FastIO&) = delete;
        FastIO& operator=(const FastIO&) = delete;
#else
    private:
        FastIO(const FastIO&);
        FastIO& operator=(const FastIO&);
    public:
#endif
        char getch() {
            return rs == S &&
            (p1 = rbuf, rs = -1, (S = fread(rbuf, 1, S + 1, stdin) - 1) == -1) ?
            (b = 0, EOF) : (++rs, *p1++);
        }
        void putch(int x) {
            ws == 1000000 &&
            (p2 = wbuf, ws = -1, fwrite(wbuf, 1, 1000001, stdout)), ++ws, *p2++ = x;
        }
        void puts(const char str[]) {
            fwrite(wbuf, 1, ws + 1, stdout) ? (ws = -1) : 0,
            fwrite(str, 1, strlen(str), stdout);
        }
        void getline(std::string& s) {
            for(reg char ch; (ch = getch()) != '\n' && FOK;) s += ch;
        }
        FastIO& operator>>(int& x) {
            x = 0;reg char f = 0, ch = getch();
            while (DSEP && FOK) f |= (ch == '-'), ch = getch();
            while (isdigit(ch))
                x = (x << 1) + (x << 3) + (ch ^ 48), ch = getch();
            return x = f ? -x : x, *this;
        }
        FastIO& operator>>(long long& x) {
            x = 0; reg char f = 0, ch = getch();
            while (DSEP && FOK) f |= (ch == '-'), ch = getch();
            while (isdigit(ch))
                x = (x << 1) + (x << 3) + (ch ^ 48), ch = getch();
            return x = f ? -x : x, *this;
        }
        FastIO& operator>>(char& ch) { return ch = getch(), *this; }
        FastIO& operator>>(std::string& s) {
            reg char ch = getch();
            while (SEP && FOK) ch = getch();
            while (!SEP && FOK) s += ch, ch = getch();
            return *this;
        }
        FastIO& operator>>(double& x) {
            x = 0; reg char f = 0, ch = getch();
            double d = 0.1;
            while (DSEP && FOK) f |= (ch == '-'), ch = getch();
            while (isdigit(ch)) x = x * 10 + (ch ^ 48), ch = getch();
            if (ch == '.')
                while (isdigit(ch = getch())) x += d * (ch ^ 48), d *= 0.1;
            return x = f ? -x : x, *this;
        }
        FastIO& operator<<(int x) {
            reg char ch[10]; int i = -1;
            !x ? (putch('0'), 0) : 0,
            x < 0 ? (putch('-'), x = -x) : 0;
            while (x) ch[++i] = x % 10 + 48, x /= 10;
            while (~i) putch(ch[i]), --i;
            return *this;
        }
        FastIO& operator<<(long long x) {
            reg char ch[20]; int i = -1;
            !x ? (putch('0'), 0) : 0,
            x < 0 ? (putch('-'), x = -x) : 0;
            while (x) ch[++i] = x % 10 + 48, x /= 10;
            while (~i) putch(ch[i]), --i;
            return *this;
        }
        FastIO& operator<<(char ch) { return putch(ch), *this; }
        FastIO& operator<<(const char* str) { return puts(str), *this; }
        FastIO& operator<<(const std::string& s) { return puts(s.c_str()), *this; }
        FastIO& operator<<(double x) {
            int y = int(x);
            *this << y;
            x -= y;
            while (NEQ(x, int(x))) x *= 10;
            if (x) *this << '.' << int(x);
            return *this;
        }
#if __cplusplus >= 201103L
        explicit
#endif
        operator bool() const { return b; }
};

FastIO io;

using namespace std;
const int maxn = 2 * 1e6 + 10;
int where[maxn];
struct Qurry{
    int l,r,id,pre;
    Qurry(){
        l = r = id = pre = 0;
    }
    bool operator< (const Qurry &r)const{
        if(l!=r.l){
            return where[l] < where[r.l];
        }
        if(this->r!=r.r){
            return where[this->r] < where[r.r];
        }
        return pre < r.pre;
    }
};
struct Change{
    int pos,val;
    Change(){
        pos = val = 0;
    }
};
Qurry Q[maxn];
Change C[maxn];
int color[maxn];
int a[maxn];
int out[maxn];
int n=0,m=0;
int ans=0;
void add(int val){
    if(++color[val]==1)
        ans++;
}
void del(int val){
    if(--color[val]==0)
        ans--;
}
void work(int now,int i){
    if(C[now].pos>=Q[i].l && C[now].pos<=Q[i].r){
        if(--color[a[C[now].pos]]==0) ans--;
        if(++color[C[now].val]==1)
            ans++;
    }
    swap(C[now].val, a[C[now].pos]);
}
int Qnum=0, Cnum=0;
void moQueue(){
    int l = 1, r = 0, now = 0;
    for (int i = 1;i<=Qnum;i++){
        while(l<Q[i].l) 
            del(a[l++]);
        while(l>Q[i].l)
            add(a[--l]);
        while(r<Q[i].r)
            add(a[++r]);
        while(r>Q[i].r)
            del(a[r--]);
        while(now<Q[i].pre)
            work(++now, i);
        while(now>Q[i].pre)
            work(now--, i);
        out[Q[i].id] = ans;
    }
    for(int i=1;i<=Qnum;i++){
        printf("%d\n",out[i]);
    }
}
int main()
{
    io >> n >> m;
    int base=sqrt(n);
    for(int i=1;i<=n;i++){
        io >> a[i];
        where[i] = (i - 1) / base + 1;
    }
    while(m--){
        char opt;
        io >> opt;
        if(opt=='Q'){
            Qnum++;
            io>>Q[Qnum].l>>Q[Qnum].r;
            Q[Qnum].pre=Cnum;
            Q[Qnum].id=Qnum; 
        }else{
            ++Cnum;
            io>>C[Cnum].pos>>C[Cnum].val;
        }
    }
    sort(Q + 1, Q + Qnum + 1);
    moQueue();
    return 0;
}