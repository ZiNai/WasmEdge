# SPDX-License-Identifier: Apache-2.0

find_package(spdlog QUIET)
if(spdlog_FOUND)
else()
  FetchContent_Declare(
    spdlog
    GIT_REPOSITORY https://github.com/gabime/spdlog.git
    GIT_TAG        v1.8.5
    GIT_SHALLOW    TRUE
  )
  set(SPDLOG_BUILD_SHARED OFF CACHE BOOL "Build shared library")
  set(BUILD_GMOCK OFF)
  FetchContent_MakeAvailable(spdlog)
  wasmedge_setup_target(spdlog)
endif()

set(OPENTELEMETRY_CPP_DIR "/root/opentelemetry-cpp")

find_package(opentelemetry-cpp CONFIG REQUIRED)



wasmedge_add_library(wasmedgeCommon
  hexstr.cpp
  log.cpp
  configure.cpp
  otlog.cpp
)

target_link_libraries(wasmedgeCommon
  PUBLIC
  spdlog::spdlog
  PRIVATE
  ${OPENTELEMETRY_CPP_LIBRARIES}
)

target_include_directories(wasmedgeCommon
  PUBLIC
  ${PROJECT_BINARY_DIR}/include
  ${PROJECT_SOURCE_DIR}/include
  PRIVATE
  ${OPENTELEMETRY_CPP_INCLUDE_DIRS}
)
