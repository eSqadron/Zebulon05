// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from maestro_interfaces:msg/CurrentPositions.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "maestro_interfaces/msg/detail/current_positions__rosidl_typesupport_introspection_c.h"
#include "maestro_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "maestro_interfaces/msg/detail/current_positions__functions.h"
#include "maestro_interfaces/msg/detail/current_positions__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  maestro_interfaces__msg__CurrentPositions__init(message_memory);
}

void maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_fini_function(void * message_memory)
{
  maestro_interfaces__msg__CurrentPositions__fini(message_memory);
}

size_t maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__size_function__CurrentPositions__current_ang(
  const void * untyped_member)
{
  (void)untyped_member;
  return 24;
}

const void * maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__get_const_function__CurrentPositions__current_ang(
  const void * untyped_member, size_t index)
{
  const uint16_t * member =
    (const uint16_t *)(untyped_member);
  return &member[index];
}

void * maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__get_function__CurrentPositions__current_ang(
  void * untyped_member, size_t index)
{
  uint16_t * member =
    (uint16_t *)(untyped_member);
  return &member[index];
}

void maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__fetch_function__CurrentPositions__current_ang(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const uint16_t * item =
    ((const uint16_t *)
    maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__get_const_function__CurrentPositions__current_ang(untyped_member, index));
  uint16_t * value =
    (uint16_t *)(untyped_value);
  *value = *item;
}

void maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__assign_function__CurrentPositions__current_ang(
  void * untyped_member, size_t index, const void * untyped_value)
{
  uint16_t * item =
    ((uint16_t *)
    maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__get_function__CurrentPositions__current_ang(untyped_member, index));
  const uint16_t * value =
    (const uint16_t *)(untyped_value);
  *item = *value;
}

static rosidl_typesupport_introspection_c__MessageMember maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_message_member_array[1] = {
  {
    "current_ang",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    24,  // array size
    false,  // is upper bound
    offsetof(maestro_interfaces__msg__CurrentPositions, current_ang),  // bytes offset in struct
    NULL,  // default value
    maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__size_function__CurrentPositions__current_ang,  // size() function pointer
    maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__get_const_function__CurrentPositions__current_ang,  // get_const(index) function pointer
    maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__get_function__CurrentPositions__current_ang,  // get(index) function pointer
    maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__fetch_function__CurrentPositions__current_ang,  // fetch(index, &value) function pointer
    maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__assign_function__CurrentPositions__current_ang,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_message_members = {
  "maestro_interfaces__msg",  // message namespace
  "CurrentPositions",  // message name
  1,  // number of fields
  sizeof(maestro_interfaces__msg__CurrentPositions),
  maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_message_member_array,  // message members
  maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_init_function,  // function to initialize message memory (memory has to be allocated)
  maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_message_type_support_handle = {
  0,
  &maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_maestro_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, maestro_interfaces, msg, CurrentPositions)() {
  if (!maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_message_type_support_handle.typesupport_identifier) {
    maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &maestro_interfaces__msg__CurrentPositions__rosidl_typesupport_introspection_c__CurrentPositions_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
