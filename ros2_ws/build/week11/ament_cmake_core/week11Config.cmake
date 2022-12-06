# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_week11_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED week11_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(week11_FOUND FALSE)
  elseif(NOT week11_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(week11_FOUND FALSE)
  endif()
  return()
endif()
set(_week11_CONFIG_INCLUDED TRUE)

# output package information
if(NOT week11_FIND_QUIETLY)
  message(STATUS "Found week11: 0.0.0 (${week11_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'week11' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${week11_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(week11_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${week11_DIR}/${_extra}")
endforeach()
