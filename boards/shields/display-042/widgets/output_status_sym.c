/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */
 
 #include <lvgl.h>


#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_SYM_USB
#define LV_ATTRIBUTE_IMG_SYM_USB
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_USB uint8_t sym_usb_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x00, 0x00, 
  0x3f, 0xc0, 
  0x40, 0x40, 
  0x40, 0x40, 
  0x4a, 0x40, 
  0x4a, 0x40, 
  0xff, 0xe0, 
  0x80, 0x20, 
  0x80, 0x20, 
  0x80, 0x20, 
  0x80, 0x20, 
  0x80, 0x20, 
  0x80, 0x20, 
  0x80, 0x20, 
  0x80, 0x20, 
  0x80, 0x20, 
  0x80, 0x20, 
};

const lv_img_dsc_t sym_usb = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 11,
  .header.h = 17,
  .data_size = 42,
  .data = sym_usb_map,
};


#ifndef LV_ATTRIBUTE_IMG_SYM_OPEN
#define LV_ATTRIBUTE_IMG_SYM_OPEN
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_OPEN uint8_t sym_open_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x38, 
  0x6c, 
  0x44, 
  0x08, 
  0x10, 
  0x10, 
  0x10, 
};

const lv_img_dsc_t sym_open = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 7,
  .header.h = 7,
  .data_size = 15,
  .data = sym_open_map,
};


#ifndef LV_ATTRIBUTE_IMG_SYM_OK
#define LV_ATTRIBUTE_IMG_SYM_OK
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_OK uint8_t sym_ok_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x02, 
  0x06, 
  0x0e, 
  0x9c, 
  0xf8, 
  0xf0, 
  0x60, 
};

const lv_img_dsc_t sym_ok = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 7,
  .header.h = 7,
  .data_size = 15,
  .data = sym_ok_map,
};


#ifndef LV_ATTRIBUTE_IMG_SYM_NOK
#define LV_ATTRIBUTE_IMG_SYM_NOK
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_NOK uint8_t sym_nok_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x82, 
  0xc6, 
  0x6c, 
  0x38, 
  0x6c, 
  0xc6, 
  0x82, 
};

const lv_img_dsc_t sym_nok = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 7,
  .header.h = 7,
  .data_size = 15,
  .data = sym_nok_map,
};


#ifndef LV_ATTRIBUTE_IMG_SYM_BT
#define LV_ATTRIBUTE_IMG_SYM_BT
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_BT uint8_t sym_bt_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0xff, 0xe0, 
  0xf3, 0xe0, 
  0xf1, 0xe0, 
  0xf1, 0xe0, 
  0xf4, 0x60, 
  0x76, 0x20, 
  0x04, 0x60, 
  0x81, 0xe0, 
  0xc3, 0xe0, 
  0xc3, 0xe0, 
  0x81, 0xe0, 
  0x04, 0x60, 
  0x76, 0x20, 
  0xf4, 0x60, 
  0xf4, 0x60, 
  0xf1, 0xe0, 
  0xf3, 0xe0, 
};

const lv_img_dsc_t sym_bt = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 11,
  .header.h = 17,
  .data_size = 42,
  .data = sym_bt_map,
};


#ifndef LV_ATTRIBUTE_IMG_SYM_6
#define LV_ATTRIBUTE_IMG_SYM_6
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_6 uint8_t sym_6_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7c, 
  0x60, 
  0x60, 
  0x7c, 
  0x6c, 
  0x6c, 
  0x6c, 
  0x7c, 
};

const lv_img_dsc_t sym_6 = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 7,
  .header.h = 8,
  .data_size = 16,
  .data = sym_6_map,
};


#ifndef LV_ATTRIBUTE_IMG_SYM_5
#define LV_ATTRIBUTE_IMG_SYM_5
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_5 uint8_t sym_5_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7c, 
  0x60, 
  0x60, 
  0x7c, 
  0x0c, 
  0x0c, 
  0x0c, 
  0x7c, 
};

const lv_img_dsc_t sym_5 = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 7,
  .header.h = 8,
  .data_size = 16,
  .data = sym_5_map,
};


#ifndef LV_ATTRIBUTE_IMG_SYM_4
#define LV_ATTRIBUTE_IMG_SYM_4
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_4 uint8_t sym_4_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x60, 
  0x6c, 
  0x6c, 
  0x6c, 
  0x7c, 
  0x0c, 
  0x0c, 
  0x0c, 
};

const lv_img_dsc_t sym_4 = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 7,
  .header.h = 8,
  .data_size = 16,
  .data = sym_4_map,
};


#ifndef LV_ATTRIBUTE_IMG_SYM_3
#define LV_ATTRIBUTE_IMG_SYM_3
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_3 uint8_t sym_3_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7c, 
  0x04, 
  0x0c, 
  0x30, 
  0x0c, 
  0x04, 
  0x04, 
  0x7c, 
};

const lv_img_dsc_t sym_3 = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 7,
  .header.h = 8,
  .data_size = 16,
  .data = sym_3_map,
};


#ifndef LV_ATTRIBUTE_IMG_SYM_2
#define LV_ATTRIBUTE_IMG_SYM_2
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_2 uint8_t sym_2_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x7c, 
  0x04, 
  0x08, 
  0x10, 
  0x20, 
  0x40, 
  0x40, 
  0x7c, 
};

const lv_img_dsc_t sym_2 = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 7,
  .header.h = 8,
  .data_size = 16,
  .data = sym_2_map,
};


#ifndef LV_ATTRIBUTE_IMG_SYM_1
#define LV_ATTRIBUTE_IMG_SYM_1
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_SYM_1 uint8_t sym_1_map[] = {
  0xff, 0xff, 0xff, 0xff, 	/*Color of index 0*/
  0x00, 0x00, 0x00, 0xff, 	/*Color of index 1*/

  0x10, 
  0x30, 
  0x70, 
  0x10, 
  0x10, 
  0x10, 
  0x10, 
  0x7c, 
};

const lv_img_dsc_t sym_1 = {
  .header.cf = LV_IMG_CF_INDEXED_1BIT,
  .header.always_zero = 0,
  .header.reserved = 0,
  .header.w = 7,
  .header.h = 8,
  .data_size = 16,
  .data = sym_1_map,
};