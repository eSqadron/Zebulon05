// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from walking_robot_interfaces:msg/Step.idl
// generated code does not contain a copyright notice
#include "walking_robot_interfaces/msg/detail/step__rosidl_typesupport_fastrtps_cpp.hpp"
#include "walking_robot_interfaces/msg/detail/step__struct.hpp"

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

namespace walking_robot_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_walking_robot_interfaces
cdr_serialize(
  const walking_robot_interfaces::msg::Step & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: type
  cdr << ros_message.type;
  // Member: step_length
  cdr << ros_message.step_length;
  // Member: step_height
  cdr << ros_message.step_height;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_walking_robot_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  walking_robot_interfaces::msg::Step & ros_message)
{
  // Member: type
  cdr >> ros_message.type;

  // Member: step_length
  cdr >> ros_message.step_length;

  // Member: step_height
  cdr >> ros_message.step_height;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_walking_robot_interfaces
get_serialized_size(
  const walking_robot_interfaces::msg::Step & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: type
  {
    size_t item_size = sizeof(ros_message.type);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: step_length
  {
    size_t item_size = sizeof(ros_message.step_length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: step_height
  {
    size_t item_size = sizeof(ros_message.step_height);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_walking_robot_interfaces
max_serialized_size_Step(
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


  // Member: type
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: step_length
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: step_height
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  return current_alignment - initial_alignment;
}

static bool _Step__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const walking_robot_interfaces::msg::Step *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Step__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<walking_robot_interfaces::msg::Step *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Step__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const walking_robot_interfaces::msg::Step *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Step__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Step(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Step__callbacks = {
  "walking_robot_interfaces::msg",
  "Step",
  _Step__cdr_serialize,
  _Step__cdr_deserialize,
  _Step__get_serialized_size,
  _Step__max_serialized_size
};

static rosidl_message_type_support_t _Step__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Step__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace walking_robot_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_walking_robot_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<walking_robot_interfaces::msg::Step>()
{
  return &walking_robot_interfaces::msg::typesupport_fastrtps_cpp::_Step__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, walking_robot_interfaces, msg, Step)() {
  return &walking_robot_interfaces::msg::typesupport_fastrtps_cpp::_Step__handle;
}

#ifdef __cplusplus
}
#endif
