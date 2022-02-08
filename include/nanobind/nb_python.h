/// Include Python header, disable linking to pythonX_d.lib on Windows in debug mode
#if defined(_MSC_VER)
#  pragma warning(push)
// C4505: 'PySlice_GetIndicesEx': unreferenced local function has been removed (PyPy only)
#  pragma warning(disable: 4505)
#  if defined(_DEBUG) && !defined(Py_DEBUG)
#    define PYBIND11_DEBUG_MARKER
#    undef _DEBUG
#  endif
#endif

#include <Python.h>
#include <frameobject.h>
#include <pythread.h>

/* Python #defines overrides on all sorts of core functions, which
   tends to weak havok in C++ codebases that expect these to work
   like regular functions (potentially with several overloads) */
#if defined(isalnum)
#  undef isalnum
#  undef isalpha
#  undef islower
#  undef isspace
#  undef isupper
#  undef tolower
#  undef toupper
#endif

#if defined(copysign)
#  undef copysign
#endif

#if defined(_MSC_VER)
#  if defined(PYBIND11_DEBUG_MARKER)
#    define _DEBUG
#    undef PYBIND11_DEBUG_MARKER
#  endif
#  pragma warning(pop)
#endif