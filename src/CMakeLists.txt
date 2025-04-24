cmake_minimum_required(VERSION 3.16)

# Project setup with version information
project(OcuKnow VERSION 0.1 LANGUAGES CXX)  # Set project name and version

# Set CMake policies for modern CMake usage
cmake_policy(SET CMP0076 NEW)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Automatic processing of UI files, MOC, and resources
set(CMAKE_AUTOUIC ON) # Enable automatic UI processing
set(CMAKE_AUTOMOC ON) # Enable automatic moc processing
set(CMAKE_AUTORCC ON) # Enable automatic resource processing

# Find Qt (try both Qt6 and Qt5)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia)

# Set project sources
set(PROJECT_SOURCES
    main.cpp
    UI/quiz/quiz.cpp
    UI/quiz/quiz.h
    UI/intro/introwidget.cpp
    UI/intro/introwidget.h
    UI/credits/creditswidget.cpp
    UI/credits/creditswidget.h
    resources.qrc
)

# Handle Qt6 vs. Qt5 and Android builds
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(OcuKnow # Changed "Quiz" to "OcuKnow" to match your project
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        UI/studyguide/eye_model.cpp UI/studyguide/eye_model.h UI/studyguide/eyemodel.ui
    )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET OcuKnow APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(OcuKnow SHARED  # Changed "Quiz" to "OcuKnow"
            ${PROJECT_SOURCES}
        )
        # Define properties for Android with Qt 5 after find_package() calls as:
        set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(OcuKnow  # Changed "Quiz" to "OcuKnow"
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Link the Qt libraries
target_link_libraries(OcuKnow  # Changed "Quiz" to "OcuKnow"
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia
)

# macOS bundle settings
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.OcuKnow)  # Change example id
endif()
set_target_properties(OcuKnow  # Changed "Quiz" to "OcuKnow"
    PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Installation settings
include(GNUInstallDirs) # Find standard install locations
install(TARGETS OcuKnow # Changed "Quiz" to "OcuKnow"
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Qt 6 finalization (if using Qt 6)
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(OcuKnow)  # Changed "Quiz" to "OcuKnow"
endif()


# target_sources(OcuKnow  # REMOVE THIS SECTION ENTIRELY
#  PRIVATE
#   main.cpp
#   UI/introwidget.cpp
#   UI/introwidget.h
#   ${OcuKnowResources}
# )

#set_property(SOURCE UI/introwidget.h PROPERTY SKIP_AUTOMOC OFF) # REMOVE THIS

# qt6_wrap_cpp(MOC_SRCS UI/introwidget.h)  # REMOVE THESE LINES
# target_sources(OcuKnow PRIVATE ${MOC_SRCS})
