set(HEADERS 
)

set(SOURCES 
	main.cpp
)

target_sources(${PROJECT_NAME} 
	PRIVATE
		${SOURCES}
		${HEADERS}
)

add_subdirectory(data)
add_subdirectory(menu_items)
