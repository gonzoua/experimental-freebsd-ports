# Created by: Oleksandr Tymoshenko <gonzo@freebsd.org>
# $FreeBSD$

PORTNAME=	tslib
PORTVERSION=	81a8532  
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	
DISTNAME=	${PORTNAME:S/_/-/}-${PORTVERSION}

MAINTAINER=	gonzo@FreeBSD.org
COMMENT=	Touchscreen interface library

LICENSE=	LGPL20

USES=		gmake autoreconf libtool
# USE_AUTOTOOLS=	autoconf aclocal
# AUTOMAKE_ARGS= --add-missing --copy
# AUTOCONF_ARGS= -f -i -I ${WRKSRC}/m4
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-ucb1x00 --disable-cy8mrln-palmpre \
			--disable-corgi --disable-collie --disable-h3600 \
			--disable-mk712 --disable-arctic2 --disable-tatung \
			--disable-dmc --disable-input --disable-touchkit \
			--disable-galax --enable-bsd

USE_GITHUB=	yes
GH_ACCOUNT=	gonzoua
GH_PROJECT=	tslib
GH_TAGNAME=	${PORTVERSION}

.include <bsd.port.mk>
