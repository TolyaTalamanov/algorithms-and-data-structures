# Algorithms and Data Structures

[![Build Status](https://travis-ci.org/TolyaTalamanov/algorithms-and-data-structures.svg?branch=master)](https://travis-ci.org/TolyaTalamanov/algorithms-and-data-structures)

Implementation of algorithms and data structures in с++ and validation with Google Test Framework.

## Dependencies

 - g++ >= 6
 ```bash
sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
sudo apt-get update -qq
sudo apt-get install -qq g++-6
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-6 90
```
 - cmake >= 3.8
 ```bash
sudo apt-get purge cmake 
mkdir temp && cd temp/
wget https://cmake.org/files/v3.11/cmake-3.11.0-rc4.tar.gz
tar -xvf cmake-3.11.0-rc4.tar.gz
cd cmake-3.11.0-rc4/
./bootstrap
sudo make -j8
sudo make install
```
## Install instruction
 - Clone
 ```bash
 git clone --recurse-submodules https://github.com/TolyaTalamanov/algorithms-and-data-structures.git
 ```
 - Build
 ```bash
 mkdir build && cd build
 cmake .. && make -j8
 ```
 - Run all tests
 ```bash
 find ./bin/ -name 'test*' -exec {} \;
 ```
