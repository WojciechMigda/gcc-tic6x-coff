/* ELF definitions for TI C6X
   Copyright (C) 2010-2013 Free Software Foundation, Inc.
   Contributed by Andrew Jenner <andrew@codesourcery.com>
   Contributed by Bernd Schmidt <bernds@codesourcery.com>

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

/* Controlling the Compilation Driver.  */
#define ENDIAN_LINK_SPEC "%{mbig-endian:-EB} %{mlittle-endian:-EL} "

#undef ASM_SPEC
#define ASM_SPEC "%{march=*:-march=%*} %{mbig-endian:-mbig-endian} \
 %{mdsbt:-mdsbt %{!fPIC:-mpid=near} %{fPIC:-mpid=far -mpic} %{fpic:-mpic}} \
 %{!mdsbt:%{fpic:-mpic -mpid=near} %{fPIC:-mpic -mpid=far}}"

#undef DATA_SECTION_ASM_OP
#define DATA_SECTION_ASM_OP "\t.section\t\".fardata\",\"aw\""
#undef READONLY_DATA_SECTION_ASM_OP
#ifndef OBJECT_FORMAT_HYBRID
#define READONLY_DATA_SECTION_ASM_OP "\t.section\t\".const\",\"a\",@progbits"
#else
#define READONLY_DATA_SECTION_ASM_OP "\t.sect\t\".const\""
#endif
#define BSS_SECTION_ASM_OP "\t.section\t\".far\",\"aw\",@nobits"
#define SDATA_SECTION_ASM_OP "\t.section\t\".neardata\",\"aw\""
#define SBSS_SECTION_ASM_OP "\t.section\t\".bss\",\"aw\",@nobits"
#define TARGET_LIBGCC_SDATA_SECTION ".neardata"
