// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from walking_robot_interfaces:msg/Step.idl
// generated code does not contain a copyright notice
#include "walking_robot_interfaces/msg/detail/step__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
walking_robot_interfaces__msg__Step__init(walking_robot_interfaces__msg__Step * msg)
{
  if (!msg) {
    return false;
  }
  // type
  msg->type = 0;
  // step_length
  // step_height
  return true;
}

void
walking_robot_interfaces__msg__Step__fini(walking_robot_interfaces__msg__Step * msg)
{
  if (!msg) {
    return;
  }
  // type
  // step_length
  // step_height
}

bool
walking_robot_interfaces__msg__Step__are_equal(const walking_robot_interfaces__msg__Step * lhs, const walking_robot_interfaces__msg__Step * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // type
  if (lhs->type != rhs->type) {
    return false;
  }
  // step_length
  if (lhs->step_length != rhs->step_length) {
    return false;
  }
  // step_height
  if (lhs->step_height != rhs->step_height) {
    return false;
  }
  return true;
}

bool
walking_robot_interfaces__msg__Step__copy(
  const walking_robot_interfaces__msg__Step * input,
  walking_robot_interfaces__msg__Step * output)
{
  if (!input || !output) {
    return false;
  }
  // type
  output->type = input->type;
  // step_length
  output->step_length = input->step_length;
  // step_height
  output->step_height = input->step_height;
  return true;
}

walking_robot_interfaces__msg__Step *
walking_robot_interfaces__msg__Step__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  walking_robot_interfaces__msg__Step * msg = (walking_robot_interfaces__msg__Step *)allocator.allocate(sizeof(walking_robot_interfaces__msg__Step), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(walking_robot_interfaces__msg__Step));
  bool success = walking_robot_interfaces__msg__Step__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
walking_robot_interfaces__msg__Step__destroy(walking_robot_interfaces__msg__Step * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    walking_robot_interfaces__msg__Step__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
walking_robot_interfaces__msg__Step__Sequence__init(walking_robot_interfaces__msg__Step__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  walking_robot_interfaces__msg__Step * data = NULL;

  if (size) {
    data = (walking_robot_interfaces__msg__Step *)allocator.zero_allocate(size, sizeof(walking_robot_interfaces__msg__Step), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = walking_robot_interfaces__msg__Step__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        walking_robot_interfaces__msg__Step__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
walking_robot_interfaces__msg__Step__Sequence__fini(walking_robot_interfaces__msg__Step__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      walking_robot_interfaces__msg__Step__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

walking_robot_interfaces__msg__Step__Sequence *
walking_robot_interfaces__msg__Step__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  walking_robot_interfaces__msg__Step__Sequence * array = (walking_robot_interfaces__msg__Step__Sequence *)allocator.allocate(sizeof(walking_robot_interfaces__msg__Step__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = walking_robot_interfaces__msg__Step__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
walking_robot_interfaces__msg__Step__Sequence__destroy(walking_robot_interfaces__msg__Step__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    walking_robot_interfaces__msg__Step__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
walking_robot_interfaces__msg__Step__Sequence__are_equal(const walking_robot_interfaces__msg__Step__Sequence * lhs, const walking_robot_interfaces__msg__Step__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!walking_robot_interfaces__msg__Step__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
walking_robot_interfaces__msg__Step__Sequence__copy(
  const walking_robot_interfaces__msg__Step__Sequence * input,
  walking_robot_interfaces__msg__Step__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(walking_robot_interfaces__msg__Step);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    walking_robot_interfaces__msg__Step * data =
      (walking_robot_interfaces__msg__Step *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!walking_robot_interfaces__msg__Step__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          walking_robot_interfaces__msg__Step__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!walking_robot_interfaces__msg__Step__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
