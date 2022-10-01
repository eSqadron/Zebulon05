# generated from rosidl_generator_py/resource/_idl.py.em
# with input from maestro_interfaces:msg/CurrentPositions.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

# Member 'current_ang'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CurrentPositions(type):
    """Metaclass of message 'CurrentPositions'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('maestro_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'maestro_interfaces.msg.CurrentPositions')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__current_positions
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__current_positions
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__current_positions
            cls._TYPE_SUPPORT = module.type_support_msg__msg__current_positions
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__current_positions

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CurrentPositions(metaclass=Metaclass_CurrentPositions):
    """Message class 'CurrentPositions'."""

    __slots__ = [
        '_current_ang',
    ]

    _fields_and_field_types = {
        'current_ang': 'uint16[24]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint16'), 24),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'current_ang' not in kwargs:
            self.current_ang = numpy.zeros(24, dtype=numpy.uint16)
        else:
            self.current_ang = numpy.array(kwargs.get('current_ang'), dtype=numpy.uint16)
            assert self.current_ang.shape == (24, )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if all(self.current_ang != other.current_ang):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def current_ang(self):
        """Message field 'current_ang'."""
        return self._current_ang

    @current_ang.setter
    def current_ang(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint16, \
                "The 'current_ang' numpy.ndarray() must have the dtype of 'numpy.uint16'"
            assert value.size == 24, \
                "The 'current_ang' numpy.ndarray() must have a size of 24"
            self._current_ang = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 24 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 65536 for val in value)), \
                "The 'current_ang' field must be a set or sequence with length 24 and each value of type 'int' and each unsigned integer in [0, 65535]"
        self._current_ang = numpy.array(value, dtype=numpy.uint16)
