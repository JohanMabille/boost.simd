//==================================================================================================
/*!
  @file

  Aggregate SIMD numerical and type limits for X86 AVX

  @copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_AVX_LIMITS_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_AVX_LIMITS_HPP_INCLUDED

#include <boost/simd/arch/x86/tags.hpp>
#include <boost/simd/arch/common/limits.hpp>
#include <boost/simd/detail/brigand.hpp>

namespace boost { namespace simd
{
  template<> struct limits<boost::simd::avx_>
  {
    struct largest_integer
    {
      template<typename Sign> struct apply { using type = brigand::no_such_type_; };
    };

    struct smallest_integer
    {
      template<typename Sign> struct apply { using type = brigand::no_such_type_; };
    };

    using parent = boost::simd::sse2_;

    using smallest_real = float;
    using largest_real  = double;

    enum { bits = 256, bytes = 32 };
  };
} }

#endif

