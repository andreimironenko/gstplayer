################################################################################
# SR1106 package list
#
# Author: Andrei Mironenko <amironenko@hanoverdisplays.com>
################################################################################


# Development build is based on the release one with some packages which are  
# taken from the cutting edge of the Git sources.
require ../rel/packages.inc

################################################################################
# Common HANOVER packages                                                      #
################################################################################

#PREFERRED_VERSION_build-scripts    = "git"
PREFERRED_VERSION_hanover-configs  = "git"
PREFERRED_VERSION_hanover-security = "git"

################################################################################
# Application packages, git cutting edge version                               #
################################################################################

PREFERRED_VERSION_sdltest = "git"
PREFERRED_VERSION_iptft = "git"
PREFERRED_VERSION_firmloader = "git"

################################################################################
# Machine specific, git cutting edge version                                   #
################################################################################
#TI DM814X packages
#DM814X-Z3
PREFERRED_VERSION_linux-omap3-z3 = "git"
PREFERRED_VERSION_u-boot-omap3-z3 = "git"
