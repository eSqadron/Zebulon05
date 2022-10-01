// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from maestro_interfaces:msg/CurrentPositions.idl
// generated code does not contain a copyright notice
#include "maestro_interfaces/msg/detail/current_positions__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
maestro_interfaces__msg__CurrentPositions__init(maestro_interfaces__msg__CurrentPositions * msg)
{
  if (!msg) {
    return false;
  }
  // current_ang
  return true;
}

void
maestro_interfaces__msg__CurrentPositions__fini(maestro_interfaces__msg__CurrentPositions * msg)
{
  if (!msg) {
    return;
  }
  // current_ang
}

bool
maestro_interfaces__msg__CurrentPositions__are_equal(const maestro_interfaces__msg__CurrentPositions * lhs, const maestro_interfaces__msg__CurrentPositions * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // current_ang
  for (size_t i = 0; i < 24; ++i) {
    if (lhs->current_ang[i] != rhs->current_ang[i]) {
      return false;
    }
  }
  return true;
}

bool
maestro_interfaces__msg__CurrentPositions__copy(
  const maestro_interfaces__msg__CurrentPositions * input,
  maestro_interfaces__msg__CurrentPositions * output)
{
  if (!input || !output) {
    return false;
  }
  // current_ang
  for (size_t i = 0; i < 24; ++i) {
    output->current_ang[i] = input->current_ang[i];
  }
  return true;
}

maestro_interfaces__msg__CurrentPositions *
maestro_interfaces__msg__CurrentPositions__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  maestro_interfaces__msg__CurrentPositions * msg = (maestro_interfaces__msg__CurrentPositions *)allocator.allocate(sizeof(maestro_interfaces__msg__CurrentPositions), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(maestro_interfaces__msg__CurrentPositions));
  bool success = maestro_interfaces__msg__CurrentPositions__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
maestro_interfaces__msg__CurrentPositions__destroy(maestro_interfaces__msg__CurrentPositions * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    maestro_interfaces__msg__CurrentPositions__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
maestro_interfaces__msg__CurrentPositions__Sequence__init(maestro_interfaces__msg__CurrentPositions__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  maestro_interfaces__msg__CurrentPositions * data = NULL;

  if (size) {
    data = (maestro_interfaces__msg__CurrentPositions *)allocator.zero_allocate(size, sizeof(maestro_interfaces__msg__CurrentPositions), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = maestro_interfaces__msg__CurrentPositions__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        maestro_interfaces__msg__CurrentPositions__fini(&data[i - 1]);
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
maestro_interfaces__msg__CurrentPositions__Sequence__fini(maestro_interfaces__msg__CurrentPositions__Sequence * array)
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
      maestro_interfaces__msg__CurrentPositions__fini(&array->data[i]);
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

maestro_interfaces__msg__CurrentPositions__Sequence *
maestro_interfaces__msg__CurrentPositions__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  maestro_interfaces__msg__CurrentPositions__Sequence * array = (maestro_interfaces__msg__CurrentPositions__Sequence *)allocator.allocate(sizeof(maestro_interfaces__msg__CurrentPositions__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = maestro_interfaces__msg__CurrentPositions__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
maestro_interfaces__msg__CurrentPositions__Sequence__destroy(maestro_interfaces__msg__CurrentPositions__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    maestro_interfaces__msg__CurrentPositions__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
maestro_interfaces__msg__CurrentPositions__Sequence__are_equal(const maestro_interfaces__msg__CurrentPositions__Sequence * lhs, const maestro_interfaces__msg__CurrentPositions__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!maestro_interfaces__msg__CurrentPositions__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
maestro_interfaces__msg__CurrentPositions__Sequence__copy(
  const maestro_interfaces__msg__CurrentPositions__Sequence * input,
  maestro_interfaces__msg__CurrentPositions__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(maestro_interfaces__msg__CurrentPositions);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    maestro_interfaces__msg__CurrentPositions * data =
      (maestro_interfaces__msg__CurrentPositions *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!maestro_interfaces__msg__CurrentPositions__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          maestro_interfaces__msg__CurrentPositions__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!maestro_interfaces__msg__CurrentPositions__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
