################################################################################
# SR1106 library list
#
# Author: Andrei Mironenko <amironenko@hanoverdisplays.com>
################################################################################

# Library packages can be build as release or development. 
# Development library build additionally includes documentation and header files   
# and usually used for SDK.
# LIB_BUILD_MODE denotes either we are building libraris for a product image or 
# product SDK, release or dev. version correspondenly.

 
pf=${LIB_BUILD_MODE}

TASK_HANOVER_GLIBC  =          "\
    glibc                       \
    glibc-utils                 \
    libsegfault                 \
    glibc-thread-db             \
    libgcc                      \
    libstdc++                   \
"

TASK_HANOVER_LIBS   =         "\
    alsa-lib${pf}              \
    jpeg${pf}                  \ 
    lzo${pf}                   \
    libopkg${pf}               \
    libpng${pf}                \
    readline${pf}              \
    libusb-compat${pf}         \
    libusb1${pf}               \
    cdparanoia${pf}            \
    zlib${pf}                  \
    ncurses${pf}               \
    expat${pf}                 \
    libcdaudio${pf}            \
    libcddb${pf}               \
    libcdio${pf}               \
    libffi${pf}                \
    libid3tag${pf}             \
    libmad${pf}                \
    liboil${pf}                \
    taglib${pf}                \
    zlib${pf}                  \
"

TASK_HANOVER_BOOST_LIBS   =     "\
   boost${pf}                    \
"

TASK_HANOVER_SDL_LIBS =        "\
    libsdl-gfx${pf}           \
    libsdl-image${pf}         \
    libsdl-mixer${pf}         \
    libsdl-ttf${pf}           \
    libsdl-net${pf}           \
  "

TASK_HANOVER_NCURSES_LIBS =     "\
    ncurses${pf}                 \
  "

TASK_HANOVER_APPS_LIBS =        "\
  jsoncpp${pf}                   \
"

export TASK_HANOVER_PRODUCT_LIBS =  "\
    ${TASK_HANOVER_GLIBC}           \
    ${TASK_HANOVER_LIBS}            \
    ${TASK_HANOVER_BOOST_LIBS}      \
    ${TASK_HANOVER_SDL_LIBS}        \
    ${TASK_HANOVER_NCURSES_LIBS}    \
    ${TASK_HANOVER_APPS_LIBS}       \
"

###############################################################################
#   Preferred versions must be define in this section                         #
###############################################################################
PREFERRED_VERSION_jsoncpp${pf} = "0.5.0"
PREFERRED_VERSION_z3-camclient${pf} = "1.0.2"

