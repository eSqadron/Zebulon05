// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from walking_robot_interfaces:msg/Step.idl
// generated code does not contain a copyright notice

#ifndef WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__STRUCT_H_
#define WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Step in the package walking_robot_interfaces.
typedef struct walking_robot_interfaces__msg__Step
{
  uint8_t type;
  int16_t step_length;
  int16_t step_height;
} walking_robot_interfaces__msg__Step;

// Struct for a sequence of walking_robot_interfaces__msg__Step.
typedef struct walking_robot_interfaces__msg__Step__Sequence
{
  walking_robot_interfaces__msg__Step * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} walking_robot_interfaces__msg__Step__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__STRUCT_H_
