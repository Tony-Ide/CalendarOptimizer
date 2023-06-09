CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
ADD_SUBDIRECTORY(googletest)
ADD_EXECUTABLE(schedule_optimizer
	src/main.cpp
	src/date.cpp
    src/main_menu.cpp
    src/scheduler.cpp
    src/todo.cpp
    src/event.cpp
    src/task.cpp
    src/blackout_time.cpp
)

ADD_EXECUTABLE(todoTests
    src/event.cpp
    src/date.cpp
    src/todo.cpp
	tests/todoTest.cpp
    src/task.cpp
    src/blackout_time.cpp
)




TARGET_LINK_LIBRARIES(todoTests gtest)
TARGET_COMPILE_DEFINITIONS(todoTests PRIVATE gtest_disable_pthreads=ON)
