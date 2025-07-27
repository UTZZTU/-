#include <bits/stdc++.h>
//#include <vector>

using namespace std;

class BucketSort {
public:
    void bucketSort(vector<int> &nums) {
        int n = nums.size();
        int mn = nums[0], mx = nums[0];
        for (int i = 1; i < n; i++) {
            mn = min(mn, nums[i]);
            mx = max(mx, nums[i]);
        }
        int size = (mx - mn) / n + 1;   // size 至少要为1
        int cnt = (mx - mn) / size + 1; // 桶的个数至少要为1
        vector<vector<int>> buckets(cnt);
        for (int i = 0; i < n; i++) {
            int idx = (nums[i] - mn) / size;
            buckets[idx].push_back(nums[i]);
        }
        for (int i = 0; i < cnt; i++) {
            sort(buckets[i].begin(), buckets[i].end());
        }
        int index = 0;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < buckets[i].size(); j++) {
                nums[index++] = buckets[i][j];
            }
        }
    }
};


int main() {
    vector<int> nums = {19, 27, 35, 43, 31, 22, 54, 66, 78};
    BucketSort().bucketSort(nums);
    for (auto num: nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

