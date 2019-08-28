cmake_minimum_required( VERSION 2.8 )
project( myhash_pro )

set( CMAKE_BUILD_TYPE "Release" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

include_directories(
    ##将src目录下的头文件加入
    "./"
)

add_executable( hash ./main.cpp  )
#target_link_libraries( detect ${LINK_LIBS} )

