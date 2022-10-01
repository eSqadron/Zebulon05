// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from maestro_interfaces:msg/CurrentPositions.idl
// generated code does not contain a copyright notice

#ifndef MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__STRUCT_HPP_
#define MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__maestro_interfaces__msg__CurrentPositions __attribute__((deprecated))
#else
# define DEPRECATED__maestro_interfaces__msg__CurrentPositions __declspec(deprecated)
#endif

namespace maestro_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CurrentPositions_
{
  using Type = CurrentPositions_<ContainerAllocator>;

  explicit CurrentPositions_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint16_t, 24>::iterator, uint16_t>(this->current_ang.begin(), this->current_ang.end(), 0);
    }
  }

  explicit CurrentPositions_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : current_ang(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint16_t, 24>::iterator, uint16_t>(this->current_ang.begin(), this->current_ang.end(), 0);
    }
  }

  // field types and members
  using _current_ang_type =
    std::array<uint16_t, 24>;
  _current_ang_type current_ang;

  // setters for named parameter idiom
  Type & set__current_ang(
    const std::array<uint16_t, 24> & _arg)
  {
    this->current_ang = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    maestro_interfaces::msg::CurrentPositions_<ContainerAllocator> *;
  using ConstRawPtr =
    const maestro_interfaces::msg::CurrentPositions_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<maestro_interfaces::msg::CurrentPositions_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<maestro_interfaces::msg::CurrentPositions_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      maestro_interfaces::msg::CurrentPositions_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<maestro_interfaces::msg::CurrentPositions_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      maestro_interfaces::msg::CurrentPositions_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<maestro_interfaces::msg::CurrentPositions_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<maestro_interfaces::msg::CurrentPositions_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<maestro_interfaces::msg::CurrentPositions_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__maestro_interfaces__msg__CurrentPositions
    std::shared_ptr<maestro_interfaces::msg::CurrentPositions_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__maestro_interfaces__msg__CurrentPositions
    std::shared_ptr<maestro_interfaces::msg::CurrentPositions_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CurrentPositions_ & other) const
  {
    if (this->current_ang != other.current_ang) {
      return false;
    }
    return true;
  }
  bool operator!=(const CurrentPositions_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CurrentPositions_

// alias to use template instance with default allocator
using CurrentPositions =
  maestro_interfaces::msg::CurrentPositions_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace maestro_interfaces

#endif  // MAESTRO_INTERFACES__MSG__DETAIL__CURRENT_POSITIONS__STRUCT_HPP_
