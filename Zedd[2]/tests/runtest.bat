@echo off
cls
make -f make.mak main.exe
move /-y "main.exe" "tests\"
cd tests
echo "#SUM testing..."
for %%i in (1 2 3) do call stest.bat %%i
echo "#PRODUCT testing..."
for %%i in (4 5 6) do call ptest.bat %%i
del main.exe
del c.txt
cd..
make -f make.mak clean
echo "#FINISH test.."
pause