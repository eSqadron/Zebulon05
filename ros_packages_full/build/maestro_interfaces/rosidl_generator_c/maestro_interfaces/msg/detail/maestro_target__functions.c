// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from maestro_interfaces:msg/MaestroTarget.idl
// generated code does not contain a copyright notice
#include "maestro_interfaces/msg/detail/maestro_target__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
maestro_interfaces__msg__MaestroTarget__init(maestro_interfaces__msg__MaestroTarget * msg)
{
  if (!msg) {
    return false;
  }
  // channel
  // target_ang
  // speed
  // acceleration
  return true;
}

void
maestro_interfaces__msg__MaestroTarget__fini(maestro_interfaces__msg__MaestroTarget * msg)
{
  if (!msg) {
    return;
  }
  // channel
  // target_ang
  // speed
  // acceleration
}

bool
maestro_interfaces__msg__MaestroTarget__are_equal(const maestro_interfaces__msg__MaestroTarget * lhs, const maestro_interfaces__msg__MaestroTarget * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // channel
  if (lhs->channel != rhs->channel) {
    return false;
  }
  // target_ang
  if (lhs->target_ang != rhs->target_ang) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // acceleration
  if (lhs->acceleration != rhs->acceleration) {
    return false;
  }
  return true;
}

bool
maestro_interfaces__msg__MaestroTarget__copy(
  const maestro_interfaces__msg__MaestroTarget * input,
  maestro_interfaces__msg__MaestroTarget * output)
{
  if (!input || !output) {
    return false;
  }
  // channel
  output->channel = input->channel;
  // target_ang
  output->target_ang = input->target_ang;
  // speed
  output->speed = input->speed;
  // acceleration
  output->acceleration = input->acceleration;
  return true;
}

maestro_interfaces__msg__MaestroTarget *
maestro_interfaces__msg__MaestroTarget__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  maestro_interfaces__msg__MaestroTarget * msg = (maestro_interfaces__msg__MaestroTarget *)allocator.allocate(sizeof(maestro_interfaces__msg__MaestroTarget), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(maestro_interfaces__msg__MaestroTarget));
  bool success = maestro_interfaces__msg__MaestroTarget__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
maestro_interfaces__msg__MaestroTarget__destroy(maestro_interfaces__msg__MaestroTarget * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    maestro_interfaces__msg__MaestroTarget__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
maestro_interfaces__msg__MaestroTarget__Sequence__init(maestro_interfaces__msg__MaestroTarget__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  maestro_interfaces__msg__MaestroTarget * data = NULL;

  if (size) {
    data = (maestro_interfaces__msg__MaestroTarget *)allocator.zero_allocate(size, sizeof(maestro_interfaces__msg__MaestroTarget), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = maestro_interfaces__msg__MaestroTarget__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        maestro_interfaces__msg__MaestroTarget__fini(&data[i - 1]);
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
maestro_interfaces__msg__MaestroTarget__Sequence__fini(maestro_interfaces__msg__MaestroTarget__Sequence * array)
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
      maestro_interfaces__msg__MaestroTarget__fini(&array->data[i]);
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

maestro_interfaces__msg__MaestroTarget__Sequence *
maestro_interfaces__msg__MaestroTarget__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  maestro_interfaces__msg__MaestroTarget__Sequence * array = (maestro_interfaces__msg__MaestroTarget__Sequence *)allocator.allocate(sizeof(maestro_interfaces__msg__MaestroTarget__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = maestro_interfaces__msg__MaestroTarget__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
maestro_interfaces__msg__MaestroTarget__Sequence__destroy(maestro_interfaces__msg__MaestroTarget__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    maestro_interfaces__msg__MaestroTarget__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
maestro_interfaces__msg__MaestroTarget__Sequence__are_equal(const maestro_interfaces__msg__MaestroTarget__Sequence * lhs, const maestro_interfaces__msg__MaestroTarget__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!maestro_interfaces__msg__MaestroTarget__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
maestro_interfaces__msg__MaestroTarget__Sequence__copy(
  const maestro_interfaces__msg__MaestroTarget__Sequence * input,
  maestro_interfaces__msg__MaestroTarget__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(maestro_interfaces__msg__MaestroTarget);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    maestro_interfaces__msg__MaestroTarget * data =
      (maestro_interfaces__msg__MaestroTarget *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!maestro_interfaces__msg__MaestroTarget__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          maestro_interfaces__msg__MaestroTarget__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!maestro_interfaces__msg__MaestroTarget__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
