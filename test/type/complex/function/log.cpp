//==================================================================================================
/*
  Copyright 2017 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/type/complex/function/log.hpp>
#include <boost/simd/type/complex.hpp>
#include <boost/simd/pack.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/pi.hpp>
#include <simd_test.hpp>
#include <iomanip>

namespace bs = boost::simd;

STF_CASE_TPL( "Complex log on complex<T>", STF_IEEE_TYPES)
{
  bs::complex<T> c1(0, 2), c2(-3, 4), c3(-2, 0);
  STF_ULP_EQUAL( bs::cmplx::log(c1), bs::complex<T>(0.69314718055994530941723212145818, 1.5707963267948966192313216916398), 0.5);
  STF_ULP_EQUAL( bs::cmplx::log(c2), bs::complex<T>(1.6094379124341003746007593332262,  2.2142974355881810060341309203571), 0.5);
  STF_ULP_EQUAL( bs::cmplx::log(c3), bs::complex<T>(0.69314718055994530941723212145818, 3.1415926535897932384626433832795), 0.5);
}

STF_CASE_TPL( "Complex log on T", STF_IEEE_TYPES)
{
  T r1(2), r2(-2);
  STF_ULP_EQUAL( bs::cmplx::log(r1), bs::complex<T>(0.69314718055994530941723212145818, 0.0), 0.5);
  STF_ULP_EQUAL( bs::cmplx::log(r2), bs::complex<T>(0.69314718055994530941723212145818, 3.1415926535897932384626433832795), 0.5);
  STF_ULP_EQUAL( bs::log(r2), bs::Nan<T>(), 0.5);
}

STF_CASE_TPL( "Complex log complex<pack<T>>", STF_IEEE_TYPES)
{
    using p_t = bs::pack<T,4>;
    using cp_t = bs::complex<p_t>;
    p_t r(T(0), T(-3), T(1), bs::Minf<T>()),  i(2, 4, 0, 1);
    p_t r1(T(0.69314718055994530941723212145818),
           T(1.6094379124341003746007593332262),
           T(0),
           bs::Inf<T>()),
      i1(T(1.5707963267948966192313216916398),
         T(2.2142974355881810060341309203571),
         T(0),
         bs::Pi<T>() );
    cp_t c1(r, i),  c2(r1, i1);
    STF_ULP_EQUAL(bs::cmplx::log(c1), c2, 0.5);
}



