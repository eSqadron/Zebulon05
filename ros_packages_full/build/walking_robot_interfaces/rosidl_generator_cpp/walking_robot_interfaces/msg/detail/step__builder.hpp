// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from walking_robot_interfaces:msg/Step.idl
// generated code does not contain a copyright notice

#ifndef WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__BUILDER_HPP_
#define WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "walking_robot_interfaces/msg/detail/step__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace walking_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Step_step_height
{
public:
  explicit Init_Step_step_height(::walking_robot_interfaces::msg::Step & msg)
  : msg_(msg)
  {}
  ::walking_robot_interfaces::msg::Step step_height(::walking_robot_interfaces::msg::Step::_step_height_type arg)
  {
    msg_.step_height = std::move(arg);
    return std::move(msg_);
  }

private:
  ::walking_robot_interfaces::msg::Step msg_;
};

class Init_Step_step_length
{
public:
  explicit Init_Step_step_length(::walking_robot_interfaces::msg::Step & msg)
  : msg_(msg)
  {}
  Init_Step_step_height step_length(::walking_robot_interfaces::msg::Step::_step_length_type arg)
  {
    msg_.step_length = std::move(arg);
    return Init_Step_step_height(msg_);
  }

private:
  ::walking_robot_interfaces::msg::Step msg_;
};

class Init_Step_type
{
public:
  Init_Step_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Step_step_length type(::walking_robot_interfaces::msg::Step::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Step_step_length(msg_);
  }

private:
  ::walking_robot_interfaces::msg::Step msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::walking_robot_interfaces::msg::Step>()
{
  return walking_robot_interfaces::msg::builder::Init_Step_type();
}

}  // namespace walking_robot_interfaces

#endif  // WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__BUILDER_HPP_
