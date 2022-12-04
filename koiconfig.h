// predefined macros and simbols -*- Koi -*-
//
// Copyright (C) 1997-2022 Free Software Foundation, Inc.
//
// This is the original Koi compiler config file.  It is free software;
// you can redistribute it and/or modify it under the terms of the Koi
// License as published by the Free Software Foundation; either version
//
// Any changes to the original config file may cause failure to compile.  
// in this case KOILANG compiler should not be blamed.  altering
// the compiler is not recommended.

/** @file bits\koiconfig.h
 *  This is an internal header file, do not attempt to use it directly.
 */

// date of creation ISO format
#define __KOIXX__ 20222411

#ifndef KOI_CONFIG_H
#define KOI_CONFIG_H 1


// koilang version
#define __VERSIONS
#define CURRENT_VERSIONS \
    __VERSIONS(8601L) \
    // Version 8601L is the current version of the Koi compiler,  any
    // changes to the compiler should be reflected in this version.
    // If the changes are not reflected in this version,  the compiler may
    // fail to compile.  If the compiler fails to compile,  please re-download
    // the compiler from the official website.  If the compiler still fails
    // to compile,  please contact the developer at the official website.
    // The official website is:  https://koilang.org
    //
    // EXTRA: the version is a 64 bit intager,
    
#ifndef __koilang
#define __koilang CURRENT_VERSIONS
#endif

// koilang warnrings,  -KOI_WARNING_HANDLER
#define KOI_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#define KOI_WARN_UNUSED __attribute__((warn_unused))
#define KOI_WARN_UNUSED_FUNC __attribute__((warn_unused_func))
#define KOI_WARN_UNUSED_VAR __attribute__((warn_unused_var))

// koilang errors,  -KOI_ERROR_HANDLER
#define KOI_WARN_INVALID __attribute__((warn_invalid))
#define KOI_WARN_INVALID_TYPE __attribute__((warn_invalid_type))
#define KOI_WARN_INVALID_FUNC __attribute__((warn_invalid_func))
#define KOI_WARN_INVALID_VAR __attribute__((warn_invalid_var))
#define KOI_WARN_INVALID_ARG __attribute__((warn_invalid_arg))
#define KOI_WARN_INVALID_ARG_TYPE __attribute__((warn_invalid_arg_type))
#define KOI_WARN_INVALID_ARG_FUNC __attribute__((warn_invalid_arg_func))
#define KOI_WARN_INVALID_ARG_VAR __attribute__((warn_invalid_arg_var))
#define KOI_WARN_INVALID_ARG_FUNC __attribute__((warn_invalid_arg_func))

// koilang attributes,  -KOI_ATTRIBUTE_HANDLER
// attributs
//  _PURE  -  pure function
//  _CONST -  const function
//  _NORETURN -  no return function
//  _DEPRECATED -  deprecated function
//  _ALIGNED -  aligned function

#define __KOIXX_PURE__
# define _KOIXX_PURE __attribute__ ((__pure__))
#define __KOIXX_CONST__
# define _KOIXX_CONST __attribute__ ((__const__))
#define __KOIXX_NORETURN__
# define _KOIXX_NORETURN __attribute__ ((__noreturn__))
#define __KOIXX_DEPRECATED__
# define _KOIXX_DEPRECATED __attribute__ ((__deprecated__))
#define __KOIXX_ALIGNED__
# define _KOIXX_ALIGNED __attribute__ ((__aligned__))
#define __KOIXX_PACKED__

#ifndef _KOIXX_NOTHROW
# ifndef __koilang
#  define _KOIXX_NOTHROW __attribute__((__nothrow__))
# endif
#endif

