// Copyright (c) 2014-2016 Sebastien Rombauts (sebastien.rombauts@gmail.com)
//
// Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
// or copy at http://opensource.org/licenses/MIT)

#pragma once

#include "ISourceControlState.h"
#include "GitSourceControlDevRevision.h"

namespace EWorkingCopyState
{
	enum Type
	{
		Unknown,
		Unchanged, // called "clean" in SVN, "Pristine" in Perforce
		Added,
		Deleted,
		Modified,
		Renamed,
		Copied,
		Missing,
		Conflicted,
		Merged,
		NotControlled,
		Ignored,
	};
}

class FGitSourceControlDevState : public ISourceControlState, public TSharedFromThis<FGitSourceControlDevState, ESPMode::ThreadSafe>
{
public:
	FGitSourceControlDevState( const FString& InLocalFilename )
		: LocalFilename(InLocalFilename)
		, WorkingCopyState(EWorkingCopyState::Unknown)
		, TimeStamp(0)
	{
	}

	/** ISourceControlState interface */
	virtual int32 GetHistorySize() const override;
	virtual TSharedPtr<class ISourceControlRevision, ESPMode::ThreadSafe> GetHistoryItem(int32 HistoryIndex) const override;
	virtual TSharedPtr<class ISourceControlRevision, ESPMode::ThreadSafe> FindHistoryRevision(int32 RevisionNumber) const override;
	virtual TSharedPtr<class ISourceControlRevision, ESPMode::ThreadSafe> FindHistoryRevision(const FString& InRevision) const override;
	virtual TSharedPtr<class ISourceControlRevision, ESPMode::ThreadSafe> GetBaseRevForMerge() const override;
	virtual FName GetIconName() const override;
	virtual FName GetSmallIconName() const override;
	virtual FText GetDisplayName() const override;
	virtual FText GetDisplayTooltip() const override;
	virtual const FString& GetFilename() const override;
	virtual const FDateTime& GetTimeStamp() const override;
	virtual bool CanCheckIn() const override;
	virtual bool CanCheckout() const override;
	virtual bool IsCheckedOut() const override;
	virtual bool IsCheckedOutOther(FString* Who = nullptr) const override;
	virtual bool IsCurrent() const override;
	virtual bool IsSourceControlled() const override;
	virtual bool IsAdded() const override;
	virtual bool IsDeleted() const override;
	virtual bool IsIgnored() const override;
   virtual bool CanEdit() const override;
   virtual bool CanDelete() const; // override; // commented out for UE4.12 and 4.13 compatibility : method added for 4.14
   virtual bool IsUnknown() const override;
	virtual bool IsModified() const override;
	virtual bool CanAdd() const override;
	virtual bool IsConflicted() const override;

public:
	/** History of the item, if any */
	TGitSourceControlDevHistory History;

	/** Filename on disk */
	FString LocalFilename;

	/** File Id with which our local revision diverged from the remote revision */
	FString PendingMergeBaseFileHash;

	/** State of the working copy */
	EWorkingCopyState::Type WorkingCopyState;

	/** The timestamp of the last update */
	FDateTime TimeStamp;
};
