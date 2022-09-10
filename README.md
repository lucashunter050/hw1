Steps for testing the ULListStr class:
1) Open directory containing ulliststr.cpp ulliststr.h and ulliststr_test.cpp in docker terminal
2) enter "g++ -g -Wall ulliststr.cpp ulliststr_test.cpp"
3) enter "./a.out"
4) program should have run
5) to verify memory integrity - type: "valgrind --tool=memcheck --leak-check=yes ./a.out"