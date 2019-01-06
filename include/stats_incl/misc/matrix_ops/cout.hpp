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

/*
 * for internal use only; used to switch between the different matrix libraries
 */

//
// printing

#ifdef STATS_USE_STDVEC
template<typename eT>
statslib_inline
void
cout_output(const std::vector<eT>& X)
{
    std::cout << "   ";
    for (const auto x: X)
        std::cout << x << "  ";
    std::cout << "\n";
}
#endif

#ifdef STATS_USE_ARMA
template<typename eT>
statslib_inline
void
cout_output(const ArmaMat<eT>& X)
{
    arma::cout << X << "\n";
}
#endif

#ifdef STATS_USE_BLAZE
template<typename eT, bool To>
statslib_inline
void
cout_output(const BlazeMat<eT,To>& X)
{
    std::cout << X << "\n";
}
#endif

#ifdef STATS_USE_EIGEN
template<typename eT, int iTr, int iTc>
statslib_inline
void
cout_output(const EigenMat<eT,iTr,iTc>& X)
{
    std::cout << X << "\n";
}
#endif
