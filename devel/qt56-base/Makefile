# $FreeBSD: head/devel/qt5/Makefile 407169 2016-01-24 18:10:14Z rakuco $

PORTNAME=	qt56-base
DISTVERSION=	5.6.0
CATEGORIES=	devel
MASTER_SITES=	http://download.qt.io/development_releases/qt/5.6/${DISTVERSION}-rc/single/
DISTNAME=	qt-everywhere-opensource-src-${DISTVERSION}-rc
DISTFILES=	qt-everywhere-opensource-src-${DISTVERSION}-rc.tar.gz

MAINTAINER=	gonzo@FreeBSD.org
COMMENT=	Cross-platform application and UI framework for embedded devices

LICENSE=	LGPL3

PLATFORM=	freebsd-clang
DEVICE=		-device freebsd-arm-generic-clang 

USES=		pkgconfig gmake

OPTIONS_DEFINE=		GSTREAMER RPI
GSTREAMER_DESC=		Gstreamer support
RPI_DESC=		Raspberry Pi HW OpenGL

CONFIGURE_ARGS+=-opensource -confirm-license -v \
				-optimized-qmake \
				-prefix ${PREFIX}/qt5 \
				-release \
				-no-pch \
				-platform ${PLATFORM} \
				-nomake examples \
				-nomake tests \
				-plugin-sql-sqlite \
				-no-qpa-platform-guard

CONFIGURE_ARGS+= -no-cups -no-icu  \
		-no-iconv -no-dbus -no-xcb -no-opengl \
		-no-alsa -no-evdev -qt-harfbuzz \
		-qt-freetype \
		-no-libudev -no-pulseaudio -no-xcb -no-xinput -no-xkb \
		-no-xkbcommon -no-xrender -no-xshape -no-xsync -no-xvideo

HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/qtbase
ALL_TARGET=	# none
DESTDIRNAME=	INSTALL_ROOT

GSTREAMER_LIB_DEPENDS=		libgstreamer-1.0.so:${PORTSDIR}/multimedia/gstreamer1
GSTREAMER_BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gstreamer-audio-1.0.pc:${PORTSDIR}/multimedia/gstreamer1-plugins
RPI_LIB_DEPENDS=		libGLESv2.so:${PORTSDIR}/misc/raspberrypi-userland

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSTREAMER}
CONFIGURE_ARGS+=	-gstreamer
.else
CONFIGURE_ARGS+=	-no-gstreamer
.endif

.if ${PORT_OPTIONS:MGENERICARM}
CONFIGURE_ARGS+=	-device freebsd-rasp-pi-clang -egl -eglfs -opengl es2 -qpa eglfs
.endif



.if ${PORT_OPTIONS:MRPI}
DEFAULT_QPA=		eglfs
CONFIGURE_ARGS+=	-device freebsd-rasp-pi-clang -egl -eglfs -opengl es2
CONFIGURE_ENV+=		PKG_CONFIG_SYSROOT_DIR=/ PKG_CONFIG_LIBDIR=${LOCALBASE}/libdata/pkgconfig
MAKE_ENV+=		PKG_CONFIG_SYSROOT_DIR=/ PKG_CONFIG_LIBDIR=${LOCALBASE}/libdata/pkgconfig
.endif

CONFIGURE_ARGS+=	-qpa ${DEFAULT_QPA}

.include <bsd.port.mk>
