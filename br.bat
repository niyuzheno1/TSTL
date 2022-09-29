if not exist build mkdir build
cd build
call cmake ..
call cmake --build . --config Debug
call .\Debug\TSTL.exe
cd ..