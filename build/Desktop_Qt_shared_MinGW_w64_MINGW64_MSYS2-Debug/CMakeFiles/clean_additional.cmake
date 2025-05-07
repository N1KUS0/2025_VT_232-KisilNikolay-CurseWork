# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\cursework_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\cursework_autogen.dir\\ParseCache.txt"
  "cursework_autogen"
  )
endif()
