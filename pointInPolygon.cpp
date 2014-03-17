#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

#define FOR(i,a,n) for(int i=a;i!=n;i++)

using namespace std;

#define INF 1000

typedef struct point{
	int x;
	int y;
}point;


int orientation(point, point, point);
bool onSegment(point, point, point);
bool doIntersect(point, point, point, point);
bool pointInPolygon(point *, point, int);


int orientation(point p, point q, point r){
	int val = (q.y - p.y)*(r.x - q.x) - (r.y - q.y)*(q.x - p.x);

	if(val == 0) return 0;

	return (val > 0 ? 1:2);
}

bool onSegment(point p, point q, point r){
	return (r.x >= min(p.x, q.x) && r.x <= max(p.x, q.x) && r.y >= min(p.y, q.y) && r.y <= max(p.y, q.y));
}

bool doIntersect(point p1, point q1, point p2, point q2){
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

	if(o1 != o2 && o3 != o4) return true;

	if(o1 == 0 && onSegment(p1, q1, p2)) return true;
	if(o2 == 0 && onSegment(p1, q1, q2)) return true;
	if(o3 == 0 && onSegment(p2, q2, p1)) return true;
	if(o4 == 0 && onSegment(p2, q2, q1)) return true;

	return false;
}

// find if a point is in the given polygon
bool pointInPolygon(point *P, point Inp, int N){
	point extL = {-INF, Inp.y};
	point extR = {INF, Inp.y};
	
	int i = 0;
	int count1 = 0;
	do{
		int j = (i+1)%N;
		if(doIntersect(P[i], P[j], extL, Inp)) count1++;
		i = j;
	}while(i!=0);
	
	int count2 = 0;
	do{
		int j = (i+1)%N;
		if(doIntersect(P[i], P[j], Inp, extR)) count2++;
		if(onSegment(P[i], P[j], Inp)) return true;
		i = j;
	}while(i!=0);

	if(count1%2 == 1 && count2%2 == 1) return true;

	return false;
}

int main(){
	point polygon3[] =  {{0, 0}, {10, 0}, {10, 10}, {0, 10}};
	point p = {5,0};
	cout << (pointInPolygon(polygon3, p, 4) ? "true":"false") << endl;
	
	return 0;
}
