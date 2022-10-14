// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from walking_robot_interfaces:msg/Step.idl
// generated code does not contain a copyright notice

#ifndef WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__TRAITS_HPP_
#define WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "walking_robot_interfaces/msg/detail/step__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace walking_robot_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Step & msg,
  std::ostream & out)
{
  out << "{";
  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: step_length
  {
    out << "step_length: ";
    rosidl_generator_traits::value_to_yaml(msg.step_length, out);
    out << ", ";
  }

  // member: step_height
  {
    out << "step_height: ";
    rosidl_generator_traits::value_to_yaml(msg.step_height, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Step & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: step_length
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step_length: ";
    rosidl_generator_traits::value_to_yaml(msg.step_length, out);
    out << "\n";
  }

  // member: step_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "step_height: ";
    rosidl_generator_traits::value_to_yaml(msg.step_height, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Step & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace walking_robot_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use walking_robot_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const walking_robot_interfaces::msg::Step & msg,
  std::ostream & out, size_t indentation = 0)
{
  walking_robot_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use walking_robot_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const walking_robot_interfaces::msg::Step & msg)
{
  return walking_robot_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<walking_robot_interfaces::msg::Step>()
{
  return "walking_robot_interfaces::msg::Step";
}

template<>
inline const char * name<walking_robot_interfaces::msg::Step>()
{
  return "walking_robot_interfaces/msg/Step";
}

template<>
struct has_fixed_size<walking_robot_interfaces::msg::Step>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<walking_robot_interfaces::msg::Step>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<walking_robot_interfaces::msg::Step>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__TRAITS_HPP_
