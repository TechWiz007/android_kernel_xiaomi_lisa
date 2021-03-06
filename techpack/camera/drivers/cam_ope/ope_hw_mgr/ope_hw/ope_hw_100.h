/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2019-2021, The Linux Foundation. All rights reserved.
 * Copyright (C) 2021 XiaoMi, Inc.
 */

#ifndef CAM_OPE_HW_100_H
#define CAM_OPE_HW_100_H

#define OPE_BUS_RD_TYPE_BAYER            0x0
#define OPE_BUS_RD_TYPE_YUV_Y            0x0
#define OPE_BUS_RD_TYPE_YUC_C            0x1
#define OPE_BUS_RD_TYPE_CDM              0x2

#define OPE_BUS_WR_TYPE_VID_Y            0x0
#define OPE_BUS_WR_TYPE_VID_C            0x1
#define OPE_BUS_WR_TYPE_DISP_Y           0x2
#define OPE_BUS_WR_TYPE_DISP_C           0x3
#define OPE_BUS_WR_TYPE_ARGB             0x4
#define OPE_BUS_WR_TYPE_RS               0x5
#define OPE_BUS_WR_TYPE_IHIST            0x6
#define OPE_BUS_WR_TYPE_LTM              0x7

static struct cam_ope_pid_mid_info g_ope_mid_info[OPE_DEV_MAX][MAX_RW_CLIENTS] = {
	{
		{
			.cam_ope_res_type = OPE_IN_RES_FULL,
			.pid = 0,
			.mid = 0,
			.read = true,
		},
		{
			.cam_ope_res_type = OPE_IN_RES_FULL,
			.pid = 0,
			.mid = 1,
			.read = true,
		},
		{
			.cam_ope_res_type = OPE_IN_RES_FULL,
			.pid = 0,
			.mid = 2,
			.read = true,
		},
		{
			.cam_ope_res_type = OPE_OUT_RES_VIDEO,
			.pid = 1,
			.mid = 16,
			.read = false,
		},
		{
			.cam_ope_res_type = OPE_OUT_RES_VIDEO,
			.pid = 1,
			.mid = 17,
			.read = false,
		},
		{
			.cam_ope_res_type = OPE_OUT_RES_DISP,
			.pid = 1,
			.mid = 18,
			.read = false,
		},
		{
			.cam_ope_res_type = OPE_OUT_RES_DISP,
			.pid = 1,
			.mid = 19,
			.read = false,
		},
		{
			.cam_ope_res_type = OPE_OUT_RES_ARGB,
			.pid = 1,
			.mid = 20,
			.read = false,
		},
		{
			.cam_ope_res_type = OPE_OUT_RES_STATS_RS,
			.pid = 1,
			.mid = 21,
			.read = false,
		},
		{
			.cam_ope_res_type = OPE_OUT_RES_STATS_IHIST,
			.pid = 1,
			.mid = 22,
			.read = false,
		},
		{
			.cam_ope_res_type = OPE_OUT_RES_STATS_LTM,
			.pid = 1,
			.mid = 23,
			.read = false,
		},
	},
};

static struct cam_ope_common common_data = {
	.ope_mid_info = g_ope_mid_info,
};

enum cam_ope_bus_rd_unpacker_format {
	BUS_RD_VER1_PACKER_FMT_PLAIN_128_BYPASS            = 0x0,
	BUS_RD_VER1_PACKER_FMT_PLAIN_8                     = 0x1,
	BUS_RD_VER1_PACKER_FMT_PLAIN_16_10BPP              = 0x2,
	BUS_RD_VER1_PACKER_FMT_PLAIN_16_12BPP              = 0x3,
	BUS_RD_VER1_PACKER_FMT_PLAIN_16_14BPP              = 0x4,
	BUS_RD_VER1_PACKER_FMT_PLAIN_32_20BPP              = 0x5,
	BUS_RD_VER1_PACKER_FMT_ARGB16_10                   = 0x6,
	BUS_RD_VER1_PACKER_FMT_ARGB16_12                   = 0x7,
	BUS_RD_VER1_PACKER_FMT_ARGB16_14                   = 0x8,
	BUS_RD_VER1_PACKER_FMT_PLAIN_32                    = 0x9,
	BUS_RD_VER1_PACKER_FMT_PLAIN_64                    = 0xA,
	BUS_RD_VER1_PACKER_FMT_TP_10                       = 0xB,
	BUS_RD_VER1_PACKER_FMT_MIPI_8                      = 0xC,
	BUS_RD_VER1_PACKER_FMT_MIPI_10                     = 0xD,
	BUS_RD_VER1_PACKER_FMT_MIPI_12                     = 0xE,
	BUS_RD_VER1_PACKER_FMT_MIPI_14                     = 0xF,
	BUS_RD_VER1_PACKER_FMT_PLAIN_16_16BPP              = 0x10,
	BUS_RD_VER1_PACKER_FMT_BYPASS_SWAP                 = 0x11,
	BUS_RD_VER1_PACKER_FMT_PLAIN_8_SWAP                = 0x12,
	BUS_RD_VER1_PACKER_FMT_MAX                         = 0x13,
};

