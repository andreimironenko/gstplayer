################################################################################
# IPTFT package list 
#
# Author: Andrei Mironenko <andrei.mironenko@paralleldynamic.com>
################################################################################


# Development build is based on the release one with some packages which are  
# taken from the cutting edge of the Git sources.
require ../rel/packages.inc

################################################################################
# Common packages                                                      #
################################################################################

#PREFERRED_VERSION_build-scripts    = "git"
PREFERRED_VERSION_system-configs  = "git"
PREFERRED_VERSION_system-security = "git"

################################################################################
# Application packages, git cutting edge version                               #
################################################################################


################################################################################
# Machine specific, git cutting edge version                                   #
################################################################################
#TI DM814X packages
#DM814X-Z3
PREFERRED_VERSION_linux-omap3-z3 = "git"
PREFERRED_VERSION_u-boot-omap3-z3 = "git"

