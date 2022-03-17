#include<stdio.h>

int a[1000010],b[1000010];
int mod = 524287;

long long ans=0;

void merge(int l,int mid,int r)
{
    int p1 = l, p2 = mid + 1;
    for(int i=l; i<=r; i++){
        if((p1 <= mid) && ( p2>r || a[p1] <= a[p2]))
            b[i] = a[p1++];
        else {
            ans += mid-p1+1;
            b[i] = a[p2++];
        }
    }
    for(int i=l; i<=r; i++) a[i]=b[i];
}
void solve(int l,int r)
{
    int mid = (l + r)>>1;
    if(l < r)
    {
        solve(l , mid);
        solve(mid+1 , r);
    }
    merge(l, mid, r);
}
int main()
{
    int n; scanf("%d", &n);

    for(int i=0;i<n;i++) scanf("%d", &a[i]);

    solve(0,n-1);

    printf("%lld", ans%524287);
    return 0;
}