static struct cam_ope_debug_register ope_debug_regs[OPE_MAX_DEBUG_REGISTER] = {
	{
		.offset = 0xA0,
	},
	{
		.offset = 0xA4
	},
	{
		.offset = 0xA8,
	},
	{
		.offset = 0xAC,
	},
	{
		.offset = 0xB0,
	},
	{
		.offset = 0xB4,
	},
	{
		.offset = 0xB8,
	},
	{
		.offset = 0xBC,
	},
	{
		.offset = 0xD0,
	},
	{
		.offset = 0xD4,
	},
};

static struct cam_ope_top_reg ope_top_reg = {
	.offset              = 0x400,
	.hw_version          = 0x0,
	.reset_cmd           = 0x4,
	.core_clk_cfg_ctrl_0 = 0x8,
	.ahb_clk_cgc_ctrl    = 0xC,
	.core_cfg            = 0x10,
	.irq_status          = 0x14,
	.irq_mask            = 0x18,
	.irq_clear           = 0x1C,
	.irq_set             = 0x20,
	.irq_cmd             = 0x24,
	.violation_status    = 0x28,
	.throttle_cnt_cfg    = 0x2C,
	.debug_cfg           = 0xDC,
	.scratch_reg         = 0x1F0,
	.num_debug_registers = 10,
	.debug_regs          = ope_debug_regs,
};

static struct cam_ope_top_reg_val ope_top_reg_val = {
	.hw_version    = 0x10000000,
	.major_mask    = 0xFFFF,
	.major_shift   = 0x0,
	.minor_mask    = 0x0FFF0000,
	.minor_shift   = 0xF,
	.incr_mask     = 0xF0000000,
	.incr_shift    = 0x1B,
	.irq_mask      = 0x0000000F,
	.sw_reset_cmd  = 0x2,
	.hw_reset_cmd  = 0x1,
	.irq_set_clear = 0x1,
	.rst_done      = 0x1,
	.we_done       = 0x2,
	.fe_done       = 0x4,
	.ope_violation = 0x8,
	.idle          = 0x10,
	.debug_cfg_val = 0x1,
};


static struct cam_ope_bus_rd_reg_val ope_bus_rd_reg_val = {
	.hw_version = 0x00050000,
	.sw_reset = 0x1,
	.cgc_override = 0x0,
	.irq_mask   = 0x30001,
	.irq_set_clear = 0x1,
	.rst_done      = 0x1,
	.rup_done      = 0x2,
	.rd_buf_done   = 0xC,
	.violation     = 0x3000,
	.go_cmd = 0x1,
	.security_cfg = 0x0,
	.latency_buf_size = 4096,
	.num_clients = 0x2,
	.rd_clients = {
		{
			.core_cfg = 0x1,
			.stripe_location_mask = 0x3,
			.stripe_location_shift = 0x0,
			.pix_pattern_mask = 0x3F,
			.pix_pattern_shift = 0x2,
			.img_width_mask = 0xFFFF,
			.img_width_shift = 0x10,
			.img_height_mask = 0xFFFF,
			.img_height_shift = 0x0,
			.mode_mask = 0x1F,
			.mode_shift = 0x0,
			.alignment_mask = 0x1,
			.alignment_shift = 0x5,
			.latency_buf_allocation = 4096,
			.input_port_id = OPE_IN_RES_FULL,
			.rm_port_id = 0,
			.format_type = BUS_RD_COMBO_BAYER_MASK |
				BUS_RD_COMBO_YUV_MASK,
			.num_combos_supported = 2,
		},
		{
			.core_cfg = 0x1,
			.stripe_location_mask = 0x3,
			.stripe_location_shift = 0x0,
			.pix_pattern_mask = 0x3F,
			.pix_pattern_shift = 0x2,
			.img_width_mask = 0xFFFF,
			.img_width_shift = 0x10,
			.img_height_mask = 0xFFFF,
			.img_height_shift = 0x0,
			.mode_mask = 0x1F,
			.mode_shift = 0x0,
			.alignment_mask = 0x1,
			.alignment_shift = 0x5,
			.latency_buf_allocation = 4096,
			.input_port_id = OPE_IN_RES_FULL,
			.rm_port_id = 1,
			.format_type = BUS_RD_COMBO_YUV_MASK,
			.num_combos_supported = 1,

		},
	},
};

