cmake_minimum_required( VERSION 3.8.0 )

project ( vaser )

find_package(FLTK REQUIRED)
find_package(OpenGL REQUIRED)

#find_path( FLTK_INC_DIR FL/Fl.H )

add_executable( polyline vaser/gl_driver.c vaser/vaser.cpp vaser/polyline.cpp samples/polyline.cpp)
target_link_libraries( polyline ${FLTK_LIBRARIES} )
target_include_directories( polyline PRIVATE ${FLTK_INCLUDE_DIR})

add_executable( samples vaser/gl_driver.c vaser/polyline.cpp vaser/vaser.cpp samples/samples.cpp )
target_link_libraries( samples ${FLTK_LIBRARIES} )
target_include_directories( samples PRIVATE ${FLTK_INCLUDE_DIR})

add_executable( segment vaser/gl_driver.c vaser/polyline.cpp vaser/vaser.cpp samples/segment.cpp )
target_link_libraries( segment ${FLTK_LIBRARIES} )
target_include_directories( segment PRIVATE ${FLTK_INCLUDE_DIR})

#
# Google benchmark lib
#
#find_path( BENCHMARK_INC_DIR benchmark/benchmark.h )
#find_library( BENCHMARK_LIB benchmark )
#target_include_directories( 3dmathbenchmark PRIVATE ${BENCHMARK_INC_DIR} )