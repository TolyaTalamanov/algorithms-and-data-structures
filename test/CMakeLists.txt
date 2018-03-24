set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

set(main main.cpp)

file(GLOB app_list RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" test*.cpp)

foreach(app_filename ${app_list})
	get_filename_component(app ${app_filename} NAME_WE)
	add_executable(${app} ${app_filename} ${main})
	set_target_properties(${app} PROPERTIES COMPILE_FLAGS "-pthread")
	target_link_libraries(${app} ${GTEST_BOTH_LIBRARIES})
endforeach(app_filename)
