# SPDX-License-Identifier: Apache-2.0
# Copyright (C) 2019-2021 Xilinx, Inc. All rights reserved.
#
set(TESTNAME "xcl_vcu_test.exe")

set(xrt_core_LIBRARY xrt_core)
set(xrt_coreutil_LIBRARY xrt_coreutil)

if (WIN32)
  set(OpenCL_INCLUDE_DIR ${OCL_ROOT}/include)
  find_library(OpenCL_LIBRARY
    NAMES OpenCL
    HINTS "${OCL_ROOT}/lib")
  include_directories(${OpenCL_INCLUDE_DIR})
else()
  find_package(OpenCL)
endif(WIN32)

include_directories(../../../src/include/1_2 ../../../src/runtime_src/core/include ../common/includes/xcl2 ../common/includes/cmdparser ../common/includes/logger )
add_executable(${TESTNAME} ../common/includes/xcl2/xcl2.cpp ../common/includes/cmdparser/cmdlineparser.cpp ../common/includes/logger/logger.cpp src/host.cpp src/plugin_dec.cpp src/xrt_utils.cpp)
target_link_libraries(${TESTNAME} PRIVATE ${xrt_coreutil_LIBRARY} ${xrt_core_LIBRARY})
add_definitions( -Wno-narrowing )

if (NOT WIN32)
  target_link_libraries(${TESTNAME} PRIVATE ${uuid_LIBRARY} pthread ${OpenCL_LIBRARY} )
endif(NOT WIN32)

if (NOT DEFINED XRT_VALIDATE_DIR)
    set(XRT_VALIDATE_DIR "${CMAKE_CURRENT_BINARY_DIR}/")
endif()

install(TARGETS ${TESTNAME}
    RUNTIME DESTINATION ${XRT_VALIDATE_DIR}) 
