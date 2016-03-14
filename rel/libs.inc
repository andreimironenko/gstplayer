################################################################################
# IPTFT product specification 
#
# Author: Andrei Mironenko <andrei.mironenko@paralleldynamic.com>
################################################################################

# Library packages can be build as release or development. 
# Development library build additionally includes documentation and header files   
# and usually used for SDK.
# LIB_BUILD_MODE denotes either we are building libraris for a product image or 
# product SDK, release or dev. version correspondenly.

 
pf=${LIB_BUILD_MODE}

TASK_GLIBC  =          "\
    glibc                       \
    glibc-utils                 \
    libsegfault                 \
    glibc-thread-db             \
    libgcc                      \
    libstdc++                   \
"

TASK_LIBS   =         "\
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

TASK_BOOST_LIBS   =     "\
   boost${pf}                    \
"

TASK_SDL_LIBS =        "\
    libsdl-gfx${pf}           \
    libsdl-image${pf}         \
    libsdl-mixer${pf}         \
    libsdl-ttf${pf}           \
    libsdl-net${pf}           \
  "

TASK_NCURSES_LIBS =     "\
    ncurses${pf}                 \
  "


#    libavahi-client3       
#    libavahi-common3       
#    libavahi-core6         
#    libdaemon0            
 
TASK_AVAHI_LIBS = "\
    libnss-mdns            \
"
   
TASK_APPS_LIBS =        "\
"

export TASK_PRODUCT_LIBS =  "\
    ${TASK_GLIBC}           \
    ${TASK_LIBS}            \
    ${TASK_BOOST_LIBS}      \
    ${TASK_SDL_LIBS}        \
    ${TASK_NCURSES_LIBS}    \
    ${TASK_AVAHI_LIBS}      \
    ${TASK_APPS_LIBS}       \
"

###############################################################################
#   Preferred versions must be define in this section                         #
###############################################################################

