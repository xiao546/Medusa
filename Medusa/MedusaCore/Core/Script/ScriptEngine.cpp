// Copyright (c) 2015 fjz13. All rights reserved.
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file.
#include "MedusaCorePreCompiled.h"
#ifdef MEDUSA_SCRIPT

#include "ScriptEngine.h"
#include "Core/Event/EventArg/UserDataEventArg.h"
#include "Core/IO/FileId.h"
#include "Core/IO/FileSystem.h"
MEDUSA_BEGIN;

ScriptEngine::ScriptEngine()
	:IModule("ScriptEngine")
{
	this->Retain();		//retain self
}

ScriptEngine::~ScriptEngine(void)
{
	Uninitialize();
}

bool ScriptEngine::Initialize()
{
#ifdef MEDUSA_LUA
	mCurrent = new LuaMachine();
	mCurrent->Initialize();
	if (!mPath.IsEmpty())
	{
		mCurrent->SetPackagePath(mPath);
	}
#endif
	return true;
}

bool ScriptEngine::Uninitialize()
{
	SAFE_DELETE(mCurrent);
	return true;
}

bool ScriptEngine::OnLoad(IEventArg& e /*= IEventArg::Empty*/)
{
	return Initialize();
}

bool ScriptEngine::OnUnload(IEventArg& e /*= IEventArg::Empty*/)
{
	Uninitialize();
	return true;
}

bool ScriptEngine::OnChildLoad(IModule& child, IEventArg& e /*= IEventArg::Empty*/)
{
	UserDataEventArg<ScriptState*> e1(mCurrent->CurrentState());
	return child.Load(e1);
}

bool ScriptEngine::OnChildUnload(IModule& child, IEventArg& e /*= IEventArg::Empty*/)
{
	UserDataEventArg<ScriptState*> e1(mCurrent->CurrentState());
	return child.Unload(e1);
}

bool ScriptEngine::OnChildReload(IModule& child, IEventArg& e /*= IEventArg::Empty*/)
{
	UserDataEventArg<ScriptState*> e1(mCurrent->CurrentState());
	return child.Reload(e1);
}


ScriptState* ScriptEngine::State()
{
	if (Instance().Current()!=nullptr)
	{
		return Instance().Current()->CurrentState();
	}
	return nullptr;
}

bool ScriptEngine::ExistsScriptFile(StringRef name)
{
	FileId fileId;
#ifdef MEDUSA_LUA
	fileId.Name = name + FileExtensions::lua;
#endif
	return FileSystem::Instance().Exists(fileId);
}


MEDUSA_END;

#endif