# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\Tarea2Qt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Tarea2Qt_autogen.dir\\ParseCache.txt"
  "Tarea2Qt_autogen"
  )
endif()
