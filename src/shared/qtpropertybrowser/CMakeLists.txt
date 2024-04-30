cmake_minimum_required (VERSION 3.20)

project (qtpropertybrowser LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_DEBUG_POSTFIX "d")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS OFF) # Windows 中, 导出所有动态库编译符号

set(CMAKE_AUTOMOC ON) # 自动 MOC, Qt 使用
set(CMAKE_AUTOUIC ON) # 自动翻译 .ui  文件, Qt 使用 (这个有 BUG, 当对 `.ui` 文件进行小幅度更新后 编译时无法触发 uic 时, 请手动 `qt_wrap_ui()` )
set(CMAKE_AUTORCC ON) # 自动翻译 .qrc 文件, Qt 使用 (手动: `qt_add_resources()`)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Multimedia)



file(GLOB SRC "./*.cpp" )
file(GLOB HEADERS "*.h")
set(QRC "qtpropertybrowser.qrc")


add_library(${PROJECT_NAME} SHARED
	${SRC} ${HEADERS} ${QRC}
)
target_compile_definitions(${PROJECT_NAME} PRIVATE "QtPropertyBrowser_LIBRARY=1") 			#* 动态库
# target_compile_definitions(${PROJECT_NAME} PUBLIC "QtPropertyBrowser_STATIC_LIBRARY=1") 	#* 静态库



target_link_libraries (${PROJECT_NAME}
    PUBLIC
         Qt6::Widgets Qt6::Core Qt6::Multimedia
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    	$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
        $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
)
install(TARGETS ${PROJECT_NAME}
		EXPORT ${PROJECT_NAME}Targets
		LIBRARY DESTINATION 	bin
		ARCHIVE DESTINATION 	lib
		RUNTIME DESTINATION 	bin
		INCLUDES DESTINATION 	include
)
install(FILES ${HEADERS}
	DESTINATION include/${PROJECT_NAME}
	COMPONENT headers
)
install(EXPORT ${PROJECT_NAME}Targets
		FILE "${PROJECT_NAME}Config.cmake"
		DESTINATION "lib/cmake/${PROJECT_NAME}"
		NAMESPACE ""
)
