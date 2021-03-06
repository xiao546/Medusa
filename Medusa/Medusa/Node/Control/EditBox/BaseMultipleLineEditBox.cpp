// Copyright (c) 2015 fjz13. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.
#include "MedusaPreCompiled.h"
#include "BaseMultipleLineEditBox.h"
#include "Node/NodeFactory.h"
#include "Node/Control/Label/ILabel.h"
#include "Node/NodeFactory.h"
MEDUSA_BEGIN;


BaseMultipleLineEditBox::BaseMultipleLineEditBox(StringRef name, const Size2F& size, const FontId& fontId, WStringRef text /*= WStringRef::Empty*/, Alignment alignment /*= Alignment::LeftBottom*/)
	:IEditBox(name)
{
	mTextLabel = NodeFactory::Instance().CreateMultipleLineLabel( fontId, text, alignment, size);
	mTextLabel->EnableManaged();
	AddChild(mTextLabel);

	mPlaceHolderLabel = NodeFactory::Instance().CreateMultipleLineLabel(fontId, WStringRef::Empty, alignment, size, true);
	mPlaceHolderLabel->EnableManaged();

	AddChild(mPlaceHolderLabel);

	OnUpdateStatus();

}

BaseMultipleLineEditBox::BaseMultipleLineEditBox(const StringRef& name /*= StringRef::Empty*/, const IEventArg& e /*= IEventArg::Empty*/)
	:IEditBox(name,e)
{

}

BaseMultipleLineEditBox::~BaseMultipleLineEditBox(void)
{

}


MEDUSA_END;
