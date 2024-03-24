docker run -it --rm -v "$(Get-Location):/src" -w /src/cSource/build emscripten/emsdk /bin/bash -c "emcmake cmake .. && emmake make"
