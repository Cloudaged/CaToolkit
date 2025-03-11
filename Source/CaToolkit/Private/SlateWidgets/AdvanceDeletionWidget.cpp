// Fill out your copyright notice in the Description page of Project Settings.


#include "SlateWidgets/AdvanceDeletionWidget.h"

#include "CaToolkit.h"
#include "AssetRegistry/AssetData.h"
#include "Components/VerticalBox.h"
#include "Styling/CoreStyle.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/SListView.h"
#include "ToolkitDebug.h"
#include "Modules/ModuleManager.h"

#define ListAll TEXT("All")
#define ListUnused TEXT("Unused")
#define ListSameName TEXT("Same Name")
void SAdvanceDeletionTab::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	allAssets = InArgs._AssetsDataArray;
	displayAssets = InArgs._AssetsDataArray;

	checkBoxArray.Empty();
	assetsDataToDelete.Empty();
	comboBoxSourceItems.Empty();
	
	comboBoxSourceItems.Add(MakeShareable(new FString(ListAll)));
	comboBoxSourceItems.Add(MakeShared<FString>(ListUnused));
	comboBoxSourceItems.Add(MakeShared<FString>(ListSameName));
	
	FSlateFontInfo titleTextFont = FCoreStyle::Get().GetFontStyle("EmbossedText");
	titleTextFont.Size = 30;
	
	ChildSlot
	[
		SNew(SVerticalBox)

		//First slot for show title
		+SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(STextBlock)
			.Text(FText::FromString("Advance Deletion"))
			.Font(titleTextFont)
			.Justification(ETextJustify::Center)
			.ShadowColorAndOpacity(FLinearColor::Black)
			.ShadowOffset(FVector2D(1.0f, 1.0f))
			.ColorAndOpacity(FLinearColor::White)
		]
		//Second slot for show list condition
		+SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			//combox box slot
			 +SHorizontalBox::Slot()
			.AutoWidth()
			[
				ConstructComboBox()
			]
			//help text
			+SHorizontalBox::Slot()
			.FillWidth(.6f)
			[
				ConstructComboHelpTexts(TEXT("click to locate the asset"),ETextJustify::Center)
			]
			//folder text
			+SHorizontalBox::Slot()
			.FillWidth(.1f)
			[
				ConstructComboHelpTexts(TEXT("Current folder:\n")+InArgs._CurrentSelectedFolder,ETextJustify::Right)
			]
		]
		//Third slot for list assets
		+SVerticalBox::Slot()
		.VAlign(VAlign_Fill)
		[
			SNew(SScrollBox)
			+SScrollBox::Slot()
			[
				ConstructListView()
			]
		]
		
		//Four slot for 3 button
		+SVerticalBox::Slot()
		.AutoHeight()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.FillWidth(10.f)
			.Padding(5.f)
			[
				ConstructDeleteAllButton()
			]
			+SHorizontalBox::Slot()
			.FillWidth(10.f)
			.Padding(5.f)
			[
				ConstructSelectAllButton()
			]
			+SHorizontalBox::Slot()
			.FillWidth(10.f)
			.Padding(5.f)
			[
				ConstructDeselectAllButton()
			]
		]
	];
}

void SAdvanceDeletionTab::RefreshAssetsListView()
{
	checkBoxArray.Empty();
	assetsDataToDelete.Empty();
	if(constructedAssetListView.IsValid())
	{
		constructedAssetListView->RebuildList();
	}
}

#pragma region ComboBoxForListingCondition
TSharedRef<SComboBox<TSharedPtr<FString>>> SAdvanceDeletionTab::ConstructComboBox()
{
	TSharedRef<SComboBox<TSharedPtr<FString>>> comboBox =
		SNew(SComboBox<TSharedPtr<FString>>)
	.OptionsSource(&comboBoxSourceItems)
	.OnGenerateWidget(this, &SAdvanceDeletionTab::OnGenerateComboContent)
	.OnSelectionChanged(this,&SAdvanceDeletionTab::OnComboBoxSelectionChanged)
	[
		SAssignNew(comboDisplayTextBlock,STextBlock)
		.Text(FText::FromString(ListAll))
	];
	return comboBox;
}

TSharedRef<SWidget> SAdvanceDeletionTab::OnGenerateComboContent(TSharedPtr<FString> sourceItem)
{
	TSharedRef<STextBlock>  textBlock= SNew(STextBlock).Text(FText::FromString(*sourceItem.Get()));
	return textBlock;
}

void SAdvanceDeletionTab::OnComboBoxSelectionChanged(TSharedPtr<FString> selectedOption, ESelectInfo::Type selectInfo)
{
	comboDisplayTextBlock->SetText(FText::FromString(*selectedOption.Get()));

	FCaToolkitModule& toolkitModule = FModuleManager::LoadModuleChecked<FCaToolkitModule>(TEXT("CaToolkit"));

	//pass data for module
	if(*selectedOption==ListAll)
	{
		//List all asset data
		displayAssets = allAssets;
		RefreshAssetsListView();
	}
	else if(*selectedOption==ListUnused)
	{
		//List unused assets
		toolkitModule.ListUnusedAssetsForAssetList(allAssets,displayAssets);
		RefreshAssetsListView();
	}else if(*selectedOption==ListSameName)
	{
		//List out all assets with same name
		toolkitModule.ListSameNameAssetsForAssetList(allAssets,displayAssets);
		RefreshAssetsListView();
	}
}


