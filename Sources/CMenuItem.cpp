/*	$Id$
	
	Copyright 1996, 1997, 1998, 2002
	        Hekkelman Programmatuur B.V.  All rights reserved.
	
	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:
	1. Redistributions of source code must retain the above copyright notice,
	   this list of conditions and the following disclaimer.
	2. Redistributions in binary form must reproduce the above copyright notice,
	   this list of conditions and the following disclaimer in the documentation
	   and/or other materials provided with the distribution.
	3. All advertising materials mentioning features or use of this software
	   must display the following acknowledgement:
	   
	    This product includes software developed by Hekkelman Programmatuur B.V.
	
	4. The name of Hekkelman Programmatuur B.V. may not be used to endorse or
	   promote products derived from this software without specific prior
	   written permission.
	
	THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
	INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
	FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
	AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
	EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
	PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
	OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
	WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
	OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
	ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 	

	Created: 11/23/97 16:13:36 by Maarten Hekkelman
*/

#include "pe.h"
#include "CMenuItem.h"

BBitmap *CMenuItem::sfBitmap = NULL;

CMenuItem::CMenuItem(BMenu *subMenu)
	: BMenuItem(subMenu)
{
	if (!sfBitmap)
	{
		sfBitmap = new BBitmap(BRect(0, 0, 15, 15), B_COLOR_8_BIT);
		
		BMimeType mime(PE_DEFAULT_IDE_APPSIG);
		mime.GetIcon(sfBitmap, B_MINI_ICON);
	}
} /* CMenuItem::CMenuItem */

void CMenuItem::DrawContent()
{
	Menu()->SetDrawingMode(B_OP_OVER);
	Menu()->DrawBitmap(sfBitmap, ContentLocation());
	Menu()->SetDrawingMode(B_OP_COPY);
} /* CMenuItem::Draw */

void CMenuItem::GetContentSize(float *width, float *height)
{
	*width = *height = 16;
} /* CMenuItem::GetContentSize */
