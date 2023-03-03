#include "Notifies/CAnimNotify_EndAttack.h"
#include "Global.h"
#include "Components/CStateComponent.h"

FString UCAnimNotify_EndAttack::GetNotifyName_Implementation() const
{
	return "EndAttack";
}

void UCAnimNotify_EndAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::Notify(MeshComp, Animation);
	CheckNull(MeshComp);
	CheckNull(MeshComp->GetOwner());

	UCStateComponent* state = CHelpers::GetComponent<UCStateComponent>(MeshComp->GetOwner());
	CheckNull(state);

	state->SetIdleState();
}
