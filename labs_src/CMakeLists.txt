add_library(labs ../../KirillovaVika-homework-3-main/labs_src/lab3/BackupJob.cpp ../../KirillovaVika-homework-3-main/labs_src/lab3/BackupJob.h ../../KirillovaVika-homework-3-main/labs_src/lab3/JobObject.cpp ../../KirillovaVika-homework-3-main/labs_src/lab3/JobObject.h ../../KirillovaVika-homework-3-main/labs_src/lab3/Repository.cpp ../../KirillovaVika-homework-3-main/labs_src/lab3/Repository.h ../../KirillovaVika-homework-3-main/labs_src/lab3/RestorePoint.cpp ../../KirillovaVika-homework-3-main/labs_src/lab3/RestorePoint.h ../../KirillovaVika-homework-3-main/labs_src/lab3/Storage.cpp ../../KirillovaVika-homework-3-main/labs_src/lab3/Storage.h)

#add_subdirectory(../../KirillovaVika-homework-3-main/labs_src/libzippp-master)
include_directories(${libzippp-master_SOURCE_DIR}/src ${libzippp-master_SOURCE_DIR})

target_sources(labs
  PRIVATE
        lab3/consolelog.cpp
  PUBLIC
        lab3/lab3_functions.h
  )

target_include_directories(labs
  PUBLIC
        .
  )

# we use this to get code coverage
# flags are only valid with the GNU compiler and on Linux
if(CMAKE_CXX_COMPILER_ID MATCHES GNU AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
  target_compile_options(labs
    PUBLIC
      "--coverage"
    )
  target_link_options(labs
    INTERFACE
      "--coverage"
    )
endif()
