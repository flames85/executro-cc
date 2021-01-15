add_library(clean_intf INTERFACE)

target_include_directories(clean_intf
  INTERFACE 
    ${CMAKE_CURRENT_LIST_DIR}
)