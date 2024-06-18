#include "TTToolboxEditorModule.h"
#include "TTToolboxBlueprintLibrary.h"
#include "Modules/ModuleManager.h"
#include "Editor/UnrealEd/Public/Editor.h"
#include "Editor/UnrealEd/Public/EditorSubsystem.h"
#include "Editor/UnrealEd/Public/EditorDelegates.h"
#include "Editor/UnrealEd/Public/Editor/UnrealEdEngine.h"
#include "Editor/UnrealEd/Public/Editor/UnrealEdGlobals.h"
#include "Editor/UnrealEd/Public/Editor/UnrealEdTypes.h"
#include "Editor/UnrealEd/Public/Editor/UnrealEdMisc.h"
#include "Editor/UnrealEd/Public/Editor/UnrealEdEngine.h"
#include "Editor/UnrealEd/Public/Editor/UnrealEdGlobals.h"
#include "Editor/UnrealEd/Public/Editor/UnrealEdTypes.h"
#include "Editor/UnrealEd/Public/Editor/UnrealEdMisc.h"

class FTTToolboxEditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        // Register the callback for FBX import
        GEditor->GetEditorSubsystem<UImportSubsystem>()->OnAssetPostImport.AddRaw(this, &FTTToolboxEditorModule::OnAssetPostImport);
    }

    virtual void ShutdownModule() override
    {
        // Unregister the callback
        if (UImportSubsystem* ImportSubsystem = GEditor->GetEditorSubsystem<UImportSubsystem>())
        {
            ImportSubsystem->OnAssetPostImport.RemoveAll(this);
        }
    }

private:
    void OnAssetPostImport(UFactory* InFactory, UObject* InCreatedObject)
    {
        // Check if the imported asset is an animation sequence
        if (UAnimSequence* AnimSequence = Cast<UAnimSequence>(InCreatedObject))
        {
            // Get the skeleton associated with the animation sequence
            USkeleton* Skeleton = AnimSequence->GetSkeleton();
            if (Skeleton)
            {
                // Define the IK bone names to be constrained
                TArray<FName> IKBoneNames = { "IK_Bone1", "IK_Bone2" }; // Replace with actual IK bone names

                // Call the function to add constraints to IK bones
                UTTToolboxBlueprintLibrary::ConstraintBonesForSkeletonPose(IKBoneNames, Skeleton);
            }
        }
    }
};

IMPLEMENT_MODULE(FTTToolboxEditorModule, TTToolboxEditor)
