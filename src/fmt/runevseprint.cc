// Copyright 2010 Google Inc.
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//      http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ------------------------------------------------------------------------

/*
 * The authors of this software are Rob Pike and Ken Thompson.
 *              Copyright (c) 2002 by Lucent Technologies.
 * Permission to use, copy, modify, and distribute this software for any
 * purpose without fee is hereby granted, provided that this entire notice
 * is included in all copies of any software which is or includes a copy
 * or modification of this software and in all copies of the supporting
 * documentation for such software.
 * THIS SOFTWARE IS BEING PROVIDED "AS IS", WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY.  IN PARTICULAR, NEITHER THE AUTHORS NOR LUCENT TECHNOLOGIES MAKE ANY
 * REPRESENTATION OR WARRANTY OF ANY KIND CONCERNING THE MERCHANTABILITY
 * OF THIS SOFTWARE OR ITS FITNESS FOR ANY PARTICULAR PURPOSE.
 */
#include <stdarg.h>
#include <string.h>
#include "fmt/fmt.h"
#include "fmt/fmtdef.h"

namespace Fmt {

Rune*
Formatter::runevseprint(Rune *buf, Rune *e, const char *fmt, va_list *args)
{
	State f;

	if(e <= buf)
		return nil;
	f.runes = 1;
	f.start = buf;
	f.to = buf;
	f.stop = e - 1;
	f.flush = nil;
	f.farg = nil;
	f.nfmt = 0;
	f.args = args;
	f.formatter = this;
	dofmt(this, &f, fmt);
	*(Rune*)f.to = '\0';
	return (Rune*)f.to;
}

Rune*
runevseprint(Rune *buf, Rune *e, const char *fmt, va_list *args)
{
	return _stdfmt.runevseprint(buf, e, fmt, args);
}

}  /* end namespace Fmt */
