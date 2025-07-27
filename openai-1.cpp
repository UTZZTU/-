#include <iostream>
#include <vector>

// 字典树节点的定义
struct TrieNode {
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

// 将数字插入字典树
void insertNumber(TrieNode* root, int num) {
    TrieNode* curr = root;
    for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        if (curr->children[bit] == nullptr)
            curr->children[bit] = new TrieNode();
        curr = curr->children[bit];
    }
}

// 在字典树中统计满足要求的数的个数
int countNumbers(TrieNode* root, int num, int maxXor) {
    TrieNode* curr = root;
    int count = 0;
    for (int i = 31; i >= 0; --i) {
        int bit = (num >> i) & 1;
        int maxXorBit = (maxXor >> i) & 1;
        if (maxXorBit == 1) {
            // 在当前位上，如果 maxXor 的对应位是 1，则应选择与 num 不同的位（异或结果为 1）。
            if (curr->children[1 - bit] != nullptr) {
                curr = curr->children[1 - bit];
                count += (1 << i);
            } else {
                curr = curr->children[bit];
            }
        } else {
            // 在当前位上，如果 maxXor 的对应位是 0，则可以随意选择与 num 相同的位或不同的位。
            if (curr->children[bit] != nullptr) {
                curr = curr->children[bit];
                count += (1 << i);
            } else {
                curr = curr->children[1 - bit];
            }
        }
    }
    return count;
}

int main() {
    int n, maxXor;
    std::cin >> n >> maxXor;

    TrieNode* root = new TrieNode();

    int result = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        insertNumber(root, num);
        result += countNumbers(root, num, maxXor);
    }

    std::cout << result << std::endl;

    return 0;
}
