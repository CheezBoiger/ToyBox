# ToyBox project.
# Copyright (c) Mario Garcia, under the GPL v2 License.
#
#
cmake_minimum_required(VERSION 2.8.11)

project("ToyBox_Compiler")

set(TOYBOX_NAME "Toybox" CACHE STRING "Toybox compiler name")
set(TOYBOX_VERSION "v0.1" CACHE STRING "Toybox version")



set(TOYBOX_FINAL "${TOYBOX_NAME}_${TOYBOX_VERSION}")


include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/src/)

add_definitions(-DTOYBOX_DEBUG)


set(TOYBOX_SRC_DIR ${CMAKE_SOURCE_DIR}/src/)
set(TOYBOX_DEBUGGER_DIR ${TOYBOX_SRC_DIR}/debugger/)
set(TOYBOX_TOKEN_DIR ${TOYBOX_SRC_DIR}/token/)


set(TOYBOX_SRC
  ${TOYBOX_SRC_DIR}/main.c
  ${TOYBOX_DEBUGGER_DIR}/debug.h
  ${TOYBOX_TOKEN_DIR}/scanner.h
)


add_executable(${TOYBOX_FINAL}
  ${TOYBOX_SRC}
)