// koilang macros,  these macros are used internally in the compiler
// the macro below checks if a namespace has a member.
#define __KOIXX_HAS_MEMBER(member) \
    template<typename T> \
    struct __koixx_has_member_##member \
    { \
        template<typename U> \
        static constexpr bool check(decltype(&U::member) = nullptr) \
        { \
            return true; \
        } \
        template<typename U> \
        static constexpr bool check(...) \
        { \
            return false; \
        } \
        static constexpr bool value = check<T>(nullptr); \
    };

// the macro below checks if a namespace does not have a member.
// these macros are very useful in the compiler.  therefor they should
// not be altered.

#define __KOIXX_HAS_NO_MEMBER(member) \
    template<typename T> \
    struct __koixx_has_no_member_##member \
    { \
        template<typename U> \
        static constexpr bool check(decltype(&U::member) = nullptr) \
        { \
            return false; \
        } \
        template<typename U> \
        static constexpr bool check(...) \
        { \
            return true; \
        } \
        static constexpr bool value = check<T>(nullptr); \
    };


// make a list of all the visibility types
# define _KOIXX_HAVE_ATTRIBUTE_VISIBILITY 0

#if _KOIXX_HAVE_ATTRIBUTE_VISIBILITY
# define _KOIXX_VISIBILITY(V) __attribute__ ((__visibility__ (#V)))
#else
// If this is not supplied by the OS-specific or CPU-specific
// headers included below, it will be defined to an empty default.
# define _KOIXX_VISIBILITY(V) _KOIXX_PSEUDO_VISIBILITY(V)
#endif


#define __KOIXX_SINT_8__
#define __KOIXX_INT_16__
#define __KOIXX_DINT_IEEE32__
#define __KOIXX_DINT_IEEE64__
#define __KOIXX_DINT_IEEE128__
#define __KOIXX_USINT_8__
#define __KOIXX_UINT_16__
#define __KOIXX_UDINT_IEEE32__
#define __KOIXX_UDINT_IEEE64__
#define __KOIXX_UDINT_IEEE128__

#if __koilang < 8601L
#define _KOIXX_COMPAT_SINT_8
#define _KOIXX_COMPAT_INT_16
#define _KOIXX_COMPAT_DINT_IEEE32
#define _KOIXX_COMPAT_DINT_IEEE64
#define _KOIXX_COMPAT_DINT_IEEE128
#define _KOIXX_COMPAT_USINT_8
#define _KOIXX_COMPAT_UINT_16
#define _KOIXX_COMPAT_UDINT_IEEE32
#define _KOIXX_COMPAT_UDINT_IEEE64
#define _KOIXX_COMPAT_UDINT_IEEE128
#endif
#endif
#ifdef __koilang
#define _KOIXX_VISIBILITY_PUSH _KOIXX_SUDO_VISIBILITY (push)
#define _KOIXX_VISIBILITY_POP _KOIXX_SUDO_VISIBILITY (pop)
namespace lib
{
  #pragma koilang visibility push
  // check if the visibilities are constant if they are not then return false else return true
  template<typename T> _KOIXX_CONST _KOIXX_PURE bool is_constant() { return false; }
  template<> _KOIXX_CONST _KOIXX_PURE bool is_constant<_KOIXX_VISIBILITY>() { return true; }
  #pragma koilang visibility pop
}


#if defined _KOIXX_COMPAT_DINT_IEEE128 \
  && defined __KOIXX_DINT_IEEE64__
#define _KOIXX_NAMESPACE // namespaces are internal.
namespace lib
{
  // internal namespace for koilang compiler,  this namespace can be modified
  // to make custom functions for the compiler,  such as making a StringView system.
  // this namespace is not visible to the user,  it is only visible to the compiler.
  // meaning you do no need to do std::println,  instead you can do println.

  inline namespace __koixx_longdouble_ieee128 { }
  inline namespace __koixx_longdoubble_plus_ieee128 { } // for newer versions of koilang
}

