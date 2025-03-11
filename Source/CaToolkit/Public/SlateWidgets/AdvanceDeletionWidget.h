// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Views/ITableRow.h"
#include "Widgets/Views/SListView.h"
#include "Widgets/Views/STableViewBase.h"
/**
 * 
 */
class  SAdvanceDeletionTab : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SAdvanceDeletionTab){}
	SLATE_ARGUMENT(TArray<TSharedPtr<FAssetData>>,AssetsDataArray)
	SLATE_ARGUMENT(FString,CurrentSelectedFolder)
	SLATE_END_ARGS()
public:
	void Construct(const FArguments& InArgs);
private:
	TArray<TSharedPtr<FAssetData>> allAssets;
	TArray<TSharedPtr<FAssetData>> displayAssets;
	TSharedPtr<SListView<TSharedPtr<FAssetData>>> constructedAssetListView;
	TArray<TSharedPtr<FAssetData>> assetsDataToDelete;
	TArray<TSharedRef<SCheckBox>> checkBoxArray;
private:
	TSharedRef<SListView<TSharedPtr<FAssetData>>> ConstructListView(); 
	void RefreshAssetsListView();
#pragma region ComboBoxForListingCondition
	TSharedRef<SComboBox<TSharedPtr<FString>>> ConstructComboBox();
	TSharedRef<SWidget> OnGenerateComboContent(TSharedPtr<FString> sourceItem);
	void OnComboBoxSelectionChanged(TSharedPtr<FString> selectedOption, ESelectInfo::Type selectInfo);
	
	TSharedPtr<STextBlock> comboDisplayTextBlock;
	TArray<TSharedPtr<FString>> comboBoxSourceItems;
#pragma endregion 

	
#pragma region RowWidgetForAssetView
	TSharedRef<ITableRow> OnGenerateRowForList(TSharedPtr<FAssetData> assetDataToDisplay,
		const TSharedRef<STableViewBase> &ownerTable);
	TSharedRef<SCheckBox> ConstructCheckBox(const TSharedPtr<FAssetData>& assetToDisplay);
	void OnCheckBoxStateChanged(ECheckBoxState state, const TSharedPtr<FAssetData> assetToDisplay);
	TSharedRef<STextBlock> ConstructTextForRowWidget(const FString& textContent,const FSlateFontInfo& fontToUse);
	TSharedRef<SButton> ConstructButtonForRowWidget(const TSharedPtr<FAssetData>& assetDataToDisplay);
	FReply OnDeleteButtonClicked(TSharedPtr<FAssetData> clickedAssetData);
	void OnRowWidgetMouseButtonClicked(TSharedPtr<FAssetData> clickedData);

	TSharedPtr<STextBlock> ComboDisplayTextBlock();
	TSharedRef<STextBlock> ConstructComboHelpTexts(const FString& textContent,ETextJustify::Type justifyType); 
	
#pragma endregion 

#pragma region TabButtons
	TSharedRef<SButton> ConstructDeleteAllButton();
	TSharedRef<SButton> ConstructSelectAllButton();
	TSharedRef<SButton> ConstructDeselectAllButton();

	FReply OnDeleteAllButtonClicked();
	FReply OnSelectAllButtonClicked();
	FReply OnDeselectAllButtonClicked();

	TSharedRef<STextBlock> ConstructTextForTabButton(const FString& textContent);
#pragma endregion

	FSlateFontInfo GetEmbossedTextFont() const {return FCoreStyle::Get().GetFontStyle("EmbossedText");};
};
