cmake_minimum_required(VERSION 3.5)

file(GLOB samples_list RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

foreach(sample_filename ${samples_list})
  get_filename_component(sample ${sample_filename} NAME_WE)

  add_executable(${sample} ${sample_filename})
  
  # Добавляем include директории
  target_include_directories(${sample} 
      PRIVATE 
      ${CMAKE_CURRENT_SOURCE_DIR}/../include
      ${CMAKE_CURRENT_SOURCE_DIR}/../src
  )
  
  # Добавляем исходные файлы проекта
  file(GLOB_RECURSE PROJECT_SRC_FILES "../src/*.cpp")
  target_sources(${sample} PRIVATE ${PROJECT_SRC_FILES})
  
  set_target_properties(${sample} PROPERTIES
    OUTPUT_NAME "${sample}"
    PROJECT_LABEL "${sample}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
endforeach()