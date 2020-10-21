#include "engine/GameManager.h"
#include "engine/GameRenderer.h"
 
auto pGameManager = Engine::GameManager::GetInstance();
auto pCamera = Engine::GameRenderer::GetInstance()->GetCamera();

for (uint64_t i = 0; i < pGameManager->GetEntities().GetSize(); i++)
{
	Engine::Entity* pEntity = pGameManager->GetEntities()[i];
	Engine::Vector3 screenPosition = pCamera->WorldToScreen(pEntity->GetPosition());
	float distance = pCamera->GetViewTranslation().Distance(pEntity->GetPosition());

	if (screenPosition.z >= 1.0f)
	{
		printf("test");
	}
}