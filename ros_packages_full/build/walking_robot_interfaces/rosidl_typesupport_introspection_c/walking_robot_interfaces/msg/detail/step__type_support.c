// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from walking_robot_interfaces:msg/Step.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "walking_robot_interfaces/msg/detail/step__rosidl_typesupport_introspection_c.h"
#include "walking_robot_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "walking_robot_interfaces/msg/detail/step__functions.h"
#include "walking_robot_interfaces/msg/detail/step__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  walking_robot_interfaces__msg__Step__init(message_memory);
}

void walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_fini_function(void * message_memory)
{
  walking_robot_interfaces__msg__Step__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_message_member_array[3] = {
  {
    "type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(walking_robot_interfaces__msg__Step, type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "step_length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(walking_robot_interfaces__msg__Step, step_length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "step_height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(walking_robot_interfaces__msg__Step, step_height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_message_members = {
  "walking_robot_interfaces__msg",  // message namespace
  "Step",  // message name
  3,  // number of fields
  sizeof(walking_robot_interfaces__msg__Step),
  walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_message_member_array,  // message members
  walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_init_function,  // function to initialize message memory (memory has to be allocated)
  walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_message_type_support_handle = {
  0,
  &walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_walking_robot_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, walking_robot_interfaces, msg, Step)() {
  if (!walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_message_type_support_handle.typesupport_identifier) {
    walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &walking_robot_interfaces__msg__Step__rosidl_typesupport_introspection_c__Step_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
