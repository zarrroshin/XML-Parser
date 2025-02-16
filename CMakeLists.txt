cmake_minimum_required(VERSION 3.12)
project(XMLParser LANGUAGES CXX)

# تنظیمات UTF-8 برای پشتیبانی از فارسی
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:GNU>:-finput-charset=UTF-8>")

# افزودن pugixml به عنوان زیرماژول
add_subdirectory(pugixml)

# تنظیمات اصلی پروژه
add_executable(xml-parser 
    src/XMLParser.cpp 
    src/XMLNode.cpp 
    src/Validator.cpp 
    src/RoutingGraph.cpp 
    src/main.cpp
)
target_include_directories(xml-parser PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/pugixml/src
)

# بخش تست‌ها
enable_testing()
add_subdirectory(tests)
