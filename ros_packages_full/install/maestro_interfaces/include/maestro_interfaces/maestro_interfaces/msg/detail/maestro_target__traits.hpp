// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from maestro_interfaces:msg/MaestroTarget.idl
// generated code does not contain a copyright notice

#ifndef MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__TRAITS_HPP_
#define MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "maestro_interfaces/msg/detail/maestro_target__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace maestro_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const MaestroTarget & msg,
  std::ostream & out)
{
  out << "{";
  // member: channel
  {
    out << "channel: ";
    rosidl_generator_traits::value_to_yaml(msg.channel, out);
    out << ", ";
  }

  // member: target_ang
  {
    out << "target_ang: ";
    rosidl_generator_traits::value_to_yaml(msg.target_ang, out);
    out << ", ";
  }

  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << ", ";
  }

  // member: acceleration
  {
    out << "acceleration: ";
    rosidl_generator_traits::value_to_yaml(msg.acceleration, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MaestroTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: channel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "channel: ";
    rosidl_generator_traits::value_to_yaml(msg.channel, out);
    out << "\n";
  }

  // member: target_ang
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target_ang: ";
    rosidl_generator_traits::value_to_yaml(msg.target_ang, out);
    out << "\n";
  }

  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }

  // member: acceleration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "acceleration: ";
    rosidl_generator_traits::value_to_yaml(msg.acceleration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MaestroTarget & msg, bool use_flow_style = false)
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

}  // namespace maestro_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use maestro_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const maestro_interfaces::msg::MaestroTarget & msg,
  std::ostream & out, size_t indentation = 0)
{
  maestro_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use maestro_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const maestro_interfaces::msg::MaestroTarget & msg)
{
  return maestro_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<maestro_interfaces::msg::MaestroTarget>()
{
  return "maestro_interfaces::msg::MaestroTarget";
}

template<>
inline const char * name<maestro_interfaces::msg::MaestroTarget>()
{
  return "maestro_interfaces/msg/MaestroTarget";
}

template<>
struct has_fixed_size<maestro_interfaces::msg::MaestroTarget>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<maestro_interfaces::msg::MaestroTarget>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<maestro_interfaces::msg::MaestroTarget>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__TRAITS_HPP_
