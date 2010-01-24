/*
 * Copyright (C) 2004-2010 Geometer Plus <contact@geometerplus.com>
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

#include "ZLCocoaImageManager.h"

ZLCocoaImageData::ZLCocoaImageData() : myUIImage(0) {
}

ZLCocoaImageData::~ZLCocoaImageData() {
}

unsigned int ZLCocoaImageData::width() const {
	if (myUIImage == 0) {
		return 0;
	}
	UIImage *uiImage = (UIImage*)myUIImage;
	return [uiImage size].width;
}

unsigned int ZLCocoaImageData::height() const {
	if (myUIImage == 0) {
		return 0;
	}
	UIImage *uiImage = (UIImage*)myUIImage;
	return [uiImage size].height;
}

void ZLCocoaImageData::init(unsigned int width, unsigned int height) {
	// TODO: implement
}

void ZLCocoaImageData::setPosition(unsigned int x, unsigned int y) {
	// TODO: implement
}

void ZLCocoaImageData::moveX(int delta) {
	// TODO: implement
}

void ZLCocoaImageData::moveY(int delta) {
	// TODO: implement
}

void ZLCocoaImageData::setPixel(unsigned char r, unsigned char g, unsigned char b) {
	// TODO: implement
}

void ZLCocoaImageData::copyFrom(const ZLImageData &source, unsigned int targetX, unsigned int targetY) {
	// TODO: implement
}

void *ZLCocoaImageData::uiImage() const {
	return myUIImage;
}

shared_ptr<ZLImageData> ZLCocoaImageManager::createData() const {
	return new ZLCocoaImageData();
}

void ZLCocoaImageManager::convertImageDirect(const std::string &stringData, ZLImageData &data) const {
	NSData *nsData = [NSData dataWithBytes:stringData.data()
									length:stringData.length()];
	((ZLCocoaImageData&)data).myUIImage = [[UIImage new] initWithData:nsData];
}