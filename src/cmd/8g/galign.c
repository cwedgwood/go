// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <u.h>
#include <libc.h>
#include "gg.h"

int	thechar	= '8';
char*	thestring	= "386";
LinkArch*	thelinkarch = &link386;

void
linkarchinit(void)
{
}

vlong MAXWIDTH = (1LL<<32) - 1;

/*
 * go declares several platform-specific type aliases:
 * int, uint, float, and uintptr
 */
Typedef	typedefs[] =
{
	{"int",		TINT,		TINT32},
	{"uint",		TUINT,		TUINT32},
	{"uintptr",	TUINTPTR,	TUINT32},
	{0}
};

void
betypeinit(void)
{
	widthptr = 4;
	widthint = 4;
	widthreg = 4;

	listinit8();
}

void
main(int argc, char **argv)
{
	arch.thechar = thechar;
	arch.thestring = thestring;
	arch.thelinkarch = thelinkarch;
	arch.typedefs = typedefs;
	arch.REGSP = REGSP;
	arch.REGCTXT = REGCTXT;
	arch.MAXWIDTH = MAXWIDTH;
	arch.anyregalloc = anyregalloc;
	arch.betypeinit = betypeinit;
	arch.bgen = bgen;
	arch.cgen = cgen;
	arch.cgen_asop = cgen_asop;
	arch.cgen_call = cgen_call;
	arch.cgen_callinter = cgen_callinter;
	arch.cgen_ret = cgen_ret;
	arch.clearfat = clearfat;
	arch.dumpit = dumpit;
	arch.excise = excise;
	arch.expandchecks = expandchecks;
	arch.gclean = gclean;
	arch.ginit = ginit;
	arch.gins = gins;
	arch.ginscall = ginscall;
	arch.igen = igen;
	arch.linkarchinit = linkarchinit;
	arch.proginfo = proginfo;
	arch.regalloc = regalloc;
	arch.regfree = regfree;
	arch.regopt = regopt;
	arch.regtyp = regtyp;
	arch.sameaddr = sameaddr;
	arch.smallindir = smallindir;
	arch.stackaddr = stackaddr;
	
	gcmain(argc, argv);
}
