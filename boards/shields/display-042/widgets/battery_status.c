/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>
#include <zephyr/bluetooth/services/bas.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include <zmk/display.h>
#include <zmk/display/widgets/battery_status.h>
#include <zmk/usb.h>
#include <zmk/ble.h>
#include <zmk/events/usb_conn_state_changed.h>
#include <zmk/event_manager.h>
#include <zmk/events/battery_state_changed.h>
#include <zmk/battery.h>

#include "battery_status.h"
#include "util.h"

#if IS_ENABLED(CONFIG_ZMK_DONGLE_DISPLAY_DONGLE_BATTERY)
    #define SOURCE_OFFSET 1
#else
    #define SOURCE_OFFSET 0
#endif

static sys_slist_t widgets = SYS_SLIST_STATIC_INIT(&widgets);

LV_IMG_DECLARE(battery00_icon);
LV_IMG_DECLARE(battery08_icon);
LV_IMG_DECLARE(battery16_icon);
LV_IMG_DECLARE(battery24_icon);
LV_IMG_DECLARE(battery32_icon);
LV_IMG_DECLARE(battery40_icon);
LV_IMG_DECLARE(battery48_icon);
LV_IMG_DECLARE(battery56_icon);
LV_IMG_DECLARE(battery64_icon);
LV_IMG_DECLARE(battery72_icon);
LV_IMG_DECLARE(battery80_icon);
LV_IMG_DECLARE(battery88_icon);
LV_IMG_DECLARE(battery96_icon);
LV_IMG_DECLARE(batterycharge_icon);
LV_IMG_DECLARE(disconnect_icon);

const lv_img_dsc_t *batterys_level[] = {
    &battery00_icon,
    &battery08_icon,
    &battery16_icon,
    &battery24_icon,
    &battery32_icon,
    &battery40_icon,
    &battery48_icon,
    &battery56_icon,
    &battery64_icon,
    &battery72_icon,
    &battery80_icon,
    &battery88_icon,
    &battery96_icon,
    &batterycharge_icon,
    &disconnect_icon,
};

struct battery_state {
    uint8_t source;
    uint8_t level;
    bool usb_present;
};

// static lv_color_t battery_image_buffer[ZMK_SPLIT_BLE_PERIPHERAL_COUNT + SOURCE_OFFSET][14 * 9];
#if IS_ENABLED(CONFIG_ZMK_SPLIT) && IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS_SHOW_PERIPHERAL)
    static lv_color_t battery_image_buffer[ZMK_SPLIT_BLE_PERIPHERAL_COUNT + SOURCE_OFFSET][13 * 20];
#else
    static lv_color_t battery_image_buffer[SOURCE_OFFSET][13 * 20];
#endif


