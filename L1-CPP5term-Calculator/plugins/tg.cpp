#include <cmath>

extern "C" __declspec(dllexport)
double func(double x) {
    return (sin(x) / cos(x));
}