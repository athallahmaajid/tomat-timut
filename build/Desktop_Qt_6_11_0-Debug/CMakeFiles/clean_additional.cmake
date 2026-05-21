# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/pomodoro_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/pomodoro_autogen.dir/ParseCache.txt"
  "pomodoro_autogen"
  )
endif()
