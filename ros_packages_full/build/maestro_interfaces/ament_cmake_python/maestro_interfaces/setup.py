from setuptools import find_packages
from setuptools import setup

setup(
    name='maestro_interfaces',
    version='0.0.0',
    packages=find_packages(
        include=('maestro_interfaces', 'maestro_interfaces.*')),
)
