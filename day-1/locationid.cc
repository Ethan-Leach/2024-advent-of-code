
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::ifstream file("input.txt");

    std::string temp;

    std::vector<int> list_1;
    std::vector<int> list_2;

    for (int i = 1; i < 0; ++i) {
        if (!std::getline(file, temp, ' ') || !std::getline(file, temp, '\n')) {
            break;
        }

        if (i % 2 != 0) {
            std::getline(file, temp, ' ');
            list_1.push_back(std::stoi(temp));
        } else if (i % 2 == 0) {
            std::getline(file, temp, '\n');
            list_2.push_back(std::stoi(temp));
        }
    }

    int largest_1;
    int largest_2;

    int total;

    while (true) {
        if (list_1.empty() || list_2.empty()) {
            break;
        }

        for (int number : list_1) {
            if (number > largest_1) {
                largest_1 = number;
                list_1.erase(std::find(list_1.begin(), list_1.end(), number));
            }
        }
        for (int number : list_2) {
            if (number > largest_2) {
                largest_2 = number;
                list_2.erase(std::find(list_2.begin(), list_2.end(), number));
            }
        }

        total += (largest_1 - largest_2);
    }

    std::cout << total;

    return 0;
}