// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from maestro_interfaces:msg/CurrentPositions.idl
// generated code does not contain a copyright notice

#ifndef MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__TRAITS_HPP_
#define MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "maestro_interfaces/msg/detail/current_positions__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace maestro_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const CurrentPositions & msg,
  std::ostream & out)
{
  out << "{";
  // member: current_ang
  {
    if (msg.current_ang.size() == 0) {
      out << "current_ang: []";
    } else {
      out << "current_ang: [";
      size_t pending_items = msg.current_ang.size();
      for (auto item : msg.current_ang) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CurrentPositions & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: current_ang
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current_ang.size() == 0) {
      out << "current_ang: []\n";
    } else {
      out << "current_ang:\n";
      for (auto item : msg.current_ang) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CurrentPositions & msg, bool use_flow_style = false)
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
  const maestro_interfaces::msg::CurrentPositions & msg,
  std::ostream & out, size_t indentation = 0)
{
  maestro_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use maestro_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const maestro_interfaces::msg::CurrentPositions & msg)
{
  return maestro_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<maestro_interfaces::msg::CurrentPositions>()
{
  return "maestro_interfaces::msg::CurrentPositions";
}

template<>
inline const char * name<maestro_interfaces::msg::CurrentPositions>()
{
  return "maestro_interfaces/msg/CurrentPositions";
}

template<>
struct has_fixed_size<maestro_interfaces::msg::CurrentPositions>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<maestro_interfaces::msg::CurrentPositions>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<maestro_interfaces::msg::CurrentPositions>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__TRAITS_HPP_
