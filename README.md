# R-TYPE aka JETPACK2TEK4
## _Epitech Tek3 Project_

This project is based on the famous game R-TYPE
You have the posibilty to play in mutiplayer or solo game

##

## INSTALLATION

##### Prerequisite
 - [CMake 3.16 (minimum)](https://cgold.readthedocs.io/en/latest/first-step/installation.html)
- [Conan](https://conan.io/downloads.html)

Linux :
```sh
# Create and move to build directory
mkdir build && cd build

# Command to lunch dependencies installation
sudo conan install ../. -c tools.system.package_manager:mode=install
```

## BUILD

For linux
```sh
# Configure the project
cmake -B build/release_unix .. -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Release

# Build the executable and libraries
cmake --build release_unix
```

for Windob
 (is comming soon)

Run Server:
All server **configuration** are located in conf.ini
```sh
./r-type_server
```
Info:
Default port : 42069

Run Client:
```sh
./r-type_client
```
## DOCUMENTATION

The documentation is avaiable [here](https://francoisbaudouin.github.io/jetpack2Tek4/)

## DEVELOPERS PART
You are allowed to create your own mods! Be creative
This [RFC]() contains what you need to communicate between server and client
