/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   Licensed under the Apache License, Version 2.0 (the "License");
  ##   you may not use this file except in compliance with the License.
  ##   You may obtain a copy of the License at
  ##
  ##       http://www.apache.org/licenses/LICENSE-2.0
  ##
  ##   Unless required by applicable law or agreed to in writing, software
  ##   distributed under the License is distributed on an "AS IS" BASIS,
  ##   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  ##   See the License for the specific language governing permissions and
  ##   limitations under the License.
  ##
  ################################################################################*/

#include "stats.hpp"
#include "../stats_tests.hpp"

int main()
{
    double err_tol = 1E-06;
    int round_digits_1 = 3;
    int round_digits_2 = 5;

    double shape_par = 2.0;
    double rate_par = 1.0;

    std::cout << "\n*** dinvgamma: begin tests. ***\n" << std::endl;

    // x = 1
    double x_1 = 0.5;
    double val_1 = stats::dgamma(1.0/x_1,shape_par,1.0/rate_par,false) /(x_1*x_1);
    double dens_1 = stats::dinvgamma(x_1,shape_par,rate_par,false);

    bool success_1 = (std::abs(dens_1 - val_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dinvgamma(" << x_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_1 << ". Success = " << success_1 << std::endl;

    // x = 2, return log
    double x_2 = 1.5;
    double val_2 = stats::dgamma(1.0/x_2,shape_par,1/rate_par,true) - 2*gcem::log(x_2);
    double dens_2 = stats::dinvgamma(x_2,shape_par,rate_par,true);

    bool success_2 = (std::abs(dens_2 - val_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1-1) << "dinvgamma(" << x_2 << ",log=true): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << dens_2 << ". Success = " << success_2 << std::endl;

    if (success_1 && success_2) {
        std::cout << "\n*** dinvgamma: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** dinvgamma: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests 

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj x_mat(2,1);
    x_mat(0,0) = 1;
    x_mat(1,0) = 2;

    stats::dinvgamma(x_mat,shape_par,rate_par);
    stats::dinvgamma(x_mat,shape_par,rate_par,true);
#endif

    return 0;
}
