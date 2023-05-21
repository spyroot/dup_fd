# dup_fd

Simple duplicate file finder, it does deep check and does it fast.

If you want build this project, you need install boost and vcpkg first.

```bash
brew install boost
brew install vcpkg
cmake -DCMAKE_BUILD_TYPE=Release ..
mkdir -p build && cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build .
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