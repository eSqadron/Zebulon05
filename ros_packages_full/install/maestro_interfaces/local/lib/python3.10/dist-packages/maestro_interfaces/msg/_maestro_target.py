# generated from rosidl_generator_py/resource/_idl.py.em
# with input from maestro_interfaces:msg/MaestroTarget.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MaestroTarget(type):
    """Metaclass of message 'MaestroTarget'."""

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
                'maestro_interfaces.msg.MaestroTarget')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__maestro_target
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__maestro_target
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__maestro_target
            cls._TYPE_SUPPORT = module.type_support_msg__msg__maestro_target
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__maestro_target

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MaestroTarget(metaclass=Metaclass_MaestroTarget):
    """Message class 'MaestroTarget'."""

    __slots__ = [
        '_channel',
        '_target_ang',
        '_speed',
        '_acceleration',
    ]

    _fields_and_field_types = {
        'channel': 'uint8',
        'target_ang': 'uint16',
        'speed': 'uint8',
        'acceleration': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.channel = kwargs.get('channel', int())
        self.target_ang = kwargs.get('target_ang', int())
        self.speed = kwargs.get('speed', int())
        self.acceleration = kwargs.get('acceleration', int())

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
        if self.channel != other.channel:
            return False
        if self.target_ang != other.target_ang:
            return False
        if self.speed != other.speed:
            return False
        if self.acceleration != other.acceleration:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def channel(self):
        """Message field 'channel'."""
        return self._channel

    @channel.setter
    def channel(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'channel' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'channel' field must be an unsigned integer in [0, 255]"
        self._channel = value

    @builtins.property
    def target_ang(self):
        """Message field 'target_ang'."""
        return self._target_ang

    @target_ang.setter
    def target_ang(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'target_ang' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'target_ang' field must be an unsigned integer in [0, 65535]"
        self._target_ang = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'speed' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'speed' field must be an unsigned integer in [0, 255]"
        self._speed = value

    @builtins.property
    def acceleration(self):
        """Message field 'acceleration'."""
        return self._acceleration

    @acceleration.setter
    def acceleration(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'acceleration' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'acceleration' field must be an unsigned integer in [0, 255]"
        self._acceleration = value
