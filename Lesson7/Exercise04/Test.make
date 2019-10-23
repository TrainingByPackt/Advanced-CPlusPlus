g++ -c CheckIp.cpp

g++ -c TestCases.cpp
 
#g++ CheckIp.o TestCases.o TestMain.cpp -lgtest -pthread -o TestRun

g++ CheckIp.o TestCases.o -lgtest -lgtest_main -pthread -o TestRun
