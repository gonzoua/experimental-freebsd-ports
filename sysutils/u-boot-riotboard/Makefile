# $FreeBSD: head/sysutils/u-boot-riotboard/Makefile 384677 2015-04-24 19:40:12Z loos $

PORTNAME=	u-boot
PORTVERSION=	2015.04
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.denx.de/pub/u-boot/
PKGNAMESUFFIX=	-riotboard
DISTFILES=	u-boot-${PORTVERSION}.tar.bz2

MAINTAINER=	gonzo@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for RIoTboard

LICENSE=	GPLv2

BUILD_DEPENDS=	arm-none-eabi-gcc:${PORTSDIR}/devel/arm-none-eabi-gcc

NO_ARCH=	yes

WRKSRC=		${WRKDIR}/u-boot-${DISTVERSION}
USES=		gmake tar:bzip2
SSP_UNSAFE=	yes # cross-LD does not support -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_FILES=	${U_BOOT_DIR}/u-boot.imx \
		${U_BOOT_DIR}/README

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=arm-none-eabi-

do-configure:
	(cd ${WRKSRC}; ${GMAKE} riotboard_defconfig)

# The build results in two output files: SPL, and u-boot.img.
# Combine them into a single u-boot.imx so that there is only one file to be
# copied onto the boot media starting at a 1K offset on the disk.
IMXFILE=	${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/u-boot.imx
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	cp ${WRKSRC}/u-boot.imx ${IMXFILE}
	${CP} ${.CURDIR}/pkg-descr ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.mk>
