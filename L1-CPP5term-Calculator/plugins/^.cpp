#include <cmath>
#include <vector>
extern "C" __declspec(dllexport)
double func(const std::vector<double>& values) {
    if (values.size() != 2) throw std::exception();
    return std::pow(values[1], values[0]);
}
