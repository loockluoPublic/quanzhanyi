docker run -it --rm  -v $(pwd):/src -w /src/cSource/build emscripten/emsdk  /bin/bash -c "emcmake cmake .. && emmake make"
