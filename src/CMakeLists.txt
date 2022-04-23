aux_source_directory(. SRC_LIST)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(mprpc ${SRC_LIST})
target_link_libraries(mprpc muduo_net muduo_base pthread zookeeper_mt)
