#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <thread>

const double precision = 1e-7;

double pi_odd = 0.0;
double pi_even = 0.0;

// Обчислює від’ємні члени ряду: -1/3 -1/7 -1/11 -1/15 ...
void calc_odd()
{
    double sum = 0.0;
    double prev = 0.0;

    for (long long k = 1; ; k += 2)                     // k = 1, 3, 5, 7, ...
    {
        sum += -1.0 / (2.0 * k + 1.0);
                                                        // 1) sum = 0 + (-1/3)     = -1/3
                                                        // 2) sum = -1/3 + (-1/7)  = -10/21
                                                        // 3) sum = -10/21 + (-1/11) = -131/231
                                                        // ...

        if (std::abs(sum - prev) < precision)
            break;
                                                        // |−1/3 − 0|            = 1/3   > 1e-7
                                                        // |−10/21 − (−1/3)|     = 1/7   > 1e-7
                                                        // |−131/231 − (−10/21)| = 1/11  > 1e-7

        prev = sum;
    }

    pi_odd = 4.0 * sum;
}

// Обчислює додатні члени ряду: +1 +1/5 +1/9 +1/13 ...
void calc_even()
{
    double sum = 1.0;
    double prev = 0.0;

    for (long long k = 2; ; k += 2)
    {
        sum += 1.0 / (2.0 * k + 1.0);

        if (std::abs(sum - prev) < precision)
            break;

        prev = sum;
    }

    pi_even = 4.0 * sum;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    std::thread t_odd(calc_odd);
    std::thread t_even(calc_even);

    t_odd.join();
    t_even.join();

    double pi = pi_odd + pi_even;

    std::cout << std::setprecision(15);
    std::cout << "pi = " << pi << '\n';

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "duration = " << duration.count() << " sec\n";

    return 0;
}

/*

pi = 3.14159245358711
duration = 0.0175772 sec

*/
