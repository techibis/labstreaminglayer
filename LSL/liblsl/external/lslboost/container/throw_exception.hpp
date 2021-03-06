//////////////////////////////////////////////////////////////////////////////
//
// (C) Copyright Ion Gaztanaga 2012-2013. Distributed under the Boost
// Software License, Version 1.0. (See accompanying file
// LICENSE_1_0.txt or copy at http://www.lslboost.org/LICENSE_1_0.txt)
//
// See http://www.lslboost.org/libs/container for documentation.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef BOOST_CONTAINER_THROW_EXCEPTION_HPP
#define BOOST_CONTAINER_THROW_EXCEPTION_HPP

#include <lslboost/container/detail/config_begin.hpp>
#include <lslboost/container/detail/workaround.hpp>

#if defined(_MSC_VER)
#  pragma once
#endif

#ifndef BOOST_NO_EXCEPTIONS
   #include <stdexcept> //for std exception types
   #include <new>       //for std::bad_alloc
#else
   #include <lslboost/assert.hpp>
   #include <cstdlib>   //for std::abort
#endif

namespace lslboost {
namespace container {

#if defined(BOOST_CONTAINER_USER_DEFINED_THROW_CALLBACKS)
   //The user must provide definitions for the following functions

   void throw_bad_alloc();

   void throw_out_of_range(const char* str);

   void throw_length_error(const char* str);

   void throw_logic_error(const char* str);

   void throw_runtime_error(const char* str);

#elif defined(BOOST_NO_EXCEPTIONS)

   inline void throw_bad_alloc()
   {
      BOOST_ASSERT(!"lslboost::container bad_alloc thrown");
      std::abort();
   }

   inline void throw_out_of_range(const char* str)
   {
      BOOST_ASSERT_MSG(!"lslboost::container out_of_range thrown", str);
      std::abort();
   }

   inline void throw_length_error(const char* str)
   {
      BOOST_ASSERT_MSG(!"lslboost::container length_error thrown", str);
      std::abort();
   }

   inline void throw_logic_error(const char* str)
   {
      BOOST_ASSERT_MSG(!"lslboost::container logic_error thrown", str);
      std::abort();
   }

   inline void throw_runtime_error(const char* str)
   {
      BOOST_ASSERT_MSG(!"lslboost::container runtime_error thrown", str);
      std::abort();
   }

#else //defined(BOOST_NO_EXCEPTIONS)

   inline void throw_bad_alloc()
   {
      throw std::bad_alloc();
   }

   inline void throw_out_of_range(const char* str)
   {
      throw std::out_of_range(str);
   }

   inline void throw_length_error(const char* str)
   {
      throw std::length_error(str);
   }

   inline void throw_logic_error(const char* str)
   {
      throw std::logic_error(str);
   }

   inline void throw_runtime_error(const char* str)
   {
      throw std::runtime_error(str);
   }

#endif

}}  //namespace lslboost { namespace container {

#include <lslboost/container/detail/config_end.hpp>

#endif //#ifndef BOOST_CONTAINER_THROW_EXCEPTION_HPP
