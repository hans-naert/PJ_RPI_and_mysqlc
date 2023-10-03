cmake_minimum_required(VERSION 3.0.0)
project(PJ_RPI_and_mysqlc)

add_executable(PJ_RPI_and_mysqlc main.c)

target_link_libraries(PJ_RPI_and_mysqlc PJ_RPI mariadb)
