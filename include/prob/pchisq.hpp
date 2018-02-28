/*################################################################################
  ##
  ##   Copyright (C) 2011-2018 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   StatsLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   StatsLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

/*
 * cdf of the chi-squared distribution
 */

#ifndef _statslib_pchisq_HPP
#define _statslib_pchisq_HPP

//
// single input

template<typename T>
statslib_constexpr T pchisq(const T x, const T dof_par, const bool log_form = false);

//
// matrix/vector input

template<typename Ta, typename Tb, typename Tc = Tb>
void pchisq_int(const Ta* __stats_pointer_settings__ vals_in, const Tb dof_par, const bool log_form, 
                      Tc* __stats_pointer_settings__ vals_out, const uint_t num_elem);

#ifdef STATS_USE_ARMA
template<typename Ta, typename Tb, typename Tc = Tb>
ArmaMat<Tc> pchisq(const ArmaMat<Ta>& X, const Tb dof_par, const bool log_form = false);
#endif

#ifdef STATS_USE_BLAZE
template<typename Ta, typename Tb, typename Tc = Tb, bool To = blaze::columnMajor>
BlazeMat<Tc,To> pchisq(const BlazeMat<Ta,To>& X, const Tb dof_par, const bool log_form = false);
#endif

#ifdef STATS_USE_EIGEN
template<typename Ta, typename Tb, typename Tc = Tb, int iTr = Eigen::Dynamic, int iTc = Eigen::Dynamic>
EigMat<Tc,iTr,iTc> pchisq(const EigMat<Ta,iTr,iTc>& X, const Tb dof_par, const bool log_form = false);
#endif

//
// include implementation files

#include "pchisq.ipp"

#endif
