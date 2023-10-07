#include <cmath>
#include <vector>
extern "C" __declspec(dllexport)
double func(const std::vector<double>& values) {
    //if (values.size() != 1) throw std::exception();
    return cos(values[0])/sin(values[0]);
}