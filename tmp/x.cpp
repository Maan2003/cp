// Input format
// The first line contains the number of test cases t (1≤t≤100).
// Description of the test cases follows.
// The only line of each test case contains a single integer n
// (1≤n≤1000).
// It is guaranteed that the sum of n over all test cases does not exceed 104.
//
// Output format
// For each test case print n integers a1,a2,…,an — the array you found. If there are multiple arrays satisfying all the conditions, print any of them.
//
// Sample Input
// 3
// 1
// 2
// 7
//
// Sample Output
// 1
// 2 3
// 111 1111 11111 111111 1111111 11111111 111111111
// 
// write the main function that takes the input and prints the output

// assume a solve function already exists


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <utility>
#include <numeric>
#include <iterator>
#include <complex>
#include <functional>
    
using namespace std;
    
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,n) FOR(i,0,n)
#define FOREQ(i,a) FORE(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define WRITE(A) REP(__i,A.size()) cout << A[__i] << " "; cout << endl;
#define WRITE_ALL(A) REP(__i,A.size()) REP(__j,A[__i].size()) cout << A[__i][__j] << " "; cout << endl;
#define WRITEMAT(A) REP(__i,A.size()) { REP(__j,A[__i].size()) cout << A[__i][__j] << " "; cout << endl; }
#define WRITEMAT_ALL(A) REP(__i,A.size()) { REP(__j,A[__i].size()) cout << A[__i][__j] << " "; cout << endl; }
#define READ(A) REP(__i,A.size()) cin >> A[__i];
#define READ_ALL(A) REP(__i,A.size()) REP(__j,A[__i].size()) cin >> A[__i][__j];
#define READMAT(A) REP(__i,A.size()) REP(__j,A[__i].size()) cin >> A[__i][__j];
#define SQR(a) ((a)*(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define SGN(a) ((a)==0?0:(a)<0?-1:1)
#define GCD(a,b) __gcd(a,b)
#define LCM(a,b) ((a)*(b)/GCD(a,b))
#define INF (1<<30)
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INF (1<<30)
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define REP(i,n) FOR(i,0,n)
#define FOREQ(i,n) FORE(i,0,n)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

