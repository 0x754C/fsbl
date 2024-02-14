/*
 * Copyright (c) 2013-2017, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __DEBUG_H__
#define __DEBUG_H__

/* The log output macros print output to the console. These macros produce
 * compiled log output only if the LOG_LEVEL defined in the makefile (or the
 * make command line) is greater or equal than the level required for that
 * type of log output.
 * The format expected is the same as for printf(). For example:
 * INFO("Info %s.\n", "message")    -> INFO:    Info message.
 * WARN("Warning %s.\n", "message") -> WARNING: Warning message.
 */

#define LOG_LEVEL_ERROR			0
#define LOG_LEVEL_WARNING		1
#define LOG_LEVEL_NOTICE		2
#define LOG_LEVEL_INFO			3
#define LOG_LEVEL_VERBOSE		4

#ifndef __ASSEMBLY__
#include <stdio.h>

#if defined(IMAGE_BL1)
#define NOTICE_STR		""
#else
#if defined(IMAGE_BL2)
#define NOTICE_STR		""
#else
#define NOTICE_STR		""
#endif
#endif

#if LOG_LEVEL >= LOG_LEVEL_NOTICE
# define NOTICE(...)	tf_printf(NOTICE_STR __VA_ARGS__)
#else
# define NOTICE(...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_ERROR
# define ERROR(...)	tf_printf("ERROR:   " __VA_ARGS__)
#else
# define ERROR(...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_WARNING
# define WARN(...)	tf_printf("WARNING: " __VA_ARGS__)
#else
# define WARN(...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_INFO
# define INFO(...)	tf_printf("INFO:    " __VA_ARGS__)
#else
# define INFO(...)
#endif

#if LOG_LEVEL >= LOG_LEVEL_VERBOSE
# define VERBOSE(...)	tf_printf("VERBOSE: " __VA_ARGS__)
#else
# define VERBOSE(...)
#endif


void __dead2 do_panic(void);
#define panic()	do_panic()

/* Function called when stack protection check code detects a corrupted stack */
void __dead2 __stack_chk_fail(void);

void tf_printf(const char *fmt, ...) __printflike(1, 2);
int tf_snprintf(char *s, size_t n, const char *fmt, ...) __printflike(3, 4);
void tf_print_buffer(const void *buf, size_t size, const char *name);

#endif /* __ASSEMBLY__ */

#define ATF_STATE_BL1_ENTRY_POINT 0xB1000000
#define ATF_STATE_BL1_EARLY_PLATFORM_SETUP 0xB1001000
#define ATF_STATE_BL1_APPLY_SW_CONF 0xB1001005
#define ATF_STATE_BL1_APPLY_PATCH 0xB1001020
#define ATF_STATE_BL1_MAIN 0xB100F000
#define ATF_STATE_BL1_PLATFORM_SETUP 0xB100F001
#define ATF_STATE_BL1_BLD_LOADED 0xB100F002
#define ATF_STATE_BL1_BOOT_SPEED_1 0xB1002001
#define ATF_STATE_BL1_BOOT_SPEED_2 0xB1002002

#define ATF_STATE_BL2_ENTRY_POINT 0xB2000000
#define ATF_STATE_BL2_EARLY_PLATFORM_SETUP 0xB2001000
#define ATF_STATE_BL2_PLAT_ARCH_SETUP 0xB2002000
#define ATF_STATE_BL2_MAIN 0xB200F000

#define ATF_STATE_BL31_ENTRY_POINT 0xB3100000
#define ATF_STATE_BL31_MAIN 0xB310F000

#define ATF_STATE_ENTER_CLI 0xC0001000
#define ATF_STATE_WAIT_DEBUG 0xC0001002
#define ATF_STATE_ENTER_DEBUG 0xC0001003
#define ATF_STATE_USB_ENUM_DONE 0xC0001004
#define ATF_STATE_USB_SEND_VID_DONE 0xC0001005
#define ATF_STATE_FIP_HEADER_IS_VALID 0xC0002001

#define ATF_STATE_USB_PHY_SETTING_DONE 0xC0003001
#define ATF_STATE_USB_HW_INIT_DONE 0xC0003002
#define ATF_STATE_USB_DL_BY_CONF_DONE 0xC0003003
#define ATF_STATE_USB_ENUM_FAIL 0xC0003004
#define ATF_STATE_USB_DATA_TIMEOUT 0xC0003005
#define ATF_STATE_USB_TRANSFER_DONE 0xC0003006
#define ATF_STATE_USB_ERR 0xC0003007
#define ATF_STATE_USB_SECOND_STAGE 0xC0003008
#define ATF_STATE_USB_SET_HSPERI_CLK_DONE 0xC0003009

#define ATF_STATE_SPINAND_INIT 0xD0001000
#define ATF_STATE_SPINAND_SCAN_VECTOR 0xD0001002
#define ATF_STATE_SPINAND_SCAN_FIP_BLKS 0xD0001003
#define ATF_STATE_SPINAND_READ_FIP_BIN 0xD0001004


#endif /* __DEBUG_H__ */
