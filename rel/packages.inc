################################################################################
# IPTFT product specification 
#
# Author: Andrei Mironenko <andrei.mironenko@paralleldynamic.com>
#
################################################################################

# Trying to get rid of busybox               
TASK_BASE =      "\
    mtd-utils             \
    curl                  \
    arago-feed-configs    \
    initscript-telnetd    \
    devmem2               \
    ethtool               \
    tcpdump               \
    base-files            \
    base-passwd           \
    busybox               \
    initscripts           \
    modutils-initscripts  \
    netbase               \
    update-alternatives   \
    module-init-tools     \
  "
  
TASK_ALSA_UTILS = "\
    alsa-conf \
    alsa-conf-base \
    alsa-server \
    alsa-utils \
    alsa-state \
    "

TASK_UTILS =     "\
   gdbserver              \
   i2c-tools              \
   fbset                  \
   fbset-modes            \
   usbutils               \
   iproute2               \
   udev-utils             \
   nfs-utils              \
   nmap                   \
   rsync                  \
   wget                   \
   bash                   \
   diffutils              \
   diffstat               \
   patch                  \
   bzip2                  \
   quilt                  \
"

TASK_EDITORS =   "\
   vim                    \
   nano                   \
    "

TASK_JPEG_VIEWER = "\
  fbida                   \
  tiff                    \
  "
  
TASK_FSUTILS =   "\
    e2fsprogs             \
    e2fsprogs-e2fsck      \
    e2fsprogs-mke2fs      \
    dosfstools            \
    mtd-utils             \
  "
  
TASK_GST =       "\
   gstreamer              \
   gst-plugins-base       \
   gst-plugins-good       \
   gst-plugins-bad        \
   gst-plugins-ugly       \
   gst-plugins-base-meta  \
   gst-plugins-good-meta  \
   gst-plugins-bad-meta   \
   gst-plugins-ugly-meta  \
   gst-rtsp               \
" 

TASK_NCURSES =   "\
    ncurses-terminfo      \
    ncurses-tools         \
    "

TASK_AVAHI = "\
    avahi-autoipd     \
    avahi-daemon      \
    avahi-utils       \
    zeroconf          \
"

TASK_APPS =      "\
  "      
  
export TASK_PRODUCT =       "\
      ${TASK_BASE}          \
      ${TASK_UTILS}         \
      ${TASK_ALSA_UTILS}    \ 
      ${TASK_EDITORS}       \
      ${TASK_JPEG_VIEWER}   \
      ${TASK_FSUTILS}       \
      ${TASK_GST}           \
      ${TASK_NCURSES}       \
      ${TASK_AVAHI}         \
      ${TASK_APPS}          \
    "    
###############################################################################
# Common packages preferred versions                                          #
###############################################################################
PREFERRED_VERSION_system-configs = "1.1.4"
PREFERRED_VERSION_system-update = "1.1.2"
PREFERRED_VERSION_system-security = "1.0.2"
PREFERRED_VERSION_build-scripts = "1.0.6"        
        
###############################################################################
# Application package preferred versions                                      #
###############################################################################

###############################################################################
# Machine specifi preferred versions                                          #
###############################################################################

#TI DM814X packages
PREFERRED_VERSION_ti-media-controller-loader = "3.00.00.08"
PREFERRED_VERSION_ti-c674x-aaclcdec = "01.41.00.00"
PREFERRED_VERSION_ti-codec-engine = "3.22.01.06"
PREFERRED_VERSION_ti-edma3lld = "02.11.05.02"
PREFERRED_VERSION_ti-framework-components = "3.22.01.07"
PREFERRED_VERSION_ti-ipc = "1.24.03.32"
PREFERRED_VERSION_ti-linuxutils = "3.22.00.02"
PREFERRED_VERSION_ti-osal = "1.22.01.09"
PREFERRED_VERSION_ti-slog = "04.00.00.02"
PREFERRED_VERSION_ti-sysbios = "6.33.05.46"
PREFERRED_VERSION_ti-uia = "1.01.01.14"
PREFERRED_VERSION_ti-xdctools = "3.23.03.53"
PREFERRED_VERSION_ti-xdais = "7.22.00.03"
PREFERRED_VERSION_ti-rpe = "1.00.00.12"
PREFERRED_VERSION_ti-dspbios = "6.33.05.46"

#upgraded 
PREFERRED_VERSION_gst-openmax-ti = "07.00.00"
PREFERRED_VERSION_ti-omx = "05.02.00.48"
PREFERRED_VERSION_ti-syslink = "2.20.02.20"
PREFERRED_VERSION_ti-cgt6x = "7.3.4"

#DM814X-Z3
PREFERRED_VERSION_linux-omap3-z3 = "2.6.37-04.04.00.03"
PREFERRED_VERSION_u-boot-omap3-z3 = "04.01.00.08"
