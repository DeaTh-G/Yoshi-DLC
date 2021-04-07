#include "pch.h"

void app::EggManager::StartExtrication(int playerNo)
{
    if (!playerNo)
        for (app::ObjEgg* egg : EggsP1)
            egg->StartExtrication();
    else
        for (app::ObjEgg* egg : EggsP2)
            egg->StartExtrication();

    IsSpaceShrink |= 2;
}

bool app::EggManager::AddEgg(ObjEgg* egg)
{
    if (!egg->PlayerNo)
    {
        if (EggsP1.size() >= 0xC)
            return false;

        EggsP1.push_back(egg);
        return true;
    }
    else
    {
        if (EggsP2.size() >= 0xC)
            return false;

        EggsP2.push_back(egg);
        return true;
    }
}

int app::EggManager::GetTargetLocusIndex(int index, char playerNo)
{
    int result{};

    int* playerInfo = ObjUtil::GetPlayerInformation(Document, playerNo);
    if (!playerInfo)
        return 0;

    if (!playerNo)
        for (size_t i = 0; i <= index; i++)
            result += EggsP1.at(i)->SpaceCount;
    else
        for (size_t i = 0; i <= index; i++)
            result += EggsP2.at(i)->SpaceCount;

    return result;
}

void app::EggManager::DoCheckReleaseAllEgg(const fnd::SUpdateInfo updateInfo, int playerNo)
{
    int* playerInfo = ObjUtil::GetPlayerInformation(Document, playerNo);
    if (!playerInfo)
        return;

    bool isDamaged = *((char*)playerInfo + 0x172);
    bool isDead = *((char*)playerInfo + 0x171);
    if (isDamaged || isDead)
    {
        if (IsSpaceShrink & 8)
            return;

        if (!playerNo)
        {
            for (ObjEgg* egg : EggsP1)
            {
                egg->StartDrop();
                egg->Time = updateInfo.deltaTime;
                egg->Frame = 0;
            }
            
            EggsP1.clear();
        }
        else
        {
            for (ObjEgg* egg : EggsP2)
            {
                egg->StartDrop();
                egg->Time = updateInfo.deltaTime;
                egg->Frame = 0;
            }
            EggsP2.clear();
        }

        IsSpaceShrink |= 8;
    }
    else
    {
        IsSpaceShrink &= ~8;
    }
}

void app::EggManager::DoCheckClearAllEggEndExtrication(int playerNo)
{
    if (!(IsSpaceShrink & 2))
        return;
    
    if (!playerNo)
    {
        if (EggsP1.empty())
            return;

        for (app::ObjEgg* egg : EggsP1)
            if (!egg->IsEndExtrication())
                return;

        for (app::ObjEgg* egg : EggsP1)
            GameObject::Kill(egg);
        
        EggsP1.clear();
        IsSpaceShrink &= ~2;
    }
    else
    {
        if (EggsP2.empty())
            return;

        for (app::ObjEgg* egg : EggsP2)
            if (!egg->IsEndExtrication())
                return;

        for (app::ObjEgg* egg : EggsP2)
            GameObject::Kill(egg);

        EggsP2.clear();
        IsSpaceShrink &= ~2;
    }
}

char app::EggManager::AddSpaceCount(int playerNo)
{
    if (!playerNo)
        for (app::ObjEgg* egg : EggsP1)
            egg->AddSpaceOffset();
    else
        for (app::ObjEgg* egg : EggsP2)
            egg->AddSpaceOffset();

    IsSpaceShrink |= 4;
    return IsSpaceShrink;
}

char app::EggManager::SubSpaceCount(int playerNo)
{
    if (!playerNo)
        for (app::ObjEgg* egg : EggsP1)
            egg->SubSpaceOffset();
    else
        for (app::ObjEgg* egg : EggsP2)
            egg->SubSpaceOffset();

    IsSpaceShrink |= 4;
    return IsSpaceShrink;
}

void app::EggManager::UpdateEggSpace(const fnd::SUpdateInfo& updateInfo, int playerNo)
{
    IsSpaceShrink &= ~4;

    int* playerInfo = app::ObjUtil::GetPlayerInformation(Document, playerNo);
    if (!playerInfo)
        return;

    if (!playerNo)
    {
        if (*((char*)playerInfo + 0x145) && *((char*)playerInfo + 0x144))
        {
            csl::math::Vector3 playerPos{ *(csl::math::Vector3*)(playerInfo + 4) };
            if (!EggsP1.size())
                return;

            SubSpaceCount(playerNo);

            if (!EggsP1.at(EggsP1.size() - 1)->SpaceCount)
            {
                for (size_t i = 0; i < EggsP1.size() * 10; i++)
                {
                    LocusData data{ playerPos, *(csl::math::Quaternion*)(playerInfo + 8),
                        *((char*)playerInfo + 0x144) ^ 1 };
                    GhostDataP1.push_front(data);
                }
            }

            return;
        }

        if (IsSpaceShrink & 1)
        {
            SubSpaceCount(playerNo);
            return;
        }

        if (field_64P1 > 0)
        {
            AddSpaceCount(playerNo);
            return;
        }
    }
    else
    {
        if (*((char*)playerInfo + 0x145) && *((char*)playerInfo + 0x144))
        {
            SubSpaceCount(playerNo);
            return;
        }

        if (IsSpaceShrink & 1)
        {
            SubSpaceCount(playerNo);
            return;
        }

        if (field_64P2 > 0)
        {
            AddSpaceCount(playerNo);
            return;
        }
    }
}