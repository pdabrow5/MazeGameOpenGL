vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO Blosc/c-blosc
    REF "v${VERSION}"
    SHA512 e9542aa2d1ebae9f6dcc12916d7ac3b920d771281ab96e2b2d59c2951e5f51d02d2684859b8823643d43d320613fb9dd8a3ea411ade34e66e323fcefa8165a91
    HEAD_REF master
    PATCHES
      0001-fix-CMake-config.patch
)

string(COMPARE EQUAL "${VCPKG_LIBRARY_LINKAGE}" "static" BLOSC_STATIC)
string(COMPARE EQUAL "${VCPKG_LIBRARY_LINKAGE}" "dynamic" BLOSC_SHARED)

file(REMOVE_RECURSE "${SOURCE_PATH}/internal-complibs")

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
    DISABLE_PARALLEL_CONFIGURE
    OPTIONS
        -DPREFER_EXTERNAL_LZ4=ON
        -DPREFER_EXTERNAL_ZLIB=ON
        -DPREFER_EXTERNAL_ZSTD=ON
        -DBUILD_TESTS=OFF
        -DBUILD_FUZZERS=OFF
        -DBUILD_BENCHMARKS=OFF
        -DBUILD_STATIC=${BLOSC_STATIC}
        -DBUILD_SHARED=${BLOSC_SHARED}
)

vcpkg_cmake_install()
vcpkg_copy_pdbs()
vcpkg_cmake_config_fixup(CONFIG_PATH share/${PORT})

vcpkg_replace_string("${CURRENT_PACKAGES_DIR}/share/${PORT}/blosc-config.cmake"
    [[# Generated by CMake]]
    [[# Generated by CMake 
include(CMakeFindDependencyMacro)
find_dependency(lz4 CONFIG)
find_dependency(zstd CONFIG)
find_dependency(Snappy CONFIG)
find_dependency(ZLIB)
find_dependency(Threads)]]
)

# cleanup
file(REMOVE_RECURSE "${CURRENT_PACKAGES_DIR}/debug/include")
# Handle copyright
vcpkg_install_copyright(FILE_LIST "${SOURCE_PATH}/LICENSES/BLOSC.txt")

vcpkg_fixup_pkgconfig()
