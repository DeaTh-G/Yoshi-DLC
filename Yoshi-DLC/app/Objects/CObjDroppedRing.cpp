#include "pch.h"

HOOK(void, __fastcall, ProcMsgHitEventCollisionHook, ASLR(0x00662320), int* This, void* edx, int* message)
{
	const char* packFileName = app::ObjUtil::GetStagePackName(*app::Document);
	if (strncmp(packFileName, "zdlc02", 6) == 0)
	{
		app::xgame::MsgTakeObject msgTakeObject{ 0 };
		app::game::EffectCreateInfo effectInfo;

		int* gocSound;
		int* gocEffect;
		int something[3];
		int effectVar = 0;

		if ((This[0xD2] & 0x40) == 0)
		{
			app::xgame::MsgTakeObject::SetShapeUserID(&msgTakeObject, *(int*)(message[7] + 0xBC));
			if (app::fnd::CActor::SendMessageImmOld((int*)This + 2, message[8], (int*)&msgTakeObject))
			{
				if (This[0xCA])
					app::game::GOCEffect::CreateEffect((int*)This[0xCA], "ef_dl2_coin_get");

				gocSound = app::GameObject::GetGOC((app::GameObject*)This, GOCSoundString);
				if (gocSound)
					app::game::GOCSound::Play(gocSound, something, "obj_yossycoin_get", 0);

				int playerNo = app::ObjUtil::GetPlayerNo(This[0xA], message[8]);
				if ((This[0xD2] & 4) != 0)
					app::ObjUtil::AddScorePlayerAction((app::GameObject*)This, "GET_DROPPED_YOSHICOIN", playerNo);
				else
					app::ObjUtil::AddScorePlayerAction((app::GameObject*)This, "GET_YOSHICOIN", playerNo);

				This[0xD2] |= 0x40;
				app::GameObject::Kill((app::GameObject*)This);
			}
			app::xgame::MsgExtendPlayer::__dt((int*)&msgTakeObject);
		}
	}
	else
	{
		originalProcMsgHitEventCollisionHook(This, edx, message);
	}
}

void app::CObjDroppedRing::ProcMsgHitEventCollision()
{
	INSTALL_HOOK(ProcMsgHitEventCollisionHook);
}
