#pragma once

namespace app
{
	struct DroppedEggCInfo;
	class ObjDroppedEgg;
	namespace egg
	{
		ObjDroppedEgg* CreateDroppedEgg(GameDocument& gameDocument, DroppedEggCInfo* cInfo);
	}

	struct DroppedEggCInfo
	{
		csl::math::Matrix34 Transform;
		csl::math::Vector3 field_40;
		game::PathEvaluator PathEvaluator;
		int ModelType;
		int ZIndex;
		int field_68;
		int field_6C;
	};

	class ObjDroppedEgg : public GameObject3D
	{
	public:
		class BoundListener : public game::MoveBound::Listener
		{
			void OnBound(csl::math::Plane& const a1) override
			{
				
			}
		};

	private:
		bool ProcMsgHitEventCollision(fnd::Message& message)
		{
			EggCInfo cInfo{};
			GameDocument& document = (GameDocument&)field_24[1];

			// TODO: Copy transform over to EggCInfo
			cInfo.ModelType = ModelType;
			egg::CreateEgg(document, &cInfo);

			return Kill(this);
		}

		void BoundCallback()
		{

		}
	
	public:
		INSERT_PADDING(0x8);
		INSERT_PADDING(0x14);	// TinyFSM
		DroppedEggCInfo* CInfo{};
		int ModelType{};
		float field_33C{};
		game::MoveBound* Movement{};
		BoundListener* Listener{};
		ObjDroppedEgg* field_348;
		fnd::HandleBase Handle{};
		INSERT_PADDING(0xC);
		csl::math::Vector3 field_360{};

		ObjDroppedEgg(GameDocument& document, DroppedEggCInfo* cInfo)
		{
			CInfo = cInfo;
			ModelType = CInfo->ModelType;
		}

		void AddCallback(GameDocument* gameDocument) override
		{
			fnd::GOCVisualModel::VisualDescription visualDescriptor{};
			game::ColliSphereShapeCInfo collisionInfo{};
			int unit = 1;

			fnd::GOComponent::Create(this, GOCVisualModel);
			fnd::GOComponent::Create(this, GOCCollider);
			fnd::GOComponent::Create(this, GOCMovementComplex);

			fnd::GOComponent::BeginSetup(this);

			int* gocTransform = GameObject::GetGOC(this, GOCTransformString);
			if (gocTransform)
			{
				csl::math::Quaternion rotation = GetRotationFromMatrix(&CInfo->Transform);
				fnd::GOCTransform::SetLocalTranslation(gocTransform, (csl::math::Vector3*)&CInfo->Transform.data[3][0]);
				fnd::GOCTransform::SetLocalRotation(gocTransform, &rotation);
			}

			ObjEggInfo* info = (ObjEggInfo*)ObjUtil::GetObjectInfo(gameDocument, "ObjEggInfo");

			int* gocVisual = GameObject::GetGOC((GameObject*)this, GOCVisual);
			if (gocVisual)
			{
				csl::math::Vector3 visualOffset{ 0, -3, 0 };

				visualDescriptor.Model = info->Models[ModelType];
				visualDescriptor.Animation |= 0x400000;
				visualDescriptor.ZIndex = -0.2 * CInfo->ZIndex;
				fnd::GOCVisualModel::Setup(gocVisual, &visualDescriptor);
				fnd::GOCVisualTransformed::SetLocalTranslation(gocVisual, &visualOffset);
			}

			int* gocCollider = GameObject::GetGOC(this, GOCColliderString);
			if (gocCollider)
			{
				game::GOCCollider::Setup(gocCollider, &unit);
				collisionInfo.ShapeType = game::CollisionShapeType::ShapeType::TYPE_SPHERE;
				collisionInfo.MotionType = 2;
				collisionInfo.Radius = 3;
				ObjUtil::SetupCollisionFilter(8, &collisionInfo);
				collisionInfo.field_04 |= 1;
				game::GOCCollider::CreateShape(gocCollider, &collisionInfo);
			}

			int* gocMovement = GameObject::GetGOC(this, GOCMovementString);
			if (gocMovement)
			{
				game::MoveBound moveBound{};
				game::GOCMovement::SetupController(gocMovement, &moveBound);

				game::MoveBound::Desc description{};
				description.field_00 = CInfo->field_40;
				description.field_10 = 3;
				description.field_14 = 300;
				description.field_18 = 0.8f;
				description.field_20 = 150;
				description.field_28 = 1;
				description.field_2C = 0.1f;
				game::PathEvaluator::__ct(&description.field_38);
				if (fnd::HandleBase::IsValid((fnd::HandleBase*)&CInfo->PathEvaluator))
				{
					int pathObject = fnd::HandleBase::Get((fnd::HandleBase*)&CInfo->PathEvaluator);
					game::PathEvaluator::SetPathObject(&description.field_38, pathObject);
					game::PathEvaluator::SetDistance(&description.field_38, CInfo->PathEvaluator.field_08);
				}
				description.field_48 |= 3;

				game::MoveBound::Setup(&moveBound, &description);
				game::MoveBound::ResetListener(&moveBound, Listener);
				Movement = &moveBound;
			}
		}

		bool ProcessMessage(fnd::Message& message) override
		{
			if (PreProcessMessage(message))
				return true;

			if (message.field_04 != fnd::PROC_MSG_HIT_EVENT_COLLISION)
				return app::GameObject::ProcessMessage(message);

			ProcMsgHitEventCollision(message);
			return true;
		}
	};
}

app::ObjDroppedEgg* app::egg::CreateDroppedEgg(GameDocument& gameDocument, DroppedEggCInfo* cInfo)
{
	ObjDroppedEgg* object = new ObjDroppedEgg(gameDocument, cInfo);
	if (!object)
		return 0;
	GameDocument::AddGameObject(*(GameDocument**)&gameDocument, object);
	return object;
}