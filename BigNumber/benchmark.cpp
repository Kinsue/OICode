// 完全兼容 C++11/14/17 的 IO 性能测试程序
// 单文件版本，便于编译测试

#include <iostream>
#include <fstream>
#include <cstdio>
#include <chrono>
#include <random>
#include <climits>
#include <vector>
#include <functional>
#include <iomanip>
#include <algorithm>
#include <cstring>

// ==================== 全局变量用于验证 ====================
long long g_sum = 0;
int g_count = 0;

// ==================== 1. 数据生成器 ====================
void generateTestData(const std::string& filename, int count) {
    std::cout << "生成测试数据: " << count << " 个整数..." << std::endl;
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "错误: 无法创建文件 " << filename << std::endl;
        return;
    }
    
    // 使用固定种子以确保可重复性
    std::mt19937_64 rng(12345);
    
    // 不同范围的分布
    std::uniform_int_distribution<long long> small_dist(1, 1000);
    std::uniform_int_distribution<long long> medium_dist(1000, 1000000);
    std::uniform_int_distribution<long long> large_dist(1000000, 999999999999LL);
    std::uniform_int_distribution<long long> negative_dist(-999999999, -1);
    std::uniform_int_distribution<int> type_selector(0, 3);
    
    for (int i = 0; i < count; ++i) {
        long long num;
        switch(type_selector(rng)) {
            case 0: num = small_dist(rng); break;
            case 1: num = medium_dist(rng); break;
            case 2: num = large_dist(rng); break;
            case 3: num = negative_dist(rng); break;
            default: num = medium_dist(rng); break;
        }
        out << num << '\n';
        
        // 进度提示
        if ((i + 1) % 1000000 == 0) {
            std::cout << "  已生成 " << (i + 1) / 1000000 << "M 个数据..." << std::endl;
        }
    }
    
    out.close();
    std::cout << "数据生成完成！" << std::endl;
}

// ==================== 2. 各种输入方法 ====================

// 方法1: 标准 cin（使用文件流）
void method1_cin(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return;
    
    g_sum = 0;
    g_count = 0;
    long long num;
    
    while (file >> num) {
        g_sum += num;
        g_count++;
    }
    file.close();
}

// 方法2: 关闭同步的 cin
void method2_cin_nosync(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return;
    
    std::ios::sync_with_stdio(false);
    
    g_sum = 0;
    g_count = 0;
    long long num;
    
    while (file >> num) {
        g_sum += num;
        g_count++;
    }
    
    file.close();
    std::ios::sync_with_stdio(true);  // 恢复
}

// 方法3: 关闭同步且解绑的 cin
void method3_cin_optimized(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) return;
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    g_sum = 0;
    g_count = 0;
    long long num;
    
    while (file >> num) {
        g_sum += num;
        g_count++;
    }
    
    file.close();
    std::ios::sync_with_stdio(true);
    std::cin.tie(&std::cout);  // 恢复
}

// 方法4: fscanf（不用 freopen 避免问题）
void method4_scanf(const std::string& filename) {
    FILE* fp = fopen(filename.c_str(), "r");
    if (!fp) return;
    
    g_sum = 0;
    g_count = 0;
    long long num;
    
    while (fscanf(fp, "%lld", &num) == 1) {
        g_sum += num;
        g_count++;
    }
    
    fclose(fp);
}

// 方法5: 基于 fgetc 的快速读入
void method5_fast_fgetc(const std::string& filename) {
    FILE* fp = fopen(filename.c_str(), "r");
    if (!fp) return;
    
    g_sum = 0;
    g_count = 0;
    
    auto fastRead = [&]() -> long long {
        long long x = 0;
        bool neg = false;
        int ch = fgetc(fp);
        
        // 跳过空白
        while (ch != EOF && ch != '-' && (ch < '0' || ch > '9')) {
            ch = fgetc(fp);
        }
        
        if (ch == EOF) return LLONG_MIN;
        
        if (ch == '-') {
            neg = true;
            ch = fgetc(fp);
        }
        
        // 读取数字
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch - '0');
            ch = fgetc(fp);
        }
        
        return neg ? -x : x;
    };
    
    long long num;
    while ((num = fastRead()) != LLONG_MIN) {
        g_sum += num;
        g_count++;
    }
    
    fclose(fp);
}

// 方法6: 缓冲快速读入
void method6_buffered(const std::string& filename) {
    FILE* fp = fopen(filename.c_str(), "r");
    if (!fp) return;
    
    const int BUFFER_SIZE = 1 << 20;  // 1MB
    char* buffer = new char[BUFFER_SIZE];
    
    g_sum = 0;
    g_count = 0;
    
    size_t pos = 0;
    size_t len = 0;
    
    auto nextChar = [&]() -> int {
        if (pos == len) {
            len = fread(buffer, 1, BUFFER_SIZE, fp);
            pos = 0;
            if (len == 0) return EOF;
        }
        return buffer[pos++];
    };
    
    auto fastRead = [&]() -> long long {
        long long x = 0;
        bool neg = false;
        int ch = nextChar();
        
        while (ch != EOF && ch != '-' && (ch < '0' || ch > '9')) {
            ch = nextChar();
        }
        
        if (ch == EOF) return LLONG_MIN;
        
        if (ch == '-') {
            neg = true;
            ch = nextChar();
        }
        
        while (ch >= '0' && ch <= '9') {
            x = x * 10 + (ch - '0');
            ch = nextChar();
        }
        
        return neg ? -x : x;
    };
    
    long long num;
    while ((num = fastRead()) != LLONG_MIN) {
        g_sum += num;
        g_count++;
    }
    
    delete[] buffer;
    fclose(fp);
}

