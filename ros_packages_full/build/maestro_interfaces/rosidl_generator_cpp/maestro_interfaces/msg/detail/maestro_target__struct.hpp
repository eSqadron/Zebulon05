// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from maestro_interfaces:msg/MaestroTarget.idl
// generated code does not contain a copyright notice

#ifndef MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__STRUCT_HPP_
#define MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__maestro_interfaces__msg__MaestroTarget __attribute__((deprecated))
#else
# define DEPRECATED__maestro_interfaces__msg__MaestroTarget __declspec(deprecated)
#endif

namespace maestro_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MaestroTarget_
{
  using Type = MaestroTarget_<ContainerAllocator>;

  explicit MaestroTarget_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->channel = 0;
      this->target_ang = 0;
      this->speed = 0;
      this->acceleration = 0;
    }
  }

  explicit MaestroTarget_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->channel = 0;
      this->target_ang = 0;
      this->speed = 0;
      this->acceleration = 0;
    }
  }

  // field types and members
  using _channel_type =
    uint8_t;
  _channel_type channel;
  using _target_ang_type =
    uint16_t;
  _target_ang_type target_ang;
  using _speed_type =
    uint8_t;
  _speed_type speed;
  using _acceleration_type =
    uint8_t;
  _acceleration_type acceleration;

  // setters for named parameter idiom
  Type & set__channel(
    const uint8_t & _arg)
  {
    this->channel = _arg;
    return *this;
  }
  Type & set__target_ang(
    const uint16_t & _arg)
  {
    this->target_ang = _arg;
    return *this;
  }
  Type & set__speed(
    const uint8_t & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__acceleration(
    const uint8_t & _arg)
  {
    this->acceleration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    maestro_interfaces::msg::MaestroTarget_<ContainerAllocator> *;
  using ConstRawPtr =
    const maestro_interfaces::msg::MaestroTarget_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<maestro_interfaces::msg::MaestroTarget_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<maestro_interfaces::msg::MaestroTarget_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      maestro_interfaces::msg::MaestroTarget_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<maestro_interfaces::msg::MaestroTarget_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      maestro_interfaces::msg::MaestroTarget_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<maestro_interfaces::msg::MaestroTarget_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<maestro_interfaces::msg::MaestroTarget_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<maestro_interfaces::msg::MaestroTarget_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__maestro_interfaces__msg__MaestroTarget
    std::shared_ptr<maestro_interfaces::msg::MaestroTarget_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__maestro_interfaces__msg__MaestroTarget
    std::shared_ptr<maestro_interfaces::msg::MaestroTarget_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MaestroTarget_ & other) const
  {
    if (this->channel != other.channel) {
      return false;
    }
    if (this->target_ang != other.target_ang) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->acceleration != other.acceleration) {
      return false;
    }
    return true;
  }
  bool operator!=(const MaestroTarget_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MaestroTarget_

// alias to use template instance with default allocator
using MaestroTarget =
  maestro_interfaces::msg::MaestroTarget_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace maestro_interfaces

#endif  // MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__STRUCT_HPP_
