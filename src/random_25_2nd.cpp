#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

void print_table(const std::vector<int>& arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (i % 5 == 0) {
            std::cout << "|";
        }

        std::cout << (arr[i] < 10 ? "0" : "") << arr[i] << "|";

        if (i % 5 == 4) {
            std::cout << std::endl;
        }
    }
}

int main() {
    const int size = 25;
    std::vector<int> arr;
    std::set<int> unique_numbers;
    srand(static_cast<unsigned int>(time(nullptr))); // Khởi tạo seed cho random

    while (unique_numbers.size() < size) {
        int number = rand() % size + 1; // Số từ 1 đến 25
        unique_numbers.insert(number); // Thêm vào set (trùng lặp sẽ tự động bị loại bỏ)
    }

    // Xáo trộn mảng để có thứ tự ngẫu nhiên
    std::shuffle(arr.begin(), arr.end());
    // Chuyển đổi từ set sang vector
    arr.assign(unique_numbers.begin(), unique_numbers.end());

    print_table(arr); // In bảng

    return 0;
}