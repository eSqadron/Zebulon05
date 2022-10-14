// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from walking_robot_interfaces:msg/Step.idl
// generated code does not contain a copyright notice

#ifndef WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__STRUCT_HPP_
#define WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__walking_robot_interfaces__msg__Step __attribute__((deprecated))
#else
# define DEPRECATED__walking_robot_interfaces__msg__Step __declspec(deprecated)
#endif

namespace walking_robot_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Step_
{
  using Type = Step_<ContainerAllocator>;

  explicit Step_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->type = 0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->type = 0;
      this->step_length = 0;
      this->step_height = 0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->step_length = 0;
      this->step_height = 0;
    }
  }

  explicit Step_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::DEFAULTS_ONLY == _init)
    {
      this->type = 0;
    } else if (rosidl_runtime_cpp::MessageInitialization::ZERO == _init) {
      this->type = 0;
      this->step_length = 0;
      this->step_height = 0;
    }
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->step_length = 0;
      this->step_height = 0;
    }
  }

  // field types and members
  using _type_type =
    uint8_t;
  _type_type type;
  using _step_length_type =
    int16_t;
  _step_length_type step_length;
  using _step_height_type =
    int16_t;
  _step_height_type step_height;

  // setters for named parameter idiom
  Type & set__type(
    const uint8_t & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__step_length(
    const int16_t & _arg)
  {
    this->step_length = _arg;
    return *this;
  }
  Type & set__step_height(
    const int16_t & _arg)
  {
    this->step_height = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    walking_robot_interfaces::msg::Step_<ContainerAllocator> *;
  using ConstRawPtr =
    const walking_robot_interfaces::msg::Step_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<walking_robot_interfaces::msg::Step_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<walking_robot_interfaces::msg::Step_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      walking_robot_interfaces::msg::Step_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<walking_robot_interfaces::msg::Step_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      walking_robot_interfaces::msg::Step_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<walking_robot_interfaces::msg::Step_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<walking_robot_interfaces::msg::Step_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<walking_robot_interfaces::msg::Step_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__walking_robot_interfaces__msg__Step
    std::shared_ptr<walking_robot_interfaces::msg::Step_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__walking_robot_interfaces__msg__Step
    std::shared_ptr<walking_robot_interfaces::msg::Step_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Step_ & other) const
  {
    if (this->type != other.type) {
      return false;
    }
    if (this->step_length != other.step_length) {
      return false;
    }
    if (this->step_height != other.step_height) {
      return false;
    }
    return true;
  }
  bool operator!=(const Step_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Step_

// alias to use template instance with default allocator
using Step =
  walking_robot_interfaces::msg::Step_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace walking_robot_interfaces

#endif  // WALKING_ROBOT_INTERFACES__MSG__DETAIL__STEP__STRUCT_HPP_
