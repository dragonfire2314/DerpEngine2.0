#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <unordered_map>
#include <assert.h>
#include <typeinfo>

#include <core.h>
#include <ecs/Component.h>
#include <ecs/Entity.h>
#include <ecs/EntityManager.h>
#include <ecs/SystemManager.h>

namespace DERP
{
	namespace CM 
	{
		//Prototypes
		template<typename T>
		uint8_t GetComponentID();

		//Key - Component name
		//Value - Component ID
		extern std::unordered_map<const char*, uint8_t> nameToID;
		//Key - Component name
		//Value - ComponentArray
		extern std::unordered_map<const char*, ComponentBase*> nameToComponent;
		extern uint32_t componentID;

		///Do Not call directly
		template<typename T>
		void setComponentData(uint32_t entityID, T component)
		{
			const char* typeName = typeid(T).name();

			//Add to entity
			EM::addComponent(entityID, nameToID[typeName]);

			((Component<T>*)nameToComponent[typeName])->addData(entityID, component);

			//Set system
			auto signature = EM::getSignature(entityID);
			signature.set(GetComponentID<T>(), true);
			SystemManager::EntitySignatureChanged(entityID, signature);
		}

		///Do Not call directly
		template<typename T>
		T* getComponentData(uint32_t entityID)
		{
			const char* typeName = typeid(T).name();

			return ((Component<T>*)nameToComponent[typeName])->getData(entityID);
		}

		template<typename T>
		void RegisterComponent()
		{
			const char* typeName = typeid(T).name();

			printf("Component Registered %s\n", typeName);

			//Check if already exsits
			assert(nameToID.find(typeName) == nameToID.end() && "Registering component type more than once.");

			nameToID.insert({ typeName, componentID });
			nameToComponent.insert({ typeName, new Component<T>() });

			componentID++;
		}

		template<typename T>
		void AddComponent(uint32_t entityID, T component)
		{
			printf("Component Added, Ent\n");

			setComponentData<T>(entityID, component);
		}

		template<typename T>
		void AddComponent(uint32_t entityID)
		{
			printf("Component Added, Ent: %i\n", entityID);

			setComponentData<T>(entityID, T());
		}

		template<typename T>
		T* GetComponent(uint32_t entityID)
		{
			return getComponentData<T>(entityID);
		}

		template<typename T>
		uint8_t GetComponentID()
		{
			const char* typeName = typeid(T).name();

			return nameToID[typeName];
		}

		template<typename T>
		bool IsComponent(uint32_t entityID)
		{
			const char* typeName = typeid(T).name();

			//Add to entity
			return EM::isComponent(entityID, nameToID[typeName]);
		}

		template<typename T>
		std::vector<T> getComponentArray()
		{
			const char* typeName = typeid(T).name();

			//Add to entity
			return ((Component<T>*)nameToComponent[typeName])->getArray();
		}
	}
}

#endif //COMPONENT_MANAGER_H