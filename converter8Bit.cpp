#include "converter8Bit.hpp"

converter8Bit::converter8Bit(double t1, double x0, double v0, double t0, double dt,  double m, double omega): converter(t1, x0, v0, t0, dt, m, omega) {}
converter8Bit::~converter8Bit() {}

std::string converter8Bit::system_of_springs(const std::string &bits)
{
    if (bits.length() == 0)
        return "";
    std::string result = "[";
    std::string brackets = "[]";

    size_t j = bits.length() - 1;

    for (size_t i = 0; i < bits.length(); i++)
    {
        if (bits[j--] == '1')
        {
            result += '[';
            while (brackets.length() != pow(2, i+1))
                brackets += brackets;
            result += brackets;
            result += ']';
        }
    }
    result += ']';

    std::cout << "Result: " << result << std::endl;
    return result;
}

double converter8Bit::binary_to_decimal(std::string binary)
{
    return pow(ampl_i(compute_oscilations(system_of_springs(binary))) * omega, 2);
}