#pragma once

#define ADDRESS_GAMEMANAGER 0x5E00F28 // Game->
#define ADDRESS_PROFILEMANAGER 0x4330E28 // Game->


#define OFFSET_PROFILEMANAGER_LOCAL_CAMERA 0x88 // ProfileManager->
#define OFFSET_PROFILEMANAGER_ENGINE_CAMERA 0x220 // ProfileManager->LocalCamera->
#define OFFSET_PROFILEMANAGER_CAMERAMANAGER 0x410 // ProfileManager->LocalCamera->Engine->

#define OFFSET_CAMERA_VIEWRIGHT 0x7A0 // Camera->
#define OFFSET_CAMERA_VIEWUP 0x7B0 // Camera->
#define OFFSET_CAMERA_VIEFORWARD 0x7C0 // Camera->
#define OFFSET_CAMERA_VIEWTRANSLATION 0x7D0 // Camera->
#define OFFSET_CAMERA_VIEWFOVX 0x7E0 // Camera->
#define OFFSET_CAMERA_VIEWFOVY 0x7F4 // Camera->

#define OFFSET_GAMEMANAGER_ENTITYLIST 0xE0 // GameManager->
#define OFFSET_GAMEMANAGER_ENTITYCOUNT 0xE8 // GameManager->

#define OFFSET_GAMEMANAGER_ENTITY_INDEX 0x8 // EntityList->

#define OFFSET_ENTITY_ENTITYINFO 0x50 // EntityList->INDEX->Entity->

#define OFFSET_ENTITY_POSITION 0x1100 // Entity->
#define OFFSET_ENTITY_HEADPOSITION 0x1070 // Entity->
