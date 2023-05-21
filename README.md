# dup_fd

Simple duplicate file finder, it does deep check and does it fast.

If you want build this project, you need install boost and vcpkg first.

```bash
brew install boost
brew install vcpkg
cmake -DCMAKE_BUILD_TYPE=Release ..
mkdir -p build-arm && cd build-arm && cmake -DCMAKE_OSX_ARCHITECTURES=arm64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-O2" .. && cmake --build .
mkdir -p build-intel && cd build-intel && cmake -DCMAKE_OSX_ARCHITECTURES=x86_64 -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_FLAGS_RELEASE="-O2" .. && cmake --build .
```

or download binary
```
./dup_finder
```

## Usage
```bash
./dup_finder ~/Dropbox/dir1 ~/Dropbox/dir2
```

Will output all file that has same hash and crs, in downstream you pass to anything