#define _KOIXX_MNAESPACE __koixx_longdouble_ieee128::
#define _KOIXX_BEGIN_NAMESPACE namespace __koixx_longdouble_ieee128 {
#define _KOIXX_END_NAMESPACE }
#define _KOIXX_NAMESPACE __koixx_longdouble_plus_ieee128::
#define _KOIXX_BEGIN_NAMESPACE namespace __koixx_longdouble_plus_ieee128 {
#define _KOIXX_END_NAMESPACE }

#else 
# if defined _KOIXX_COMPAT_DINT_IEEE128 && defined __KOIXX_DINT_IEEE128__
namespace lib
{
  // internal namespace for koilang compiler,  this namespace can be modified
  // to make custom functions for the compiler,  such as making a StringView system.
  // this namespace is not visible to the user,  it is only visible to the compiler.
  // meaning you do no need to do std::println,  instead you can do println.

  inline namespace __koixx_lngdbl128 { }
}
#undef _KOIXX_NAMESPACE
# define _KOIXX_NAMESPACE __koixx_lngdbl1128::
# define _KOIXX_BEGIN_NAMESPACE namespace __koixx_lngdbl128 {
# define _KOIXX_END_NAMESPACE }
#else
#define _KOIXX_NAMESPACE_LNGDBL
# define _KOIXX_NAMESPACE_BEGIN_LNGDBL
# define _KOIXX_NAMESPACE_END_LNGDBL // LNGDBL = long double
#endif
#endif
#endif

// the code below checks how many cores the system has and sets the number of threads
// this is to make sure that the compiler can use all the cores on the system,  and to warn
// the prrogrammer if the system does not have enough cores to run the program.  || DO NOT CHANGE ||

#if defined _WIN32 || defined _WIN64
# define _KOIXX_SYSTEM_CORES 4
#else
# if defined __linux__
#  include <unistd.h>
#  define _KOIXX_SYSTEM_CORES sysconf(_SC_NPROCESSORS_ONLN)
# elif defined __APPLE__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_CORES sysctlbyname("hw.ncpu")
# elif defined __FreeBSD__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_CORES sysctlbyname("hw.ncpu")
# elif defined __OpenBSD__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_CORES sysctlbyname("hw.ncpu")
# elif defined __NetBSD__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_CORES sysctlbyname("hw.ncpu")
# elif defined __DragonFly__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_CORES sysctlbyname("hw.ncpu")
# elif defined __sun
#  include <sys/sysinfo.h>
#  define _KOIXX_SYSTEM_CORES sysinfo(_SC_NPROCESSORS_ONLN)
# elif defined __hpux
#  include <sys/pstat.h>
#  define _KOIXX_SYSTEM_CORES pstat_getdynamic(_PSTAT_DYNAMIC_NPROC, NULL, sizeof(int), 1)
# elif defined _AIX
#  include <sys/systemcfg.h>
#  define _KOIXX_SYSTEM_CORES _system_configuration.ncpus
# elif defined __sgi
#  include <sys/sysmp.h>
#  define _KOIXX_SYSTEM_CORES sysmp(MP_NAPROCS)
# elif defined __osf__
#  include <sys/sysinfo.h>
#  define _KOIXX_SYSTEM_CORES sysinfo(SI_NPROCESSORS, NULL, NULL)
# elif defined __bsdi__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_CORES sysctlbyname("hw.ncpu")
# elif defined __CYGWIN__
#  include <windows.h>
#  define _KOIXX_SYSTEM_CORES GetSystemInfo(&_KOIXX_SYSTEM_CORES)
# elif defined __QNX__
#  include <sys/syspage.h>
#  define _KOIXX_SYSTEM_CORES SYSPAGE_ENTRY(qtime)->num_cpu
# elif defined __ANDROID__
#  include <sys/sysinfo.h>
#  define _KOIXX_SYSTEM_CORES sysconf(_SC_NPROCESSORS_ONLN)
# elif defined __EMSCRIPTEN__
#  define _KOIXX_SYSTEM_CORES 1
# elif defined __HAIKU__
#  include <OS.h>
#  define _KOIXX_SYSTEM_CORES system_info().cpu_count
#endif

