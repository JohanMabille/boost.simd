//==================================================================================================
/*!
  @file

  @copyright 2012-2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_DEFINITION_LOG_2HI_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_DEFINITION_LOG_2HI_HPP_INCLUDED

#include <boost/simd/detail/brigand.hpp>
#include <boost/simd/detail/dispatch.hpp>
#include <boost/simd/detail/constant_traits.hpp>
#include <boost/dispatch/function/make_callable.hpp>
#include <boost/dispatch/hierarchy/functions.hpp>
#include <boost/dispatch/as.hpp>

namespace boost { namespace simd
{
  namespace tag
  {
    struct log_2hi_ : boost::dispatch::constant_value_<log_2hi_>
    {
      BOOST_DISPATCH_MAKE_CALLABLE(ext,log_2hi_,boost::dispatch::constant_value_<log_2hi_>);
      BOOST_SIMD_REGISTER_CONSTANT(0, 0x3f318000UL, 0x3fe62e42fee00000ULL);
    };
  }

  namespace ext
  {
    BOOST_DISPATCH_FUNCTION_DECLARATION(tag,log_2hi_);
  }

  namespace functional
  {
    BOOST_DISPATCH_CALLABLE_DEFINITION(tag::log_2hi_,log_2hi);
  }

  template<typename T> BOOST_FORCEINLINE auto Log_2hi() BOOST_NOEXCEPT
  -> decltype(functional::log_2hi( boost::dispatch::as_<T>{}))
  {
    return functional::log_2hi( boost::dispatch::as_<T>{} );
  }
} }

#endif