#pragma endregion 


#pragma region RowWidgetForAssetView

TSharedRef<SListView<TSharedPtr<FAssetData>>> SAdvanceDeletionTab::ConstructListView()
{
	constructedAssetListView =SNew(SListView<TSharedPtr<FAssetData>>)
				.ItemHeight(24.f)
				.ListItemsSource(&displayAssets)
				.OnGenerateRow(this, &SAdvanceDeletionTab::OnGenerateRowForList)
				.OnMouseButtonClick(this,&SAdvanceDeletionTab::OnRowWidgetMouseButtonClicked);
	return constructedAssetListView.ToSharedRef();
}

TSharedRef<ITableRow> SAdvanceDeletionTab::OnGenerateRowForList(TSharedPtr<FAssetData> assetDataToDisplay,
                                                                const TSharedRef<STableViewBase>& ownerTable)
{
	if(!assetDataToDisplay.IsValid()) return SNew(STableRow<TSharedPtr<FAssetData>>,ownerTable);
	const FString displayAssetClassName = assetDataToDisplay.Get()->GetClass()->GetName();
	 const FString displayAssetName = assetDataToDisplay.Get()->AssetName.ToString();

	FSlateFontInfo assetClassNameFont =  GetEmbossedTextFont();
	assetClassNameFont.Size = 10;

	FSlateFontInfo assetNameFont =  GetEmbossedTextFont();
	assetNameFont.Size = 15;
	auto listViewRowWidget =
		SNew(STableRow<TSharedPtr<FAssetData>>, ownerTable)
		.Padding(FMargin(5.0f))
	[
		SNew(SHorizontalBox)
		//First slot for check box
		+SHorizontalBox::Slot()
		.HAlign(HAlign_Left)
		.VAlign(VAlign_Center)
		.FillWidth(0.05f)
		[
			ConstructCheckBox(assetDataToDisplay)
		]
		//Second slot for class name
		+SHorizontalBox::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Fill)
		.FillWidth(0.5f)
		[
			ConstructTextForRowWidget(displayAssetClassName,assetClassNameFont)
		]
	
		//Third slot for name
		+SHorizontalBox::Slot()
		[
			ConstructTextForRowWidget(displayAssetName,assetNameFont)
		]
		//Fourth slot for delete button
		+SHorizontalBox::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Fill)
		[
			ConstructButtonForRowWidget(assetDataToDisplay)
		]
		
		
		
	];
	return listViewRowWidget;
}

TSharedRef<SCheckBox> SAdvanceDeletionTab::ConstructCheckBox(const TSharedPtr<FAssetData>& assetToDisplay)
{
	auto checkBox = SNew(SCheckBox)
	.Type(ESlateCheckBoxType::CheckBox)
	.OnCheckStateChanged(this, &SAdvanceDeletionTab::OnCheckBoxStateChanged, assetToDisplay)
	.Visibility(EVisibility::Visible);

	checkBoxArray.Add(checkBox);
	
	return checkBox;
} 

void SAdvanceDeletionTab::OnCheckBoxStateChanged(ECheckBoxState state, const TSharedPtr<FAssetData> assetToDisplay)
{
	switch (state)
	{
	case ECheckBoxState::Unchecked:
		if(assetsDataToDelete.Contains(assetToDisplay))
		{
			assetsDataToDelete.Remove(assetToDisplay);
		}
		break;
	case ECheckBoxState::Checked:
		assetsDataToDelete.Add(assetToDisplay);
		break;
	case ECheckBoxState::Undetermined:
		break;
	}		
}

TSharedRef<STextBlock> SAdvanceDeletionTab::ConstructTextForRowWidget(const FString& textContent,
	const FSlateFontInfo& fontToUse)
{
	return SNew(STextBlock)
	.Text(FText::FromString(textContent))
	.Font(fontToUse)
	.ColorAndOpacity(FColor::White);
}

TSharedRef<SButton> SAdvanceDeletionTab::ConstructButtonForRowWidget(const TSharedPtr<FAssetData>& assetDataToDisplay)
{
	return SNew(SButton)
	.Text(FText::FromString("Delete"))
	.OnClicked(this, &SAdvanceDeletionTab::OnDeleteButtonClicked, assetDataToDisplay);
}