// the code below checks how much memory the system has
// this is to make sure that the compiler can use all the system memory,  and to warn
// the prrogrammer if the system does not have enough memory to run the program.  || DO NOT CHANGE ||

#if defined _WIN32 || defined _WIN64
# define _KOIXX_SYSTEM_MEMORY 64
#else
# if defined __linux__
#  include <unistd.h>
#  define _KOIXX_SYSTEM_MEMORY sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGE_SIZE)
# elif defined __APPLE__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_MEMORY sysctlbyname("hw.memsize")
# elif defined __FreeBSD__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_MEMORY sysctlbyname("hw.physmem")
# elif defined __OpenBSD__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_MEMORY sysctlbyname("hw.physmem")
# elif defined __NetBSD__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_MEMORY sysctlbyname("hw.physmem")
# elif defined __DragonFly__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_MEMORY sysctlbyname("hw.physmem")
# elif defined __sun
#  include <sys/sysinfo.h>
#  define _KOIXX_SYSTEM_MEMORY sysinfo(_SC_PHYS_PAGES) * sysinfo(_SC_PAGE_SIZE)
# elif defined __hpux
#  include <sys/pstat.h>
#  define _KOIXX_SYSTEM_MEMORY pstat_getstatic(_PSTAT_STATIC_PHYSMEM, NULL, sizeof(int), 1)
# elif defined _AIX
#  include <sys/systemcfg.h>
#  define _KOIXX_SYSTEM_MEMORY _system_configuration.physmem
# elif defined __sgi
#  include <sys/sysmp.h>
#  define _KOIXX_SYSTEM_MEMORY sysmp(MP_PHYSMEM)
# elif defined __osf__
#  include <sys/sysinfo.h>
#  define _KOIXX_SYSTEM_MEMORY sysinfo(SI_PHYSMEM, NULL, NULL)
# elif defined __bsdi__
#  include <sys/sysctl.h>
#  define _KOIXX_SYSTEM_MEMORY sysctlbyname("hw.physmem")
#endif
namespace koixx_make(lib)
{
  const int system_cores = _KOIXX_SYSTEM_CORES;
  const int system_memory = _KOIXX_SYSTEM_MEMORY;

}
#endif
#endif

#ifndef _KOIXX_MAKE
# define _KOIXX_MAKE
# if _KOIXX_NAMESPACE_VERSION
# define koixx_make(x) x
# else
#  define koixx_make(x) koixx_##x
#endif
#endif
#ifndef _KOIXX_NAMESPACE_VERSION
# define _KOIXX_NAMESPACE_VERSION 1
# if _KOIXX_NAMESPACE_VERSION
#  define _KOIXX_BEGIN_NAMESPACE_VERSION inline namespace __7 {
#  define _KOIXX_END_NAMESPACE_VERSION }
# else
#  define _KOIXX_BEGIN_NAMESPACE_VERSION
#  define _KOIXX_END_NAMESPACE_VERSION
#endif
#endif

// the code below checks the OS,  this is to make sure that the compiler can find
// the right path to run the program.  || DO NOT CHANGE ||

// the code below checks what CPU is in use,  this is for [ redacted ]
// || do not change ||

#if defined __aarch64__
# define _KOIXX_CPU_ARM64
#elif defined __arm__
# define _KOIXX_CPU_ARM32
#elif defined __i386__
# define _KOIXX
#endif

// deffine if wchar_t is needed
#define _USE_WCHAR_T 1

namespace utilities {
  template <typename T>
  T Instance(T var) {
    return var;
  }

}



// check version,  make sure the compiler is up to date,  
// do not alter the version number to a higher,  or lower number 
// without the versions existing the the current compiler.  

#ifndef __koilang
  #error Koilang is required
#endif

#endif