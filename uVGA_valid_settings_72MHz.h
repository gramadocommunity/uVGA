/*
	This file is part of uVGA library.

	uVGA library is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	uVGA library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with uVGA library.  If not, see <http://www.gnu.org/licenses/>.

	Copyright (C) 2017 Eric PREVOTEAU

	Original Author: Eric PREVOTEAU <digital.or@gmail.com>
*/

#ifndef UVGA_VALID_SETTINGS_72MHZ_H
#define UVGA_VALID_SETTINGS_72MHZ_H

#include <uVGA.h>

#if F_CPU == 72000000
extern "C"
{
#ifdef UVGA_DEFAULT_REZ

#if defined(__MK64FX512__) || defined(__MK66FX1M0__)
// Teensy 3.6 & 3.5
#define UVGA_72M_602X240
#elif defined(__MK20DX128__) || defined(__MK20DX256__)
// Teensy 3.2
#define UVGA_72M_255X120
#endif

#endif

// ======================================================
// valid video settings for 72MHz CPU
// * UVGA_72M_602X240 (640x480@60Hz, FB resolution: 602x240), fairly stable, very minor glitch. DMA starts to fail to compensate clock slowness
// * UVGA_72M_255X120 (640x480@60Hz, FB resolution: 255x120), fairly stable, very minor glitch. DMA starts to fail to compensate clock slowness. Use nearly all RAM on teensy 3.2.
// * UVGA_72M_166X120 (640x480@60Hz, FB resolution: 166x120), fairly stable, very minor glitch. DMA starts to fail to compensate clock slowness. compatible with teensy 3.2

#ifdef UVGA_72M_602X240
// 72Mhz, 640x480@60Hz, FB resolution: 602x240
#pragma message "72Mhz 602x240"

#define UVGA_HREZ 602
#define UVGA_VREZ 480
#define UVGA_RPTL 2
#define UVGA_TOP_MARGIN 0
#define UVGA_BOTTOM_MARGIN 0

uVGAmodeline modeline = {
   .pixel_clock = 25180000, //25.18Mhz
   .hres = UVGA_HREZ,
   .hsync_start = 656,
   .hsync_end = 752,
   .htotal = 800,
   .vres = UVGA_VREZ,
   .vsync_start = 490,
   .vsync_end = 492,
   .vtotal = 525,
	.top_margin = UVGA_TOP_MARGIN,
	.bottom_margin = UVGA_BOTTOM_MARGIN,
   .h_polarity = UVGA_NEGATIVE_POLARITY,
   .v_polarity = UVGA_NEGATIVE_POLARITY,
   .img_color_mode = UVGA_RGB332,
   .repeat_line = UVGA_RPTL,
   .horizontal_position_shift = 8,
	.pixel_h_stretch = UVGA_HSTRETCH_NORMAL,
	.dma_settings = UVGA_DMA_AUTO,
	};
#endif

#ifdef UVGA_72M_255X120
// 72Mhz, 640x480@60Hz, FB resolution: 255x120
#pragma message "72Mhz 255x120"

#define UVGA_HREZ 255
#define UVGA_VREZ 480
#define UVGA_RPTL 4
#define UVGA_TOP_MARGIN 0
#define UVGA_BOTTOM_MARGIN 0

uVGAmodeline modeline = {
   .pixel_clock = 25180000, //25.18Mhz
   .hres = UVGA_HREZ,
   .hsync_start = 656,
   .hsync_end = 752,
   .htotal = 800,
   .vres = UVGA_VREZ,
   .vsync_start = 490,
   .vsync_end = 492,
   .vtotal = 525,
	.top_margin = UVGA_TOP_MARGIN,
	.bottom_margin = UVGA_BOTTOM_MARGIN,
   .h_polarity = UVGA_NEGATIVE_POLARITY,
   .v_polarity = UVGA_NEGATIVE_POLARITY,
   .img_color_mode = UVGA_RGB332,
   .repeat_line = UVGA_RPTL,
   .horizontal_position_shift = 8,
	.pixel_h_stretch = UVGA_HSTRETCH_WIDE,
	.dma_settings = UVGA_DMA_SINGLE,
	};
#endif

#ifdef UVGA_72M_166X120
// 72Mhz, 640x480@60Hz, FB resolution: 166x120
#pragma message "72Mhz 166x120"

#define UVGA_HREZ 166
#define UVGA_VREZ 480
#define UVGA_RPTL 4
#define UVGA_TOP_MARGIN 0
#define UVGA_BOTTOM_MARGIN 0

uVGAmodeline modeline = {
   .pixel_clock = 25180000, //25.18Mhz
   .hres = UVGA_HREZ,
   .hsync_start = 656,
   .hsync_end = 752,
   .htotal = 800,
   .vres = UVGA_VREZ,
   .vsync_start = 490,
   .vsync_end = 492,
   .vtotal = 525,
	.top_margin = UVGA_TOP_MARGIN,
	.bottom_margin = UVGA_BOTTOM_MARGIN,
   .h_polarity = UVGA_NEGATIVE_POLARITY,
   .v_polarity = UVGA_NEGATIVE_POLARITY,
   .img_color_mode = UVGA_RGB332,
   .repeat_line = UVGA_RPTL,
   .horizontal_position_shift = 8,
	.pixel_h_stretch = UVGA_HSTRETCH_ULTRA_WIDE,
	.dma_settings = UVGA_DMA_SINGLE,
	};
#endif

}
#endif
#endif
