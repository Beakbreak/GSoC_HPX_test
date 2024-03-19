#!/bin/sh
#-*-sh-*-

#
# Copyright © 2012-2021 Inria.  All rights reserved.
# See COPYING in top-level directory.
#

HWLOC_top_builddir="/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-src"
HWLOC_top_srcdir="/home/beakbreak/Desktop/GSoC_HPX_test/build/_deps/hwloc-src"
xmlbuffer=xmlbuffer

HWLOC_TOP_SRCDIR=${HWLOC_top_srcdir}
export HWLOC_TOP_SRCDIR

HWLOC_PLUGINS_PATH=${HWLOC_top_builddir}/hwloc/.libs
export HWLOC_PLUGINS_PATH

HWLOC_DEBUG_CHECK=1
export HWLOC_DEBUG_CHECK

HWLOC_LIBXML_CLEANUP=1
export HWLOC_LIBXML_CLEANUP

if test "`basename $1`" = "$xmlbuffer"; then
    "$@" 1 1
    "$@" 0 1
    "$@" 1 0
    "$@" 0 0
else
    "$@"
fi
