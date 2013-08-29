#line 5 "Escape.cpp"


#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <strstream>
using namespace std;
 
struct node
{
  node(int _x, int _y) {x = _x; y = _y;}
 
  int id() const
  {
    return y*501+x;
  }
  
  int x, y;
};
 
map <int, int> dist;
 
bool operator<(const node &n1, const node &n2)
{
  if (dist[n1.id()] != dist[n2.id()])
    return dist[n1.id()] < dist[n2.id()];
  return n1.id() < n2.id();
}
 
 
class Escape
{
public:
 
int grid[501][501];
 
void clear(int x1, int y1, int x2, int y2, int val)
{
  int tx;
  if (x2 < x1)
  {
    tx = x1;
    x1 = x2;
    x2 = tx;
  }
  if (y2 < y1)
  {
    tx = y1;
    y1 = y2;
    y2 = tx;
  }
  for (int y = y1; y <= y2; y++)
  for (int x = x1; x <= x2; x++)
  {
    grid[y][x] = val;
  }
}
 
void bfs(int srcx, int srcy)
{
  node src(srcx, srcy);
  set <node> totry;
  dist.clear();
  dist[src.id()] = 0;
  totry.insert(src);
 
  int x = 0;
  while (totry.size())
  {
    srcx = totry.begin()->x;
    srcy = totry.begin()->y;
    src = node(srcx, srcy);
/*    cout 
    x++;*/
 
    for (int dstx = srcx-1; dstx <= srcx+1; dstx++)
    for (int dsty = srcy-1; dsty <= srcy+1; dsty++)
    if (dstx >= 0 && dsty >= 0 && dstx <= 500 && dsty <= 500)
    if ( (dstx-srcx)*(dstx-srcx) + (dsty-srcy)*(dsty-srcy) == 1)
    {
      node dest(dstx, dsty);
      int length = grid[dsty][dstx];
      if (length < 2)
      if (!dist.count(dest.id()) || dist[dest.id()] > dist[src.id()] + length)
      {
        dist[dest.id()] = dist[src.id()] + length;
        totry.insert(dest);
      }
    }
    totry.erase(src);
  }
}
 
int lowest(vector<string> harmful, vector<string> deadly)
{
  int i;
 
  clear(0,0,500,500, 0);
  for (i = 0; i < harmful.size(); i++)
  {
    istrstream in(harmful[i].c_str());
    int x1, y1, x2, y2;
    in >> x1 >> y1 >> x2 >> y2;
    clear(x1, y1, x2, y2, 1);
  }
  for (i = 0; i < deadly.size(); i++)
  {
    istrstream in(deadly[i].c_str());
    int x1, y1, x2, y2;
    in >> x1 >> y1 >> x2 >> y2;
    clear(x1, y1, x2, y2, 2);
  }
 
  bfs(0, 0);
 
  
  node end = node(500,500);
  if (!dist.count(end.id()))
    return -1;
  else
    return dist[end.id()];
}
 
};
