/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:08:24 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:55:00 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACRO_H
# define MACRO_H

# define PI 		3.14159265359
# define SPLITLEN	100000
# define MININT		-2147483648
# define MAXINT		2147483647
# define RED 		0xFF0000
# define GREEN 		0x00FF00
# define BLUE 		0x0000FF
# define YELLOW 	0xFFFF00
# define PINK 		0xFF00FF
# define LIGHT_BLUE 0x00FFFF
# define WHITE 		0xFFFFFF
# define BLACK 		0

# define EXITONNULL 1

enum e_keycode
{
	KEYCODE_A = 0,
	KEYCODE_S = 1,
	KEYCODE_D = 2,
	KEYCODE_F = 3,
	KEYCODE_H = 4,
	KEYCODE_G = 5,
	KEYCODE_Y = 6,
	KEYCODE_X = 7,
	KEYCODE_C = 8,
	KEYCODE_V = 9,
	KEYCODE_RAN = 10,
	KEYCODE_B = 11,
	KEYCODE_Q = 12,
	KEYCODE_W = 13,
	KEYCODE_E = 14,
	KEYCODE_R = 15,
	KEYCODE_Z = 18,
	KEYCODE_T = 17,
	KEYCODE_1 = 18,
	KEYCODE_2 = 19,
	KEYCODE_3 = 20,
	KEYCODE_4 = 21,
	KEYCODE_6 = 22,
	KEYCODE_5 = 23,
	KEYCODE_9 = 25,
	KEYCODE_7 = 26,
	KEYCODE_8 = 28,
	KEYCODE_0 = 29,
	KEYCODE_O = 31,
	KEYCODE_I = 34,
	KEYCODE_L = 37,
	KEYCODE_K = 40,
	KEYCODE_TAB = 49,
	KEYCODE_SPACE = 49,
	KEYCODE_LEFT_ARROW = 123,
	KEYCODE_RIGHT_ARROW = 124,
	KEYCODE_DOWN_ARROW = 125,
	KEYCODE_UP_ARROW = 126,
	KEYCODE_LSHIFT = 257,
	KEYCODE_RSHIFT = 258,
};

#endif
