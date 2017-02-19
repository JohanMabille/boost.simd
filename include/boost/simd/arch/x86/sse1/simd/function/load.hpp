//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_LOAD_HPP_INCLUDED
#define BOOST_SIMD_ARCH_X86_SSE1_SIMD_FUNCTION_LOAD_HPP_INCLUDED

#include <boost/simd/detail/overload.hpp>
#include <boost/simd/detail/nsm.hpp>
#include <boost/simd/detail/dispatch/adapted/common/pointer.hpp>

namespace boost { namespace simd { namespace ext
{
  namespace bd = ::boost::dispatch;
  namespace bs = ::boost::simd;

  //------------------------------------------------------------------------------------------------
  // load from a pointer of single
  BOOST_DISPATCH_OVERLOAD ( load_
                          , (typename Target, typename Pointer)
                          , bs::sse1_
                          , bd::pointer_<bd::scalar_<bd::single_<Pointer>>,1u>
                          , bd::target_<bs::pack_<bd::single_<Target>,bs::sse_>>
                          )
  {
    using target = typename Target::type;

    BOOST_FORCEINLINE target do_(Pointer p, nsm::size_t<4> const&) const
    {
      return _mm_loadu_ps(p);
    }

    BOOST_FORCEINLINE target do_(Pointer p, nsm::size_t<2> const&) const
    {
      return _mm_loadl_pi(target{},(__m64 const*)(p));
    }

    BOOST_FORCEINLINE target do_(Pointer p, nsm::size_t<1> const&) const
    {
      return _mm_load_ss(p);
    }

    BOOST_FORCEINLINE target operator()(Pointer p, Target const&) const
    {
      return do_(p, nsm::size_t<target::static_size>{});
    }
  };
} } }

#endif
