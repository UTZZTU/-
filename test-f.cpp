#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool hasIntersection(const vector<pair<int, int>>& segments) {
    vector<pair<int, pair<int, int>>> events; // 存储事件，包括坐标、线段编号和事件类型（起始点或终点）

    // 将起始点和终点拆分成两个事件，并加入events
    for (int i = 0; i < segments.size(); ++i) {
        events.push_back({segments[i].first, {i, 0}});  // 起始点事件
        events.push_back({segments[i].second, {i, 1}}); // 终点事件
    }

    // 按横坐标排序所有事件
    sort(events.begin(), events.end());

    int count = 0; // 计数器，用于跟踪当前扫描线上的线段数量

    for (const auto& event : events) {
        if (event.second.second == 0) { // 起始点事件
            count++;
            if (count == 2) {
                return true; // 有两条线段相交
            }
        } else { // 终点事件
            count--;
        }
    }

    return false; // 没有两条线段相交
}

int main() {
    vector<pair<int, int>> segments = {{1, 4}, {2, 3}};

    if (hasIntersection(segments)) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }

    return 0;
}