static struct cam_ope_bus_rd_reg ope_bus_rd_reg = {
	.offset = 0x4C00,
	.hw_version = 0x0,
	.sw_reset = 0x4,
	.cgc_override = 0x8,
	.irq_mask = 0xC,
	.irq_clear = 0x10,
	.irq_cmd = 0x14,
	.irq_status = 0x18,
	.input_if_cmd = 0x1C,
	.irq_set = 0x20,
	.misr_reset = 0x24,
	.security_cfg = 0x28,
	.iso_cfg = 0x2C,
	.iso_seed = 0x30,
	.num_clients = 0x2,
	.rd_clients = {
		{
			.core_cfg = 0x50,
			.ccif_meta_data = 0x54,
			.img_addr = 0x58,
			.img_cfg = 0x5C,
			.stride = 0x60,
			.unpack_cfg = 0x64,
			.latency_buf_allocation = 0x78,
			.misr_cfg_0 =  0x80,
			.misr_cfg_1 =  0x84,
			.misr_rd_val = 0x88,
		},
		{
			.core_cfg = 0xF0,
			.ccif_meta_data = 0xF4,
			.img_addr = 0xF8,
			.img_cfg = 0xFC,
			.stride = 0x100,
			.unpack_cfg = 0x104,
			.latency_buf_allocation = 0x118,
			.misr_cfg_0 =  0x120,
			.misr_cfg_1 =  0x124,
			.misr_rd_val = 0x128,
		},
	},
};

static struct cam_ope_bus_wr_reg ope_bus_wr_reg = {
	.offset = 0x4D90,
	.hw_version = 0x0,
	.cgc_override = 0x8,
	.irq_mask_0 = 0x18,
	.irq_mask_1 = 0x1C,
	.irq_clear_0 = 0x20,
	.irq_clear_1 = 0x24,
	.irq_status_0 = 0x28,
	.irq_status_1 = 0x2C,
	.irq_cmd = 0x30,
	.frame_header_cfg_0 = 0x34,
	.local_frame_header_cfg_0 = 0x4C,
	.irq_set_0 = 0x50,
	.irq_set_1 = 0x54,
	.iso_cfg = 0x5C,
	.violation_status = 0x64,
	.image_size_violation_status  = 0x70,
	.misr_cfg_0 = 0xB8,
	.misr_cfg_1 = 0xBC,
	.misr_rd_sel = 0xC8,
	.misr_reset = 0xCC,
	.misr_val = 0xD0,
	.num_clients = 0x8,
	.wr_clients = {
		{
			.core_cfg = 0x200,
			.img_addr = 0x204,
			.img_cfg = 0x20C,
			.x_init = 0x210,
			.stride = 0x214,
			.pack_cfg = 0x218,
			.bw_limit = 0x21C,
			.frame_header_addr = 0x220,
			.subsample_period = 0x230,
			.subsample_pattern = 0x234,
		},
		{
			.core_cfg = 0x300,
			.img_addr = 0x304,
			.img_cfg = 0x30C,
			.x_init = 0x310,
			.stride = 0x314,
			.pack_cfg = 0x318,
			.bw_limit = 0x31C,
			.frame_header_addr = 0x320,
			.subsample_period = 0x330,
			.subsample_pattern = 0x334,
		},
		{
			.core_cfg = 0x400,
			.img_addr = 0x404,
			.img_cfg = 0x40C,
			.x_init = 0x410,
			.stride = 0x414,
			.pack_cfg = 0x418,
			.bw_limit = 0x41C,
			.frame_header_addr = 0x420,
			.subsample_period = 0x430,
			.subsample_pattern = 0x434,
		},
		{
			.core_cfg = 0x500,
			.img_addr = 0x504,
			.img_cfg = 0x50C,
			.x_init = 0x510,
			.stride = 0x514,
			.pack_cfg = 0x518,
			.bw_limit = 0x51C,
			.frame_header_addr = 0x520,
			.subsample_period = 0x530,
			.subsample_pattern = 0x534,
		},
		{
			.core_cfg = 0x600,
			.img_addr = 0x604,
			.img_cfg = 0x60C,
			.x_init = 0x610,
			.stride = 0x614,
			.pack_cfg = 0x618,
			.bw_limit = 0x61C,
			.frame_header_addr = 0x620,
			.subsample_period = 0x630,
			.subsample_pattern = 0x634,
		},
		{
			.core_cfg = 0x700,
			.img_addr = 0x704,
			.img_cfg = 0x70C,
			.x_init = 0x710,
			.stride = 0x714,
			.pack_cfg = 0x718,
			.bw_limit = 0x71C,
			.frame_header_addr = 0x720,
			.subsample_period = 0x730,
			.subsample_pattern = 0x734,
		},
		{
			.core_cfg = 0x800,
			.img_addr = 0x804,
			.img_cfg = 0x80C,
			.x_init = 0x810,
			.stride = 0x814,
			.pack_cfg = 0x818,
			.bw_limit = 0x81C,
			.frame_header_addr = 0x820,
			.subsample_period = 0x830,
			.subsample_pattern = 0x834,
		},
		{
			.core_cfg = 0x900,
			.img_addr = 0x904,
			.img_cfg = 0x90C,
			.x_init = 0x910,
			.stride = 0x914,
			.pack_cfg = 0x918,
			.bw_limit = 0x91C,
			.frame_header_addr = 0x920,
			.subsample_period = 0x930,
			.subsample_pattern = 0x934,
		},
	},
};

