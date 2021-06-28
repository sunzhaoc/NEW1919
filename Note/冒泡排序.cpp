/*
Description: 冒泡排序
*/

# include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, q[N];

void bubble_sort(int q[]) {
    for (int i = 0; i < n - 1; i ++) { // 走n-1趟
        for (int j = 0; j < n - i - 1; j ++) { // 比较n - i - 1次
            if (q[j] > q[j + 1]) swap(q[i], q[j]);
        }
    }
}

int main() {
    scanf("&d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    bubble_sort(q);
    for (int i = 0; i < n; i ++) printf("%d", q[i]);
    return 0;
}


/*
Description: 冒泡排序，优化。
*/

# include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, q[N];

void bubble_sort(int q[]) {
    for (int i = 0; i < n - 1; i ++) { // 走n-1趟
        bool flag = false;
        for (int j = 0; j < n - i - 1; j ++) { // 比较n - i - 1次
            if (q[j] > q[j + 1]) {
                swap(q[i], q[j]);
                flag = true;
            }
        }
        if (flag == false) return;
    }
}

int main() {
    scanf("&d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    bubble_sort(q);
    for (int i = 0; i < n; i ++) printf("%d", q[i]);
    return 0;
}





# include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, q[N];

void bubble_sort(int q[]) {
    for (int i = 0; i < n - 1; i ++) { // 走n-1趟
        bool flag = false;
        for (int j = 0; j < n - i - 1; j ++) { // 比较n - i - 1次
            if (q[j] > q[j + 1]) {
                swap(q[i], q[j]);
                flag = true;
            }
        }
        if (flag == false) return;
    }
}

int main() {
    scanf("&d", &n);
    for (int i = 0; i < n; i ++) scanf("%d", &q[i]);
    bubble_sort(q);
    for (int i = 0; i < n; i ++) printf("%d", q[i]);
    return 0;
}