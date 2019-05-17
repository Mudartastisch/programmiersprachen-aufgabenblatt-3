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


