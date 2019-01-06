/*################################################################################
  ##
  ##   Copyright (C) 2011-2019 Keith O'Hara
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
    double prob_par = 0.75;

    double bern_mean = prob_par;
    double bern_var = prob_par*(1.0 - prob_par);

    int n_sample = 10000;

    std::cout << "\n*** rbern: begin tests. ***\n" << std::endl;

    //

    int bern_rand = stats::rbern(prob_par);

    std::cout << "bern rv draw: " << bern_rand << std::endl;

#ifdef STATS_TEST_STDVEC_FEATURES
    std::vector<double> bern_std_vec = stats::rbern<std::vector<double>>(n_sample,1,prob_par);

    std::cout << "bern rv mean: " << stats::mat_ops::mean(bern_std_vec) << ". Should be close to: " << bern_mean << "\n";
    std::cout << "bern rv variance: " << stats::mat_ops::var(bern_std_vec) << ". Should be close to: " << bern_var << std::endl;
#endif

#ifdef STATS_TEST_MATRIX_FEATURES
    mat_obj bern_vec = stats::rbern<mat_obj>(n_sample,1,prob_par);

    std::cout << "bern rv mean: " << stats::mat_ops::mean(bern_vec) << ". Should be close to: " << bern_mean << "\n";
    std::cout << "bern rv variance: " << stats::mat_ops::var(bern_vec) << ". Should be close to: " << bern_var << std::endl;
#endif

    //

    std::cout << "\n*** rbern: end tests. ***\n" << std::endl;

    return 0;
}
