#pragma once

#include <deque>
#include <functional>
#include "stuff.h"
#include "AnimationStuff.h"

class BasicInfoHistoryManager
{
public:
	void AddBasicInfo(BasicInfoItem bii);

	struct Info
	{
		v3* Head{};
		v3* Pos{};
		v3* Dir{};
		v3* CameraDir{};
	};

	bool GetInfo(const Info& Out, double Time,
		const std::function<MMatchItemDesc*(MMatchCharItemParts)>& GetItemDesc,
		MMatchSex Sex, bool IsDead) const;
	
	bool empty() const { return BasicInfoList.empty(); }
	auto& front() const { return BasicInfoList.front(); }
	void clear() { BasicInfoList.clear(); }

private:
	std::deque<BasicInfoItem> BasicInfoList;
};