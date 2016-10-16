#pragma once

#include "MZFileSystem.h"
#include "ZSoundEngine.h"
#include "ZDirectInput.h"
#include "MDataChecker.h"
#include "ZLanguageConf.h"
#include "ZTimer.h"
#include "ZEmblemInterface.h"
#include "ZStageInterface.h"
#include "ZSkill.h"
#include "ZWorldManager.h"

class ZGame;
class ZGameClient;
class ZGameInterface;
class ZLoadingProgress;
class ZProfiler;
class ZOptionInterface;

enum GunzState{
	GUNZ_NA = 0,
	GUNZ_GAME = 1,
	GUNZ_LOGIN = 2,
	GUNZ_NETMARBLELOGIN = 3,
	GUNZ_LOBBY = 4,
	GUNZ_STAGE = 5,
	GUNZ_GREETER = 6,
	GUNZ_CHARSELECTION = 7,
	GUNZ_CHARCREATION = 8,
	GUNZ_PREVIOUS = 10,
	GUNZ_SHUTDOWN = 11,
	GUNZ_BIRDTEST
};

class ZApplication 
{
public:
	enum ZLAUNCH_MODE {
		ZLAUNCH_MODE_DEBUG,
		ZLAUNCH_MODE_NETMARBLE,
		ZLAUNCH_MODE_STANDALONE,
		ZLAUNCH_MODE_STANDALONE_DEVELOP,
		ZLAUNCH_MODE_STANDALONE_REPLAY,
		ZLAUNCH_MODE_STANDALONE_GAME,
		ZLAUNCH_MODE_STANDALONE_DUMMY,
		ZLAUNCH_MODE_STANDALONE_AI,
		ZLAUNCH_MODE_STANDALONE_QUEST,
	};

private:
	ZGameInterface*			m_pGameInterface;
	GunzState				m_nInitialState;
	ZStageInterface*		m_pStageInterface;
	ZOptionInterface*		m_pOptionInterface;
	ZLAUNCH_MODE			m_nLaunchMode;
    char					m_szFileName[_MAX_PATH];
	char					m_szCmdLine[256];
	UINT					m_nTimerRes;
	MDataChecker			m_GlobalDataChecker;
	bool					m_bLaunchDevelop;
	bool					m_bLaunchTest;
	u64 Time = 0;
	float Timescale = 1.f;

	void ParseStandAloneArguments(const char* pszArgs);
protected:
	static ZApplication*	m_pInstance;
	static MZFileSystem		m_FileSystem;
	static ZSoundEngine		m_SoundEngine;
	static RMeshMgr			m_NPCMeshMgr;
	static RMeshMgr			m_MeshMgr;
	static RMeshMgr			m_WeaponMeshMgr;
	static ZTimer			m_Timer;
	static ZEmblemInterface	m_EmblemInterface;
	static ZSkillManager	m_SkillManager;
	ZWorldManager			m_WorldManager;
	MZFileCheckList			m_fileCheckList;
#ifdef _ZPROFILER
	ZProfiler				*m_pProfiler;
#endif

public:
	ZApplication();
	~ZApplication();

	bool ParseArguments(const char* pszArgs);
	void SetInterface();
	void SetNextInterface();
	void CheckSound();
	void SetInitialState();
	template<size_t size>
	bool GetSystemValue(const char* szField, char(&szData)[size]) {
		return GetSystemValue(szField, szData, size);
	}
	bool GetSystemValue(const char* szField, char* szData, int maxlen);
	void SetSystemValue(const char* szField, const char* szData);

	void InitFileSystem();

	bool OnCreate(ZLoadingProgress *pLoadingProgress);
	void OnDestroy();
	bool OnDraw();
	void OnUpdate();
	void OnInvalidate();
	void OnRestore();

	static void ResetTimer();
	static void Exit();
	static ZApplication*		GetInstance(void);
	static ZGameInterface*		GetGameInterface(void);
	static ZStageInterface*		GetStageInterface(void);
	static ZOptionInterface*	GetOptionInterface(void);
	static MZFileSystem*		GetFileSystem(void);
	static ZGameClient*			GetGameClient(void);
	static ZGame*				GetGame(void);
	static ZTimer*				GetTimer(void);
	static ZSoundEngine*		GetSoundEngine(void);
	static RMeshMgr*			GetNpcMeshMgr()			{ return &m_NPCMeshMgr;}
	static RMeshMgr*			GetMeshMgr()			{ return &m_MeshMgr; }
	static RMeshMgr*			GetWeaponMeshMgr()		{ return &m_WeaponMeshMgr; }
	static ZEmblemInterface*	GetEmblemInterface()	{ return &m_EmblemInterface; }
	static ZSkillManager*		GetSkillManager()		{ return &m_SkillManager; }
	ZWorldManager*				GetWorldManager()		{ return &m_WorldManager; }

	__forceinline ZLAUNCH_MODE GetLaunchMode()			{ return m_nLaunchMode; }
	__forceinline void SetLaunchMode(ZLAUNCH_MODE nMode)	{ m_nLaunchMode = nMode; }
	__forceinline bool IsLaunchDevelop()					{ return m_bLaunchDevelop; }
	__forceinline bool IsLaunchTest()					{ return m_bLaunchTest; }

	__forceinline unsigned int GetFileListCRC()			{ return m_fileCheckList.GetCRC32(); }

	bool InitLocale();
	void PreCheckArguments();

	auto GetTime() const { return Time; }
	auto GetTimescale() const { return Timescale; }
	void SetTimescale(float f) { Timescale = f; }
};