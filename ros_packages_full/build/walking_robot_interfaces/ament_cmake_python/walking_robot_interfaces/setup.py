from setuptools import find_packages
from setuptools import setup

setup(
    name='walking_robot_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('walking_robot_interfaces', 'walking_robot_interfaces.*')),
)
