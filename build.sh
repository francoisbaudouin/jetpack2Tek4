mkdir build
cd build
conan install .. --build=missing -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
cd ..
cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=Release -A x64
cmake --build . --config Release -j
