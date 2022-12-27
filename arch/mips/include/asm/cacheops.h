/*
 * Cache operations for the cache instruction.
 *
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * (C) Copyright 1996, 97, 99, 2002, 03 Ralf Baechle
 * (C) Copyright 1999 Silicon Graphics, Inc.
 */
#ifndef	__ASM_CACHEOPS_H
#define	__ASM_CACHEOPS_H

/*
 * Cache Operations available on all MIPS processors with R4000-style caches
 */
#define Index_Invalidate_I      0x00
#define Index_Writeback_Inv_D   0x01
#define Index_Load_Tag_I	0x04
#define Index_Load_Tag_D	0x05
#define Index_Store_Tag_I	0x08
#define Index_Store_Tag_D	0x09
#if defined(CONFIG_CPU_LOONGSON2)
#define Hit_Invalidate_I	0x00
#else
#define Hit_Invalidate_I	0x10
#endif
#define Hit_Invalidate_D	0x11
#define Hit_Writeback_Inv_D	0x15

/*
 * R4000-specific cacheops
 */
#define Create_Dirty_Excl_D	0x0d
#define Fill			0x14
#define Hit_Writeback_I		0x18
#define Hit_Writeback_D		0x19

/*
 * R4000SC and R4400SC-specific cacheops
 */
#define Index_Invalidate_SI     0x02
#define Index_Writeback_Inv_SD  0x03
#define Index_Load_Tag_SI	0x06
#define Index_Load_Tag_SD	0x07
#define Index_Store_Tag_SI	0x0A
#define Index_Store_Tag_SD	0x0B
#define Create_Dirty_Excl_SD	0x0f
#define Hit_Invalidate_SI	0x12
#define Hit_Invalidate_SD	0x13
#define Hit_Writeback_Inv_SD	0x17
#define Hit_Writeback_SD	0x1b
#define Hit_Set_Virtual_SI	0x1e
#define Hit_Set_Virtual_SD	0x1f

/*
 * R5000-specific cacheops
 */
#define R5K_Page_Invalidate_S	0x17

/*
 * RM7000-specific cacheops
 */
#define Page_Invalidate_T	0x16

/*
 * R10000-specific cacheops
 *
 * Cacheops 0x02, 0x06, 0x0a, 0x0c-0x0e, 0x16, 0x1a and 0x1e are unused.
 * Most of the _S cacheops are identical to the R4000SC _SD cacheops.
 */
#define Index_Writeback_Inv_S	0x03
#define Index_Load_Tag_S	0x07
#define Index_Store_Tag_S	0x0B
#define Hit_Invalidate_S	0x13
#define Cache_Barrier		0x14
#define Hit_Writeback_Inv_S	0x17
#define Index_Load_Data_I	0x18
#define Index_Load_Data_D	0x19
#define Index_Load_Data_S	0x1b
#define Index_Store_Data_I	0x1c
#define Index_Store_Data_D	0x1d
#define Index_Store_Data_S	0x1f


/*
 * Cache Operations available on all MIPS processors with R4000-style caches
 */
#define INDEX_INVALIDATE_I      0x00
#define INDEX_WRITEBACK_INV_D   0x01
#define INDEX_LOAD_TAG_I	0x04
#define INDEX_LOAD_TAG_D	0x05
#define INDEX_STORE_TAG_I	0x08
#define INDEX_STORE_TAG_D	0x09
#if defined(CONFIG_CPU_LOONGSON2)
#define HIT_INVALIDATE_I	0x00
#else
#define HIT_INVALIDATE_I	0x10
#endif
#define HIT_INVALIDATE_D	0x11
#define HIT_WRITEBACK_INV_D	0x15

/*
 * R4000-specific cacheops
 */
#define CREATE_DIRTY_EXCL_D	0x0d
#define FILL			0x14
#define HIT_WRITEBACK_I		0x18
#define HIT_WRITEBACK_D		0x19

/*
 * R4000SC and R4400SC-specific cacheops
 */
#define INDEX_INVALIDATE_SI     0x02
#define INDEX_WRITEBACK_INV_SD  0x03
#define INDEX_LOAD_TAG_SI	0x06
#define INDEX_LOAD_TAG_SD	0x07
#define INDEX_STORE_TAG_SI	0x0A
#define INDEX_STORE_TAG_SD	0x0B
#define CREATE_DIRTY_EXCL_SD	0x0f
#define HIT_INVALIDATE_SI	0x12
#define HIT_INVALIDATE_SD	0x13
#define HIT_WRITEBACK_INV_SD	0x17
#define HIT_WRITEBACK_SD	0x1b
#define HIT_SET_VIRTUAL_SI	0x1e
#define HIT_SET_VIRTUAL_SD	0x1f

/*
 * R5000-specific cacheops
 */
#define R5K_PAGE_INVALIDATE_S	0x17

/*
 * RM7000-specific cacheops
 */
#define PAGE_INVALIDATE_T	0x16

/*
 * R10000-specific cacheops
 *
 * Cacheops 0x02, 0x06, 0x0a, 0x0c-0x0e, 0x16, 0x1a and 0x1e are unused.
 * Most of the _S cacheops are identical to the R4000SC _SD cacheops.
 */
#define INDEX_WRITEBACK_INV_S	0x03
#define INDEX_LOAD_TAG_S	0x07
#define INDEX_STORE_TAG_S	0x0B
#define HIT_INVALIDATE_S	0x13
#define CACHE_BARRIER		0x14
#define HIT_WRITEBACK_INV_S	0x17
#define INDEX_LOAD_DATA_I	0x18
#define INDEX_LOAD_DATA_D	0x19
#define INDEX_LOAD_DATA_S	0x1b
#define INDEX_STORE_DATA_I	0x1c
#define INDEX_STORE_DATA_D	0x1d
#define INDEX_STORE_DATA_S	0x1f

#endif	/* __ASM_CACHEOPS_H */
