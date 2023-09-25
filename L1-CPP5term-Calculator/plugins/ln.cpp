#include <cmath>

extern "C" __declspec(dllexport)
double func(double x) {
    return log(x);
}
