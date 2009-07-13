#include <iostream>
#include <random>
#include <ctime>
#include <functional>

using namespace std;

template <typename RNG>
struct rng
{
    typedef typename RNG::result_type result_type;

    RNG &d_rng;
    result_type d_min;
    result_type d_max;
    result_type d_oldmin;
    double d_slope;

    rng(RNG &rg, result_type min = 0, result_type max = result_type(100))
    :
        d_rng(rg),
        d_min(min),
        d_max(max),
        d_oldmin(rg.min()),
        d_slope((d_max - static_cast<double>(d_min)) / (rg.max() - d_oldmin))
    {
//        cout << d_min << " " << d_max << " " << d_oldmin << " " << d_slope << 
//                " " << rg.max() << endl << endl;
    }

    result_type operator()()
    {
        return d_min + d_slope * (d_rng() - d_oldmin);
    }
};


int main()
{
    std::mt19937 mt; //(time(0));

    rng<std::mt19937> rg(mt, 1, 100);

//    bernoulli_distribution bd;
//    binomial_distribution<> bd;       // N.A.
//    gamma_distribution<> bd;          // N.A.
//    geometric_distribution<> bd;
//    exponential_distribution<> bd;
//    normal_distribution<> bd;         // N.A.
//    poisson_distribution<> bd;        // N.A.

    uniform_real<> bd;

    for (int idx = 0; idx < 20; ++idx)
        cout << bd(rg) << (idx + 1 == 10 ? '\n' : ' ');
    cout << endl;
}

 