static void set_battery_symbol(lv_obj_t *widget, struct battery_state state) {
    lv_obj_t *canvas = lv_obj_get_child(widget, state.source );
    // lv_obj_t *symbol = lv_obj_get_child(widget, state.source );
    // lv_obj_t *symbol = lv_obj_get_child(widget, state.source * 2);
    // lv_obj_t *label = lv_obj_get_child(widget, state.source * 2 + 1);
    uint8_t level = state.level;
    // if (level > 0 || state.usb_present) {
    //     lv_obj_clear_flag(symbol, LV_OBJ_FLAG_HIDDEN);
    // } else {
    //     lv_obj_add_flag(symbol, LV_OBJ_FLAG_HIDDEN);
    // }
    // 绘制电池
    // lv_obj_t *canvas = lv_canvas_create(symbol);
    // lv_draw_rect_dsc_t rect_black_dsc;
    // init_rect_dsc(&rect_black_dsc, LVGL_BACKGROUND);
    // lv_draw_rect_dsc_t rect_white_dsc;
    // init_rect_dsc(&rect_white_dsc, LVGL_FOREGROUND);

    // lv_canvas_draw_rect(canvas, 0, 2, 29, 12, &rect_white_dsc);
    // lv_canvas_draw_rect(canvas, 1, 3, 27, 10, &rect_black_dsc);

    if (!state.usb_present) {
        // lv_draw_img_dsc_t img_dsc;
        // lv_draw_img_dsc_init(&img_dsc); //x,y是坐标，src是图像的源，可以是文件、结构体指针、Symbol，img_dsc是图像的样式。
        // lv_canvas_draw_img(canvas, 0, 0, batterys_level[0], &img_dsc);
        // lv_img_set_src(symbol, batterys_level[0]);
        // lv_canvas_draw_rect(canvas, 3, 7, 7, 5, &rect_black_dsc);
      
        if (level > 96) {
            // lv_canvas_draw_rect(canvas, 3, 5, 7, 12, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[12]);
        } else if (level > 88) {
            // lv_canvas_draw_rect(canvas, 3, 6, 7, 11, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[11]);
        } else if (level > 80) {
            // lv_canvas_draw_rect(canvas, 3, 7, 7, 10, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[10]);
        } else if (level > 72) {
            // lv_canvas_draw_rect(canvas, 3, 8, 7, 9, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[9]);
        } else if (level > 64) {
            // lv_canvas_draw_rect(canvas, 3, 9, 7, 8, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[8]);
        } else if (level > 56) {
            // lv_canvas_draw_rect(canvas, 3, 10, 7, 7, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[7]);
        } else if (level > 48) {
            // lv_canvas_draw_rect(canvas, 3, 11, 7, 6, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[6]);
        } else if (level > 40) {
            // lv_canvas_draw_rect(canvas, 3, 12, 7, 5, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[5]);
        } else if (level > 32) {
            // lv_canvas_draw_rect(canvas, 3, 13, 7, 4, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[4]);
        } else if (level > 24) {
            // lv_canvas_draw_rect(canvas, 3, 14, 7, 3, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[3]);
        } else if (level > 16) {
            // lv_canvas_draw_rect(canvas, 3, 15, 7, 2, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[2]);
        } else if (level > 8) {
            // lv_canvas_draw_rect(canvas, 3, 16, 7, 1, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[1]);
        } else {
            // lv_canvas_draw_rect(canvas, 3, 12, 7, 10, &rect_black_dsc);
            lv_img_set_src(canvas, batterys_level[0]);
        }
        
    } else {
        lv_img_set_src(canvas, batterys_level[13]);
    }
}

void battery_status_update_cb(struct battery_state state) {
    struct zmk_widget_ky_battery_status *widget;
    SYS_SLIST_FOR_EACH_CONTAINER(&widgets, widget, node) { set_battery_symbol(widget->obj, state); }
}


static struct battery_state peripheral_battery_status_get_state(const zmk_event_t *eh) {
    const struct zmk_peripheral_battery_state_changed *ev = as_zmk_peripheral_battery_state_changed(eh);
    return (struct battery_state){
        .source = ev->source + SOURCE_OFFSET,
        .level = ev->state_of_charge,
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
         .usb_present = zmk_usb_is_powered(),
#endif /* IS_ENABLED(CONFIG_USB_DEVICE_STACK) */
    };
}

static struct battery_state central_battery_status_get_state(const zmk_event_t *eh) {
    const struct zmk_battery_state_changed *ev = as_zmk_battery_state_changed(eh);
    return (struct battery_state) {
        .source = 0,
        .level = (ev != NULL) ? ev->state_of_charge : zmk_battery_state_of_charge(),
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
        .usb_present = zmk_usb_is_powered(),
#endif /* IS_ENABLED(CONFIG_USB_DEVICE_STACK) */
    };
}

static struct battery_state battery_status_get_state(const zmk_event_t *eh) { 
    if (as_zmk_peripheral_battery_state_changed(eh) != NULL) {
        return peripheral_battery_status_get_state(eh);
    } else {
        return central_battery_status_get_state(eh);
    }
}

ZMK_DISPLAY_WIDGET_LISTENER(widget_ky_battery_status, struct battery_state, 
                            battery_status_update_cb, battery_status_get_state)
