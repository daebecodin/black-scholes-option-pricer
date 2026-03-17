#include <iostream>
#include <string>
#include <limits>
#include <cmath>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getValidInput(std::string_view message)
{
    while (true) {
        double value{};
        std::cout << message;;
        std::cin >> value ;

        if (std::cin.fail() || value < 0) {
            std::cout << "Invalid input. Try again" << '\n';
            std::cin.clear();
            ignoreLine();
            continue;
        }
        ignoreLine();
        return value;
    }

}

double calculateD1(double stockPrice, double strikePrice, double riskFreeRate, double volatility, double timeToExpiration) {

    double logTerm = std::log(stockPrice/strikePrice);
    double varianceTerm = 0.5 * (volatility * volatility);
    double driftPlusVariance = riskFreeRate + varianceTerm;
    double timeAdjusted = driftPlusVariance * timeToExpiration;

    double numerator = logTerm + timeAdjusted;
    double denominator = volatility * std::sqrt(timeToExpiration);

    double d1{numerator / denominator};

    return d1;
}

double calculateD2(double d1, double stockPrice, double strikePrice, double riskFreeRate, double volatility, double timeToExpiration)
{

    d1 = calculateD1(stockPrice, strikePrice, riskFreeRate, volatility, timeToExpiration);


    double d2{ d1 - (volatility * std::sqrt(timeToExpiration))};

    return d2;
}

double calculateNormalCDF(double x)
{
    double errorFunctionInput = x / std::sqrt(2.0);
    double errorFunctionResult = std::erf(errorFunctionInput);
    double cdf = 0.5 * (1.0 + errorFunctionResult);
    return cdf;
}



int main() {

    double stockPrice = getValidInput("Enter Stock Price (S): ");
    double strikePrice = getValidInput("Enter Strike Price (K): ");
    double volatility = getValidInput("Enter Volatility (σ): ");
    double timeToExpiration = getValidInput("Enter Time to Expiration (T): ");
    double riskFreeRate = getValidInput("Enter Rick-Free Rate (S): ");

    std::cout << stockPrice << '\n';
    std::cout << strikePrice << '\n';
    std::cout << volatility << '\n';
    std::cout << timeToExpiration << '\n';
    std::cout << riskFreeRate << '\n';
    return 0;
}