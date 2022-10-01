// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from maestro_interfaces:msg/MaestroTarget.idl
// generated code does not contain a copyright notice
#include "maestro_interfaces/msg/detail/maestro_target__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "maestro_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "maestro_interfaces/msg/detail/maestro_target__struct.h"
#include "maestro_interfaces/msg/detail/maestro_target__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _MaestroTarget__ros_msg_type = maestro_interfaces__msg__MaestroTarget;

static bool _MaestroTarget__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _MaestroTarget__ros_msg_type * ros_message = static_cast<const _MaestroTarget__ros_msg_type *>(untyped_ros_message);
  // Field name: channel
  {
    cdr << ros_message->channel;
  }

  // Field name: target_ang
  {
    cdr << ros_message->target_ang;
  }

  // Field name: speed
  {
    cdr << ros_message->speed;
  }

  // Field name: acceleration
  {
    cdr << ros_message->acceleration;
  }

  return true;
}

static bool _MaestroTarget__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _MaestroTarget__ros_msg_type * ros_message = static_cast<_MaestroTarget__ros_msg_type *>(untyped_ros_message);
  // Field name: channel
  {
    cdr >> ros_message->channel;
  }

  // Field name: target_ang
  {
    cdr >> ros_message->target_ang;
  }

  // Field name: speed
  {
    cdr >> ros_message->speed;
  }

  // Field name: acceleration
  {
    cdr >> ros_message->acceleration;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_maestro_interfaces
size_t get_serialized_size_maestro_interfaces__msg__MaestroTarget(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MaestroTarget__ros_msg_type * ros_message = static_cast<const _MaestroTarget__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name channel
  {
    size_t item_size = sizeof(ros_message->channel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name target_ang
  {
    size_t item_size = sizeof(ros_message->target_ang);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name speed
  {
    size_t item_size = sizeof(ros_message->speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name acceleration
  {
    size_t item_size = sizeof(ros_message->acceleration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _MaestroTarget__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_maestro_interfaces__msg__MaestroTarget(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_maestro_interfaces
size_t max_serialized_size_maestro_interfaces__msg__MaestroTarget(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: channel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: target_ang
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: acceleration
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _MaestroTarget__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_maestro_interfaces__msg__MaestroTarget(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MaestroTarget = {
  "maestro_interfaces::msg",
  "MaestroTarget",
  _MaestroTarget__cdr_serialize,
  _MaestroTarget__cdr_deserialize,
  _MaestroTarget__get_serialized_size,
  _MaestroTarget__max_serialized_size
};

static rosidl_message_type_support_t _MaestroTarget__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MaestroTarget,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, maestro_interfaces, msg, MaestroTarget)() {
  return &_MaestroTarget__type_support;
}

#if defined(__cplusplus)
}
#endif
