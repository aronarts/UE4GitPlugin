// Copyright (c) 2014-2016 Sebastien Rombauts (sebastien.rombauts@gmail.com)
//
// Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
// or copy at http://opensource.org/licenses/MIT)

#pragma once

#include "ISourceControlLabel.h"

/** 
 * Abstraction of a 'Git tag'.
 */
class FGitSourceControlDevLabel : public ISourceControlLabel, public TSharedFromThis<FGitSourceControlDevLabel>
{
public:

	FGitSourceControlDevLabel( const FString& InName, int32 InRevision )
		: Name(InName)
		, Revision(InRevision)
	{
	}

	/** ISourceControlLabel implementation */
	virtual const FString& GetName() const override;
	virtual bool GetFileRevisions( const TArray<FString>& InFiles, TArray< TSharedRef<ISourceControlRevision, ESPMode::ThreadSafe> >& OutRevisions ) const override;
	virtual bool Sync( const TArray<FString>& InFilenames ) const override;

private:

	/** Label name */
	FString Name;

	/** Repository revision this label was created at */
	int32 Revision;
};