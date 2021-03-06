// Copyright (c) 2015 fjz13. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.
#pragma once
#include "MedusaPreDeclares.h"
#include "Core/String/HeapString.h"
#include "Core/Pattern/ISharable.h"
#include "TiledTileset.h"

MEDUSA_BEGIN;

class TiledTilesetRef 
{
public:
	TiledTilesetRef();
	~TiledTilesetRef();
	bool operator==(const TiledTilesetRef& val)const { return mFirstGlobalId == val.mFirstGlobalId; }
	bool Parse(const pugi::xml_node& node);

	uint FirstGlobalId() const { return mFirstGlobalId; }
	void SetFirstGlobalId(uint val) { mFirstGlobalId = val; }

	StringRef Name() const { return mName; }
	void SetName(const StringRef& val) { mName = val; }

	const Share<TiledTileset>& Tileset() const { return mTileset; }
	void SetTileset(const Share<TiledTileset>& val);
private:
	uint mFirstGlobalId=0;
	HeapString mName;

	Share<TiledTileset> mTileset=nullptr;
	

};

MEDUSA_END;
