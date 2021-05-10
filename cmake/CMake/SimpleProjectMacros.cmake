message(STATUS ${CMAKE_CURRENT_LIST_DIR})

function (set_env name value)
  set("ENV{${name}}" ${value})
endfunction ()
