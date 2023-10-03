#include <cmath>
#include <vector>
extern "C" __declspec(dllexport)
double func(const std::vector<double>& values) {
    //if (values.size() != 1) throw std::exception();
    return sin(values[0])/cos(values[0]);
}