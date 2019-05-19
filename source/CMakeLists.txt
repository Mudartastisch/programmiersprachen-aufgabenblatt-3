# Build example
add_executable(example
  window.cpp
  glew.c
  example.cpp
  vec2.hpp
  vec2.cpp
  mat2.hpp
  mat2.cpp
  circle.hpp
  circle.cpp
  rectangle.hpp
  rectangle.cpp
  color.hpp
    )
target_link_libraries(example
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
  glew.c
  tests.cpp
  window.cpp
  vec2.hpp
  vec2.cpp
  mat2.hpp
  mat2.cpp
  circle.hpp
  circle.cpp
  rectangle.hpp
  rectangle.cpp
  color.hpp
  )
target_link_libraries(tests
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

#Build clock
add_executable(clock
  window.cpp
  glew.c
  clock.cpp
  vec2.hpp
  vec2.cpp
  mat2.hpp
  mat2.cpp
  circle.hpp
  circle.cpp
  rectangle.hpp
  rectangle.cpp
  color.hpp
    )
target_link_libraries(clock
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )
add_dependencies(example glfw nanovg ${COPY_BINARY})


#Build aufgabe2und3
add_executable(aufgabe2und3 aufgabe2und3.cpp)

#Build aufgabe6
add_executable(aufgabe6
  aufgabe_6.cpp
  window.cpp
  glew.c
  vec2.hpp
  vec2.cpp
  mat2.hpp
  mat2.cpp
  circle.hpp
  circle.cpp
  rectangle.hpp
  rectangle.cpp
  color.hpp
  )
  target_link_libraries(aufgabe6
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

#Build aufgabe7
add_executable(aufgabe7
  aufgabe_7.cpp
  window.cpp
  glew.c
  vec2.hpp
  vec2.cpp
  mat2.hpp
  mat2.cpp
  circle.hpp
  circle.cpp
  rectangle.hpp
  rectangle.cpp
  color.hpp
  )
  target_link_libraries(aufgabe7
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

#Build aufgabe8
add_executable(aufgabe8
  aufgabe_8.cpp
  window.cpp
  glew.c
  vec2.hpp
  vec2.cpp
  mat2.hpp
  mat2.cpp
  circle.hpp
  circle.cpp
  rectangle.hpp
  rectangle.cpp
  color.hpp
  )
  target_link_libraries(aufgabe8
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )

#Build aufgabe9
add_executable(aufgabe9 aufgabe_9.cpp)

#Build aufgabe10
add_executable(aufgabe10 aufgabe_10.cpp)

#Build aufgabe11
add_executable(aufgabe11 aufgabe_11.cpp)

#Build aufgabe12
add_executable(aufgabe12 aufgabe_12.cpp)

#Build aufgabe13
add_executable(aufgabe13 aufgabe_13.cpp)

#Build aufgabe14
add_executable(aufgabe14
  aufgabe_14.cpp
  window.cpp
  glew.c
  vec2.hpp
  vec2.cpp
  mat2.hpp
  mat2.cpp
  circle.hpp
  circle.cpp
  rectangle.hpp
  rectangle.cpp
  color.hpp
  )
  target_link_libraries(aufgabe14
  glfw
  ${GLFW_LIBRARIES}
  nanovg
  ${OPENGL_LIBRARIES}
  )