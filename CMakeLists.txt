cmake_minimum_required(VERSION 3.23)
project(Assignment2_Data_Structure)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment2_Data_Structure
        arrayBasedList.h
        CircularLinkedList.h
        DoublyLinkedList.h
        LinkedListFunctions.h
        main.cpp
        Queue.h
        QueueFunctions.h
        SingleLinkedList.h
        Stack.h
        StackFunctions.h)
