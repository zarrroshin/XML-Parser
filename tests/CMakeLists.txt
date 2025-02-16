add_executable(tests 
    test_main.cpp
    test_validator.cpp
    ../src/Validator.cpp
    ../src/XMLNode.cpp
)
target_link_libraries(tests PRIVATE 
    CuTest
    pugixml
)
target_include_directories(tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
add_test(NAME validator_tests COMMAND tests)
