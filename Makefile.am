# WOSS - World Ocean Simulation System -
# 
# Copyright (C) 2009 Federico Guerra 
# and regents of the SIGNET lab, University of Padova
# 
# Author: Federico Guerra - federico@guerra-tlc.com
# 
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation;
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

# This software has been developed by Federico Guerra
# and SIGNET lab, University of Padova, 
# in collaboration with the NATO Centre for Maritime Research 
# and Experimentation (http://www.cmre.nato.int ; 
# E-mail: pao@cmre.nato.int), 
# whose support is gratefully acknowledged.


SUBDIRS = doxy doxy/imgs woss woss/woss_def woss/woss_db woss_phy woss_phy/tcl_hooks samples tests m4

EXTRA_DIST = autogen.sh CHANGELOG COPYRIGHT INSTALL LICENSE ACKNOWLEDGEMENTS doc-woss.cfg

ACLOCAL_AMFLAGS = -I m4

if NS_MIRACLE_BUILD
DISTCHECK_CONFIGURE_FLAGS = @NS_ALLINONE_DISTCHECK_CONFIGURE_FLAGS@ \
                            @NSMIRACLE_DISTCHECK_CONFIGURE_FLAGS@  \
                            @NETCDF_DISTCHECK_CONFIGURE_FLAGS@ \
                            @NETCDF4_DISTCHECK_CONFIGURE_FLAGS@
else
DISTCHECK_CONFIGURE_FLAGS = @NETCDF_DISTCHECK_CONFIGURE_FLAGS@ \
                            @NETCDF4_DISTCHECK_CONFIGURE_FLAGS@
endif 
