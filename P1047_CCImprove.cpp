#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int l, m;
    cin >> l >> m;
    
    if (m == 0) {
        cout << l + 1 << endl;
        return 0;
    }
    
    vector<pair<int, int>> intervals(m);
    for (int i = 0; i < m; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }
    
    // Sort by left endpoint only
    sort(intervals.begin(), intervals.end());
    
    // Merge overlapping intervals in-place
    int merged_count = 0;
    for (int i = 0; i < m; i++) {
        if (merged_count == 0 || intervals[i].first > intervals[merged_count-1].second) {
            intervals[merged_count++] = intervals[i];
        } else {
            intervals[merged_count-1].second = max(intervals[merged_count-1].second, intervals[i].second);
        }
    }
    
    // Calculate remaining trees
    int removed = 0;
    for (int i = 0; i < merged_count; i++) {
        removed += intervals[i].second - intervals[i].first + 1;
    }
    
    cout << l + 1 - removed << endl;
    return 0;
}