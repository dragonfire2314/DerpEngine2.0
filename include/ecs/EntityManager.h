#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <unordered_map>
#include <vector>

#include <core.h>
#include <ecs/Entity.h>

namespace DERP 
{
	namespace EM
	{
		void Init();
		uint32_t CreateEntity();
		uint32_t CreateEntity(uint32_t entityID);
		Entity* getEntity(uint32_t entityID);

		bool isComponent(uint32_t entityID, uint32_t componentID);
		void addComponent(uint32_t entityID, uint32_t componentID);

		std::bitset<UINT8_MAX> getSignature(uint32_t entityID);
	}
}

#endif //ENTITY_MANAGER_H
