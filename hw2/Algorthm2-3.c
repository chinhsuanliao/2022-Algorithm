#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long LL;

const int N = 300010, M = N*2;

struct Node
{
    int x, y, rank_y;
    int id;
}a[M];

int n, tr[M], ans[M];
int tot[M];

bool cmp(Node A, Node B)
{
    if(A.x == B.x) return A.y<B.y;
    return A.x < B.x;
}

void solve()
{
    for(int i = 1; i <= n; i++)
    {
        int y = a[i].y;
        a[i].rank_y = upper_bound(tot+1, tot+n+1, y)-tot-1;
        //cout << "**" << y << ' ' << a[i].rank_y << '\n';
    }
}

int lowbit(int x)
{
    return x & -x;
}

void add(int t, int c)
{
    for(int i = t; i <= N; i += lowbit(i)) tr[i] += c;
    return ;
}

int que(int t)
{
    int res = 0;
    for(int i = t; i; i -= lowbit(i)) res += tr[i];
    return res;
 }

int main()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].id = i;
        tot[i] = a[i].y;
    }

    sort(tot+1, tot+n+1);
    solve();

    sort(a+1, a+n+1, cmp);
    for(int i = 1; i <= n; i++)
    {
        int y = a[i].rank_y;
        int id = a[i].id;

        ans[id] = que(y);
        add(y, 1);
    }

    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);

    return 0;
}
