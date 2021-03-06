//==================================================================================================
/*!
  @file

  Copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#include <boost/simd/pack.hpp>
#include <boost/simd/function/dec.hpp>
#include <boost/simd/function/bits.hpp>
#include <boost/simd/meta/cardinal_of.hpp>
#include <simd_test.hpp>
#include <boost/simd/detail/dispatch/meta/as_integer.hpp>
#include <boost/simd/constant/inf.hpp>
#include <boost/simd/constant/minf.hpp>
#include <boost/simd/constant/mone.hpp>
#include <boost/simd/constant/nan.hpp>
#include <boost/simd/constant/one.hpp>
#include <boost/simd/constant/zero.hpp>
#include <boost/simd/constant/valmin.hpp>
#include <boost/simd/constant/two.hpp>
#include <boost/simd/constant/mtwo.hpp>

template <typename T, std::size_t N, typename Env>
void test(Env& runtime)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T, N>;

  T a1[N], b[N];
  for(std::size_t i = 0; i < N; ++i)
  {
    a1[i] = (i%2) ? T(i) : T(-i);
    b[i] = bs::saturated_(bs::dec)(a1[i]) ;
  }
  p_t aa1(&a1[0], &a1[0]+N);
  p_t bb (&b[0], &b[0]+N);
  STF_IEEE_EQUAL(bs::saturated_(bs::dec)(aa1), bb);
}

STF_CASE_TPL("Check dec_s on pack" , STF_NUMERIC_TYPES)
{
  namespace bs = boost::simd;
  using p_t = bs::pack<T>;
  static const std::size_t N = bs::cardinal_of<p_t>::value;
  test<T, N>(runtime);
  test<T, N/2>(runtime);
  test<T, N*2>(runtime);
}


STF_CASE_TPL (" bs::saturated_(dec) signed_int",  STF_SIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::dec;
  using p_t = bs::pack<T>;

  using r_t = decltype(bs::saturated_(dec)(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(bs::saturated_(dec)(bs::Mone<p_t>()), bs::Mtwo<p_t>());
  STF_EQUAL(bs::saturated_(dec)(bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(bs::saturated_(dec)(bs::Valmin<p_t>()), bs::Valmin<p_t>());
  STF_EQUAL(bs::saturated_(dec)(bs::Zero<p_t>()), bs::Mone<p_t>());
}

STF_CASE_TPL (" bs::saturated_(dec) unsigned_uint",  STF_UNSIGNED_INTEGRAL_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::dec;
  using p_t = bs::pack<T>;

  using r_t = decltype(bs::saturated_(dec)(p_t()));

  // return type conformity test
  STF_TYPE_IS(r_t, p_t);

  // specific values tests
  STF_EQUAL(bs::saturated_(dec)(bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(bs::saturated_(dec)(bs::Two<p_t>()), bs::One<p_t>());
  STF_EQUAL(bs::saturated_(dec)(bs::Zero<p_t>()), bs::Zero<p_t>());
}

STF_CASE_TPL(" bs::saturated_(dec) floating", STF_IEEE_TYPES)
{
  namespace bs = boost::simd;
  namespace bd = boost::dispatch;
  using bs::dec;
  using p_t = bs::pack<T>;

  using r_t = decltype(bs::saturated_(dec)(p_t()));

  STF_TYPE_IS(r_t, p_t);

  // specific values tests
#ifndef BOOST_SIMD_NO_INVALIDS
  STF_EQUAL(bs::saturated_(dec)(bs::Inf<p_t>()), bs::Inf<p_t>());
  STF_IEEE_EQUAL(bs::saturated_(dec)(bs::Nan<p_t>()), bs::Nan<p_t>());
  STF_EQUAL(bs::saturated_(dec)(bs::Minf<p_t>()), bs::Minf<p_t>());
#endif
  STF_EQUAL(bs::saturated_(dec)(bs::One<p_t>()), bs::Zero<p_t>());
  STF_EQUAL(bs::saturated_(dec)(bs::Two<p_t>()), bs::One<p_t>());
  STF_EQUAL(bs::saturated_(dec)(bs::Zero<p_t>()), bs::Mone<p_t>());
}
