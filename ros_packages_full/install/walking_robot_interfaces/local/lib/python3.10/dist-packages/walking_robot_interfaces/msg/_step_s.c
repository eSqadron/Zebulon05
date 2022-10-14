// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from walking_robot_interfaces:msg/Step.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "walking_robot_interfaces/msg/detail/step__struct.h"
#include "walking_robot_interfaces/msg/detail/step__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool walking_robot_interfaces__msg__step__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("walking_robot_interfaces.msg._step.Step", full_classname_dest, 39) == 0);
  }
  walking_robot_interfaces__msg__Step * ros_message = _ros_message;
  {  // type
    PyObject * field = PyObject_GetAttrString(_pymsg, "type");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->type = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // step_length
    PyObject * field = PyObject_GetAttrString(_pymsg, "step_length");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->step_length = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // step_height
    PyObject * field = PyObject_GetAttrString(_pymsg, "step_height");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->step_height = (int16_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * walking_robot_interfaces__msg__step__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Step */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("walking_robot_interfaces.msg._step");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Step");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  walking_robot_interfaces__msg__Step * ros_message = (walking_robot_interfaces__msg__Step *)raw_ros_message;
  {  // type
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->type);
    {
      int rc = PyObject_SetAttrString(_pymessage, "type", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // step_length
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->step_length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "step_length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // step_height
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->step_height);
    {
      int rc = PyObject_SetAttrString(_pymessage, "step_height", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
