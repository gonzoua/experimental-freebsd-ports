# $FreeBSD: head/devel/qt5/Makefile 407169 2016-01-24 18:10:14Z rakuco $

PORTNAME=	qt56-multimedia
DISTVERSION=	5.6.0
CATEGORIES=	multimedia
MASTER_SITES=	http://download.qt.io/official_releases/qt/5.6/${DISTVERSION}/single/
DISTNAME=	qt-everywhere-opensource-src-${DISTVERSION}
DISTFILES=	qt-everywhere-opensource-src-${DISTVERSION}.tar.gz

MAINTAINER=	gonzo@FreeBSD.org
COMMENT=	Cross-platform application and UI framework for embedded devices

LICENSE=	LGPL3

USES=		pkgconfig gmake

BUILD_DEPENDS+=	${LOCALBASE}/qt5/bin/qmake:${PORTSDIR}/devel/qt56-base
LIB_DEPENDS=	libgstaudio-1.0.so.0:${PORTSDIR}/multimedia/gstreamer1-plugins

WRKSRC=		${WRKDIR}/${DISTNAME}/qtmultimedia
ALL_TARGET=	# none
DESTDIRNAME=	INSTALL_ROOT

do-configure:
	cd ${WRKSRC} && ${LOCALBASE}/qt5/bin/qmake qtmultimedia.pro

.include <bsd.port.mk>
