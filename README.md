# TTToolbox

tuatec's toolbox is a collection of helper scripts that can speed up your character integration process a lot.
To tackle the most rare or complex use cases [Advanced Locomotion System (ALS)](https://www.unrealengine.com/marketplace/en-US/product/advanced-locomotion-system-v1) was used to develop the scripts.

If you ever tried to integrate a custom character you might now already how easily the systems of ALS can break.
Sadly we currently don't have a lot of tooling or helpers to show us the potential errors.
This is where TTToolbox should join your table and help getting your character working.

If you want to know how the inital development started or want to know how the scripts work, you should follow the series [ALS Secrets - UE5 Manny Integration + Git Workflow](https://youtube.com/playlist?list=PLslFX7TZAr8_kS1zdzEvrjBXI1gMRckZE).

Here is a user focused video series that shows how to use TTToolbox during the task of Paragon TwinBlast retargeting.
[The Truth of Retargeting in UE5 - Paragon TwinBlast](
https://www.youtube.com/playlist?list=PLslFX7TZAr89enRHIfJwUJJ_hJV8wX_8v)

# How to Build TTToolbox
It's still very early for TTToolbox and this part is not yet covered within the series,
[ALS Secrets - UE5 Manny Integration + Git Workflow](https://youtube.com/playlist?list=PLslFX7TZAr8_kS1zdzEvrjBXI1gMRckZE).
But will be covered soon, at first we need to get the packaging work. ;-)

# How to Contribute to TTToolbox
You can open [pull requests](https://github.com/tuatec/TTToolbox/pulls) at any time with your changes.
Then we will see how we can integrate them properly into TTToolbox.

In case you found issues, please raise an issue [here](https://github.com/tuatec/TTToolbox/issues).

In case you want to drop a feature, maybe consider to have a look at first for the [existing](https://github.com/tuatec/TTToolbox/labels/enhancement) ones and vote with a thumbs up.

If you want to start a discussion about a specific topic, do not hesitate to do so in [discussions](https://github.com/tuatec/TTToolbox/discussions).

Bugfixes are very welcome and will be reviewed as soon as possible.

# New Feature: Constraints to IK Bones During FBX Import

## Description
This feature introduces functionality to add constraints to IK bones during the import of FBX animation sequences and virtual bones in Unreal Engine. The implementation utilizes the UImportSubsystem callbacks to ensure that the bones are constrained during the import process.

## How to Use
1. Ensure that the TTToolbox plugin is enabled in your Unreal Engine project.
2. Import an FBX animation sequence into your project.
3. The constraints will be automatically applied to the IK bones during the import process.

## Testing
To test the functionality:
1. Import an FBX animation sequence with IK bones into your Unreal Engine project.
2. Verify that the constraints have been applied to the IK bones as expected.
3. Check the output log for any error messages related to the constraint application process.

## Notes
- The IK bone names to be constrained are currently hardcoded in the `TTToolboxEditorModule.cpp` file. Update these names as needed to match the IK bones in your skeleton.
- If you encounter any issues or have suggestions for improvements, please raise an issue or start a discussion on the TTToolbox GitHub repository.
