// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from maestro_interfaces:msg/MaestroTarget.idl
// generated code does not contain a copyright notice

#ifndef MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__FUNCTIONS_H_
#define MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "maestro_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "maestro_interfaces/msg/detail/maestro_target__struct.h"

/// Initialize msg/MaestroTarget message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * maestro_interfaces__msg__MaestroTarget
 * )) before or use
 * maestro_interfaces__msg__MaestroTarget__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
bool
maestro_interfaces__msg__MaestroTarget__init(maestro_interfaces__msg__MaestroTarget * msg);

/// Finalize msg/MaestroTarget message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
void
maestro_interfaces__msg__MaestroTarget__fini(maestro_interfaces__msg__MaestroTarget * msg);

/// Create msg/MaestroTarget message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * maestro_interfaces__msg__MaestroTarget__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
maestro_interfaces__msg__MaestroTarget *
maestro_interfaces__msg__MaestroTarget__create();

/// Destroy msg/MaestroTarget message.
/**
 * It calls
 * maestro_interfaces__msg__MaestroTarget__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
void
maestro_interfaces__msg__MaestroTarget__destroy(maestro_interfaces__msg__MaestroTarget * msg);

/// Check for msg/MaestroTarget message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
bool
maestro_interfaces__msg__MaestroTarget__are_equal(const maestro_interfaces__msg__MaestroTarget * lhs, const maestro_interfaces__msg__MaestroTarget * rhs);

/// Copy a msg/MaestroTarget message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
bool
maestro_interfaces__msg__MaestroTarget__copy(
  const maestro_interfaces__msg__MaestroTarget * input,
  maestro_interfaces__msg__MaestroTarget * output);

/// Initialize array of msg/MaestroTarget messages.
/**
 * It allocates the memory for the number of elements and calls
 * maestro_interfaces__msg__MaestroTarget__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
bool
maestro_interfaces__msg__MaestroTarget__Sequence__init(maestro_interfaces__msg__MaestroTarget__Sequence * array, size_t size);

/// Finalize array of msg/MaestroTarget messages.
/**
 * It calls
 * maestro_interfaces__msg__MaestroTarget__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
void
maestro_interfaces__msg__MaestroTarget__Sequence__fini(maestro_interfaces__msg__MaestroTarget__Sequence * array);

/// Create array of msg/MaestroTarget messages.
/**
 * It allocates the memory for the array and calls
 * maestro_interfaces__msg__MaestroTarget__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
maestro_interfaces__msg__MaestroTarget__Sequence *
maestro_interfaces__msg__MaestroTarget__Sequence__create(size_t size);

/// Destroy array of msg/MaestroTarget messages.
/**
 * It calls
 * maestro_interfaces__msg__MaestroTarget__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
void
maestro_interfaces__msg__MaestroTarget__Sequence__destroy(maestro_interfaces__msg__MaestroTarget__Sequence * array);

/// Check for msg/MaestroTarget message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
bool
maestro_interfaces__msg__MaestroTarget__Sequence__are_equal(const maestro_interfaces__msg__MaestroTarget__Sequence * lhs, const maestro_interfaces__msg__MaestroTarget__Sequence * rhs);

/// Copy an array of msg/MaestroTarget messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_maestro_interfaces
bool
maestro_interfaces__msg__MaestroTarget__Sequence__copy(
  const maestro_interfaces__msg__MaestroTarget__Sequence * input,
  maestro_interfaces__msg__MaestroTarget__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MAESTRO_INTERFACES__MSG__DETAIL__MAESTRO_TARGET__FUNCTIONS_H_
