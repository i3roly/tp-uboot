cmd_scripts/kconfig/zconf.tab.o := gcc -Wp,-MD,scripts/kconfig/.zconf.tab.o.d -Wall -Wmissing-prototypes -Wstrict-prototypes -O2 -fomit-frame-pointer   -DCURSES_LOC="<curses.h>" -DLOCALE -DKBUILD_NO_NLS -Iscripts/kconfig -c -o scripts/kconfig/zconf.tab.o scripts/kconfig/zconf.tab.c

source_scripts/kconfig/zconf.tab.o := scripts/kconfig/zconf.tab.c

deps_scripts/kconfig/zconf.tab.o := \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/ctype.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_ctype.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_symbol_aliasing.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_posix_availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/runetype.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_types.h \
  /usr/local/include/i386/_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_size_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ct_rune_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_rune_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wchar_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_wint_t.h \
  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.0/include/stdarg.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/Availability.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/AvailabilityInternal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_va_list.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/types.h \
  /usr/local/include/i386/types.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_u_int64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_intptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uintptr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_null.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_off_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ssize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_stdio.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_common.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdlib.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/wait.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_pid_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_id_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/signal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/appleapiopts.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/signal.h \
  /usr/local/include/i386/signal.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/_mcontext.h \
  /usr/local/include/i386/_mcontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/machine/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/mach/i386/_structs.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_pthread/_pthread_attr_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigaltstack.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ucontext.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_sigset_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uid_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/resource.h \
  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.0/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdint.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint8_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint16_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint32_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uint64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_intmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_types/_uintmax_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_timeval.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/endian.h \
  /usr/local/include/i386/endian.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_endian.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/libkern/_OSByteOrder.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/libkern/i386/_OSByteOrder.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/alloca.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/malloc/_malloc.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_dev_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_mode_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/string.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_rsize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_errno_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/strings.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_strings.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/secure/_string.h \
  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.0/include/stdbool.h \
  scripts/kconfig/lkc.h \
    $(wildcard include/config/.h) \
    $(wildcard include/config/list.h) \
  scripts/kconfig/expr.h \
  scripts/kconfig/lkc_proto.h \
  scripts/kconfig/zconf.hash.c \
  scripts/kconfig/lex.zconf.c \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/errno.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/errno.h \
  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.0/include/inttypes.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/inttypes.h \
  /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/11.0.0/include/limits.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/limits.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/machine/limits.h \
  /usr/local/include/i386/limits.h \
  /usr/local/include/i386/_limits.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/syslimits.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/unistd.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_posix_vdisable.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_seek_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_gid_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_useconds_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/select.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_def.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_timespec.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_time_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_suseconds_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_setsize.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_set.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_clr.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_isset.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_zero.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_fd_copy.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_select.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_uuid_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/gethostuuid.h \
  scripts/kconfig/util.c \
  scripts/kconfig/confdata.c \
    $(wildcard include/config/config.h) \
    $(wildcard include/config/autoconfig.h) \
    $(wildcard include/config/overwriteconfig.h) \
    $(wildcard include/config/notimestamp.h) \
    $(wildcard include/config/autoheader.h) \
    $(wildcard include/config/tristate.h) \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/stat.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_blkcnt_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_blksize_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_ino64_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_nlink_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_s_ifmt.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_filesec_t.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/fcntl.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/fcntl.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_o_sync.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_o_dsync.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/time.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/_types/_clock_t.h \
  scripts/kconfig/expr.c \
  scripts/kconfig/symbol.c \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/regex.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/_regex.h \
  /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/utsname.h \
  scripts/kconfig/menu.c \

scripts/kconfig/zconf.tab.o: $(deps_scripts/kconfig/zconf.tab.o)

$(deps_scripts/kconfig/zconf.tab.o):
