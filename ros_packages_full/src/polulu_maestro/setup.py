from setuptools import setup

package_name = 'polulu_maestro'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='JakubMazur',
    maintainer_email='kubam0906@gmail.com',
    description='Package that interfaces Polulu Maestro plugged by UART with ROS',
    license='Placeholder license declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
		'maestro_wrapper = polulu_maestro.MaestroRosWrapper:main',
		'maestro_test_pub = polulu_maestro.MaestroTestPub:main',
        ],
    },
)
