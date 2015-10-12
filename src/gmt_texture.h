/*--------------------------------------------------------------------
 *	$Id$
 *
 *	Copyright (c) 1991-2015 by P. Wessel, W. H. F. Smith, R. Scharroo, J. Luis and F. Wobbe
 *	See LICENSE.TXT file for copying and redistribution conditions.
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU Lesser General Public License as published by
 *	the Free Software Foundation; version 3 or any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Lesser General Public License for more details.
 *
 *	Contact info: gmt.soest.hawaii.edu
 *--------------------------------------------------------------------*/
/*
 * gmt_texture.h contains definitions of structures for pens, fills, and fonts.
 *
 * Author:	Paul Wessel
 * Date:	01-OCT-2009
 * Version:	5 API
 */

/*!
 * \file gmt_texture.h
 * \brief Definitions of structures for pens, fills, and fonts.
 */

#ifndef _GMT_TEXTURE_H
#define _GMT_TEXTURE_H

/*--------------------------------------------------------------------
 *			GMT TEXTURE STRUCTURE DEFINITIONS
 *--------------------------------------------------------------------*/

struct GMT_VECT_ATTR;	/* Forward declaration (declared in gmt_plot.h) */

/*! Holds line attributes */
struct GMT_LINE_END {
	double offset;		/* Offset the start or stop of the line by this amount before drawing */
	unsigned int type;	/* Projection type for distances */
	char unit;		/* Unit of the offset (X for Cartesian, C for plot distances in inch, else map distances) */
	/* Here we will also add vector head attributes in 5.3 */
	double length;
	struct GMT_VECT_ATTR *V;
};

/*! Holds pen attributes */
struct GMT_PEN {
	double width;			/* In points */
	double offset;			/* In points */
	double rgb[4];			/* RGB color of pen + Transparency 0-1 [0 = opaque] */
	char style[GMT_PEN_LEN];	/* Uses points as unit internally */
	/* For line modifications: */
	unsigned int mode;		/* Line-type: PSL_LINEAR [0; default] or PSL_BEZIER [1] */
	struct GMT_LINE_END end[2];	/* What happens at each end of the line (see above) */
};

/*! Holds fill attributes */
struct GMT_FILL {
	double rgb[4];			/* Chosen color if no pattern + Transparency 0-1 [0 = opaque] */
	double f_rgb[4], b_rgb[4];	/* Colors applied to unset and set bits in 1-bit image */
	bool use_pattern;		/* true if pattern rather than rgb is set */
	int pattern_no;			/* Number of a predefined pattern, or -1 if not set */
	unsigned int dpi;		/* Desired dpi of image building-block if use_pattern is true */
	char pattern[GMT_BUFSIZ];	/* Full filename of user-defined raster pattern */
};

/*! Holds font attributes */
struct GMT_FONT {
	double size;			/* Font size in points */
	unsigned int id;		/* Font ID number from predefined list */
	unsigned int form;		/* Combination of binary 1 = fill, 2 = outline, 4 = pattern fill [1] */
	struct GMT_FILL fill;		/* Font fill [black] */
	struct GMT_PEN pen;		/* Font outline pen [none] */
};

/*! Holds information for each predefined font */
struct GMT_FONTSPEC {
	double height;			/* Height of letter "A" for unit fontsize */
	char *name;			/* Name of the font */
};

/*! Holds information about paper sizes in points */
struct GMT_MEDIA {
	double width;		/* Width in points */
	double height;		/* Height in points */
};

#endif  /* _GMT_TEXTURE_H */
