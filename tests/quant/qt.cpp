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
    double err_tol = 1E-05;
    int round_digits_1 = 5;
    int round_digits_2 = 3;

    double dof_par = 11;

    std::cout << "\n*** qt: begin tests. ***\n" << std::endl;

    // x = -1.01
    double x_1 = -1.01;
    double val_1 = 0.1670981;
    double q_1 = stats::qt(val_1,dof_par);

    bool success_1 = (std::abs(q_1 - x_1) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qt(" << val_1 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2-1) << q_1 << ". Success = " << success_1 << std::endl;

    // x = -0.37
    double x_2 = -0.37;
    double val_2 = 0.3592038;
    double q_2 = stats::qt(val_2,dof_par);

    bool success_2 = (std::abs(q_2 - x_2) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qt(" << val_2 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2-1) << q_2 << ". Success = " << success_2 << std::endl;

    // x = 0
    double x_3 = 0;
    double val_3 = 0.5;
    double q_3 = stats::qt(val_3,dof_par);

    bool success_3 = (std::abs(q_3 - x_3) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qt(" << val_3 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2-1) << q_3 << ". Success = " << success_3 << std::endl;

    // x = +0.37
    double x_4 = 0.37;
    double val_4 = 0.6407962;
    double q_4 = stats::qt(val_4,dof_par);

    bool success_4 = (std::abs(q_4 - x_4) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qt(" << val_4 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_4 << ". Success = " << success_4 << std::endl;

    // x = +1.01
    double x_5 = 1.01;
    double val_5 = 0.8329019;
    double q_5 = stats::qt(val_5,dof_par);

    bool success_5 = (std::abs(q_5 - x_5) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qt(" << val_5 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_5 << ". Success = " << success_5 << std::endl;

    // x = +1.58
    double x_6 = 1.58;
    double val_6 = 0.9287938;
    double q_6 = stats::qt(val_6,dof_par);

    bool success_6 = (std::abs(q_6 - x_6) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qt(" << val_6 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_6 << ". Success = " << success_6 << std::endl;

    // x = +2.5
    double x_7 = 2.5;
    double val_7 = 0.9852468;
    double q_7 = stats::qt(val_7,dof_par);

    bool success_7 = (std::abs(q_7 - x_7) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qt(" << val_7 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_7 << ". Success = " << success_7 << std::endl;

    // x = +3.5
    double x_8 = 3.5;
    double val_8 = 0.9975148547;
    double q_8 = stats::qt(val_8,dof_par);

    bool success_8 = (std::abs(q_8 - x_8) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qt(" << val_8 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_8 << ". Success = " << success_8 << std::endl;

    // x = -3.5
    double x_9 = -3.5;
    double val_9 = 0.002485145257;
    double q_9 = stats::qt(val_9,dof_par);

    bool success_9 = (std::abs(q_9 - x_9) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "qt(" << val_9 << "): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_9 << ". Success = " << success_9 << std::endl;

    // test edge case
    double x_10 = -1.846695528;
    double val_10 = 0.1;
    double q_10 = stats::qt(val_10,2.1);

    bool success_10 = (std::abs(q_10 - x_10) < err_tol);
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_1) << "\nqt(" << val_10 << ",2.1): ";
    std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(round_digits_2) << q_10 << ". Success = " << success_10 << std::endl;

    if (success_1 && success_2 && success_3 && success_4 && success_5 && success_6 && success_7 && success_8 && success_9 && success_10)
    {
        std::cout << "\n*** qt: \033[32mall tests PASSED.\033[0m ***\n" << std::endl;
    } else {
        std::cout << "\n*** qt: \033[31msome tests FAILED.\033[0m ***\n" << std::endl;
    }

    //
    // coverage tests

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj x_mat(2,1);
    x_mat(0,0) = 0.7;
    x_mat(1,0) = 0.8;

    stats::qt(x_mat,dof_par);
#endif

    return 0;
}
