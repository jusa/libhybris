lib_LTLIBRARIES = \
	libhybris-eglplatformcommon.la

libhybris_eglplatformcommon_la_SOURCES = \
	native_handle.c \
	nativewindowbase.cpp \
	eglplatformcommon.cpp

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = hybris-egl-platform.pc

if WANT_WAYLAND
lib_LTLIBRARIES += libwayland-egl.la

pkgconfig_DATA += wayland-egl.pc


libhybris_eglplatformcommon_la_SOURCES += \
	server_wlegl.cpp \
	server_wlegl_handle.cpp \
	server_wlegl_buffer.cpp \
	wayland-android-protocol.c

BUILT_SOURCES = wayland-android-protocol.c \
		wayland-android-client-protocol.h \
		wayland-android-server-protocol.h

%-protocol.c : %.xml
	$(AM_V_GEN)$(WAYLAND_SCANNER) code < $< > $@

%-server-protocol.h : %.xml
	$(AM_V_GEN)$(WAYLAND_SCANNER) server-header < $< > $@

%-client-protocol.h : %.xml
	$(AM_V_GEN)$(WAYLAND_SCANNER) client-header < $< > $@

libwayland_egl_la_SOURCES = wayland-egl.c

libwayland_egl_la_CFLAGS = -I. -I$(top_srcdir)/include -I$(top_srcdir)/include/android $(WAYLAND_CLIENT_CFLAGS) $(WAYLAND_SERVER_CFLAGS)
if WANT_TRACE
libwayland_egl_la_CFLAGS += -DDEBUG
endif
if WANT_DEBUG
libwayland_egl_la_CFLAGS += -ggdb -O0
endif

libwayland_egl_la_CXXFLAGS = -I. -I$(top_srcdir)/include -I$(top_srcdir)/include/android $(WAYLAND_CLIENT_CFLAGS) $(WAYLAND_SERVER_CFLAGS)
if WANT_TRACE
libwayland_egl_la_CXXFLAGS += -DDEBUG
endif
if WANT_DEBUG
libwayland_egl_la_CXXFLAGS += -ggdb -O0
endif
libwayland_egl_la_LDFLAGS = \
	-version-info "1":"0"

endif

libhybris_eglplatformcommon_la_CFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/include/android -I$(top_srcdir)/egl -I$(top_srcdir)/common/
if WANT_WAYLAND
libhybris_eglplatformcommon_la_CFLAGS += $(WAYLAND_CLIENT_CFLAGS) $(WAYLAND_SERVER_CFLAGS) -I$(top_srcdir)/include/android
endif

if WANT_MESA
libhybris_eglplatformcommon_la_CFLAGS += -DLIBHYBRIS_WANTS_MESA_X11_HEADERS
endif
if WANT_TRACE
libhybris_eglplatformcommon_la_CFLAGS += -DDEBUG
endif
if WANT_DEBUG
libhybris_eglplatformcommon_la_CFLAGS += -ggdb -O0
endif


libhybris_eglplatformcommon_la_CXXFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/egl -I$(top_srcdir)/include/android -I$(top_srcdir)/common/
if WANT_MESA
libhybris_eglplatformcommon_la_CXXFLAGS += -DLIBHYBRIS_WANTS_MESA_X11_HEADERS
endif

if WANT_WAYLAND
libhybris_eglplatformcommon_la_CXXFLAGS += $(WAYLAND_CLIENT_CFLAGS) $(WAYLAND_SERVER_CFLAGS) -I$(top_srcdir)/include/android
endif

if WANT_TRACE
libhybris_eglplatformcommon_la_CXXFLAGS += -DDEBUG
endif
if WANT_DEBUG
libhybris_eglplatformcommon_la_CXXFLAGS += -ggdb -O0
endif
libhybris_eglplatformcommon_la_LDFLAGS = \
	$(top_builddir)/common/libhybris-common.la \
	-version-info "1":"0":"0"

eglplatformcommondir = $(includedir)/hybris/eglplatformcommon
eglplatformcommon_HEADERS = \
	support.h \
	nativewindowbase.h \
	eglplatformcommon.h

if WANT_WAYLAND
libhybris_eglplatformcommon_la_LDFLAGS += \
	$(WAYLAND_CLIENT_LIBS) \
	$(WAYLAND_SERVER_LIBS)
endif
