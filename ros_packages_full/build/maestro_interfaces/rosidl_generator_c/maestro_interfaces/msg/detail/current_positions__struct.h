// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from maestro_interfaces:msg/CurrentPositions.idl
// generated code does not contain a copyright notice

#ifndef MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__STRUCT_H_
#define MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/CurrentPositions in the package maestro_interfaces.
typedef struct maestro_interfaces__msg__CurrentPositions
{
  uint16_t current_ang[24];
} maestro_interfaces__msg__CurrentPositions;

// Struct for a sequence of maestro_interfaces__msg__CurrentPositions.
typedef struct maestro_interfaces__msg__CurrentPositions__Sequence
{
  maestro_interfaces__msg__CurrentPositions * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} maestro_interfaces__msg__CurrentPositions__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__STRUCT_H_
