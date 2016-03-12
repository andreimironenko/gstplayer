################################################################################
# SR1106 library list
#
# Author: Andrei Mironenko <amironenko@hanoverdisplays.com>
################################################################################

# Development build is based on release one with some packages which are taken 
# from the cutting edge of the Git sources
require ../rel/libs.inc

################################################################################
# Additional packages for the development build 
################################################################################
TASK_HANOVER_APPS_LIBS += "\
 unittest-cpp${pf} \
 "
PREFERRED_VERSION_unittest-cpp${pf} = "1.4"
 
################################################################################
# Git cutting edge version of libraries                                        #
################################################################################
PREFERRED_VERSION_jsoncpp${pf} = "git"

