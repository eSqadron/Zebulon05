#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "walking_robot_interfaces::walking_robot_interfaces__rosidl_generator_py" for configuration ""
set_property(TARGET walking_robot_interfaces::walking_robot_interfaces__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(walking_robot_interfaces::walking_robot_interfaces__rosidl_generator_py PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libwalking_robot_interfaces__rosidl_generator_py.so"
  IMPORTED_SONAME_NOCONFIG "libwalking_robot_interfaces__rosidl_generator_py.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS walking_robot_interfaces::walking_robot_interfaces__rosidl_generator_py )
list(APPEND _IMPORT_CHECK_FILES_FOR_walking_robot_interfaces::walking_robot_interfaces__rosidl_generator_py "${_IMPORT_PREFIX}/lib/libwalking_robot_interfaces__rosidl_generator_py.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
