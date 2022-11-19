cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order subscriber_member_function.cpp 
Done processing subscriber_member_function.cpp

cpplint --filter=-build/c++11,+build/c++17,-build/namespaces,-build/include_order publisher_member_function.cpp
publisher_member_function.cpp:130:  Using C-style cast.  Use static_cast<int>(...) instead  [readability/casting] [4]
publisher_member_function.cpp:144:  Could not find a newline character at the end of the file.  [whitespace/ending_newline] [5]
Done processing publisher_member_function.cpp
Total errors found: 2


cppcheck --enable=all --std=c++17 --suppress=missingIncludeSystem  subscriber_member_function.cpp 
Checking subscriber_member_function.cpp ...

cppcheck --enable=all --std=c++17 --suppress=missingIncludeSystem  publisher_member_function.cpp
Checking publisher_member_function.cpp ...
