// Language: cpp
// Path: Tree/van-emde-boas-tree.cpp
// Implementation of van Emde Boas tree.
// Time complexity: O(log^2 n)

#include <bits/stdc++.h>
using namespace std;

class VEB {
    int u;
    int min, max;
    VEB *summary;
    vector<VEB *> cluster;

   public:
    VEB(int u) {
        this->u = u;
        min = max = -1;
        if (u > 2) {
            summary = new VEB(sqrt(u));
            for (int i = 0; i < sqrt(u); i++)
                cluster.push_back(new VEB(sqrt(u)));
        }
    }
    int high(int x) {
        return x / sqrt(u);
    }
    int low(int x) {
        return x % (int)sqrt(u);
    }
    int index(int x, int y) {
        return x * sqrt(u) + y;
    }
    void insert(int x) {
        if (min == -1) {
            min = max = x;
            return;
        }
        if (x < min) swap(x, min);
        if (u > 2) {
            if (cluster[high(x)]->min == -1) {
                summary->insert(high(x));
                cluster[high(x)]->min = cluster[high(x)]->max = low(x);
            } else {
                cluster[high(x)]->insert(low(x));
            }
        }
        if (x > max) max = x;
    }
    void erase(int x) {
        if (min == max) {
            min = max = -1;
            return;
        }
        if (u == 2) {
            if (x == 0)
                min = 1;
            else
                min = 0;
            max = min;
            return;
        }
        if (x == min) {
            int first_cluster = summary->min;
            x = index(first_cluster, cluster[first_cluster]->min);
            min = x;
        }
        cluster[high(x)]->erase(low(x));
        if (cluster[high(x)]->min == -1) {
            summary->erase(high(x));
            if (x == max) {
                int summary_max = summary->max;
                if (summary_max == -1)
                    max = min;
                else
                    max = index(summary_max, cluster[summary_max]->max);
            }
        } else if (x == max) {
            max = index(high(x), cluster[high(x)]->max);
        }
    }
    int predecessor(int x) {
        if (u == 2) {
            if (x == 1 && min == 0)
                return 0;
            else
                return -1;
        }
        if (min != -1 && x > min) return min;
        int max_low = cluster[high(x)]->max;
        if (max_low != -1 && low(x) > max_low) {
            int pred_cluster = summary->predecessor(high(x));
            if (pred_cluster == -1)
                return -1;
            else
                return index(pred_cluster, cluster[pred_cluster]->max);
        } else {
            int offset = cluster[high(x)]->predecessor(low(x));
            if (offset == -1)
                return -1;
            else
                return index(high(x), offset);
        }
    }
    int successor(int x) {
        if (u == 2) {
            if (x == 0 && max == 1)
                return 1;
            else
                return -1;
        }
        if (max != -1 && x < max) return max;
        int min_low = cluster[high(x)]->min;
        if (min_low != -1 && low(x) < min_low) {
            int succ_cluster = summary->successor(high(x));
            if (succ_cluster == -1)
                return -1;
            else
                return index(succ_cluster, cluster[succ_cluster]->min);
        } else {
            int offset = cluster[high(x)]->successor(low(x));
            if (offset == -1)
                return -1;
            else
                return index(high(x), offset);
        }
    }
};

// Usage example
int main() {
    VEB veb(16);
    veb.insert(2);
    veb.insert(3);
    veb.insert(7);
    veb.insert(14);
    veb.insert(15);
    cout << veb.predecessor(4) << endl;
    cout << veb.successor(4) << endl;
    veb.erase(3);
    cout << veb.predecessor(4) << endl;
    cout << veb.successor(4) << endl;
}
