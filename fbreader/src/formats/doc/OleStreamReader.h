/*
 * Copyright (C) 2009-2010 Geometer Plus <contact@geometerplus.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#ifndef __OLESTREAMREADER_H__
#define __OLESTREAMREADER_H__

#include <ZLUnicodeUtil.h>
#include <ZLEncodingConverter.h>

#include "OleStream.h"

class OleStreamReader {

public:
	//word's control chars:
	static const ZLUnicodeUtil::Ucs2Char WORD_FOOTNOTE_MARK;
	static const ZLUnicodeUtil::Ucs2Char WORD_TABLE_SEPARATOR;
	static const ZLUnicodeUtil::Ucs2Char WORD_HORIZONTAL_TAB;
	static const ZLUnicodeUtil::Ucs2Char WORD_HARD_LINEBREAK;
	static const ZLUnicodeUtil::Ucs2Char WORD_PAGE_BREAK;
	static const ZLUnicodeUtil::Ucs2Char WORD_END_OF_PARAGRAPH;
	static const ZLUnicodeUtil::Ucs2Char WORD_SHORT_DEFIS;
	static const ZLUnicodeUtil::Ucs2Char WORD_SOFT_HYPHEN;
	static const ZLUnicodeUtil::Ucs2Char WORD_START_FIELD;
	static const ZLUnicodeUtil::Ucs2Char WORD_SEPARATOR_FIELD;
	static const ZLUnicodeUtil::Ucs2Char WORD_END_FIELD;
	static const ZLUnicodeUtil::Ucs2Char WORD_ZERO_WIDTH_UNBREAKABLE_SPACE;

	//unicode values:
	static const ZLUnicodeUtil::Ucs2Char NULL_SYMBOL;
	static const ZLUnicodeUtil::Ucs2Char FILE_SEPARATOR;
	static const ZLUnicodeUtil::Ucs2Char LINE_FEED;
	static const ZLUnicodeUtil::Ucs2Char SOFT_HYPHEN;
	static const ZLUnicodeUtil::Ucs2Char START_OF_HEADING;
	static const ZLUnicodeUtil::Ucs2Char SPACE;
	static const ZLUnicodeUtil::Ucs2Char SHORT_DEFIS;
	static const ZLUnicodeUtil::Ucs2Char VERTICAL_LINE;

public:
	OleStreamReader(const std::string& encoding);

	bool readStream(OleStream &stream);
	void clear();

protected:
	//virtual void parapgraphHandler(std::string paragraph) = 0;
	virtual void handleChar(ZLUnicodeUtil::Ucs2Char ucs2char) = 0;
	virtual void handleHardLinebreak() = 0;
	virtual void handleParagraphEnd() = 0;
	virtual void handlePageBreak() = 0;
	virtual void handleTableSeparator() = 0;
	virtual void handleTableEndRow() = 0;
	virtual void handleFootNoteMark() = 0;
	virtual void handleStartField() = 0;
	virtual void handleSeparatorField() = 0;
	virtual void handleEndField() = 0;
	virtual void handleStartOfHeading() = 0;
	virtual void handleOtherControlChar(ZLUnicodeUtil::Ucs2Char ucs2char) = 0;

private:
	//TODO implement get8BitChar method
	bool getUcs2Char(OleStream& stream, ZLUnicodeUtil::Ucs2Char& ucs2char);

private:
	char myTmpBuffer[256];
	unsigned long myTextOffset;
	bool myBufIsUnicode;

	shared_ptr<ZLEncodingConverter> myConverter;
	const std::string myEncoding;
};

#endif /* __OLESTREAMREADER_H__ */