// 方法7: 优化的缓冲快读（使用位运算）
void method7_optimized(const std::string& filename) {
    FILE* fp = fopen(filename.c_str(), "r");
    if (!fp) return;
    
    const int BUFFER_SIZE = 1 << 20;
    char* buffer = new char[BUFFER_SIZE];
    
    g_sum = 0;
    g_count = 0;
    
    size_t pos = 0;
    size_t len = 0;
    
    auto nextChar = [&]() -> int {
        if (pos == len) {
            len = fread(buffer, 1, BUFFER_SIZE, fp);
            pos = 0;
            if (len == 0) return EOF;
        }
        return buffer[pos++];
    };
    
    auto fastRead = [&]() -> long long {
        long long x = 0;
        bool neg = false;
        int ch = nextChar();
        
        while (ch != EOF && ch != '-' && (ch < '0' || ch > '9')) {
            ch = nextChar();
        }
        
        if (ch == EOF) return LLONG_MIN;
        
        if (ch == '-') {
            neg = true;
            ch = nextChar();
        }
        
        // 使用位运算优化
        while (ch >= '0' && ch <= '9') {
            x = (x << 3) + (x << 1) + (ch ^ 48);  // x*10 + (ch-'0')
            ch = nextChar();
        }
        
        return neg ? -x : x;
    };
    
    long long num;
    while ((num = fastRead()) != LLONG_MIN) {
        g_sum += num;
        g_count++;
    }
    
    delete[] buffer;
    fclose(fp);
}

// ==================== 3. 基准测试框架 ====================
struct TestResult {
    std::string name;
    std::vector<double> times;
    double avg_time;
    double min_time;
    double max_time;
    long long checksum;
    int count;
};

class Benchmark {
private:
    std::string test_file;
    int runs;
    std::vector<TestResult> results;
    
public:
    Benchmark(const std::string& file, int r) : test_file(file), runs(r) {}
    
    void runTest(const std::string& name, 
                 std::function<void(const std::string&)> func) {
        TestResult result;
        result.name = name;
        
        std::cout << "测试: " << name << " ";
        std::cout.flush();
        
        // 预热
        func(test_file);
        
        // 正式测试
        for (int i = 0; i < runs; ++i) {
            auto start = std::chrono::high_resolution_clock::now();
            func(test_file);
            auto end = std::chrono::high_resolution_clock::now();
            
            double time_ms = std::chrono::duration<double, std::milli>(end - start).count();
            result.times.push_back(time_ms);
            
            std::cout << ".";
            std::cout.flush();
        }
        
        // 记录结果
        result.checksum = g_sum;
        result.count = g_count;
        
        // 计算统计
        result.avg_time = 0;
        for (size_t i = 0; i < result.times.size(); ++i) {
            result.avg_time += result.times[i];
        }
        result.avg_time /= runs;
        
        result.min_time = *std::min_element(result.times.begin(), result.times.end());
        result.max_time = *std::max_element(result.times.begin(), result.times.end());
        
        std::cout << " 完成! (平均: " << std::fixed << std::setprecision(2) 
                  << result.avg_time << " ms)" << std::endl;
        
        results.push_back(result);
    }
    
