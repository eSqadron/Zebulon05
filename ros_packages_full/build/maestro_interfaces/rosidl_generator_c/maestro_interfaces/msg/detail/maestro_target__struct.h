// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from maestro_interfaces:msg/MaestroTarget.idl
// generated code does not contain a copyright notice

#ifndef MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__STRUCT_H_
#define MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MaestroTarget in the package maestro_interfaces.
typedef struct maestro_interfaces__msg__MaestroTarget
{
  uint8_t channel;
  uint16_t target_ang;
  uint8_t speed;
  uint8_t acceleration;
} maestro_interfaces__msg__MaestroTarget;

// Struct for a sequence of maestro_interfaces__msg__MaestroTarget.
typedef struct maestro_interfaces__msg__MaestroTarget__Sequence
{
  maestro_interfaces__msg__MaestroTarget * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} maestro_interfaces__msg__MaestroTarget__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__STRUCT_H_