static struct cam_ope_bus_wr_reg_val ope_bus_wr_reg_val = {
	.hw_version = 0x20010000,
	.irq_mask_0 = 0xD0000000,
	.irq_mask_1 = 0x0,
	.irq_set_clear = 0x1,
	.comp_rup_done = 0x1,
	.comp_buf_done = 0x100,
	.cons_violation = 0x10000000,
	.violation = 0x40000000,
	.img_size_violation = 0x80000000,
	.num_clients = 0x8,
	.wr_clients = {
		{
			.core_cfg_en = 0x1,
			.core_cfg_en_mask = 0x1,
			.core_cfg_en_shift = 0x0,
			.virtual_frame_en_mask = 0x1,
			.virtual_frame_en_shift = 0x1,
			.frame_header_en_mask = 0x1,
			.frame_header_en_shift = 0x2,
			.auto_recovery_en_mask = 0x1,
			.auto_recovery_en_shift = 0x4,
			.mode_mask = 0x3,
			.mode_shift = 0x10,
			.width_mask = 0xFFFF,
			.width_shift = 0x0,
			.height_mask = 0xFFFF,
			.height_shift = 0x10,
			.format_mask = 0xF,
			.format_shift = 0x0,
			.alignment_mask = 0x1,
			.alignment_shift = 0x4,
			.output_port_id = OPE_OUT_RES_VIDEO,
			.wm_port_id = BUS_WR_VIDEO_Y,
			.format_type = BUS_WR_COMBO_YUV_MASK,
			.num_combos_supported = 1,
		},
		{
			.core_cfg_en = 0x1,
			.core_cfg_en_mask = 0x1,
			.core_cfg_en_shift = 0x0,
			.virtual_frame_en_mask = 0x1,
			.virtual_frame_en_shift = 0x1,
			.frame_header_en_mask = 0x1,
			.frame_header_en_shift = 0x2,
			.auto_recovery_en_mask = 0x1,
			.auto_recovery_en_shift = 0x4,
			.mode_mask = 0x3,
			.mode_shift = 0x10,
			.width_mask = 0xFFFF,
			.width_shift = 0x0,
			.height_mask = 0xFFFF,
			.height_shift = 0x10,
			.format_mask = 0xF,
			.format_shift = 0x0,
			.alignment_mask = 0x1,
			.alignment_shift = 0x4,
			.output_port_id = OPE_OUT_RES_VIDEO,
			.wm_port_id = BUS_WR_VIDEO_C,
			.format_type = BUS_WR_COMBO_YUV_MASK,
			.num_combos_supported = 1,
		},
		{
			.core_cfg_en = 0x1,
			.core_cfg_en_mask = 0x1,
			.core_cfg_en_shift = 0x0,
			.virtual_frame_en_mask = 0x1,
			.virtual_frame_en_shift = 0x1,
			.frame_header_en_mask = 0x1,
			.frame_header_en_shift = 0x2,
			.auto_recovery_en_mask = 0x1,
			.auto_recovery_en_shift = 0x4,
			.mode_mask = 0x3,
			.mode_shift = 0x10,
			.width_mask = 0xFFFF,
			.width_shift = 0x0,
			.height_mask = 0xFFFF,
			.height_shift = 0x10,
			.format_mask = 0xF,
			.format_shift = 0x0,
			.alignment_mask = 0x1,
			.alignment_shift = 0x4,
			.output_port_id = OPE_OUT_RES_DISP,
			.wm_port_id = BUS_WR_DISP_Y,
			.format_type = BUS_WR_COMBO_YUV_MASK,
			.num_combos_supported = 1,
		},
		{
			.core_cfg_en = 0x1,
			.core_cfg_en_mask = 0x1,
			.core_cfg_en_shift = 0x0,
			.virtual_frame_en_mask = 0x1,
			.virtual_frame_en_shift = 0x1,
			.frame_header_en_mask = 0x1,
			.frame_header_en_shift = 0x2,
			.auto_recovery_en_mask = 0x1,
			.auto_recovery_en_shift = 0x4,
			.mode_mask = 0x3,
			.mode_shift = 0x10,
			.width_mask = 0xFFFF,
			.width_shift = 0x0,
			.height_mask = 0xFFFF,
			.height_shift = 0x10,
			.format_mask = 0xF,
			.format_shift = 0x0,
			.alignment_mask = 0x1,
			.alignment_shift = 0x4,
			.output_port_id = OPE_OUT_RES_DISP,
			.wm_port_id = BUS_WR_DISP_C,
			.format_type = BUS_WR_COMBO_YUV_MASK,
			.num_combos_supported = 1,
		},
		{
			.core_cfg_en = 0x1,
			.core_cfg_en_mask = 0x1,
			.core_cfg_en_shift = 0x0,
			.virtual_frame_en_mask = 0x1,
			.virtual_frame_en_shift = 0x1,
			.frame_header_en_mask = 0x1,
			.frame_header_en_shift = 0x2,
			.auto_recovery_en_mask = 0x1,
			.auto_recovery_en_shift = 0x4,
			.mode_mask = 0x3,
			.mode_shift = 0x10,
			.width_mask = 0xFFFF,
			.width_shift = 0x0,
			.height_mask = 0xFFFF,
			.height_shift = 0x10,
			.format_mask = 0xF,
			.format_shift = 0x0,
			.alignment_mask = 0x1,
			.alignment_shift = 0x4,
			.output_port_id = OPE_OUT_RES_ARGB,
			.wm_port_id = BUS_WR_ARGB,
			.format_type = BUS_WR_COMBO_YUV_MASK,
			.num_combos_supported = 1,
		},
		{
			.core_cfg_en = 0x1,
			.core_cfg_en_mask = 0x1,
			.core_cfg_en_shift = 0x0,
			.virtual_frame_en_mask = 0x1,
			.virtual_frame_en_shift = 0x1,
			.frame_header_en_mask = 0x1,
			.frame_header_en_shift = 0x2,
			.auto_recovery_en_mask = 0x1,
			.auto_recovery_en_shift = 0x4,
			.mode_mask = 0x3,
			.mode_shift = 0x10,
			.width_mask = 0xFFFF,
			.width_shift = 0x0,
			.height_mask = 0xFFFF,
			.height_shift = 0x10,
			.format_mask = 0xF,
			.format_shift = 0x0,
			.alignment_mask = 0x1,
			.alignment_shift = 0x4,
			.output_port_id = OPE_OUT_RES_STATS_RS,
			.wm_port_id = BUS_WR_STATS_RS,
			.format_type = BUS_WR_COMBO_YUV_MASK,
			.num_combos_supported = 1,
		},
		{
			.core_cfg_en = 0x1,
			.core_cfg_en_mask = 0x1,
			.core_cfg_en_shift = 0x0,
			.virtual_frame_en_mask = 0x1,
			.virtual_frame_en_shift = 0x1,
			.frame_header_en_mask = 0x1,
			.frame_header_en_shift = 0x2,
			.auto_recovery_en_mask = 0x1,
			.auto_recovery_en_shift = 0x4,
			.mode_mask = 0x3,
			.mode_shift = 0x10,
			.width_mask = 0xFFFF,
			.width_shift = 0x0,
			.height_mask = 0xFFFF,
			.height_shift = 0x10,
			.format_mask = 0xF,
			.format_shift = 0x0,
			.alignment_mask = 0x1,
			.alignment_shift = 0x4,
			.output_port_id = OPE_OUT_RES_STATS_IHIST,
			.wm_port_id = BUS_WR_STATS_IHIST,
			.format_type = BUS_WR_COMBO_YUV_MASK,
			.num_combos_supported = 1,
		},
		{
			.core_cfg_en = 0x1,
			.core_cfg_en_mask = 0x1,
			.core_cfg_en_shift = 0x0,
			.virtual_frame_en_mask = 0x1,
			.virtual_frame_en_shift = 0x1,
			.frame_header_en_mask = 0x1,
			.frame_header_en_shift = 0x2,
			.auto_recovery_en_mask = 0x1,
			.auto_recovery_en_shift = 0x4,
			.mode_mask = 0x3,
			.mode_shift = 0x10,
			.width_mask = 0xFFFF,
			.width_shift = 0x0,
			.height_mask = 0xFFFF,
			.height_shift = 0x10,
			.format_mask = 0xF,
			.format_shift = 0x0,
			.alignment_mask = 0x1,
			.alignment_shift = 0x4,
			.output_port_id = OPE_OUT_RES_STATS_LTM,
			.wm_port_id = BUS_WR_STATS_LTM,
			.format_type = BUS_WR_COMBO_YUV_MASK,
			.num_combos_supported = 1,
		},
	},
};

