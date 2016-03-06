// Copyright (c) 2014-2016 Sebastien Rombauts (sebastien.rombauts@gmail.com)
//
// Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
// or copy at http://opensource.org/licenses/MIT)

#pragma once

class SGitSourceControlDevSettings : public SCompoundWidget
{
public:
	
	SLATE_BEGIN_ARGS(SGitSourceControlDevSettings) {}
	
	SLATE_END_ARGS()

public:

	void Construct(const FArguments& InArgs);

private:

	/** Delegate to get binary path from settings */
	FText GetBinaryPathText() const;

	/** Delegate to commit repository text to settings */
	void OnBinaryPathTextCommited(const FText& InText, ETextCommit::Type InCommitType) const;

	/** Delegate to get repository root, user name and email from provider */
	FText GetPathToRepositoryRoot() const;
	FText GetUserName() const;
	FText GetUserEmail() const;

	/** Delegate to initialize a new Git repository */
	EVisibility CanInitializeGitRepository() const;
	FReply OnClickedInitializeGitRepository();
	void OnCheckedCreateGitIgnore(ECheckBoxState NewCheckedState);
	bool bAutoCreateGitIgnore;
};