    void printResults() {
        std::cout << "\n" << std::string(80, '=') << std::endl;
        std::cout << "                      性能测试结果" << std::endl;
        std::cout << std::string(80, '=') << std::endl;
        
        // 检查正确性
        bool all_correct = true;
        if (!results.empty()) {
            long long expected_sum = results[0].checksum;
            int expected_count = results[0].count;
            
            std::cout << "\n正确性验证:" << std::endl;
            std::cout << "  读取数量: " << expected_count << std::endl;
            std::cout << "  校验和: " << expected_sum << std::endl;
            
            for (size_t i = 1; i < results.size(); ++i) {
                if (results[i].checksum != expected_sum || 
                    results[i].count != expected_count) {
                    std::cout << "  ❌ " << results[i].name << " 结果不一致!" << std::endl;
                    all_correct = false;
                }
            }
            
            if (all_correct) {
                std::cout << "  ✅ 所有方法结果一致！" << std::endl;
            }
        }
        
        // 性能表格
        std::cout << "\n性能对比:" << std::endl;
        std::cout << std::string(80, '-') << std::endl;
        std::cout << std::left << std::setw(30) << "方法"
                  << std::right << std::setw(12) << "平均(ms)"
                  << std::setw(12) << "最小(ms)"
                  << std::setw(12) << "最大(ms)"
                  << std::setw(12) << "速度比" << std::endl;
        std::cout << std::string(80, '-') << std::endl;
        
        // 按速度排序
        std::sort(results.begin(), results.end(), 
                  [](const TestResult& a, const TestResult& b) {
                      return a.avg_time < b.avg_time;
                  });
        
        double baseline = results.back().avg_time;  // 最慢的作为基准
        
        for (size_t i = 0; i < results.size(); ++i) {
            const TestResult& r = results[i];
            std::cout << std::left << std::setw(30) << r.name
                      << std::right << std::fixed << std::setprecision(2)
                      << std::setw(12) << r.avg_time
                      << std::setw(12) << r.min_time
                      << std::setw(12) << r.max_time
                      << std::setw(11) << (baseline / r.avg_time) << "x" << std::endl;
        }
        
        std::cout << std::string(80, '=') << std::endl;
        
        if (!results.empty()) {
            std::cout << "🏆 最快: " << results[0].name 
                      << " (" << results[0].avg_time << " ms)" << std::endl;
            std::cout << "🐌 最慢: " << results.back().name 
                      << " (" << results.back().avg_time << " ms)" << std::endl;
            std::cout << "⚡ 加速: " << std::fixed << std::setprecision(1) 
                      << (baseline / results[0].avg_time) << " 倍" << std::endl;
        }
    }
};

// ==================== 4. 主函数 ====================
int main(int argc, char* argv[]) {
    // 检测 C++ 版本
    std::cout << "\n====== C++ IO 性能测试 ======" << std::endl;
    
    #if __cplusplus >= 201703L
        std::cout << "C++ 版本: C++17 或更高" << std::endl;
    #elif __cplusplus >= 201402L
        std::cout << "C++ 版本: C++14" << std::endl;
    #elif __cplusplus >= 201103L
        std::cout << "C++ 版本: C++11" << std::endl;
    #else
        std::cout << "C++ 版本: C++98/03" << std::endl;
    #endif
    
    // 参数设置
    int data_count = 1000000;  // 默认100万，避免太慢
    int runs = 5;
    
    if (argc > 1) data_count = std::atoi(argv[1]);
    if (argc > 2) runs = std::atoi(argv[2]);
    
    std::cout << "测试数据: " << data_count << " 个整数" << std::endl;
    std::cout << "运行次数: " << runs << " 次" << std::endl;
    std::cout << std::string(30, '=') << std::endl;
    
    // 生成测试数据
    const std::string test_file = "test_data.txt";
    generateTestData(test_file, data_count);
    
    // 创建基准测试
    Benchmark bench(test_file, runs);
    
    std::cout << "\n开始性能测试..." << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    // 添加测试方法 - 使用兼容 C++11 的方式
    typedef std::pair<std::string, std::function<void(const std::string&)> > TestMethod;
    std::vector<TestMethod> methods;
    
    methods.push_back(TestMethod("标准 cin", method1_cin));
    methods.push_back(TestMethod("cin (关闭同步)", method2_cin_nosync));
    methods.push_back(TestMethod("cin (优化版)", method3_cin_optimized));
    methods.push_back(TestMethod("fscanf", method4_scanf));
    methods.push_back(TestMethod("快读 (fgetc)", method5_fast_fgetc));
    methods.push_back(TestMethod("缓冲快读", method6_buffered));
    methods.push_back(TestMethod("优化快读 (位运算)", method7_optimized));
    
    // 运行测试 - 兼容 C++11 的循环方式
    for (size_t i = 0; i < methods.size(); ++i) {
        bench.runTest(methods[i].first, methods[i].second);
    }
    
    // 打印结果
    bench.printResults();
    
    std::cout << "\n提示: 可以通过命令行参数调整测试规模" << std::endl;
    std::cout << "用法: " << argv[0] << " [数据量] [运行次数]" << std::endl;
    std::cout << "例如: " << argv[0] << " 5000000 5" << std::endl;
    
    return 0;
}

/* ==================== 编译和运行脚本 ====================

编译命令：
---------
# C++11
g++ -std=c++11 -O2 -o benchmark11 benchmark.cpp

# C++14  
g++ -std=c++14 -O2 -o benchmark14 benchmark.cpp

# C++17
g++ -std=c++17 -O2 -o benchmark17 benchmark.cpp

运行命令：
---------
./benchmark11 1000000 5   # 100万数据，运行5次
./benchmark14 5000000 5   # 500万数据，运行5次
./benchmark17 10000000 3  # 1000万数据，运行3次

批量测试脚本 (test_all.sh)：
---------------------------
#!/bin/bash

echo "编译所有版本..."
g++ -std=c++11 -O2 -o benchmark11 benchmark.cpp
g++ -std=c++14 -O2 -o benchmark14 benchmark.cpp
g++ -std=c++17 -O2 -o benchmark17 benchmark.cpp

echo -e "\n测试 C++11..."
./benchmark11 1000000 5

echo -e "\n测试 C++14..."
./benchmark14 1000000 5

echo -e "\n测试 C++17..."
./benchmark17 1000000 5

==================== */
