set(HEADERS
	System.hpp
)

set(SOURCES
	System.cpp
)

add_library(System
	${HEADERS}
	${SOURCES}
)

target_link_libraries(System
	Logic
)