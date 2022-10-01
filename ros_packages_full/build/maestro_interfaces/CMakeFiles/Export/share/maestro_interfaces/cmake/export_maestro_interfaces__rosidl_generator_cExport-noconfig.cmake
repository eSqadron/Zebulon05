#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "maestro_interfaces::maestro_interfaces__rosidl_generator_c" for configuration ""
set_property(TARGET maestro_interfaces::maestro_interfaces__rosidl_generator_c APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(maestro_interfaces::maestro_interfaces__rosidl_generator_c PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmaestro_interfaces__rosidl_generator_c.so"
  IMPORTED_SONAME_NOCONFIG "libmaestro_interfaces__rosidl_generator_c.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS maestro_interfaces::maestro_interfaces__rosidl_generator_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_maestro_interfaces::maestro_interfaces__rosidl_generator_c "${_IMPORT_PREFIX}/lib/libmaestro_interfaces__rosidl_generator_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
