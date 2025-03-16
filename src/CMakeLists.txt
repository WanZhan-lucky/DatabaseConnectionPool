aux_source_directory(. SRC_LIST)


add_executable(ConnPool ${SRC_LIST})


target_link_libraries(ConnPool mysqlclient)