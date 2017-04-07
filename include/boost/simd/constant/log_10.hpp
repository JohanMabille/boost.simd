//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_LOG_10_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_LOG_10_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Log_10 Log_10 (function object)

    Generates a value of the chosen type which all bits are set to 1.

    @headerref{<boost/simd/constant/log_10.hpp>}

    @par Description

    1.  @code
        template<typename T> auto log_10();
        @endcode

    2.  @code
        template<typename T> auto log_10( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Log_10 constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Log_10<T>();
    @endcode
    is similar to:
    @code
      r =  T(2.302585092994045684017991454684364207601101488628773);
    @endcode

    2.  A value of type @c T so that:
    @code
    T x, r = Log_10( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Log_10<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/log_10.hpp>
#include <boost/simd/constant/simd/log_10.hpp>

#endif
