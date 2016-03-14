#IPTFT product configuration package

LICENSE = "MIT"

PR = "r0"
PE = "0"

COMPATIBLE_MACHINE = "(dm814x-z3|dm814x-evm)" 

PACKAGES = "${PN}"
PACKAGE_ARCH = "${MACHINE_ARCH}"

       
do_configure () {
  :
}
 
do_compile () {
  :
}

do_install () {
    install -d ${D}${sysconfdir}
    install -d ${D}${sysconfdir}/configs
    #install -d ${D}/boot/img

    BUILD_DATE=`date`
    
    cd ${OEBASE}/arago
    ARAGO_VERSION=`git describe`
    
    cd ${OEBASE}/arago-bitbake
    BITBAKE_VERSION=`git describe`
    
    cd ${OEBASE}/arago-oe-dev
    OE_VERSION=`git describe`
    
    cd ${OEBASE}/pd-apps
    APPS_VERSION=`git describe`
    
    cd ${OEBASE}/pd-system
    SYSTEM_VERSION=`git describe`
    
    if [ "${RELDIR}" = "dev" ] ; then
        cd ${OEBASE}/pd-system-dev
        SYSTEM_DEV_VERSION=`git describe`
       
        cd ${OEBASE}/pd-apps-dev
        SYSTEM_APPS_DEV_VERSION=`git describe`
    fi
    
    cd ${FILE_DIRNAME}
    echo "Build Date: $BUILD_DATE" > ${D}${sysconfdir}/product.version
    echo "Product ID: ${PRODUCT}" >> ${D}${sysconfdir}/product.version
    echo "Product release: ${PRODUCT_RELEASE}" >> ${D}${sysconfdir}/product.version
    echo "Machine: ${MACHINE}" >> ${D}${sysconfdir}/product.version
    echo "CPU instruction set: ${FEED_ARCH}" >> ${D}${sysconfdir}/product.version
    echo "Compiler: ${TARGET_SYS}" >> ${D}${sysconfdir}/product.version
    echo "Build purpose: ${BUILD_PURPOSE}" >> ${D}${sysconfdir}/product.version
    echo "Build type: ${RELDIR}" >> ${D}${sysconfdir}/product.version
    echo "" >> ${D}${sysconfdir}/product.version
    
    echo "Versions:" >> ${D}${sysconfdir}/product.version
    echo "arago: ${ARAGO_VERSION}" >> ${D}${sysconfdir}/product.version
    echo "arago-bitbake: ${BITBAKE_VERSION}" >> ${D}${sysconfdir}/product.version
    echo "arago-oe-dev: ${OE_VERSION}" >> ${D}${sysconfdir}/product.version
    echo "pd-apps: ${APPS_VERSION}" >> ${D}${sysconfdir}/product.version
    echo "pd-system: ${SYSTEM_VERSION}" >> ${D}${sysconfdir}/product.version
    if [ "${RELDIR}" = "dev" ] ; then
        echo "pd-system-dev: ${SYSTEM_DEV_VERSION}" >> ${D}${sysconfdir}/product.version
        echo "pd-apps-dev: ${APPS_DEV_VERSION}" >> ${D}${sysconfdir}/product.version
    fi
        
    #Exporting build environment variables
    echo "export RELDIR=${RELDIR}" >  ${D}${sysconfdir}/product.conf
    echo "export BUILD_PURPOSE=${BUILD_PURPOSE}" >> ${D}${sysconfdir}/product.conf
    echo "export PRODUCT=${PRODUCT}" >> ${D}${sysconfdir}/product.conf
    echo "export PRODUCT_RELEASE=${PRODUCT_RELEASE}" >> ${D}${sysconfdir}/product.conf
    echo "export MACHINE=${MACHINE}" >> ${D}${sysconfdir}/product.conf
    echo "export FEED_ARCH=${FEED_ARCH}" >> ${D}${sysconfdir}/product.conf
   
    
   #makeself --bzip2 --nox11 --quiet ${FILE_DIRNAME}/config ${D}/boot/img/config.${PRODUCT}.${PRODUCT_RELEASE}.${MACHINE}.tar.bz2.run "STIB configurations"  ./product.config.install.sh 
   #chmod 744 ${D}/boot/img/config.${PRODUCT}.${PRODUCT_RELEASE}.${MACHINE}.tar.bz2.run	
   #cd ${D}/boot/img
   #ln -sf config.${PRODUCT}.${PRODUCT_RELEASE}.${MACHINE}.tar.bz2.run config.tar.bz2.run
   
   local configs=`ls -1 ${S}/configs`
   for config in ${configs} ; do 
        install -d ${D}${sysconfdir}/configs/${config}
        install -d ${D}${sysconfdir}/configs/${config}/scripts
        install -d ${D}${sysconfdir}/configs/${config}/patches
        
        install -m 0655 ${S}/configs/${config}/description.txt                  ${D}${sysconfdir}/configs/${config}/
        install -m 0655 ${S}/configs/${config}/patches/*.diff                   ${D}${sysconfdir}/configs/${config}/patches/
        
        if [ -d  ${S}/configs/${config}/scripts/machine/${MACHINE} ] ; then
            fc=`find  ${S}/configs/${config}/scripts/machine/${MACHINE} ! -type d | wc -l`
            if [ $fc -gt "0" ] ; then
                install -m 0655 ${S}/configs/${config}/scripts/machine/${MACHINE}/*     ${D}${sysconfdir}/configs/${config}/scripts/
            fi
        fi
        
        if [ -d  ${S}/configs/${config}/patches/machine/${MACHINE} ] ; then
            fc=`find  ${S}/configs/${config}/scripts/machine/${MACHINE} ! -type d | wc -l`
            if [ $fc -gt "0" ] ; then
                install -m 0655 ${S}/configs/${config}/patches/machine/${MACHINE}/*.diff ${D}${sysconfdir}/configs/${config}/patches/
            fi
        fi
         
        local patches=`ls -1 ${D}${sysconfdir}/configs/${config}/patches`
        for patch in $patches ; do
            echo "$patch" >> ${D}${sysconfdir}/configs/${config}/patches/series
        done
   done
   
   
}

#Creating a package
FILES_${PN}="${sysconfdir}/product.version ${sysconfdir}/product.conf"
FILES_${PN} += "/boot/img"
INSANE_SKIP_${PN} = True

CONFFILES_${PN} = " \
	${sysconfdir}/product.version \
	${sysconfdir}/product.conf \
"

PACKAGES += "${PN}-configs"
FILES_${PN}-configs = "${sysconfdir}/configs/*"
INSANE_SKIP_${PN} = True


#CONFFILES_${PN} = " \
#"

pkg_postinst_${PN}_append() {
    #/boot/img/config.tar.bz2.run -- /
}


pkg_postrm_${PN}_append() {

}


do_deploy () {
    #Creating deploy folder
    install -d ${DEPLOY_DIR_IMAGE}
    
    #Copying product version to the deploy folder
    install -m 644 ${D}${sysconfdir}/product.version ${DEPLOY_DIR_IMAGE}/
    package_stagefile_shell ${DEPLOY_DIR_IMAGE}/product.version
    
    #Copying system configuration self-extracting tarball to the deploy folder
    #install -m 744 ${D}/boot/img/config.${PRODUCT}.${PRODUCT_RELEASE}.${MACHINE}.tar.bz2.run ${DEPLOY_DIR_IMAGE}/
    #package_stagefile_shell ${DEPLOY_DIR_IMAGE}/config.${PRODUCT}.${PRODUCT_RELEASE}.${MACHINE}.tar.bz2.run 
}


do_deploy[dirs] = "${S}"
addtask deploy before do_package_stage after do_install
