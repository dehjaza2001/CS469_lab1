QT       += core gui
QT += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bartimer.cpp \
    main.cpp \
    mainwindow.cpp \
    server/src/app/client_network_manager.cpp \
    server/src/app/const.cpp \
    server/src/app/event_manager.cpp \
    server/src/app/events.cpp \
    server/src/app/events_data.cpp \
    server/src/app/network_manager.cpp \
    server/src/data/question_bank.cpp \
    server/src/logic/client.cpp \
    server/src/logic/game.cpp

HEADERS += \
    bartimer.h \
    mainwindow.h \
    server/_deps/json-src/include/nlohmann/adl_serializer.hpp \
    server/_deps/json-src/include/nlohmann/byte_container_with_subtype.hpp \
    server/_deps/json-src/include/nlohmann/detail/abi_macros.hpp \
    server/_deps/json-src/include/nlohmann/detail/conversions/from_json.hpp \
    server/_deps/json-src/include/nlohmann/detail/conversions/to_chars.hpp \
    server/_deps/json-src/include/nlohmann/detail/conversions/to_json.hpp \
    server/_deps/json-src/include/nlohmann/detail/exceptions.hpp \
    server/_deps/json-src/include/nlohmann/detail/hash.hpp \
    server/_deps/json-src/include/nlohmann/detail/input/binary_reader.hpp \
    server/_deps/json-src/include/nlohmann/detail/input/input_adapters.hpp \
    server/_deps/json-src/include/nlohmann/detail/input/json_sax.hpp \
    server/_deps/json-src/include/nlohmann/detail/input/lexer.hpp \
    server/_deps/json-src/include/nlohmann/detail/input/parser.hpp \
    server/_deps/json-src/include/nlohmann/detail/input/position_t.hpp \
    server/_deps/json-src/include/nlohmann/detail/iterators/internal_iterator.hpp \
    server/_deps/json-src/include/nlohmann/detail/iterators/iter_impl.hpp \
    server/_deps/json-src/include/nlohmann/detail/iterators/iteration_proxy.hpp \
    server/_deps/json-src/include/nlohmann/detail/iterators/iterator_traits.hpp \
    server/_deps/json-src/include/nlohmann/detail/iterators/json_reverse_iterator.hpp \
    server/_deps/json-src/include/nlohmann/detail/iterators/primitive_iterator.hpp \
    server/_deps/json-src/include/nlohmann/detail/json_pointer.hpp \
    server/_deps/json-src/include/nlohmann/detail/json_ref.hpp \
    server/_deps/json-src/include/nlohmann/detail/macro_scope.hpp \
    server/_deps/json-src/include/nlohmann/detail/macro_unscope.hpp \
    server/_deps/json-src/include/nlohmann/detail/meta/call_std/begin.hpp \
    server/_deps/json-src/include/nlohmann/detail/meta/call_std/end.hpp \
    server/_deps/json-src/include/nlohmann/detail/meta/cpp_future.hpp \
    server/_deps/json-src/include/nlohmann/detail/meta/detected.hpp \
    server/_deps/json-src/include/nlohmann/detail/meta/identity_tag.hpp \
    server/_deps/json-src/include/nlohmann/detail/meta/is_sax.hpp \
    server/_deps/json-src/include/nlohmann/detail/meta/std_fs.hpp \
    server/_deps/json-src/include/nlohmann/detail/meta/type_traits.hpp \
    server/_deps/json-src/include/nlohmann/detail/meta/void_t.hpp \
    server/_deps/json-src/include/nlohmann/detail/output/binary_writer.hpp \
    server/_deps/json-src/include/nlohmann/detail/output/output_adapters.hpp \
    server/_deps/json-src/include/nlohmann/detail/output/serializer.hpp \
    server/_deps/json-src/include/nlohmann/detail/string_concat.hpp \
    server/_deps/json-src/include/nlohmann/detail/string_escape.hpp \
    server/_deps/json-src/include/nlohmann/detail/value_t.hpp \
    server/_deps/json-src/include/nlohmann/json.hpp \
    server/_deps/json-src/include/nlohmann/json_fwd.hpp \
    server/_deps/json-src/include/nlohmann/ordered_map.hpp \
    server/_deps/json-src/include/nlohmann/thirdparty/hedley/hedley.hpp \
    server/_deps/json-src/include/nlohmann/thirdparty/hedley/hedley_undef.hpp \
    server/_deps/json-src/single_include/nlohmann/json.hpp \
    server/_deps/json-src/single_include/nlohmann/json_fwd.hpp \
    server/include/app/client_network_manager.hpp \
    server/include/app/const.hpp \
    server/include/app/event_manager.hpp \
    server/include/app/events.hpp \
    server/include/app/exception.hpp \
    server/include/app/network_manager.hpp \
    server/include/data/question_bank.hpp \
    server/include/logic/client.hpp \
    server/include/logic/game.hpp \
    server/include/logic/question.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    server/CMakeLists.txt \
    server/README.md \
    server/_deps/json-build/CMakeFiles/CMakeDirectoryInformation.cmake \
    server/_deps/json-build/CMakeFiles/progress.marks \
    server/_deps/json-build/cmake_install.cmake \
    server/_deps/json-build/nlohmann_json.pc \
    server/_deps/json-build/nlohmann_jsonConfig.cmake \
    server/_deps/json-build/nlohmann_jsonConfigVersion.cmake \
    server/_deps/json-src/CMakeLists.txt \
    server/_deps/json-src/LICENSE.MIT \
    server/_deps/json-src/cmake/config.cmake.in \
    server/_deps/json-src/cmake/nlohmann_jsonConfigVersion.cmake.in \
    server/_deps/json-src/cmake/pkg-config.pc.in \
    server/_deps/json-src/nlohmann_json.natvis \
    server/_deps/json-subbuild/CMakeCache.txt \
    server/_deps/json-subbuild/CMakeFiles/3.25.2/CMakeSystem.cmake \
    server/_deps/json-subbuild/CMakeFiles/CMakeDirectoryInformation.cmake \
    server/_deps/json-subbuild/CMakeFiles/CMakeOutput.log \
    server/_deps/json-subbuild/CMakeFiles/CMakeRuleHashes.txt \
    server/_deps/json-subbuild/CMakeFiles/TargetDirectories.txt \
    server/_deps/json-subbuild/CMakeFiles/cmake.check_cache \
    server/_deps/json-subbuild/CMakeFiles/json-populate-complete \
    server/_deps/json-subbuild/CMakeFiles/json-populate.dir/DependInfo.cmake \
    server/_deps/json-subbuild/CMakeFiles/json-populate.dir/Labels.json \
    server/_deps/json-subbuild/CMakeFiles/json-populate.dir/Labels.txt \
    server/_deps/json-subbuild/CMakeFiles/json-populate.dir/build.make \
    server/_deps/json-subbuild/CMakeFiles/json-populate.dir/cmake_clean.cmake \
    server/_deps/json-subbuild/CMakeFiles/json-populate.dir/compiler_depend.make \
    server/_deps/json-subbuild/CMakeFiles/json-populate.dir/compiler_depend.ts \
    server/_deps/json-subbuild/CMakeFiles/json-populate.dir/progress.make \
    server/_deps/json-subbuild/CMakeFiles/progress.marks \
    server/_deps/json-subbuild/CMakeLists.txt \
    server/_deps/json-subbuild/cmake_install.cmake \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/download-json-populate.cmake \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/extract-json-populate.cmake \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-build \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-configure \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-done \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-download \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-install \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-mkdir \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-patch \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-test \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-update \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-urlinfo.txt \
    server/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/verify-json-populate.cmake \
    server/_deps/json-subbuild/json-populate-prefix/src/json.tar.xz \
    server/_deps/json-subbuild/json-populate-prefix/tmp/json-populate-cfgcmd.txt \
    server/_deps/json-subbuild/json-populate-prefix/tmp/json-populate-mkdirs.cmake \
    server/client \
    server/cmd.sh \
    server/diagram/diagram.puml \
    server/out/diagram/diagram/Sequence.png \
    server/server

INCLUDEPATH += /opt/homebrew/include
