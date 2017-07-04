add_executable(71-bounded-int
    71-bounded_int.cpp
)

add_custom_target(run-71-bounded-int
    DEPENDS 71-bounded-int
    COMMAND ./71-bounded-int
)

add_executable(72-vector
    72-vector.cpp
)

add_custom_target(run-72-vector
    DEPENDS 72-vector
    COMMAND ./72-vector
)

add_custom_target(run-70-all)
add_dependencies(run-70-all
    run-71-bounded-int
    run-72-vector
)

add_dependencies(run-all
    run-70-all
)

