add_executable(msg 
    main.cpp 
    io.cpp 
    io.hpp 
    config.cpp 
    config.hpp
)

target_link_libraries(msg Boost::headers)

