#pragma 

namespace app
{
	class ObjEgg;

	class EggManager : public fnd::GameService
	{
		struct LocusData
		{
			int field_00;
			int field_04;
			int field_08;
			int field_0C;
			int field_10;
			csl::fnd::IAllocator* pAllocator;
		};

	public:
		std::vector<ObjEgg*> Eggs;
		LocusData Locus{};
		int field_64{};
		bool SpaceShrink{};
		char FlowerCount{};
		INSERT_PADDING(2);

		EggManager()
		{
			// TODO: CHECK IF CRASH
			Locus.pAllocator = (*(csl::fnd::IAllocator**)ASLR(0x00FD3FC4) + 3);
		}

	private:
		static void* staticClass() { return (void*)ASLR(0x00FEE764); }

		void UpdateLocusPos(float a2)
		{
			
		}

	public:
		bool AddEgg(ObjEgg* egg)
		{
			if (Eggs.size() >= 0xC)
				return false;
			
			Eggs.push_back(egg);
			return true;
		}
		
		void SetForceSpaceShrink(bool isShrink)
		{
			if (!SpaceShrink)
				SpaceShrink = true;
			else
				SpaceShrink = false;
		}

		void TakeYoshiSpecialFlower(char flowerID) { FlowerCount |= 1 << flowerID; }
		unsigned int IsYoshiSpecialFlowerTaked(char flowerID) { return (FlowerCount >> flowerID) & 1; }

		static EggManager* GetService(GameDocument* gameDocument)
		{
			void* managerClass = staticClass();
			EggManager* service = (EggManager*)GameDocument::GetServiceByClass(gameDocument, managerClass);
			return service;
		}

		void StartGame(bool a1) override
		{
			Eggs.clear();
			Locus.field_00 = 0;
			Locus.field_04 = 0;
			Locus.field_08 = 0;
			Locus.field_0C = 0;
			Locus.field_10 = 0;
			Locus.pAllocator = (*(csl::fnd::IAllocator**)ASLR(0x00FD3FC4) + 3);
		
			field_64 = 0;
			SpaceShrink = false;
			FlowerCount = 0;
		}

		void Update(const fnd::SUpdateInfo& updateInfo) override
		{

		}
	};
	
	EggManager* construct_EggManager(csl::fnd::IAllocator* pAllocator)
	{
		return new(pAllocator) EggManager();
	}
}