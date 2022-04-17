#include <algorithm>

using namespace std;
int a[500005];
// cnt[i] 表示海平面下降到i时，答案的变化量。
int cnt[10005] = {0};

int main() {
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    a[0] = a[n + 1] = 0;
    //边界默认为0
    //左闭右开区间
    //unique() in head file algorithm
    n = unique(a, a + n + 2) - a;                            //去掉相邻重复元素
    for (int i = 1; i < n - 1; i++)
        if (a[i - 1] < a[i] && a[i] > a[i + 1])                //大于左右则为凸峰，对答案贡献了1。因去重，不存在等于左右情况
            cnt[a[i]]++;
        else if (a[i - 1] > a[i] && a[i] < a[i + 1])
            cnt[a[i]]--;
    int ans = 0, sum = 0;
    for (int i = 10000; i > 0; i--) {
        sum += cnt[i];                                //差分的前缀和即为单点的答案
        ans = max(ans, sum);
    }
    printf("%d\n", ans);
}

