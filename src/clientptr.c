/*
 * Copyright © 2007 Peter Hutterer
 * Copyright © 2009 Red Hat, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */


#include "xinput.h"
#include <string.h>

int
set_clientpointer(Display* dpy, int argc, char** argv, char* name, char *desc)
{
    XIDeviceInfo *info;
    XID window;
    char* id;
    char* dummy;

    if (argc <= 1)
    {
        fprintf(stderr, "Usage: xinput %s %s\n", name, desc);
        return EXIT_FAILURE;
    }

    id = argv[0];

    while(*id == '0') id++;

    window = strtol(argv[0], &dummy, (*id == 'x') ? 16 : 10);

    info = xi2_find_device_info(dpy, argv[1]);

    if (!info) {
	fprintf(stderr, "unable to find device '%s'\n", argv[1]);
	return EXIT_FAILURE;
    }

    XISetClientPointer(dpy, window, info->deviceid);
    return 0;
}

int
get_clientpointer(Display* dpy, int argc, char** argv, char* name, char *desc)
{
    XID window;
    char* id;
    char* dummy;
	int deviceid;
	char devicestr[6]; // max is 65535
	XIDeviceInfo *info;

    if (argc <= 0)
    {
        fprintf(stderr, "Usage: xinput %s %s\n", name, desc);
        return EXIT_FAILURE;
    }

    id = argv[0];

    while(*id == '0') id++;

    window = strtol(argv[0], &dummy, (*id == 'x') ? 16 : 10);

	Bool ret = XIGetClientPointer(dpy, window, &deviceid);

	sprintf(devicestr, "%d", deviceid);
    info = xi2_find_device_info(dpy, devicestr);

    if (!info) {
		fprintf(stderr, "unable to find client pointer device '%d'\n", deviceid);
		return EXIT_FAILURE;
    }

	print_info_xi2(dpy, info, FORMAT_SHORT);
	printf("ret: %d", ret);
    return 0;
}

