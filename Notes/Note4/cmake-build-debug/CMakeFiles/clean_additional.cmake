# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Note4_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Note4_autogen.dir\\ParseCache.txt"
  "Note4_autogen"
  )
endif()
