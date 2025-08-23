#include <iostream>
#include <vector>

// 定义常量
// 使用 unsigned int 以正确处理到 2^31 - 1 的范围
const unsigned int MAX_N = 2147483647; 
const int INTERVAL = 1;

int main() {
    // 加速 cout
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);

    long long count = 0;
    
    // 打印数组头
    std::cout << "const long long lookup_table[] = {\n";

    // 预先处理第0个元素
    // x = 0, 条件满足, count = 1
    count = 1;
    std::cout << "    " << count << ", ";

    for (unsigned int x = 1; x <= MAX_N; ++x) {
        if ((x & (x << 1)) == 0) {
            count++;
        }

        // 每隔 INTERVAL，记录一次累计结果
        // 我们在 x = INTERVAL - 1, 2*INTERVAL - 1 ... 的位置记录
        // 这样 lookup_table[k] 对应的是 0 到 k*INTERVAL-1 的结果
        // 为了方便，我们直接在 x = k*INTERVAL 的时候记录，含义是 0~k*INTERVAL
        if (x % INTERVAL == 0) {
            std::cout << count << ", ";
            // 每10个结果换一行，方便阅读
            if ((x / INTERVAL) % 10 == 0) {
                std::cout << "\n    ";
            }
        }
        
        // 由于循环到2^31-1的最后一个数，在循环结束后不会触发取模打印
        // 所以，我们需要确保最后一个区间的值被记录
        // 或者，让主查询程序自己处理最后一个不完整的区间，这样更简单
    }

    // 打印数组尾
    std::cout << "\n};\n";

    return 0;
}
