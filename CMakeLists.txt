cmake_minimum_required(VERSION 2.8)

project(SimpleQueryParser++)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

add_executable(
  parser
  src/driver.cc
  src/exprtest.cc
  src/parser.tab.cc
  src/lexer.cc
  src/ast_node.cc
  src/ast_phrase_node.cc
  src/ast_and_node.cc
  src/ast_or_node.cc
  src/ast_not_node.cc
  )

