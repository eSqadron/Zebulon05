// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from maestro_interfaces:msg/MaestroTarget.idl
// generated code does not contain a copyright notice
#include "maestro_interfaces/msg/detail/maestro_target__rosidl_typesupport_fastrtps_cpp.hpp"
#include "maestro_interfaces/msg/detail/maestro_target__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace maestro_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_maestro_interfaces
cdr_serialize(
  const maestro_interfaces::msg::MaestroTarget & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: channel
  cdr << ros_message.channel;
  // Member: target_ang
  cdr << ros_message.target_ang;
  // Member: speed
  cdr << ros_message.speed;
  // Member: acceleration
  cdr << ros_message.acceleration;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_maestro_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  maestro_interfaces::msg::MaestroTarget & ros_message)
{
  // Member: channel
  cdr >> ros_message.channel;

  // Member: target_ang
  cdr >> ros_message.target_ang;

  // Member: speed
  cdr >> ros_message.speed;

  // Member: acceleration
  cdr >> ros_message.acceleration;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_maestro_interfaces
get_serialized_size(
  const maestro_interfaces::msg::MaestroTarget & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: channel
  {
    size_t item_size = sizeof(ros_message.channel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_ang
  {
    size_t item_size = sizeof(ros_message.target_ang);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: speed
  {
    size_t item_size = sizeof(ros_message.speed);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: acceleration
  {
    size_t item_size = sizeof(ros_message.acceleration);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_maestro_interfaces
max_serialized_size_MaestroTarget(
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


  // Member: channel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: target_ang
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: speed
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: acceleration
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _MaestroTarget__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const maestro_interfaces::msg::MaestroTarget *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MaestroTarget__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<maestro_interfaces::msg::MaestroTarget *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MaestroTarget__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const maestro_interfaces::msg::MaestroTarget *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MaestroTarget__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_MaestroTarget(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _MaestroTarget__callbacks = {
  "maestro_interfaces::msg",
  "MaestroTarget",
  _MaestroTarget__cdr_serialize,
  _MaestroTarget__cdr_deserialize,
  _MaestroTarget__get_serialized_size,
  _MaestroTarget__max_serialized_size
};

static rosidl_message_type_support_t _MaestroTarget__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MaestroTarget__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace maestro_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_maestro_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<maestro_interfaces::msg::MaestroTarget>()
{
  return &maestro_interfaces::msg::typesupport_fastrtps_cpp::_MaestroTarget__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, maestro_interfaces, msg, MaestroTarget)() {
  return &maestro_interfaces::msg::typesupport_fastrtps_cpp::_MaestroTarget__handle;
}

#ifdef __cplusplus
}
#endif
