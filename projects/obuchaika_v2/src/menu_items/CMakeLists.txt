set(HEADERS 
	exit_item.hpp
	goback_item.hpp
	menu_item.hpp
)

set(SOURCES 
	exit_item.cpp
	goback_item.cpp
	menu_item.cpp
)

target_sources(${PROJECT_NAME} 
	PRIVATE
		${HEADERS}
		${SOURCES}
)

target_include_directories(${PROJECT_NAME} PRIVATE
	"${PROJECT_SOURCE_DIR}/src/menu_items"
)
