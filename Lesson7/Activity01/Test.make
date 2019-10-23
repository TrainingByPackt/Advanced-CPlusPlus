g++ -c -g -Wall ../Util.cpp -I../

g++ -c -g -Wall ParseFileTestCases.cpp 
 
g++ -g -Wall Util.o ParseFileTestCases.o -lgtest -lgtest_main -pthread -o ParseFileTestCases
