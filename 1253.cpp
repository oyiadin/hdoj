#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define BFS(_1, _2, _3) \
    if (!V[_1][_2][_3] && M[_1][_2][_3]) { \
        V[_1][_2][_3] = true; \
        p.x = _1; \
        p.y = _2; \
        p.z = _3; \
        p.t = pos.t+1; \
        q.push(p); \
    }

#define IN(x, range) ((x) > 0 && (x) < range)

bool M[52][52][52];
bool V[52][52][52];

int a, b, c, t;

struct Pos {
  int x, y, z;
  int t;
};


int bfs(int x, int y, int z) {
  queue<Pos> q;
  Pos p = {x, y, z, 0};
  q.push(p);
  cout << q.size() << endl;
  V[x][y][z] = true;

  while (!q.empty()) {
    Pos pos = q.front();
    q.pop();

    if (pos.t > t)
      return -1;

    if (!(IN(pos.x, a) && IN(pos.y, b) && IN(pos.z, c)))
      continue;

    if (pos.x == a && pos.y == b && pos.z == c)
      return pos.t;

    BFS(pos.x+1, pos.y, pos.z);
    BFS(pos.x-1, pos.y, pos.z);
    BFS(pos.x, pos.y+1, pos.z);
    BFS(pos.x, pos.y-1, pos.z);
    BFS(pos.x, pos.y, pos.z+1);
    BFS(pos.x, pos.y, pos.z-1);
  }

  return 23333;
}


int main() {
  int k; scanf("%d", &k);

  while (k--) {
    scanf("%d%d%d%d", &a, &b, &c, &t);

    memset(M, 0, sizeof(M));  // 默认堵住，可以堵边缘
    // 0 为堵住，与题意相反
    memset(V, 0, sizeof(V));

    for (int i = 1; i <= a; ++i) {
      for (int j = 1; j <= b; ++j) {
        for (int k = 1; k <= c; ++k) {
          int t; scanf("%d", &t);
          M[i][j][k] = !t;
        }
      }
    }
    // data input ends

    cout << bfs(1, 1, 1) << endl;
  }
}
