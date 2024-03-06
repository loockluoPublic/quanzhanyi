# emcc codegen/lib/apb/apb.c -o src/matlab/apb.js -sMODULARIZE -sEXPORTED_RUNTIME_METHODS=ccall 
# emcc codegen2/lib/cylderfit/cylderfit.c -o src/matlab/cylderfit.js -sMODULARIZE -sEXPORTED_RUNTIME_METHODS=ccall 

# emcc codegen/lib/cylderfit/interface/_coder_cylderfit_api.c -o src/matlab/cylderfit.js -sMODULARIZE -sEXPORTED_RUNTIME_METHODS=ccall 

emcc codegen/lib/cylderfit/cylderfit.c -o src/matlab/cylderfit.js -sMODULARIZE -sEXPORTED_RUNTIME_METHODS=ccall 