#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef pair<int, int>     ii;
typedef vector<ii>         vii;
typedef set<int>           si;
typedef map<string, int>   msi;

#define MAX 4000000

int p[MAX], num_sets;
void initSet(int n) {
  for (int i = 0; i < n ; i++) p[i] = i;
  num_sets = n;
}
int findSet(int i) {
  return p[i] == i?i:p[i] = findSet(p[i]);
}
bool isSameSet(int i, int j) {
  return findSet(i) == findSet(j);
}
void unionSet(int i, int j) {
  if(!isSameSet(i, j)) num_sets--;
  p[findSet(i)] = findSet(j);
}

int main() {
  int n;

  while(scanf("%d", &n) != EOF) {
    int R = 2*n, C = 2*n+1;
    initSet(R*C);

    string s;
    for(int i=0; i<R-1; i++) {
      cin >> s;

      if(i % 2 == 0) {
	for(int j=0; j<C-1; j+=2) {
	  int a = j + i * C;
	  int b = a + 1;
	  int c = a + C;
	  int d = b + C;

	  if(s[j/2] == 'H') {
	    unionSet(a, b);
	    unionSet(c, d);
	  } else if(s[j/2] == 'V') {
	    unionSet(a, c);
	    unionSet(b, d);
	  }
	}
      } else {
	for(int j=0; j<C; j+=2) {
	  int a = j + i * C + 1;
	  int b = a + 1;
	  int c = a + C;
	  int d = b + C;

	  if(s[j/2] == 'H') {
	    unionSet(a, b);
	    unionSet(c, d);
	  } else if(s[j/2] == 'V') {
	    unionSet(a, c);
	    unionSet(b, d);
	  }
	}
      }
    }

    for(int i=1; i<C; i+=2) {
      unionSet(i, i+1);
      unionSet(i+(C*(R-1)), i+(C*(R-1))+1);
    }

    for(int i=0; i<R; i++) {
      if(i%2 == 0) {
	if(i*C+C-1 < R*C && (i+1)*C+C-1 < R*C) {
	  unionSet(i*C+C-1, (i+1)*C+C-1);
	}
      } else {
	if(i*C < R*C && (i+1)*C < R*C) {
	  unionSet(i*C, (i+1)*C);
	}
      }
    }

    printf("%d\n", num_sets-1);
  }
  
  return 0;
}
