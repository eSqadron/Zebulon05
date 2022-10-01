// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from maestro_interfaces:msg/CurrentPositions.idl
// generated code does not contain a copyright notice

#ifndef MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__BUILDER_HPP_
#define MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "maestro_interfaces/msg/detail/current_positions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace maestro_interfaces
{

namespace msg
{

namespace builder
{

class Init_CurrentPositions_current_ang
{
public:
  Init_CurrentPositions_current_ang()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::maestro_interfaces::msg::CurrentPositions current_ang(::maestro_interfaces::msg::CurrentPositions::_current_ang_type arg)
  {
    msg_.current_ang = std::move(arg);
    return std::move(msg_);
  }

private:
  ::maestro_interfaces::msg::CurrentPositions msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::maestro_interfaces::msg::CurrentPositions>()
{
  return maestro_interfaces::msg::builder::Init_CurrentPositions_current_ang();
}

}  // namespace maestro_interfaces

#endif  // MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__BUILDER_HPP_
