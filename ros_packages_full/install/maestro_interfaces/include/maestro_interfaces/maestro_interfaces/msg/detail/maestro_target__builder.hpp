// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from maestro_interfaces:msg/MaestroTarget.idl
// generated code does not contain a copyright notice

#ifndef MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__BUILDER_HPP_
#define MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "maestro_interfaces/msg/detail/maestro_target__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace maestro_interfaces
{

namespace msg
{

namespace builder
{

class Init_MaestroTarget_acceleration
{
public:
  explicit Init_MaestroTarget_acceleration(::maestro_interfaces::msg::MaestroTarget & msg)
  : msg_(msg)
  {}
  ::maestro_interfaces::msg::MaestroTarget acceleration(::maestro_interfaces::msg::MaestroTarget::_acceleration_type arg)
  {
    msg_.acceleration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::maestro_interfaces::msg::MaestroTarget msg_;
};

class Init_MaestroTarget_speed
{
public:
  explicit Init_MaestroTarget_speed(::maestro_interfaces::msg::MaestroTarget & msg)
  : msg_(msg)
  {}
  Init_MaestroTarget_acceleration speed(::maestro_interfaces::msg::MaestroTarget::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_MaestroTarget_acceleration(msg_);
  }

private:
  ::maestro_interfaces::msg::MaestroTarget msg_;
};

class Init_MaestroTarget_target_ang
{
public:
  explicit Init_MaestroTarget_target_ang(::maestro_interfaces::msg::MaestroTarget & msg)
  : msg_(msg)
  {}
  Init_MaestroTarget_speed target_ang(::maestro_interfaces::msg::MaestroTarget::_target_ang_type arg)
  {
    msg_.target_ang = std::move(arg);
    return Init_MaestroTarget_speed(msg_);
  }

private:
  ::maestro_interfaces::msg::MaestroTarget msg_;
};

class Init_MaestroTarget_channel
{
public:
  Init_MaestroTarget_channel()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MaestroTarget_target_ang channel(::maestro_interfaces::msg::MaestroTarget::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return Init_MaestroTarget_target_ang(msg_);
  }

private:
  ::maestro_interfaces::msg::MaestroTarget msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::maestro_interfaces::msg::MaestroTarget>()
{
  return maestro_interfaces::msg::builder::Init_MaestroTarget_channel();
}

}  // namespace maestro_interfaces

#endif  // MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__BUILDER_HPP_
