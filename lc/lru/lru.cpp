#include <bits/stdc++.h>

using namespace std;

class LRUCache {
private:
  struct LRUNode {
    int next;
    int prev;
    int val;
  };

  int cap;
  int len = 0;
  unordered_map<int, LRUNode> map;
  int head;
  int tail;

  void bump(int key) {
    LRUNode &now = map[key];
    LRUNode &h = map[head];
    if(now.prev != -1) {

    }
  }

public:
  LRUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    if (map.find(key) == map.end()) {
      return -1;
    }
    bump(key);
  }

  void put(int key, int value) {}
};
