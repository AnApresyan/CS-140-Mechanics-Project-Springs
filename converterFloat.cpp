#include "converterFloat.hpp"

converterFloat::converterFloat(double t1,  double x0, double v0, double t0, double dt, double m, double omega): converter(t1, x0, v0, t0, dt, m, omega) {}
converterFloat::~converterFloat() {}

std::string converterFloat::system_of_springs(const std::string &bits)
{
    int point = bits.find(".");
    std::string decimal_part = bits.substr(0, point);
    std::string fractional_part = "0" + bits.substr(point + 1, bits.length());
    std::cout << "Decimal part: " << decimal_part << std::endl;
    std::cout << "Fractional part: " << fractional_part << std::endl;
    reverse(fractional_part.begin(), fractional_part.end());
    return "[" + system_of_springs(decimal_part, "[", "]") + system_of_springs(fractional_part, "{", "}") + "]";
}

std::string converterFloat::system_of_springs(const std::string &bits, std::string opening, std::string closing)
{
    if (bits.length() == 0)
        return "";
    std::string result = opening;
    std::string brackets = opening + closing;

    size_t j = bits.length() - 1;

    for (size_t i = 0; i < bits.length(); i++)
    {
        if (bits[j--] == '1')
        {
            result += opening;
            while (brackets.length() != pow(2, i+1))
                brackets += brackets;
            result += brackets;
            result += closing;
        }
    }
    result += closing;
    return result;
}


double converterFloat::binary_to_decimal(std::string binary)
{
    std::cout << "system: " << system_of_springs(binary) << std::endl;
    return pow(ampl_i(compute_oscilations(system_of_springs(binary))) * omega, 2);
}