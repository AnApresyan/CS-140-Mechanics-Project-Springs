#include "spring.hpp"

spring::spring(): _k(1) {}

spring::spring(double k, double m): _k(k), _m(m) {}

double spring::getK()
{
    return _k;
}

void spring::setK(double k)
{
    _k = k;
}

std::vector<double> spring::move(double t, double dt, double x0, double v0)
{
    std::vector<double> coords;
    double omega = sqrt(_k);

    for (double time = 0; time <= t; time+=dt)
        coords.push_back(x0 * cos(omega * time) + v0/omega * sin(omega * time));
    return (coords);
}

std::vector<double> spring::move(double t, double dt, double x0)
{
    std::vector<double> coords;
    double omega = sqrt(_k);

    for (double time = 0; time <= t; time+=dt)
        coords.push_back(x0 * cos(omega * time));
    return (coords);
}

std::vector<double> spring::move(double t0, double t1, double dt, double x0, double v0)
{
    std::vector<double> coords;
    double omega = sqrt(_k);

    for (double time = t0; time <= t1; time+=dt)
        coords.push_back(x0 * cos(omega * time) + v0/omega * sin(omega * time));
    return (coords);
}

std::vector<double> spring::move(double t0, double t1, double dt, double x0, double v0, double m)
{
    std::vector<double> coords;
    double omega = sqrt(_k/m);

    for (double time = t0; time <= t1; time+=dt)
        coords.push_back(x0 * cos(omega * time) + v0/omega * sin(omega * time));
    return (coords);
}

spring spring::inSeries(const spring &other)
{
    return (spring((_k * other._k)/(_k + other._k)));
}

spring spring::inParallel(const spring &other)
{
    return (spring(_k + other._k));
}

double spring::getOmega()
{
    return sqrt(_k/_m);
}

