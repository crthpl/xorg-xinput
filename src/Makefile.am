# Copyright © 2007 Peter Hutterer
# Copyright © 2009 Red Hat, Inc.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice (including the next
# paragraph) shall be included in all copies or substantial portions of the
# Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.

bin_PROGRAMS = xinput

AM_CFLAGS = $(XINPUT_CFLAGS)
xinput_LDADD = $(XINPUT_LIBS)


if HAVE_XI2
xinput2_files = hierarchy.c clientptr.c test_xi2.c transform.c
endif

xinput_SOURCES = \
    buttonmap.c \
    feedback.c \
    list.c \
    setint.c \
    setmode.c \
    setptr.c \
    state.c \
    property.c \
    test.c \
    xinput.c \
    xinput.h \
    $(xinput2_files)