FReply SAdvanceDeletionTab::OnDeleteButtonClicked(TSharedPtr<FAssetData> clickedAssetData)
{
	FCaToolkitModule& toolkitModule = FModuleManager::LoadModuleChecked<FCaToolkitModule>(TEXT("CaToolkit"));
	bool result = toolkitModule.DeleteSingleAssetForAssetList(*clickedAssetData.Get());
	if(result)
	{
		//update list
		if(allAssets.Contains(clickedAssetData))
		{
			allAssets.Remove(clickedAssetData); 
		}
		if(displayAssets.Contains(clickedAssetData))
		{
			displayAssets.Remove(clickedAssetData);
		}
		//Refresh the list
		RefreshAssetsListView();
		
	}
	return FReply::Handled();
}

void SAdvanceDeletionTab::OnRowWidgetMouseButtonClicked(TSharedPtr<FAssetData> clickedData)
{
	FCaToolkitModule& toolkitModule = FModuleManager::LoadModuleChecked<FCaToolkitModule>(TEXT("CaToolkit"));

	toolkitModule.SyncCBToClickedAssetForAssetList(clickedData.Get()->ObjectPath.ToString());
}

TSharedPtr<STextBlock> SAdvanceDeletionTab::ComboDisplayTextBlock()
{
	return comboDisplayTextBlock;
}

TSharedRef<STextBlock> SAdvanceDeletionTab::ConstructComboHelpTexts(const FString& textContent,ETextJustify::Type justifyType)
{
	TSharedRef<STextBlock> constructedHelpText = SNew(STextBlock)
	.Text(FText::FromString(textContent))
	.Justification(justifyType)
	.Font(GetEmbossedTextFont())
	.AutoWrapText(true);
	return constructedHelpText;
}

#pragma endregion 

#pragma region TabButtons
TSharedRef<SButton> SAdvanceDeletionTab::ConstructDeleteAllButton()
{
	TSharedRef<SButton> deleteAllButton = SNew(SButton)
	.ContentPadding(FMargin(5.0f))
	.OnClicked(this, &SAdvanceDeletionTab::OnDeleteAllButtonClicked);

	deleteAllButton->SetContent(ConstructTextForTabButton("Delete All"));
	return deleteAllButton;
}

TSharedRef<SButton> SAdvanceDeletionTab::ConstructSelectAllButton()
{
	TSharedRef<SButton> selectAllButton = SNew(SButton)
	.ContentPadding(FMargin(5.0f))
	.OnClicked(this, &SAdvanceDeletionTab::OnSelectAllButtonClicked);

	selectAllButton->SetContent(ConstructTextForTabButton("Select All"));
	return selectAllButton;
}

TSharedRef<SButton> SAdvanceDeletionTab::ConstructDeselectAllButton()
{
	TSharedRef<SButton> deselectAllButton = SNew(SButton)
	.ContentPadding(FMargin(5.0f))
	.OnClicked(this, &SAdvanceDeletionTab::OnDeselectAllButtonClicked);

	deselectAllButton->SetContent(ConstructTextForTabButton("Deselect All"));
	return deselectAllButton;
}

FReply SAdvanceDeletionTab::OnDeleteAllButtonClicked()
{
	if(assetsDataToDelete.Num()==0)
	{
		 return FReply::Unhandled();
	}
	TArray<FAssetData> toDelete;
	for(TSharedPtr<FAssetData>& assetData : assetsDataToDelete)
	{
		toDelete.Add(*assetData.Get());
	}
	FCaToolkitModule& toolkitModule = FModuleManager::LoadModuleChecked<FCaToolkitModule>(TEXT("CaToolkit"));
	bool result = toolkitModule.DeleteMultipleAssetsForAssetList(toDelete);

	if(result)
	{
		for(const TSharedPtr<FAssetData>& assetData : assetsDataToDelete)
		{
			if(allAssets.Contains(assetData))
			{
				allAssets.Remove(assetData);
			}
			if(displayAssets.Contains(assetData))
			{
				displayAssets.Remove(assetData);
			}
		}
		RefreshAssetsListView();
	}
	
	return FReply::Handled();
}

FReply SAdvanceDeletionTab::OnSelectAllButtonClicked()
{
	if(checkBoxArray.Num() == 0) return FReply::Unhandled();

	for(const TSharedRef<SCheckBox>& checkBox : checkBoxArray)
	{
		if(!checkBox->IsChecked())
		{
			checkBox->ToggleCheckedState();
		}
	}
	return FReply::Handled();
}

FReply SAdvanceDeletionTab::OnDeselectAllButtonClicked()
{
	if(checkBoxArray.Num() == 0) return FReply::Unhandled();

	for(const TSharedRef<SCheckBox>& checkBox : checkBoxArray)
	{
		if(checkBox->IsChecked())
		{
			checkBox->ToggleCheckedState();
		}
	}
	return FReply::Handled();
}

TSharedRef<STextBlock> SAdvanceDeletionTab::ConstructTextForTabButton(const FString& textContent)
{
	FSlateFontInfo buttonTextInfo = GetEmbossedTextFont();
	buttonTextInfo.Size = 15; 
	TSharedRef<STextBlock> constructedTextBlock  = SNew(STextBlock)
	.Text(FText::FromString(textContent))
	.Font(buttonTextInfo)
	.Justification(ETextJustify::Center);
	return constructedTextBlock;
}

#pragma endregion 