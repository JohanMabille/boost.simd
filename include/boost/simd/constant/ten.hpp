//==================================================================================================
/*!
  @file

  @copyright 2016 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_SIMD_CONSTANT_TEN_HPP_INCLUDED
#define BOOST_SIMD_CONSTANT_TEN_HPP_INCLUDED



  /*!
  @ingroup group-constant
  @defgroup constant-Ten Ten (function object)

    Generates a value of the chosen type which all bits are set to 1.

    @headerref{<boost/simd/constant/ten.hpp>}

    @par Description

    1.  @code
        template<typename T> auto ten();
        @endcode

    2.  @code
        template<typename T> auto ten( boost::simd::as_<T> const& target );
        @endcode

    1. and 2.  return a value of type @c T containing the Ten constant.


    @par Parameters

    | Name                | Description                                                         |
    |--------------------:|:--------------------------------------------------------------------|
    | **target**          | a [placeholder](@ref type-as) value encapsulating the constant type |

    @par Return Value
    1.  A value of type @c T so that:
    @code
    T r = Ten<T>();
    @endcode


    2.  A value of type @c T so that:
    @code
    T x, r = Ten( boost::simd::as(x));
    @endcode
    is equivalent to:
    @code
    T r = Ten<T>();
    @endcode

    @par Requirements
    - **T** models Vectorizable
  **/

#include <boost/simd/constant/scalar/ten.hpp>
#include <boost/simd/constant/simd/ten.hpp>

#endif
