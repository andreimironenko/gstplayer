COMPATIBLE_MACHINE = "(dm814x-z3|dm814x-evm)"

#SSH provider - dropbear light, optimised for embedded system SSH package
DISTRO_SSH_DAEMON = "dropbear"

###############################################################################
#       Hardware configurations                                               #
###############################################################################

###################
#  DM814x-Z3      #
###################
IMAGE_INSTALL_append_dm814x-z3 = "\
   task-hanover-dm814x-z3         \
   "
EXTRA_IMAGEDEPENDS_append_dm814x-z3 = "\
   linux-omap3-z3                      \
   u-boot-omap3-z3                     \
  "