static struct cam_ope_pp_reg ope_pp_reg = {
	.offset = 0x800,
	.num_clients = MAX_PP_CLIENTS,
	.pp_clients = {
		{
			.hw_status = 0x4,
		},
		{
			.hw_status = 0x204,
		},
		{
			.hw_status = 0x404,
		},
		{
			.hw_status = 0x604,
		},
		{
			.hw_status = 0x804,
		},
		{
			.hw_status = 0xA04,
		},
		{
			.hw_status = 0xC04,
		},
		{
			.hw_status = 0xE04,
		},
		{
			.hw_status = 0x1004,
		},
		{
			.hw_status = 0x1204,
		},
		{
			.hw_status = 0x1404,
		},
		{
			.hw_status = 0x1604,
		},
		{
			.hw_status = 0x1804,
		},
		{
			.hw_status = 0x1A04,
		},
		{
			.hw_status = 0x1C04,
		},
		{
			.hw_status = 0x1E04,
		},
		{
			.hw_status = 0x2204,
		},
		{
			.hw_status = 0x2604,
		},
		{
			.hw_status = 0x2804,
		},
		{
			.hw_status = 0x2A04,
		},
		{
			.hw_status = 0x2C04,
		},
		{
			.hw_status = 0x2E04,
		},
		{
			.hw_status = 0x3004,
		},
		{
			.hw_status = 0x3204,
		},
		{
			.hw_status = 0x3404,
		},
		{
			.hw_status = 0x3604,
		},
		{
			.hw_status = 0x3804,
		},
		{
			.hw_status = 0x3A04,
		},
		{
			.hw_status = 0x3C04,
		},
		{
			.hw_status = 0x3E04,
		},
		{
			.hw_status = 0x4004,
		},
		{
			.hw_status = 0x4204,
		},
	},
};

static struct ope_hw ope_hw_100 = {
	.top_reg     = &ope_top_reg,
	.top_reg_val = &ope_top_reg_val,
	.bus_rd_reg  = &ope_bus_rd_reg,
	.bus_rd_reg_val  = &ope_bus_rd_reg_val,
	.bus_wr_reg  = &ope_bus_wr_reg,
	.bus_wr_reg_val  = &ope_bus_wr_reg_val,
	.pp_reg  = &ope_pp_reg,
	.common  = &common_data,
};

#endif /* CAM_OPE_HW_100_H */
