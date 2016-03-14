#IPTFT product export and build scripts package
require system-product-gstplayer.inc

inherit srctree gitver

PV = ${GITVER}
S  = ${FILE_DIRNAME}
