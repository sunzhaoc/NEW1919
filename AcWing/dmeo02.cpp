/*
 * @Description: 
 * @Version: 1.0
 * @Author: 冰凝水
 * @Date: 2021-06-07 14:10:15
 * @LastEditTime: 2021-06-17 21:39:33
 * @FilePath: \Leetcode\AcWing\dmeo02.cpp
 */

# include<bits/stdc++.h>
using namespace std;

const int N = 500000;

int n, m;
vector<int> head_node, node_weight, end_node, next_node, dist, st;
int idx = 0;
bool st[N]; 

void add(int a, int b, int c) {
    end_node[idx] = b, node_weight[idx] = c, next_node[idx] = head_node[a], head_node[a] = idx ++;
}

int dijstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({node_weight[1], 1});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;

        for (int i = head_node[ver]; i != -1; i = next_node[i]) {
            int j = end_node[i];
            if (dist[j] > distance + node_weight[i]) {
                dist[j] = distance + node_weight[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == INT_MAX) return -1;
    return dist[n];
}

int main() {
    vector<int> weight;
    weight.push_back(-1);
    
    string s;
    cin >> s;
    int l = 0, r = 0;
    while (r < s.size()) {
        if (r + 1 == s.size() || s[r + 1] == ',') {
            int num = 0;
            for (int i = l; i <= r; i ++) num = num * 10 + (s[i] - '0');
            l = r + 2;
            r = l;
            weight.push_back(num);
        }
        else r += 1;
    }

    n = weight.size() - 1;

    head_node.resize(n + 1, -1);
    dist.resize(n + 1, INT_MAX);
    dist[1] = weight[1];
    node_weight.resize(n + 1);
    end_node.resize(n + 1);
    next_node.resize(n + 1);
    st.resize(n + 1);
    
    cin >> s;
    int id = 1;
    l = 0, r = 0;
    while (r < s.size()) {
        if (r + 1 == s.size() || s[r + 1] == ';' || s[r + 1] == ',') {
            int num = 0;
            for (int i = l; i <= r; i ++) num = num * 10 + (s[i] - '0');
            if (s[r + 1] == ';') id ++;
            l = r + 2;
            r = l;
            if (num != 0) add(id, num, weight[num]);
        }
        else r += 1;
    }


    int id = 1;
    while (n --) {
        int endNode;
        cin >> endNode;
        add(id, endNode, weight[endNode]);
    }

    int t = dijstra();
    printf("%d\n", t);
    
    return 0;
}