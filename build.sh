pip3 install conan
mkdir build
cd build
conan install ../. --build=missing  -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
cd ..
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build . -j
