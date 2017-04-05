##===================================================================================================
##                              Copyright 2016 NumScale SAS
##
##                   Distributed under the Boost Software License, Version 1.0.
##                        See accompanying file LICENSE.txt or copy at
##                            http://www.boost.org/LICENSE_1_0.txt
##===================================================================================================

SET( SOURCES
    aligned_object.cpp
    is_aligned.cpp
    allocate.cpp
  )

make_unit( "doc.memory" ${SOURCES})
