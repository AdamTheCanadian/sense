/* ----- core/safe_assert.h -----

  Used for asserts in debug mode and exiting the program gracefully
  If you use assert() from <assert.h> or <cassert> and an assert is raised the
  program just ends, and no destructors are called. This way we get the assert 
  to raise, and we exit the program calling destructors.

*/

#ifndef __ATC_CORE_SAFE_ASSERT_H__
#define __ATC_CORE_SAFE_ASSERT_H__

#include <iostream>

#ifndef NDEBUG
#define ASSERT(condition, message)                                       \
  do                                                                     \
  {                                                                      \
    if (!(condition))                                                    \
    {                                                                    \
      std::cerr << "Assertion `" #condition "` failed in " << __FILE__   \
                << " line " << __LINE__ << ": " << message << std::endl; \
      exit(EXIT_FAILURE);                                                \
    }                                                                    \
  } while (false)
#else
#define ASSERT(condition, message) \
  do                               \
  {                                \
  } while (false)
#endif

#endif