ZMK_SUBSCRIPTION(widget_ky_battery_status, zmk_peripheral_battery_state_changed);

#if IS_ENABLED(CONFIG_ZMK_DONGLE_DISPLAY_DONGLE_BATTERY)
//#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)

ZMK_SUBSCRIPTION(widget_ky_battery_status, zmk_battery_state_changed);
#if IS_ENABLED(CONFIG_USB_DEVICE_STACK)
ZMK_SUBSCRIPTION(widget_ky_battery_status, zmk_usb_conn_state_changed);
#endif /* IS_ENABLED(CONFIG_USB_DEVICE_STACK) */
//#endif /* !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL) */
#endif /* IS_ENABLED(CONFIG_ZMK_DONGLE_DISPLAY_DONGLE_BATTERY) */

int zmk_widget_ky_battery_status_init(struct zmk_widget_ky_battery_status *widget, lv_obj_t *parent) {
    widget->obj = lv_obj_create(parent);

    lv_obj_set_size(widget->obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);

#if IS_ENABLED(CONFIG_ZMK_SPLIT) && IS_ENABLED(CONFIG_ZMK_WIDGET_BATTERY_STATUS_SHOW_PERIPHERAL)
    for (int i =0; i< ZMK_SPLIT_BLE_PERIPHERAL_COUNT + SOURCE_OFFSET; i++) {  
        lv_obj_t *image_canvas = lv_canvas_create(widget->obj);
        // lv_obj_t *battery_label = lv_label_create(widget->obj);

        lv_canvas_set_buffer(image_canvas, battery_image_buffer[i], 13, 20, LV_IMG_CF_TRUE_COLOR);
        lv_obj_align(image_canvas, LV_ALIGN_TOP_LEFT, i*15, 1);
        // lv_obj_align(battery_label, LV_ALIGN_TOP_LEFT, i*14+3, 10);
        
        lv_obj_add_flag(image_canvas, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(battery_label, LV_OBJ_FLAG_HIDDEN);

        lv_img_set_src(image_canvas, batterys_level[2]);
    }
#else
    for (int i =0; i< SOURCE_OFFSET; i++) {  
        lv_obj_t *image_canvas = lv_canvas_create(widget->obj);
        // lv_obj_t *battery_label = lv_label_create(widget->obj);

        lv_canvas_set_buffer(image_canvas, battery_image_buffer[i], 13, 20, LV_IMG_CF_TRUE_COLOR);
        lv_obj_align(image_canvas, LV_ALIGN_TOP_LEFT, i*15, 1);

        // lv_draw_rect_dsc_t rect_black_dsc;
        // init_rect_dsc(&rect_black_dsc, LVGL_BACKGROUND);
        // lv_draw_rect_dsc_t rect_white_dsc;
        // init_rect_dsc(&rect_white_dsc, LVGL_FOREGROUND);
        // lv_draw_img_dsc_t img_dsc;
        // lv_draw_img_dsc_init(&img_dsc); //x,y是坐标，src是图像的源，可以是文件、结构体指针、Symbol，img_dsc是图像的样式。
        // lv_canvas_draw_img(image_canvas, 0, 0, batterys_level[0], &img_dsc);
        // lv_canvas_draw_rect(image_canvas, 3, 7, 7, 5, &rect_white_dsc);

        // lv_obj_align(battery_label, LV_ALIGN_TOP_LEFT, i*14+3, 10);
        
        // lv_obj_add_flag(image_canvas, LV_OBJ_FLAG_HIDDEN);
        // lv_obj_add_flag(battery_label, LV_OBJ_FLAG_HIDDEN);

        lv_img_set_src(image_canvas, batterys_level[0]);
    }
#endif

    sys_slist_append(&widgets, &widget->node);

    widget_ky_battery_status_init();
    return 0;
}

lv_obj_t *zmk_widget_ky_battery_status_obj(struct zmk_widget_ky_battery_status *widget) {
    return widget->obj;
}
