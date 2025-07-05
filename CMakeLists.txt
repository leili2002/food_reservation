cmake_minimum_required(VERSION 3.21)
project(food_reservation C)

set(CMAKE_C_STANDARD 99)
add_executable(food_reservation
        library.c
        repository/repository.h
        repository/student.c
        repository/responsible.c
        entity/entity.h
        logic/logic.h
        logic/student.c
        logic/responsible.c
        main.c logic/food.c repository/food.c)
