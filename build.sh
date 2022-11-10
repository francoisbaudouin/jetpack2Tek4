pip3 install conan
mkdir build
cd build
conan install ../. --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
cd ..
#cmake -B build/ -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=build/conan_paths.cmake
cmake -G "Visual Studio" -DCMAKE_BUILD_TYPE=Release -DCMAKE_TOOLCHAIN_FILE=build/conan_paths.cmake
#cmake --config Release --build build/ --target install
cmake --build . -j
