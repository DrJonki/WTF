set(INCDIR ${CMAKE_SOURCE_DIR}/include/WTF)
set(SRCDIR ${CMAKE_CURRENT_SOURCE_DIR})

# Sources here
set(SRC
  # Core files
  ${INCDIR}/Entity.hpp
  ${SRCDIR}/Entity.cpp
  ${INCDIR}/Engine.hpp
  ${SRCDIR}/Engine.cpp
  ${INCDIR}/Config.hpp
  ${SRCDIR}/Config.cpp
  ${INCDIR}/Resource.hpp
  ${SRCDIR}/Resource.cpp
  ${INCDIR}/Layer.hpp
  ${INCDIR}/Layer.inl
  ${SRCDIR}/Layer.cpp
  ${INCDIR}/Scene.hpp
  ${SRCDIR}/Scene.cpp
  ${INCDIR}/Randomizer.hpp
  ${INCDIR}/Randomizer.inl
  ${SRCDIR}/Randomizer.cpp
)

include(${CMAKE_SOURCE_DIR}/src/Game/CMakeLists.txt)

add_executable(WTF ${SRC})
add_dependencies(WTF SFML GLM JSON)
add_definitions(-DSFML_STATIC)

set(CMK_SLP ${CMAKE_STATIC_LIBRARY_PREFIX})
set(CMK_SLS ${CMAKE_STATIC_LIBRARY_SUFFIX})

ExternalProject_Get_Property(SFML BINARY_DIR)
target_link_libraries(WTF
  # SFML libs
  debug ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-audio-s-d${CMK_SLS}
  debug ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-graphics-s-d${CMK_SLS}
  debug ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-network-s-d${CMK_SLS}
  debug ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-window-s-d${CMK_SLS}
  debug ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-system-s-d${CMK_SLS}
)
target_link_libraries(WTF
  # SFML libs
  optimized ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-audio-s${CMK_SLS}
  optimized ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-graphics-s${CMK_SLS}
  optimized ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-network-s${CMK_SLS}
  optimized ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-window-s${CMK_SLS}
  optimized ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-system-s${CMK_SLS}
)

target_link_libraries(WTF
  debug ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-main-d${CMK_SLS}
)
target_link_libraries(WTF
  optimized ${BINARY_DIR}/lib/${CMAKE_CFG_INTDIR}/${CMK_SLP}sfml-main${CMK_SLS}
)

target_link_libraries(WTF
  # SFML dependencies
  ${SOURCE_DIR}/extlibs/libs-msvc-universal/x86/flac.lib
  ${SOURCE_DIR}/extlibs/libs-msvc-universal/x86/freetype.lib
  ${SOURCE_DIR}/extlibs/libs-msvc-universal/x86/ogg.lib
  ${SOURCE_DIR}/extlibs/libs-msvc-universal/x86/openal32.lib
  ${SOURCE_DIR}/extlibs/libs-msvc-universal/x86/vorbis.lib
  ${SOURCE_DIR}/extlibs/libs-msvc-universal/x86/vorbisenc.lib
  ${SOURCE_DIR}/extlibs/libs-msvc-universal/x86/vorbisfile.lib

  opengl32.lib
  winmm.lib
  gdi32.lib
  ws2_32.lib
  Wldap32.lib
)

set_target_properties(WTF PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")

add_custom_target(wtf_assets ALL DEPENDS asset_copy)

add_custom_command(OUTPUT asset_copy PRE_BUILD
  DEPENDS always_rebuild
  
  COMMAND ${CMAKE_COMMAND} -E copy
          ${SOURCE_DIR}/extlibs/bin/x86/openal32.dll
          ${CMAKE_CURRENT_BINARY_DIR}/openal32.dll

  COMMAND ${CMAKE_COMMAND} -E copy
          ${SOURCE_DIR}/extlibs/bin/x86/openal32.dll
          ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/openal32.dll

  COMMAND ${CMAKE_COMMAND} -E copy_directory
          ${CMAKE_SOURCE_DIR}/assets
          ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/assets

  COMMAND ${CMAKE_COMMAND} -E copy_directory
          ${CMAKE_SOURCE_DIR}/assets
          ${CMAKE_CURRENT_BINARY_DIR}/assets
)

add_custom_command(OUTPUT always_rebuild COMMAND cmake -E echo)
add_dependencies(WTF wtf_assets)
