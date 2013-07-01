/*
 * Copyright (c) 2013 Juho Hämäläinen <juho.hamalainen@tieto.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <memory.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <dlfcn.h>
#include <hybris/internal/binding.h>

// Properties stuff
extern int property_set(const char *key, const char *value);
extern int property_get(const char *key, char *value, const char *default_value);

/* CSD stuff */

static int (*_csd_client_init)();
static int (*_csd_client_deinit)();
static int (*_csd_start_playback)();
static int (*_csd_stop_playback)();

// alsa_default.cpp side
static int (*_csd_disable_device)();
static int (*_csd_enable_device)(int, int, uint32_t);
static int (*_csd_volume)(int);
static int (*_csd_mic_mute)(int);
static int (*_csd_wide_voice)(uint8_t);
static int (*_csd_slow_talk)(uint8_t);
static int (*_csd_fens)(uint8_t);
static int (*_csd_start_voice)();
static int (*_csd_stop_voice)();


static void *_libcsd;

static void _init_csdclient()
{
	_libcsd = (void *) android_dlopen("/system/lib/libcsd-client.so", RTLD_LAZY);
}

#define CSD_DLSYM(fptr, sym) do { if (_libcsd == NULL) { _init_csdclient(); }; if (*(fptr) == NULL) { *(fptr) = (void *) android_dlsym(_libcsd, sym); } } while (0) 

static void init_csd()
{
	const char *func = "csd_client_init";

	printf("%s()\n", func);
	CSD_DLSYM(&_csd_client_init, func);

	int ret = _csd_client_init();

	printf("%s() return %d\n", func, ret);
}

static void start_voice()
{
	const char *func = "csd_client_start_voice";

	printf("%s()\n", func);
	CSD_DLSYM(&_csd_start_voice, func);

	int ret = _csd_start_voice();

	printf("%s() return %d\n", func, ret);
}

int main(int argc, char **argv)
{
	init_csd();
	start_voice();

	printf("forever sleep()\n");
	while (1)
		sleep(10000);

	return 0;
}

// vim:ts=4:sw=4:noexpandtab
