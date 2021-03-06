# ToyBox project.
# Copyright (c) Mario Garcia, under the GPL v2 License.
#
#
cmake_minimum_required(VERSION 2.8.11)

project("ToyBox_Compiler")

set(TOYBOX_NAME "toybox" CACHE STRING "Toybox compiler name")
set(TOYBOX_VERSION "v0.1" CACHE STRING "Toybox version")



set(TOYBOX_FINAL "${TOYBOX_NAME}")

if (CMAKE_VERSION VERSION_LESS "3.1")
  if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS "--std=gnu99 ${CMAKE_C_FLAGS}")
  endif()
else()
  set(CMAKE_C_STANDARD 99)
endif()


include_directories(SYSTEM
  ${CMAKE_CURRENT_SOURCE_DIR}/src/
)


add_definitions(-DTOYBOX_DEBUG)


set(TOYBOX_SRC_DIR ${CMAKE_SOURCE_DIR}/src/)
set(TOYBOX_DEBUGGER_DIR ${TOYBOX_SRC_DIR}/debugger/)
set(TOYBOX_TOKEN_DIR ${TOYBOX_SRC_DIR}/token/)
set(TOYBOX_LEX_DIR ${TOYBOX_SRC_DIR}/lex/)
set(TOYBOX_SYMBOL_DIR ${TOYBOX_SRC_DIR}/symbol/)
set(TOYBOX_ERR_DIR ${TOYBOX_SRC_DIR}/err/)
set(TOYBOX_PARSER_DIR ${TOYBOX_SRC_DIR}/parser/)


set(TOYBOX_SRC
  ${TOYBOX_SRC_DIR}/main.c
  ${TOYBOX_DEBUGGER_DIR}/debug.h
  ${TOYBOX_TOKEN_DIR}/token.h
  ${TOYBOX_TOKEN_DIR}/scanner.h
  ${TOYBOX_TOKEN_DIR}/scanner.c
  ${TOYBOX_LEX_DIR}/lexical.h
  ${TOYBOX_LEX_DIR}/lex.yy.c
  ${TOYBOX_SYMBOL_DIR}/trieArray.h
  ${TOYBOX_SYMBOL_DIR}/trieArray.c
  ${TOYBOX_SYMBOL_DIR}/map.h
  ${TOYBOX_SYMBOL_DIR}/map.c
  ${TOYBOX_SYMBOL_DIR}/hash.h
  ${TOYBOX_SYMBOL_DIR}/hash.c
  ${TOYBOX_SYMBOL_DIR}/xxhash.h
  ${TOYBOX_SYMBOL_DIR}/xxhash.c
  ${TOYBOX_ERR_DIR}/types.h
  ${TOYBOX_PARSER_DIR}/parser.h
  ${TOYBOX_PARSER_DIR}/parser.c
  ${TOYBOX_PARSER_DIR}/stack.h
  ${TOYBOX_PARSER_DIR}/stack.c
  ${TOYBOX_PARSER_DIR}/slr.h
  ${TOYBOX_PARSER_DIR}/slr.c
  ${TOYBOX_PARSER_DIR}/y.tab.h
  ${TOYBOX_PARSER_DIR}/y.tab.c
)


add_executable(${TOYBOX_FINAL}
  ${TOYBOX_SRC}
)
