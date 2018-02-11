#include<cstdio >
#include<cstring >
#include<string>
#define maxn 105

bool less(const char* s, int p, int q) {
  std::string a,b;
  for (int i=0;i<strlen(s);i++){
    a+=s[(p+i)%strlen(s)];
    b+=s[(q+i)%strlen(s)];
  }
  return a<b;
  
}

int main() {
  int T;
  char s[maxn];
  scanf("%d", &T);
  while(T--) {
    scanf("%s", s);
    int ans = 0;
    int n = strlen(s);
    for(int i = 1; i < n; i++)
      if(less(s, i, ans)) ans = i;
    for(int i = 0; i < n; i++)
      putchar(s[(i+ans)%n]);
    putchar('\n');
  }
  return 0;
}

