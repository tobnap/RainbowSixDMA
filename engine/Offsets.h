/**
 * Rainbow Six: Siege SDK
 * Copyright (C) 2017 RangeMachine
 */

#pragma once

#define ADDRESS_GAMEMANAGER 0x435B1B0 // Game->
#define ADDRESS_GAMERENDERER 0x4330E28 // Game->

#define OFFSET_GAMERENDERER_ENGINE 0x20 // GameRenderer->
#define OFFSET_GAMERENDERER_ENGINE_CAMERA 0x2F0 // GameRenderer->Engine->

#define OFFSET_CAMERA_VIEWRIGHT 0x560 // Camera->
#define OFFSET_CAMERA_VIEWUP 0x570 // Camera->
#define OFFSET_CAMERA_VIEFORWARD 0x580 // Camera->
#define OFFSET_CAMERA_VIEWTRANSLATION 0x590 // Camera->
#define OFFSET_CAMERA_VIEWFOVX 0x5A0 // Camera->
#define OFFSET_CAMERA_VIEWFOVY 0x5B4 // Camera->

#define OFFSET_GAMEMANAGER_ENTITYLIST 0xB8 // GameManager->

#define OFFSET_ENTITY_POSITION 0x190 // Entity->
#define OFFSET_ENTITY_HEADPOSITION 0x130 // Entity->