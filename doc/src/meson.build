####################################################################################################################################
# Error on release builds since we do not want anyone using meson for production yet
####################################################################################################################################
if not get_option('force-release') and get_option('buildtype') != 'debug' and get_option('buildtype') != 'debugoptimized'
    error('meson is currently not supported for release builds')
endif

####################################################################################################################################
# Write configuration
####################################################################################################################################
configure_file(output: 'build.auto.h', configuration: configuration)

####################################################################################################################################
# Build config target
####################################################################################################################################
# build parse.auto.c.inc
subdir('config')

####################################################################################################################################
# Build help target
####################################################################################################################################
# build help.auto.c.inc
subdir('command/help')

####################################################################################################################################
# test target
####################################################################################################################################
src_doc = [
    '../../src/build/common/render.c',
    '../../src/build/common/string.c',
    '../../src/build/common/xml.c',
    '../../src/build/common/yaml.c',
    '../../src/build/config/parse.c',
    '../../src/build/help/parse.c',
    '../../src/command/command.c',
    '../../src/command/exit.c',
    '../../src/command/help/help.c',
    '../../src/common/compress/bz2/common.c',
    '../../src/common/compress/bz2/decompress.c',
    '../../src/common/ini.c',
    '../../src/common/io/fd.c',
    '../../src/common/io/fdRead.c',
    '../../src/common/io/fdWrite.c',
    '../../src/common/lock.c',
    '../../src/common/stat.c',
    '../../src/common/type/json.c',
    '../../src/config/config.c',
    '../../src/config/parse.c',
    'command/build/build.c',
    'command/build/reference.c',
    'config/load.c',
    'main.c',
]

executable(
    'doc-pgbackrest',
    src_common,
    src_doc,
    doc_help_auto_c_inc,
    doc_parse_auto_c_inc,
    include_directories: include_directories('.', '../../src'),
    c_args: [
        # Use large buffer sizes to capture large error/log outputs
        '-DERROR_MESSAGE_BUFFER_SIZE=262144',
        '-DLOG_BUFFER_SIZE=262144',
        arg_unity,
    ],
    dependencies: [
        lib_backtrace,
        lib_bz2,
        lib_xml,
        lib_yaml,
    ],
    build_by_default: false,
)
