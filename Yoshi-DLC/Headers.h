#pragma once

#include "framework.h"
#include "LWVariables.h"

// csl
#include "csl/fnd.h"
#include "csl/math/math.h"
#include "csl/math/Plane.h"
#include "csl/math/Vector3.h"
#include "csl/math/Matrix34.h"
#include "csl/math/Quaternion.h"

// hh
#include "hh/base.h"

// app
#include "app/ut/internal/StateImpl.h"
#include "app/animation/AnimationResContainer.h"
#include "app/animation/AnimCallbackBridge.h"

#include "app/fnd/HFrame.h"
#include "app/fnd/Handle.h"
#include "csl/ut/NonCopyable.h"
#include "app/fnd/Message.h"
#include "app/fnd/CActor.h"
#include "app/fnd/CLeafActor.h"
#include "app/ut/StateBase.h"
#include "app/EnemyState.h"
#include "app/GameDocument.h"
#include "app/fnd/GOCTransform.h"
#include "app/GameObject.h"
#include "app/GameObject3D.h"
#include "app/CGOCCollectionImpl.h"
#include "app/CLevelInfo.h"
#include "app/fnd/BaseObject.h"
#include "app/fnd/ReferencedObject.h"
#include "app/animation/AnimationObj.h"
#include "app/animation/AnimationListener.h"
#include "app/CObjInfo.h"
#include "app/EnemyInfo.h"
#include "app/CObjInfoContainer.h"
#include "app/CSetAdapter.h"
#include "app/CSetObjectListener.h"
#include "app/enemy/DeadEffectCInfo.h"
#include "app/EnemyBlowOffObjectCInfo.h"
#include "app/xgame/MsgHitEventCollision.h"
#include "app/xgame/MsgDamage.h"
#include "app/xgame/MsgPLHoldOn.h"
#include "app/EnemyBase.h"
#include "app/EnemyManager.h"
#include "app/game/CollisionObjCInfo.h"
#include "app/CSetObjClass.h"

#include "app/fnd/GameServiceClass.h"
#include "app/fnd/GameService.h"
#include "app/fnd/GOComponent.h"
#include "app/fnd/GOCVisualContainer.h"
#include "app/fnd/MessageManager.h"
#include "app/fnd/TexSrtControlHH.h"
#include "app/fnd/SoundPlayerCri.h"
#include "app/ObjUtil.h"
#include "app/game/GOCLauncher.h"

#include "app/game/CollisionShapeType.h"
#include "app/game/GOCAnimationScript.h"
#include "app/game/GOCAnimationSimple.h"
#include "app/game/ColliShapeBase.h"
#include "app/game/GOCCollider.h"
#include "app/game/GOCEffect.h"
#include "app/game/GOCGravity.h"
#include "app/game/HudLayerController.h"
#include "app/game/GOCHud.h"
#include "app/game/GOCMotor.h"
#include "app/game/GOCMotorRotate.h"
#include "app/game/GOCShadowSimple.h"
#include "app/game/GOCShadow.h"
#include "app/game/ShadowShape.h"
#include "app/game/GOCSound.h"
#include "app/game/GOCVisual.h"
#include "app/math/Transform.h"
#include "app/game/GOCVisualModel.h"
#include "app/game/GOCMovement.h"
#include "app/game/MoveStraight.h"
#include "app/game/ShadowShapeCInfo.h"
#include "app/game/PathManager.h"
#include "app/game/PathEvaluator.h"
#include "app/game/MoveController.h"
#include "app/game/MoveBound.h"
#include "app/game/MovePopup.h"
#include "app/GameMode.h"
#include "app/GameModeStage.h"
#include "app/GOCEnemyTarget.h"
#include "app/GOCEnemyHsm.h"
#include "app/SetShotInfo.h"

#include "app/Gimmick/CRingManager.h"

#include "app/HUD/SRUtility.h"

#include "app/math/math.h"
#include "app/math/CalculatedTransform.h"

#include "app/Player/CPhysics.h"
#include "app/Player/StateUtil.h"
#include "app/Player/CPlayer.h"
#include "app/Player/CStateBase.h"
#include "app/Player/CStateGOC.h"

#include "app/xgame.h"
#include "app/xgame/Blackboard.h"
#include "app/xgame/MsgCatchEndPlayer.h"
#include "app/xgame/MsgCatchPlayer.h"
#include "app/xgame/MsgExtendPlayer.h"
#include "app/xgame/MsgGetExternalMovePosition.h"
#include "app/xgame/MsgKick.h"
#include "app/xgame/MsgNotifyObjectEvent.h"
#include "app/xgame/MsgPLGetInputButton.h"
#include "app/xgame/MsgPLVisibleItemEffect.h"
#include "app/xgame/MsgResumeGameTimer.h"
#include "app/xgame/MsgSetPosition.h"
#include "app/xgame/MsgSpringImpulse.h"
#include "app/xgame/MsgStayTrigger.h"
#include "app/xgame/MsgStopGameTimer.h"
#include "app/xgame/MsgTakeObject.h"
#include "app/xgame/MsgWarpNewArea.h"
#include "app/xgame/MsgLeaveEventCollision.h"
#include "app/xgame/MsgDlcChangeEggRotation.h"
#include "app/xgame/MsgPLJumpToTargetPosition.h"
#include "app/xgame/MsgCameraOn.h"
#include "app/xgame/MsgCameraOff.h"
#include "app/xgame/MsgDisableItemBag.h"
#include "app/xgame/MsgStopBgm.h"
#include "app/xgame/MsgPlayerReachGoal.h"
#include "app/xgame/MsgGoalForBattle.h"

#include "SonicUSA/System/Random.h"

// hh:ut
#include "hh/ut/Packfile.h"

// SurfRide
#include "SurfRide/Layer.h"

#include "Helpers.h"

#include "app/EnemyUvAnimLinkController.h"
#include "app/CObjOneUp.h"
#include "app/Objects/CSharedObjInfo.h"
#include "app/Objects/EnemyBlowOffObject.h"
#include "app/Objects/CObjDroppedRing.h"

// Yoshi Objects
#include "app/egg.h"

#include "Yoshi Objects/HudWipeCrayPipe.h"
#include "Yoshi Objects/EnemyPiranhaPlant.h"
#include "Yoshi Objects/EnemyShyGuy.h"
#include "Yoshi Objects/EggManager.h"
#include "app/HUD/CHudGameMainDisplay.h"
#include "Yoshi Objects/ObjYoshiOneUp.h"
#include "Yoshi Objects/ObjYoshi.h"
#include "Yoshi Objects/ObjEgg.h"
#include "Yoshi Objects/ObjDroppedEgg.h"
#include "Yoshi Objects/ObjEggBlock.h"
#include "Yoshi Objects/ObjEggRotationChangeCollision.h"
#include "Yoshi Objects/ObjCrayPipe.h"
#include "Yoshi Objects/ObjCrayPipeExit.h"
#include "Yoshi Objects/ObjRotateLift.h"
#include "Yoshi Objects/ObjYoshiCoin.h"
#include "Yoshi Objects/ObjYoshiJumpBoard.h"
#include "Yoshi Objects/ObjYoshiSpecialFlower.h"
#include "Yoshi Objects/ObjYoshiGoal.h"