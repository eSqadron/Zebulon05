// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from maestro_interfaces:msg/CurrentPositions.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "maestro_interfaces/msg/detail/current_positions__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace maestro_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void CurrentPositions_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) maestro_interfaces::msg::CurrentPositions(_init);
}

void CurrentPositions_fini_function(void * message_memory)
{
  auto typed_message = static_cast<maestro_interfaces::msg::CurrentPositions *>(message_memory);
  typed_message->~CurrentPositions();
}

size_t size_function__CurrentPositions__current_ang(const void * untyped_member)
{
  (void)untyped_member;
  return 24;
}

const void * get_const_function__CurrentPositions__current_ang(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<uint16_t, 24> *>(untyped_member);
  return &member[index];
}

void * get_function__CurrentPositions__current_ang(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<uint16_t, 24> *>(untyped_member);
  return &member[index];
}

void fetch_function__CurrentPositions__current_ang(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const uint16_t *>(
    get_const_function__CurrentPositions__current_ang(untyped_member, index));
  auto & value = *reinterpret_cast<uint16_t *>(untyped_value);
  value = item;
}

void assign_function__CurrentPositions__current_ang(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<uint16_t *>(
    get_function__CurrentPositions__current_ang(untyped_member, index));
  const auto & value = *reinterpret_cast<const uint16_t *>(untyped_value);
  item = value;
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember CurrentPositions_message_member_array[1] = {
  {
    "current_ang",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    24,  // array size
    false,  // is upper bound
    offsetof(maestro_interfaces::msg::CurrentPositions, current_ang),  // bytes offset in struct
    nullptr,  // default value
    size_function__CurrentPositions__current_ang,  // size() function pointer
    get_const_function__CurrentPositions__current_ang,  // get_const(index) function pointer
    get_function__CurrentPositions__current_ang,  // get(index) function pointer
    fetch_function__CurrentPositions__current_ang,  // fetch(index, &value) function pointer
    assign_function__CurrentPositions__current_ang,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers CurrentPositions_message_members = {
  "maestro_interfaces::msg",  // message namespace
  "CurrentPositions",  // message name
  1,  // number of fields
  sizeof(maestro_interfaces::msg::CurrentPositions),
  CurrentPositions_message_member_array,  // message members
  CurrentPositions_init_function,  // function to initialize message memory (memory has to be allocated)
  CurrentPositions_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t CurrentPositions_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &CurrentPositions_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace maestro_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<maestro_interfaces::msg::CurrentPositions>()
{
  return &::maestro_interfaces::msg::rosidl_typesupport_introspection_cpp::CurrentPositions_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, maestro_interfaces, msg, CurrentPositions)() {
  return &::maestro_interfaces::msg::rosidl_typesupport_introspection_cpp::CurrentPositions_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
