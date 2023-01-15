#include <iostream>     // std::cout
#include <algorithm>    // std::copy
#include <vector>       // std::vector
#include <cctype>
#include <iomanip>
#include <string>
#include <format>
#include <numeric>



void hw2_1() {
    double input;
    std::vector<double> coordinates;

    std::cout << "please input some numbers, integer or double, separated by space:" << std::endl;
    while (std::cin >> input) {
        coordinates.push_back(input);
    };

    std::vector<double> results(coordinates.size());

    std::transform(coordinates.cbegin(), coordinates.cend(), coordinates.cbegin(),
        results.begin(), std::multiplies<>{});

    for (auto& ele : results) {
        std::cout << ele << " " << std::endl;
    }


}

void hw2_2() {
    double input;
    std::vector<double> coordinates;
    std::vector<double> origin;

    //origin = { 0.0, 0.0, 0.0 };
    std::cout << "please input some doubles, separated by space for the origin:" << std::endl;
    while (std::cin >> input) {
        origin.push_back(input);
    };

    
    std::cout << std::format("please input {} doubles, separated by space for the point you want to calc distance for:", origin.size()) << std::endl;
    while (std::cin >> input) {
        coordinates.push_back(input);
    };

    std::vector<double> results(coordinates.size());

    //calc distance
    std::transform(coordinates.cbegin(), coordinates.cend(), origin.cbegin(),
        results.begin(), std::minus<>{});

    //calc square
    std::transform(results.begin(), results.end(), results.begin(),
        results.begin(), std::multiplies<>{});

    std::cout << std::sqrt(std::accumulate(results.begin(), results.end(), 0.0));

}

void hw2_3() {
    double input;
    std::vector<double> coordinates;
    std::vector<double> origin;

    //origin = { 0.0, 0.0, 0.0 };
    std::cout << "please input some doubles, separated by space for the origin:" << std::endl;
    while (std::cin >> input) {
        origin.push_back(input);
    };
    
    std::cout << std::format("please input {} doubles, separated by space for the point you want to calc distance for:", origin.size()) << std::endl;
    while (std::cin >> input) {
        coordinates.push_back(input);
    };

    std::vector<double> results(coordinates.size());

    //calc distance
    std::transform(coordinates.cbegin(), coordinates.cend(), origin.cbegin(),
        results.begin(), std::minus<>{});

    std::cout << std::sqrt(std::inner_product(results.cbegin(), results.cend(), results.cbegin(), 0.0));

}

void hw2_4() {
    double input;
    std::vector<double> coordinates;
    std::vector<double> origin;

    //origin = { 1.0, 1.0, 1.0 };
    std::cout << "please input some doubles, separated by space for the origin:" << std::endl;
    while (std::cin >> input) {
        origin.push_back(input);
    };

    std::cout << std::format("please input {} doubles, separated by space for the point you want to calc distance for:", origin.size()) << std::endl;
    while (std::cin >> input) {
        coordinates.push_back(input);
    };

    std::vector<double> results(coordinates.size());

    //calc distance
    std::transform(coordinates.cbegin(), coordinates.cend(), origin.cbegin(),
        results.begin(), std::minus<>{});

    std::cout << std::sqrt(std::accumulate(results.begin(), results.end(), 0.0, std::multiplies()));

}


int main() {
    //hw2_1();
    hw2_2();
    hw2_3();
    hw2_4();

    return 0;
}
