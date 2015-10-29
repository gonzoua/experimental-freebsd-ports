# Created by: Mikael Urankar <mikael.urankar@gmail.com>
# $FreeBSD: head/misc/raspberrypi-userland/Makefile 399859 2015-10-20 15:09:55Z brd $

PORTNAME=	ioquake3-pi
PORTVERSION=	20151027
CATEGORIES=	misc

MAINTAINER=	gonzo@freebsd.org
COMMENT=	ioquake3 port to FreeBSD

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	armv6


BUILDDIR=	${WRKSRC}/build/release-freebsd-arm

USES=		gmake
USES+=		openal:al

LIB_DEPENDS=	libGLESv2.so:${PORTSDIR}/misc/raspberrypi-userland

MAKE_ARGS+=	DEFAULT_BASEDIR="${Q3DIR}" \
		DEFAULT_LIBDIR="${PREFIX}/${LIBDIR}" \
		ARCH="arm"
MAKE_ARGS+=	USE_SVN=0 USE_CURL=0
MAKE_ARGS+=	USE_OPENAL=1 USE_OPENAL_DLOPEN=0

# We only build client
MAKE_ARGS+=	BUILD_CLIENT=1 BUILD_SERVER=0 BUILD_GAME_SO=0 BUILD_CLIENT_SMP=0 BUILD_MISSIONPACK=0 BUILD_GAME_QVM=0

MAKE_ARGS+=	CFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/interface/vcos/pthreads -g -DVCMODS_MISC -DVCMODS_NOSDL -DVCMODS_OPENGLES -DVCMODS_DEPTH -DVCMODS_REPLACETRIG"
LDFLAGS+=	-lvchostif -lvcfiled_check -lbcm_host -lkhrn_static -lvchiq_arm -lopenmaxil -lEGL -lGLESv2 -lvcos -lrt
LDFLAGS+=	-L${LOCALBASE}/lib/

USE_GITHUB=	yes
GH_ACCOUNT=	gonzoua
GH_PROJECT=	quake3
GH_TAGNAME=	95c5aca


do-install:
	${INSTALL_PROGRAM} ${BUILDDIR}/ioquake3.arm \
		${STAGEDIR}${PREFIX}/bin/ioquake3.arm


.include <bsd.port.mk>
