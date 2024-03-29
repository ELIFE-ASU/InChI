/*
 * International Chemical Identifier (InChI)
 * Version 1
 * Software version 1.05
 * January 27, 2017
 *
 * The InChI library and programs are free software developed under the
 * auspices of the International Union of Pure and Applied Chemistry (IUPAC).
 * Originally developed at NIST.
 * Modifications and additions by IUPAC and the InChI Trust.
 * Some portions of code were developed/changed by external contributors
 * (either contractor or volunteer) which are listed in the file
 * 'External-contributors' included in this distribution.
 *
 * IUPAC/InChI-Trust Licence No.1.0 for the
 * International Chemical Identifier (InChI)
 * Copyright (C) IUPAC and InChI Trust Limited
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the IUPAC/InChI Trust InChI Licence No.1.0,
 * or any later version.
 *
 * Please note that this library is distributed WITHOUT ANY WARRANTIES
 * whatsoever, whether expressed or implied.
 * See the IUPAC/InChI-Trust InChI Licence No.1.0 for more details.
 *
 * You should have received a copy of the IUPAC/InChI Trust InChI
 * Licence No. 1.0 with this library; if not, please write to:
 *
 * The InChI Trust
 * 8 Cavendish Avenue
 * Cambridge CB1 7US
 * UK
 *
 * or e-mail to alan@inchi-trust.org
 *
 */


#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* #include <varargs.h> */
#include <errno.h>
#include <limits.h>

#include "inchi/base/mode.h"
#ifndef COMPILE_ANSI_ONLY
#include <conio.h>
#endif

#include "inchi/base/incomdef.h"
#include "inchi/base/ichidrp.h"
#include "inchi/base/inpdef.h"
#include "inchi/base/ichi.h"
#include "inchi/base/strutil.h"
#include "inchi/base/util.h"
#include "inchi/base/ichidrp.h"
#include "inchi/base/ichierr.h"
#include "inchi/base/ichimain.h"
#include "inchi/base/extr_ct.h"
#ifdef TARGET_LIB_FOR_WINCHI
#include "inchi/base/../../../IChI_lib/src/ichi_lib.h"
#endif
#include "inchi/base/ichicomp.h"

#include "inchi/base/ichi_io.h"
#include "inchi/base/ichiparm.h"
